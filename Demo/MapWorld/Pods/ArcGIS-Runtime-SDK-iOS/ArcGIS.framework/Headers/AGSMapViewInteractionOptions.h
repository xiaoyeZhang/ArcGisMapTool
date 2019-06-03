/*
 COPYRIGHT 2016 ESRI
 
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

/** @file AGSMapViewInteractionOptions.h */ //Required for Globals API doc

/** @brief Options to configure Map View user interactions
 
 Instances of this class provide options to configure the user interactions supported by `AGSMapView`.
 
 @since 100
 */
@interface AGSMapViewInteractionOptions : NSObject

#pragma mark -
#pragma mark initializers

+(instancetype)mapViewInteractionOptions;

#pragma mark -
#pragma mark properties

/** Whether all the user interaction is enabled on the @c AGSMapView.
 Default is @c YES
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isEnabled) BOOL enabled;

/** Whether the user can rotate the @c AGSMapView.
 Default is @c YES
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isRotateEnabled) BOOL rotateEnabled;

/** Whether the user can pan the @c AGSMapView.
 If this is disabled then zooming will zoom to center instead of any anchor point.
 Also when diabled this will prevent the magnifier panning the @c AGSMapView regardless of what `allowMagnifierToPan` is set to.
 Default is @c YES
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isPanEnabled) BOOL panEnabled;

/** Whether the user can zoom in or out on the @c AGSMapView.
 Default is @c YES
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isZoomEnabled) BOOL zoomEnabled;

/** Indicates whether a magnifier should be shown on the @c AGSMapView when the user performs a long press.
 Default is @c YES
 */
@property (nonatomic, assign, readwrite, getter=isMagnifierEnabled) BOOL magnifierEnabled;

/** Indicates whether the @c AGSMapView should be panned automatically when the magnifier gets near the edge of the @c AGSMapView.
 Default is @c YES
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL allowMagnifierToPan;

/** Zoom factor for animated zooming in and out.
 Default is 2.0. Values less than or equal to 1.0 are not supported and will be ignored.
 @since 100.3
 */
@property (nonatomic, assign, readwrite) double zoomFactor;
    
#pragma mark -
#pragma mark methods

@end



