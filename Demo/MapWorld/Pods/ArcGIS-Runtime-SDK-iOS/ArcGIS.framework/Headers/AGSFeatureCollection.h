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

#import "AGSLoadableBase.h"

@class AGSItem;
@class AGSFeatureCollectionTable;
@class AGSPortal;
@class AGSPortalFolder;

/** @file AGSFeatureCollection.h */ //Required for Globals API doc

/** @brief A lightweight collection of features
 
 Instances of this class represent a lightweight collection of features. The features in the collection are organized into tables, where all the features that belong to a table share the same attribute schema (fields), geometry type, and spatial reference.
 The feature collection may be created and stored as part of a map or as a separate item (of type `AGSPortalItemTypeFeatureCollection`) on ArcGIS Portal. You can also programmatically create an empty feature collection and then add tables and features to it.
 @since 100
 @see `AGSFeatureCollectionLayer` to display features in the feature collection on a map or a scene. 
 */
@interface AGSFeatureCollection : AGSLoadableBase <AGSJSONSerializable>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize the feature collection with the provided item. The item must be of type `AGSPortalItemTypeFeatureCollection`
 @param item of type `AGSPortalItemTypeFeatureCollection` that represents the feature collection
 @return Initialized feature collection
 @since 100
 */
-(instancetype)initWithItem:(AGSItem*)item;

/** Initialize the feature collection with the provided feature collection tables
 @param featureCollectionTables containing tables which organize the features for the feature collection
 @return Initialized feature collection
 @since 100
 */
-(instancetype)initWithFeatureCollectionTables:(NSArray<AGSFeatureCollectionTable*>*)featureCollectionTables;

/**Initialize an empty feature collection to which feature collection tables can be added
 @return Initialized feature collection
 @since 100
 */
+(instancetype)featureCollection;

/** Initialize the feature collection with the provided item. The item must be of type `AGSPortalItemTypeFeatureCollection`
 @param item of type `AGSPortalItemTypeFeatureCollection` that represents the feature collection
 @return Initialized feature collection
 @since 100
 */
+(instancetype)featureCollectionWithItem:(AGSItem*)item;

/** Initialize the feature collection with the provided feature collection tables
 @param featureCollectionTables containing tables which organize the features for the feature collection
 @return Initialized feature collection
 @since 100
 */
+(instancetype)featureCollectionWithFeatureCollectionTables:(NSArray<AGSFeatureCollectionTable*>*)featureCollectionTables;

#pragma mark -
#pragma mark properties

/** The item that this feature collection represents.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSItem *item;

/** The individual tables that are part of this feature collection. The tables provide a way to organize and group features that have the attribute schema (fields), geometry type, and spatial reference.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSFeatureCollectionTable*> *tables;

#pragma mark -
#pragma mark methods

#pragma mark - Save/SaveAs

/** Saves this feature collection as a new feature collection item on the specified portal with the given title in the given folder.
 Once completed, the feature collection's `#item` property will be populated with the new portal item.
 Note that if the feature collection already has a valid item property (either because the feature collection was created using an item or was previously saved),
 that property will be replaced with a new item, effecitively 'duplicating' the feature collection on the portal.
 @param title The title of the feature collection.  Cannot be nil.
 @param portal The portal to save the feature collection to.
 @param folder The folder in which to save the feature collection. If nil is passed it will be added to the user's root folder.
 @param tags The tags to be associated with the newly created portal item.
 @param thumbnail The thumbnail of the feature collection. The recommended thumbnail image size is 200 pixels wide by 133 pixels high. Acceptable image formats are PNG, GIF, and JPEG with a maximum file size of 1 MB
 @param itemDescription The description of the feature collection.
 @param completion The block that is invoked when operation finishes.
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)saveAs:(NSString *)title
                    portal:(AGSPortal *)portal
                      tags:(NSArray<NSString*> *)tags
                    folder:(nullable AGSPortalFolder *)folder
           itemDescription:(NSString*)itemDescription
                 thumbnail:(nullable AGSImage *)thumbnail
                completion:(nullable void(^)(NSError* __nullable error))completion;

/** Saves this feature collection back to the item it originated from.  Upon completion, the item's data will have been updated with the feature collection.
 An error will occur if the feature collection does not have a valid `#item` property.  A feature collection has a valid item property if it was created using `#initWithItem:`,
 or has been previously saved as a new item using `#saveAs:portal:tags:folder:itemDescription:thumbnail:completion:`.
 @warning This will overwrite contents of the existing feature collection item.
 @param completion block that is invoked when operation finishes.
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)saveWithCompletion:(nullable void(^)(NSError* __nullable error))completion;

NS_ASSUME_NONNULL_END

@end
