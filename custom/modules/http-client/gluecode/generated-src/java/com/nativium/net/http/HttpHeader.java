// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

package com.nativium.net.http;

public final class HttpHeader implements android.os.Parcelable {


    /*package*/ final String mName;

    /*package*/ final String mValue;

    public HttpHeader(
            String name,
            String value) {
        this.mName = name;
        this.mValue = value;
    }

    public String getName() {
        return mName;
    }

    public String getValue() {
        return mValue;
    }

    @Override
    public String toString() {
        return "HttpHeader{" +
                "mName=" + mName +
                "," + "mValue=" + mValue +
        "}";
    }


    public static final android.os.Parcelable.Creator<HttpHeader> CREATOR
        = new android.os.Parcelable.Creator<HttpHeader>() {
        @Override
        public HttpHeader createFromParcel(android.os.Parcel in) {
            return new HttpHeader(in);
        }

        @Override
        public HttpHeader[] newArray(int size) {
            return new HttpHeader[size];
        }
    };

    public HttpHeader(android.os.Parcel in) {
        this.mName = in.readString();
        this.mValue = in.readString();
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(android.os.Parcel out, int flags) {
        out.writeString(this.mName);
        out.writeString(this.mValue);
    }

}
