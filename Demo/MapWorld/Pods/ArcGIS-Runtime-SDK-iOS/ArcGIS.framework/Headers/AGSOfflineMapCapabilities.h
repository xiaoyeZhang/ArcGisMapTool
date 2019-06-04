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

@class AGSLayer;
@class AGSOfflineCapability;
@class AGSFeatureTable;

/** @file AGSOfflineMapCapabilities.h */ //Required for Globals API doc

/** @brief Offline capabilities of a map

 Instances of this class represent offline capabilities of a map.
 
 @since 100.1
 */
@interface AGSOfflineMapCapabilities : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates if any errors were encountered while determining the offline capabilities of the map's layers and tables.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL hasErrors;

/** Offline capabilities of the map's layers
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSDictionary<AGSLayer*,AGSOfflineCapability*> *layerCapabilities;


/** Offline capabilities of the map's tables
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSDictionary<AGSFeatureTable*,AGSOfflineCapability*> *tableCapabilities;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

