// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "nativium/helper/EnvironmentHelper.hpp"

namespace djinni_generated {

class NTVHelperEnvironmentHelper final : ::djinni::JniInterface<::nativium::helper::EnvironmentHelper, NTVHelperEnvironmentHelper> {
public:
    using CppType = std::shared_ptr<::nativium::helper::EnvironmentHelper>;
    using CppOptType = std::shared_ptr<::nativium::helper::EnvironmentHelper>;
    using JniType = jobject;

    using Boxed = NTVHelperEnvironmentHelper;

    ~NTVHelperEnvironmentHelper();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NTVHelperEnvironmentHelper>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NTVHelperEnvironmentHelper>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NTVHelperEnvironmentHelper();
    friend ::djinni::JniClass<NTVHelperEnvironmentHelper>;
    friend ::djinni::JniInterface<::nativium::helper::EnvironmentHelper, NTVHelperEnvironmentHelper>;

};

}  // namespace djinni_generated
