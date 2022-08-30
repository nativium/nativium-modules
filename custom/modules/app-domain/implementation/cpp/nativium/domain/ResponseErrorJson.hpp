#pragma once

#include "nativium/domain/ResponseError.hpp"
#include "nativium/helper/JsonHelper.hpp"
#include "nlohmann/json.hpp"

#include <string>

using namespace nativium::domain;
using namespace nativium::helper;

namespace nlohmann
{
template <>
struct adl_serializer<ResponseError>
{
    static ResponseError from_json(const json &j)
    {
        auto o = ResponseError{"", ""};

        o.field = JsonHelper::getBool(j, "field");
        o.message = JsonHelper::getString(j, "message");

        return o;
    }

    static void to_json(json &j, ResponseError o)
    {
        j = nlohmann::json{
            {"field", o.field},
            {"message", o.message},
        };
    }
};
} // namespace nlohmann
