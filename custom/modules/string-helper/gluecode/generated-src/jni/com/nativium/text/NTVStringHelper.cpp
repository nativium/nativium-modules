// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "com/nativium/text/NTVStringHelper.hpp"  // my header
#include "djinni/jni/Marshal.hpp"

namespace djinni_generated {

NTVStringHelper::NTVStringHelper() : ::djinni::JniInterface<::nativium::text::StringHelper, NTVStringHelper>("com/nativium/text/StringHelper$CppProxy") {}

NTVStringHelper::~NTVStringHelper() = default;


CJNIEXPORT void JNICALL Java_com_nativium_text_StringHelper_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        delete reinterpret_cast<::djinni::CppProxyHandle<::nativium::text::StringHelper>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_com_nativium_text_StringHelper_trim(JNIEnv* jniEnv, jobject /*this*/, jstring j_value)
{
    try {
        auto r = ::nativium::text::StringHelper::trim(::djinni::String::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_nativium_text_StringHelper_leftTrim(JNIEnv* jniEnv, jobject /*this*/, jstring j_value)
{
    try {
        auto r = ::nativium::text::StringHelper::leftTrim(::djinni::String::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_nativium_text_StringHelper_rightTrim(JNIEnv* jniEnv, jobject /*this*/, jstring j_value)
{
    try {
        auto r = ::nativium::text::StringHelper::rightTrim(::djinni::String::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_nativium_text_StringHelper_toLower(JNIEnv* jniEnv, jobject /*this*/, jstring j_value)
{
    try {
        auto r = ::nativium::text::StringHelper::toLower(::djinni::String::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_nativium_text_StringHelper_toUpper(JNIEnv* jniEnv, jobject /*this*/, jstring j_value)
{
    try {
        auto r = ::nativium::text::StringHelper::toUpper(::djinni::String::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_com_nativium_text_StringHelper_split(JNIEnv* jniEnv, jobject /*this*/, jstring j_text, jstring j_sep, jboolean j_trimEmpty)
{
    try {
        auto r = ::nativium::text::StringHelper::split(::djinni::String::toCpp(jniEnv, j_text),
                                                       ::djinni::String::toCpp(jniEnv, j_sep),
                                                       ::djinni::Bool::toCpp(jniEnv, j_trimEmpty));
        return ::djinni::release(::djinni::List<::djinni::String>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_nativium_text_StringHelper_encodeUri(JNIEnv* jniEnv, jobject /*this*/, jstring j_value)
{
    try {
        auto r = ::nativium::text::StringHelper::encodeUri(::djinni::String::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_nativium_text_StringHelper_decodeUri(JNIEnv* jniEnv, jobject /*this*/, jstring j_value)
{
    try {
        auto r = ::nativium::text::StringHelper::decodeUri(::djinni::String::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
