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

@class AGSRasterFunctionArguments;

/** @file AGSRasterFunction.h */ //Required for Globals API doc

/** @brief A function used to apply on-the-fly processing to rasters
 
 An instance of this class represents a raster function that can be used to apply processing to rasters. This processing is applied on-the-fly so as not to change the original data.
 
 Raster functions can be chained together to apply more complex processing to a raster. The chain works in such a way that the output of one raster function becomes the input to the raster function applied on top of it in the chain.
 
 @see [Raster Function JSON syntax](http://resources.arcgis.com/en/help/arcgis-rest-api/index.html#/Raster_function_objects/02r3000000rv000000/)
 @since 100
*/
@interface AGSRasterFunction : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

/** Initalize raster function using the provided file
 @param fileURL to a JSON file containing a template for the raster function
 @return Initialized raster function
 @since 100
 */
-(instancetype)initWithFileURL:(NSURL *)fileURL;

/** Initalize raster function using the provided file
 @param fileURL to a JSON file containing a template for the raster function
 @return Initialized raster function
 @since 100
 */
+(instancetype)rasterFunctionWithFileURL:(NSURL *)fileURL;

#pragma mark -
#pragma mark properties

/** The arguments for the raster function. These arguments provide values for the place holders specified in the raster function template at `#fileURL`. 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSRasterFunctionArguments *arguments;

/** URL to a JSON file containing a template for the raster function
 @since 100
 */
@property (nonatomic, strong, readonly) NSURL *fileURL;

#pragma mark -
#pragma mark methods

+(id)fromJSON:(NSString *)json error:(NSError **)error;

NS_ASSUME_NONNULL_END

@end

