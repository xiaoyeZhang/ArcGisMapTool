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


/** @file AGSColorRamp.h */ //Required for Globals API doc

/** @brief A color ramp representing a range of colors
 
 An instance of this class represents a color ramp specifying a range of colors useful for displaying continuous raster data such as elevation or precipitation. Color ramps are used with `AGSBlendRenderer` and `AGSStretchRenderer` to visualize raster data.

 @since 100
 */
@interface AGSColorRamp : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize color ramp with specified parameters
 @param type The predefined color ramp type
 @param size of the color ramp. Use at least 256 to achieve a reasonable color transition, but for smoother transitions use larger values (for eg 20,000-30,000) to match the number of unique pixel values in your raster data.
 @note This is a failable initializer. Specifying a size that is too small for the color ramp type will return nil.
 @return Initialized color ramp
 @since 100
 */
-(nullable instancetype)initWithType:(AGSPresetColorRampType)type size:(NSInteger)size;

/** Initialize color ramp with specified parameters
 @param type The predefined color ramp type
 @param size of the color ramp. Use at least 256 to achieve a reasonable color transition, but for smoother transitions use larger values (for eg 20,000-30,000) to match the number of unique pixel values in your raster data.
 @note This is a failable initializer. Specifying a size that is too small for the color ramp type will return nil.
 @return Initialized color ramp
 @since 100
 */
+(nullable instancetype)colorRampWithType:(AGSPresetColorRampType)type size:(NSInteger)size;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
