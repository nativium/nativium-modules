// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "nativium/systemservice/CustomerSystemServiceLoginData.hpp"

namespace djinni_generated {

class NTVSystemServiceCustomerSystemServiceLoginData final {
public:
    using CppType = ::nativium::systemservice::CustomerSystemServiceLoginData;
    using JniType = jobject;

    using Boxed = NTVSystemServiceCustomerSystemServiceLoginData;

    ~NTVSystemServiceCustomerSystemServiceLoginData();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NTVSystemServiceCustomerSystemServiceLoginData();
    friend ::djinni::JniClass<NTVSystemServiceCustomerSystemServiceLoginData>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nativium/systemservice/CustomerSystemServiceLoginData") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Lcom/nativium/domain/Response;Lcom/nativium/domain/Customer;)V") };
    const jfieldID field_mResponse { ::djinni::jniGetFieldID(clazz.get(), "mResponse", "Lcom/nativium/domain/Response;") };
    const jfieldID field_mCustomer { ::djinni::jniGetFieldID(clazz.get(), "mCustomer", "Lcom/nativium/domain/Customer;") };
};

}  // namespace djinni_generated