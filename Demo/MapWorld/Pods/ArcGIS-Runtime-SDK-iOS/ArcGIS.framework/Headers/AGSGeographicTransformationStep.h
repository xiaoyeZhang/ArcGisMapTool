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

/** @file AGSGeographicTransformationStep.h */ //Required for Globals API doc

/** @brief Represents a step in the process of transforming between datums
 
 Instances of this class represent a step in the process of transforming between datums of spatial references.
 
 Each geographic transformation step can be constructed from a well-known ID (WKID) that represents a geographic transformation. Because the Projection Engine supports thousands of transformations, WKIDs are not presented in the SDK as enumerations. Instead, they are documented in the guide and online.
 The list of supported WKIDs includes a transformation from every supported datum to WGS 1984. Additionally, there is a more limited list of transformations directly between two non-WGS84 datums, such as 4461, which is NAD_1983_HARN_To_NAD_1983_NSRS2007_1.
 
 Transformations with more than one step typically go via WGS84, with one forward and one inverse geographic transformation chained together to get the required geographic coordinates.
 
 A geographic transformation step object is immutable.
 
 @see `AGSTransformationCatalog` to find a list of suitable tranformations between two spatial references
 @since 100.2
 */
@interface AGSGeographicTransformationStep : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this step with the given well known ID of a geographic transformation
 @param WKID well known ID of a geographic transformation
 @return Initialized geographic transformation step
 @since 100.2
 */
-(nullable instancetype)initWithWKID:(NSInteger)WKID;

/** Initialize this step with the given well known text of a geographic transformation
 @param WKText well known text of a geographic transformation
 @return Initialized geographic transformation step
 @since 100.2
 */
-(nullable instancetype)initWithWKText:(NSString*)WKText;

/** Initialize this step with the given well known ID of a geographic transformation
 @param WKID well known ID of a geographic transformation
 @return Initialized geographic transformation step
 @since 100.2
 */
+(nullable instancetype)geographicTransformationStepWithWKID:(NSInteger)WKID;

/** Initialize this step with the given well known text of a geographic transformation
 @param WKText well known text of a geographic transformation
 @return Initialized geographic transformation step
 @since 100.2
 */
+(nullable instancetype)geographicTransformationStepWithWKText:(NSString*)WKText;

#pragma mark -
#pragma mark properties

/** Well Known ID of the geographic transformation
 @since 100.2
 */
@property (nonatomic, assign, readonly) NSInteger WKID;


/** Well Known Text of the geographic transformation
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *WKText;

/** Indicates if any files needed by the Projection Engine for this geographic transformation step are missing from the local file system
  @note In order for the Projection Engine files to be found, their location must be set upon application startup using `AGSTransformationCatalog#setProjectionEngineDirectory:error:` before using any other Runtime API.
 @since 100.2
 */
@property (nonatomic, assign, readonly, getter=isMissingProjectionEngineFiles) BOOL missingProjectionEngineFiles;

/** The list of the Projection Engine files required to support this geographic transformation step.
 Each name in the list includes the full path. Projection Engine datasets are used in grid-based transforms.
 @note In order for the Projection Engine files to be found, their location must be set upon application startup using `AGSTransformationCatalog#setProjectionEngineDirectory:error:` before using any other Runtime API.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *projectionEngineFilenames;

#pragma mark -
#pragma mark methods

/** Returns the inverse of this geographic transformation step or NULL if the transformation is not invertible.
 @since 100.2
 */
-(nullable AGSGeographicTransformationStep*)inverse;

/** Returns if this geographic transformation step is equal to the one provided
 @param other step to compare this one to
 @since 100.2
 */
-(BOOL)isEqualToGeographicTransformationStep:(AGSGeographicTransformationStep*)other;

NS_ASSUME_NONNULL_END

@end
