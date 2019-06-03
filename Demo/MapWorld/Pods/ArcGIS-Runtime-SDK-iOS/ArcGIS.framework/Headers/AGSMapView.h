/*
 COPYRIGHT 2012 ESRI
 
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


#import "AGSMapViewCommon.h"

NS_ASSUME_NONNULL_BEGIN

/*@file AGSMapView.h */

/** @brief A View component to display 2D geographic content such as maps.
 
 Instances of this class represent views that can display 2D geographic content such as maps on screen. In an MVC architecture, this class represents the View tier and is a type of `UIView` on iOS or `NSView` on Mac. The Model tier is represented by `AGSMap` which contains the geographic content.
 
 
 To display a map, add an `AGSMapView` to your view controller's view heirarchy. You can do this either using Interface Builder and Storyboards, or programmatically in code. Next, assign an `AGSMap` to the mapview. The mapview will automatically load the map, its basemap, and operational layers, and display their contents on screen.
 
 To navigate the map, you can use touch gestures such as double-tap, drag, two-finger tap, etc on iOS, and the mouse/trackpad, and keyboard shortcuts on Mac OS. You can also programmatically [change the viewpoint](#setViewpoint:) with or without animation.
 
 The mapview informs it's [touch delegate](#touchDelegate) whenever touch/mouse/trackpad/keyboard events are associated with it. You can set your class as the touch delegate to be notified of these events.
 
 
 @see `AGSSceneView` to display 3D geographic content such as scenes.
 @since 100
 */

@interface AGSMapView : AGSMapViewCommon


@end

NS_ASSUME_NONNULL_END
