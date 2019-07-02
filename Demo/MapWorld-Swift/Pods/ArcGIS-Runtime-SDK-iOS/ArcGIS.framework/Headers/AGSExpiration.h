/*
 COPYRIGHT 2019 ESRI
 
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

#import "AGSObject.h"
/** @file AGSExpiration.h */ //Required for Globals API doc

/** @brief Expiration details, that indicate whether a given package is out of date.
 
 Expiration details can indicate that the package in question:
 1. is still valid
 2. has expired and should be used with caution (see `AGSExpirationTypeAllowExpiredAccess`)
 3. has expired and can no longer be used (see `AGSExpirationTypePreventExpiredAccess`)
 
 @since 100.5
 */
@interface AGSExpiration : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init NS_UNAVAILABLE;

#pragma mark -
#pragma mark properties

/** The date and time when the package will expire.
 @since 100.5
 */
@property (nullable, nonatomic, strong, readonly) NSDate *dateTime;

/** Returns YES if the given package has expired
 @since 100.5
 */
@property (nonatomic, assign, readonly, getter=isExpired) BOOL expired;

/** An accompanying message which provides contextual information when the package has expired.
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSString *message;

/** The type of expiration for the given package.
 @since 100.5
 */
@property (nonatomic, assign, readonly) AGSExpirationType expirationType;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end



