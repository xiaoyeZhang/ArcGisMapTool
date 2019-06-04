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

#import "AGSDomain.h"

/** @file AGSRangeDomain.h */ //Required for Globals API doc

/** @brief Range domain supported by a field
 
 Instances of this class represent a range domain
 
 @since 100
 */
@interface AGSRangeDomain : AGSDomain

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Minumum value of the range. Can be NSNumber or NSDate
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) id minValue;

/** Maximun value of the range. Can be NSNumber or NSDate
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) id maxValue;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
