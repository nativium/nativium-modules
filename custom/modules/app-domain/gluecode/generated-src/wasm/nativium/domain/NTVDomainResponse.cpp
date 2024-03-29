// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/domain/NTVDomainResponse.hpp"  // my header
#include "nativium/domain/NTVDomainResponseError.hpp"
#include "nativium/net/http/NTVHttpResponse.hpp"

namespace djinni_generated {

auto NTVDomainResponse::toCpp(const JsType& j) -> CppType {
    return {::djinni::Bool::Boxed::toCpp(j["success"]),
            ::djinni::String::Boxed::toCpp(j["message"]),
            ::djinni_generated::NTVDomainResponseError::Boxed::toCpp(j["error"]),
            ::djinni::Bool::Boxed::toCpp(j["hasError"]),
            ::djinni_generated::NTVHttpResponse::Boxed::toCpp(j["httpResponse"])};
}
auto NTVDomainResponse::fromCpp(const CppType& c) -> JsType {
    em::val js = em::val::object();
    js.set("success", ::djinni::Bool::Boxed::fromCpp(c.success));
    js.set("message", ::djinni::String::Boxed::fromCpp(c.message));
    js.set("error", ::djinni_generated::NTVDomainResponseError::Boxed::fromCpp(c.error));
    js.set("hasError", ::djinni::Bool::Boxed::fromCpp(c.hasError));
    js.set("httpResponse", ::djinni_generated::NTVHttpResponse::Boxed::fromCpp(c.httpResponse));
    return js;
}

}  // namespace djinni_generated
