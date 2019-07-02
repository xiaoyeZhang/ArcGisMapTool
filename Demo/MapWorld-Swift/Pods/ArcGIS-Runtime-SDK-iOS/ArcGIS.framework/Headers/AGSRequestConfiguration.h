/*
 COPYRIGHT 2014 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */

@class AGSAuthenticationChallenge;

NS_ASSUME_NONNULL_BEGIN

/** @file AGSRequestConfiguration.h */ //Required for Globals API doc

/** @brief Networking related configuration of resources

 Instances of this class represent networking related configuration of resources (`AGSRemoteResource`).
 You can access the default configuration used by all resources using `#globalConfiguration`.
 
 You can change the configuration of any resource individually by specifying it using `AGSRemoteResource#requestConfiguration`, or you can change it for all resources using `#setGlobalConfiguration:`.
 
 @since 100
 */
@interface AGSRequestConfiguration : NSObject <NSCopying>

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** The cache policy that should be used for making web requests to the remote resource.
 Default value is NSURLRequestUseProtocolCachePolicy
 @since 100
 */
@property (nonatomic, assign, readwrite) NSURLRequestCachePolicy requestCachePolicy;

/** The timeout interval (in seconds) for web requests. Default value is 60 seconds.
 @since 100
 */
@property (nonatomic, assign, readwrite) NSTimeInterval timeoutInterval;

/** A block specifying whether or not `AGSAuthenticationChallenge#challengeHandler` should be invoked to handle authentication challenges for the remote resource.
 If the block returns NO, any security errors encountered with web requests to this remote resource will result in failure.
 Default is nil, in which case the challenge handler will be invoked. You should set a custom handler to perform authentication and potentially recover from any security errors.
 @since 100
 */
@property (nullable, nonatomic, copy, readwrite) BOOL (^shouldIssueAuthenticationChallenge)(AGSAuthenticationChallenge *challenge);

/** Whether the response should be cached. Default is YES.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL shouldCacheResponse;

/** Any custom headers you would like to set on the request with the exception of User-Agent and Content-Type. If you need to add info to the User-Agent header use  @c AGSRequest#setAdditionalUserAgentInfo: .
 @since 100
 */
@property (nullable, nonatomic, copy, readwrite) NSDictionary<NSString*,NSString*> *userHeaders;

/** Whether or not the http/s method is forced to be POST. Default is NO.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL forcePost;

/** Specifies whether or not downloading files is allowed in the background. The default setting is YES.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL allowsBackgroundSessionForDownloads;

#if TARGET_OS_IPHONE
/** Specifies whether or not cellular access can be used to download files. This will only affect AGSRequestOperation's that
 have set the @p outputFileURL parameter. The default setting is YES.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL allowsCellularAccessForDownloads;

/** The timeout interval (in seconds) for web requests when the application is in the
 background. Default value is 20 seconds.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) NSTimeInterval backgroundTimeoutInterval;
#endif

#pragma mark -
#pragma mark methods

/** The global AGSRequestConfiguration object that is used for resources that do not have a configuration specified.
 @since 100
 */
+(AGSRequestConfiguration*)globalConfiguration;

/** Set the global request configuration. This will affect any AGSRemoteResource objects that are using the globalConfiguration.
 Resources are using the globalConfiguration if their requestConfiguration property is nil.
 @param globalConfiguration The request configuration you want to set as global configuration
 @since 100
 */
+(void)setGlobalConfiguration:(AGSRequestConfiguration*)globalConfiguration;

/** Used to set some specific user agent information. This is useful for
 analytics.
 @param additionalInfo to send along in the user agent string
 @since 100
 */
+(void)setAdditionalUserAgentInfo:(nullable NSString*)additionalInfo;

/** Class method to retrieve the additional user agent string.
 @since 100
 */
+(NSString*)additionalUserAgentInfo;

@end


/** @brief Networking related configuration of resources useful for debugging
 
 This category contains networking related configuration that can be helpful to debug network traffic.
 You can change the configuration of any resource individually by specifying it using `AGSRemoteResource#requestConfiguration`, or you can change it for all resources using `#setGlobalConfiguration:`.

 @note You should not use this in production deployment as it may impact performance of the application.
 
 @since 100
 */
@interface AGSRequestConfiguration (Debug)

/** Set to true if you want to log requests wherever this request configuration object is used.
 @note This will affect performance and should only be used for debugging.
 Default value is false.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL debugLogRequests;

/** Set to true if you want to log responses wherever this request configuration object is used.
 @note This will affect performance and should only be used for debugging.
 Default value is false.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL debugLogResponses;

/** File location to write the log messages when logging is turned on for requests or responses.
 If this is null and logging is turned on then the logs will be written to the console.
 If the file exists when the application starts up, it will be deleted and a new file will be created. If it does not exist it will be created.
 The file can grow quite large quickly, so do not leave logging on for longer than necessary
 and clean up the file. 
 The file is in markdown format for easy visual parsing in a markdown previewing application.
 Default value is nil.
 @note This will affect performance and should only be used for debugging.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) NSURL *debugLogFileURL;

/** Set to true if you want the request headers logged with the requests. Only honored when `#debugLogRequests` is true.
 Default value is false.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL debugLogIncludeRequestHeaders;

/** Set to true if you want the response headers logged with the responses. Only honored when `#debugLogResponses` is true.
 Default value is false.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL debugLogIncludeResponseHeaders;

@end

NS_ASSUME_NONNULL_END




