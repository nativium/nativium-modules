#include "NTVCustomerHelper.hpp"

#include "nativium/core/ApplicationCore.hpp"
#include "nativium/domain/CustomerJson.hpp"
#include "nativium/enumerator/CustomerStatusEnum.hpp"
#include "nativium/helper/SharedDataHelper.hpp"
#include "nlohmann/json.hpp"

namespace nativium
{
namespace helper
{

using namespace nativium::core;
using namespace nativium::enumerator;

bool CustomerHelper::isLogged()
{
    auto application = ApplicationCore::shared();
    auto customer = application->getCustomer();

    if (customer.token.length() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string CustomerHelper::getToken()
{
    return ApplicationCore::shared()->getCustomer().token;
}

Customer NTVCustomerHelper::fromJson(const nlohmann::json &json)
{
    try
    {
        return json.get<Customer>();
    }
    catch (const std::exception &e)
    {
        // ignore
    }

    return create();
}

std::string NTVCustomerHelper::toJson(const Customer &customer)
{
    try
    {
        return nlohmann::json(customer).dump();
    }
    catch (const std::exception &e)
    {
        // ignore
    }

    return "";
}

Customer NTVCustomerHelper::fromHttpResponse(const HttpResponse httpResponse)
{
    try
    {
        auto json = nlohmann::json::parse(httpResponse.body);
        return json["data"]["customer"].get<Customer>();
    }
    catch (const std::exception &e)
    {
        // ignore
    }

    return create();
}

Customer CustomerHelper::create()
{
    return Customer{0, "", "", CustomerStatusEnum::INACTIVE};
}

void CustomerHelper::onCustomerLogin(const Customer &customer)
{
    ApplicationCore::shared()->setCustomer(customer);
    SharedDataHelper::storeCustomer();
}

} // namespace helper
} // namespace nativium
