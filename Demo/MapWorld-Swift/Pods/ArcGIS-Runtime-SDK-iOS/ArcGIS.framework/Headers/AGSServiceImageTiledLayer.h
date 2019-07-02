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

#import "AGSImageTiledLayer.h"
#import "AGSRemoteResource.h"

@class AGSTileKey;
@class AGSSpatialReference;
@class AGSRequestConfiguration;
@class AGSEnvelope;

/** @file AGSServiceImageTiledLayer.h */ //Required for Globals API doc

/** @brief A base class for service based tiled layers
 
 Subclasses represent layers which display pre-cached maps from tiled services.
 
 @since 100
 */
@interface AGSServiceImageTiledLayer : AGSImageTiledLayer <AGSRemoteResource>
NS_ASSUME_NONNULL_BEGIN

@end


/** @brief Category for implementing custom tiled layers based on remote services
 
 This category organizes the methods that are relevant to creating a custom tiled layer that provides tiles from a remote service or location.
 
 @since 100
 @see `AGSImageTiledLayer(CustomTiledLayer)` for creating custom tiled layers based on local tiles.
 */
@interface AGSServiceImageTiledLayer (CustomTiledLayer)

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
 */+(instancetype)serviceImageTiledLayerWithTiledInfo:(AGSTileInfo*)tileInfo fullExtent:(AGSEnvelope *)fullExtent;

#pragma mark -
#pragma mark properties

/** The handler that will be invoked when a new tile is needed. This should be assigned a block that contains the business logic specific to the custom layer for fetching the requested tile. The block should return a URL that can be used to fetch the remote data.
 @since 100
 */
@property (nullable, nonatomic, strong) NSURL*(^urlForTileKeyHandler)(AGSTileKey *tileKey);

NS_ASSUME_NONNULL_END
@end
