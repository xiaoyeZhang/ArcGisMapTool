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

/** @file AGSLicenseResult.h */ //Required for Globals API doc

/** @brief Result of setting a license
 
 Instances of this class represent the result of setting an application license through `AGSArcGISRuntimeEnvironment`
 
 @since 100
 */
@interface AGSLicenseResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));


#pragma mark -
#pragma mark properties

/** Status of application's extension licenses as a dictionary where the keys are the extension license name, and values are `AGSLicenseStatus`
 @since 100
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString*, NSNumber*> *extensionsStatus;

/** Status of application's license.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSLicenseStatus licenseStatus;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
