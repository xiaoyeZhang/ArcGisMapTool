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

@class AGSRaster;
@class AGSStretchParameters;

#import "AGSBaseStretchRenderer.h"

/** @file AGSRGBRenderer.h */ //Required for Globals API doc

/** @brief A RGB composite raster renderer
 
 Instances of this class represent a RGB composite stretch renderer that can help visualize raster data using `AGSRasterLayer`. 
 
 A RGB composite stretch renderer similar to `AGSStretchRenderer` but allows you to combine bands as red, green, blue composites. This renderer can be used for viewing color aerial photography, which is a three-band raster dataset, or to display different combinations of bands when working with multiband raster datasets, such as satellite or aerial imagery.
 
 @since 100
 */
@interface AGSRGBRenderer : AGSBaseStretchRenderer
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a RGB composite stretch renderer.
 @param stretchParameters The stretch parameters to use
 @param bandIndexes specifying which bands to use as Red, Green, and Blue.
 @param gammas An array of values in the range 0-2 to apply gamma correction for each band in the raster dataset. Gamma refers to the degree of contrast between the midlevel gray values of a raster dataset. Gamma does not affect the black or white values in a raster dataset, only the middle values. By applying a gamma correction, you can control the overall brightness of a raster dataset. Additionally, gamma changes not only the brightness but also the ratios of red to green to blue. Values lower than 1 decrease the contrast in the darker areas and increase the contrast in the lighter areas. This darkens the image without saturating the dark or light areas of the image. This helps bring out details in lighter features, such as building tops. Conversely, gamma values greater than 1 increase the contrast in darker areas, such as shadows from buildings. Gamma values greater than one can also help bring out details in lower elevation areas when working with elevation data.
 @param estimateStatistics indicating whether statistics should be estimated for raster datasets that don't contain statistical information about their pixel values
 @return Initialized RGB composite stretch renderer
 @since 100
 */
-(instancetype)initWithStretchParameters:(AGSStretchParameters*)stretchParameters
                             bandIndexes:(NSArray<NSNumber*>*)bandIndexes
                                  gammas:(NSArray<NSNumber*>*)gammas
                      estimateStatistics:(BOOL)estimateStatistics;



/** Initialize a RGB composite stretch renderer.
 @param stretchParameters The stretch parameters to use
 @param bandIndexes specifying which bands to use as Red, Green, and Blue.
 @param gammas An array of values in the range 0-2 to apply gamma correction for each band in the raster dataset. Gamma refers to the degree of contrast between the midlevel gray values of a raster dataset. Gamma does not affect the black or white values in a raster dataset, only the middle values. By applying a gamma correction, you can control the overall brightness of a raster dataset. Additionally, gamma changes not only the brightness but also the ratios of red to green to blue. Values lower than 1 decrease the contrast in the darker areas and increase the contrast in the lighter areas. This darkens the image without saturating the dark or light areas of the image. This helps bring out details in lighter features, such as building tops. Conversely, gamma values greater than 1 increase the contrast in darker areas, such as shadows from buildings. Gamma values greater than one can also help bring out details in lower elevation areas when working with elevation data.
 @param estimateStatistics indicating whether statistics should be estimated for raster datasets that don't contain statistical information about their pixel values
 @return Initialized RGB composite stretch renderer
 @since 100
 */
+(instancetype)RGBRendererWithStretchParameters:(AGSStretchParameters*)stretchParameters
                                    bandIndexes:(NSArray<NSNumber*>*)bandIndexes
                                         gammas:(NSArray<NSNumber*>*)gammas
                             estimateStatistics:(BOOL)estimateStatistics;

/** Initialize a RGB composite stretch renderer.
 @param stretchParameters The stretch parameters to use
 @param bandIndexes specifying which bands to use as Red, Green, and Blue.
 @param gammas An array of values in the range 0-2 to apply gamma correction for each band in the raster dataset. Gamma refers to the degree of contrast between the midlevel gray values of a raster dataset. Gamma does not affect the black or white values in a raster dataset, only the middle values. By applying a gamma correction, you can control the overall brightness of a raster dataset. Additionally, gamma changes not only the brightness but also the ratios of red to green to blue. Values lower than 1 decrease the contrast in the darker areas and increase the contrast in the lighter areas. This darkens the image without saturating the dark or light areas of the image. This helps bring out details in lighter features, such as building tops. Conversely, gamma values greater than 1 increase the contrast in darker areas, such as shadows from buildings. Gamma values greater than one can also help bring out details in lower elevation areas when working with elevation data.
 @param estimateStatistics indicating whether statistics should be estimated for raster datasets that don't contain statistical information about their pixel values
 @param pansharpenType specifying the type of panchromatic sharpening method to apply
 @param panchromaticRaster The high resolution raster used as the basis for pan-sharpening
 @param weights used by the pan-sharpening method
 @return Initialized RGB composite stretch renderer
 @since 100
 */
