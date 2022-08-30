#pragma once

#include "nativium/helper/JsonHelper.hpp"
#include "nativium/helper/TodoHelper.hpp"
#include "nativium/time/DateTime.hpp"
#include "nlohmann/json.hpp"

#include <string>
#include <vector>

using namespace nativium::domain;
using namespace nativium::helper;
using namespace nativium::time;

namespace nlohmann
{
template <>
struct adl_serializer<Todo>
{
    static Todo from_json(const json &j)
    {
        auto o = TodoHelper::create();

        o.id = JsonHelper::getInt64(j, "id");
        o.title = JsonHelper::getString(j, "title");
        o.body = JsonHelper::getString(j, "body");
        o.data = JsonHelper::getMap(j, "data");
        o.done = JsonHelper::getBool(j, "done");
        o.createdAt = JsonHelper::getDateTimeFromTimestampInMilliseconds(j, "created_at");
        o.updatedAt = JsonHelper::getDateTimeFromTimestampInMilliseconds(j, "updated_at");

        return o;
    }

    static void to_json(json &j, Todo o)
    {
        j = nlohmann::json{
            {"id", o.id},
            {"title", o.title},
            {"body", o.body},
            {"data", o.data},
            {"done", o.done},
            {"created_at", DateTime::getStringFromDateTime(o.createdAt)},
            {"updated_at", DateTime::getStringFromDateTime(o.updatedAt)},
        };
    }
};
} // namespace nlohmann

/*
#include "nativium/domain/StdTimePointJson.hpp"

namespace nativium
{
namespace domain
{

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Todo, id, title, body, data, done, createdAt, updatedAt)

} // namespace domain
} // namespace nativium
*/
