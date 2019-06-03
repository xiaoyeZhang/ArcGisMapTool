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

@class AGSStatisticRecord;

/** @file AGSStatisticRecordEnumerator.h */ //Required for Globals API doc

/** @brief An enumerator to iterate over statistic results
 
 Instances of this class represent an enumerator to iterate over AGSStatisticRecord objects.
 
 @since 100.2
 */
@interface AGSStatisticRecordEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/**
 Provides all the statistic records that can be enumerated as an array of `AGSStatisticRecord` objects.
 @since 100.2
 @note Accessing this property causes all the statistic records to be loaded into memory. To conserve memory, consider iterating over the statistic records one-by-one using a for-in loop, or using `#nextObject`.
 */
@property(nonatomic, copy, readonly) NSArray<AGSStatisticRecord*> *allObjects;

#pragma mark -
#pragma mark methods

/**
 Returns the next statistic record.
 @since 100.2
 */
-(nullable AGSStatisticRecord*)nextObject;

/**
 returns YES if there is another statistic record available
 @since 100.2
 */
-(BOOL)hasNextObject;

/**
 puts the cursor back to the beginning
 @since 100.2
 */
-(void)reset;

NS_ASSUME_NONNULL_END

@end
