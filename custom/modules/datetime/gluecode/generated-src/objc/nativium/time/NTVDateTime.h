// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import <Foundation/Foundation.h>


@interface NTVDateTime : NSObject

+ (nonnull NSDate *)getDateTimeFromString:(nonnull NSString *)value;

+ (nonnull NSString *)getStringFromDateTime:(nonnull NSDate *)value;

+ (nonnull NSDate *)getDateTimeFromStringWithFormat:(nonnull NSString *)value
                                             format:(nonnull NSString *)format;

+ (nonnull NSString *)getCurrentDateTimeAsString;

+ (nonnull NSDate *)getCurrentDateTime;

+ (nonnull NSDate *)getDateTimeFromSeconds:(int64_t)value;

+ (nonnull NSDate *)getDateTimeFromMilliseconds:(int64_t)value;

+ (int64_t)getTimestampInMillisecondsFromDateTime:(nonnull NSDate *)value;

+ (int64_t)getTimestampInSecondsFromDateTime:(nonnull NSDate *)value;

+ (nonnull NSString *)getCurrentTimestampInSecondsAsString;

+ (int64_t)getCurrentTimestampInSeconds;

+ (nonnull NSString *)getCurrentTimestampInMillisecondsAsString;

+ (int64_t)getCurrentTimestampInMilliseconds;

+ (nonnull NSString *)getFormattedStringFromDateTime:(nonnull NSDate *)value
                                              format:(nonnull NSString *)format;

+ (int64_t)getMillisecondsFromTimeString:(nonnull NSString *)value;

+ (nonnull NSDate *)getDateTimeFromTimeInPosixTimezone:(nonnull NSString *)time
                                              timezone:(nonnull NSString *)timezone;

@end