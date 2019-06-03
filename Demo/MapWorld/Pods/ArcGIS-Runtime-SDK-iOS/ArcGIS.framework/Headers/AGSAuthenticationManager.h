/*
 COPYRIGHT 2015 ESRI
 
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

#import "AGSAuthenticationManagerDelegate.h"

@class AGSAuthenticationChallenge;
@class AGSCredentialCache;
@class AGSOAuthConfiguration;

/** @file AGSAuthenticationManager.h */ //Required for Globals API doc

/** @brief A class to manage authentication
 
 This class allows you to manage authentication/security related events.
 
 It raises an `AGSAuthenticationChallenge` whenever an authentication or security issue is encountered anywhere in the API. It also provides a default challenge handler which displays UI containing information about the challenge and presents appropriate options to the user, for instance, requesting a username & password. If you want to handle authentication challenges yourself, for example to display your own custom UI, you can provide your own `#delegate`
 
 @note For challenges related to secure resources that support oAuth, if you provide to the authentication manager a ClientID, the default handler will use the resource's standard oAuth dialog for signing in (as opposed to a generic alert view). See `#OAuthConfigurations`
 
 It also maintains a cache (in memory) of credentials that have been previously used to satisfy authentication challenges. This allows credentials to be reused, where appropriate, and prevent unnecessary or duplicate challenges from being issued while accessing secure resources from the same security realm. Additionally, the cache can easily be persisted in the keychain (See `AGSCredentialCache#enableAutoSyncToKeychainWithIdentifier:accessGroup:acrossDevices:`) so that if the app is restarted, the cache is automatically pre-populated with saved credentials and the user does not have to sign in again.
 
 @note When the user wants to log out, you need to explicitly clear the cache by calling `AGSCredentialCache#removeAllCredentials`
 
 @since 100
 */

@interface AGSAuthenticationManager : NSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** The singleton instance of authentication manager
 @since 100
 */
+(instancetype)sharedAuthenticationManager;

#pragma mark -
#pragma mark properties

/** The delegate to be notified whenever any authentication challenges are encountered. This delegate can help centralize all the authentication related logic in your app. If you don't provide a delegate, a default challenge handler will be used to display UI containing information about the challenge and presents appropriate options to the user, for instance, requesting a username & password. You can also use the delegate to customize how the default handler presents UI.
 
 @since 100
 */
@property (nullable, nonatomic, weak, readwrite) id<AGSAuthenticationManagerDelegate> delegate;

/**
 A list of hosts that can be trusted even if they are using self-signed certificates.
 */
@property (nonatomic, strong, readonly) NSMutableArray<NSString*> *trustedHosts;

/** The cache (in-memory) of credentials being maintained by the authentication manager. The cache contains credentials that have been previously used to satisfy authentication challenges. This allows credentials to be reused, where appropriate, and prevent unnecessary or duplicate challenges from being issued while accessing secure resources from the same security realm.
 
 The cache can be persisted securely in the keychain (See `AGSCredentialCache#enableAutoSyncToKeychainWithIdentifier:accessGroup:acrossDevices:`) so that if the app is restarted, the cache is automatically pre-populated with saved credentials and the user does not have to sign in again.
 
 @note When the user wants to log out, you need to explicitly clear the cache by calling `AGSCredentialCache#removeAllCredentials`
 @since 100
 */
@property (nonatomic, strong, readonly) AGSCredentialCache *credentialCache;

#if !TARGET_OS_TV
/** A list of configurations specifying whether OAuth should be used by the default handler to respond to an authentication challenge. If there isn't a configuration that applies to the challenge, the default handler displays a generic view instead of the resource's OAuth login view.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSOAuthConfiguration*> *OAuthConfigurations;
#endif

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
