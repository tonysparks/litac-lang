# std::profile

## Functions

<a id="func-startwatch"></a>

### func StartWatch(tag: [ProfileTag](std_profile.md#enum-profiletag)) : void

*public* | *stdlib/std/profile.lita:26*

---

<a id="func-stopwatch"></a>

### func StopWatch(tag: [ProfileTag](std_profile.md#enum-profiletag)) : void

*public* | *stdlib/std/profile.lita:33*

---

<a id="func-exporttimings"></a>

### func ExportTimings(filename: \*const char) : void

*public* | *stdlib/std/profile.lita:40*

---

## Types

<a id="enum-profiletag"></a>

### enum ProfileTag

*public* | *stdlib/std/profile.lita:7*

| Value | Description |
|-------|-------------|
| `MAX_PROFILE_TAGS` |  |

---

<a id="struct-profileentry"></a>

### struct ProfileEntry

*public* | *stdlib/std/profile.lita:18*

| Field | Type | Description |
|-------|------|-------------|
| `functionName` | \*const char |  |
| `count` | u64 |  |
| `startTime` | f64 |  |
| `totalTime` | f64 |  |

---

## Variables and Constants

<a id="const-profileentries"></a>

### const profileEntries

*public* | *stdlib/std/profile.lita:14*

---

