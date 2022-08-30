#pragma once

#include "nativium/domain/Response.hpp"
#include "nativium/domain/ResponseErrorJson.hpp"
#include "nativium/helper/JsonHelper.hpp"
#include "nativium/helper/ResponseHelper.hpp"
#include "nlohmann/json.hpp"

#include <string>

using namespace nativium::domain;
using namespace nativium::helper;

namespace nlohmann
{
template <>
struct adl_serializer<Response>
{
    static Response from_json(const json &j)
    {
        auto o = ResponseHelper::create();

        o.success = JsonHelper::getBool(j, "success");
        o.message = JsonHelper::getString(j, "message");

        if (j.contains("data"))
        {
            auto &data = j["data"];

            if (data.contains("errors"))
            {
                auto &dataErrors = data["errors"];

                if (dataErrors.is_array())
                {
                    for (auto &dataErrorItem : dataErrors)
                    {
                        if (dataErrorItem.is_array())
                        {
                            std::string errorField = "";
                            std::string errorMessage = "";

                            auto x = 0;

                            for (auto &dataError : dataErrorItem)
                            {
                                if (dataError.is_string())
                                {
                                    /**
                                     * In this case errors is:
                                     * "data":{
                                     *     "errors":[
                                     *         ["error-field-1","error-message-1"]
                                     *         ["error-field-2","error-message-2"]
                                     *     ]
                                     * }
                                     */

                                    if (x == 0)
                                    {
                                        errorField = dataError.get<std::string>();
                                    }
                                    else if (x == 1)
                                    {
                                        errorMessage = dataError.get<std::string>();
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                                else if (dataError.is_array())
                                {
                                    /**
                                     * In this case errors is:
                                     * "data":{
                                     *     "errors":[
                                     *         [
                                     *             "error-field",
                                     *             ["error-message"]
                                     *         ]
                                     *     ]
                                     * }
                                     */

                                    for (auto &dataErrorMessage : dataError)
                                    {
                                        if (dataErrorMessage.is_string())
                                        {
                                            if (x == 1)
                                            {
                                                errorMessage = dataErrorMessage.get<std::string>();
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }

                                x++;
                            }

                            o.error.field = errorField;
                            o.error.message = errorMessage;
                        }
                    }
                }
            }
        }

        if (o.error.message.size() > 0)
        {
            o.hasError = true;
        }

        return o;
    }

    static void to_json(json &j, Response o)
    {
        j = nlohmann::json{
            {"success", o.success},
            {"message", o.message},
            {"has_error", o.hasError},
            {"error", o.error},
        };
    }
};
} // namespace nlohmann
