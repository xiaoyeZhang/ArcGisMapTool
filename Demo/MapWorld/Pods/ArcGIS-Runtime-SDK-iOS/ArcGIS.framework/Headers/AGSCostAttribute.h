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

/** @file AGSCostAttribute.h */ //Required for Globals API doc

/** @brief A cost to travel along the edge of a transportation network
 
 Instances of this class represent a cost incurred while traversing the edge of a transportation network. Optimized routes attempt to minimize the cost of various impedances such as travel time, distance covered, elevation gained, etc.
 
 @since 100
 @see http://desktop.arcgis.com/en/arcmap/latest/extensions/network-analyst/understanding-network-attributes.htm#GUID-ADE9DCEB-62A0-405E-AE57-A13829DE7DEC
 */
@interface AGSCostAttribute : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Cost values
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary<NSString*,NSDictionary<NSString*,id>*> *parameterValues;

/** The unit in which the cost values are measured
 @since 100
 */
@property (nonatomic, assign, readonly) AGSAttributeUnit unit;

NS_ASSUME_NONNULL_END
@end
