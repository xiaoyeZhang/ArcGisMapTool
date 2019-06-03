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

@class AGSFeatureServiceCapabilities;
@class AGSDrawingInfo;
@class AGSFeatureSubtype;
@class AGSEnvelope;
@class AGSOwnershipBasedAccessControlInfo;
@class AGSLayerTimeInfo;
@class AGSFeatureType;
@class AGSField;
@class AGSEditFieldsInfo;
@class AGSFeatureTemplate;
@class AGSRelationshipInfo;

#import "AGSLoadableBase.h"

/** @file AGSArcGISFeatureLayerInfo.h */ //Required for Globals API doc

/** @brief Information about an individual layer or table in ArcGIS Feature Service.
 
 Instances of this class represent information about an individual layer or table in an ArcGIS Feature Service.
 
 @since 100
 */
@interface AGSArcGISFeatureLayerInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The URL of the ArcGIS Feature service layer.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *URL;

/** The ID of the layer or table in the service.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger serviceLayerID;

/** Indicates whether geometry of existing features can be updated
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allowGeometryUpdates;

/** Attribution information
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *attribution;

/** Capabilities supported by the service
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSFeatureServiceCapabilities *capabilities;

/** Indicates whether data in the service is versioned
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL dataVersioned;

/** The code for the default feature subtype of this sublayer
 @since 100.3
 */
@property (nullable, nonatomic, copy, readonly) id defaultSubtypeCode;

/** Default visibility state 
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isVisibleByDefault) BOOL visibleByDefault;

/** Defaut z-values for features created without a valid z-value. Only applicable if `#zDefaultsEnabled` is true.
 @since 100
 */
@property (nonatomic, assign, readonly) double zDefault;

/** Indicates whether a default z-value will be applied for features created without a z-value
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL zDefaultsEnabled;

/* Description of the layer/table in the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *layerDescription;

/** The field which should be used to display a title for features in the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *displayFieldName;

/** Information about how features in the service should be displayed on a map
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSDrawingInfo *drawingInfo;

/** Metadata specifying which fields or attributes of a feature contain information
 about who created/edited the feature and when was it created/edited.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSEditFieldsInfo *editFieldsInfo;

/** The maximum scale at which this layer or any of its parents is visible. If the map is zoomed in beyond this scale, the layer will not be visible.
 @since 100
 */
@property (nonatomic, assign, readonly) double effectiveMaxScale;

/** The minimum scale at which this layer or any of its parents is visible. If the map is zoomed out beyond this scale, the layer will not be visible.
 @since 100
 */
@property (nonatomic, assign, readonly) double effectiveMinScale;

/** The geographic extent this layer covers
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *extent;

/** The attribute fields (columns) available in data. The property is an
 array of @c AGSField objects. 
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSField *> *fields;

/** The type of geometry contained by features in the service
 @since 100
 */
@property (nonatomic, assign, readonly) AGSGeometryType geometryType;

/** The name of field which contains the @em GLOBALID for each feature
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *globalIDFieldName;

/** Indicates whether features may have attachments.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasAttachments;

/** Indicates whether features may contain M values
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasM;

/** Indicates whether features may contain Z values
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasZ;

/** The maximum number of results returned by the service for any query operation
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger maxRecordCount;

/** The maximum scale at which this layer is visible. If the map is zoomed in beyond this scale, the layer will not be visible.
 @since 100
 */
@property (nonatomic, assign, readonly) double maxScale;

/** The minimum scale at which this layer is visible. If the map is zoomed out beyond this scale, the layer will not be visible.
 @since 100
 */
@property (nonatomic, assign, readonly) double minScale;

/** The name of the layer/table in the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *serviceLayerName;

/** The name of field which contains the @em OBJECTID for each feature
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *objectIDFieldName;

/** The service type of layer info.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSArcGISFeatureLayerInfoServiceType serviceType;

/** Information about ownership-based access policies governing who can edit, delete, and query features.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSOwnershipBasedAccessControlInfo *ownershipBasedAccessControl;

/** Information about this layer's relationships with other layers or tables in the ArcGIS Service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSRelationshipInfo*> *relationshipInfos;

/** A collection of @c AGSFeatureType objects representing feature sub-types in
 the layer. For example, a @em roads layer may contain 2 feature sub-types : highways
 and streets.
 @avail{10.0}
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureType*> *featureTypes;

/** The type of service this layer came from.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSServiceType serviceSourceType;

/** The name of the field which contains the sub-type information for each feature in this sublayer
 @see `#featureSubtypes`
 @since 100.3
 */
@property (nonatomic, copy, readonly) NSString *subtypeField;

/** Indicates whether the service support advanced query operations (such as ordering results, or returning distinct results)
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsAdvancedQueries;

/** Indicates whether the service supports ownership-based access control for anonymous users
 @since 100.3
 */
@property (nonatomic, assign, readonly) BOOL supportsOBACForAnonymousUsers;

/** Indicates whether the service supports querying
 @since 100.2
 */
@property (nonatomic, assign, readonly) BOOL supportsQueryExtent;

/** Indicates whether the service supports queries that can be use to limit the number of results returned and paginate the results.
 @since 100.2
 */
@property (nonatomic, assign, readonly) BOOL supportsPagination;

/** Indicates whether the service is capable of rolling back all edit operations in a batch if any one of the operations in the batch fails
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsRollbackOnFailureParameter;

/** Indicates whether the service is capable of returning statistics for query results
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsStatistics;

/** The list of feature subtypes available for this sublayer. For example, a @em roads sublayer may contain 2 feature sub-types : highways and streets.
 @since 100.3
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureSubtype*> *featureSubtypes;

/** A collection of @c AGSFeatureTemplate objects representing feature templates
 for the layer. Usually only present if the layer does not contain feature
 sub-types. Only applicable if this dataset is based on an ArcGIS Feature
 Service.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureTemplate*> *featureTemplates;

/** Time information for the layer, such as start time field, end time field,
 track id field, layers time extent and the draw time interval. Only applicable
 if the layer is time aware.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLayerTimeInfo *timeInfo;

/** The name of the field which contains the sub-type information for each feature.
 @avail{10.0}
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *typeIDFieldName;

/** The version of the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *version;

/** The layer's CIM (Cartographic Information Model) version.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *CIMVersion;

#pragma mark -
#pragma mark methods


/** Convenience method to find a field with the given name
 @param name The name of the field.
 @return field
 @since 100
 */
-(nullable AGSField*)fieldWithName:(NSString*)name;

/** Convenience method to find feature type with the given name
 @param name The name of the feature type.
 @return feature type
 @since 100
 */
-(nullable AGSFeatureType*)featureTypeWithName:(NSString*)name;

NS_ASSUME_NONNULL_END

@end
