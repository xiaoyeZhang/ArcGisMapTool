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

#import "AGSObject.h"

@class AGSPolygon;

/** @file AGSServiceAreaPolygon.h */ //Required for Globals API doc

/** @brief Result polygon returned by `AGSServiceAreaTask`
 
 Instances of this class represent a service area polygon returned as the result of `AGSServiceAreaTask#solveServiceAreaWithParameters:completion:`.  The polygon covers the area of the network that can be reached within the given time, distance, or other travel-cost cutoff. 
 
 @since 100.1
 */
 @interface AGSServiceAreaPolygon : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The lower bound of the service area polygon's cutoff
 @since 100.1
 */
@property (nonatomic, assign, readonly) double fromImpedanceCutoff;

/** The upper bound of the service area polygon's cutoff
 @since 100.1
 */
@property (nonatomic, assign, readonly) double toImpedanceCutoff;

/** The polygon geometry of the service area
 @since 100.1
 */
@property (nonatomic, strong, readonly) AGSPolygon *geometry;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

