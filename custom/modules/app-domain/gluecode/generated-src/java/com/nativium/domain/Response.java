// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

package com.nativium.domain;

public final class Response implements android.os.Parcelable {


    /*package*/ final boolean mSuccess;

    /*package*/ final String mMessage;

    /*package*/ final ResponseError mError;

    /*package*/ final boolean mHasError;

    /*package*/ final com.nativium.net.http.HttpResponse mHttpResponse;

    public Response(
            boolean success,
            String message,
            ResponseError error,
            boolean hasError,
            com.nativium.net.http.HttpResponse httpResponse) {
        this.mSuccess = success;
        this.mMessage = message;
        this.mError = error;
        this.mHasError = hasError;
        this.mHttpResponse = httpResponse;
    }

    public boolean getSuccess() {
        return mSuccess;
    }

    public String getMessage() {
        return mMessage;
    }

    public ResponseError getError() {
        return mError;
    }

    public boolean getHasError() {
        return mHasError;
    }

    public com.nativium.net.http.HttpResponse getHttpResponse() {
        return mHttpResponse;
    }

    @Override
    public String toString() {
        return "Response{" +
                "mSuccess=" + mSuccess +
                "," + "mMessage=" + mMessage +
                "," + "mError=" + mError +
                "," + "mHasError=" + mHasError +
                "," + "mHttpResponse=" + mHttpResponse +
        "}";
    }


    public static final android.os.Parcelable.Creator<Response> CREATOR
        = new android.os.Parcelable.Creator<Response>() {
        @Override
        public Response createFromParcel(android.os.Parcel in) {
            return new Response(in);
        }

        @Override
        public Response[] newArray(int size) {
            return new Response[size];
        }
    };

    public Response(android.os.Parcel in) {
        this.mSuccess = in.readByte() != 0;
        this.mMessage = in.readString();
        this.mError = new ResponseError(in);
        this.mHasError = in.readByte() != 0;
        this.mHttpResponse = new com.nativium.net.http.HttpResponse(in);
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(android.os.Parcel out, int flags) {
        out.writeByte(this.mSuccess ? (byte)1 : 0);
        out.writeString(this.mMessage);
        this.mError.writeToParcel(out, flags);
        out.writeByte(this.mHasError ? (byte)1 : 0);
        mHttpResponse.writeToParcel(out, flags);
    }

}
