// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/wasm/djinni_wasm.hpp"
#include "nativium/util/Logger.hpp"

namespace djinni_generated {

struct NTVLogger : ::djinni::JsInterface<::nativium::util::Logger, NTVLogger> {
    using CppType = std::shared_ptr<::nativium::util::Logger>;
    using CppOptType = std::shared_ptr<::nativium::util::Logger>;
    using JsType = em::val;
    using Boxed = NTVLogger;

    static CppType toCpp(JsType j) { return _fromJs(j); }
    static JsType fromCppOpt(const CppOptType& c) { return {_toJs(c)}; }
    static JsType fromCpp(const CppType& c) {
        djinni::checkForNull(c.get(), "NTVLogger::fromCpp");
        return fromCppOpt(c);
    }

    static em::val cppProxyMethods();

    static em::val shared();
    static void setPlatformService(const CppType& self, const em::val& w_ps);
    static em::val getPlatformService(const CppType& self);
    static bool hasPlatformService(const CppType& self);
    static bool allowedLevel(const CppType& self, int32_t w_level);
    static void setLevel(const CppType& self, int32_t w_level);
    static void v(const std::string& w_message);
    static void d(const std::string& w_message);
    static void i(const std::string& w_message);
    static void w(const std::string& w_message);
    static void e(const std::string& w_message);
    static void setGroup(const std::string& w_group);

};

}  // namespace djinni_generated