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

/** @file AGSLocationDataSource.h */

/** @brief An abstract base class that provides location updates to `AGSLocationDisplay`
 
 Subclasses represent datasources that provide location updates to the mapview's location display.
 
 @since 100
 @see AGSLocationDisplay
 */

@interface AGSLocationDataSource : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers


#pragma mark -
#pragma mark properties

/** Indicates whether the datasource is active or not
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL started;

/** The error that prevented the datasource from starting or was encountered while retrieving a location udpate
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSError *error;

#pragma mark -
#pragma mark methods

/** This is invoked by the location display on the datasource to initiate requesting location updates. Internally this method calls `#doStart` which subclasses must implement.
 @param completion block which will be invoked when the operation completes. If the dataSource failed to start, the error property will be populated.
 @since 100
 */
-(void)startWithCompletion:(nullable void(^)(NSError *__nullable error))completion;

/** This is invoked by the location display on the datasource to stop requesting location updates. Internally this method calls `#doStop` which subclasses must implement.
 @since 100
 */
-(void)stop;

@end

/** @brief A category to organize subclassable aspects of `AGSLocationDataSource`
 
 Members of particular interest while subclassing `AGSLocationDataSource`
 
 @since 100
 */
@interface AGSLocationDataSource (ForSubclassEyesOnly)

/** Subclasses must implement this method to start the datasource.
 Once the datasource has started or failed to start it should call `#didStartOrFailWithError:`. As updates are received, the datasource should call `#didUpdateLocation:` or `#didUpdateHeading:`.
 @since 100
 */
-(void)doStart;

/** Subclasses must implement this method to stop the datasource.
 Once the datasource has stopped it should call `#didStop`
 @since 100
 */
-(void)doStop;

/** Subclasses must call this in `#doStart` once the datasource has started.
 @since 100
 */
-(void)didStartOrFailWithError:(nullable NSError*)error;

/** Subclasses must call this in `#doStop` once the datasource has stopped.
 @since 100
 */
-(void)didStop;

/** Subclasses must call this once they have a new heading.
 @since 100
 */
-(void)didUpdateHeading:(double)heading;

/** Subclasses must call this once they have a new location.
 @since 100
 */
-(void)didUpdateLocation:(AGSLocation*)location;

NS_ASSUME_NONNULL_END
@end


