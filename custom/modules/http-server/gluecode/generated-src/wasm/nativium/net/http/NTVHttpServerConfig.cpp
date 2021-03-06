// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/net/http/NTVHttpServerConfig.hpp"  // my header

namespace djinni_generated {

auto NTVHttpServerConfig::toCpp(const JsType& j) -> CppType {
    return {::djinni::I32::Boxed::toCpp(j["port"]),
            ::djinni::String::Boxed::toCpp(j["staticPath"])};
}
auto NTVHttpServerConfig::fromCpp(const CppType& c) -> JsType {
    em::val js = em::val::object();
    js.set("port", ::djinni::I32::Boxed::fromCpp(c.port));
    js.set("staticPath", ::djinni::String::Boxed::fromCpp(c.staticPath));
    return js;
}

}  // namespace djinni_generated
