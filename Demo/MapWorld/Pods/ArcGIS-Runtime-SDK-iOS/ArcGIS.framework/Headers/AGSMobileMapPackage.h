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

#import "AGSLoadableBase.h"

@class AGSLocatorTask;
@class AGSMap;
@class AGSItem;

/** @file AGSMobileMapPackage.h */ //Required for Globals API doc

/** @brief A mobile map package
 
 Instances of this class represent a mobile map package (.mmpk file).
 
 A mobile map package can be created from ArcGIS Pro. It is a transport mechanism for mobile maps and scenes, their layers, and the layer's data. It contains metadata about the package (description, thumbnail, etc.), one or more mobile maps/scenes, layers, data and optionally networks and locators.
 
 @since 100
 @licenseExtn{StreetMap, when opening StreetMap Premium mobile map package}
 @ingroup licensing
 */
@interface AGSMobileMapPackage : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this object with the specified mobile map package (.mmpk file) on disk.
 @param fileURL to the mobile map package (.mmpk file) on disk.
 @return A new mobile map package object
 @since 100
 @licenseExtn{StreetMap, when opening StreetMap Premium mobile map package}
 @ingroup licensing
 */
-(instancetype)initWithFileURL:(NSURL *)fileURL;

/** Initialize this object with the name of a mobile map package (.mmpk file), excluding the ".mmpk" extension,
 within the application bundle or shared documents directory.
 @param name of the mobile map package (excluding the .mmpk extension)
 @return A new mobile map package object
 @since 100
 @licenseExtn{StreetMap, when opening StreetMap Premium mobile map package}
 @ingroup licensing
 */
-(instancetype)initWithName:(NSString *)name;

/** Initialize this object with the specified mobile map package (.mmpk file) on disk.
 @param fileURL to the mobile map package (.mmpk file) on disk.
 @return A new mobile map package object
 @since 100
 @licenseExtn{StreetMap, when opening StreetMap Premium mobile map package}
 @ingroup licensing
 */
+(instancetype)mobileMapPackageWithFileURL:(NSURL *)fileURL;

/** Initialize this object with the name of a mobile map package (.mmpk file), excluding the ".mmpk" extension,
 within the application bundle or shared documents directory.
 @param name of the mobile map package (excluding the .mmpk extension)
 @return A new mobile map package object
 @since 100
 @licenseExtn{StreetMap, when opening StreetMap Premium mobile map package}
 @ingroup licensing
 */
+(instancetype)mobileMapPackageWithName:(NSString *)name;

#pragma mark -
#pragma mark properties

/** Metadata associated with the mobile map package
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSItem *item;

/** The locator contained in the mobile map package
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLocatorTask *locatorTask;

/** The maps contained in the mobile map package
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSMap*> *maps;

/** The URL of the mobile map package (.mmpk file) on disk.
 @since 100
 */
@property (nonatomic, strong, readonly) NSURL *fileURL;

/** Version of the mobile map package
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *version;

#pragma mark -
#pragma mark methods

/** Checks if the mobile map package can be read directly. If the package contains data or functionality that can be only used after the package is unpacked (for instance, if it contains raster datasets), then this will return false. If package doesn't exist or it cannot be read, an error is returned. See `#unpackMobileMapPackageAtFileURL:outputDirectory:completion:` to unpack mmpk files that cannot be read directly.
 @param fileURL location to mmpk file
 @param completion block that is invoked with information about whether direct read is supported if the operation succeeds, or an error if it fails
 @return operation that can be canceled
 @since 100.2.1
 */
+(id<AGSCancelable>)checkDirectReadSupportForMobileMapPackageAtFileURL:(NSURL*)fileURL
                                                            completion:(void(^)(BOOL isDirectReadSupported, NSError * __nullable error))completion;
    
/** Unpacks a mobile map package file (.mmpk) to the specified directory. Only required if direct read is not supported for the package, for instance if it contains raster datasets. See `#checkDirectReadSupportForMobileMapPackageAtFileURL:completion:` for information on whether direct read is supported or not for your mobile map package. If it is not supported, you must first `unpack` the package before trying to `load` it, otherwise it will fail loading.
 @param fileURL location to mmpk file
 @param outputDirectory specifying where to unpack the package. If the last component of the directory location does not exist, it will be created during unpacking.
 @param completion block that is invoked when the operation completes.
 @return operation that can be canceled
 @since 100.2.1
 */
+(id<AGSCancelable>)unpackMobileMapPackageAtFileURL:(NSURL *)fileURL
                                    outputDirectory:(NSURL*)outputDirectory
                                         completion:(void(^)(NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END

@end

