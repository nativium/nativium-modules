// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "nativium/util/NTVLoggerLevel.h"
#import <Foundation/Foundation.h>
@class NTVLogger;
@protocol NTVLoggerPlatformService;


@interface NTVLogger : NSObject

+ (nullable NTVLogger *)shared;

- (void)setPlatformService:(nullable id<NTVLoggerPlatformService>)ps;

- (nullable id<NTVLoggerPlatformService>)getPlatformService;

- (BOOL)hasPlatformService;

- (BOOL)allowedLevel:(NTVLoggerLevel)level;

- (void)setLevel:(NTVLoggerLevel)level;

+ (void)v:(nonnull NSString *)message;

+ (void)d:(nonnull NSString *)message;

+ (void)i:(nonnull NSString *)message;

+ (void)w:(nonnull NSString *)message;

+ (void)e:(nonnull NSString *)message;

+ (void)setGroup:(nonnull NSString *)group;

@end
