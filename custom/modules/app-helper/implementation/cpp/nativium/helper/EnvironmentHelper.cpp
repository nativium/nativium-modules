#include "nativium/helper/EnvironmentHelper.hpp"
#include "nativium/helper/SecurityHelper.hpp"

namespace nativium
{
namespace helper
{

std::string EnvironmentHelper::getSecretKey()
{
    return SecurityHelper::generateUuidV4();
}

} // namespace helper
} // namespace nativium
