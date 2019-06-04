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

/** @file AGSLocatorAttribute.h */ //Required for Globals API doc

/** @brief Attribute avaialable for an `AGSLocatorTask`
 
 Instances of this class represent an attribute (field) available for an `AGSLocatorTask`.

 Attributes can provide additional information for results returned by the task (`AGSLocatorInfo#resultAttributes`, and `AGSLocatorInfo#intersectionResultAttributes`), or they can be used to define the input for a multi-line address (`AGSLocatorInfo#searchAttributes`).
 
 @since 100
 */
@interface AGSLocatorAttribute : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Name of the attribute
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

/** User-friendly name of the attribute
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *displayName;

/** Whether the attribute is mandatory to be specified as input.
 Only applicable if this attribute belongs `AGSLocatorInfo#searchAttributes` and is used as input for `AGSLocatorTask#geocodeWithSearchValues:completion:`
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL required;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
