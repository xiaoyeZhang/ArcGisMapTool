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

/** @file AGSAddRastersParameters.h */ //Required for Globals API doc

/** @brief Parameters specifying rasters to add to a mosaic dataset raster
 
 An instance of this class represents parameters specifying which rasters to add to a mosaic dataset raster.
 
 The rasters do not have to be adjoining or overlapping but can exist as unconnected, discontinuous datasets. For example, you can have images that completely cover an area or you can have many strips of images that may not join together to form a continuous image (such as along pipelines).
 
 
 @since 100
 @see `AGSMosaicDatasetRaster#addRasters:completion:`
 */
@interface AGSAddRastersParameters : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)addRastersParameters;

#pragma mark -
#pragma mark properties

/** A filter for the raster data being added to the mosaic dataset. It is a regular expression with ECMA-262 grammar (http://ecma-international.org/ecma-262/5.1/#sec-15.10) used to filter rasters based on their filename.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *filter;

/** URL to a folder containing multiple raster datasets to be added to the mosaic dataset raster.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) NSURL *inputDirectoryURL;

/** URL to a CSV file that contains the list of rasters and their properties are to be added to the mosaic dataset raster
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) NSURL *inputFileURL;

/**
 @since 100
 */
@property (nonatomic, assign, readwrite) double maxPixelSizeFactor;

/**
 @since 100
 */
@property (nonatomic, assign, readwrite) double minPixelSizeFactor;

/** URL to a JSON file that contains a raster function template which is applied to each input raster when adding them to a mosaic dataset.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) NSURL *rasterFunctionTemplateFileURL;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

