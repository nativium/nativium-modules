// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "com/nativium/helper/NTVHelperCustomerHelper.hpp"  // my header
#include "com/nativium/domain/NTVDomainCustomer.hpp"
#include "djinni/jni/Marshal.hpp"

namespace djinni_generated {

NTVHelperCustomerHelper::NTVHelperCustomerHelper() : ::djinni::JniInterface<::nativium::helper::CustomerHelper, NTVHelperCustomerHelper>("com/nativium/helper/CustomerHelper$CppProxy") {}

NTVHelperCustomerHelper::~NTVHelperCustomerHelper() = default;


CJNIEXPORT void JNICALL Java_com_nativium_helper_CustomerHelper_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        delete reinterpret_cast<::djinni::CppProxyHandle<::nativium::helper::CustomerHelper>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jboolean JNICALL Java_com_nativium_helper_CustomerHelper_isLogged(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        auto r = ::nativium::helper::CustomerHelper::isLogged();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_nativium_helper_CustomerHelper_getToken(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        auto r = ::nativium::helper::CustomerHelper::getToken();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT ::djinni_generated::NTVDomainCustomer::JniType JNICALL Java_com_nativium_helper_CustomerHelper_create(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        auto r = ::nativium::helper::CustomerHelper::create();
        return ::djinni::release(::djinni_generated::NTVDomainCustomer::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_nativium_helper_CustomerHelper_onCustomerLogin(JNIEnv* jniEnv, jobject /*this*/, ::djinni_generated::NTVDomainCustomer::JniType j_customer)
{
    try {
        ::nativium::helper::CustomerHelper::onCustomerLogin(::djinni_generated::NTVDomainCustomer::toCpp(jniEnv, j_customer));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
