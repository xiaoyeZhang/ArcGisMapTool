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

#import "AGSMarkerSymbolLayer.h"
#import "AGSLoadable.h"
#import "AGSRemoteResource.h"

/** @file AGSPictureMarkerSymbolLayer.h */ //Required for Globals API doc

/** @brief A class representing a symbol layer that's used to place a picture marker on a point geometry
 
 This symbol layer in a `AGSMultilayerPointSymbol` places a picture marker at the location of the point feature. The class supports changing dimensions of the marker, specifying the image (or URL linking to the image) to use as the marker, as well as the general marker options provided by the `AGSMarkerSymbolLayer` base class.
 
 This symbol layer is similar to the Web Scene specification's IconSymbol3DLayer, when the IconSymbol3DLayer references an image. It is also similar to the Web Map specification's `AGSPictureMarkerSymbol`. As a symbol layer, `AGSPictureMarkerSymbolLayer` can be combined with other symbol layers in a `AGSMultilayerSymbol`, whereas `AGSPictureMarkerSymbol` cannot.
 
 @since 100.5
 */

@interface AGSPictureMarkerSymbolLayer : AGSMarkerSymbolLayer <AGSLoadable, AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

/** Initialize a picture marker symbol layer with the provided image
 @param image to use with the symbol layer
 @return Initialized picture marker symbol layer
 @since 100.5
 */
-(instancetype)initWithImage:(AGSImage*)image;

/** Initialize a picture marker symbol layer with the provided URL to an image
 @param URL to an image
 @return Initialized picture marker symbol layer
 @since 100.5
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize a picture marker symbol layer with the provided image
 @param image to use with the symbol layer
 @return Initialized picture marker symbol layer
 @since 100.5
 */
+(instancetype)pictureMarkerSymbolLayerWithImage:(AGSImage*)image;

/** Initialize a picture marker symbol layer with the provided URL to an image
 @param URL to an image
 @return Initialized picture marker symbol layer
 @since 100.5
 */
+(instancetype)pictureMarkerSymbolLayerWithURL:(NSURL*)URL;

#pragma mark -
#pragma mark properties

/** The image being used by the picture marker symbol layer. May be nil until `#loadStatus` is `AGSLoadStatusLoaded`
 @since 100.5
 */
@property (nullable, nonatomic, strong, readonly) AGSImage *image;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

