/*
 COPYRIGHT 2012 ESRI
 
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

@class AGSKeychainItem;

/** @file AGSCredentialCache.h */ //Required for Globals API doc

/** @brief A cache containing credentials to reuse
 
 Instances of this class represent a cache containing credentials. 
 Objects that use the same cache could potentially reuse credentials if they need to access the same
 security realm and a credential for it already exists in the cache.
 
 @since 100
 */
@interface AGSCredentialCache : NSObject<NSCoding>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates whether to save credential cache to keychain or not.
 @see `#enableAutoSyncToKeychainWithIdentifier:accessGroup:acrossDevices:`
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL autoSyncToKeychain;

/** Instance of the keychain item if the credential cache is synced with keychain.
 @see `#enableAutoSyncToKeychainWithIdentifier:accessGroup:acrossDevices:`
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSKeychainItem *keychainItem;

#pragma mark -
#pragma mark methods

/** Removes all @c AGSCredential objects from the cache.
 @since 100
 */
- (void)removeAllCredentials;

/** Enables automatic syncing of credential cache to the keychain. An exception will be raised if identifier is nil or empty. If item is available in the keychain for the specified identifier then it will be fetched from the keychain and replace the contents of the current credential cache. If no item is found with the specified identifier, then current credential cache will be pushed to the keychain. Any changes to the credential cache after auto-syncing is enabled will be pushed to keychain automatically.
 @param identifier The keychain identifier. Must be unique. Cannot be nil.
 @param accessGroup If you want the credential cache keychain item to be shared among multiple applications, the value of this key must be the name of a keychain access group to which all of the programs that will share this item belong. Otherwise, nil.
 @param acrossDevices If you want to share the keychain item across devices using iCloud Keychain then set to YES. The iCloud Keychain must be enabled on device to make this work.
 @since 100
 */
- (void)enableAutoSyncToKeychainWithIdentifier:(NSString*)identifier accessGroup:(nullable NSString*)accessGroup acrossDevices:(BOOL)acrossDevices;


/** Enables automatic syncing of credential cache to the keychain. An exception will be raised if identifier is nil or empty. If item is available in the keychain for the specified identifier then it will be fetched from the keychain and replace the contents of the current credential cache. If no item is found with the specified identifier, then current credential cache will be pushed to the keychain. Any changes to the credential cache after auto-syncing is enabled will be pushed to keychain automatically.
 @param identifier The keychain identifier. Must be unique. Cannot be nil.
 @param accessGroup If you want the credential cache keychain item to be shared among multiple applications, the value of this key must be the name of a keychain access group to which all of the programs that will share this item belong. Otherwise, nil.
 @param acrossDevices If you want to share the keychain item across devices using iCloud Keychain then set to YES. The iCloud Keychain must be enabled on device to make this work.
 @param accessible Indicates when a keychain item is accessible. If `acrossDevices` is YES, the valid options are only those which do not end with ThisDeviceOnly, as those cannot sync to another device. For macOS, this works only if `acrossDevices` is YES. You cannot change this option after the first time you enable auto sync in your app. The keychain item will always be persisted with the option you first provided while enabling auto sync. To change this option, you first have to remove the existing keychain item using `AGSCredentialCache#removeFromKeychainWithIdentifier:completion:`.
 @since 100.2
 */
- (void)enableAutoSyncToKeychainWithIdentifier:(NSString*)identifier accessGroup:(nullable NSString*)accessGroup acrossDevices:(BOOL)acrossDevices accessible:(AGSKeychainItemAccessible)accessible;


/** Disables automatic syncing of credential cache to the keychain. If you want to remove entry from keychain then use `AGSCredentialCache#removeFromKeychainWithIdentifier:completion:`.
 @since 100
 */
- (void)disableAutoSyncToKeychain;

/** Removes credential cache from keychain. If automatic syncing of credential cache is enabled for the same keychain identifier then any activity on credential cache will re-add the keychin item. If `acrossDevices` was true while enabling automatic syncing then it will be honored and iCloud Keychain item will be removed as well.
 @since 100
 */
+(void)removeFromKeychainWithIdentifier:(NSString*)identifier completion:(nullable void(^)(NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
