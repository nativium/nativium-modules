#pragma once

#include "nativium/helper/JsonHelper.hpp"
#include "nativium/net/http/HttpRequestParam.hpp"
#include "nlohmann/json.hpp"

#include <string>

using namespace nativium::net::http;
using namespace nativium::helper;

namespace nlohmann
{
template <>
struct adl_serializer<HttpRequestParam>
{
    static HttpRequestParam from_json(const json &j)
    {
        return HttpRequestParam{
            JsonHelper::getString(j, "name"),
            JsonHelper::getString(j, "value"),
        };
    }

    static void to_json(json &j, HttpRequestParam o)
    {
        j = nlohmann::json{
            {"name", o.name},
            {"value", o.value},
        };
    }
};
} // namespace nlohmann
