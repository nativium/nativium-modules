// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "nativium/data/SharedDataPlatformService.hpp"

namespace djinni_generated {

class NTVSharedDataPlatformService final : ::djinni::JniInterface<::nativium::data::SharedDataPlatformService, NTVSharedDataPlatformService> {
public:
    using CppType = std::shared_ptr<::nativium::data::SharedDataPlatformService>;
    using CppOptType = std::shared_ptr<::nativium::data::SharedDataPlatformService>;
    using JniType = jobject;

    using Boxed = NTVSharedDataPlatformService;

    ~NTVSharedDataPlatformService();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NTVSharedDataPlatformService>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NTVSharedDataPlatformService>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NTVSharedDataPlatformService();
    friend ::djinni::JniClass<NTVSharedDataPlatformService>;
    friend ::djinni::JniInterface<::nativium::data::SharedDataPlatformService, NTVSharedDataPlatformService>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::nativium::data::SharedDataPlatformService
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void setString(const std::string & groupName, const std::string & key, const std::string & value) override;
        void setInteger(const std::string & groupName, const std::string & key, int32_t value) override;
        void setLong(const std::string & groupName, const std::string & key, int64_t value) override;
        void setBool(const std::string & groupName, const std::string & key, bool value) override;
        void setFloat(const std::string & groupName, const std::string & key, float value) override;
        void setDouble(const std::string & groupName, const std::string & key, double value) override;
        std::string getString(const std::string & groupName, const std::string & key) override;
        int32_t getInteger(const std::string & groupName, const std::string & key) override;
        int64_t getLong(const std::string & groupName, const std::string & key) override;
        bool getBool(const std::string & groupName, const std::string & key) override;
        float getFloat(const std::string & groupName, const std::string & key) override;
        double getDouble(const std::string & groupName, const std::string & key) override;
        std::string getStringWithDefaultValue(const std::string & groupName, const std::string & key, const std::string & defaultValue) override;
        int32_t getIntegerWithDefaultValue(const std::string & groupName, const std::string & key, int32_t defaultValue) override;
        int64_t getLongWithDefaultValue(const std::string & groupName, const std::string & key, int64_t defaultValue) override;
        bool getBoolWithDefaultValue(const std::string & groupName, const std::string & key, bool defaultValue) override;
        float getFloatWithDefaultValue(const std::string & groupName, const std::string & key, float defaultValue) override;
        double getDoubleWithDefaultValue(const std::string & groupName, const std::string & key, double defaultValue) override;
        bool has(const std::string & groupName, const std::string & key) override;
        void remove(const std::string & groupName, const std::string & key) override;
        void clear(const std::string & groupName) override;

    private:
        friend ::djinni::JniInterface<::nativium::data::SharedDataPlatformService, ::djinni_generated::NTVSharedDataPlatformService>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nativium/data/SharedDataPlatformService") };
    const jmethodID method_setString { ::djinni::jniGetMethodID(clazz.get(), "setString", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V") };
    const jmethodID method_setInteger { ::djinni::jniGetMethodID(clazz.get(), "setInteger", "(Ljava/lang/String;Ljava/lang/String;I)V") };
    const jmethodID method_setLong { ::djinni::jniGetMethodID(clazz.get(), "setLong", "(Ljava/lang/String;Ljava/lang/String;J)V") };
    const jmethodID method_setBool { ::djinni::jniGetMethodID(clazz.get(), "setBool", "(Ljava/lang/String;Ljava/lang/String;Z)V") };
    const jmethodID method_setFloat { ::djinni::jniGetMethodID(clazz.get(), "setFloat", "(Ljava/lang/String;Ljava/lang/String;F)V") };
    const jmethodID method_setDouble { ::djinni::jniGetMethodID(clazz.get(), "setDouble", "(Ljava/lang/String;Ljava/lang/String;D)V") };
    const jmethodID method_getString { ::djinni::jniGetMethodID(clazz.get(), "getString", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;") };
    const jmethodID method_getInteger { ::djinni::jniGetMethodID(clazz.get(), "getInteger", "(Ljava/lang/String;Ljava/lang/String;)I") };
    const jmethodID method_getLong { ::djinni::jniGetMethodID(clazz.get(), "getLong", "(Ljava/lang/String;Ljava/lang/String;)J") };
    const jmethodID method_getBool { ::djinni::jniGetMethodID(clazz.get(), "getBool", "(Ljava/lang/String;Ljava/lang/String;)Z") };
    const jmethodID method_getFloat { ::djinni::jniGetMethodID(clazz.get(), "getFloat", "(Ljava/lang/String;Ljava/lang/String;)F") };
    const jmethodID method_getDouble { ::djinni::jniGetMethodID(clazz.get(), "getDouble", "(Ljava/lang/String;Ljava/lang/String;)D") };
    const jmethodID method_getStringWithDefaultValue { ::djinni::jniGetMethodID(clazz.get(), "getStringWithDefaultValue", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;") };
    const jmethodID method_getIntegerWithDefaultValue { ::djinni::jniGetMethodID(clazz.get(), "getIntegerWithDefaultValue", "(Ljava/lang/String;Ljava/lang/String;I)I") };
    const jmethodID method_getLongWithDefaultValue { ::djinni::jniGetMethodID(clazz.get(), "getLongWithDefaultValue", "(Ljava/lang/String;Ljava/lang/String;J)J") };
    const jmethodID method_getBoolWithDefaultValue { ::djinni::jniGetMethodID(clazz.get(), "getBoolWithDefaultValue", "(Ljava/lang/String;Ljava/lang/String;Z)Z") };
    const jmethodID method_getFloatWithDefaultValue { ::djinni::jniGetMethodID(clazz.get(), "getFloatWithDefaultValue", "(Ljava/lang/String;Ljava/lang/String;F)F") };
    const jmethodID method_getDoubleWithDefaultValue { ::djinni::jniGetMethodID(clazz.get(), "getDoubleWithDefaultValue", "(Ljava/lang/String;Ljava/lang/String;D)D") };
    const jmethodID method_has { ::djinni::jniGetMethodID(clazz.get(), "has", "(Ljava/lang/String;Ljava/lang/String;)Z") };
    const jmethodID method_remove { ::djinni::jniGetMethodID(clazz.get(), "remove", "(Ljava/lang/String;Ljava/lang/String;)V") };
    const jmethodID method_clear { ::djinni::jniGetMethodID(clazz.get(), "clear", "(Ljava/lang/String;)V") };
};

}  // namespace djinni_generated
