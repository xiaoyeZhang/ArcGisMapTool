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

/** @file AGSRestrictionAttribute.h */ //Required for Globals API doc

/** @brief Restrictions within a transportation network
 
 Instances of this class represent a restriction that either completely prevents or attempts to avoid the traversal of an edge in a transportation network
 
 @since 100
 @see http://desktop.arcgis.com/en/arcmap/latest/extensions/network-analyst/understanding-network-attributes.htm#GUID-4BAE3856-0B23-4D4B-937F-7C2B01FEB426
 */
@interface AGSRestrictionAttribute : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Values that specify how the restriction should be applied
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary<NSString*,NSDictionary<NSString*,id>*> *parameterValues;

/** Name of the restriction
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *restrictionUsageParameterName;

NS_ASSUME_NONNULL_END
@end
