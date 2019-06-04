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

#import "AGSMarkerSymbol.h"

#import "AGSLoadable.h"
#import "AGSRemoteResource.h"

@class AGSSimpleLineSymbol;

/** @file AGSPictureMarkerSymbol.h */ //Required for Globals API doc

/** @brief A marker symbol based on an image
 
 Instances of this class represent picture marker symbols. Symbols describe how graphics and features
 look on a map. Different symbols are used with different geometry
 types.  Marker symbols are used to display those graphics and features which are based on
 point or multipoint geometries. Picture marker symbols display graphics using a picture image.
 
 @since 100
 */
@interface AGSPictureMarkerSymbol : AGSMarkerSymbol <AGSLoadable, AGSRemoteResource>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a picture marker symbol with the provided image
 @param image to use with the symbol
 @return Initialized picture marker symbol
 @since 100
 */
-(instancetype)initWithImage:(AGSImage*)image;

/** Initialize a picture marker symbol with the provided URL to an image
 @param URL to an image
 @return Initialized picture marker symbol
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize a picture marker symbol with the provided image
 @param image to use with the symbol
 @return Initialized picture marker symbol
 @since 100
 */
+(instancetype)pictureMarkerSymbolWithImage:(AGSImage*)image;

/** Initialize a picture marker symbol with the provided URL to an image
 @param URL to an image
 @return Initialized picture marker symbol
 @since 100
 */
+(instancetype)pictureMarkerSymbolWithURL:(NSURL*)URL;


#pragma mark -
#pragma mark properties

/** The image being used by the picture marker symbol. May be nil until `#loadStatus` is `AGSLoadStatusLoaded`
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSImage *image;

/** The height (in points, not pixels) of the symbol. Defaults to size of the image.
 @since 100
 */
@property (nonatomic, assign, readwrite) CGFloat height;

/** The width (in points, not pixels) of the symbol. Defaults to size of the image.
 @since 100
 */
@property (nonatomic, assign, readwrite) CGFloat width;

/** Opacity of the symbol. Defaults to 1 (fully opaque)
 Permitted values range between 0-1 (both inclusive)
 @since 100
 */
@property (nonatomic, assign, readwrite) float opacity;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end


