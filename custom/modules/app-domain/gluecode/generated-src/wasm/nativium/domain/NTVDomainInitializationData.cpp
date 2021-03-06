// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "nativium/domain/NTVDomainInitializationData.hpp"  // my header

namespace djinni_generated {

auto NTVDomainInitializationData::toCpp(const JsType& j) -> CppType {
    return {::djinni::String::Boxed::toCpp(j["appId"]),
            ::djinni::String::Boxed::toCpp(j["name"]),
            ::djinni::String::Boxed::toCpp(j["basePath"]),
            ::djinni::I32::Boxed::toCpp(j["databaseMigrationMaxVersion"]),
            ::djinni::Bool::Boxed::toCpp(j["debug"])};
}
auto NTVDomainInitializationData::fromCpp(const CppType& c) -> JsType {
    em::val js = em::val::object();
    js.set("appId", ::djinni::String::Boxed::fromCpp(c.appId));
    js.set("name", ::djinni::String::Boxed::fromCpp(c.name));
    js.set("basePath", ::djinni::String::Boxed::fromCpp(c.basePath));
    js.set("databaseMigrationMaxVersion", ::djinni::I32::Boxed::fromCpp(c.databaseMigrationMaxVersion));
    js.set("debug", ::djinni::Bool::Boxed::fromCpp(c.debug));
    return js;
}

}  // namespace djinni_generated
