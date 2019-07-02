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


/** @file AGSPortalHelperServices.h */ //Required for Globals API doc

#import <Foundation/Foundation.h>

#import "AGSElevationServiceInfo.h"

NS_ASSUME_NONNULL_BEGIN

/** @brief Services provided by an organization's portal.
 
 Instances of this class provide information about the various services provided
 by an organization's portal.
 
 @since 100
 */
@interface AGSPortalHelperServices : NSObject

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

#pragma mark -
#pragma mark properties

/** Geoprocessing service that performs analyses
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *analysisServiceURL;

/** Geoprocessing service for asynchronous closest-facility analysis
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *asyncClosestFacilityServiceURL;

/** Geoprocessing service for asynchronous location-allocation network analysis.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *asyncLocationAllocationServiceURL;

/** Geoprocessing service for generating origin-destination cost matrices asynchronously.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *asyncODCostMatrixServiceURL;

/** Geoprocessing service for asynchronous service-area analysis
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *asyncServiceAreaServiceURL;

/** Geoprocessing service for solving asynchronous vehicle routing problems.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *asyncVRPServiceURL;

/** Network Analyst service for synchronous closest-facility analysis.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *closestFacilityServiceURL;

/**
 Information about Limited Error Raster Compression (LERC) elevation services
 used by ArcGIS Pro and the Web Scene Viewer.
 
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSArray<AGSElevationServiceInfo *> *defaultElevationServices;

/** Geoprocessing service for elevation analysis.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *elevationServiceURL;

/** Geoprocessing service for elevation analysis.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *elevationSyncServiceURL;

/** Geocoding services to use for geocoding.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<NSURL*> *geocodeServiceURLs;

/** Geoenrichment services for getting facts about a location or area.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *geoenrichmentServiceURL;

/**  Geometry service to use for geometry functions.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *geometryServiceURL;

/** Geoprocessing service for hydrologic analysis.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *hydrologyServiceURL;

/**
 The URL of the location tracking service.
 
 @since 100.5
 */
@property (nullable, nonatomic, strong, readonly) NSURL *locationTrackingServiceURL;

/** Print Task service to use for printing functionality.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *printTaskURL;

/** Geoprocessing service for asynchronous route analysis.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *routeServiceURL;

/** Network Analyst service for service-area analysis
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *serviceAreaServiceURL;

/** Geoprocessing service for solving synchronous vehicle routing problems.

 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *syncVRPServiceURL;

/** Map service for displaying traffic speeds and traffic incidents.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *trafficServiceURL;

#pragma mark -
#pragma mark methods

@end

@interface AGSPortalHelperServices (AGSDeprecated)

/** Limited Error Raster Compression (LERC) elevation service to use as a surface for 3D scenes
 @since 100
 @deprecated 100.5. This property has never been populated. Use
 AGSPortalHelperServices#defaultElevationServices to access the 3D elevation
 service URLs.
 */
@property (nullable, nonatomic, strong, readonly) NSURL *elevation3DServiceURL __attribute__((deprecated("Use 'defaultElevationServices' instead.")));

@end

NS_ASSUME_NONNULL_END
