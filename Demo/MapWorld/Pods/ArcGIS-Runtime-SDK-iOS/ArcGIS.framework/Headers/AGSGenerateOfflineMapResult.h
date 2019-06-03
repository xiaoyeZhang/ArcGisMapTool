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

@class AGSMap;
@class AGSMobileMapPackage;
@class AGSLayer;
@class AGSFeatureTable;

/** @file AGSGenerateOfflineMapResult.h */ //Required for Globals API doc

/** @brief Results of taking a map offline
 
 Instances of this class represent the results of taking a map offline.
 
 @see `AGSOfflineMapTask` to take a map offline
 @since 100.1
 */
@interface AGSGenerateOfflineMapResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The offline map.
 @since 100.1
 */
@property (nonatomic, strong, readonly) AGSMap *offlineMap;

/** Indicates if any errors were encountered while taking the map offline.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL hasErrors;

/** The errors that were encountered while taking the map's layers offline.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSDictionary<AGSLayer *, id> *layerErrors;

/** The errors that were encountered while taking the map's tables offline.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSDictionary<AGSFeatureTable*, id> *tableErrors;

/** The mobile map package on disk (in exploded format) that contains the `#offlineMap`
 @since 100.1
 */
@property (nonatomic, strong, readonly) AGSMobileMapPackage *mobileMapPackage;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END
