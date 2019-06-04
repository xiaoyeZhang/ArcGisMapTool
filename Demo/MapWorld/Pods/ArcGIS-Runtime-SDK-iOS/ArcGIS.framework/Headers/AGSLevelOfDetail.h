/*
 COPYRIGHT 2015 ESRI
 
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

/** @file AGSLevelOfDetail.h */ //Required for Globals API doc

/** @brief A scale level in a tiling scheme
 
 Instances of this class represent an individual scale level of a tile cache's tiling scheme
 
 @since 100
 */

@interface AGSLevelOfDetail : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a level of detail to represent a scale level of a tiling scheme
 @param level of the desired scale level
 @param resolution of the desired scale level
 @param scale of the desired scale level
 @return An initialized level of detail
 @since 100
 */
-(instancetype)initWithLevel:(NSInteger)level resolution:(double)resolution scale:(double)scale;

/** Initialize a level of detail to represent a scale level of a tiling scheme
 @param level of the desired scale level
 @param resolution of the desired scale level
 @param scale of the desired scale level
 @return An initialized level of detail
 @since 100
 */
+(instancetype)levelOfDetailWithLevel:(NSInteger)level resolution:(double)resolution scale:(double)scale;

#pragma mark -
#pragma mark properties

/** ID for the scale level. The top most level is 0. This level represents the
 finest level of detail.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger level;

/** Resolution, in map units, of each pixel in a tile for the scale level.
 @since 100
 */
@property (nonatomic, assign, readonly) double resolution;


/** Scale for the level.
 @since 100
 */
@property (nonatomic, assign, readonly) double scale;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
