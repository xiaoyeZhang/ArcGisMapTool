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

@class AGSLocation;
@class AGSSymbol;
@class AGSPoint;
@class AGSLocationDataSource;

/** @file AGSLocationDisplay.h */


/** @brief Displays device location on a map
 
 Instances of this class manage the "display" of device location on a map - for instance, the symbols used, animation, auto pan behavior, etc. Each `AGSMapView` has its own instance of a location display.
 
 The location display does not itself retrieve any location information. Rather, that is the job of its `#dataSource` which provides location updates on a frequent basis. The default dataSource, `AGSCLLocationDataSource`, uses the underlying platform's location manager (`CLLocationManager`).
 
 @note The default location datasource, `AGSCLLocationDataSource`, needs the app to be authorized in order to access the device's location. The app's Info.plist must contain appropriate purpose strings (`NSLocationWhenInUseUsageDescription`, `NSLocationAlwaysUsageDescription`, or `NSLocationAlwaysAndWhenInUseUsageDescription` keys) to permit this functionality. When the datasource is started it will attempt to request when-in-use authorization if the app's authorization status is not determined, otherwise it will reuse the authorization that has already been granted. If authorization is denied, location updates will not be available.

 
 To start displaying location, you need to call `#startWithCompletion:`. To stop displaying location, you need to call `#stop`.
 
 By default, a round, blue symbol is used to display the device's location. The default dataSource will try to get the
 most accurate location available, but depending upon signal strength, satellite positions, and other factors, the location
 reported could be a best possible approximation. A semi-transparent circle around the location symbol indicates the range of accuracy.
 As the device moves and new location updates are provided by the dataSource, the location symbol will be repositioned on the map.
 
 
 @see @concept{map-gps.htm, Displaying %location on the map}
 @see @sample{5e9fe50031f5461796b5d158a11d0bad, GPS Sample}
 @since 100
 */
@interface AGSLocationDisplay : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates whether the location display is active or not
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL started;

/** The source for location updates.
 Defaults to @c AGSCLLocationDataSource.
 You can create your own datasource, or choose from one of the datasources provided.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSLocationDataSource *dataSource;

/** Defines how to automatically pan the map when new location updates are received.
 Default is @c AGSLocationDisplayAutoPanModeOff
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSLocationDisplayAutoPanMode autoPanMode;

/** Scale that map should automatically be zoomed to upon receiving the first location update.
 Only applies to the first location update received after the autoPanMode goes from AGSLocationDisplayAutoPanModeOff to any other value.
 Defaults to 10,000.
 A value of 0 or less will tell the location display not to auto zoom at all.
 @since 100
 */
@property (nonatomic, assign, readwrite) double initialZoomScale;

/** Determines where to position the location symbol when `#autoPanMode` is `AGSLocationDisplayAutoPanModeNavigation`.
 The default is 0.125 (1/8th), which places it 1/8th of the height of the map view
 starting from the bottom of the map view.
 @since 100
 */
@property (nonatomic, assign, readwrite) float navigationPointHeightFactor;

/** The factor that is used to calculate a wander extent for the location symbol. The location symbol may move freely within the wander extent, but as soon as the symbol exits the wander extent, the mapview re-centers the map on the symbol.
 The default value for this property is 0.5, which means that the wander extent is half the size of the mapview.
 Permissible values are between 0 and 1.  A value of 0 implies an infinitesimal wander extent, and the map is potentially re-centered on every location update (heavy CPU & battery consumption). A value of 1 implies a wander extent equal to the size of the mapview's extent, so the location symbol may move up to the edge of the mapview before the map re-centers (light CPU & battery consumption).
 @since 100
 */
@property (nonatomic, assign, readwrite) float wanderExtentFactor;

