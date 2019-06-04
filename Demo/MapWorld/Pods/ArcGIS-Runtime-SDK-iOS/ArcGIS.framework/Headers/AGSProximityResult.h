/*
 COPYRIGHT 2014 ESRI
 
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

@class AGSPoint;

/** @file AGSProximityResult.h */ //Required for Globals API doc

/** @brief The result of a proximity search.
 
 Instances of this class represent results of a proximity search using AGSGeometryEngine
 such as finding the nearest vertex or a coordinate of a geometry.
 @since 100
 */

@interface AGSProximityResult : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The point found.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPoint *point;

/** The index of the point that was found within it's part.
 @since 100
 */
@property (nonatomic, readonly) NSInteger pointIndex;

/** The index of the part in which the point was found.
 @since 100
 */
@property (nonatomic, readonly) NSInteger partIndex;

/** The result distance.
 @since 100
 */
@property (nonatomic, readonly) double distance;

NS_ASSUME_NONNULL_END
@end

