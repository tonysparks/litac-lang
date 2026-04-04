# std::http::libcurl

## Functions

<a id="func-curl_global_init"></a>

### func curl_global_init(flags: i32) : [CURLcode](std_http_libcurl.md#enum-curlcode)

*public* | *stdlib/std/http/libcurl/libcurl.lita:119*

---

<a id="func-curl_global_cleanup"></a>

### func curl_global_cleanup() : void

*public* | *stdlib/std/http/libcurl/libcurl.lita:122*

---

<a id="func-curl_easy_init"></a>

### func curl_easy_init() : \*[CURL](std_http_libcurl.md#struct-curl)

*public* | *stdlib/std/http/libcurl/libcurl.lita:125*

---

<a id="func-curl_easy_cleanup"></a>

### func curl_easy_cleanup(curl: \*[CURL](std_http_libcurl.md#struct-curl)) : void

*public* | *stdlib/std/http/libcurl/libcurl.lita:128*

---

<a id="func-curl_easy_setopt"></a>

### func curl_easy_setopt\<T\>(curl: \*[CURL](std_http_libcurl.md#struct-curl), option: [CURLoption](std_http_libcurl.md#enum-curloption), parameter: T) : [CURLcode](std_http_libcurl.md#enum-curlcode)

*public* | *stdlib/std/http/libcurl/libcurl.lita:131*

---

<a id="func-curl_easy_perform"></a>

### func curl_easy_perform(curl: \*[CURL](std_http_libcurl.md#struct-curl)) : [CURLcode](std_http_libcurl.md#enum-curlcode)

*public* | *stdlib/std/http/libcurl/libcurl.lita:134*

---

<a id="func-curl_easy_getinfo"></a>

### func curl_easy_getinfo(curl: \*[CURL](std_http_libcurl.md#struct-curl), option: [CURLinfo](std_http_libcurl.md#enum-curlinfo), value: \*void) : [CURLcode](std_http_libcurl.md#enum-curlcode)

*public* | *stdlib/std/http/libcurl/libcurl.lita:137*

---

<a id="func-curl_easy_strerror"></a>

### func curl_easy_strerror(code: [CURLcode](std_http_libcurl.md#enum-curlcode)) : \*const char

*public* | *stdlib/std/http/libcurl/libcurl.lita:140*

---

<a id="func-curl_slist_append"></a>

### func curl_slist_append(list: \*[curl_slist](std_http_libcurl.md#struct-curl_slist), str: \*const char) : \*[curl_slist](std_http_libcurl.md#struct-curl_slist)

*public* | *stdlib/std/http/libcurl/libcurl.lita:143*

---

<a id="func-curl_slist_free_all"></a>

### func curl_slist_free_all(list: \*[curl_slist](std_http_libcurl.md#struct-curl_slist)) : void

*public* | *stdlib/std/http/libcurl/libcurl.lita:146*

---

## Types

<a id="struct-curl"></a>

### struct CURL

*public* | *stdlib/std/http/libcurl/libcurl.lita:113*

---

<a id="struct-curl_slist"></a>

### struct curl_slist

*public* | *stdlib/std/http/libcurl/libcurl.lita:116*

---

<a id="enum-curlflags"></a>

### enum CURLflags

*public* | *stdlib/std/http/libcurl/libcurl.lita:150*

| Value | Description |
|-------|-------------|
| `CURL_GLOBAL_ALL` |  |
| `CURL_GLOBAL_SSL` |  |
| `CURL_GLOBAL_WIN32` |  |
| `CURL_GLOBAL_NOTHING` |  |
| `CURL_GLOBAL_DEFAULT` |  |
| `CURL_GLOBAL_ACK_EINTR` |  |

---

<a id="enum-curloption"></a>

### enum CURLoption

*public* | *stdlib/std/http/libcurl/libcurl.lita:160*

