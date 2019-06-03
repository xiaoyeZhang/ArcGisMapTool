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

@class AGSFeatureEditResult;

/** @file AGSOfflineMapSyncLayerResult.h */ //Required for Globals API doc

/** @brief Result of a sync operation for a map layer or table initiated by `AGSOfflineMapSyncJob`
 
 Instances of this class represent results of a sync operation for a particular offline map layer or table initiated by `AGSOfflineMapSyncJob`. If the entire operation failed, for instance due to network interruption, the `#error` property is popluated. However, if the opeartion completed successfully, but certain edits could not be synchronized, those details are provided in `#editErrors`.
 

 @since 100.1
 */
@interface AGSOfflineMapSyncLayerResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties


/** Information about the individual edits that could not be synchronized. Only happens on rare occasions when the service cannot reconcile edits in its current state, or if those edits violate some service constraints. 
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureEditResult*> *editErrors;

/** Returns an error if the entire sync operation failed, for instance, due to a network interruption.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) NSError *error;

/** Indicates if any errors were encountered while syncronizing an offline map's layer or table. If `true` you should inspect `#error` and `#editErrors` to find out if the whole sync operation failed due to an error ,for example, a network interruption, or if only certain edits could not be synchronized but the overall sync operation completed.
 If `false`, it means the sync opeation completed without any errors.
 @since 100.1
*/
@property (nonatomic, assign, readonly) BOOL hasErrors;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
