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

@class AGSPortalInfo;

#import "AGSObject.h"

@class AGSExtensionLicense;

/** @file AGSLicense.h */ //Required for Globals API doc

#pragma mark -

/** @brief The application's license details
 
 Instances of this class represent the current state of the application's license as returned by `AGSRuntimeEnvironment#license`.
 
 @since 100
 */
@interface AGSLicense : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark
#pragma mark properties

/** The date the application's license will expire.
 @since 100
 */
@property (nonatomic, strong, readonly, nullable) NSDate *expiry;

/** Details about the application's extension licenses.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSExtensionLicense*> *extensions;

/** The level at which the application is currently licensed.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSLicenseLevel licenseLevel;

/** Current status of the application's license.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSLicenseStatus licenseStatus;

/** Type of license currently being used by the application.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSLicenseType licenseType;

#pragma mark
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
