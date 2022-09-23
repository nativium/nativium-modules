#pragma once

#include "nativium/helper/JsonHelper.hpp"
#include "nativium/net/http/HttpCookieJson.hpp"
#include "nativium/net/http/HttpHeaderJson.hpp"
#include "nativium/net/http/HttpRequest.hpp"
#include "nativium/net/http/HttpRequestParamJson.hpp"
#include "nlohmann/json.hpp"

#include <string>
#include <vector>

using namespace nativium::net::http;
using namespace nativium::helper;

namespace nlohmann
{
template <>
struct adl_serializer<HttpRequest>
{
    static HttpRequest from_json(const json &j)
    {
        auto o = HttpRequest{"", HttpMethod::METHOD_GET, {}, {}, {}, ""};

        o.url = JsonHelper::getString(j, "url");
        o.body = JsonHelper::getString(j, "body");

        // headers
        if (j.contains("headers"))
        {
            try
            {
                o.headers = j["headers"].get<std::vector<HttpHeader>>();
            }
            catch (const std::exception &e)
            {
                // ignore
            }
        }

        // cookies
        if (j.contains("cookies"))
        {
            try
            {
                o.cookies = j["cookies"].get<std::vector<HttpCookie>>();
            }
            catch (const std::exception &e)
            {
                // ignore
            }
        }

        // params
        if (j.contains("params"))
        {
            try
            {
                o.params = j["params"].get<std::vector<HttpRequestParam>>();
            }
            catch (const std::exception &e)
            {
                // ignore
            }
        }

        // method
        auto method = JsonHelper::getInt32(j, "method");

        if (method == static_cast<int>(HttpMethod::METHOD_CONNECT))
        {
            o.method = HttpMethod::METHOD_CONNECT;
        }
        else if (method == static_cast<int>(HttpMethod::METHOD_DELETE))
        {
            o.method = HttpMethod::METHOD_DELETE;
        }
        else if (method == static_cast<int>(HttpMethod::METHOD_GET))
        {
            o.method = HttpMethod::METHOD_GET;
        }
        else if (method == static_cast<int>(HttpMethod::METHOD_HEAD))
        {
            o.method = HttpMethod::METHOD_HEAD;
        }
        else if (method == static_cast<int>(HttpMethod::METHOD_OPTIONS))
        {
            o.method = HttpMethod::METHOD_OPTIONS;
        }
        else if (method == static_cast<int>(HttpMethod::METHOD_PATCH))
        {
            o.method = HttpMethod::METHOD_PATCH;
        }
        else if (method == static_cast<int>(HttpMethod::METHOD_POST))
        {
            o.method = HttpMethod::METHOD_POST;
        }
        else if (method == static_cast<int>(HttpMethod::METHOD_PUT))
        {
            o.method = HttpMethod::METHOD_PUT;
        }
        else if (method == static_cast<int>(HttpMethod::METHOD_TRACE))
        {
            o.method = HttpMethod::METHOD_TRACE;
        }

        return o;
    }

    static void to_json(json &j, HttpRequest o)
    {
        j = nlohmann::json{
            {"url", o.url},
            {"method", o.method},
            {"params", o.params},
            {"headers", o.headers},
            {"cookies", o.cookies},
            {"body", o.body},
        };
    }
};
} // namespace nlohmann
