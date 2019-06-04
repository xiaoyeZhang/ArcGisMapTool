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
#import "AGSFeature.h"
#import "AGSLoadable.h"

@class AGSAttachment;
@class AGSRelationshipInfo;

/** @file AGSArcGISFeature.h */ //Required for Globals API doc

/** @brief Represents a geographic feature in an ArcGIS Geodatabase
 
 Instances of this class represent geographic features that specifically originate from an ArcGIS Geodatabase.
 
 A feature can contain a set of attributes (key-value pairs) providing more
 information about the real-world entity it represents. Attribute types supported are  NSNull, NSString, NSDate, and NSNumber.
 All other attribute types will be ignored. A feature can also have a geometry which describes the location and the shape of the. A feature can also have additional data associated with it in the form of picture, video, or document attachments.
 entity.

 @since 100
 */
@interface AGSArcGISFeature : AGSFeature <AGSLoadable>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));


#pragma mark -
#pragma mark properties

/** Indicates whether the feature's attachments can be edited.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL canEditAttachments;

/** Indicates whether the feature's geometry can be updated.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL canUpdateGeometry;

#pragma mark -
#pragma mark methods

/** Refreshes the ObjectID and GlobalID attributes of this feature by fetching them again from the geodatabase on disk. This is useful when you create a new feature and add it to the service but still keep holding on to the original reference you got when you created the feature. The original reference does not automatically get the new IDs it was assigned by the service. You can call this method to update the reference with the new IDs.  
 @since 100
 @deprecated 100.4. Use `AGSFeature#refresh` instead.
 */
-(BOOL)refreshObjectID __deprecated_msg("Please use -[AGSFeature refresh]");

/** Adds a new attachment for the feature
 @param name of the attachment
 @param contentType The MIME type of the attachment
 @param data representing the attachment's content
 @param completion block that is invoked when operation completes.
 @return operation which can be canceled
 @license{Basic, when editing a local mobile geodatabase or a private feature service. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)addAttachmentWithName:(NSString *)name
                               contentType:(NSString *)contentType
                                      data:(NSData *)data
                                completion:(nullable void(^)(AGSAttachment *__nullable result, NSError *__nullable error))completion;

/** Delete an existing attachment of this feature.
 @param attachment to be deleted
 @param completion block that is invoked when the operation completes
 @return operation which can be canceled
 @license{Basic, when editing a local mobile geodatabase or a private feature service. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)deleteAttachment:(AGSAttachment *)attachment
                           completion:(nullable void(^)(NSError *__nullable error))completion;

/** Delete a set of existing attachments of this feature.
 @param attachments to be deleted as an array of `AGSAttachment` objects
 @param completion block that is invoked when the operation completes
 @return operation which can be canceled
 @license{Basic, when editing a local mobile geodatabase or a private feature service. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)deleteAttachments:(NSArray<AGSAttachment*> *)attachments
                            completion:(nullable void(^)(NSError *__nullable error))completion;


/**
 Fetch information about attachments that belong to this feature.
 @param completion block that is called when the operation is complete. The attachments are passed in as an array of @c AGSAttachment objects.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchAttachmentsWithCompletion:(nullable void(^)(NSArray<AGSAttachment*> *__nullable result, NSError *__nullable error))completion;

/** Update an existing attachment of the feature
 @param attachment The attachment to update
 @param name The new name of the attachment
 @param contentType The new MIME type
 @param data The new data
 @param completion block that is invoked when the operation completes
 @return operation which can be canceled
 @license{Basic, when editing a local mobile geodatabase or a private feature service. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)updateAttachment:(AGSAttachment *)attachment
                                 name:(NSString *)name
                          contentType:(NSString *)contentType
                                 data:(NSData*)data
                           completion:(nullable void(^)(NSError *__nullable error))completion;

/** Relates this feature to the provided feature if their owning feature tables are related (see `AGSArcGISFeatureTable#relatedTables`).
 The relationship between the features is established by updating the destination feature's attribute on which the relationship is based.

 @note You must commit this change to the feature table using `AGSFeatureTable#addFeature:completion:` or `AGSFeatureTable#updateFeature:completion:` to finish relating the features. After committing the change, you can use `AGSArcGISFeatureTable#validateRelationshipConstraintsForFeature:completion:` to check if any relationship constraints have been violated.
 
 If the relationship is keyed on an Object ID or Global ID, and the origin feature in this call has been newly created and added to a service feature table, you must first call `AGSServiceFeatureTable#applyEditsWithCompletion:` after the feature is added and then `AGSFeature#refresh` to obtain the new Object ID and Global ID generated by the service for the origin feature. If this is not done, then the destination feature will end up referring to an outdated ID and will not be considered related.
 
 @param feature that this feature needs to be related to
 @since 100.1
 */
-(void)relateToFeature:(AGSArcGISFeature *)feature;

/** Relates this feature to the provided feature if their owning feature tables are related through the specified relationship (see `AGSArcGISFeatureTable#relatedTablesWithRelationshipInfo:`).
 The relationship between the features is established by updating the destination feature's attribute on which the relationship is based.
 
 @note You must commit this change to the feature table using `AGSFeatureTable#addFeature:completion:` or `AGSFeatureTable#updateFeature:completion:` to finish relating the features. After committing the change, you can use `AGSArcGISFeatureTable#validateRelationshipConstraintsForFeature:completion:` to check if any relationship constraints have been violated.

 If the relationship is keyed on an Object ID or Global ID, and the origin feature in this call has been newly created and added to a service feature table, you must first call `AGSServiceFeatureTable#applyEditsWithCompletion:` after the feature is added and then `AGSFeature#refresh` to obtain the new Object ID and Global ID generated by the service for the origin feature. If this is not done, then the destination feature will end up referring to an outdated ID and will not be considered related.
 
 @param feature that this feature needs to be related to
 @param relationshipInfo specifying how to relate the features
 @since 100.1
 */
-(void)relateToFeature:(AGSArcGISFeature *)feature relationshipInfo:(nullable AGSRelationshipInfo *)relationshipInfo;

/** Unrelates this feature to the provided feature

 @note You must commit this change to the feature table using `AGSFeatureTable#addFeature:completion:` or `AGSFeatureTable#updateFeature:completion:` to finish unrelating the features. After committing the change, you can use `AGSArcGISFeatureTable#validateRelationshipConstraintsForFeature:completion:` to check if any relationship constraints have been violated.
 
 @param feature that this feature needs to be unrelated to
 @since 100.1
 */
-(void)unrelateToFeature:(AGSArcGISFeature *)feature;

NS_ASSUME_NONNULL_END

@end
