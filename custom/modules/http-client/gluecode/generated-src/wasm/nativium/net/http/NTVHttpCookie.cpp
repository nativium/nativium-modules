// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/net/http/NTVHttpCookie.hpp"  // my header

namespace djinni_generated {

auto NTVHttpCookie::toCpp(const JsType& j) -> CppType {
    return {::djinni::String::Boxed::toCpp(j["name"]),
            ::djinni::String::Boxed::toCpp(j["value"])};
}
auto NTVHttpCookie::fromCpp(const CppType& c) -> JsType {
    em::val js = em::val::object();
    js.set("name", ::djinni::String::Boxed::fromCpp(c.name));
    js.set("value", ::djinni::String::Boxed::fromCpp(c.value));
    return js;
}

}  // namespace djinni_generated