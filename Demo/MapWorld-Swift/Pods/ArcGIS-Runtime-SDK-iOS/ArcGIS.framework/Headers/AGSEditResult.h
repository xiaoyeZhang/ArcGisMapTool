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

/** @file AGSEditResult.h */ //Required for Globals API doc

/** @brief Information about the outcome of an attachment edit operation
 
 Instances of this class represent the outcome of an edit operation.
 
 @see `AGSFeatureEditResult` for outcomes of feature edit operations.
 @since 100
 */

@interface AGSEditResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Indicates if the edit operation encountered an error
 @see `#error`
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL completedWithErrors;

/** The type of edit performed
 @since 100
 */
@property (nonatomic, assign, readonly) AGSEditOperation editOperation;

/** The error encountered during the edit operation. Only available if `#completedWithErrors` is true.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSError *error;

/** The Globl ID of the entity (feature or attachment) being edited
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *globalID;

/** The Object ID of the entity (feature or attachment) being edited
 @since 100
 */
@property (nonatomic, assign, readonly) long long objectID;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
