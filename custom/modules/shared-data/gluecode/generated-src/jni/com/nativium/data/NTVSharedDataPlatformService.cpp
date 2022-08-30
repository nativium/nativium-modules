// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "com/nativium/data/NTVSharedDataPlatformService.hpp"  // my header
#include "djinni/jni/Marshal.hpp"

namespace djinni_generated {

NTVSharedDataPlatformService::NTVSharedDataPlatformService() : ::djinni::JniInterface<::nativium::data::SharedDataPlatformService, NTVSharedDataPlatformService>() {}

NTVSharedDataPlatformService::~NTVSharedDataPlatformService() = default;

NTVSharedDataPlatformService::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NTVSharedDataPlatformService::JavaProxy::~JavaProxy() = default;

void NTVSharedDataPlatformService::JavaProxy::setString(const std::string & c_groupName, const std::string & c_key, const std::string & c_value) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_setString,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_value)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NTVSharedDataPlatformService::JavaProxy::setInteger(const std::string & c_groupName, const std::string & c_key, int32_t c_value) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_setInteger,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)),
                           ::djinni::get(::djinni::I32::fromCpp(jniEnv, c_value)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NTVSharedDataPlatformService::JavaProxy::setLong(const std::string & c_groupName, const std::string & c_key, int64_t c_value) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_setLong,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)),
                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c_value)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NTVSharedDataPlatformService::JavaProxy::setBool(const std::string & c_groupName, const std::string & c_key, bool c_value) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_setBool,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)),
                           ::djinni::get(::djinni::Bool::fromCpp(jniEnv, c_value)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NTVSharedDataPlatformService::JavaProxy::setFloat(const std::string & c_groupName, const std::string & c_key, float c_value) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_setFloat,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)),
                           ::djinni::get(::djinni::F32::fromCpp(jniEnv, c_value)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NTVSharedDataPlatformService::JavaProxy::setDouble(const std::string & c_groupName, const std::string & c_key, double c_value) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_setDouble,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)),
                           ::djinni::get(::djinni::F64::fromCpp(jniEnv, c_value)));
    ::djinni::jniExceptionCheck(jniEnv);
}
std::string NTVSharedDataPlatformService::JavaProxy::getString(const std::string & c_groupName, const std::string & c_key) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = (jstring)jniEnv->CallObjectMethod(Handle::get().get(), data.method_getString,
                                                  ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                                  ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::String::toCpp(jniEnv, jret);
}
int32_t NTVSharedDataPlatformService::JavaProxy::getInteger(const std::string & c_groupName, const std::string & c_key) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = jniEnv->CallIntMethod(Handle::get().get(), data.method_getInteger,
                                      ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                      ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::I32::toCpp(jniEnv, jret);
}
int64_t NTVSharedDataPlatformService::JavaProxy::getLong(const std::string & c_groupName, const std::string & c_key) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = jniEnv->CallLongMethod(Handle::get().get(), data.method_getLong,
                                       ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                       ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::I64::toCpp(jniEnv, jret);
}
bool NTVSharedDataPlatformService::JavaProxy::getBool(const std::string & c_groupName, const std::string & c_key) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = jniEnv->CallBooleanMethod(Handle::get().get(), data.method_getBool,
                                          ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                          ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::Bool::toCpp(jniEnv, jret);
}
float NTVSharedDataPlatformService::JavaProxy::getFloat(const std::string & c_groupName, const std::string & c_key) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = jniEnv->CallFloatMethod(Handle::get().get(), data.method_getFloat,
                                        ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                        ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::F32::toCpp(jniEnv, jret);
}
double NTVSharedDataPlatformService::JavaProxy::getDouble(const std::string & c_groupName, const std::string & c_key) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = jniEnv->CallDoubleMethod(Handle::get().get(), data.method_getDouble,
                                         ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                         ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::F64::toCpp(jniEnv, jret);
}
std::string NTVSharedDataPlatformService::JavaProxy::getStringWithDefaultValue(const std::string & c_groupName, const std::string & c_key, const std::string & c_defaultValue) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = (jstring)jniEnv->CallObjectMethod(Handle::get().get(), data.method_getStringWithDefaultValue,
                                                  ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                                  ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)),
                                                  ::djinni::get(::djinni::String::fromCpp(jniEnv, c_defaultValue)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::String::toCpp(jniEnv, jret);
}
int32_t NTVSharedDataPlatformService::JavaProxy::getIntegerWithDefaultValue(const std::string & c_groupName, const std::string & c_key, int32_t c_defaultValue) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = jniEnv->CallIntMethod(Handle::get().get(), data.method_getIntegerWithDefaultValue,
                                      ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                      ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)),
                                      ::djinni::get(::djinni::I32::fromCpp(jniEnv, c_defaultValue)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::I32::toCpp(jniEnv, jret);
}
int64_t NTVSharedDataPlatformService::JavaProxy::getLongWithDefaultValue(const std::string & c_groupName, const std::string & c_key, int64_t c_defaultValue) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = jniEnv->CallLongMethod(Handle::get().get(), data.method_getLongWithDefaultValue,
                                       ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                       ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)),
                                       ::djinni::get(::djinni::I64::fromCpp(jniEnv, c_defaultValue)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::I64::toCpp(jniEnv, jret);
}
bool NTVSharedDataPlatformService::JavaProxy::getBoolWithDefaultValue(const std::string & c_groupName, const std::string & c_key, bool c_defaultValue) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = jniEnv->CallBooleanMethod(Handle::get().get(), data.method_getBoolWithDefaultValue,
                                          ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                          ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)),
                                          ::djinni::get(::djinni::Bool::fromCpp(jniEnv, c_defaultValue)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::Bool::toCpp(jniEnv, jret);
}
float NTVSharedDataPlatformService::JavaProxy::getFloatWithDefaultValue(const std::string & c_groupName, const std::string & c_key, float c_defaultValue) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = jniEnv->CallFloatMethod(Handle::get().get(), data.method_getFloatWithDefaultValue,
                                        ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                        ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)),
                                        ::djinni::get(::djinni::F32::fromCpp(jniEnv, c_defaultValue)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::F32::toCpp(jniEnv, jret);
}
double NTVSharedDataPlatformService::JavaProxy::getDoubleWithDefaultValue(const std::string & c_groupName, const std::string & c_key, double c_defaultValue) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = jniEnv->CallDoubleMethod(Handle::get().get(), data.method_getDoubleWithDefaultValue,
                                         ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                         ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)),
                                         ::djinni::get(::djinni::F64::fromCpp(jniEnv, c_defaultValue)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::F64::toCpp(jniEnv, jret);
}
bool NTVSharedDataPlatformService::JavaProxy::has(const std::string & c_groupName, const std::string & c_key) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    auto jret = jniEnv->CallBooleanMethod(Handle::get().get(), data.method_has,
                                          ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                                          ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::Bool::toCpp(jniEnv, jret);
}
void NTVSharedDataPlatformService::JavaProxy::remove(const std::string & c_groupName, const std::string & c_key) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_remove,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_key)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NTVSharedDataPlatformService::JavaProxy::clear(const std::string & c_groupName) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NTVSharedDataPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_clear,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_groupName)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
