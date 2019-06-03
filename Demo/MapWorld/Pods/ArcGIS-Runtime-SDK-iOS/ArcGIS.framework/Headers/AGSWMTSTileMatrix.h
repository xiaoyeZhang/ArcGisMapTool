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

/** @file AGSWMTSTileMatrix.h */ //Required for Globals API doc

/** @brief An OGC-WMTS service tile matrix
 
 Instances of this class represent an individual tile matrix in an OGC-WMTS service tile matrix set.
 
 The tile matrix specifies which tiles are available for a particular scale. Each tile in a tile matrix is identified by its TileCol and TileRow indices that have their 0,0 origin in the tile next to the top left corner of the tile matrix and that increases towards the right and towards the bottom respectively.
 
 @since 100.1
 */
 @interface AGSWMTSTileMatrix : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Unique identifier of the tile matrix in the service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *matrixID;


/** The scale for which this tile matrix contains tiles
 @since 100.1
 */
@property (nonatomic, assign, readonly) double scaleDenominator;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
