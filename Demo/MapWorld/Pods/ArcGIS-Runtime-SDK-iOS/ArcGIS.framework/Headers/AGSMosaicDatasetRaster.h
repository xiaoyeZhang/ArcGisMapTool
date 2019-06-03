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

#import "AGSRaster.h"

@class AGSAddRastersParameters;
@class AGSGeodatabase;

/** @file AGSMosaicDatasetRaster.h */ //Required for Globals API doc

/** @brief A mosaic dataset raster
 
 An instance of this class represents a mosaic dataset raster. A mosaic dataset allows you to store, manage, view, and query collections of raster and image data. It is a data model within the geodatabase used to manage a collection of raster datasets (images) stored as a catalog and viewed as a mosaicked image. Mosaic datasets have advanced raster querying capabilities and processing functions.
 
 A mosaic dataset is created in a geodatabase and can have raster datasets added to it directly. The raster data in a mosaic dataset does not have to be adjoining or overlapping but can exist as unconnected, discontinuous datasets. For example, you can have images that completely cover an area or you can have many strips of images that may not join together to form a continuous image (such as along pipelines).
 
 
 A mosaic dataset raster can be displayed on screen in a 2D map or a 3D scene using an `AGSRasterLayer`.
 
 @since 100
 @license{Standard}
 @ingroup licensing
*/
@interface AGSMosaicDatasetRaster : AGSRaster

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a mosaic dataset raster using the provided details
 @param fileURL to the geodatabase containing the mosaic dataset
 @param name of the mosaic dataset within the geodatabase
 @since 100
 @return Initialized mosaic dataset raster
 */
-(instancetype)initWithFileURL:(NSURL *)fileURL
                          name:(NSString *)name;

/** Initialize a mosaic dataset raster using the provided details
 @param fileURL to the geodatabase containing the mosaic dataset
 @param name of the mosaic dataset within the geodatabase
 @since 100
 @return Initialized mosaic dataset raster
 */
+(instancetype)mosaicDatasetRasterWithFileURL:(NSURL *)fileURL
                                         name:(NSString *)name;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

/** Create a new mosaic dataset raster 
 @param fileURL to the geodatabase in which the new mosaic dataset raster needs to be created
 @param name of the new mosaic dataset raster to be created
 @param spatialReference of the new mosaic dataset raster to be created
 @since 100
 */
+(AGSMosaicDatasetRaster *)createMosaicDatasetRasterWithDatabaseAtFileURL:(NSURL *)fileURL
                                                                     name:(NSString *)name
                                                         spatialReference:(AGSSpatialReference *)spatialReference;

/** Create a new mosaic dataset raster
 @param geodatabase in which the new mosaic dataset raster needs to be created
 @param name of the new mosaic dataset raster to be created
 @param spatialReference of the new mosaic dataset raster to be created
 @since 100
 */
+(AGSMosaicDatasetRaster *)createMosaicDatasetRasterWithGeodatabase:(AGSGeodatabase *)geodatabase
                                                               name:(NSString *)name
                                                   spatialReference:(AGSSpatialReference *)spatialReference;

/** Add individual rasters to the mosaic dataset raster
 @param parameters specifiying which rasters to add
 @param completion block that is invoked when the operation completes. The error is populated only if the operation fails. 
 @since 100
 */
-(id<AGSCancelable>)addRasters:(AGSAddRastersParameters *)parameters
                     completion:(nullable void(^)(NSError *__nullable error))completion;

/** Returns a list of mosaic dataset rasters in the given geodatabase
 @param fileURL to the geodatabase 
 @return list of mosaic dataset raster names within the geodatabase
 @since 100
 */
+(NSArray<NSString*> *)mosaicDatasetRasterNamesFromDatabaseAtFileURL:(NSURL *)fileURL;

/** Remove the specified mosaic dataset raster from the geodatabase
 @param name of the mosaic dataset raster to remove
 @param geodatabase from which to remove the mosaic dataset raster
 @since 100
 */
+(void)removeMosaicDatasetRasterWithName:(NSString *)name fromGeodatabase:(AGSGeodatabase *)geodatabase;

NS_ASSUME_NONNULL_END

@end

