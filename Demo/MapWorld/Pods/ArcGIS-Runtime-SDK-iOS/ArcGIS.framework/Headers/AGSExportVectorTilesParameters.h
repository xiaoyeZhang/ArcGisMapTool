/*
 COPYRIGHT 2017 ESRI
 
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

@class AGSGeometry;

/** @file AGSExportVectorTilesParameters.h */ //Required for Globals API doc

/** @brief Parameters for the operations on `AGSExportVectorTilesTask`
 
 Instances of this class represent input parameters of operations on `AGSExportVectorTilesTask` to export a vector tile cache.
 
 @since 100.2
 @see `AGSExportVectorTilesTask`
 */
@interface AGSExportVectorTilesParameters : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)exportVectorTilesParameters;

#pragma mark -
#pragma mark properties

/**
 An `AGSPolygon` or `AGSEnvelope` geometry that defines the geographic area for which tiles are needed.
 `AGSPoint` and `AGSPolyline` geometries are not supported. If this is not specified, the full extent of the service will be used.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readwrite) AGSGeometry *areaOfInterest;

/** The maximum level of detail to export vector tiles.  The vector tile export will always take levels 0 and all in between levels up to and including the value of max level. The larger the level the more tiles will be included. The default value is -1, which must be set to a valid value >= 0.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) NSInteger maxLevel;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
