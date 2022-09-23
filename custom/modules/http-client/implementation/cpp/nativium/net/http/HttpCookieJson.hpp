#pragma once

#include "nativium/helper/JsonHelper.hpp"
#include "nativium/net/http/HttpCookie.hpp"
#include "nlohmann/json.hpp"

#include <string>

using namespace nativium::net::http;
using namespace nativium::helper;

namespace nlohmann
{
template <>
struct adl_serializer<HttpCookie>
{
    static HttpCookie from_json(const json &j)
    {
        return HttpCookie{
            JsonHelper::getString(j, "name"),
            JsonHelper::getString(j, "value"),
        };
    }

    static void to_json(json &j, HttpCookie o)
    {
        j = nlohmann::json{
            {"name", o.name},
            {"value", o.value},
        };
    }
};
} // namespace nlohmann
