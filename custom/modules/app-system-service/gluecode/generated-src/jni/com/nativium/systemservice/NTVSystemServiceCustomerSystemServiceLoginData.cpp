// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "com/nativium/systemservice/NTVSystemServiceCustomerSystemServiceLoginData.hpp"  // my header
#include "com/nativium/domain/NTVDomainCustomer.hpp"
#include "com/nativium/domain/NTVDomainResponse.hpp"

namespace djinni_generated {

NTVSystemServiceCustomerSystemServiceLoginData::NTVSystemServiceCustomerSystemServiceLoginData() = default;

NTVSystemServiceCustomerSystemServiceLoginData::~NTVSystemServiceCustomerSystemServiceLoginData() = default;

auto NTVSystemServiceCustomerSystemServiceLoginData::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NTVSystemServiceCustomerSystemServiceLoginData>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni_generated::NTVDomainResponse::fromCpp(jniEnv, c.response)),
                                                           ::djinni::get(::djinni_generated::NTVDomainCustomer::fromCpp(jniEnv, c.customer)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NTVSystemServiceCustomerSystemServiceLoginData::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 3);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NTVSystemServiceCustomerSystemServiceLoginData>::get();
    return {::djinni_generated::NTVDomainResponse::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mResponse)),
            ::djinni_generated::NTVDomainCustomer::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mCustomer))};
}

}  // namespace djinni_generated
