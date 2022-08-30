// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/enumerator/NTVEnumeratorCustomerStatusEnum.h"
#import <Foundation/Foundation.h>

@interface NTVDomainCustomer : NSObject
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
- (nonnull instancetype)initWithId:(int64_t)id
                              name:(nonnull NSString *)name
                             token:(nonnull NSString *)token
                            status:(NTVEnumeratorCustomerStatusEnum)status NS_DESIGNATED_INITIALIZER;
+ (nonnull instancetype)customerWithId:(int64_t)id
                                  name:(nonnull NSString *)name
                                 token:(nonnull NSString *)token
                                status:(NTVEnumeratorCustomerStatusEnum)status;

@property (nonatomic, readonly) int64_t id;

@property (nonatomic, readonly, nonnull) NSString * name;

@property (nonatomic, readonly, nonnull) NSString * token;

@property (nonatomic, readonly) NTVEnumeratorCustomerStatusEnum status;

@end