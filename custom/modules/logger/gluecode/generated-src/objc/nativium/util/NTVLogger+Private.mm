// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/util/NTVLogger+Private.h"
#import "nativium/util/NTVLogger.h"
#import "djinni/objc/DJICppWrapperCache+Private.h"
#import "djinni/objc/DJIError.h"
#import "djinni/objc/DJIMarshal+Private.h"
#import "nativium/util/NTVLoggerLevel+Private.h"
#import "nativium/util/NTVLoggerPlatformService+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface NTVLogger ()

- (id)initWithCpp:(const std::shared_ptr<::nativium::util::Logger>&)cppRef;

@end

@implementation NTVLogger {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::nativium::util::Logger>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::nativium::util::Logger>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nullable NTVLogger *)shared {
    try {
        auto objcpp_result_ = ::nativium::util::Logger::shared();
        return ::djinni_generated::Logger::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setPlatformService:(nullable id<NTVLoggerPlatformService>)ps {
    try {
        _cppRefHandle.get()->setPlatformService(::djinni_generated::LoggerPlatformService::toCpp(ps));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable id<NTVLoggerPlatformService>)getPlatformService {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getPlatformService();
        return ::djinni_generated::LoggerPlatformService::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)hasPlatformService {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->hasPlatformService();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)allowedLevel:(NTVLoggerLevel)level {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->allowedLevel(::djinni::Enum<::nativium::util::LoggerLevel, NTVLoggerLevel>::toCpp(level));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setLevel:(NTVLoggerLevel)level {
    try {
        _cppRefHandle.get()->setLevel(::djinni::Enum<::nativium::util::LoggerLevel, NTVLoggerLevel>::toCpp(level));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)v:(nonnull NSString *)message {
    try {
        ::nativium::util::Logger::v(::djinni::String::toCpp(message));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)d:(nonnull NSString *)message {
    try {
        ::nativium::util::Logger::d(::djinni::String::toCpp(message));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)i:(nonnull NSString *)message {
    try {
        ::nativium::util::Logger::i(::djinni::String::toCpp(message));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)w:(nonnull NSString *)message {
    try {
        ::nativium::util::Logger::w(::djinni::String::toCpp(message));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)e:(nonnull NSString *)message {
    try {
        ::nativium::util::Logger::e(::djinni::String::toCpp(message));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)setGroup:(nonnull NSString *)group {
    try {
        ::nativium::util::Logger::setGroup(::djinni::String::toCpp(group));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto Logger::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto Logger::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<NTVLogger>(cpp);
}

}  // namespace djinni_generated

@end