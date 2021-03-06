// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/wasm/djinni_wasm.hpp"
#include "nativium/helper/SharedDataHelper.hpp"

namespace djinni_generated {

struct NTVHelperSharedDataHelper : ::djinni::JsInterface<::nativium::helper::SharedDataHelper, NTVHelperSharedDataHelper> {
    using CppType = std::shared_ptr<::nativium::helper::SharedDataHelper>;
    using CppOptType = std::shared_ptr<::nativium::helper::SharedDataHelper>;
    using JsType = em::val;
    using Boxed = NTVHelperSharedDataHelper;

    static CppType toCpp(JsType j) { return _fromJs(j); }
    static JsType fromCppOpt(const CppOptType& c) { return {_toJs(c)}; }
    static JsType fromCpp(const CppType& c) {
        djinni::checkForNull(c.get(), "NTVHelperSharedDataHelper::fromCpp");
        return fromCppOpt(c);
    }

    static em::val cppProxyMethods();

    static void setCustomer(const em::val& w_value);
    static em::val getCustomer();
    static void storeCustomer();
    static void setDemoFlag(bool w_value);
    static bool getDemoFlag();

};

}  // namespace djinni_generated
