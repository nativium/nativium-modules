// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "nativium/io/FileHelper.hpp"

namespace djinni_generated {

class NTVFileHelper final : ::djinni::JniInterface<::nativium::io::FileHelper, NTVFileHelper> {
public:
    using CppType = std::shared_ptr<::nativium::io::FileHelper>;
    using CppOptType = std::shared_ptr<::nativium::io::FileHelper>;
    using JniType = jobject;

    using Boxed = NTVFileHelper;

    ~NTVFileHelper();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NTVFileHelper>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NTVFileHelper>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NTVFileHelper();
    friend ::djinni::JniClass<NTVFileHelper>;
    friend ::djinni::JniInterface<::nativium::io::FileHelper, NTVFileHelper>;

};

}  // namespace djinni_generated
