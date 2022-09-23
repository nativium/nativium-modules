#pragma once

#include "nativium/helper/JsonHelper.hpp"
#include "nativium/net/http/HttpCookieJson.hpp"
#include "nativium/net/http/HttpHeaderJson.hpp"
#include "nativium/net/http/HttpRequestParamJson.hpp"
#include "nativium/net/http/HttpResponse.hpp"
#include "nlohmann/json.hpp"

#include <string>
#include <vector>

using namespace nativium::net::http;
using namespace nativium::helper;

namespace nlohmann
{
template <>
struct adl_serializer<HttpResponse>
{
    static HttpResponse from_json(const json &j)
    {
        auto o = HttpResponse{0, "", "", {}, {}};

        o.url = JsonHelper::getString(j, "url");
        o.code = JsonHelper::getInt32(j, "code");
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

        return o;
    }

    static void to_json(json &j, HttpResponse o)
    {
        j = nlohmann::json{
            {"url", o.url},
            {"code", o.code},

            {"body", o.body},
            {"headers", o.headers},
            {"cookies", o.cookies},
        };
    }
};
} // namespace nlohmann
