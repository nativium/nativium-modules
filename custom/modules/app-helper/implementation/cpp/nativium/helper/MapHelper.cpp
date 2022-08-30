#include "MapHelper.hpp"
#include "nlohmann/json.hpp"

namespace nativium
{
namespace helper
{

std::string MapHelper::toJsonString(const std::unordered_map<std::string, std::string> &data)
{
    try
    {
        return nlohmann::json(data).dump();
    }
    catch (const std::exception &e)
    {
        // ignore
    }

    return "";
}

std::unordered_map<std::string, std::string> MapHelper::fromJsonString(const std::string &data)
{
    try
    {
        auto json = nlohmann::json::parse(data);
        return json.get<std::unordered_map<std::string, std::string>>();
    }
    catch (const std::exception &e)
    {
        // ignore
    }

    return {};
}

std::string MapHelper::getValue(const std::string &key, const std::unordered_map<std::string, std::string> &data, const std::string &defaultValue)
{
    auto it = data.find(key);

    if (it == data.end())
    {
        return defaultValue;
    }

    return it->second;
}

} // namespace helper
} // namespace nativium
