// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/wasm/djinni_wasm.hpp"
#include "nativium/helper/TodoHelper.hpp"

namespace djinni_generated {

struct NTVHelperTodoHelper : ::djinni::JsInterface<::nativium::helper::TodoHelper, NTVHelperTodoHelper> {
    using CppType = std::shared_ptr<::nativium::helper::TodoHelper>;
    using CppOptType = std::shared_ptr<::nativium::helper::TodoHelper>;
    using JsType = em::val;
    using Boxed = NTVHelperTodoHelper;

    static CppType toCpp(JsType j) { return _fromJs(j); }
    static JsType fromCppOpt(const CppOptType& c) { return {_toJs(c)}; }
    static JsType fromCpp(const CppType& c) {
        djinni::checkForNull(c.get(), "NTVHelperTodoHelper::fromCpp");
        return fromCppOpt(c);
    }

    static em::val cppProxyMethods();

    static em::val create();

};

}  // namespace djinni_generated