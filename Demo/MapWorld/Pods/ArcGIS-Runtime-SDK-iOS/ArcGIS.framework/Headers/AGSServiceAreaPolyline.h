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

@class AGSNetworkLocation;
@class AGSPolyline;

/** @file AGSServiceAreaPolyline.h */ //Required for Globals API doc

/** @brief Result polyline returned by `AGSServiceAreaTask`
 
 Instances of this class represent a service area polyline returned as the result of `AGSServiceAreaTask#solveServiceAreaWithParameters:completion:`. The polyline represents the network edges that can be reached within the given impedance.
 
 @since 100.1
 */
@interface AGSServiceAreaPolyline : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Location on the network where the service area polyline begins.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSNetworkLocation *fromNetworkLocation;

/** Location on the network where the service area polyline ends.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSNetworkLocation *toNetworkLocation;

/** The polyline geometry of the service area
 @since 100.1
 */
@property (nonatomic, strong, readonly) AGSPolyline *geometry;

#pragma mark -
#pragma mark methods

/** Cumulative cost value of the path from the facility to the beginning of this polyline. 
 @since 100.1
 */
-(double)fromCumulativeCostForCostAttribute:(NSString*)attributeName;

/** Cumulative cost value of the path from the facility to the end of this polyline.
 @since 100.1
 */
-(double)toCumulativeCostForCostAttribute:(NSString*)attributeName;

NS_ASSUME_NONNULL_END

@end

