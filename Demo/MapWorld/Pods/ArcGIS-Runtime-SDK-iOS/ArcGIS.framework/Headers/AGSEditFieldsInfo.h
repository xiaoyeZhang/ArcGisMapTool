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

/** @file AGSEditFieldsInfo.h */ //Required for Globals API doc

/** @brief Information about edit tracking fields
 
 Instances of this class indicate which fields or attributes of a feature contain information
 about who created/edited the feature and when was it created/edited.
 
 @since 100
 */
@interface AGSEditFieldsInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Name of the field containing information about when the feature was first created.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *creationDateField;

/** Name of the field containing information about who created the feature.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *creatorField;

/** Name of the field containing information about when the feature was last edited.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *editDateField;

/** Name of the field containing information about who edited the feature last.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *editorField;

/** Name of the field containing information about the realm of the person who edited the feature last.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *realm;

NS_ASSUME_NONNULL_END

@end
