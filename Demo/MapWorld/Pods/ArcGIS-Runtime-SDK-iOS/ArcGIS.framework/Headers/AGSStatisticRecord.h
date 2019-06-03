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

/** @file AGSStatisticRecord.h */ //Required for Globals API doc

/** @brief An individual statistic record
 
 Instances of this class represent an individual statistic record in a collection that is iterated over using `AGSStatisticRecordEnumerator`.
 
 @since 100.2
 */
@interface AGSStatisticRecord : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Dictionary containing names of fields specified in `AGSStatisticsQueryParameters#groupByFieldNames` and their associated values.
 The type of value depends upon the type of the field.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString*,id> *group;

/** Dictionary of statistics values returned in the query result. The keys match the output alias specified in `AGSStatisticDefinition#outputAlias` and values are of type float or string.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString*,id> *statistics;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
