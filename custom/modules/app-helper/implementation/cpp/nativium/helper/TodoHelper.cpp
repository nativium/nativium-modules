#include "nativium/helper/TodoHelper.hpp"
#include "nativium/time/DateTime.hpp"

namespace nativium
{
namespace helper
{

using namespace nativium::domain;
using namespace nativium::time;

Todo TodoHelper::create()
{
    auto data = std::unordered_map<std::string, std::string>();
    return Todo{0, "", "", data, false, DateTime::getCurrentDateTime(), DateTime::getCurrentDateTime()};
}

} // namespace helper
} // namespace nativium