/** Most recent location update provided by the `#dataSource`.
 It includes the raw information about the location and may not be in the map's spatial reference.
 @see #mapLocation
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLocation *location;


/** Position of the location symbol, as provided by the most recent location update, projected to the map's spatial reference.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) AGSPoint *mapLocation;


/** Heading relative to the geographic North Pole. The value 0 means the device is pointed toward true north, 90 means it is pointed due east, 180 means it is pointed due south, and so on. A negative value indicates that the heading could not be determined.
 @since 100
 */
@property (nonatomic, assign, readonly) double heading;

/**
 Block that is invoked whenever the location display's `#autoPanMode` changes
 @note The block will be invoked on the same thread on which the event occured, which could be any arbitrary thread. You need to dispatch any UI related work to the main thread.
 @since 100
 */
@property (nullable, nonatomic, copy, readwrite) void (^autoPanModeChangedHandler)(AGSLocationDisplayAutoPanMode autoPanMode);

/**
 Block that is invoked whenever the location display receives a new location update from its `#dataSource`
 @note The block will be invoked on the same thread on which the event occured, which could be any arbitrary thread. You need to dispatch any UI related work to the main thread.
 @since 100
 */
@property (nullable, nonatomic, copy, readwrite) void (^locationChangedHandler)(AGSLocation *location);

/**
 Block that is invoked whenever the `#dataSource` status changes.
 @note The block will be invoked on the same thread on which the event occured, which could be any arbitrary thread. You need to dispatch any UI related work to the main thread.
 @since 100
 */
@property (nullable, nonatomic, copy, readwrite) void (^dataSourceStatusChangedHandler)(BOOL started);

/** The symbol that is used to show the accuracy circle around the location display, provided `#showAccuracy` is true.  Use a symbol that can fill a polygon geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *accuracySymbol;

/** The symbol that is used for location updates that are not current but instead based on a last known position (for example, in the case of deferred location updates).  Use a symbol that can symbolize a point geometry.
 @see `AGSLocation#lastKnown
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *acquiringSymbol;

/** The symbol that is animated to depict a ping around the location symbol to suggest that a location upate was received, provided `#showPingAnimationSymbol` is true.  Use a symbol that can symbolize a point geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *pingAnimationSymbol;

/** The symbol that is used when the location update has both a velocity and course, provided `#useCourseSymbolOnMovement` is true.  Use a symbol that can symbolize a point geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *courseSymbol;

/** The symbol that is used when the location update doesn't have velocity or a course.  Use a symbol that can symbolize a point geometry.
 @see `#acquiringSymbol` for location updates that are not current but instead based on a last known position
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *defaultSymbol;

/** The symbol that is used when the location display `#autoPanMode` is `AGSLocationDisplayAutoPanModeCompassNavigation`.  Use a symbol that can symbolize a point geometry.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *headingSymbol;

/** Indicates whether the `#courseSymbol` should be used instead of `#defaultSymbol` when location updates suggest the device is moving.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL useCourseSymbolOnMovement;

/** The opacity of content (all symbols) displayed by the location display.
 Default is 1.
 @since 100
 */
@property (nonatomic, assign, readwrite) float opacity;

/** Indicates whether the accuracy circle around the location symbol should be displayed. Default is true.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL showAccuracy;

/** Indicates whether the location symbol should be displayed. Default is true.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL showLocation;

/** Indicates whether the ping symbol animating around the location symbol should be displayed. Default is true.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL showPingAnimationSymbol;

#pragma mark -
#pragma mark methods

/** Start the location display, which will in-turn start its #dataSource to start receiving location updates. As the updates are received they will be displayed on the map.
 @param completion block which will be invoked when the operation completes. If the dataSource failed to start, the error property will be populated.
 @since 100
 */
-(void)startWithCompletion:(nullable void(^)(NSError *__nullable error))completion;

/** Stop the location display, which will in-turn stop its #dataSource. Location updates will no longer be received or displayed on the map.
 @since 100
 */
-(void)stop;

NS_ASSUME_NONNULL_END
@end

