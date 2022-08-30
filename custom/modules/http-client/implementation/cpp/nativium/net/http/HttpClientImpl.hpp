#pragma once

#include "nativium/net/http/HttpClient.hpp"
#include "nativium/net/http/HttpClientLogger.hpp"
#include "nativium/net/http/HttpClientPlatformService.hpp"
#include "nativium/net/http/HttpRequest.hpp"
#include "nativium/net/http/HttpResponse.hpp"

#include <string>

namespace nativium
{
namespace net
{
namespace http
{

class HttpClientImpl : public HttpClient
{
public:
    HttpClientImpl();
    static std::shared_ptr<HttpClientImpl> internalSharedInstance();

    void setPlatformService(const std::shared_ptr<HttpClientPlatformService> &ps) override;
    std::shared_ptr<HttpClientPlatformService> getPlatformService() override;
    bool hasPlatformService() override;

    HttpResponse doRequest(const HttpRequest &request) override;

    void setLogger(const std::shared_ptr<HttpClientLogger> &logger) override;
    std::shared_ptr<HttpClientLogger> getLogger() override;
    bool hasLogger() override;

private:
    static std::shared_ptr<HttpClientImpl> instance;
    std::shared_ptr<HttpClientPlatformService> ps;
    std::shared_ptr<HttpClientLogger> logger;
};

} // namespace http
} // namespace net
} // namespace nativium
