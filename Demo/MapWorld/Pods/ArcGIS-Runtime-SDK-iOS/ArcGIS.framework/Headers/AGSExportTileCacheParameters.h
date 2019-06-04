/*
 COPYRIGHT 2015 ESRI
 
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

@class AGSGeometry;
@class AGSLevelOfDetail;

/** @file AGSExportTileCacheParameters.h */ //Required for Globals API doc

/** @brief Parameters for the operations on `AGSExportTileCacheTask`
 
 Instances of this class represent input parameters of operations on `AGSExportTileCacheTask` to get a size estimate of and export a tile cache.
 
 @since 100
 @see `AGSExportTileCacheTask`
 */
@interface AGSExportTileCacheParameters : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)tileCacheParameters;

#pragma mark -
#pragma mark properties

/**
 An `AGSPolygon` or `AGSEnvelope` geometry that defines the geographic area for which tiles are needed.
 `AGSPoint` and `AGSPolyline` geometries are not supported. If this is not specified, the full extent of the service will be used.
 @since 100
 */
@property (nullable, nonatomic, copy, readwrite) AGSGeometry *areaOfInterest;

/** The quality that must be maintained while compressing the tiles. A value in the range 0-100. Defaults to -1 which preserves the compression quality specified on the service.
 
 The value cannot be greater than the default compression quality already set on the service. For example, if the default value is 75, the value provided must be between 0 and 75. A value greater than 75 in this example will attempt to up sample an already compressed tile and will further degrade the quality of tiles.
 
 Providing a value smaller than the default set on the service will result in greater compression being applied to the tiles to reduce size, but may also degrade quality.
 @since 100
 */
@property (nonatomic, assign, readwrite) float compressionQuality;

/** The levels of detail that should be included in the tile cache. The values should correspond to Level IDs in the service's tiling scheme. You can specify consecutive levels (for example 1,2,3,4,5) or skip some levels (for example for the ranges 1-3 and 7-9 you would specify 1,2,3,7,8,9).
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSNumber*> *levelIDs;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
