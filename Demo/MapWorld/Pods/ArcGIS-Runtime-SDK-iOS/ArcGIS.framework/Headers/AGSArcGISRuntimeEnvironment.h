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

@class AGSLicense;
@class AGSLicenseInfo;
@class AGSLicenseResult;

/** @file AGSArcGISRuntimeEnvironment.h */ //Required for Globals API doc

#pragma mark -

/** @brief Class representing the ArcGIS Runtime Environment.
 
 A class representing the ArcGIS Runtime Environment.

 @since 100
 */
@interface AGSArcGISRuntimeEnvironment : NSObject
NS_ASSUME_NONNULL_BEGIN

/** Returns the current license details about the application.
 @since 100
 */
+(AGSLicense*)license;

/** License the application for deployment using an ESRI license key. 
 
 ArcGIS Runtime must be licensed to be used in a production application. The application can be licensed at any one of the four levels; Lite, Basic, Standard, and Advanced; where each level enables additional capabilities fundamental to ArcGIS Runtime. Extension licenses are optional and provide access to supplementary capabilities, analysis tools, and data. By default, an ArcGIS Runtime application will run under a developer license (mode) where all licensed capabilities are available.
 @param licenseKey to use
 @param error that is popuplated if there was an error in using the license key
 @return Result of the operation
 @since 100
 */
+(nullable AGSLicenseResult*)setLicenseKey:(NSString *)licenseKey error:(NSError**)error;

/** License the application for deployment using a license info for named-user access. A license info instance can be obtained from a portal for the current logged in user. The license info instance is only valid for 30 days so the user will be required to log into the portal again when this expires.
 
 ArcGIS Runtime must be licensed to be used in a production application. The application can be licensed at any one of the four levels; Lite, Basic, Standard, and Advanced; where each level enables additional capabilities fundamental to ArcGIS Runtime. Extension licenses are optional and provide access to supplementary capabilities, analysis tools, and data. By default, an ArcGIS Runtime application will run under a developer license (mode) where all licensed capabilities are available.
 @param licenseInfo to use
 @param error that is popuplated if there was an error in using the license key
 @return Result of the operation
 @since 100
 */
+(nullable AGSLicenseResult*)setLicenseInfo:(AGSLicenseInfo *)licenseInfo error:(NSError**)error;

/** License the application for deployment using an ESRI license key and one or more extension license keys.
 
 ArcGIS Runtime must be licensed to be used in a production application. The application can be licensed at any one of the four levels; Lite, Basic, Standard, and Advanced; where each level enables additional capabilities fundamental to ArcGIS Runtime. Extension licenses are optional and provide access to supplementary capabilities, analysis tools, and data. By default, an ArcGIS Runtime application will run under a developer license (mode) where all licensed capabilities are available.
 @param licenseKey to use
 @param extensions A list of extension licenses to apply
 @param error that is popuplated if there was an error in using the license key
 @return Result of the operation
 @since 100
 */
+(nullable AGSLicenseResult*)setLicenseKey:(NSString *)licenseKey extensions:(NSArray<NSString*> *)extensions error:(NSError**)error;

NS_ASSUME_NONNULL_END
@end
