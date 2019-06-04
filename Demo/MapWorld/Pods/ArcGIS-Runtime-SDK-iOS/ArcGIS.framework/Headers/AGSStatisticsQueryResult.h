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

@class AGSStatisticRecordEnumerator;

/** @file AGSStatisticsQueryResult.h */ //Required for Globals API doc

/** @brief Result of queries that return statistics.
 
 Instances of this class represent results of queries that return statistics.  This class has methods that can be used to iterate over the statistics.
 The @c AGSStatisticRecordEnumerator class conforms to `%NSFastEnumeration` which permits the statistic records to be enumerated conveniently using a for-in loop. For example -
 
 ```
 let result:AGSStatisticsQueryResult = ... //A feature query result instance
 let enumr = result.statisticRecordEnumerator()
 for statisticRecord in enumr {
 //do something
 }
 ```
 
 @since 100.2
 */
@interface AGSStatisticsQueryResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties


#pragma mark -
#pragma mark methods

/**
 Returns an enumerator object that lets you access each statistic.
 @since 100.2
 */
-(AGSStatisticRecordEnumerator*)statisticRecordEnumerator;

NS_ASSUME_NONNULL_END

@end
