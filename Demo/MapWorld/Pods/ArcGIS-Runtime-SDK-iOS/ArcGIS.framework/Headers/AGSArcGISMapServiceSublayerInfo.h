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

@class AGSArcGISMapServiceCapabilities;
@class AGSDrawingInfo;
@class AGSFeatureType;
@class AGSField;
@class AGSOwnershipBasedAccessControlInfo;
@class AGSFeatureSubtype;
@class AGSEnvelope;
@class AGSLayerTimeInfo;
@class AGSIDInfo;
@class AGSRelationshipInfo;

/** @file AGSArcGISMapServiceSublayerInfo.h */ //Required for Globals API doc

/** @brief Information about an individual sublayer in an ArcGIS Map Service.
 
 Instances of this class represent information about an individual sublayer in an ArcGIS Map Service.
 
 @since 100.1
 */
@interface AGSArcGISMapServiceSublayerInfo : AGSObject <AGSJSONSerializable>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The URL of the ArcGIS Map Service sublayer.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) NSURL *URL;

/** Attribution information of the sublayer
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *attribution;

/** Indicates whether the sublayer supports modifying its renderer and/or its data source.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL canModifyLayer;

/** Indicates whether the text and symbols on the sublayer will be resized as the map scale varies.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL canScaleSymbols;

/** Capabilities of the ArcGIS Map Service that this sublayer belongs to
 @since 100.1
 */
@property (nonatomic, strong, readonly) AGSArcGISMapServiceCapabilities *capabilities;

/** The code for the default feature subtype of this sublayer
 @since 100.3
 */
@property (nullable, nonatomic, copy, readonly) id defaultSubtypeCode;

/** Indicates whether the sublayer is visible or not by default
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL defaultVisibility;

/** The definition expression in the syntax of a SQL where clause by which to limit which features are displayed for the sublayer.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *definitionExpression;

/** Description of the ArcGIS Map Service that this sublayer belongs to
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *serviceDescription;

/** The field which should be used to display a title for features in this sublayer
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *displayFieldName;

/** Information about how features in the sublayer should be displayed
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSDrawingInfo *drawingInfo;

/** The maximum scale at which this sublayer or any of its parents is visible. If the map is zoomed in beyond this scale, the sublayer will not be visible.
 @since 100.1
 */
@property (nonatomic, assign, readonly) double effectiveMaxScale;

/** The minimum scale at which this sublayer or any of its parents is visible. If the map is zoomed out beyond this scale, the sublayer will not be visible.
 @since 100.1
 */
@property (nonatomic, assign, readonly) double effectiveMinScale;

/** The geographic extent this sublayer covers
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *extent;

/** The list of feature subtypes available for this sublayer. For example, a @em roads sublayer may contain 2 feature sub-types : highways and streets.
 @since 100.3
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureSubtype*> *featureSubtypes;

/** A collection of @c AGSFeatureType objects representing feature sub-types in
 the sublayer. For example, a @em roads sublayer may contain 2 feature sub-types : highways
 and streets.
 @avail{10.0}
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureType*> *featureTypes;

/** The attribute fields (columns) available in this sublayer's data. The property is an
 array of @c AGSField objects.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSField*> *fields;

/** The type of geometry contained by features in the sublayer.
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSGeometryType geometryType;

/** Indicates whether features may have attachments.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL hasAttachments;

/** Indicates whether this sublayer has labels defined.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL hasLabels;

/** Indicates whether features may contain M values
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL hasM;

/** Indicates whether features may contain Z values
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL hasZ;

/** Indicates whether data in the service is versioned
 @since 100.1
 */
@property (nonatomic, assign, readonly, getter=isDataVersioned) BOOL dataVersioned;

/** The maximum number of results returned by the service for any query operation
 @since 100.1
 */
@property (nonatomic, assign, readonly) long long maxRecordCount;

/** The maximum scale at which this sublayer is visible. If the map is zoomed in beyond this scale, the sublayer will not be visible.
 @since 100.1
 @see `#effectiveMaxScale`
 */
@property (nonatomic, assign, readonly) double maxScale;

/** The minimum scale at which this sublayer is visible. If the map is zoomed out beyond this scale, the sublayer will not be visible.
 @since 100.1
 @see `#effectiveMinScale`
 */
@property (nonatomic, assign, readonly) double minScale;

/** Information about ownership-based access policies governing who can edit, delete, and query features.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSOwnershipBasedAccessControlInfo *ownershipBasedAccessControl;

/** Information about this sublayer's parent sublayer. If nil, the sublayer has no parent and is at the root of the ArcGIS Map Service.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSIDInfo *parentLayerInfo;

/** Information about this sublayer's relationships with other sublayers in the ArcGIS Map Service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSRelationshipInfo*> *relationshipInfos;

/** ID of the sublayer in the ArcGIS Map Service.
 @since 100.1
 */
@property (nonatomic, assign, readonly) NSInteger serviceLayerID;

/** Name of the sublayer in the ArcGIS Map Service.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *serviceLayerName;

/** The type of sublayer in the ArcGIS Map Service
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSArcGISMapServiceSublayerType sublayerType;

/** The name of the field which contains the sub-type information for each feature in this sublayer
 @see `#featureSubtypes`
 @since 100.3
 */
@property (nonatomic, copy, readonly) NSString *subtypeField;

/** Information about this sublayer's nested (child) sublayers.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSIDInfo *> *sublayerInfos;

/** Indicates whether the sublayer supports order-by and group-by functions in query operations.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL supportsAdvancedQueries;

/** Indicates whether the sublayer supports statistical functions in query operations.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL supportsStatistics;

/** Time information for the sublayer, such as start time field, end time field,
 track id field, layers time extent and the draw time interval. Only applicable
 if the sublayer is time aware.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSLayerTimeInfo *timeInfo;

/** The name of the field which contains the sub-type information for each feature.
 @avail{10.0}
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *typeIDFieldName;

/** Indicates whether the sublayer requires the use of standardized queries to help prevent SQL injection attacks.
 @avail{10.0}
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL useStandardizedQueries;

/** The version of the ArcGIS Map Service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *version;


#pragma mark -
#pragma mark methods


/** Convenience method to retrieve field by name from the `#fields` collection.
 @param name Name of a field to retrieve.
 @since 100.1
 */
-(nullable AGSField*)fieldWithName:(NSString *)name;

NS_ASSUME_NONNULL_END

@end
