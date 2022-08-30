#pragma once

#include "nativium/net/http/HttpClientPlatformService.hpp"
#include <string>

namespace nativium
{
namespace net
{
namespace http
{

class SimpleHttpClientPlatformService : public HttpClientPlatformService
{
public:
    HttpResponse doRequest(const HttpRequest &request) override;

private:
    std::string getMethodFromRequest(const HttpRequest &request);
};

} // namespace http
} // namespace net
} // namespace nativium
