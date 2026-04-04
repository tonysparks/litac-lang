# std::test::test

## Functions

<a id="func-setjmp"></a>

### func setjmp(env: [jmp_buf](std_test_test.md#struct-jmp_buf)) : i32

*public* | *stdlib/std/test/test.lita:24*

---

<a id="func-init"></a>

### func (this: \*[TestSuite](std_test_test.md#struct-testsuite)) init(allocator: \*const [Allocator](std_mem.md#struct-allocator)) : void

*public* | *stdlib/std/test/test.lita:77*

---

<a id="func-free"></a>

### func (this: \*[TestSuite](std_test_test.md#struct-testsuite)) free() : void

*public* | *stdlib/std/test/test.lita:87*

---

<a id="func-entertest"></a>

### func (this: \*[TestSuite](std_test_test.md#struct-testsuite)) enterTest() : \*[TestCase](std_test_test.md#struct-testcase)

*public* | *stdlib/std/test/test.lita:101*

---

<a id="func-adddynamictest"></a>

### func (this: \*[TestSuite](std_test_test.md#struct-testsuite)) addDynamicTest(name: \*const char, userData: \*void, testFn: func(\*[TestCase](std_test_test.md#struct-testcase), \*void) : void, cleanupFn: func(\*[TestCase](std_test_test.md#struct-testcase), \*void) : void) : \*[TestCase](std_test_test.md#struct-testcase)

*public* | *stdlib/std/test/test.lita:112*

---

<a id="func-enterdynamictest"></a>

### func (this: \*[TestSuite](std_test_test.md#struct-testsuite)) enterDynamicTest() : \*[TestCase](std_test_test.md#struct-testcase)

*public* | *stdlib/std/test/test.lita:130*

---

<a id="func-executedynamictest"></a>

### func (this: \*[TestSuite](std_test_test.md#struct-testsuite)) executeDynamicTest() : void

*public* | *stdlib/std/test/test.lita:141*

---

<a id="func-printdynamictest"></a>

### func (this: \*[TestSuite](std_test_test.md#struct-testsuite)) printDynamicTest(isJsonFormat: bool) : void

*public* | *stdlib/std/test/test.lita:152*

---

<a id="func-init"></a>

### func (this: \*[TestCase](std_test_test.md#struct-testcase)) init(testSuite: \*[TestSuite](std_test_test.md#struct-testsuite)) : void

*public* | *stdlib/std/test/test.lita:160*

---

<a id="func-free"></a>

### func (this: \*[TestCase](std_test_test.md#struct-testcase)) free() : void

*public* | *stdlib/std/test/test.lita:165*

---

<a id="func-reset"></a>

### func (this: \*[TestCase](std_test_test.md#struct-testcase)) reset() : void

*public* | *stdlib/std/test/test.lita:169*

---

<a id="func-adderror"></a>

### func (this: \*[TestCase](std_test_test.md#struct-testcase)) addError(error: \*const char, filename: \*const char, lineNumber: usize) : void

*public* | *stdlib/std/test/test.lita:173*

---

<a id="func-printresults"></a>

### func (this: \*[TestCase](std_test_test.md#struct-testcase)) printResults(name: \*const char, isJson: bool) : void

*public* | *stdlib/std/test/test.lita:187*

---

<a id="func-assertcstr"></a>

### func AssertCStr(expected: \*const char, actual: \*const char, filename: \*const char, lineNumber: usize) : void

*public* | *stdlib/std/test/test.lita:256*

---

<a id="func-assertfloat"></a>

### func AssertFloat\<F\>(expected: F, actual: F, tolerance: F, filename: \*const char, lineNumber: usize) : void

*public* | *stdlib/std/test/test.lita:270*

---

<a id="func-assert"></a>

### func Assert(cond: bool, filename: \*const char, lineNumber: usize) : void

*public* | *stdlib/std/test/test.lita:286*

---

## Types

<a id="struct-jmp_buf"></a>

### struct jmp_buf

*public* | *stdlib/std/test/test.lita:18*

---

<a id="enum-teststatus"></a>

### enum TestStatus

*public* | *stdlib/std/test/test.lita:33*

| Value | Description |
|-------|-------------|
| `SUCCESS` |  |
| `FAILED` |  |
| `DISABLED` |  |

---

<a id="struct-testinfomessage"></a>

### struct TestInfoMessage

*public* | *stdlib/std/test/test.lita:40*

| Field | Type | Description |
|-------|------|-------------|
| `type` | \*const char |  |
| `name` | \*const char |  |
| `status` | [TestStatus](std_test_test.md#enum-teststatus) |  |
| `errors` | [Array](std_array.md#struct-array)\<\*const char\> |  |
| `durationMSec` | f64 |  |

---

<a id="struct-assertentry"></a>

### struct AssertEntry

*public* | *stdlib/std/test/test.lita:48*

| Field | Type | Description |
|-------|------|-------------|
| `filename` | \*const char |  |
| `lineNumber` | usize |  |
| `errorMessage` | \*const char |  |

---

<a id="struct-testsuite"></a>

### struct TestSuite

*public* | *stdlib/std/test/test.lita:54*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `testCases` | [Array](std_array.md#struct-array)\<[TestCase](std_test_test.md#struct-testcase)\> |  |
| `currentCase` | \*[TestCase](std_test_test.md#struct-testcase) |  |
| `env` | [jmp_buf](std_test_test.md#struct-jmp_buf) |  |
| `dynamicTestCases` | [Array](std_array.md#struct-array)\<[TestCase](std_test_test.md#struct-testcase)\> |  |
| `index` | i32 |  |

---

<a id="struct-testcase"></a>

### struct TestCase

*public* | *stdlib/std/test/test.lita:64*

| Field | Type | Description |
|-------|------|-------------|
| `testSuite` | \*[TestSuite](std_test_test.md#struct-testsuite) |  |
| `errors` | [Array](std_array.md#struct-array)\<[AssertEntry](std_test_test.md#struct-assertentry)\> |  |
| `startTime` | f64 |  |
| `isDisabled` | bool |  |
| `name` | \*const char |  |
| `userData` | \*void |  |
| `testFn` | func(\*[TestCase](std_test_test.md#struct-testcase), \*void) : void |  |
| `cleanupFn` | func(\*[TestCase](std_test_test.md#struct-testcase), \*void) : void |  |

---

## Variables and Constants

<a id="var-testsuite"></a>

### var testSuite

*public* | *stdlib/std/test/test.lita:26*

---

