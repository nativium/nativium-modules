import { HttpMethod } from "../../../nativium/modules/http-client/gluecode/generated-src/ts/http-client";

class SimpleHttpClientPlatformService {
    /** @param {import("../../../nativium/modules/http-client/gluecode/generated-src/ts/http-client").HttpRequest} r */
    getMethodFromRequest(r) {
        switch (r.method) {
            case HttpMethod.METHOD_GET:
                return "GET";
            case HttpMethod.METHOD_POST:
                return "POST";
            case HttpMethod.METHOD_HEAD:
                return "HEAD";
            case HttpMethod.METHOD_PUT:
                return "PUT";
            case HttpMethod.METHOD_DELETE:
                return "DELETE";
            case HttpMethod.METHOD_PATCH:
                return "PATCH";
            case HttpMethod.METHOD_CONNECT:
                return "CONNECT";
            case HttpMethod.METHOD_OPTIONS:
                return "OPTIONS";
            case HttpMethod.METHOD_TRACE:
                return "TRACE";
        }
    }

    getXhrResponseHeaders(xhr) {
        var headers = [];

        try {
            // process headers
            const xhrHeadersRaw = xhr.getAllResponseHeaders();
            const xhrHeaders = xhrHeadersRaw.trim().split(/[\r\n]+/);

            // create a map of header names to values
            xhrHeaders.forEach((line) => {
                const parts = line.split(": ");
                const header = parts.shift();
                const value = parts.join(": ");

                headers.push({
                    name: header,
                    value: value,
                });
            });
        } catch {
            // ignore
        }

        return headers;
    }

    /** @param {import("../../../nativium/modules/http-client/gluecode/generated-src/ts/http-client").HttpRequest} r */
    doRequest(r) {
        /** @type {import("../../../nativium/modules/http-client/gluecode/generated-src/ts/http-client").HttpResponse} */
        var response = {
            code: 0,
            body: "",
            headers: [],
            cookies: [],
            url: r.url,
        };

        // parameters
        var params = null;

        if (r.method == HttpMethod.METHOD_GET) {
            params = null;
        } else {
            if (r.params && r.params.length > 0) {
                params = "";

                for (var p = 0; p < r.params.length; p++) {
                    if (params.length == 0) {
                        params += r.params[p].name + "=" + r.params[p].value;
                    } else {
                        params +=
                            "&" + r.params[p].name + "=" + r.params[p].value;
                    }
                }
            } else {
                if (r.body.length > 0) {
                    params = r.body;
                }
            }
        }

        // connection
        try {
            let xhr = new XMLHttpRequest();
            // eslint-disable-next-line no-undef
            if (!("withCredentials" in xhr)) xhr = new XDomainRequest(); // fix IE8/9
            xhr.open(this.getMethodFromRequest(r), r.url, false); // false=sync and true=async

            // set headers
            if (r.headers && r.headers.length > 0) {
                for (var h = 0; h < r.headers.length; h++) {
                    xhr.setRequestHeader(r.headers[h].name, r.headers[h].value);
                }
            }

            var self = this;

            // load callback
            xhr.onload = function () {
                if (xhr.status >= 200 && xhr.status < 300) {
                    response.code = xhr.status;
                    response.body = xhr.responseText;
                    response.headers = self.getXhrResponseHeaders(xhr);

                    return response;
                } else {
                    response.code = xhr.status;
                    response.body = xhr.responseText;
                    response.headers = self.getXhrResponseHeaders(xhr);

                    return response;
                }
            };

            // error callback
            xhr.onerror = function () {
                response.code = xhr.status;
                response.body = xhr.responseText;
                response.headers = self.getXhrResponseHeaders(xhr);

                return response;
            };

            // execute
            xhr.send(params);

            return response;
        } catch (error) {
            return response;
        }
    }
}

export default SimpleHttpClientPlatformService;
