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

@class AGSLayer;
@class AGSMobileMapPackage;
@class AGSMap;

/** @file AGSDownloadPreplannedOfflineMapResult.h */ //Required for Globals API doc

/** @brief Results of taking a map offline using preplanned map areas
 
 Instances of this class represent the results of taking a map offline using preplanned map areas.
 
 @see `AGSOfflineMapTask` to take a map offline using preplanned map areas
 @since 100.2
 */
@interface AGSDownloadPreplannedOfflineMapResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates if any errors were encountered while taking the map offline.
 @since 100.2
 */
@property (nonatomic, assign, readonly) BOOL hasErrors;

/** The errors that were encountered while taking the map's layers offline.
 The keys in the dictionary are layer objects, and corresponding value is error encountered for that layer.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSDictionary<AGSLayer *, id> *layerErrors;

/** The mobile map package on disk (in exploded format) that contains the `#offlineMap`
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSMobileMapPackage *mobileMapPackage;

/** The offline map.
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSMap *offlineMap;

/** The errors that were encountered while taking the map's tables offline.
 The keys in the dictionary are table objects, and corresponding value is error encountered for that table.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSDictionary<AGSFeatureTable*, id> *tableErrors;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
