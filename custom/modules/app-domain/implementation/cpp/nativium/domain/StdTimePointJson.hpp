#pragma once

#include "nativium/time/DateTime.hpp"
#include "nlohmann/json.hpp"
#include <chrono>

using namespace nativium::time;

namespace nlohmann
{
template <typename Clock, typename Duration>
struct adl_serializer<std::chrono::time_point<Clock, Duration>>
{
    static void to_json(json &j, const std::chrono::time_point<Clock, Duration> &tp)
    {
        j = DateTime::getStringFromDateTime(tp);
    }

    static void from_json(const json &j, std::chrono::time_point<Clock, Duration> &value)
    {
        if (j.is_null())
        {
            auto dur = std::chrono::milliseconds(0);
            value = DateTime::getTimestampInMillisecondsFromDateTime(std::chrono::time_point<std::chrono::system_clock>(dur));
        }
        else
        {
            auto dur = std::chrono::milliseconds(j);
            value = DateTime::getTimestampInMillisecondsFromDateTime(std::chrono::time_point<std::chrono::system_clock>(dur));
        }
    }
};
} // namespace nlohmann
