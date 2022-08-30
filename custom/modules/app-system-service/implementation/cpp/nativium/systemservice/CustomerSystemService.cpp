#include "nativium/systemservice/CustomerSystemService.hpp"
#include "nativium/core/ApplicationCore.hpp"
#include "nativium/core/ApplicationCoreImpl.hpp"
#include "nativium/helper/CustomerHelper.hpp"
#include "nativium/helper/NTVCustomerHelper.hpp"
#include "nativium/helper/ResponseHelper.hpp"
#include "nativium/systemservice/CustomerSystemServiceLoginData.hpp"

#include "nativium/net/http/HttpClient.hpp"
#include "nativium/net/http/HttpCookie.hpp"
#include "nativium/net/http/HttpHeader.hpp"
#include "nativium/net/http/HttpMethod.hpp"
#include "nativium/net/http/HttpRequest.hpp"
#include "nativium/net/http/HttpRequestParam.hpp"
#include "nativium/net/http/HttpResponse.hpp"

namespace nativium
{
namespace systemservice
{

using namespace nativium::helper;
using namespace nativium::core;
using namespace nativium::net::http;

CustomerSystemServiceLoginData CustomerSystemService::login(const std::string &username, const std::string &password)
{
    auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());

    auto httpHeaders = application->getDefaultHttpRequestHeaders();
    httpHeaders.push_back(HttpHeader{"Content-Type", "application/x-www-form-urlencoded"});

    auto httpParams = application->getDefaultHttpRequestParams();
    httpParams.push_back(HttpRequestParam{"username", username});
    httpParams.push_back(HttpRequestParam{"password", password});

    auto httpURL = "https://nativium.s3.amazonaws.com/data/http-test/login-success.json";

    if (username != "demo" || password != "demo")
    {
        httpURL = "https://nativium.s3.amazonaws.com/data/http-test/login-error.json";
    }

    auto httpRequest = HttpRequest{httpURL, HttpMethod::METHOD_GET, httpParams, httpHeaders, {}, ""};
    auto httpResponse = HttpClient::shared()->doRequest(httpRequest);

    auto response = ResponseHelper::fromHttpResponse(httpResponse);
    auto customer = NTVCustomerHelper::fromHttpResponse(httpResponse);
    auto data = CustomerSystemServiceLoginData{response, customer};

    if (response.success)
    {
        CustomerHelper::onCustomerLogin(customer);
    }

    return data;
}

} // namespace systemservice
} // namespace nativium
