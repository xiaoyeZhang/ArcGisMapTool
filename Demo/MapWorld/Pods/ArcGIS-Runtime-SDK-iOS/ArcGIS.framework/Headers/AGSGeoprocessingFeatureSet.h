/*
 COPYRIGHT 2016 ESRI
 
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

#import "AGSFeatureSet.h"

/** @file AGSGeoprocessingFeatureSet.h */ //Required for Globals API doc

/** @brief A set of features representing results of a geoprocessing job
 
 Instances of this class represent a set of features that are returned as the result of a geoprocessing job.
 
 @since 100
 */
@interface AGSGeoprocessingFeatureSet : AGSObject <AGSFeatureSet>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates whether the server limit was exceeded while transferring the features. If `true`, then this feature set doesn't contain all the features that it was meant to contain.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isTransferLimitExceeded) BOOL transferLimitExceeded;

NS_ASSUME_NONNULL_END
@end
