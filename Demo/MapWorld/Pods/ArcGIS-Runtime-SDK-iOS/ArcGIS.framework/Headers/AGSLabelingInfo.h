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

@class AGSSymbol;

/** @file AGSLabelingInfo.h */ //Required for Globals API doc

/** @brief Represents labelling properties
 
 Represents the properties of how a service should be labelled.
 @since 100
 */
@interface AGSLabelingInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The expression that specifies what text is drawn in the label.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *labelExpression;

/** The placement of the label.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSLabelingPlacement labelPlacement;

/** The max scale that this label class should be used.
 @since 100
 */
@property (nonatomic, assign, readonly) double maxScale;

/** The min scale that this label class should be used.
 @since 100
 */
@property (nonatomic, assign, readonly) double minScale;

/** The symbol that is used for this label class.  Returns a symbol that can symbolize text.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSymbol *symbol;

/** Specifies whether or not the labelling should use coded values.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL useCodedValues;

/** Label only those feature which satisfy the where clause condition
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *where;

NS_ASSUME_NONNULL_END

@end
