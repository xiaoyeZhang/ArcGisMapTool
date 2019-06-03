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


/** @file AGSLegendInfo.h */ //Required for Globals API doc

/** @brief An individual legend element
 
 Instances of this class represent an individual element in a legend.
 
 @since 100
 */
@interface AGSLegendInfo : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Name of the legend element
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Symbol of the legend element
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSymbol *symbol;

#pragma mark -
#pragma mark methods

/** Compares whether two legend elements are equal
 @param other legend element to compare this one to
 @return whether the legend elements are equal
 @since 100
 */
-(BOOL)isEqualToLegendInfo:(AGSLegendInfo*)other;

NS_ASSUME_NONNULL_END
@end
