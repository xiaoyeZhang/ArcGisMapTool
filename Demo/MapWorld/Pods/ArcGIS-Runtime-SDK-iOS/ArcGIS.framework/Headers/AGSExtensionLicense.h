/*
 COPYRIGHT 2016 ESRI
 
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

/** @file AGSExtensionLicense.h */ //Required for Globals API doc

/** @brief The application's extension license details
 
 Instances of this class represent the current state of the application's extension license.
 
 @since 100
 */
@interface AGSExtensionLicense : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The date this extension license will expire.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *expiry;

/** Whether or not the extension license is permanent.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isPermanent) BOOL permanent;

/** Current status of this extension license.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSLicenseStatus licenseStatus;

/** Name of this extension license. This is the name embedded in the license key.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
