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

#import "AGSBaseStretchRenderer.h"

@class AGSStretchParameters;
@class AGSColorRamp;

/** @file AGSStretchRenderer.h */ //Required for Globals API doc

/** @brief A stretch raster renderer
 
 Instances of this class represent a stretch renderer that can help visualize raster data using `AGSRasterLayer`.
 
 A stretch renderer displays continuous raster cell values across a gradual ramp of colors. Use it to draw a single band of continuous data. The stretch renderer works well when you have a large range of values to display, such as in imagery, aerial photographs, or elevation models.
 
 Stretching improves the appearance of the raster data by spreading its pixel values along a histogram whose minimum and maximum values are defined by the raster's bit depth. For example, an 8-bit raster dataset will be stretched along a histogram from 0 to 255.

 
 @since 100
*/
@interface AGSStretchRenderer : AGSBaseStretchRenderer
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a stretch renderer.
 @param stretchParameters The stretch parameters to use
 @param gammas An array of values in the range 0-2 to apply gamma correction for each band in the raster dataset. Gamma refers to the degree of contrast between the midlevel gray values of a raster dataset. Gamma does not affect the black or white values in a raster dataset, only the middle values. By applying a gamma correction, you can control the overall brightness of a raster dataset. Additionally, gamma changes not only the brightness but also the ratios of red to green to blue. Values lower than 1 decrease the contrast in the darker areas and increase the contrast in the lighter areas. This darkens the image without saturating the dark or light areas of the image. This helps bring out details in lighter features, such as building tops. Conversely, gamma values greater than 1 increase the contrast in darker areas, such as shadows from buildings. Gamma values greater than one can also help bring out details in lower elevation areas when working with elevation data.
 @param estimateStatistics indicating whether statistics should be estimated for raster datasets that don't contain statistical information about their pixel values
 @param colorRamp The color ramp to use
 @since 100
 @return Initialized stretch renderer
 */
-(instancetype)initWithStretchParameters:(AGSStretchParameters*)stretchParameters
                                  gammas:(NSArray<NSNumber*>*)gammas
                      estimateStatistics:(BOOL)estimateStatistics
                               colorRamp:(nullable AGSColorRamp*)colorRamp;

/** Initialize a stretch renderer.
 @param stretchParameters The stretch parameters to use
 @param gammas An array of values in the range 0-2 to apply gamma correction for each band in the raster dataset. Gamma refers to the degree of contrast between the midlevel gray values of a raster dataset. Gamma does not affect the black or white values in a raster dataset, only the middle values. By applying a gamma correction, you can control the overall brightness of a raster dataset. Additionally, gamma changes not only the brightness but also the ratios of red to green to blue. Values lower than 1 decrease the contrast in the darker areas and increase the contrast in the lighter areas. This darkens the image without saturating the dark or light areas of the image. This helps bring out details in lighter features, such as building tops. Conversely, gamma values greater than 1 increase the contrast in darker areas, such as shadows from buildings. Gamma values greater than one can also help bring out details in lower elevation areas when working with elevation data.
 @param estimateStatistics indicating whether statistics should be estimated for raster datasets that don't contain statistical information about their pixel values
 @param colorRamp The color ramp to use
 @since 100
 @return Initialized stretch renderer
 */
+(instancetype)stretchRendererWithStretchParameters:(AGSStretchParameters*)stretchParameters
                                             gammas:(NSArray<NSNumber*>*)gammas
                                 estimateStatistics:(BOOL)estimateStatistics
                                          colorRamp:(nullable AGSColorRamp*)colorRamp;

#pragma mark -
#pragma mark properties

NS_ASSUME_NONNULL_END
@end
