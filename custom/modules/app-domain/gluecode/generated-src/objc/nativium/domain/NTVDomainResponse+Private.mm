// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/domain/NTVDomainResponse+Private.h"
#import "djinni/objc/DJIMarshal+Private.h"
#import "nativium/domain/NTVDomainResponseError+Private.h"
#import "nativium/net/http/NTVHttpResponse+Private.h"
#include <cassert>

namespace djinni_generated {

auto Response::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::Bool::toCpp(obj.success),
            ::djinni::String::toCpp(obj.message),
            ::djinni_generated::ResponseError::toCpp(obj.error),
            ::djinni::Bool::toCpp(obj.hasError),
            ::djinni_generated::HttpResponse::toCpp(obj.httpResponse)};
}

auto Response::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[NTVDomainResponse alloc] initWithSuccess:(::djinni::Bool::fromCpp(cpp.success))
                                              message:(::djinni::String::fromCpp(cpp.message))
                                                error:(::djinni_generated::ResponseError::fromCpp(cpp.error))
                                             hasError:(::djinni::Bool::fromCpp(cpp.hasError))
                                         httpResponse:(::djinni_generated::HttpResponse::fromCpp(cpp.httpResponse))];
}

}  // namespace djinni_generated
