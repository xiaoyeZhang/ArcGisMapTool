/*
 COPYRIGHT 2018 ESRI
 
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
@class AGSScene;
@class AGSItem;
@class AGSExpiration;

/** @file AGSMobileScenePackage.h */ //Required for Globals API doc

/** @brief A mobile scene package
 
 Instances of this class represent a mobile scene package (.mspk file).
 
 A mobile scene package can be created from ArcGIS Pro. It is a transport mechanism for scenes,
    their layers, and the layer's data. It contains metadata about the package (description,
    thumbnail, etc.), one or more mobile scenes, layers, data, and optionally locators.
 
 @since 100.5
 */

@interface AGSMobileScenePackage : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

/** Initialize this object with the specified mobile scene package (.mspk file) on disk.
 @param fileURL to the mobile scene package (.mspk file) on disk.
 @return A new mobile scene package object
 @since 100.5
 */
-(instancetype)initWithFileURL:(NSURL *)fileURL;

/** Initialize this object with the name of a mobile scene package (.mspk file),
    excluding the ".mspk" extension, within the application bundle or shared documents directory.
 @param name of the mobile scene package (excluding the .mspk extension)
 @return A new mobile scene package object
 @since 100.5
 */
-(instancetype)initWithName:(NSString *)name;

/** Initialize this object with the specified mobile scene package (.mspk file) on disk.
 @param fileURL to the mobile scene package (.mspk file) on disk.
 @return A new mobile scene package object
 @since 100.5
 */
+(instancetype)mobileScenePackageWithFileURL:(NSURL *)fileURL;

/** Initialize this object with the name of a mobile scene package (.mspk file),
    excluding the ".mspk" extension, within the application bundle or shared documents directory.
 @param name of the mobile scene package (excluding the .mspk extension)
 @return A new mobile scene package object
 @since 100.5
 */
+(instancetype)mobileScenePackageWithName:(NSString *)name;

#pragma mark -
#pragma mark properties

/** Metadata associated with the mobile scene package
 @since 100.5
 */
@property (nullable, nonatomic, strong, readonly) AGSItem *item;

/** The locator contained in the mobile scene package
 @since 100.5
 */
@property (nullable, nonatomic, strong, readonly) AGSLocatorTask *locatorTask;

/** The URL of the mobile scene package (.mspk file) on disk.
 @since 100.5
 */
@property (nonatomic, strong, readonly) NSURL *fileURL;

/** The scenes contained in the mobile scene package
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSArray<AGSScene*> *scenes;

/** Version of the mobile scene package
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSString *version;

/** Expiration details for this mobile map package, if provided. If the package has expired and was authored as `ExpirationTypePreventExpiredAccess`, then it will fail to load and can no longer be used.
 @since 100.5
 */
@property (nullable, nonatomic, strong, readonly) AGSExpiration *expiration;

#pragma mark -
#pragma mark methods

/** Checks if the mobile scene package can be read directly. If the package contains data or
    functionality that can be only used after the package is unpacked (for instance, if it
    contains raster datasets), then this will return false. If package doesn't exist or it
    cannot be read, an error is returned. See `#unpackMobileScenePackageAtFileURL:outputDirectory:completion:`
    to unpack mspk files that cannot be read directly.
 @param fileURL location to .mspk file
 @param completion block that is invoked with information about whether direct read is supported if the operation succeeds, or an error if it fails
 @return operation that can be canceled
 @since 100.5
 */
+(id<AGSCancelable>)checkDirectReadSupportForMobileScenePackageAtFileURL:(NSURL*)fileURL
                                                            completion:(void(^)(BOOL isDirectReadSupported, NSError * __nullable error))completion;

/** Unpacks a mobile scene package file (.mspk) to the specified directory. Only required if
    direct read is not supported for the package, for instance if it contains raster datasets.
    See `#checkDirectReadSupportForMobileScenePackageAtFileURL:completion:` for information on
    whether direct read is supported or not for your mobile scene package. If it is not supported,
    you must first `unpack` the package before trying to `load` it, otherwise it will fail loading.
 @param fileURL location to .mspk file
 @param outputDirectory specifying where to unpack the package. If the last component of the directory
        location does not exist, it will be created during unpacking.
 @param completion block that is invoked when the operation completes.
 @return operation that can be canceled
 @since 100.5
 */
+(id<AGSCancelable>)unpackMobileScenePackageAtFileURL:(NSURL *)fileURL
                                    outputDirectory:(NSURL*)outputDirectory
                                         completion:(void(^)(NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END

@end

