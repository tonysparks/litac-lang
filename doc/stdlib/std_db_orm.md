# std::db::orm

## Functions

<a id="func-querymany"></a>

### func (this: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) queryMany\<T\>(allocator: \*const [Allocator](std_mem.md#struct-allocator), result: \*[Array](std_array.md#struct-array)\<T\>, alias: String, sql: String, ...) : i32

*public* | *stdlib/std/db/orm.lita:14*

---

<a id="func-queryonebyid"></a>

### func (this: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) queryOneById\<T, ID\>(result: \*T, id: ID) : i32

*public* | *stdlib/std/db/orm.lita:122*

---

<a id="func-insertmany"></a>

### func (this: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) insertMany\<T\>(items: \*[Array](std_array.md#struct-array)\<T\>) : i32

*public* | *stdlib/std/db/orm.lita:157*

---

<a id="func-insertone"></a>

### func (this: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) insertOne\<T\>(item: \*T) : i32

*public* | *stdlib/std/db/orm.lita:185*

---

<a id="func-deleteone"></a>

### func (this: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) deleteOne\<T\>(entity: \*T) : i32

*public* | *stdlib/std/db/orm.lita:212*

---

<a id="func-deletebyid"></a>

### func (this: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) deleteById\<T, ID\>(id: ID) : i32

*public* | *stdlib/std/db/orm.lita:235*

---

<a id="func-deletemany"></a>

### func (this: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) deleteMany\<T\>(entities: \*[Array](std_array.md#struct-array)\<T\>) : i32

*public* | *stdlib/std/db/orm.lita:259*

---

<a id="func-updateone"></a>

### func (this: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) updateOne\<T\>(entity: \*T) : i32

*public* | *stdlib/std/db/orm.lita:292*

---

<a id="func-updatemany"></a>

### func (this: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) updateMany\<T\>(entities: \*[Array](std_array.md#struct-array)\<T\>) : i32

*public* | *stdlib/std/db/orm.lita:316*

---

