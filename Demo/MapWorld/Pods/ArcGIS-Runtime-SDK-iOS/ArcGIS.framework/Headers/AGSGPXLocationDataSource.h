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

#import "AGSSimulatedLocationDataSource.h"
#import "AGSRemoteResource.h"

@class AGSLocation;
@class AGSPolyline;
@class AGSRequestConfiguration;


/** @file AGSGPXLocationDataSource.h */ //Required for Globals API doc

/** @brief Simulates location updates based on a GPX file
 
 Instances of this class represent a datasource that can simulate location updates from a GPX file. If a track exists, it will use the first track segment in the file. Else, if a route exists, it will use the full route.
 
 @note The GPX file is loaded and parsed asynchronously when `#startWithCompletion:` is invoked.
 
 @since 100
 @see AGSLocationDisplay
 */


@interface AGSGPXLocationDataSource : AGSSimulatedLocationDataSource <AGSRemoteResource>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initializes the datasource using a URL to the GPX file (on the web or on disk)
 @param URL URL to a GPX file on the web or on disk
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize this object with the name of a GPX (.gpx file) within the application bundle or shared documents directory.
 @param name of GPX file (same as the name of the .gpx file without the file extension)
 @since 100
 */
-(instancetype)initWithName:(NSString*)name;

/** Initialize the datasource using GPX data
 @param gpxData Representation of data in a GPX file
 @since 100
 */
-(instancetype)initWithData:(NSData*)gpxData;


/** Initializes the datasource using a URL to the GPX file (on the web or on disk)
 @param URL URL to a GPX file on the web or on disk
 @since 100
 */
+(instancetype)GPXLocationDataSourceWithURL:(NSURL*)URL;

/** Initialize this object with the name of a GPX (.gpx file) within the application bundle or shared documents directory.
 @param name of GPX file (same as the name of the .gpx file without the file extension)
 @since 100
 */
+(instancetype)GPXLocationDataSourceWithName:(NSString*)name;

/** Initialize the datasource using GPX data
 @param gpxData Representation of data in a GPX file
 @since 100
 */
+(instancetype)GPXLocationDataSourceWithData:(NSData*)gpxData;

#pragma mark -
#pragma mark properties

/** URL to a GPX file on the web or on disk
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *URL;

/** Security credentials to access the remote GPX file. Only applicable if the file is secured.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSCredential *credential;

/** Configuration which defines the behavior and policies to use when accessing the remote GPX file.
 The default will be nil. If it is nil the `AGSRequestConfiguration#globalConfiguration` will be used.
 @since 100
 */

@property (nullable, nonatomic, strong, readwrite) AGSRequestConfiguration *requestConfiguration;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end

