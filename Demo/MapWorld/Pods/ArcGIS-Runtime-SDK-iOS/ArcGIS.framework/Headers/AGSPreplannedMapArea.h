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

@class AGSGeometry;
@class AGSPortalItem;

#import "AGSLoadableBase.h"

/** @file AGSPreplannedMapArea.h */ //Required for Globals API doc

/** @brief Represents an individual preplanned map area
 
 Instances of this class represent an individual preplanned map area.
 
 Preplanned map areas are specific work areas or major incident areas that are defined by a map author. Each map can contain a number of preplaned map areas. These can be retrieved using `AGSOfflineMapTask#getPreplannedMapAreasWithCompletion:`
 
 Each preplanned map area contains map content that is packaged and staged for easy download that speeds up the process of taking a map offline. Preplanned map areas can be downloaded to create an offline map using `AGSOfflineMapTask#downloadPreplannedOfflineMapJobWithArea:downloadDirectory:`
 
 @since 100.2
 */
@interface AGSPreplannedMapArea : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this preplanned map area the provided portal item representing a map area
 @param portalItem representing a map area
 @return Initialized preplanned map area
 @since 100.2
 */
-(instancetype)initWithPortalItem:(AGSPortalItem *)portalItem;

/** Initialize this preplanned map area the provided portal item representing a map area
 @param portalItem representing a map area
 @return Initialized preplanned map area
 @since 100.2
 */
+(instancetype)preplannedMapAreaWithPortalItem:(AGSPortalItem *)portalItem;

#pragma mark -
#pragma mark properties

/** Bounding box representing the region covered by this preplanned map area
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSGeometry *areaOfInterest;

/** Portal item representing a map area
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSPortalItem *portalItem;

#pragma mark -
#pragma mark methods

/** Retrieves a list of items representing map content for this preplanned map area, if there are any. The content items will be cached so the same instances will be returned with each subsequent call of this method.
 @param completion block that is invoked with the results if the operation succeeds, or an error if it fails
 @return operation that can be canceled
 @since 100.3
 */
-(id<AGSCancelable>)getContentItemsWithCompletion:(void(^)(NSArray<AGSPortalItem*> * __nullable contentItems, NSError * __nullable error))completion;
    
NS_ASSUME_NONNULL_END

@end
