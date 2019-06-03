/*
 COPYRIGHT 2009 ESRI
 
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
@class AGSCredential;
@class AGSRequestConfiguration;
@protocol AGSRemoteResource;
@protocol AGSLoadable;

#import "AGSObservableOperation.h"

NS_ASSUME_NONNULL_BEGIN

/** @file AGSRequestOperation.h */ //Required for Globals API doc

/** @brief Base class for operations that perform http requests.
 
 The request will execute on a background thread. Once the response has been parsed the
 completion blocks will called.
 
 @li This class encapsulates the logic for accessing secured (token or basic)
 resources. Including refreshing a token if it has expired. It also has the ability 
 to perform the parsing of the response in a child operation so that the main 
 thread of the application is not bogged down.
 
 @li This class, or a subclass thereof, is used by all the tasks execute requests across the wire.
 
 @li This class, or a subclass thereof, is also used by most of the layers for retrieving images or tiles.
 
 @li This class can be used directly, but you will probably use a subclass of it for getting
 back the response data in the format that you are looking for.
 
 @since 100
 */
@interface AGSRequestOperation : AGSObservableOperation <AGSCancelable, NSProgressReporting>

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize an <code>AGSRequestOperation</code> with the specified request.
 @param remoteResource The AGSRemoteResource which is responsible for making the request.
 When the remoteResource is set, properties will get pulled from that such as the credential, requestConfiguration, etc.
 @param request Request to initialize the operation with.
 @return Initialized <code>AGSRequestOperation</code>.
 @since 100
 */
- (instancetype)initWithRemoteResource:(nullable id<AGSRemoteResource>)remoteResource
                               request:(NSURLRequest *)request NS_DESIGNATED_INITIALIZER;

/** Initialize an <code>AGSRequestOperation</code> with the specified url.
 @param url URL to initialize the request operation.
 @return Initialized <code>AGSRequestOperation</code>.
 @since 100
 */
- (instancetype)initWithURL:(NSURL *)url;

/** Initialize an <code>AGSRequestOperation</code> with the specified remote resource, url and
 query parameters.
 @param remoteResource The AGSRemoteResource which is responsible for making the request.
 When the remoteResource is set, properties will get pulled from that such as the credential, requestConfiguration, etc.
 @param URL URL to initialize the request operation.
 @param queryParameters Query parameters to submit along with the request.
 @return Initialized <code>AGSRequestOperation</code>.
 @since 100
 */
-(instancetype)initWithRemoteResource:(nullable id<AGSRemoteResource>)remoteResource
                                  URL:(NSURL *)URL
                      queryParameters:(nullable NSDictionary<NSString*,id> *)queryParameters;

/** Initialize an <code>AGSRequestOperation</code> with the specified remote resource, url,
 query parameters and HTTP method.
 @param remoteResource The AGSRemoteResource which is responsible for making the request.
 When the remoteResource is set, properties will get pulled from that such as the credential, requestConfiguration, etc.
 @param URL URL to initialize the request operation.
 @param queryParameters Query parameters to submit along with the request.
 @param method The AGSRequestHTTPMethod to be used with this request.
 @return Initialized <code>AGSRequestOperation</code>.
 @since 100
 */
-(instancetype)initWithRemoteResource:(nullable id<AGSRemoteResource>)remoteResource
                                  URL:(NSURL*)URL
                      queryParameters:(nullable NSDictionary<NSString*,id> *)queryParameters
                               method:(AGSRequestHTTPMethod)method NS_DESIGNATED_INITIALIZER;
#pragma mark -
#pragma mark properties

/** URL of the resource to make a request from.
 @since 100
 */
@property (nonatomic, strong, readonly) NSURL *URL;

/** Query parameters to be used in the request to #URL.
 @since 100
 */
@property (nullable, copy, readonly) NSDictionary<NSString*,id> *queryParameters;

/** Flag to determine whether or not the request is a GET or a POST and if it
  is a post how it's parameters are encoded.
  @since 100
  */
