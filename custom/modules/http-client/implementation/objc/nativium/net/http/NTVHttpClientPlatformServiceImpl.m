#import "NTVHttpClientPlatformServiceImpl.h"

@interface NTVHttpClientPlatformServiceImpl ()

@end

@implementation NTVHttpClientPlatformServiceImpl

//------------------------------------------------------------------------------
#pragma mark - Class Initializer
//------------------------------------------------------------------------------

+ (instancetype)proxy
{
    return [[self alloc] init];
}

//------------------------------------------------------------------------------
#pragma mark - Initialization
//------------------------------------------------------------------------------

- (instancetype)init
{
    self = [super init];
    if (self)
    {
        //
    }
    return self;
}

//------------------------------------------------------------------------------
#pragma mark - NTVHttpClientPlatformServiceImpl
//------------------------------------------------------------------------------

- (nonnull NTVHttpResponse *)doRequest:(nonnull NTVHttpRequest *)request
{
    // general
    NSURL *nsurl = [[NSURL alloc] initWithString:[request url]];

    NSMutableURLRequest *urlRequest = [NSMutableURLRequest requestWithURL:nsurl];
    [urlRequest setHTTPMethod:[self getMethodFromHttpMethod:[request method]]];
    [urlRequest setCachePolicy:NSURLRequestReloadIgnoringLocalCacheData];

    // headers
    if ([request headers] != nil && [request headers].count > 0)
    {
        for (NTVHttpHeader *header in [request headers])
        {
            if ([header name] != nil && [header value] != nil)
            {
                [urlRequest setValue:[header value] forHTTPHeaderField:[header name]];
            }
        }
    }

    // cookies
    [urlRequest setHTTPShouldHandleCookies:YES];

    NSString *requestCookies = @"";

    if ([request cookies] != nil && [request cookies].count > 0)
    {
        for (int x = 0; x < [request cookies].count; x++)
        {
            NTVHttpCookie *cookie = [request cookies][x];

            if ([cookie name] != nil && [cookie value] != nil)
            {
                if (x > 0)
                {
                    requestCookies = [requestCookies stringByAppendingString:@"; "];
                }

                requestCookies = [requestCookies stringByAppendingFormat:@"%@=%@", [cookie name], [cookie value]];
            }
        }
    }

    if ([requestCookies length] > 0)
    {
        [urlRequest setValue:requestCookies forHTTPHeaderField:@"Cookie"];
    }

    // request data
    NSString *body = @"";

    if ([request params] != nil && [request params].count > 0)
    {
        for (NTVHttpRequestParam *param in [request params])
        {
            if ([param name] != nil && [param value] != nil)
            {
                NSString *format;

                if (body != nil && [body length] > 0)
                {
                    format = @"&%@=%@";
                }
                else if (body != nil)
                {
                    format = @"%@=%@";
                }

                body = [body stringByAppendingString:[NSString stringWithFormat:format, [param name], [param value]]];
            }
        }
    }
    else
    {
        if ([request body] != nil)
        {
            body = [request body];
        }
    }

    // request data
    if (body != nil)
    {
        NSData *requestData = [body dataUsingEncoding:NSUTF8StringEncoding];

        if (requestData != nil)
        {
            [urlRequest setHTTPBody:requestData];
            [urlRequest setValue:[NSString stringWithFormat:@"%lu", (unsigned long)[requestData length]] forHTTPHeaderField:@"Content-Length"];
        }
    }

    // prepare and do the request
    NSURLResponse *response = nil;
    NSError *error = nil;
    NSData *receivedData = [self sendSynchronousRequest:urlRequest returningResponse:&response error:&error];
    NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *)response;

    if (error != nil)
    {
        return [[NTVHttpResponse alloc] initWithCode:((int)[httpResponse statusCode]) body:@"" url:[request url] headers:@[] cookies:@[]];
    }

    // get response body
    NSString *responseBody = @"";
    [NSString stringEncodingForData:receivedData encodingOptions:nil convertedString:&responseBody usedLossyConversion:nil];

    // get response headers
    NSDictionary *responderHeaders = [(NSHTTPURLResponse *)response allHeaderFields];
    NSMutableArray<NTVHttpHeader *> *headers = [NSMutableArray array];

    if (responderHeaders != nil)
    {
        for (NSString *headerName in responderHeaders)
        {
            if (headerName != nil)
            {
                NSString *headerValue = responderHeaders[headerName];

                if (headerValue != nil)
                {
                    NTVHttpHeader *header = [[NTVHttpHeader alloc] initWithName:headerName value:headerValue];
                    [headers addObject:header];
                }
            }
        }
    }

    // get response cookies
    NSMutableArray<NTVHttpCookie *> *cookies = [NSMutableArray array];

    NSArray<NSHTTPCookie *> *responseCookies = [NSHTTPCookie cookiesWithResponseHeaderFields:((NSHTTPURLResponse *)response).allHeaderFields forURL:response.URL];

    for (NSHTTPCookie *responseCookie in responseCookies)
    {
        if ([responseCookie name] != nil && [responseCookie value] != nil)
        {
            NTVHttpCookie *cookie = [[NTVHttpCookie alloc] initWithName:[responseCookie name] value:[responseCookie value]];
            [cookies addObject:cookie];
        }
    }

    return [[NTVHttpResponse alloc] initWithCode:((int)[httpResponse statusCode]) body:responseBody url:[request url] headers:headers cookies:cookies];
}

- (nonnull NSString *)getMethodFromHttpMethod:(NTVHttpMethod)method
{
    switch (method)
    {
    case NTVHttpMethodMethodGet:
        return @"GET";
        break;

    case NTVHttpMethodMethodPost:
        return @"POST";
        break;

    case NTVHttpMethodMethodPut:
        return @"PUT";
        break;

    case NTVHttpMethodMethodHead:
        return @"HEAD";
        break;

    case NTVHttpMethodMethodPatch:
        return @"PATCH";
        break;

    case NTVHttpMethodMethodTrace:
        return @"TRACE";
        break;

    case NTVHttpMethodMethodDelete:
        return @"DELETE";
        break;

    case NTVHttpMethodMethodConnect:
        return @"CONNECT";
        break;

    case NTVHttpMethodMethodOptions:
        return @"OPTIONS";
        break;

    default:
        return @"";
        break;
    }
}

- (NSData *)sendSynchronousRequest:(NSURLRequest *)request returningResponse:(NSURLResponse **)response error:(NSError **)error
{
    dispatch_group_t group = dispatch_group_create();
    dispatch_group_enter(group);

    NSError __block *err = NULL;
    NSData __block *data;
    NSURLResponse __block *resp;

    [[[NSURLSession sharedSession] dataTaskWithRequest:request
                                     completionHandler:^(NSData *_data, NSURLResponse *_response, NSError *_error) {
                                         resp = _response;
                                         err = _error;
                                         data = _data;
                                         dispatch_group_leave(group);
                                     }] resume];

    dispatch_group_wait(group, DISPATCH_TIME_FOREVER);

    if (response)
    {
        *response = resp;
    }

    if (error)
    {
        *error = err;
    }

    return data;
}

@end
