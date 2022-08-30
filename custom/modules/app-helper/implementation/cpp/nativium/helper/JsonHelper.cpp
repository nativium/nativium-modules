#include "JsonHelper.hpp"
#include "nativium/time/DateTime.hpp"

namespace nativium
{
namespace helper
{

using namespace nativium::time;

std::string JsonHelper::getString(const nlohmann::json &j, const std::string &key, const std::string &defaultValue)
{
    if (j.contains(key))
    {
        auto &v = j[key];

        if (v.is_string())
        {
            return v.get<std::string>();
        }
    }

    return defaultValue;
}

int64_t JsonHelper::getInt64(const nlohmann::json &j, const std::string &key, const int64_t &defaultValue)
{
    if (j.contains(key))
    {
        auto &v = j[key];

        if (v.is_string())
        {
            return std::stoll(v.get<std::string>());
        }
        else if (v.is_number_integer())
        {
            return v.get<int64_t>();
        }
    }

    return defaultValue;
}

int32_t JsonHelper::getInt32(const nlohmann::json &j, const std::string &key, const int32_t &defaultValue)
{
    if (j.contains(key))
    {
        auto &v = j[key];

        if (v.is_string())
        {
            return std::stoi(v.get<std::string>());
        }
        else if (v.is_number_integer())
        {
            return v.get<int32_t>();
        }
    }

    return defaultValue;
}

bool JsonHelper::getBool(const nlohmann::json &j, const std::string &key, const bool &defaultValue)
{
    if (j.contains(key))
    {
        auto &v = j[key];

        if (v.is_string())
        {
            if (v.get<std::string>() == "1")
            {
                return true;
            }
            else if (v.get<std::string>() == "yes")
            {
                return true;
            }
        }
        else if (v.is_number_integer())
        {
            if (v.get<int32_t>() == 1)
            {
                return true;
            }
        }
        else if (v.is_boolean())
        {
            return v.get<bool>();
        }
    }

    return defaultValue;
}

float JsonHelper::getFloat(const nlohmann::json &j, const std::string &key, const float &defaultValue)
{
    if (j.contains(key))
    {
        auto &v = j[key];

        if (v.is_string())
        {
            return std::stof(v.get<std::string>());
        }
        else if (v.is_number_float())
        {
            return v.get<float>();
        }
    }

    return defaultValue;
}

double JsonHelper::getDouble(const nlohmann::json &j, const std::string &key, const double &defaultValue)
{
    if (j.contains(key))
    {
        auto &v = j[key];

        if (v.is_string())
        {
            return std::stod(v.get<std::string>());
        }
        else if (v.is_number_float())
        {
            return v.get<double>();
        }
    }

    return defaultValue;
}

std::string JsonHelper::getString(const nlohmann::json &j, const std::string &key)
{
    return getString(j, key, "");
}

int64_t JsonHelper::getInt64(const nlohmann::json &j, const std::string &key)
{
    return getInt64(j, key, 0);
}

int32_t JsonHelper::getInt32(const nlohmann::json &j, const std::string &key)
{
    return getInt32(j, key, 0);
}

bool JsonHelper::getBool(const nlohmann::json &j, const std::string &key)
{
    return getBool(j, key, false);
}

float JsonHelper::getFloat(const nlohmann::json &j, const std::string &key)
{
    return getFloat(j, key, 0.0f);
}

double JsonHelper::getDouble(const nlohmann::json &j, const std::string &key)
{
    return getDouble(j, key, 0.0f);
}

std::chrono::system_clock::time_point JsonHelper::getDateTime(const nlohmann::json &j, const std::string &key, const std::chrono::system_clock::time_point &defaultValue)
{
    if (j.contains(key))
    {
        auto &v = j[key];

        if (v.is_string())
        {
            return DateTime::getDateTimeFromString(v.get<std::string>());
        }
    }

    return defaultValue;
}

std::chrono::system_clock::time_point JsonHelper::getDateTime(const nlohmann::json &j, const std::string &key)
{
    return getDateTime(j, key, DateTime::getCurrentDateTime());
}

std::chrono::system_clock::time_point JsonHelper::getDateTimeFromDateOnly(const nlohmann::json &j, const std::string &key, const std::chrono::system_clock::time_point &defaultValue)
{
    if (j.contains(key))
    {
        auto &v = j[key];

        if (v.is_string())
        {
            return DateTime::getDateTimeFromStringWithFormat(v.get<std::string>(), "%F");
        }
    }

    return defaultValue;
}

std::chrono::system_clock::time_point JsonHelper::getDateTimeFromDateOnly(const nlohmann::json &j, const std::string &key)
{
    return getDateTimeFromDateOnly(j, key, DateTime::getCurrentDateTime());
}

std::chrono::system_clock::time_point JsonHelper::getDateTimeFromTimestampInSeconds(const nlohmann::json &j, const std::string &key, const std::chrono::system_clock::time_point &defaultValue)
{
    if (j.contains(key))
    {
        auto &v = j[key];
        int64_t timestamp = 0;

        if (v.is_string())
        {
            timestamp = std::stoll(v.get<std::string>());
        }
        else if (v.is_number_integer())
        {
            timestamp = v.get<int64_t>();
        }

        return DateTime::getDateTimeFromSeconds(timestamp);
    }

    return defaultValue;
}

std::chrono::system_clock::time_point JsonHelper::getDateTimeFromTimestampInSeconds(const nlohmann::json &j, const std::string &key)
{
    return getDateTimeFromTimestampInSeconds(j, key, DateTime::getCurrentDateTime());
}

std::chrono::system_clock::time_point JsonHelper::getDateTimeFromTimestampInMilliseconds(const nlohmann::json &j, const std::string &key, const std::chrono::system_clock::time_point &defaultValue)
{
    if (j.contains(key))
    {
        auto &v = j[key];
        int64_t timestamp = 0;

        if (v.is_string())
        {
            timestamp = std::stoll(v.get<std::string>());
        }
        else if (v.is_number_integer())
        {
            timestamp = v.get<int64_t>();
        }

        return DateTime::getDateTimeFromMilliseconds(timestamp);
    }

    return defaultValue;
}

std::chrono::system_clock::time_point JsonHelper::getDateTimeFromTimestampInMilliseconds(const nlohmann::json &j, const std::string &key)
{
    return getDateTimeFromTimestampInMilliseconds(j, key, DateTime::getCurrentDateTime());
}

std::unordered_map<std::string, std::string> JsonHelper::getMap(const nlohmann::json &j, const std::string &key, const std::unordered_map<std::string, std::string> &defaultValue)
{
    if (j.contains(key))
    {
        auto &v = j[key];

        try
        {
            return v.get<std::unordered_map<std::string, std::string>>();
        }
        catch (const std::exception &e)
        {
            // ignore
        }
    }

    return defaultValue;
}

std::unordered_map<std::string, std::string> JsonHelper::getMap(const nlohmann::json &j, const std::string &key)
{
    return getMap(j, key, {});
}

} // namespace helper
} // namespace nativium
