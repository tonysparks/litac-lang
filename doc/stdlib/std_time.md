# std::time

## Functions

<a id="func-todatetime"></a>

### func (this: i64) toDateTime() : [DateTime](std_time.md#struct-datetime)

*public* | *stdlib/std/time/time.lita:85*

---

<a id="func-tooffsetdatetime"></a>

### func (this: \*[DateTime](std_time.md#struct-datetime)) toOffsetDateTime(offset: \*[Offset](std_time.md#struct-offset)) : [OffsetDateTime](std_time.md#struct-offsetdatetime)

*public* | *stdlib/std/time/time.lita:89*

---

<a id="func-toepochtime"></a>

### func (this: \*[DateTime](std_time.md#struct-datetime)) toEpochTime() : [EpochTime](std_time.md#typedef-epochtime)

*public* | *stdlib/std/time/time.lita:96*

---

<a id="func-format"></a>

### func (this: \*[DateTime](std_time.md#struct-datetime)) format(format: String, output: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer)) : [DateTimeStatus](std_time.md#enum-datetimestatus)

*public* | *stdlib/std/time/time.lita:100*

---

<a id="func-add"></a>

### func (this: \*[DateTime](std_time.md#struct-datetime)) add(amount: i32, unit: [TimeUnit](std_time.md#enum-timeunit)) : [DateTime](std_time.md#struct-datetime)

*public* | *stdlib/std/time/time.lita:108*

---

<a id="func-minus"></a>

### func (this: \*[DateTime](std_time.md#struct-datetime)) minus(amount: i32, unit: [TimeUnit](std_time.md#enum-timeunit)) : [DateTime](std_time.md#struct-datetime)

*public* | *stdlib/std/time/time.lita:112*

---

<a id="func-compare"></a>

### func (this: \*[DateTime](std_time.md#struct-datetime)) compare(other: \*[DateTime](std_time.md#struct-datetime)) : i32

*public* | *stdlib/std/time/time.lita:116*

---

<a id="func-isoformat"></a>

### func (this: \*[DateTime](std_time.md#struct-datetime)) isoFormat(output: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer)) : [DateTimeStatus](std_time.md#enum-datetimestatus)

*public* | *stdlib/std/time/time.lita:120*

---

<a id="func-now"></a>

### func Now() : [EpochTime](std_time.md#typedef-epochtime)

*public* | *stdlib/std/time/time.lita:128*

---

<a id="func-datetimenow"></a>

### func DateTimeNow() : [DateTime](std_time.md#struct-datetime)

*public* | *stdlib/std/time/time.lita:132*

---

<a id="func-datetimefrom"></a>

### func DateTimeFrom(format: String, value: String) : [DateTime](std_time.md#struct-datetime)

*public* | *stdlib/std/time/time.lita:136*

---

<a id="func-datetimefromiso"></a>

### func DateTimeFromIso(value: String) : [DateTime](std_time.md#struct-datetime)

*public* | *stdlib/std/time/time.lita:143*

---

<a id="func-todatetime"></a>

### func ToDateTime(epoch: [EpochTime](std_time.md#typedef-epochtime)) : [DateTime](std_time.md#struct-datetime)

*internal* | *stdlib/std/time/time.lita:207*

---

<a id="func-fromtm"></a>

### func FromTM(tm: \*tm) : [DateTime](std_time.md#struct-datetime)

*internal* | *stdlib/std/time/time.lita:214*

---

<a id="func-totm"></a>

### func ToTM(dateTime: \*[DateTime](std_time.md#struct-datetime), tm: \*tm) : \*tm

*internal* | *stdlib/std/time/time.lita:230*

---

<a id="func-datetimeadd"></a>

### func (this: \*[DateTime](std_time.md#struct-datetime)) DateTimeAdd(amount: i64, unit: [TimeUnit](std_time.md#enum-timeunit)) : [DateTime](std_time.md#struct-datetime)

*internal* | *stdlib/std/time/time.lita:240*

---

<a id="func-toepochtime"></a>

### func ToEpochTime(dateTime: \*[DateTime](std_time.md#struct-datetime)) : [EpochTime](std_time.md#typedef-epochtime)

