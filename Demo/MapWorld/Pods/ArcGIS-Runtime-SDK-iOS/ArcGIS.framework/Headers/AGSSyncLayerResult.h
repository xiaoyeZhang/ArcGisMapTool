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

#import "AGSObject.h"

@class AGSFeatureEditResult;

/** @file AGSSyncLayerResult.h */ //Required for Globals API doc

/** @brief Result of a sync operation by `AGSSyncGeodatabaseJob`
 
 Instances of this class represent results of a sync operation for a particular layer or table initiated by `AGSSyncGeodatabaseJob`
  
 @note This result object is only present if some edits could not be synchronized for that layer or table. See `#editResults`. The result does not not contain information about adds, deletes or updates performed successfully during the sync operation.
 
 @since 100
 */
@interface AGSSyncLayerResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The result of edits applied during the sync operation.
 @note This array only contains information about edits that could not be synchronized. Only happens on rare occasions when the service cannot reconcile edits in its current state, or if those edits violate some service constraints.
 If the array is empty, it should be assumed all edits could be synchronized properly and no edit errors were encountered during the sync process. There is no explicit information about adds, deletes or updates performed successfully during the sync operation
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureEditResult*> *editResults;

/** The ID of the layer in the feature service this result applies to.
 Same as `AGSArcGISFeatureLayerInfo#serviceLayerID` and `AGSLayer#layerID`
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger layerID;

/** The name of the table in the geodatabase this result applies to.
 Same as `AGSFeatureTable#tableName`.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *tableName;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
