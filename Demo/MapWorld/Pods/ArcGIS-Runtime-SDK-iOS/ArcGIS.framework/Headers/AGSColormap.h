/*
 COPYRIGHT 2016 ESRI
 
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

/** @file AGSColormap.h */ //Required for Globals API doc

/** @brief A colormap to display raster data as either a grayscale or color image.
 
 An instance of this class represents a colormap to display raster data as either a grayscale or color image.
 
 Colormaps help to associate a pixel value with a corresponding color. The pixel value is specified by the index of the color in the colormap. So, a color at index 0 in the colormap will be used to paint all the pixels that have a value of 0 in the raster.
 
 @since 100
 @see `AGSColormapRenderer`
 */
@interface AGSColormap : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Intialize the colormap with the specified colors
 @param colors that are part of the colormap. The color at the 0th index is used for raster pixels that have a value of 0, color at 1st index for value 1, and so on. 
 @since 100
 */
-(instancetype)initWithColors:(NSArray<AGSColor*>*)colors;

/** Intialize the colormap with the specified colors
 @param colors that are part of the colormap. The color at the 0th index is used for raster pixels that have a value of 0, color at 1st index for value 1, and so on.
 @since 100
 */
+(instancetype)colormapWithColors:(NSArray<AGSColor*>*)colors;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
