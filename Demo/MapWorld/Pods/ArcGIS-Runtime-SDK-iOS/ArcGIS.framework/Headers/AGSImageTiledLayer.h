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

#import "AGSImageAdjustmentLayer.h"
@class AGSTileInfo;
@class AGSTileKey;

/** @file AGSImageTiledLayer.h */ //Required for Globals API doc

/** @brief A base class for tiled layers
 
 Subclasses represent layers which display pre-cached maps from tiled sources (either local data or remote services).
 
 @since 100
 */
@interface AGSImageTiledLayer : AGSImageAdjustmentLayer
NS_ASSUME_NONNULL_BEGIN

/** Attribution information of the layer
 @since 100
 */
 @property (nonatomic, copy, readwrite) NSString *attribution;

/** Tiling scheme for the layer.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSTileInfo * tileInfo;

/** The behavior of no data tile.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSNoDataTileBehavior noDataTileBehavior;

@end


/** @brief Category for implementing custom tiled layers
 
 This category organizes the methods that are relevant to creating a custom tiled layer. The custom layer can work with local tiled data or remote tiled services depending upon how it is implemented.
 
 @since 100
 @see `AGSServiceImageTiledLayer(CustomTiledLayer)` for creating custom tiled layers based on remote tiles.
 */
@interface AGSImageTiledLayer (CustomImageTiledLayer)

#pragma mark -
#pragma mark initializers

/** Initialize the custom tiled layer with the provided details
 @param tileInfo specifying the tiling scheme used by the layer
 @param fullExtent of the layer
 @return Initialized tiled layer
 @since 100
 */
-(instancetype)initWithTileInfo:(AGSTileInfo*)tileInfo fullExtent:(AGSEnvelope *)fullExtent;

/** Initialize the custom tiled layer with the provided details
 @param tileInfo specifying the tiling scheme used by the layer
 @param fullExtent of the layer
 @return Initialized tiled layer
 @since 100
 */
+(instancetype)imageTiledLayerWithTileInfo:(AGSTileInfo*)tileInfo fullExtent:(AGSEnvelope *)fullExtent;

#pragma mark -
#pragma mark properties

/** The handler that will be invoked when a new tile is needed. This should be assigned a block that contains the business logic specific to the custom layer for fetching the requested tile. The block should eventually invoke `#respondWithTileKey:data:error:` if a tile is retrieved or an error is encountered. Alternatively, it can invoke `#respondWithNoDataTileForTileKey` if no tile is available.
 @since 100
 */
@property (nullable, nonatomic, strong) void (^tileRequestHandler)(AGSTileKey *tileKey);

/** The handler that will be invoked when a requested tile is no longer needed. This should be assigned a block that contains the business logic specific to the custom layer for canceling the requested tile.
 @since 100
 */
@property (nullable, nonatomic, strong) void (^cancelTileRequestHandler)(AGSTileKey *tileKey);

#pragma mark -
#pragma mark methods

/** Needs to be invoked when the custom layer has successfully retrieved the tile requested in `#tileRequestHandler`, or if an error is encountered while retrieving the tile.
 @param tileKey specifying the tile that was requested
 @param data for the retrieved tile if the operation was successful
 @param error encountered while retrieving the tile if the operation failed
 @since 100
 */
-(void)respondWithTileKey:(AGSTileKey*)tileKey
                     data:(nullable NSData*)data
                    error:(nullable NSError*)error;

/** Needs to be invoked when the custom layer does not find a tile.
 @param tileKey specifying the tile that was requested
 @since 100
 */
-(void)respondWithNoDataTileForTileKey:(AGSTileKey*)tileKey;

@end

NS_ASSUME_NONNULL_END

