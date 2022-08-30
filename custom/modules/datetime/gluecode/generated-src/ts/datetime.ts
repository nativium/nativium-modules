// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni


export interface DateTime {
}
export interface DateTime_statics {
    getDateTimeFromString(value: string): Date;
    getStringFromDateTime(value: Date): string;
    getDateTimeFromStringWithFormat(value: string, format: string): Date;
    getCurrentDateTimeAsString(): string;
    getCurrentDateTime(): Date;
    getDateTimeFromSeconds(value: bigint): Date;
    getDateTimeFromMilliseconds(value: bigint): Date;
    getTimestampInMillisecondsFromDateTime(value: Date): bigint;
    getTimestampInSecondsFromDateTime(value: Date): bigint;
    getCurrentTimestampInSecondsAsString(): string;
    getCurrentTimestampInSeconds(): bigint;
    getCurrentTimestampInMillisecondsAsString(): string;
    getCurrentTimestampInMilliseconds(): bigint;
    getFormattedStringFromDateTime(value: Date, format: string): string;
    getMillisecondsFromTimeString(value: string): bigint;
    getDateTimeFromTimeInPosixTimezone(time: string, timezone: string): Date;
}

export interface Datetime_statics {
    DateTime: DateTime_statics;
}
