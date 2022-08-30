#pragma once

#include "nlohmann/json.hpp"
#include <chrono>
#include <string>
#include <unordered_map>

namespace nativium
{
namespace helper
{

class JsonHelper
{

public:
    static std::string getString(const nlohmann::json &j, const std::string &key, const std::string &defaultValue);
    static int64_t getInt64(const nlohmann::json &j, const std::string &key, const int64_t &defaultValue);
    static int32_t getInt32(const nlohmann::json &j, const std::string &key, const int32_t &defaultValue);
    static bool getBool(const nlohmann::json &j, const std::string &key, const bool &defaultValue);
    static float getFloat(const nlohmann::json &j, const std::string &key, const float &defaultValue);
    static double getDouble(const nlohmann::json &j, const std::string &key, const double &defaultValue);

    static std::string getString(const nlohmann::json &j, const std::string &key);
    static int64_t getInt64(const nlohmann::json &j, const std::string &key);
    static int32_t getInt32(const nlohmann::json &j, const std::string &key);
    static bool getBool(const nlohmann::json &j, const std::string &key);
    static float getFloat(const nlohmann::json &j, const std::string &key);
    static double getDouble(const nlohmann::json &j, const std::string &key);

    static std::chrono::system_clock::time_point getDateTime(const nlohmann::json &j, const std::string &key, const std::chrono::system_clock::time_point &defaultValue);
    static std::chrono::system_clock::time_point getDateTime(const nlohmann::json &j, const std::string &key);

    static std::chrono::system_clock::time_point getDateTimeFromDateOnly(const nlohmann::json &j, const std::string &key, const std::chrono::system_clock::time_point &defaultValue);
    static std::chrono::system_clock::time_point getDateTimeFromDateOnly(const nlohmann::json &j, const std::string &key);

    static std::chrono::system_clock::time_point getDateTimeFromTimestampInSeconds(const nlohmann::json &j, const std::string &key, const std::chrono::system_clock::time_point &defaultValue);
    static std::chrono::system_clock::time_point getDateTimeFromTimestampInSeconds(const nlohmann::json &j, const std::string &key);

    static std::chrono::system_clock::time_point getDateTimeFromTimestampInMilliseconds(const nlohmann::json &j, const std::string &key, const std::chrono::system_clock::time_point &defaultValue);
    static std::chrono::system_clock::time_point getDateTimeFromTimestampInMilliseconds(const nlohmann::json &j, const std::string &key);

    static std::unordered_map<std::string, std::string> getMap(const nlohmann::json &j, const std::string &key, const std::unordered_map<std::string, std::string> &defaultValue);
    static std::unordered_map<std::string, std::string> getMap(const nlohmann::json &j, const std::string &key);
};

} // namespace helper
} // namespace nativium
