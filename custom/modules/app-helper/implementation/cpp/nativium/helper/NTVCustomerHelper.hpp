#pragma once

#include "nativium/domain/Customer.hpp"
#include "nativium/helper/CustomerHelper.hpp"
#include "nativium/net/http/HttpResponse.hpp"
#include "nlohmann/json.hpp"

#include <string>

namespace nativium
{
namespace helper
{

using namespace domain;
using namespace nativium::net::http;

class NTVCustomerHelper : public CustomerHelper
{
public:
    virtual ~NTVCustomerHelper() {}

    static std::string toJson(const Customer &customer);
    static Customer fromJson(const nlohmann::json &json);
    static Customer fromHttpResponse(const HttpResponse httpResponse);
};

} // namespace helper
} // namespace nativium
