// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include <memory>
#include <string>

namespace nativium { namespace util {

class LoggerPlatformService;
enum class LoggerLevel;

class Logger {
public:
    virtual ~Logger() = default;

    static /*not-null*/ std::shared_ptr<Logger> shared();

    virtual void setPlatformService(const /*not-null*/ std::shared_ptr<LoggerPlatformService> & ps) = 0;

    virtual /*not-null*/ std::shared_ptr<LoggerPlatformService> getPlatformService() = 0;

    virtual bool hasPlatformService() = 0;

    virtual bool allowedLevel(LoggerLevel level) = 0;

    virtual void setLevel(LoggerLevel level) = 0;

    static void v(const std::string & message);

    static void d(const std::string & message);

    static void i(const std::string & message);

    static void w(const std::string & message);

    static void e(const std::string & message);

    static void setGroup(const std::string & group);
};

} }  // namespace nativium::util