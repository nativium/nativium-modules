#pragma once

#include "nativium/enumerator/CustomerStatusEnum.hpp"
#include "nativium/helper/JsonHelper.hpp"
#include "nativium/helper/NTVCustomerHelper.hpp"
#include "nlohmann/json.hpp"

#include <string>
#include <vector>

using namespace nativium::domain;
using namespace nativium::helper;
using namespace nativium::enumerator;

namespace nlohmann
{
template <>
struct adl_serializer<Customer>
{
    static Customer from_json(const json &j)
    {
        auto o = NTVCustomerHelper::create();

        o.id = JsonHelper::getInt64(j, "id");
        o.name = JsonHelper::getString(j, "name");
        o.token = JsonHelper::getString(j, "token");

        // status
        int32_t status = JsonHelper::getInt32(j, "status");

        if (status == static_cast<int>(CustomerStatusEnum::ACTIVE))
        {
            o.status = CustomerStatusEnum::ACTIVE;
        }
        else if (status == static_cast<int>(CustomerStatusEnum::INACTIVE))
        {
            o.status = CustomerStatusEnum::INACTIVE;
        }

        return o;
    }

    static void to_json(json &j, Customer o)
    {
        j = nlohmann::json{
            {"id", o.id},
            {"name", o.name},
            {"token", o.token},
            {"status", o.status},
        };
    }
};
} // namespace nlohmann
