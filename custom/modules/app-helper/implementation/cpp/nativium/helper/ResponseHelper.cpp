#include "ResponseHelper.hpp"
#include "nativium/domain/ResponseJson.hpp"
#include "nlohmann/json.hpp"
#include <string>

namespace nativium
{
namespace helper
{

Response ResponseHelper::fromHttpResponse(const HttpResponse httpResponse)
{
    try
    {
        auto json = nlohmann::json::parse(httpResponse.body);
        auto o = json.get<Response>();
        o.httpResponse = httpResponse;
        return o;
    }
    catch (const std::exception &e)
    {
        // ignore
    }

    return create(httpResponse);
}

ResponseError ResponseHelper::createResponseError()
{
    return ResponseError{"", ""};
}

Response ResponseHelper::create()
{
    return Response{false, "", createResponseError(), false, HttpResponse{0, "", "", {}, {}}};
}

Response ResponseHelper::create(const HttpResponse httpResponse)
{
    return Response{false, "", createResponseError(), false, httpResponse};
}

} // namespace helper
} // namespace nativium
