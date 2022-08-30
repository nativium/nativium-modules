#pragma once

#include "nativium/util/Logger.hpp"
#include "nativium/util/LoggerPlatformService.hpp"

namespace nativium
{
namespace util
{

class LoggerImpl : public Logger
{

public:
    LoggerImpl();

    static std::shared_ptr<LoggerImpl> internalSharedInstance();

    void setPlatformService(const std::shared_ptr<LoggerPlatformService> &ps) override;
    std::shared_ptr<LoggerPlatformService> getPlatformService() override;
    bool hasPlatformService() override;

    bool allowedLevel(LoggerLevel level) override;
    void setLevel(LoggerLevel level) override;

private:
    static std::shared_ptr<LoggerImpl> instance;

    std::shared_ptr<LoggerPlatformService> ps;
    LoggerLevel level;
};

} // namespace util
} // namespace nativium
