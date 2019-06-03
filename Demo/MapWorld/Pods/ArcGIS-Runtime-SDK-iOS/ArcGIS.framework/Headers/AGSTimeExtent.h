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

/** @file AGSTimeExtent.h */

/** @brief An interface to hold a given time interval.
 
 Instances of this class represent a time extent. The time extent is a span of
 time going from a start time to an end time and it is returned in the metadata
 for time-aware services and layers.
 
 @since 100.2
 */
@interface AGSTimeExtent : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

-(instancetype)initWithStartTime:(nullable NSDate *)startTime endTime:(nullable NSDate *)endTime;
+(instancetype)timeExtentWithStartTime:(nullable NSDate *)startTime endTime:(nullable NSDate *)endTime;

-(instancetype)initWithTimeInstant:(NSDate *)timeInstant;
+(instancetype)timeExtentWithTimeInstant:(NSDate *)timeInstant;

#pragma mark -
#pragma mark properties

@property (nullable, nonatomic, strong, readonly) NSDate *endTime;
@property (nullable, nonatomic, strong, readonly) NSDate *startTime;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
