// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/net/http/NTVHttpCookie+Private.h"
#import "djinni/objc/DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto HttpCookie::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::String::toCpp(obj.name),
            ::djinni::String::toCpp(obj.value)};
}

auto HttpCookie::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[NTVHttpCookie alloc] initWithName:(::djinni::String::fromCpp(cpp.name))
                                         value:(::djinni::String::fromCpp(cpp.value))];
}

}  // namespace djinni_generated
