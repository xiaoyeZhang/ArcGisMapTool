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

#import "AGSDatumTransformation.h"
@class AGSGeographicTransformationStep;

/** @file AGSGeographicTransformation.h */ //Required for Globals API doc

/** @brief A transformation between two geographic coordinate systems that have different datums.
 
 Instances of this class represent a transformation between two geographic coordinate systems that have different datums.
 
 A geographic transformation can be constructed from a single geographic transformation step object, or from a list of geographic transformation steps objects that are chained together. Most transformations between spatial references that do not share the WGS 1984 datum use WGS 1984 as an intermediate datum. Thus, it is common to create a geographic transformation object with two geographic transformation steps: first to transform from the datum in the input spatial reference to WGS 1984, and then from WGS 1984 to the output spatial reference's datum. There are a limited number of transformations directly between two non-WGS84 datums, such as WKID 4461, which is NAD_1983_HARN_To_NAD_1983_NSRS2007_1. These do not need WGS 1984 as an intermediate datum.
 
 In most cases, you do not need to construct your own geographic transformation. You can get a list of suitable transformations for a given input and output spatial reference using `AGSTransformationCatalog`.

 The inverse of the geographic transformation, if any, used to transform in the opposite direction, may be accessed using `#inverse`.
 
 A geographic transformation object is immutable.
 
 @see `AGSTransformationCatalog` to find a list of suitable tranformations between two spatial references
 @since 100.2
 */
@interface AGSGeographicTransformation : AGSDatumTransformation

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this transformation with a single step
 @param step in the process of transforming between datums
 @return Initialized geographic transformation
 @since 100.2
 */
- (instancetype)initWithStep:(AGSGeographicTransformationStep *)step;

/** Initialize this transformation with multiple steps. Use this when the multi-step transformation is known in advance. The output of each step should match the input of the following step. Then, you can use the new multi-step transformation where you would use a single-step transformation.
 @param steps in the process of transforming between datums
 @return Initialized geographic transformation
 @since 100.2
 */
- (instancetype)initWithSteps:(NSArray<AGSGeographicTransformationStep*> *)steps;

/** Initialize this transformation with a single step
 @param step in the process of transforming between datums
 @return Initialized geographic transformation
 @since 100.2
 */
+(instancetype)geographicTransformationWithStep:(AGSGeographicTransformationStep *)step;

/** Initialize this transformation with multiple steps. Use this when the multi-step transformation is known in advance. The output of each step should match the input of the following step. Then, you can use the new multi-step transformation where you would use a single-step transformation.
 @param steps in the process of transforming between datums
 @return Initialized geographic transformation
 @since 100.2
 */
+(instancetype)geographicTransformationWithSteps:(NSArray<AGSGeographicTransformationStep*> *)steps;

#pragma mark -
#pragma mark properties

/** One or more steps used in the transformation.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSArray<AGSGeographicTransformationStep*> *steps;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
