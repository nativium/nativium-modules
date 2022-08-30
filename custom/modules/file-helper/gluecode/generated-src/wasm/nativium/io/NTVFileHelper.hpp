// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "djinni/wasm/djinni_wasm.hpp"
#include "nativium/io/FileHelper.hpp"

namespace djinni_generated {

struct NTVFileHelper : ::djinni::JsInterface<::nativium::io::FileHelper, NTVFileHelper> {
    using CppType = std::shared_ptr<::nativium::io::FileHelper>;
    using CppOptType = std::shared_ptr<::nativium::io::FileHelper>;
    using JsType = em::val;
    using Boxed = NTVFileHelper;

    static CppType toCpp(JsType j) { return _fromJs(j); }
    static JsType fromCppOpt(const CppOptType& c) { return {_toJs(c)}; }
    static JsType fromCpp(const CppType& c) {
        djinni::checkForNull(c.get(), "NTVFileHelper::fromCpp");
        return fromCppOpt(c);
    }

    static em::val cppProxyMethods();

    static em::val shared();
    static void setPlatformService(const CppType& self, const em::val& w_ps);
    static em::val getPlatformService(const CppType& self);
    static bool hasPlatformService(const CppType& self);
    static bool createFile(const std::string& w_path);
    static bool createFileWithStringContent(const std::string& w_path,const std::string& w_content);
    static bool createFileWithBinaryContent(const std::string& w_path,const em::val& w_content);
    static bool createDir(const std::string& w_path);
    static em::val listFiles(const std::string& w_path);
    static std::string getExtension(const std::string& w_path);
    static std::string getFilename(const std::string& w_path);
    static std::string getBasename(const std::string& w_path);
    static std::string getFilenameFromUrl(const std::string& w_url);
    static std::string getBasenameFromUrl(const std::string& w_url);
    static bool removeFile(const std::string& w_path);
    static bool removeDir(const std::string& w_path);
    static bool isDir(const std::string& w_path);
    static bool isFile(const std::string& w_path);
    static int64_t getFileSize(const std::string& w_path);
    static bool copyFile(const std::string& w_from,const std::string& w_to);
    static bool moveFile(const std::string& w_from,const std::string& w_to);
    static std::string join(const std::string& w_first,const std::string& w_second);
    static std::string getFileContentAsString(const std::string& w_path);
    static em::val getFileContentAsBinary(const std::string& w_path);
    static std::string getHomeDir();

};

}  // namespace djinni_generated
