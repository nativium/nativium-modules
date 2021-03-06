// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/jni/djinni_support.hpp"
#include "nativium/io/FileHelperPlatformService.hpp"

namespace djinni_generated {

class NTVFileHelperPlatformService final : ::djinni::JniInterface<::nativium::io::FileHelperPlatformService, NTVFileHelperPlatformService> {
public:
    using CppType = std::shared_ptr<::nativium::io::FileHelperPlatformService>;
    using CppOptType = std::shared_ptr<::nativium::io::FileHelperPlatformService>;
    using JniType = jobject;

    using Boxed = NTVFileHelperPlatformService;

    ~NTVFileHelperPlatformService();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NTVFileHelperPlatformService>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NTVFileHelperPlatformService>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NTVFileHelperPlatformService();
    friend ::djinni::JniClass<NTVFileHelperPlatformService>;
    friend ::djinni::JniInterface<::nativium::io::FileHelperPlatformService, NTVFileHelperPlatformService>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::nativium::io::FileHelperPlatformService
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        bool createFile(const std::string & path) override;
        bool createFileWithStringContent(const std::string & path, const std::string & content) override;
        bool createFileWithBinaryContent(const std::string & path, const std::vector<uint8_t> & content) override;
        bool createDir(const std::string & path) override;
        std::vector<std::string> listFiles(const std::string & path) override;
        std::string getExtension(const std::string & path) override;
        std::string getFilename(const std::string & path) override;
        std::string getBasename(const std::string & path) override;
        std::string getFilenameFromUrl(const std::string & url) override;
        std::string getBasenameFromUrl(const std::string & url) override;
        bool removeFile(const std::string & path) override;
        bool removeDir(const std::string & path) override;
        bool isDir(const std::string & path) override;
        bool isFile(const std::string & path) override;
        int64_t getFileSize(const std::string & path) override;
        bool copyFile(const std::string & from, const std::string & to) override;
        bool moveFile(const std::string & from, const std::string & to) override;
        std::string join(const std::string & first, const std::string & second) override;
        std::string getFileContentAsString(const std::string & path) override;
        std::vector<uint8_t> getFileContentAsBinary(const std::string & path) override;
        std::string getHomeDir() override;

    private:
        friend ::djinni::JniInterface<::nativium::io::FileHelperPlatformService, ::djinni_generated::NTVFileHelperPlatformService>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nativium/io/FileHelperPlatformService") };
    const jmethodID method_createFile { ::djinni::jniGetMethodID(clazz.get(), "createFile", "(Ljava/lang/String;)Z") };
    const jmethodID method_createFileWithStringContent { ::djinni::jniGetMethodID(clazz.get(), "createFileWithStringContent", "(Ljava/lang/String;Ljava/lang/String;)Z") };
    const jmethodID method_createFileWithBinaryContent { ::djinni::jniGetMethodID(clazz.get(), "createFileWithBinaryContent", "(Ljava/lang/String;[B)Z") };
    const jmethodID method_createDir { ::djinni::jniGetMethodID(clazz.get(), "createDir", "(Ljava/lang/String;)Z") };
    const jmethodID method_listFiles { ::djinni::jniGetMethodID(clazz.get(), "listFiles", "(Ljava/lang/String;)Ljava/util/ArrayList;") };
    const jmethodID method_getExtension { ::djinni::jniGetMethodID(clazz.get(), "getExtension", "(Ljava/lang/String;)Ljava/lang/String;") };
    const jmethodID method_getFilename { ::djinni::jniGetMethodID(clazz.get(), "getFilename", "(Ljava/lang/String;)Ljava/lang/String;") };
    const jmethodID method_getBasename { ::djinni::jniGetMethodID(clazz.get(), "getBasename", "(Ljava/lang/String;)Ljava/lang/String;") };
    const jmethodID method_getFilenameFromUrl { ::djinni::jniGetMethodID(clazz.get(), "getFilenameFromUrl", "(Ljava/lang/String;)Ljava/lang/String;") };
    const jmethodID method_getBasenameFromUrl { ::djinni::jniGetMethodID(clazz.get(), "getBasenameFromUrl", "(Ljava/lang/String;)Ljava/lang/String;") };
    const jmethodID method_removeFile { ::djinni::jniGetMethodID(clazz.get(), "removeFile", "(Ljava/lang/String;)Z") };
    const jmethodID method_removeDir { ::djinni::jniGetMethodID(clazz.get(), "removeDir", "(Ljava/lang/String;)Z") };
    const jmethodID method_isDir { ::djinni::jniGetMethodID(clazz.get(), "isDir", "(Ljava/lang/String;)Z") };
    const jmethodID method_isFile { ::djinni::jniGetMethodID(clazz.get(), "isFile", "(Ljava/lang/String;)Z") };
    const jmethodID method_getFileSize { ::djinni::jniGetMethodID(clazz.get(), "getFileSize", "(Ljava/lang/String;)J") };
    const jmethodID method_copyFile { ::djinni::jniGetMethodID(clazz.get(), "copyFile", "(Ljava/lang/String;Ljava/lang/String;)Z") };
    const jmethodID method_moveFile { ::djinni::jniGetMethodID(clazz.get(), "moveFile", "(Ljava/lang/String;Ljava/lang/String;)Z") };
    const jmethodID method_join { ::djinni::jniGetMethodID(clazz.get(), "join", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;") };
    const jmethodID method_getFileContentAsString { ::djinni::jniGetMethodID(clazz.get(), "getFileContentAsString", "(Ljava/lang/String;)Ljava/lang/String;") };
    const jmethodID method_getFileContentAsBinary { ::djinni::jniGetMethodID(clazz.get(), "getFileContentAsBinary", "(Ljava/lang/String;)[B") };
    const jmethodID method_getHomeDir { ::djinni::jniGetMethodID(clazz.get(), "getHomeDir", "()Ljava/lang/String;") };
};

}  // namespace djinni_generated
