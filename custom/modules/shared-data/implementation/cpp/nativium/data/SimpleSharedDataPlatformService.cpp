#include "SimpleSharedDataPlatformService.hpp"
#include "nativium/io/FileHelper.hpp"
#include <iostream>

namespace nativium
{
namespace data
{

using namespace nativium::io;

std::string SimpleSharedDataPlatformService::baseDir = "nativium";

void SimpleSharedDataPlatformService::setString(const std::string &groupName, const std::string &key, const std::string &value)
{
    auto json = create(groupName);
    json[key] = value;
    save(json, groupName);
}

void SimpleSharedDataPlatformService::setInteger(const std::string &groupName, const std::string &key, int32_t value)
{
    auto json = create(groupName);
    json[key] = value;
    save(json, groupName);
}

void SimpleSharedDataPlatformService::setLong(const std::string &groupName, const std::string &key, int64_t value)
{
    auto json = create(groupName);
    json[key] = value;
    save(json, groupName);
}

void SimpleSharedDataPlatformService::setBool(const std::string &groupName, const std::string &key, bool value)
{
    auto json = create(groupName);
    json[key] = value;
    save(json, groupName);
}

void SimpleSharedDataPlatformService::setFloat(const std::string &groupName, const std::string &key, float value)
{
    auto json = create(groupName);
    json[key] = value;
    save(json, groupName);
}

void SimpleSharedDataPlatformService::setDouble(const std::string &groupName, const std::string &key, double value)
{
    auto json = create(groupName);
    json[key] = value;
    save(json, groupName);
}

std::string SimpleSharedDataPlatformService::getString(const std::string &groupName, const std::string &key)
{
    return getStringWithDefaultValue(groupName, key, "");
}

int32_t SimpleSharedDataPlatformService::getInteger(const std::string &groupName, const std::string &key)
{
    return getIntegerWithDefaultValue(groupName, key, 0);
}

int64_t SimpleSharedDataPlatformService::getLong(const std::string &groupName, const std::string &key)
{
    return getLongWithDefaultValue(groupName, key, 0);
}

bool SimpleSharedDataPlatformService::getBool(const std::string &groupName, const std::string &key)
{
    return getBoolWithDefaultValue(groupName, key, false);
}

float SimpleSharedDataPlatformService::getFloat(const std::string &groupName, const std::string &key)
{
    return getFloatWithDefaultValue(groupName, key, 0);
}

double SimpleSharedDataPlatformService::getDouble(const std::string &groupName, const std::string &key)
{
    return getDoubleWithDefaultValue(groupName, key, 0);
}

std::string SimpleSharedDataPlatformService::getStringWithDefaultValue(const std::string &groupName, const std::string &key, const std::string &defaultValue)
{
    auto json = create(groupName);

    if (json.contains(key))
    {
        return json[key].get<std::string>();
    }

    return defaultValue;
}

int32_t SimpleSharedDataPlatformService::getIntegerWithDefaultValue(const std::string &groupName, const std::string &key, int32_t defaultValue)
{
    auto json = create(groupName);

    if (json.contains(key))
    {
        return json[key].get<int32_t>();
    }

    return defaultValue;
}

int64_t SimpleSharedDataPlatformService::getLongWithDefaultValue(const std::string &groupName, const std::string &key, int64_t defaultValue)
{
    auto json = create(groupName);

    if (json.contains(key))
    {
        return json[key].get<int64_t>();
    }

    return defaultValue;
}

bool SimpleSharedDataPlatformService::getBoolWithDefaultValue(const std::string &groupName, const std::string &key, bool defaultValue)
{
    auto json = create(groupName);

    if (json.contains(key))
    {
        return json[key].get<bool>();
    }

    return defaultValue;
}

float SimpleSharedDataPlatformService::getFloatWithDefaultValue(const std::string &groupName, const std::string &key, float defaultValue)
{
    auto json = create(groupName);

    if (json.contains(key))
    {
        return json[key].get<float>();
    }

    return defaultValue;
}

double SimpleSharedDataPlatformService::getDoubleWithDefaultValue(const std::string &groupName, const std::string &key, double defaultValue)
{
    auto json = create(groupName);

    if (json.contains(key))
    {
        return json[key].get<double>();
    }

    return defaultValue;
}

bool SimpleSharedDataPlatformService::has(const std::string &groupName, const std::string &key)
{
    auto json = create(groupName);

    if (json.contains(key))
    {
        return true;
    }

    return false;
}

void SimpleSharedDataPlatformService::remove(const std::string &groupName, const std::string &key)
{
    auto json = create(groupName);

    if (json.contains(key))
    {
        json.erase(key);
    }

    save(json, groupName);
}

void SimpleSharedDataPlatformService::clear(const std::string &groupName)
{
    std::string homeDir = FileHelper::join(FileHelper::getHomeDir(), baseDir);
    FileHelper::createDir(homeDir);

    homeDir = FileHelper::join(homeDir, "shared-data");

    std::string filename = groupName + ".json";
    std::string filePath = FileHelper::join(homeDir, filename);

    FileHelper::removeFile(filePath);
}

void SimpleSharedDataPlatformService::save(nlohmann::json &json, const std::string &groupName)
{
    std::string homeDir = FileHelper::join(FileHelper::getHomeDir(), baseDir);
    homeDir = FileHelper::join(homeDir, "shared-data");

    std::string filename = groupName + ".json";
    std::string filePath = FileHelper::join(homeDir, filename);

    FileHelper::createFileWithStringContent(filePath, json.dump(4));
}

nlohmann::json SimpleSharedDataPlatformService::create(const std::string &groupName)
{
    // prepare data
    std::string homeDir = FileHelper::join(FileHelper::getHomeDir(), baseDir);
    FileHelper::createDir(homeDir);

    homeDir = FileHelper::join(homeDir, "shared-data");
    FileHelper::createDir(homeDir);

    std::string filename = groupName + ".json";
    std::string filePath = FileHelper::join(homeDir, filename);

    // create file to check errors
    if (!FileHelper::isFile(filePath))
    {
        FileHelper::createFile(filePath);
    }

    // if at the end the file exists then continue
    if (FileHelper::isFile(filePath))
    {
        try
        {
            return nlohmann::json::parse(FileHelper::getFileContentAsString(filePath));
        }
        catch (const std::exception &e)
        {
            // ignore
        }
    }

    return nlohmann::json::parse("{}");
}

} // namespace data
} // namespace nativium
