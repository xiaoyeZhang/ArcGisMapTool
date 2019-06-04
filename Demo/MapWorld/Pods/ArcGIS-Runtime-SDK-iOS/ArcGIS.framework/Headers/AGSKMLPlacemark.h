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

#import "AGSKMLNode.h"
#import "AGSGeoElement.h"

@class AGSKMLGeometry;

/** @file AGSKMLPlacemark.h */ //Required for Globals API doc

/** @brief A KML Placemark element
 
 An instance of this class represents a KML `<Placemark>` element which is a node with associated Geometry.
 
 @since 100.4
 */
@interface AGSKMLPlacemark : AGSKMLNode <AGSGeoElement>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The geometries associated with this placemark.
 @note The array will only have one geometry for non-multi geometries.
 @since 100.4
 */
@property (nonatomic, copy, readonly) NSArray<AGSKMLGeometry*> *geometries;

/** The type of the graphic in this KML placemark.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSKMLGraphicType graphicType;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