-(instancetype)initWithStretchParameters:(AGSStretchParameters*)stretchParameters
                             bandIndexes:(NSArray<NSNumber*>*)bandIndexes
                                  gammas:(NSArray<NSNumber*>*)gammas
                      estimateStatistics:(BOOL)estimateStatistics
                          pansharpenType:(AGSPansharpenType)pansharpenType
                      panchromaticRaster:(nullable AGSRaster*)panchromaticRaster
                                 weights:(nullable NSArray<NSNumber*>*)weights;

/** Initialize a RGB composite stretch renderer.
 @param stretchParameters The stretch parameters to use
 @param bandIndexes specifying which bands to use as Red, Green, and Blue.
 @param gammas An array of values in the range 0-2 to apply gamma correction for each band in the raster dataset. Gamma refers to the degree of contrast between the midlevel gray values of a raster dataset. Gamma does not affect the black or white values in a raster dataset, only the middle values. By applying a gamma correction, you can control the overall brightness of a raster dataset. Additionally, gamma changes not only the brightness but also the ratios of red to green to blue. Values lower than 1 decrease the contrast in the darker areas and increase the contrast in the lighter areas. This darkens the image without saturating the dark or light areas of the image. This helps bring out details in lighter features, such as building tops. Conversely, gamma values greater than 1 increase the contrast in darker areas, such as shadows from buildings. Gamma values greater than one can also help bring out details in lower elevation areas when working with elevation data.
 @param estimateStatistics indicating whether statistics should be estimated for raster datasets that don't contain statistical information about their pixel values
 @param pansharpenType specifying the type of panchromatic sharpening method to apply
 @param panchromaticRaster The high resolution raster used as the basis for pan-sharpening
 @param weights used by the pan-sharpening method
 @return Initialized RGB composite stretch renderer
 @since 100
 */
+(instancetype)RGBRendererWithStretchParameters:(AGSStretchParameters*)stretchParameters
                                    bandIndexes:(NSArray<NSNumber*>*)bandIndexes
                                         gammas:(NSArray<NSNumber*>*)gammas
                             estimateStatistics:(BOOL)estimateStatistics
                                 pansharpenType:(AGSPansharpenType)pansharpenType
                             panchromaticRaster:(nullable AGSRaster*)panchromaticRaster
                                        weights:(nullable NSArray<NSNumber*>*)weights;

#pragma mark -
#pragma mark properties

/** Indexes of bands of a multi-band raster dataset that the renderer is based on.
 The band specified by the 0th index is used as the Red band, 1st index as the Green band, and 2nd index as the Blue band.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber*> *bandIndexes;

/** The high-resolution panchromatic raster to use as a basis for panchoromatic sharpening.
 
 Pan-sharpening uses a higher-resolution panchromatic image (or raster band) to fuse with a lower-resolution multiband raster dataset. The result produces a multiband raster dataset with the resolution of the panchromatic raster where the two rasters fully overlap.
 
 @see http://desktop.arcgis.com/en/arcmap/latest/manage-data/raster-and-images/fundamentals-of-panchromatic-sharpening.htm
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSRaster *panchromaticRaster;

/** The type of panchromatic sharpening method to apply.

 @see http://desktop.arcgis.com/en/arcmap/latest/manage-data/raster-and-images/fundamentals-of-panchromatic-sharpening.htm
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPansharpenType pansharpenType;

/** The weights to use in the panchormatic sharpening method.
 
 Each of method uses different models to improve the spatial resolution while maintaining the color, and some are adjusted to include a weighting so that a fourth band can be included (such as the near-infrared band available in many multispectral image sources). By adding the weighting and enabling the infrared component, the visual quality in the output colors is improved.
 
 @see http://desktop.arcgis.com/en/arcmap/latest/manage-data/raster-and-images/fundamentals-of-panchromatic-sharpening.htm
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber*> *weights;

NS_ASSUME_NONNULL_END
@end
