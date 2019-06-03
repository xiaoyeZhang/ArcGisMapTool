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

#import "AGSFillSymbol.h"

#import "AGSLoadable.h"
#import "AGSRemoteResource.h"

@interface AGSPictureFillSymbol : AGSFillSymbol <AGSLoadable, AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a picture fill symbol with the provided image
 @param image to use with the symbol
 @return Initialized picture fill symbol
 @since 100
 */
-(instancetype)initWithImage:(AGSImage*)image;

/** Initialize a picture fill symbol with the provided URL to an image
 @param URL to an image
 @return Initialized picture fill symbol
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize a picture fill symbol with the provided image
 @param image to use with the symbol
 @return Initialized picture fill symbol
 @since 100
 */
+(instancetype)pictureFillSymbolWithImage:(AGSImage*)image;

/** Initialize a picture fill symbol with the provided URL to an image
 @param URL to an image
 @return Initialized picture fill symbol
 @since 100
 */
+(instancetype)pictureFillSymbolWithURL:(NSURL*)URL;

#pragma mark -
#pragma mark properties

/** The image being used by the picture fill symbol. May be nil until `#loadStatus` is `AGSLoadStatusLoaded`
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

@property (nonatomic, assign, readwrite) double angle;
@property (nonatomic, assign, readwrite) double scaleX;
@property (nonatomic, assign, readwrite) double scaleY;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

