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

@class AGSGeometry;

/** @file AGSGeoElement.h */ //Required for Globals API doc

/** @brief An abstract representation of geographic entities on a map
 
 This protocol represents abstract geographic entities on a map. Conforming classes provide concrete implementations such as graphics in a graphics overlay, features in a layer, etc.
 
 A geo-element can contain a set of attributes (key-value pairs) providing more
 information about the real-world entity it represents. Attribute types supported are  NSNull, NSString, NSDate, and NSNumber.
 All other attribute types will be ignored. A geo-element can also have a geometry which describes the location and the shape of the
 entity.

 
 @since 100
 */
@protocol AGSGeoElement <NSObject>
NS_ASSUME_NONNULL_BEGIN

@required

#pragma mark -
#pragma mark properties

/** A dictionary containing all the attributes.
 Attribute types supported are NSNull, NSString, NSDate, and NSNumber.
 Other attribute types will be ignored.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString*,id> *attributes;

/** The geometry that defines shape and location.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSGeometry *geometry;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
