// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "nativium/util/Logger.hpp"

namespace djinni_generated {

class NTVLogger final : ::djinni::JniInterface<::nativium::util::Logger, NTVLogger> {
public:
    using CppType = std::shared_ptr<::nativium::util::Logger>;
    using CppOptType = std::shared_ptr<::nativium::util::Logger>;
    using JniType = jobject;

    using Boxed = NTVLogger;

    ~NTVLogger();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NTVLogger>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NTVLogger>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NTVLogger();
    friend ::djinni::JniClass<NTVLogger>;
    friend ::djinni::JniInterface<::nativium::util::Logger, NTVLogger>;

};

}  // namespace djinni_generated
