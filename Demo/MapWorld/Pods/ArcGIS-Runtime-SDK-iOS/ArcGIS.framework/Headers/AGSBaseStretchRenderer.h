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

@class AGSStretchParameters;

/** @file AGSBaseStretchRenderer.h */ //Required for Globals API doc

/** @brief A base class for stretch raster renderers
 
 A base class for stretch renderers that can help visualize raster data using `AGSRasterLayer`. 
 
 Stretching improves the appearance of the raster data by spreading its pixel values along a histogram whose minimum and maximum values are defined by the raster's bit depth. For example, an 8-bit raster dataset will be stretched along a histogram from 0 to 255.

 
 @since 100
 */
@interface AGSBaseStretchRenderer : AGSRasterRenderer
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init;
+(instancetype)baseStretchRenderer;

#pragma mark -
#pragma mark properties

/** 
 An array of values in the range 0-2 to apply gamma correction for each band in the raster dataset. Gamma refers to the degree of contrast between the midlevel gray values of a raster dataset. Gamma does not affect the black or white values in a raster dataset, only the middle values. By applying a gamma correction, you can control the overall brightness of a raster dataset. Additionally, gamma changes not only the brightness but also the ratios of red to green to blue. Values lower than 1 decrease the contrast in the darker areas and increase the contrast in the lighter areas. This darkens the image without saturating the dark or light areas of the image. This helps bring out details in lighter features, such as building tops. Conversely, gamma values greater than 1 increase the contrast in darker areas, such as shadows from buildings. Gamma values greater than one can also help bring out details in lower elevation areas when working with elevation data.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber*> *gammas;

/** Indicates whether statistics should be estimated for the raster dataset. This is typically needed for datasets that do not have statistics.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL estimateStatistics;

/** The stretch parameters used for the renderer.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSStretchParameters *stretchParameters;

NS_ASSUME_NONNULL_END
@end
