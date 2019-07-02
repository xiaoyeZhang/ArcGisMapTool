/*
 COPYRIGHT 2019 ESRI
 
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

#import "AGSSymbolLayer.h"
#import "AGSSymbolAnchor.h"

/** @file AGSMarkerSymbolLayer.h */ //Required for Globals API doc

/** @brief A base class for marker symbol layers
 
 A base class for marker symbol layers representing a symbol layer used to display a marker.
 
 This symbol layer controls many common operations vital for working with markers.
 
 This class and its subclasses have properties that may affect both 2D and 3D markers. Some properties apply only to 3D markers, such as angleX, or offsetZ. These properties have no effect on markers in 2D. Properties on 2D markers, such as offsetX, affect the marker's position in screen space, not world space. This means that the x-axis for a 2D marker runs from negative-x on the West edge of the screen to positive-x on the East edge of the screen. Negative-y to positive-y runs from the South edge of the screen to the North edge of the screen.
 
 Properties that apply only to 3D markers affect the marker's position in world space, rather than screen space. This means that the x, y, and z-axes to which the class methods are the axes of the world, with the following layout: from negative to positive, the x-axis spans from world West to world East, the y-axis from world South to world North, and the z-axis from directly into the surface to the sky.
 
 @since 100.5
 */
@interface AGSMarkerSymbolLayer : AGSSymbolLayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/**
 The anchor of a marker symbol layer. It determines how marker symbols are anchored and specifies the marker's anchor point and anchor placement mode. The default symbol anchor is at XY(0, 0) and uses `AGSSymbolAnchorPlacementModeRelative` placement.
 @since 100.5
 */
@property (nonatomic, assign, readwrite) AGSSymbolAnchor anchor;

/**
 The angle of rotation about the anchor point, in degrees. It may be any real number. Defaults to 0. This property affects markers in both Maps and Scenes. Positive values represent counterclockwise rotation. In 2D, the rotation applies around the anchor point of the 2D marker. For 3D markers, the rotation is around the z-axis.
 @since 100.5
 */
@property (nonatomic, assign, readwrite) double heading;

/**
 The marker symbol layer's x-offset. It may be any real number. Defaults to 0. This property affects markers in both Maps and Scenes. The x-offset is a delta applied to the marker in the direction corresponding to the given value. For example, a positive x-offset moves the marker in the positive-x direction.
 @since 100.5
 */
@property (nonatomic, assign, readwrite) CGFloat offsetX;

/**
The marker symbol layer's y-offset. It may be any real number. Defaults to 0. This property affects markers in both Maps and Scenes. The y-offset is a delta applied to the marker in the direction corresponding to the given value. For example, a positive y-offset moves the marker in the positive-y direction.
 @since 100.5
 */
@property (nonatomic, assign, readwrite) CGFloat offsetY;

/**
 The size of marker symbol layer. It may be any real positive number. The default value is 13.333 DIPs (10 points). A larger size means a larger marker.
 @since 100.5
 */
@property (nonatomic, assign, readwrite) CGFloat size;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end


