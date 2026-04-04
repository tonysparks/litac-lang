# std::cmdline

## Functions

<a id="func-cmdparserinit"></a>

### func CmdParserInit(allocator: \*const [Allocator](std_mem.md#struct-allocator)) : [CmdParser](std_cmdline.md#struct-cmdparser)

*public* | *stdlib/std/cmdline.lita:62*

---

<a id="func-init"></a>

### func init(p: \*[CmdParser](std_cmdline.md#struct-cmdparser), allocator: \*const [Allocator](std_mem.md#struct-allocator)) : void

*public* | *stdlib/std/cmdline.lita:69*

---

<a id="func-free"></a>

### func free(p: \*[CmdParser](std_cmdline.md#struct-cmdparser)) : void

*public* | *stdlib/std/cmdline.lita:80*

---

<a id="func-addcommand"></a>

### func addCommand(p: \*[CmdParser](std_cmdline.md#struct-cmdparser), name: \*const char, description: \*const char, hasArg: bool) : \*[Cmd](std_cmdline.md#struct-cmd)

*public* | *stdlib/std/cmdline.lita:89*

---

<a id="func-addoption"></a>

### func (this: \*[Cmd](std_cmdline.md#struct-cmd)) addOption(longName: \*const char, shortName: char, description: \*const char, flags: i32, defaultValue: \*const char) : \*[Cmd](std_cmdline.md#struct-cmd)

*public* | *stdlib/std/cmdline.lita:106*

---

<a id="func-addoption"></a>

### func addOption(p: \*[CmdParser](std_cmdline.md#struct-cmdparser), longName: \*const char, shortName: char, description: \*const char, flags: i32, defaultValue: \*const char) : \*[CmdParser](std_cmdline.md#struct-cmdparser)

*public* | *stdlib/std/cmdline.lita:127*

---

<a id="func-hascmd"></a>

### func hasCmd(p: \*[CmdParser](std_cmdline.md#struct-cmdparser)) : bool

*public* | *stdlib/std/cmdline.lita:145*

---

<a id="func-getcmd"></a>

### func getCmd(p: \*[CmdParser](std_cmdline.md#struct-cmdparser)) : \*[Cmd](std_cmdline.md#struct-cmd)

*public* | *stdlib/std/cmdline.lita:149*

---

<a id="func-getoption"></a>

### func (this: \*[Cmd](std_cmdline.md#struct-cmd)) getOption(longName: \*const char) : \*[Option](std_cmdline.md#struct-option)

*public* | *stdlib/std/cmdline.lita:153*

---

<a id="func-getoption"></a>

### func getOption(p: \*[CmdParser](std_cmdline.md#struct-cmdparser), longName: \*const char) : \*[Option](std_cmdline.md#struct-option)

*public* | *stdlib/std/cmdline.lita:164*

---

<a id="func-getoptionshort"></a>

### func (this: \*[Cmd](std_cmdline.md#struct-cmd)) getOptionShort(shortName: char) : \*[Option](std_cmdline.md#struct-option)

*public* | *stdlib/std/cmdline.lita:168*

---

<a id="func-getoptionshort"></a>

### func getOptionShort(p: \*[CmdParser](std_cmdline.md#struct-cmdparser), shortName: char) : \*[Option](std_cmdline.md#struct-option)

*public* | *stdlib/std/cmdline.lita:179*

---

<a id="func-hasoption"></a>

### func (this: \*[Cmd](std_cmdline.md#struct-cmd)) hasOption(longName: \*const char) : bool

*public* | *stdlib/std/cmdline.lita:184*

---

<a id="func-hasoption"></a>

### func hasOption(p: \*[CmdParser](std_cmdline.md#struct-cmdparser), longName: \*const char) : bool

*public* | *stdlib/std/cmdline.lita:193*

---

<a id="func-hasoptionshort"></a>

### func (this: \*[Cmd](std_cmdline.md#struct-cmd)) hasOptionShort(shortName: char) : bool

*public* | *stdlib/std/cmdline.lita:199*

---

<a id="func-hasoptionshort"></a>

