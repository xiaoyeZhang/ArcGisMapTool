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


/** @file AGSRelationshipInfo.h */ //Required for Globals API doc

/** @brief Information about a feature table's relationship
 
 Instances of this class represent information about a relationship that a feature table participates in.

 A relationship consists of two and only two tables, each having one of these roles in the relationship:
 * Origin table, sometimes referred to as the source table or original table.
 * Destination table.
 
 
 A table can participate in more than one relationship. It may be an origin table in one relationship and a destination table in another relationship.
 
 The relationship's cardinality describes whether features in a table are related to only one feature in the other table, or whether a feature may be related to multiple features. 
 
 In a simple relationship, the features in the participating tables can exist without the other. For example, a transformer and an electric pole may be related but one's existence does not depend on the other. Deleting the origin features will simply disassociate the destination features from the origin features.
 
 In a composite relationship, the destination features cannot exist without the origin features. This means that each destination feature must be linked to a counterpart origin feature. When an origin feature is deleted, the related destination feature is deleted as well. This is called a cascade delete. The related feature is deleted on the client if it exists locally, otherwise it is deleted by the service when the origin feature's deletion is applied or synced to the service.  Edits that result in orphan features (A feature in the destination table that’s not related to origin feature) can be checked for constraint violation. For more info on checking constraint violations, and recovering from them, see `AGSArcGISFeature#validateRelationshipConstraintsForFeature:completion:`.
 
 
 @since 100.1
 */
@interface AGSRelationshipInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Cardinality of the relationship (from origin table to destination table). It describes whether features in the origin table are related to only one feature in the other table, or whether a feature may be related to multiple features.
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSRelationshipCardinality cardinality;

/** Unique identifier of the relationship
 @since 100.1
 */
@property (nonatomic, assign, readonly) NSInteger relationshipInfoID;

/** Indicates whether the relationship is composite or simple. 

  In a simple relationship, the features in the participating tables can exist without the other. For example, a transformer and an electric pole may be related but one's existence does not depend on the other. Deleting an origin feature will simply disassociate its related destination features. 
  
  In a composite relationship, the destination features cannot exist without the origin features. This means that each destination feature must be linked to a counterpart origin feature. When an origin feature is deleted, the related destination feature is deleted as well. This is called a cascade delete. The related feature is deleted on the client if it exists locally, otherwise it is deleted by the service when the origin feature's deletion is applied or synced to the service.  Edits that result in orphan features (A feature in the destination table that’s not related to origin feature) can be checked for constraint violation. For more info on checking constraint violations, and recovering from them, see `AGSArcGISFeature#validateRelationshipConstraintsForFeature:completion:`.
  
 @since 100.1
 */
@property (nonatomic, assign, readonly, getter=isComposite) BOOL composite;

/** Name of the key field that links the origin and destination tables of this relationship.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *keyField;

/** Name of the relationship.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Unique identifier of the related feature table specified by this relationship.
 @since 100.1
 */
@property (nonatomic, assign, readonly) NSInteger relatedTableID;

/** Role of the feature table in this relationship.
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSRelationshipRole role;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