*internal* | *stdlib/std/time/time.lita:291*

---

<a id="func-_now"></a>

### func _Now() : [EpochTime](std_time.md#typedef-epochtime)

*internal* | *stdlib/std/time/time.lita:298*

---

<a id="func-_datetimenow"></a>

### func _DateTimeNow() : [DateTime](std_time.md#struct-datetime)

*internal* | *stdlib/std/time/time.lita:303*

---

<a id="func-datetimeformat"></a>

### func DateTimeFormat(dateTime: \*[DateTime](std_time.md#struct-datetime), format: String, buffer: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer)) : [DateTimeStatus](std_time.md#enum-datetimestatus)

*internal* | *stdlib/std/time/time.lita:308*

---

<a id="func-_datetimefrom"></a>

### func _DateTimeFrom(format: String, value: String) : [DateTime](std_time.md#struct-datetime)

*internal* | *stdlib/std/time/time.lita:336*

---

## Types

<a id="typedef-epochtime"></a>

### typedef EpochTime = i64

*public* | *stdlib/std/time/time.lita:8*

---

<a id="typedef-duration"></a>

### typedef Duration = i64

*public* | *stdlib/std/time/time.lita:11*

---

<a id="struct-time"></a>

### struct Time

*public* | *stdlib/std/time/time.lita:14*

| Field | Type | Description |
|-------|------|-------------|
| `sec` | u8 |  |
| `min` | u8 |  |
| `hour` | u8 |  |

---

<a id="struct-date"></a>

### struct Date

*public* | *stdlib/std/time/time.lita:20*

| Field | Type | Description |
|-------|------|-------------|
| `year` | i32 |  |
| `month` | u8 |  |
| `day` | u8 |  |

---

<a id="struct-datetime"></a>

### struct DateTime

*public* | *stdlib/std/time/time.lita:27*

| Field | Type | Description |
|-------|------|-------------|
| `date` | [Date](std_time.md#struct-date) |  |
| `time` | [Time](std_time.md#struct-time) |  |

---

<a id="struct-offset"></a>

### struct Offset

*public* | *stdlib/std/time/time.lita:32*

| Field | Type | Description |
|-------|------|-------------|
| `min` | u8 |  |
| `hr` | u8 |  |

---

<a id="struct-offsetdatetime"></a>

### struct OffsetDateTime

*public* | *stdlib/std/time/time.lita:38*

| Field | Type | Description |
|-------|------|-------------|
| `dateTime` | [DateTime](std_time.md#struct-datetime) |  |
| `offset` | [Offset](std_time.md#struct-offset) |  |

---

<a id="enum-weekday"></a>

### enum Weekday

*public* | *stdlib/std/time/time.lita:43*

| Value | Description |
|-------|-------------|
| `Sunday` |  |
| `Monday` |  |
| `Tuesday` |  |
| `Wednesday` |  |
| `Thursday` |  |
| `Friday` |  |
| `Saturday` |  |

---

<a id="enum-month"></a>

### enum Month

*public* | *stdlib/std/time/time.lita:53*

| Value | Description |
|-------|-------------|
| `January` |  |
| `February` |  |
| `March` |  |
| `April` |  |
| `May` |  |
| `June` |  |
| `July` |  |
| `August` |  |
| `September` |  |
| `October` |  |
| `November` |  |
| `December` |  |

---

<a id="enum-timeunit"></a>

### enum TimeUnit

*public* | *stdlib/std/time/time.lita:68*

| Value | Description |
|-------|-------------|
| `NANOSECONDS` |  |
| `MILLISECONDS` |  |
| `SECONDS` |  |
| `MINUTES` |  |
| `HOURS` |  |
| `DAYS` |  |
| `MONTHS` |  |
| `YEARS` |  |

---

<a id="enum-datetimestatus"></a>

### enum DateTimeStatus

*public* | *stdlib/std/time/time.lita:79*

| Value | Description |
|-------|-------------|
| `OK` |  |
| `INVALID_INPUT_FORMAT` |  |

---

## Variables and Constants

<a id="const-iso_8601_date_format"></a>

### const ISO_8601_DATE_FORMAT

*public* | *stdlib/std/time/time.lita:5*

---

