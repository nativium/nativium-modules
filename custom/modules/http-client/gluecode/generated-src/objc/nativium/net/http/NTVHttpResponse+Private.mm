// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/net/http/NTVHttpResponse+Private.h"
#import "djinni/objc/DJIMarshal+Private.h"
#import "nativium/net/http/NTVHttpCookie+Private.h"
#import "nativium/net/http/NTVHttpHeader+Private.h"
#include <cassert>

namespace djinni_generated {

auto HttpResponse::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::I32::toCpp(obj.code),
            ::djinni::String::toCpp(obj.body),
            ::djinni::String::toCpp(obj.url),
            ::djinni::List<::djinni_generated::HttpHeader>::toCpp(obj.headers),
            ::djinni::List<::djinni_generated::HttpCookie>::toCpp(obj.cookies)};
}

auto HttpResponse::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[NTVHttpResponse alloc] initWithCode:(::djinni::I32::fromCpp(cpp.code))
                                            body:(::djinni::String::fromCpp(cpp.body))
                                             url:(::djinni::String::fromCpp(cpp.url))
                                         headers:(::djinni::List<::djinni_generated::HttpHeader>::fromCpp(cpp.headers))
                                         cookies:(::djinni::List<::djinni_generated::HttpCookie>::fromCpp(cpp.cookies))];
}

}  // namespace djinni_generated
