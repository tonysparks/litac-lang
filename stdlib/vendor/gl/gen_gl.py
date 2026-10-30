#!/usr/bin/env python3
# Generates stdlib/vendor/gl/gl.lita from a glad2 header-only GL 3.3 core header.
import re, sys

src, out = sys.argv[1], sys.argv[2]
text = open(src).read()

KEYWORDS = set("""import struct union trait enum func typedef var const null void true false bool char
i8 u8 i16 u16 i32 u32 i64 u64 f32 f64 usize for while do if else switch case default defer break
continue return goto sizeof typeof nameof offsetof as public internal using""".split())

GL_TYPES = {
    "GLenum": "u32", "GLboolean": "u8", "GLbitfield": "u32", "GLbyte": "i8", "GLubyte": "u8",
    "GLshort": "i16", "GLushort": "u16", "GLint": "i32", "GLuint": "u32", "GLsizei": "i32",
    "GLfloat": "f32", "GLclampf": "f32", "GLdouble": "f64", "GLclampd": "f64", "GLchar": "char",
    "GLintptr": "i64", "GLsizeiptr": "i64", "GLint64": "i64", "GLuint64": "u64", "GLhalf": "u16",
}

def lita_type(ctype):
    # ctype e.g. "const GLchar *const*", "void *", "GLuint"
    ctype = ctype.strip()
    stars = ctype.count("*")
    base = ctype.replace("*", " ").replace("const", " ").split()
    base = base[0] if base else "void"
    is_const = ctype.startswith("const")
    if base == "GLvoid":
        base = "void"
    if base == "GLsync":
        base = "GLsync"
    prefix = "*" * stars
    if stars and is_const:
        return prefix + "const " + base
    return prefix + base

def split_param(p):
    p = p.strip()
    m = re.match(r"(.*?)([A-Za-z_][A-Za-z0-9_]*)$", p)
    ctype, name = m.group(1), m.group(2)
    if name in KEYWORDS:
        name += "_"
    return name, lita_type(ctype)

protos = {}
for m in re.finditer(r"typedef (.+?) \(GLAD_API_PTR \*PFN(GL\w+)PROC\)\((.*?)\);", text):
    ret, pfn, params = m.group(1), m.group(2), m.group(3)
    protos[pfn] = (ret, params)

funcs = re.findall(r"^#define (gl[A-Z]\w*) glad_gl\w+$", text, re.M)
consts = re.findall(r"^#define (GL_[A-Z0-9_]+) (0x[0-9A-Fa-f]+|\d+)$", text, re.M)

SPECIAL_CONST_TYPES = {"GL_TRUE": "GLboolean", "GL_FALSE": "GLboolean",
                       "GL_TIMEOUT_IGNORED": "GLuint64", "GL_INVALID_INDEX": "GLuint"}

lines = []
w = lines.append
w("// OpenGL 3.3 core bindings. Generated from a glad2 header (glad/gl.h) -- do not edit by hand;")
w("// regenerate with gen_gl.py if the GL version or extension set changes.")
w('@raw("""')
w("#define GLAD_GL_IMPLEMENTATION")
w('""");')
w('@include("glad/gl.h");')
w("")
w("@compiler_option(")
w('    .options = "-I{relativePath}"')
w(");")
w("")
for t, lt in GL_TYPES.items():
    w(f"@foreign public typedef {lt} as {t};")
w("@foreign public struct __GLsync {}")
w("@foreign public typedef *__GLsync as GLsync;")
w("")
w("@foreign public typedef func() : void as GLADapiproc;")
w("@foreign public typedef func(*const char) : GLADapiproc as GLADloadfunc;")
w("")
w("// Loads all GL 3.3 core entry points; returns the loaded version (GLAD_VERSION_MAJOR/MINOR), 0 on failure.")
w("// Must be called after a GL context is made current, e.g. `gladLoadGL(SDL_GL_GetProcAddress as (GLADloadfunc))`.")
w("@foreign public func gladLoadGL(load: GLADloadfunc) : i32;")
w("@foreign public func GLAD_VERSION_MAJOR(version: i32) : i32;")
w("@foreign public func GLAD_VERSION_MINOR(version: i32) : i32;")
w("")
seen = set()
for name, _ in consts:
    if name in seen: continue
    seen.add(name)
    w(f"@foreign public const {name}: {SPECIAL_CONST_TYPES.get(name, 'GLenum')};")
w("")
for f in funcs:
    ret, params = protos["GL" + f[2:].upper()] if ("GL" + f[2:].upper()) in protos else protos[f.upper()]
    ps = []
    if params.strip() not in ("", "void"):
        for p in params.split(","):
            n, t = split_param(p)
            ps.append(f"{n}: {t}")
    rt = lita_type(ret)
    sig = f"@foreign public func {f}({', '.join(ps)})"
    if rt != "void":
        sig += f" : {rt}"
    w(sig + ";")

open(out, "w").write("\n".join(lines) + "\n")
print(f"{len(funcs)} funcs, {len(seen)} consts")
