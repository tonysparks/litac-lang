# dependency_graph

## Functions

<a id="func-init"></a>

### func (this: \*[DependencyGraph](dependency_graph.md#struct-dependencygraph)) init(lita: \*[Lita](lita.md#struct-lita)) : void

*public* | *src/dependency_graph.lita:57*

---

<a id="func-sort"></a>

### func (this: \*[DependencyGraph](dependency_graph.md#struct-dependencygraph)) sort() : Array\<\*[Symbol](symbols.md#struct-symbol)\>

*public* | *src/dependency_graph.lita:232*

---

## Types

<a id="struct-dependencygraph"></a>

### struct DependencyGraph

*public* | *src/dependency_graph.lita:30*


    Creates an ordering for C to handle compilation unit correction.  LitaC allows for
    out of order declarations -- but C does not -- this will order the symbols in C for
    proper compilation in C.

    The general algorithm is:
    1) Constant global primitives
    2) sort any Structs or Unions based on:
       Depends of their fields:
       a) if an aggregate has no aggregate types as fields (NOTE: Pointers to aggregates do not count,
          because C can calculate the size of the structure with pointers), it is considered 'resolved'
       b) otherwise create a list of 'dependencies' for this aggregate and place on 'unresolved' list
    3) take the aggregates in the 'unresolved' list and iterate thru them to see if they can be resolved
    4) Any global variables not in #1
    5) Functions


| Field | Type | Description |
|-------|------|-------------|
| `sortedPrimitives` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `sortedGlobals` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `sortedAggregates` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `sortedFuncs` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `sortedSymbols` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `dependencies` | Map\<\*[Symbol](symbols.md#struct-symbol), Dependency\> |  |
| `lita` | \*[Lita](lita.md#struct-lita) |  |

---

