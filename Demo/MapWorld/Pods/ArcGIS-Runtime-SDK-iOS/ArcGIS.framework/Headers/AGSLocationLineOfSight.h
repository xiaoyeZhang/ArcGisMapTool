/*
 COPYRIGHT 2017 ESRI
 
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

#import "AGSLineOfSight.h"

@class AGSPoint;

/** @file AGSLocationLineOfSight.h */ //Required for Globals API doc

/** @brief Analysis of visibility along a line between two locations
 
 Instances of this class represent an analysis object that evaluates visibility along a line defined by observer and target locations.
 
 The result of the analysis is a line between the observer and the target locations (each using Point geometry). Visible and obstructed portions of the line are displayed with unique colors (green and red by default).
 
 @license{Standard}
 @ingroup licensing
 @since 100.2
 */
@interface AGSLocationLineOfSight : AGSLineOfSight
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Intialize the analysis with the provided observer and target locations. As a result of the analysis, a line is rendered between the observer and target with distinct colors representing visible and obstructed segments.
 @param observerLocation defining the observer's location
 @param targetLocation defining the target's location
 @return Initialized line of sight analysis
 @since 100.2
 */
-(instancetype)initWithObserverLocation:(AGSPoint*)observerLocation
                         targetLocation:(AGSPoint*)targetLocation;

/** Intialize the analysis with the provided observer and target locations. As a result of the analysis, a line is rendered between the observer and target with distinct colors representing visible and obstructed segments.
 @param observerLocation defining the observer's location
 @param targetLocation defining the target's location
 @return Initialized line of sight analysis
 @since 100.2
 */
+(instancetype)lineOfSightWithObserverLocation:(AGSPoint*)observerLocation
                                targetLocation:(AGSPoint*)targetLocation;

#pragma mark -
#pragma mark properties

/** The location representing the observer
 @since 100.2
 */
@property (nonatomic, strong, readwrite) AGSPoint *observerLocation;

/** The location representing the target
 @since 100.2
 */
@property (nonatomic, strong, readwrite) AGSPoint *targetLocation;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
