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

#import "AGSEditResult.h"

@class AGSEditResult;

/** @file AGSFeatureEditResult.h */ //Required for Globals API doc

/** @brief Information about the outcome of a feature edit operation
 
 Instances of this class represent the outcome of a feature edit operation.
 
 @see `AGSEditResult` for outcomes of attachment edit operations.
 @since 100
 */

@interface AGSFeatureEditResult : AGSEditResult

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Results of edit operations on attachments belonging to this feature. The array contains `AGSEditResult` objects.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSEditResult*> *attachmentResults;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
