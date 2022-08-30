// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import <Foundation/Foundation.h>

@interface NTVHttpRequestParam : NSObject
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
- (nonnull instancetype)initWithName:(nonnull NSString *)name
                               value:(nonnull NSString *)value NS_DESIGNATED_INITIALIZER;
+ (nonnull instancetype)httpRequestParamWithName:(nonnull NSString *)name
                                           value:(nonnull NSString *)value;

@property (nonatomic, readonly, nonnull) NSString * name;

@property (nonatomic, readonly, nonnull) NSString * value;

@end
