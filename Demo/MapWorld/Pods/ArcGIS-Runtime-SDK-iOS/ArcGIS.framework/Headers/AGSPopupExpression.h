/*
 COPYRIGHT 2018 ESRI
 
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

/** @file AGSPopupExpression.h */ //Required for Globals API doc

/** @brief Arcade expression to display in a popup
 
 Instances of this class represent an expression based on the Arcade language. The expression can be evaluated to display a computed value in the popup.
 @since 100.3
 */
@interface AGSPopupExpression : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The expression that needs to be evaluated
 @since 100.3
 */
@property (nonatomic, copy, readwrite) NSString *expression;

/** Unique name of the expression
 @since 100.3
 */
@property (nonatomic, copy, readwrite) NSString *name;

/** The type of data returned when the expression is evaluated
 @since 100.3
 */
@property (nonatomic, assign, readwrite) AGSPopupExpressionReturnType returnType;

/** User-friendly title for the expression that can be displayed in the UI
 @since 100.3
 */
@property (nonatomic, copy, readwrite) NSString *title;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
