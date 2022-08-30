// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "nativium/systemservice/CustomerSystemService.hpp"

namespace djinni_generated {

class NTVSystemServiceCustomerSystemService final : ::djinni::JniInterface<::nativium::systemservice::CustomerSystemService, NTVSystemServiceCustomerSystemService> {
public:
    using CppType = std::shared_ptr<::nativium::systemservice::CustomerSystemService>;
    using CppOptType = std::shared_ptr<::nativium::systemservice::CustomerSystemService>;
    using JniType = jobject;

    using Boxed = NTVSystemServiceCustomerSystemService;

    ~NTVSystemServiceCustomerSystemService();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NTVSystemServiceCustomerSystemService>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NTVSystemServiceCustomerSystemService>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NTVSystemServiceCustomerSystemService();
    friend ::djinni::JniClass<NTVSystemServiceCustomerSystemService>;
    friend ::djinni::JniInterface<::nativium::systemservice::CustomerSystemService, NTVSystemServiceCustomerSystemService>;

};

}  // namespace djinni_generated
