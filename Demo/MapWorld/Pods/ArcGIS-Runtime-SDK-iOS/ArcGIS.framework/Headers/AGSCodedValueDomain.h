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

@class AGSCodedValue;

/** @file AGSCodedValueDomain.h */ //Required for Globals API doc

/** @brief Coded value domain supported by a field
 
 Instances of this class represent a coded value domain
 
 @since 100
 */
@interface AGSCodedValueDomain : AGSDomain

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** An array containing the coded values
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSCodedValue*> *codedValues;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
