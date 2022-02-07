#include "nativium/helper/SharedDataHelper.hpp"
#include "nativium/core/ApplicationCore.hpp"
#include "nativium/data/SharedData.hpp"
#include "nativium/domain/Customer.hpp"
#include "nativium/helper/CustomerHelper.hpp"
#include "nativium/helper/NTVCustomerHelper.hpp"

#include "rapidjson/document.h"
#include "rapidjson/pointer.h"

#include <string>

namespace nativium
{
namespace helper
{

using namespace nativium::data;
using namespace nativium::domain;
using namespace nativium::core;

void SharedDataHelper::setCustomer(const Customer &value)
{
    auto customerJson = NTVCustomerHelper::toJson(value);

    SharedData::shared()->setString("customer", "data", customerJson);
}

Customer SharedDataHelper::getCustomer()
{
    auto customerJson = SharedData::shared()->getString("customer", "data");

    rapidjson::Document json;
    json.Parse(customerJson.c_str());

    if (json.IsObject())
    {
        return NTVCustomerHelper::fromJson(json);
    }

    return CustomerHelper::create();
}

void SharedDataHelper::storeCustomer()
{
    setCustomer(ApplicationCore::shared()->getCustomer());
}

void SharedDataHelper::setDemoFlag(bool value)
{
    SharedData::shared()->setBool("demo", "flag", value);
}

bool SharedDataHelper::getDemoFlag()
{
    return SharedData::shared()->getBool("demo", "flag");
}

} // namespace helper
} // namespace nativium
