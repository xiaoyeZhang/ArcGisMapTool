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

/** @file AGSHillshadeRenderer.h */ //Required for Globals API doc

/** @brief A hillshade raster renderer
 
 Instances of this class represent a hillshade renderer that can help visualize raster data using `AGSRasterLayer`.
 
 A hillshade (also known as shaded relief) is a grayscale representation of a 3D surface, with the sun's relative position taken into account for shading the image.
 
 @since 100
 */
@interface AGSHillshadeRenderer : AGSRasterRenderer
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a hillshade raster renderer with the provided parameters
 @param altitude Sun's angle of elevation above the horizon ranging from 0 to 90 degrees
 @param azimuth Sun's relative position along the horizon ranging from 0 to 360 degrees
 @param zFactor Scaling factor used to convert the elevation values to horizontal coordinate units. For default, use 1.
 @param slopeType specifying how inclination of the slope is calculated
 @param pixelSizeFactor to account for altitude changes (scale) as the viewer zooms in and out. For default, use 1.
 @param pixelSizePower to account for altitude changes (scale) as the viewer zooms in and out. For default, use 1.
 @param outputBitDepth of a raster cell. For default, use 8.
 @return Initialized hillshade raster renderer
 @since 100
 */
-(instancetype)initWithAltitude:(double)altitude
                        azimuth:(double)azimuth
                        zFactor:(double)zFactor
                      slopeType:(AGSSlopeType)slopeType
                pixelSizeFactor:(double)pixelSizeFactor
                 pixelSizePower:(double)pixelSizePower
                 outputBitDepth:(NSInteger)outputBitDepth;

/** Initialize a hillshade raster renderer with the provided parameters
 @param altitude Sun's angle of elevation above the horizon ranging from 0 to 90 degrees
 @param azimuth Sun's relative position along the horizon ranging from 0 to 360 degrees
 @param zFactor Scaling factor used to convert the elevation values to horizontal coordinate units. For default, use 1.
 @param slopeType specifying how inclination of the slope is calculated
 @param pixelSizeFactor to account for altitude changes (scale) as the viewer zooms in and out. For default, use 1.
 @param pixelSizePower to account for altitude changes (scale) as the viewer zooms in and out. For default, use 1.
 @param outputBitDepth of a raster cell. For default, use 8.
 @return Initialized hillshade raster renderer
 @since 100
 */
+(instancetype)hillshadeRendererWithAltitude:(double)altitude
                                     azimuth:(double)azimuth
                                     zFactor:(double)zFactor
                                   slopeType:(AGSSlopeType)slopeType
                             pixelSizeFactor:(double)pixelSizeFactor
                              pixelSizePower:(double)pixelSizePower
                              outputBitDepth:(NSInteger)outputBitDepth;

#pragma mark -
#pragma mark properties

/** Altitude is the sun's angle of elevation above the horizon and ranges from 0 to 90 degrees. A value of 0 degrees indicates that the sun is on the horizon, that is, on the same horizontal plane as the frame of reference. A value of 90 degrees indicates that the sun is directly overhead.
 
  Together the `#altitude` and `#azimuth` together indicate the sun's relative position.

 @since 100
 */
@property (nonatomic, assign, readonly) double altitude;

/** Azimuth is the sun's relative position along the horizon (in degrees). This position is indicated by the angle of the sun measured clockwise from due north. An azimuth of 0 degrees indicates north, east is 90 degrees, south is 180 degrees, and west is 270 degrees.
 
 Together the `#altitude` and `#azimuth` together indicate the sun's relative position.
 
 @since 100
 */
@property (nonatomic, assign, readonly) double azimuth;

/** The bit depth (pixel depth) of a raster cell. Determines the range of values that a particular raster can store, which is based on the formula 2n (where n is the bit depth). For example, an 8-bit raster can have 256 unique values that range from 0 to 255.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger outputBitDepth;

/** `pixelSizeFactor` and `#pixelSizePower` values account for altitude changes (scale) as the viewer zooms in and out. This is recommended when using worldwide datasets.
 
 Only applicable is `#slopeType` is `AGSSlopeTypeScaled`
 @since 100
 */
@property (nonatomic, assign, readonly) double pixelSizeFactor;

/** `pixelSizePower` and `#pixelSizeFactor` values account for altitude changes (scale) as the viewer zooms in and out. This is recommended when using worldwide datasets.

 Only applicable is `#slopeType` is `AGSSlopeTypeScaled`

 @since 100
 */
@property (nonatomic, assign, readonly) double pixelSizePower;

/** The manner in which inclination of the slope is calculated.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSSlopeType slopeType;

/** A scaling factor used to convert the elevation values for two purposes:
 
 @li To convert the elevation units (such as meters or feet) to the horizontal coordinate units (x,y) of the dataset, which may be feet, meters, or degrees.
 @li To add vertical exaggeration for visual effect.

 If the x,y units and z units are in the same units of measure the z-factor is 1, unless a vertical exaggeration needs to be applied.
 If the x,y units and z units are in different units of measure the z-factor must be set to the appropriate factor, or the results will be incorrect. For example, if your z units are feet and your x,y units are meters, you would use a z-factor of 0.3048 to convert your z units from feet to meters (1 foot = 0.3048 meter).
 
 @since 100
 */
@property (nonatomic, assign, readonly) double zFactor;

NS_ASSUME_NONNULL_END
@end
