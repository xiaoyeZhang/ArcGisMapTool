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
@class AGSColorRamp;

#import "AGSHillshadeRenderer.h"

/** @file AGSBlendRenderer.h */ //Required for Globals API doc

/** @brief A blend renderer for elevation raster data
 
 An instance of this class represents a blend renderer that can be used to visualize elevation raster data.
 The renderer allows a hillshade to be computed and blended with the original raster. This provides a look similar to the original raster, but with some terrain shading, giving it a rich, textured look.
 
 @since 100
*/
@interface AGSBlendRenderer : AGSHillshadeRenderer
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a blend raster renderer with the provided parameters
 @param elevationRaster containing the elevation data
 @param outputMinValues Min output stretch values, one for each band in the raster
 @param outputMaxValues Max output stretch values, one for each band in the raster
 @param sourceMinValues Min input stretch values, one for each band in the raster
 @param sourceMaxValues Max input stretch values, one for each band in the raster
 @param noDataValues NoData values, one for each band in the raster
 @param gammas Gamma adjustment for each band in the raster
 @param colorRamp The spectrum of colors to use
 @param altitude Sun's angle of elevation above the horizon ranging from 0 to 90 degrees.
 @param azimuth Sun's relative position along the horizon ranging from 0 to 360 degrees.
 @param zFactor Scaling factor used to convert the elevation values to horizontal coordinate units. For default, use 1.
 @param slopeType specifying how inclination of the slope is calculated.
 @param pixelSizeFactor to account for altitude changes (scale) as the viewer zooms in and out. For default, use 1.
 @param pixelSizePower to account for altitude changes (scale) as the viewer zooms in and out.  For default, use 1.
 @param outputBitDepth of a raster cell.  For default, use 8.
 @return Initialized hillshade raster renderer
 @since 100
 */
-(instancetype)initWithElevationRaster:(AGSRaster*)elevationRaster
                       outputMinValues:(NSArray<NSNumber*>*)outputMinValues
                       outputMaxValues:(NSArray<NSNumber*>*)outputMaxValues
                       sourceMinValues:(NSArray<NSNumber*>*)sourceMinValues
                       sourceMaxValues:(NSArray<NSNumber*>*)sourceMaxValues
                          noDataValues:(NSArray<NSNumber*>*)noDataValues
                                gammas:(NSArray<NSNumber*>*)gammas
                             colorRamp:(nullable AGSColorRamp*)colorRamp
                              altitude:(double)altitude
                               azimuth:(double)azimuth
                               zFactor:(double)zFactor
                             slopeType:(AGSSlopeType)slopeType
                       pixelSizeFactor:(double)pixelSizeFactor
                        pixelSizePower:(double)pixelSizePower
                        outputBitDepth:(NSInteger)outputBitDepth;

/** Initialize a blend raster renderer with the provided parameters
 @param elevationRaster containing the elevation data
 @param outputMinValues Min output stretch values, one for each band in the raster
 @param outputMaxValues Max output stretch values, one for each band in the raster
 @param sourceMinValues Min input stretch values, one for each band in the raster
 @param sourceMaxValues Max input stretch values, one for each band in the raster
 @param noDataValues NoData values, one for each band in the raster
 @param gammas Gamma adjustment for each band in the raster
 @param colorRamp The spectrum of colors to use
 @param altitude Sun's angle of elevation above the horizon ranging from 0 to 90 degrees.
 @param azimuth Sun's relative position along the horizon ranging from 0 to 360 degrees.
 @param zFactor Scaling factor used to convert the elevation values to horizontal coordinate units. For default, use 1.
 @param slopeType specifying how inclination of the slope is calculated.
 @param pixelSizeFactor to account for altitude changes (scale) as the viewer zooms in and out. For default, use 1.
 @param pixelSizePower to account for altitude changes (scale) as the viewer zooms in and out.  For default, use 1.
 @param outputBitDepth of a raster cell.  For default, use 8.
 @return Initialized hillshade raster renderer
 @since 100
 */
+(instancetype)blendRendererWithElevationRaster:(AGSRaster*)elevationRaster
                                outputMinValues:(NSArray<NSNumber*>*)outputMinValues
                                outputMaxValues:(NSArray<NSNumber*>*)outputMaxValues
                                sourceMinValues:(NSArray<NSNumber*>*)sourceMinValues
                                sourceMaxValues:(NSArray<NSNumber*>*)sourceMaxValues
                                   noDataValues:(NSArray<NSNumber*>*)noDataValues
                                         gammas:(NSArray<NSNumber*>*)gammas
                                      colorRamp:(nullable AGSColorRamp*)colorRamp
                                       altitude:(double)altitude azimuth:(double)azimuth
                                        zFactor:(double)zFactor
                                      slopeType:(AGSSlopeType)slopeType
                                pixelSizeFactor:(double)pixelSizeFactor
                                 pixelSizePower:(double)pixelSizePower
                                 outputBitDepth:(NSInteger)outputBitDepth;

#pragma mark -
#pragma mark properties

/** The elevation data for the renderer
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSRaster *elevationRaster;

/** Gamma correction for each band in the raster
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber*> *gammas;

/** Maximum output values, one for each band in the raster
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber*> *outputMaxValues;

/** Minimum output values, one for each band in the raster
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber*> *outputMinValues;

/** NoData values, one for each band in the raster
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber*> *noDataValues;

/** Maximum input values, one for each band in the raster
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber*> *sourceMaxValues;

/** Minimum input values, one for each band in the raster
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber*> *sourceMinValues;

NS_ASSUME_NONNULL_END
@end
