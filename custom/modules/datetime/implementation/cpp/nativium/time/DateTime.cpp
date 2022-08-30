#include "nativium/time/DateTime.hpp"
#include "date/date.h"
#include "date/ptz.h"

#include <chrono>
#include <cmath>
#include <sstream>

namespace nativium
{
namespace time
{

std::chrono::system_clock::time_point DateTime::getDateTimeFromString(const std::string &value)
{
    std::chrono::system_clock::time_point dt;
    std::stringstream ss{value};
    ss >> date::parse("%F %T", dt);
    return date::floor<std::chrono::seconds>(dt);
}

std::string DateTime::getStringFromDateTime(const std::chrono::system_clock::time_point &value)
{
    return date::format("%F %T", date::floor<std::chrono::seconds>(value));
}

std::chrono::system_clock::time_point DateTime::getDateTimeFromStringWithFormat(const std::string &value, const std::string &format)
{
    // formats: https://github.com/HowardHinnant/date
    std::chrono::system_clock::time_point dt;
    std::stringstream ss{value};
    ss >> date::parse(format, dt);
    return date::floor<std::chrono::seconds>(dt);
}

std::string DateTime::getCurrentDateTimeAsString()
{
    auto dt = std::chrono::system_clock::now();
    return date::format("%F %T", date::floor<std::chrono::seconds>(dt));
}

std::chrono::system_clock::time_point DateTime::getCurrentDateTime()
{
    return date::floor<std::chrono::seconds>(std::chrono::system_clock::now());
}

std::chrono::system_clock::time_point DateTime::getDateTimeFromSeconds(int64_t value)
{
    auto dur = std::chrono::seconds(value);
    return std::chrono::time_point<std::chrono::system_clock>(dur);
}

std::chrono::system_clock::time_point DateTime::getDateTimeFromMilliseconds(int64_t value)
{
    auto dur = std::chrono::milliseconds(value);
    return std::chrono::time_point<std::chrono::system_clock>(dur);
}

int64_t DateTime::getTimestampInMillisecondsFromDateTime(const std::chrono::system_clock::time_point &value)
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(value.time_since_epoch()).count();
}

int64_t DateTime::getTimestampInSecondsFromDateTime(const std::chrono::system_clock::time_point &value)
{
    return std::chrono::duration_cast<std::chrono::seconds>(value.time_since_epoch()).count();
}

std::string DateTime::getCurrentTimestampInSecondsAsString()
{
    return std::to_string(getCurrentTimestampInSeconds());
}

int64_t DateTime::getCurrentTimestampInSeconds()
{
    return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

std::string DateTime::getCurrentTimestampInMillisecondsAsString()
{
    return std::to_string(getCurrentTimestampInMilliseconds());
}

int64_t DateTime::getCurrentTimestampInMilliseconds()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

std::string DateTime::getFormattedStringFromDateTime(const std::chrono::system_clock::time_point &value, const std::string &format)
{
    // formats: https://github.com/HowardHinnant/date
    return date::format(format, date::floor<std::chrono::seconds>(value));
}

int64_t DateTime::getMillisecondsFromTimeString(const std::string &value)
{
    if (value.empty())
    {
        return 0;
    }

    std::istringstream in{value};
    std::chrono::milliseconds d;
    in >> date::parse("%T", d);
    return std::chrono::duration_cast<std::chrono::milliseconds>(d).count();
}

std::chrono::system_clock::time_point DateTime::getDateTimeFromTimeInPosixTimezone(const std::string &time, const std::string &timezone)
{
    // ex: https://wandbox.org/permlink/rB1LRRKsSQOQzg7y
    // get data from timezone (ex: "<-03>3" - America/Sao_Paulo)
    Posix::time_zone timeZone{timezone};
    std::istringstream in{time};
    std::chrono::seconds localTimeOfDay;
    in >> date::parse("%H:%M:%S", localTimeOfDay);

    // get current date from timezone
    using zonedTime = date::zoned_time<std::chrono::seconds, Posix::time_zone>;
    zonedTime now{timeZone, date::floor<std::chrono::seconds>(std::chrono::system_clock::now())};

    auto current_local_date = date::floor<date::days>(now.get_local_time());
    zonedTime fullDateTime{timeZone, current_local_date + localTimeOfDay};

    // convert to utc
    auto dt = fullDateTime.get_sys_time();

    return dt;
}

} // namespace time
} // namespace nativium
