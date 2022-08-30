// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/domain/NTVDomainCustomer+Private.h"
#import "djinni/objc/DJIMarshal+Private.h"
#import "nativium/enumerator/NTVEnumeratorCustomerStatusEnum+Private.h"
#include <cassert>

namespace djinni_generated {

auto Customer::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::I64::toCpp(obj.id),
            ::djinni::String::toCpp(obj.name),
            ::djinni::String::toCpp(obj.token),
            ::djinni::Enum<::nativium::enumerator::CustomerStatusEnum, NTVEnumeratorCustomerStatusEnum>::toCpp(obj.status)};
}

auto Customer::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[NTVDomainCustomer alloc] initWithId:(::djinni::I64::fromCpp(cpp.id))
                                            name:(::djinni::String::fromCpp(cpp.name))
                                           token:(::djinni::String::fromCpp(cpp.token))
                                          status:(::djinni::Enum<::nativium::enumerator::CustomerStatusEnum, NTVEnumeratorCustomerStatusEnum>::fromCpp(cpp.status))];
}

}  // namespace djinni_generated