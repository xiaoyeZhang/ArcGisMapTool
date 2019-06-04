/*
 COPYRIGHT 2017 ESRI
 
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

/** @file AGSDatumTransformation.h */ //Required for Globals API doc

/** @brief A base class for transformation between two geographic coordinate systems that have different datums
 
 This is the base class for classes used to transform coordinates between spatial references that have different datums. The inverse of the datum transformation, used to transform in the opposite direction, may be accessed using a member function. A datum transformation has a name property intended to be suitable for display, such as when displaying a list of available transformations to an end user.
 
 You can get a list of suitable transformations for a given input and output spatial reference using the `AGSTransformationCatalog` class.  Some transformations require that certain Projection Engine data files be present on the local file system.  Use the function `#missingProjectionEngineFiles` to determine whether any of the required files are missing. The complete list of necessary files is available using `AGSGeographicTransformationStep#projectionEngineFilenames`.
 
 @note In order for any Projection Engine files to be found, the location must be set upon application startup using `AGSTransformationCatalog#setProjectionEngineDirectory:error:` before using any other Runtime API.
 
 A datum transformation object is immutable
 
 @see `AGSTransformationCatalog` to find a list of suitable tranformations between two spatial references
 @since 100.2
 */
@interface AGSDatumTransformation : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** The input spatial reference this transformation can be applied on.
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *inputSpatialReference;

/** Indicates whether any data files needed by the Projection Engine is missing from the local file system.
 @note In order for any Projection Engine files to be found, the location must be set upon application startup using `AGSTransformationCatalog#setProjectionEngineDirectory:error:` before using any other Runtime API.
 @since 100.2
 */
@property (nonatomic, assign, readonly, getter=isMissingProjectionEngineFiles) BOOL missingProjectionEngineFiles;

/** The name of the transformation
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *name;

/** The output spatial reference this transformation produces
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *outputSpatialReference;

#pragma mark -
#pragma mark methods


/** Compares this spatial reference with the provided one for equality.
 @param other transformation to compare this one to.
 @return boolean indicating whether the two transformation are equal
 @since 100.2
 */
-(BOOL)isEqualToDatumTransformation:(AGSDatumTransformation*)other;


/** Returns the inverse of this datum transformation.
 @since 100.2
 */
-(nullable AGSDatumTransformation *)inverse;

NS_ASSUME_NONNULL_END

@end
