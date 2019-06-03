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

#import "AGSObject.h"

@class AGSEnvelope;
@class AGSSpatialReference;
@class AGSWMTSTileMatrix;

/** @file AGSWMTSTileMatrixSet.h */ //Required for Globals API doc

/** @brief An OGC-WMTS service tile matrix set
 
 Instances of this class represent a tile matrix set in an OGC-WMTS map service, for example, http://v2.suite.opengeo.org/geoserver/gwc/service/wmts .
 
 A tile matrix set defines the geometry of the tiled space.  Each tile matrix set contains one
 or more "tile matrices" defining the tiles that are available for that coordinate reference
 system. The tile matrix set specifies : 
 
 * The scale of the tiles as a scale denominator.
 * The width and height of each tile in pixels
 * The top left (minimum x, maximum y) corner of the bounding box of the tile matrix
 * The width and height of the tile matrix in tile units (i.e., number of tiles)
 
 @since 100.1
 */
@interface AGSWMTSTileMatrixSet : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Description of the tile matrix set
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *tileMatrixSetDescription;

/** Geographic area covered by the tile matrix set
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *extent;

/** Unique identifier of the tile matrix set in the service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *tileMatrixSetID;

/** Keywords describing the tile matrix set
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *keywords;

/** Spatial reference in which the tiles were generated for this tile matrix set
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** Collection of individual tile matrices contained in this tile matrix set. 
 An individual tile matrix specifies which tiles are available.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSWMTSTileMatrix*> *tileMatrices;

/** Title of the tile matrix set
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *title;

/** Identifier of a well-known scale set used by this tile matrix set.
 A well-known scale set is a well-known combination of a coordinate reference system
 and a set of scales that a tile matrix set declares support for.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *wellKnownScaleSetID;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
