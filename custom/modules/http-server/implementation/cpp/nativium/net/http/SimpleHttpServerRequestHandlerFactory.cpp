#include "nativium/net/http/SimpleHttpServerRequestHandlerFactory.hpp"
#include "nativium/net/http/SimpleHttpServerRequestHandler.hpp"

#include "nativium/util/Logger.hpp"

namespace nativium
{
namespace net
{

namespace http
{

using namespace nativium::net::http;
using namespace nativium::util;

SimpleHttpServerRequestHandlerFactory::SimpleHttpServerRequestHandlerFactory(const std::shared_ptr<HttpServerConfig> &config)
{
    Logger::d("[SimpleHttpServerRequestHandlerFactory : constructor]");
    serverConfig = config;
}

Poco::Net::HTTPRequestHandler *SimpleHttpServerRequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request)
{
    Logger::d("[SimpleHttpServerRequestHandlerFactory : createRequestHandler]");
    return new SimpleHttpServerRequestHandler{serverConfig};
}

} // namespace http
} // namespace net
} // namespace nativium