### func hasOptionShort(p: \*[CmdParser](std_cmdline.md#struct-cmdparser), shortName: char) : bool

*public* | *stdlib/std/cmdline.lita:208*

---

<a id="func-hasargvalue"></a>

### func (this: \*[Cmd](std_cmdline.md#struct-cmd)) hasArgValue() : bool

*public* | *stdlib/std/cmdline.lita:213*

---

<a id="func-getargvalue"></a>

### func (this: \*[Cmd](std_cmdline.md#struct-cmd)) getArgValue() : \*const char

*public* | *stdlib/std/cmdline.lita:217*

---

<a id="func-merge"></a>

### func merge(p: \*[CmdParser](std_cmdline.md#struct-cmdparser), argc: i32, argv: \*\*char) : [CmdParserStatus](std_cmdline.md#enum-cmdparserstatus)

*public* | *stdlib/std/cmdline.lita:229*


    Apply the supplied program arguments over this,
    meaning these new args will take precedence.

    If they are not the same command, this will error
    

---

<a id="func-parse"></a>

### func parse(p: \*[CmdParser](std_cmdline.md#struct-cmdparser), argc: i32, argv: \*\*char) : [CmdParserStatus](std_cmdline.md#enum-cmdparserstatus)

*public* | *stdlib/std/cmdline.lita:308*

---

<a id="func-printall"></a>

### func printAll(p: \*[CmdParser](std_cmdline.md#struct-cmdparser)) : void

*public* | *stdlib/std/cmdline.lita:374*

---

<a id="func-printerrors"></a>

### func printErrors(p: \*[CmdParser](std_cmdline.md#struct-cmdparser), sb: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : void

*public* | *stdlib/std/cmdline.lita:384*

---

<a id="func-printhelp"></a>

### func printHelp(p: \*[CmdParser](std_cmdline.md#struct-cmdparser), sb: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : void

*public* | *stdlib/std/cmdline.lita:391*

---

## Types

<a id="enum-cmdparserstatus"></a>

### enum CmdParserStatus

*public* | *stdlib/std/cmdline.lita:12*

| Value | Description |
|-------|-------------|
| `OK` |  |
| `MISSING_ARGUMENT` |  |
| `MISSING_REQUIRED` |  |
| `ERROR_MERGING_ARGS` |  |

---

<a id="enum-optionflag"></a>

### enum OptionFlag

*public* | *stdlib/std/cmdline.lita:20*

| Value | Description |
|-------|-------------|
| `HAS_ARGUMENT` |  |
| `IS_REQUIRED` |  |
| `IS_USED` |  |

---

<a id="struct-option"></a>

### struct Option

*public* | *stdlib/std/cmdline.lita:28*

| Field | Type | Description |
|-------|------|-------------|
| `name` | \*const char |  |
| `shortName` | char |  |
| `description` | \*const char |  |
| `value` | \*const char |  |
| `defaultValue` | \*const char |  |
| `flags` | i32 |  |

---

<a id="struct-cmd"></a>

### struct Cmd

*public* | *stdlib/std/cmdline.lita:37*

| Field | Type | Description |
|-------|------|-------------|
| `name` | \*const char |  |
| `description` | \*const char |  |
| `options` | [Array](std_array.md#struct-array)\<[Option](std_cmdline.md#struct-option)\> |  |
| `hasArg` | bool |  |
| `argValue` | \*const char |  |

---

<a id="struct-cmdparser"></a>

### struct CmdParser

*public* | *stdlib/std/cmdline.lita:45*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `commands` | [Array](std_array.md#struct-array)\<[Cmd](std_cmdline.md#struct-cmd)\> |  |
| `args` | [Array](std_array.md#struct-array)\<\*const char\> |  |
| `errors` | \[\]char |  |
| `status` | [CmdParserStatus](std_cmdline.md#enum-cmdparserstatus) |  |
| `header` | \*const char |  |
| `defaultCmd` | \*[Cmd](std_cmdline.md#struct-cmd) |  |
| `cmd` | \*[Cmd](std_cmdline.md#struct-cmd) |  |
| `cmdArgCount` | i32 |  |
| `cmdArgs` | \*\*char |  |

---

