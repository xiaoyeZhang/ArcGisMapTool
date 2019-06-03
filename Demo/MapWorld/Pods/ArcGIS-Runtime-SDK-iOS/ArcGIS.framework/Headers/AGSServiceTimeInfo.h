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

@class AGSTimeReference;
@class AGSTimeExtent;
@class AGSTimeValue;

/** @file AGSServiceTimeInfo.h */ //Required for Globals API doc

/** @brief Information about an ArcGIS Server service time info.
 
 Instances of this class represent information about an ArcGIS service time info.
 
 @since 100.2
 */
@interface AGSServiceTimeInfo : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

@property (nullable, nonatomic, strong, readonly) AGSTimeValue *defaultInterval;

/** Default time interval of the data in the service.
 @since 100.2
 */
@property (nonatomic, assign, readonly) NSInteger defaultTimeInterval;

/** Temporal unit in which the default time interval is measured.
 @since 100.2
 */
@property (nonatomic, assign, readonly) AGSTimeUnit defaultTimeIntervalUnit;

/** Default time window of the data in the service.
 @since 100.2
 */
@property (nonatomic, assign, readonly) NSInteger defaultTimeWindow;

/** Indicates whether the service has live data.
 @since 100.2
 */
@property (nonatomic, assign, readonly) BOOL hasLiveData;

@property (nullable, nonatomic, strong, readonly) AGSTimeExtent *timeExtent;

/** Information about the time reference of the data in the service.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSTimeReference *timeReference;

/** Indicates time relation.
 @since 100.2
 */
@property (nonatomic, assign, readonly) AGSTimeRelation timeRelation;

@property (nullable, nonatomic, strong, readonly) AGSTimeValue *timeWindow;

#pragma mark -
#pragma mark methods

/** Determines whether or not two time infos are equal.
 @param other The time info to compare the current time info with.
 @since 100.2
 */
-(BOOL)isEqualToServiceTimeInfo:(AGSServiceTimeInfo*)other;

NS_ASSUME_NONNULL_END
@end
