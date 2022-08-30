#include "nativium/text/StringHelper.hpp"
#include <regex>
#include <sstream>

namespace nativium
{
namespace text
{

std::string StringHelper::trim(const std::string &value)
{
    return leftTrim(rightTrim(value));
}

std::string StringHelper::leftTrim(const std::string &value)
{
    static const std::regex lws{"^[[:space:]]*", std::regex_constants::extended};
    return std::regex_replace(value, lws, "");
}

std::string StringHelper::rightTrim(const std::string &value)
{
    static const std::regex tws{"[[:space:]]*$", std::regex_constants::extended};
    return std::regex_replace(value, tws, "");
}

std::string StringHelper::toLower(const std::string &value)
{
    std::string result(value);
    transform(value.begin(), value.end(), result.begin(), ::tolower);
    return result;
}

std::string StringHelper::toUpper(const std::string &value)
{
    std::string result(value);
    transform(value.begin(), value.end(), result.begin(), ::toupper);
    return result;
}

std::vector<std::string> StringHelper::split(const std::string &text, const std::string &sep, bool trimEmpty)
{
    std::vector<std::string> tokens;

    std::string::size_type pos, lastPos = 0, length = text.length();

    while (lastPos < length + 1)
    {
        pos = text.find_first_of(sep, lastPos);

        if (pos == std::string::npos)
        {
            pos = length;
        }

        if (pos != lastPos || !trimEmpty)
        {
            tokens.push_back(std::string(text.data() + lastPos, pos - lastPos));
        }

        lastPos = pos + 1;
    }

    return tokens;
}

std::string StringHelper::encodeUri(const std::string &value)
{
    std::ostringstream oss;
    std::regex r("[!'\\(\\)*-.0-9A-Za-z_~]");

    for (const char &c : value)
    {
        if (std::regex_match(std::string{c}, r))
        {
            oss << c;
        }
        else
        {
            oss << "%" << std::uppercase << std::hex << (0xff & c);
        }
    }

    return oss.str();
}

std::string StringHelper::decodeUri(const std::string &value)
{
    std::string decoded = value;
    std::smatch sm;
    std::string haystack;

    int dynamicLength = decoded.size() - 2;

    if (decoded.size() < 3)
    {
        return decoded;
    }

    for (int i = 0; i < dynamicLength; i++)
    {
        haystack = decoded.substr(i, 3);

        if (std::regex_match(haystack, sm, std::regex("%[0-9A-F]{2}")))
        {
            haystack = haystack.replace(0, 1, "0x");
            std::string rc = {(char)std::stoi(haystack, nullptr, 16)};
            decoded = decoded.replace(decoded.begin() + i, decoded.begin() + i + 3, rc);
        }

        dynamicLength = decoded.size() - 2;
    }

    return decoded;
}

} // namespace text
} // namespace nativium
