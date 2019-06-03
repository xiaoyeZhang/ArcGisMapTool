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

@class AGSDatumTransformation;
@class AGSEnvelope;
@class AGSSpatialReference;

/** @file AGSTransformationCatalog.h */ //Required for Globals API doc

/** @brief A class for discovering and managing transformations
 
 This class represent a catalog of available geographic transformation that can be used to covert between datums. It provides a mechanism for discovering available transformations. You can retrieve the default transformation or the best available transformation. The area of interest may be taken into account.
 
 This class also allows you to set the location where Projection Engine data files needed for some transformations are found on local storage. The `#setProjectionEngineDirectory:error:` must be called upon application startup to specify the location before using any other Runtime API.
 
 The default transformation used is the most suitable one across the area covered by the input and output spatial references. You can sometimes get a more suitable transformation by specifying the extent of your specific work area.
 
 @since 100.2
 */
@interface AGSTransformationCatalog : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

/** Returns the directory of the Projection Engine files on the local file system.
 @since 100.2
 */
+(nullable NSURL *)projectionEngineDirectory;

/** Sets the directory of the Projection Engine files on the local file system.
 @note This method should be called immediately upon application startup before any other API method calls.
 @since 100.2
 */
+(BOOL)setProjectionEngineDirectory:(nullable NSURL*)directory error:(NSError**)error;


/** Returns the default transformation used to transform between datums of the input and output spatial references, without taking into account the area of interest. This default transformation is automatically used in `AGSGeometryEngine#projectGeometry:toSpatialReference:`.
 @param inputSpatialReference The spatial reference whose datum is the starting point for the transformation
 @param outputSpatialReference The spatial reference whose datum is the ending point for the transformation
 @return transformation. Returns null if no transformation is required (for example if the two spatial references have the same underlying datum).
 @since 100.2
 */
+(nullable AGSDatumTransformation *)transformationForInputSpatialReference:(AGSSpatialReference *)inputSpatialReference
                                                    outputSpatialReference:(AGSSpatialReference *)outputSpatialReference;


/** Returns the most suitable transformation used to transform between datums of the input and output spatial references, taking into account the area of interest.
 @param inputSpatialReference The spatial reference whose datum is the starting point for the transformation
 @param outputSpatialReference The spatial reference whose datum is the ending point for the transformation
 @param areaOfInterest A geographic area containing coordinates to be transformed, expressed as an envelope. Will be reprojected to the inputSpatialReference if it has a different spatial reference.
 @return transformation. Returns null if no transformation is required (for example if the two spatial references have the same underlying datum), or if `areaOfInterest` lies outside of the horizon of `inputSpatialReference`.
 @since 100.2
 */
+(nullable AGSDatumTransformation *)transformationForInputSpatialReference:(AGSSpatialReference *)inputSpatialReference
                                                    outputSpatialReference:(AGSSpatialReference *)outputSpatialReference
                                                            areaOfInterest:(nullable AGSEnvelope *)areaOfInterest;


/** Returns a list representing the datum transformations suitable for projecting between datums of spatial references without taking into account the area of interest.
 
 The list is ordered in descending order by suitability, with the most suitable being first in the list. The list includes grid-based transformations, regardless of the presence or absence of required Projection Engine files supporting those transformations. To check for presence/absence of supporting files, use `AGSGeographicTransformationStep#missingProjectionEngineFiles`.
 @param inputSpatialReference The spatial reference whose datum is the starting point for the transformation
 @param outputSpatialReference The spatial reference whose datum is the ending point for the transformation
 @return transformation
 @since 100.2
 */
+(NSArray<AGSDatumTransformation*> *)transformationsBySuitabilityWithInputSpatialReference:(AGSSpatialReference *)inputSpatialReference
                                                                    outputSpatialReference:(AGSSpatialReference *)outputSpatialReference;


/** Returns a list representing the datum transformations suitable for projecting between spatial references and takes into account the area of interest.
 
 The list is ordered in descending order by suitability, with the most suitable being first in the list. The list includes grid-based transformations, regardless of the presence or absence of required Projection Engine files supporting those transformations. To check for presence/absence of supporting files, use `AGSGeographicTransformationStep#missingProjectionEngineFiles`.
 @param inputSpatialReference The spatial reference whose datum is the starting point for the transformation
 @param outputSpatialReference The spatial reference whose datum is the ending point for the transformation
 @param areaOfInterest A geographic area containing coordinates to be transformed, expressed as an envelope.
 @return transformation
 @since 100.2
 */
+(NSArray<AGSDatumTransformation*> *)transformationsBySuitabilityWithInputSpatialReference:(AGSSpatialReference *)inputSpatialReference
                                                                    outputSpatialReference:(AGSSpatialReference *)outputSpatialReference
                                                                            areaOfInterest:(nullable AGSEnvelope *)areaOfInterest;


NS_ASSUME_NONNULL_END

@end
