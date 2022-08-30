// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "nativium/data/SharedData.hpp"

namespace djinni_generated {

class NTVSharedData final : ::djinni::JniInterface<::nativium::data::SharedData, NTVSharedData> {
public:
    using CppType = std::shared_ptr<::nativium::data::SharedData>;
    using CppOptType = std::shared_ptr<::nativium::data::SharedData>;
    using JniType = jobject;

    using Boxed = NTVSharedData;

    ~NTVSharedData();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NTVSharedData>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NTVSharedData>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NTVSharedData();
    friend ::djinni::JniClass<NTVSharedData>;
    friend ::djinni::JniInterface<::nativium::data::SharedData, NTVSharedData>;

};

}  // namespace djinni_generated