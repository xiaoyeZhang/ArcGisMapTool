/*
 COPYRIGHT 2013 ESRI
 
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

@protocol AGSRemoteResource;
@class AGSCredential;

/**
 @brief Represents an authentication challenge when accessing secured resources
 
 Instances of this class represent an authentication challenge that was raised because a security error was encountered while trying to access
 a secured remote resource. You can use `AGSAuthenticationManager#setChallengeHandler:` in order to register a block for handling all authentication challenges in your app. This block can help centralize  your authentication related logic.
 
 To satisfy the challenge, you  need to do one of the following -
 @li invoke `#continueWithCredential:` with a valid credential. The `#remoteResource` that issued the challenge will try to connect to the resource with those credentials.
 @li invoke `#cancel` to cancel the challenge. The `#remoteResource` that issued the challenge will fail to connect to the resource.
 @li invoke `#trustHostAndContinue` if the challenge was due to an untrusted server certificate and if you choose to trust the server
 
 @since 100
 */
@interface AGSAuthenticationChallenge : NSObject
NS_ASSUME_NONNULL_BEGIN

/** The number of times this particular challenge has failed.
 @since 100
 */
@property (nonatomic, assign, readonly) NSUInteger failureCount;

/** The secured resource that needs authentication.
 @since 100
 */
@property (nullable, nonatomic, weak, readonly) id<AGSRemoteResource> remoteResource;

/** An empty credential that has been pre-configured with the authentication scheme being used by the `#remoteResource`.
 All you need to do is specify is the identity through a username/password, or token, or certificate, and then call `#continueWithCredential:`
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSCredential *proposedCredential;

/** The security realm of the web request.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURLProtectionSpace *protectionSpace;

/**
 The underlying security error that led to this authentication challenge.
 @since 100
 */
@property (nonatomic, strong, readonly) NSError *error;

/**
 The web request used to access the `#remoteResource` that led to this authentication challenge.
 @since 100
 */
@property (nonatomic, copy, readonly) NSURLRequest *request;

/** The host server of the `#remoteResource`.
  This is useful to display to a user when prompting them for credentials when a resource fails to load.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *authenticatingHost;

/** The portal URL will be avilable when the remote resource is a portal or any federated resource.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *portalURL;

/** Type of authentication challenge. This is useful for displaying user interface to user for credentials when a resource fails to load.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSAuthenticationChallengeType type;

/** Attempts to continue loading the `#remoteResource` with the provided credential.
 Continuing with nil will cause the resource to fail to load.
 @since 100
 @see `#proposedCredential`
 */
-(void)continueWithCredential:(nullable AGSCredential*)credential;

/** Adds the `#authenticatingHost` to a list of trusted hosts and repeats the web request.
 @note Only use this method if you are confident that the challenge was rasied due to an untrusted server certificate error, otherwise it will raise an exception. You can check `#type` to make sure challenge is for an untrusted server certificate.
 @since 100
 */
-(void)trustHostAndContinue;

/** Cancels performing the operation that led to the authentication challenge, resource will fail to load.
 @since 100
 */
-(void)cancel;

/** A default handler will be used which displays UI containing information about the challenge and presents appropriate options to the user, for instance, requesting a username & password.
 @since 100
 */
-(void)continueWithDefaultHandling;

/** Returns a BOOL indicating whether the `#remoteResource` is federated with speficied portal url.
 @since 100
 */
- (BOOL)isRemoteResourceFederatedWithPortalURL:(NSURL*)portalURL;

NS_ASSUME_NONNULL_END
@end