| Value | Description |
|-------|-------------|
| `CURLOPT_URL` |  |
| `CURLOPT_WRITEFUNCTION` |  |
| `CURLOPT_WRITEDATA` |  |
| `CURLOPT_READFUNCTION` |  |
| `CURLOPT_INFILESIZE_LARGE` |  |
| `CURLOPT_READDATA` |  |
| `CURLOPT_PROXY` |  |
| `CURLOPT_NOPROGRESS` |  |
| `CURLOPT_USERAGENT` |  |
| `CURLOPT_SSL_VERIFYPEER` |  |
| `CURLOPT_CAINFO` |  |
| `CURLOPT_FOLLOWLOCATION` |  |
| `CURLOPT_MAXREDIRS` |  |
| `CURLOPT_HTTPHEADER` |  |
| `CURLOPT_HEADERFUNCTION` |  |
| `CURLOPT_HEADERDATA` |  |
| `CURLOPT_ACCEPT_ENCODING` |  |
| `CURLOPT_POSTFIELDS` |  |
| `CURLOPT_POSTFIELDSIZE` |  |
| `CURLOPT_POSTFIELDSIZE_LARGE` |  |
| `CURLOPT_POST` |  |
| `CURLOPT_CUSTOMREQUEST` |  |
| `CURLOPT_HTTPGET` |  |
| `CURLOPT_NOBODY` |  |
| `CURLOPT_UPLOAD` |  |

---

<a id="enum-curlinfo"></a>

### enum CURLinfo

*public* | *stdlib/std/http/libcurl/libcurl.lita:189*

| Value | Description |
|-------|-------------|
| `CURLINFO_NONE` |  |
| `CURLINFO_EFFECTIVE_URL` |  |
| `CURLINFO_RESPONSE_CODE` |  |
| `CURLINFO_TOTAL_TIME` |  |
| `CURLINFO_NAMELOOKUP_TIME` |  |
| `CURLINFO_CONNECT_TIME` |  |
| `CURLINFO_PRETRANSFER_TIME` |  |
| `CURLINFO_SIZE_UPLOAD` |  |
| `CURLINFO_SIZE_UPLOAD_T` |  |
| `CURLINFO_SIZE_DOWNLOAD` |  |
| `CURLINFO_SIZE_DOWNLOAD_T` |  |
| `CURLINFO_SPEED_DOWNLOAD` |  |
| `CURLINFO_SPEED_DOWNLOAD_T` |  |
| `CURLINFO_SPEED_UPLOAD` |  |
| `CURLINFO_SPEED_UPLOAD_T` |  |
| `CURLINFO_HEADER_SIZE` |  |
| `CURLINFO_REQUEST_SIZE` |  |
| `CURLINFO_SSL_VERIFYRESULT` |  |
| `CURLINFO_FILETIME` |  |
| `CURLINFO_FILETIME_T` |  |
| `CURLINFO_CONTENT_LENGTH_DOWNLOAD` |  |
| `CURLINFO_CONTENT_LENGTH_DOWNLOAD_T` |  |
| `CURLINFO_CONTENT_LENGTH_UPLOAD` |  |
| `CURLINFO_CONTENT_LENGTH_UPLOAD_T` |  |
| `CURLINFO_STARTTRANSFER_TIME` |  |
| `CURLINFO_CONTENT_TYPE` |  |
| `CURLINFO_REDIRECT_TIME` |  |
| `CURLINFO_REDIRECT_COUNT` |  |
| `CURLINFO_PRIVATE` |  |
| `CURLINFO_HTTP_CONNECTCODE` |  |
| `CURLINFO_HTTPAUTH_AVAIL` |  |
| `CURLINFO_PROXYAUTH_AVAIL` |  |
| `CURLINFO_OS_ERRNO` |  |
| `CURLINFO_NUM_CONNECTS` |  |
| `CURLINFO_SSL_ENGINES` |  |
| `CURLINFO_COOKIELIST` |  |
| `CURLINFO_LASTSOCKET` |  |
| `CURLINFO_FTP_ENTRY_PATH` |  |
| `CURLINFO_REDIRECT_URL` |  |
| `CURLINFO_PRIMARY_IP` |  |
| `CURLINFO_APPCONNECT_TIME` |  |
| `CURLINFO_CERTINFO` |  |
| `CURLINFO_CONDITION_UNMET` |  |
| `CURLINFO_RTSP_SESSION_ID` |  |
| `CURLINFO_RTSP_CLIENT_CSEQ` |  |
| `CURLINFO_RTSP_SERVER_CSEQ` |  |
| `CURLINFO_RTSP_CSEQ_RECV` |  |
| `CURLINFO_PRIMARY_PORT` |  |
| `CURLINFO_LOCAL_IP` |  |
| `CURLINFO_LOCAL_PORT` |  |
| `CURLINFO_TLS_SESSION` |  |
| `CURLINFO_ACTIVESOCKET` |  |
| `CURLINFO_TLS_SSL_PTR` |  |
| `CURLINFO_HTTP_VERSION` |  |
| `CURLINFO_PROXY_SSL_VERIFYRESULT` |  |
| `CURLINFO_PROTOCOL` |  |
| `CURLINFO_SCHEME` |  |
| `CURLINFO_TOTAL_TIME_T` |  |
| `CURLINFO_NAMELOOKUP_TIME_T` |  |
| `CURLINFO_CONNECT_TIME_T` |  |
| `CURLINFO_PRETRANSFER_TIME_T` |  |
| `CURLINFO_STARTTRANSFER_TIME_T` |  |
| `CURLINFO_REDIRECT_TIME_T` |  |
| `CURLINFO_APPCONNECT_TIME_T` |  |
| `CURLINFO_RETRY_AFTER` |  |
| `CURLINFO_EFFECTIVE_METHOD` |  |
| `CURLINFO_PROXY_ERROR` |  |
| `CURLINFO_LASTONE` |  |

