/*
 COPYRIGHT 2018 ESRI
 
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

#import "AGSKMLNode.h"

/** @file AGSKMLTour.h */ //Required for Globals API doc

/** @brief A KML tour.
 
 @since 100.4
 */
@interface AGSKMLTour : AGSKMLNode

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

#pragma mark -
#pragma mark properties

/** The KML tour's status. The tour status changes can be monitored using Key-Value Observing (KVO).
 @since 100.5
 */
@property (nonatomic, assign, readonly) AGSKMLTourStatus tourStatus;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

