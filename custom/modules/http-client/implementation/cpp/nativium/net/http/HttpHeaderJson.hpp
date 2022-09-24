#pragma once

#include "nativium/helper/JsonHelper.hpp"
#include "nativium/net/http/HttpHeader.hpp"
#include "nlohmann/json.hpp"

#include <string>

using namespace nativium::net::http;
using namespace nativium::helper;

namespace nlohmann
{
template <>
struct adl_serializer<HttpHeader>
{
    static HttpHeader from_json(const json &j)
    {
        return HttpHeader{
            JsonHelper::getString(j, "name"),
            JsonHelper::getString(j, "value"),
        };
    }

    static void to_json(json &j, HttpHeader o)
    {
        j = nlohmann::json{
            {"name", o.name},
            {"value", o.value},
        };
    }
};
} // namespace nlohmann
