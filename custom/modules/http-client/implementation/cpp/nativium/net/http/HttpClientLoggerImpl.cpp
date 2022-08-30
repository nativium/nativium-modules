#include "HttpClientLoggerImpl.hpp"

#include "nativium/net/http/HttpRequest.hpp"
#include "nativium/net/http/HttpRequestParam.hpp"
#include "nativium/net/http/HttpResponse.hpp"

#include "nativium/util/Logger.hpp"

#include <string>

namespace nativium
{
namespace net
{
namespace http
{

using namespace nativium::util;

void HttpClientLoggerImpl::onRequest(const HttpRequest &request)
{
    // headers
    std::string headersStr = "Headers:";

    for (auto &header : request.headers)
    {
        headersStr = headersStr + "\n> " + header.name + ": " + header.value;
    }

    // params
    std::string paramsStr = "Params:";

    for (auto &param : request.params)
    {
        paramsStr = paramsStr + "\n> " + param.name + ": " + param.value;
    }

    Logger::v("New request: " + request.url + "\n" + headersStr + "\n" + paramsStr);
}

void HttpClientLoggerImpl::onResponse(const HttpRequest &request, const HttpResponse &response)
{
    // headers
    std::string headersStr = "Headers:";

    for (auto &header : response.headers)
    {
        headersStr = headersStr + "\n> " + header.name + ": " + header.value;
    }

    Logger::v("Request response: \nURL: " + request.url + "\n" + headersStr + "\nCode: " + std::to_string(response.code) + "\nBody: " + response.body);
}

} // namespace http
} // namespace net
} // namespace nativium
