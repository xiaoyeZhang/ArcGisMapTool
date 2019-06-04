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

/** @brief A convenience class to store and retrieve objects in the keychain.
 
 This class represents a generic keychain item which can store objects securely and retrieve them from the keychain.
 The object must implement @c %NSCoding. For example, you can store an @c AGSCredential representing a user's identity 
 and retrieve it when the app is restarted so that the user does not have to log in again.
 
 @define{AGSKeychainItem, ArcGIS}
 @since 100
 */
@interface AGSKeychainItem : NSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the keychain item with given identifier, access group and shared across devices.
 @param identifier Must be unique, for example - com.acme.appname
 @param accessGroup  If you want the new keychain item to be shared among multiple applications, the value of this key must be the name of a keychain access group to which all of the programs that will share this item belong. Otherwise, nil.
 @param acrossDevices If you want to share the keychain item across devices using iCloud Keychain then set to YES. The iCloud Keychain must be enabled on device to make this work.
 @since 100
*/
-(instancetype)initWithIdentifier:(NSString*)identifier accessGroup:(nullable NSString*)accessGroup acrossDevices:(BOOL)acrossDevices;

/** Initialize the keychain item with given identifier, access group and shared across devices.
 @param identifier Must be unique, for example - com.acme.appname
 @param accessGroup  If you want the new keychain item to be shared among multiple applications, the value of this key must be the name of a keychain access group to which all of the programs that will share this item belong. Otherwise, nil.
 @param acrossDevices If you want to share the keychain item across devices using iCloud Keychain then set to YES. The iCloud Keychain must be enabled on device to make this work.
 @since 100
 */
+(instancetype)keychainItemWithIdentifier:(NSString*)identifier accessGroup:(nullable NSString*)accessGroup acrossDevices:(BOOL)acrossDevices;

/** Initialize the keychain item with given identifier, access group and shared across devices.
 @param identifier Must be unique, for example - com.acme.appname
 @param accessGroup  If you want the new keychain item to be shared among multiple applications, the value of this key must be the name of a keychain access group to which all of the programs that will share this item belong. Otherwise, nil.
 @param acrossDevices If you want to share the keychain item across devices using iCloud Keychain then set to YES. The iCloud Keychain must be enabled on device to make this work.
 @param accessible Indicates when a keychain item is accessible. If `acrossDevices` is YES, the valid options are only those which do not end with ThisDeviceOnly, as those cannot sync to another device. For macOS, this works only if `acrossDevices` is YES. You cannot change this option for an existing item. The keychain item will always be persisted with the option you first provided. To change this option, you first have to remove the existing keychain item using `#removeObjectFromKeychainWithCompletion:`.
 @since 100.2
 */
-(instancetype)initWithIdentifier:(NSString*)identifier accessGroup:(nullable NSString*)accessGroup acrossDevices:(BOOL)acrossDevices accessible:(AGSKeychainItemAccessible)accessible;

/** Initialize the keychain item with given identifier, access group and shared across devices.
 @param identifier Must be unique, for example - com.acme.appname
 @param accessGroup  If you want the new keychain item to be shared among multiple applications, the value of this key must be the name of a keychain access group to which all of the programs that will share this item belong. Otherwise, nil.
 @param acrossDevices If you want to share the keychain item across devices using iCloud Keychain then set to YES. The iCloud Keychain must be enabled on device to make this work.
 @param accessible Indicates when a keychain item is accessible. If `acrossDevices` is YES, the valid options are only those which do not end with ThisDeviceOnly, as those cannot sync to another device. For macOS, this works only if `acrossDevices` is YES. You cannot change this option for an existing item. The keychain item will always be persisted with the option you first provided. To change this option, you first have to remove the existing keychain item using `#removeObjectFromKeychainWithCompletion:`.
 @since 100.2
 */
+(instancetype)keychainItemWithIdentifier:(NSString*)identifier accessGroup:(nullable NSString*)accessGroup acrossDevices:(BOOL)acrossDevices accessible:(AGSKeychainItemAccessible)accessible;

#pragma mark -
#pragma mark properties

/** The keychain identifier is used when synchronizing and persisting the cache with the keychain.
 @see `#initWithIdentifier:accessGroup:acrossDevices:`
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *identifier;

/** Use keychain access group to share keychain item among multiple applications. It is used when synchronizing and persisting the cache with the keychain.
 @see `#initWithIdentifier:accessGroup:acrossDevices:acrossDevices:`
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *accessGroup;

/** Indicates whether keychain item is shared across devices using iCloud Keychain or not.
 @see `#initWithIdentifier:accessGroup:acrossDevices:acrossDevices:`
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL sharedAcrossDevices;

#pragma mark -
#pragma mark methods

/** Set an archivable object as the @c kSecValueData in the keychain item.
 @param object The archivable object to store in the keychain.
 @param completion block that is invoked when the operation completes. The `error` argument will be populated if a problem is encountered while storing the item in the keychain.
 @since 100
 */
-(void)writeObjectToKeychain:(id<NSCoding>)object completion:(nullable void(^)(NSError * __nullable error))completion;

/** Retrieve the archivable object from the kSecValueData in the keychain item
 @since 100
 */
-(nullable id<NSCoding>)readObjectFromKeychain;

/** Removes generic keychain item data.
 @param completion block that is invoked when the operation completes. The `error` argument will be populated if a problem is encountered while removing the item from the keychain.
@since 100
 */
-(void)removeObjectFromKeychainWithCompletion:(nullable void(^)(NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
