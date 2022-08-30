// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/domain/NTVDomainCustomer.h"
#import "nativium/domain/NTVDomainResponse.h"
#import <Foundation/Foundation.h>

@interface NTVSystemServiceCustomerSystemServiceLoginData : NSObject
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
- (nonnull instancetype)initWithResponse:(nonnull NTVDomainResponse *)response
                                customer:(nonnull NTVDomainCustomer *)customer NS_DESIGNATED_INITIALIZER;
+ (nonnull instancetype)customerSystemServiceLoginDataWithResponse:(nonnull NTVDomainResponse *)response
                                                          customer:(nonnull NTVDomainCustomer *)customer;

@property (nonatomic, readonly, nonnull) NTVDomainResponse * response;

@property (nonatomic, readonly, nonnull) NTVDomainCustomer * customer;

@end