@property (nonatomic, assign, readwrite) AGSRequestHTTPMethod method;

/** Request object to be used instead of generating one on the fly.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURLRequest *request;

/** Security credentials to access the remote resource. Only applicable if the resource is secured.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSCredential *credential;

/** The AGSRequestConfiguration object which defines the behavior and policies to use when accessing the remote resource.
 Defaults to the [AGSRequestConfiguration globalConfiguration]
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSRequestConfiguration *requestConfiguration;

/** The remote resource, if applicable, that is making the web request.
 @since 100
 */
@property (nullable, nonatomic, weak, readonly) id<AGSRemoteResource> remoteResource;

/** The id<AGSLoadable> object that should be loaded before this request is kicked off.
 @since 100
 */
@property (nullable, nonatomic, weak, readwrite) id<AGSLoadable> loadDependency;

/** The response of the request.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURLResponse *response;

/** If this is set then the data is saved to this file as it is retrieved.
 Must be set to a local file URL.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) NSURL *outputFileURL;

/** If provided, the operation will use NSURLSession to allow for downloading in the background. This requires that @p outputFileURL is also specified.
 @since 100
 */
@property (nullable, nonatomic, copy, readwrite) NSString *sessionID;

/** The number of bytes currently downloaded for this request.
 @since 100
 */
@property (nonatomic, assign, readonly) long long totalBytesDownloaded;

/** The total number of bytes expected to be downloaded. Will be -1 if unknown.
 @since 100
 */
@property (nonatomic, assign, readonly) long long totalBytesExpected;

/** If provided, the operation will call this block with the progress of the request. If the content length is unknown or not specified in the request, @p totalBytesExpected
 will return -1.
 @since 100
 */
@property (nullable, nonatomic, copy, readwrite) void(^progressHandler)(long long totalBytesDownloaded, long long totalBytesExpected);

/** Defaults to YES.
 Specifies whether or not the download session used to download the file is canceled
 when the operation is canceled. Otherwise the session stays in the state that it was in.
 The value of occasionally being able to set this to NO is that you can cancel the operation, which 
 is taking the spot in the queue and have the download continue out of process, or remain paused, 
 if you wish.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL cancelSessionWhenOperationIsCanceled;

/** The progress for this operation.
 As a consumer of this progress property, you can observe it's property changes
 and pause, cancel, resume. Do not, however, set the readwrite properties of this progress object. Those are reserved for
 internal use. Setting them externally will corrupt the state and lead to undefined behavior.
 @since 100.1
 */
@property (nonatomic, strong, readonly) NSProgress *progress;

#pragma mark -
#pragma mark methods

/** Pause the operation. Returns YES if it isPaused is YES after calling this.
 If the operation is in a state where it cannot be paused, it will return NO. For example
 if the operation is canceled or done.
 @since 100
 @deprecated 100.1. Please use the `pause` method through the NSProgress API (exposed via `%NSProgressReporting` through the `#progress` property).
 */
-(BOOL)pause __deprecated_msg("Please use the pause method through the NSProgress API (exposed via NSProgressReporting through the progress property)");

/** Indicates whether the operation is paused.
 @since 100
 @deprecated 100.1. Please use the `isPaused` property through the NSProgress API (exposed via `%NSProgressReporting` through the `#progress` property).
 */
-(BOOL)isPaused __deprecated_msg("Please use the isPaused property through the NSProgress API (exposed via NSProgressReporting through the progress property)");

/** Resumes an operation after it's been paused. Only valid to be called when isPaused is YES.
 @since 100
 @deprecated 100.1. Please use the `resume` method through the NSProgress API (exposed via `%NSProgressReporting` through the `#progress` property).
 */
-(void)resume __deprecated_msg("Please use the resume method through the NSProgress API (exposed via NSProgressReporting through the progress property)");

@end


NS_ASSUME_NONNULL_END
