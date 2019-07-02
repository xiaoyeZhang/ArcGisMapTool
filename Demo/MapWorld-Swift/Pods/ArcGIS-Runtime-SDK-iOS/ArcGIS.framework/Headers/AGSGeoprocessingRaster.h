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

#import "AGSGeoprocessingDataFile.h"

/** @file AGSGeoprocessingRaster.h */ //Required for Globals API doc

/** @brief A geoprocessing parameter for raster data
 
 Instances of this class represent a parameter for raster data that can be used as input to a geoprocessing job or returned as the result of the job.
 
 @since 100
 */
@interface AGSGeoprocessingRaster : AGSGeoprocessingDataFile
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)geoprocessingRaster;

/** Initialize this parameter with a reference to a local raster file
 @param inputFileURL URL to the location of the raster data file, for instance `file://mydir/lake.tif`
 @since 100.1
 */
-(instancetype)initWithInputFileURL:(NSURL*)inputFileURL;

/** Initialize this parameter with a reference to a remote raster file that has been uploaded to the service
 @param uploadID The upload ID of a raster uploaded to the geoprocessing service.
 @since 100.1
 */
-(instancetype)initWithUploadID:(NSString*)uploadID;

/** Initialize this parameter with a reference to a remote raster file
 @param URL to the location of the raster data file, for instance `http://myserver/lake.tif`
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize this parameter with a reference to a remote raster file
 @param URL to the location of the raster data file, for instance `http://myserver/lake.tif`
 @since 100
 */
+(instancetype)geoprocessingRasterWithURL:(NSURL*)URL;

/** Initialize this parameter with a reference to a remote raster file
 @param URL to the location of the raster data file, for instance `http://myserver/lake.tif`
 @param format of the raster data, such as "jpg", "tif", and so on.
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL format:(NSString*)format;

/** Initialize this parameter with a reference to a remote raster file
 @param URL to the location of the raster data file, for instance `http://myserver/lake.tif`
 @param format of the raster data, such as "jpg", "tif", and so on.
 @since 100
 */
+(instancetype)geoprocessingRasterWithURL:(NSURL*)URL format:(NSString*)format;

/** Initialize this parameter with a reference to a local raster file
 @param inputFileURL URL to the location of the raster data file, for instance `file://mydir/lake.tif`
 @since 100.1
 */
+(instancetype)geoprocessingRasterWithInputFileURL:(NSURL*)inputFileURL;

/** Initialize this parameter with a reference to a remote raster file that has been uploaded to the service
 @param uploadID The upload ID of a raster uploaded to the geoprocessing service.
 @since 100.1
 */
+(instancetype)geoprocessingRasterWithUploadID:(NSString*)uploadID;

#pragma mark -
#pragma mark properties

/** Format of the raster data, such as "jpg", "tif", and so on.
 @since 100
 */
 @property (nonatomic, copy, readwrite) NSString *format;

NS_ASSUME_NONNULL_END
@end
