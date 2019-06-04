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

#import "AGSRasterRenderer.h"

@class AGSColormap;

/** @file AGSColormapRenderer.h */ //Required for Globals API doc

/** @brief A colormap raster renderer
 
 Instances of this class represent a color map renderer that can help visualize raster data using `AGSRasterLayer`. It displays each pixel value in the raster using a color from the color map. Color maps contain a set of values that are associated with colors and are used to display a single-band raster consistently with the same colors. Each pixel value is associated with a color. You can use a color map to represent analyzed data, such as a classified image, or when displaying a topographic map (or index color-scanned image).
 
 
 @since 100
 */
@interface AGSColormapRenderer : AGSRasterRenderer
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a colormap renderer based on the provided colors
 @param colors to use. The color at the 0th index is used for raster pixels that have a value of 0, color at 1st index for value 1, and so on.
 @return Initialized colormap renderer
 @since 100
 */
-(instancetype)initWithColors:(NSArray<AGSColor*>*)colors;

/** Initialize a colormap renderer based on the provided colors
 @param colors to use. The color at the 0th index is used for raster pixels that have a value of 0, color at 1st index for value 1, and so on.
 @return Initialized colormap renderer
 @since 100
 */
+(instancetype)colormapRendererWithColors:(NSArray<AGSColor*>*)colors;

/** Initialize a colormap renderer based on the provided colormap
 @param colormap to use. 
 @return Initialized colormap renderer
 @since 100
 */
-(instancetype)initWithColormap:(AGSColormap*)colormap;

/** Initialize a colormap renderer based on the provided colormap
 @param colormap to use.
 @return Initialized colormap renderer
 @since 100
 */
+(instancetype)colormapRendererWithColormap:(AGSColormap*)colormap;

#pragma mark -
#pragma mark properties

/** The colormap used to create renderer.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSColormap *colormap;

NS_ASSUME_NONNULL_END
@end
