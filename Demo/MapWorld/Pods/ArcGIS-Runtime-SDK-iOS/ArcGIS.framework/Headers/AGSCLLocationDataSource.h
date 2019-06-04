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
#import "AGSLocationDataSource.h"

/*@file AGSCLLocationDataSource.h */

/** @brief A datasource for @c AGSLocationDisplay based on Core Location
 
 Instances of this class represent a datasource that provides device location based on Apple's Core Location services.
 
 @note The datasource needs the app to be authorized in order to access the device's location. The app's Info.plist must contain appropriate purpose strings (`NSLocationWhenInUseUsageDescription`, `NSLocationAlwaysUsageDescription`, or `NSLocationAlwaysAndWhenInUseUsageDescription` keys) to permit this functionality. When the datasource is started it will attempt to request when-in-use authorization if the app's authorization status is not determined, otherwise it will reuse the authorization that has already been granted. If authorization is denied, location updates will not be available.
 
 @since 100
 @see AGSLocationDisplay
 */
@interface AGSCLLocationDataSource : AGSLocationDataSource
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** The location manager used by this datasource. You should not call the start/stop methods
 on the location manager directly (startUpdatingLocation, startUpdatingHeading, stopUpdatingLocation, stopUdpdatingHeading, etc).
 Also do not assign yourself as the delegate to this location manager.
 @since 100
 */
@property (nonatomic, strong, readonly) CLLocationManager *locationManager;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end