---

<a id="enum-curlcode"></a>

### enum CURLcode

*public* | *stdlib/std/http/libcurl/libcurl.lita:262*

| Value | Description |
|-------|-------------|
| `CURLE_OK` |  |
| `CURLE_UNSUPPORTED_PROTOCOL` |  |
| `CURLE_FAILED_INIT` |  |
| `CURLE_URL_MALFORMAT` |  |
| `CURLE_NOT_BUILT_IN` |  |
| `CURLE_COULDNT_RESOLVE_PROXY` |  |
| `CURLE_COULDNT_RESOLVE_HOST` |  |
| `CURLE_COULDNT_CONNECT` |  |
| `CURLE_WEIRD_SERVER_REPLY` |  |
| `CURLE_REMOTE_ACCESS_DENIED` |  |
| `CURLE_FTP_ACCEPT_FAILED` |  |
| `CURLE_FTP_WEIRD_PASS_REPLY` |  |
| `CURLE_FTP_ACCEPT_TIMEOUT` |  |
| `CURLE_FTP_WEIRD_PASV_REPLY` |  |
| `CURLE_FTP_WEIRD_227_FORMAT` |  |
| `CURLE_FTP_CANT_GET_HOST` |  |
| `CURLE_HTTP2` |  |
| `CURLE_FTP_COULDNT_SET_TYPE` |  |
| `CURLE_PARTIAL_FILE` |  |
| `CURLE_FTP_COULDNT_RETR_FILE` |  |
| `CURLE_OBSOLETE20` |  |
| `CURLE_QUOTE_ERROR` |  |
| `CURLE_HTTP_RETURNED_ERROR` |  |
| `CURLE_WRITE_ERROR` |  |
| `CURLE_OBSOLETE24` |  |
| `CURLE_UPLOAD_FAILED` |  |
| `CURLE_READ_ERROR` |  |
| `CURLE_OUT_OF_MEMORY` |  |
| `CURLE_OPERATION_TIMEDOUT` |  |
| `CURLE_OBSOLETE29` |  |
| `CURLE_FTP_PORT_FAILED` |  |
| `CURLE_FTP_COULDNT_USE_REST` |  |
| `CURLE_OBSOLETE32` |  |
| `CURLE_RANGE_ERROR` |  |
| `CURLE_HTTP_POST_ERROR` |  |
| `CURLE_SSL_CONNECT_ERROR` |  |
| `CURLE_BAD_DOWNLOAD_RESUME` |  |
| `CURLE_FILE_COULDNT_READ_FILE` |  |
| `CURLE_LDAP_CANNOT_BIND` |  |
| `CURLE_LDAP_SEARCH_FAILED` |  |
| `CURLE_OBSOLETE40` |  |
| `CURLE_FUNCTION_NOT_FOUND` |  |
| `CURLE_ABORTED_BY_CALLBACK` |  |
| `CURLE_BAD_FUNCTION_ARGUMENT` |  |
| `CURLE_OBSOLETE44` |  |
| `CURLE_INTERFACE_FAILED` |  |
| `CURLE_OBSOLETE46` |  |
| `CURLE_TOO_MANY_REDIRECTS` |  |
| `CURLE_UNKNOWN_OPTION` |  |
| `CURLE_TELNET_OPTION_SYNTAX` |  |
| `CURLE_OBSOLETE50` |  |
| `CURLE_OBSOLETE51` |  |
| `CURLE_GOT_NOTHING` |  |
| `CURLE_SSL_ENGINE_NOTFOUND` |  |
| `CURLE_SSL_ENGINE_SETFAILED` |  |
| `CURLE_SEND_ERROR` |  |
| `CURLE_RECV_ERROR` |  |
| `CURLE_OBSOLETE57` |  |
| `CURLE_SSL_CERTPROBLEM` |  |
| `CURLE_SSL_CIPHER` |  |
| `CURLE_PEER_FAILED_VERIFICATION` |  |
| `CURLE_BAD_CONTENT_ENCODING` |  |
| `CURLE_LDAP_INVALID_URL` |  |
| `CURLE_FILESIZE_EXCEEDED` |  |
| `CURLE_USE_SSL_FAILED` |  |
| `CURLE_SEND_FAIL_REWIND` |  |
| `CURLE_SSL_ENGINE_INITFAILED` |  |
| `CURLE_LOGIN_DENIED` |  |
| `CURLE_TFTP_NOTFOUND` |  |
| `CURLE_TFTP_PERM` |  |
| `CURLE_REMOTE_DISK_FULL` |  |
| `CURLE_TFTP_ILLEGAL` |  |
| `CURLE_TFTP_UNKNOWNID` |  |
| `CURLE_REMOTE_FILE_EXISTS` |  |
| `CURLE_TFTP_NOSUCHUSER` |  |
| `CURLE_CONV_FAILED` |  |
| `CURLE_CONV_REQD` |  |
| `CURLE_SSL_CACERT_BADFILE` |  |
| `CURLE_REMOTE_FILE_NOT_FOUND` |  |
| `CURLE_SSH` |  |
| `CURLE_SSL_SHUTDOWN_FAILED` |  |
| `CURLE_AGAIN` |  |
| `CURLE_SSL_CRL_BADFILE` |  |
| `CURLE_SSL_ISSUER_ERROR` |  |
| `CURLE_FTP_PRET_FAILED` |  |
| `CURLE_RTSP_CSEQ_ERROR` |  |
| `CURLE_RTSP_SESSION_ERROR` |  |
| `CURLE_FTP_BAD_FILE_LIST` |  |
| `CURLE_CHUNK_FAILED` |  |
| `CURLE_NO_CONNECTION_AVAILABLE` |  |
| `CURLE_SSL_PINNEDPUBKEYNOTMATCH` |  |
| `CURLE_SSL_INVALIDCERTSTATUS` |  |
| `CURLE_HTTP2_STREAM` |  |
| `CURLE_RECURSIVE_API_CALL` |  |
| `CURLE_AUTH_ERROR` |  |
| `CURLE_HTTP3` |  |
| `CURLE_QUIC_CONNECT_ERROR` |  |
| `CURLE_PROXY` |  |
| `CURL_LAST` |  |

---

