/*
 COPYRIGHT 2019 ESRI
 
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

#import "AGSFillSymbolLayer.h"
#import "AGSLoadable.h"
#import "AGSRemoteResource.h"

/** @file AGSPictureFillSymbolLayer.h */ //Required for Globals API doc

/** @brief A class representing a picture fill symbol layer.
 
The class represents a polygon geometry filled with an image. This symbol layer, if it is the sole symbol layer in a `AGSMultilayerPolygonSymbol` fills the geometry associated with the symbol with the specified image. The image, should it not fill the geometry, will be tiled throughout the fill.
 
It is also used to represent the Web Scene specification's Icon3DSymbolLayers. IconSymbol3DLayers from Web Scene JSON as long as those Icon3DSymbolLayers contain pictures rather than primitives or vector paths, those symbol layers are represented as instances of `AGSPictureFillSymbolLayer`. If those Icon3DSymbolLayers are primitives or vector paths, they are represented as `AGSVectorMarkerSymbolLayer` objects.
 
It provides a similar user experience to the simple `AGSPictureFillSymbol`, but can be used in a `AGSMultilayerSymbol`.
 
 @since 100.5
 */
@interface AGSPictureFillSymbolLayer : AGSFillSymbolLayer <AGSLoadable, AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

/** Initialize a picture fill symbol layer with the provided image
 @param image to use with the symbol layer
 @return Initialized picture fill symbol layer
 @since 100.5
 */
-(instancetype)initWithImage:(AGSImage *)image;

/** Initialize a picture fill symbol layer with the provided URL to an image
 @param URL to an image
 @return Initialized picture fill symbol layer
 @since 100.5
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize a picture fill symbol layer with the provided image
 @param image to use with the symbol layer
 @return Initialized picture fill symbol layer
 @since 100.5
 */
+(instancetype)pictureFillSymbolLayerWithImage:(AGSImage *)image;

/** Initialize a picture fill symbol layer with the provided URL to an image
 @param URL to an image
 @return Initialized picture fill symbol layer
 @since 100.5
 */
+(instancetype)pictureFillSymbolLayerWithURL:(NSURL*)URL;

#pragma mark -
#pragma mark properties

/** The image being used by the picture fill symbol layer. May be nil until `#loadStatus` is `AGSLoadStatusLoaded`
 @since 100.5
 */
@property (nullable, nonatomic, strong, readonly) AGSImage *image;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end




