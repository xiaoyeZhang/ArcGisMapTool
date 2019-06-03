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

#import "AGSObject.h"

@class AGSRaster;

/** @file AGSRasterFunctionArguments.h */ //Required for Globals API doc

/** @brief Arguments for a raster function
 
 An instance of this class represents the  arguments (inputs) for a raster function.
 
 @since 100
 */
@interface AGSRasterFunctionArguments : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)rasterFunctionArguments;

#pragma mark -
#pragma mark properties

/** The names of raster arguments in the raster function
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSString *> *rasterNames;

/** The names of other arguments in the raster function
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSString *> *argumentNames;

#pragma mark -
#pragma mark methods

/** Sets a value for an argument in the raster function
 @param argument The argument value to set
 @param name of the argument for which the value is specified. This name must be in the `#argumentNames` list.
 @since 100
 */
-(void)setArgument:(NSString *)argument withName:(NSString *)name;

/** Sets a value for an argument in the raster function
 @param raster The raster value to set
 @param name of the raster argument for which the value is specified. This name must be in the `#rasterNames` list.
 @since 100
 */
-(void)setRaster:(AGSRaster *)raster withName:(NSString *)name;

NS_ASSUME_NONNULL_END

@end

