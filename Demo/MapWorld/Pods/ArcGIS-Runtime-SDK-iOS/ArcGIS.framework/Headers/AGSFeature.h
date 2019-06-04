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
#import "AGSGeoElement.h"

@class AGSField;
@class AGSFeatureTable;
@class AGSGeometry;

/** @file AGSFeature.h */ //Required for Globals API doc

/** @brief Represents a geographic feature on a map
 
 Instances of this class represent a geographic feature on a map. 
 
 A feature can contain a set of attributes (key-value pairs) providing more
 information about the real-world entity it represents. Attribute types supported are NSNull, NSString, NSDate, and NSNumber.
 All other attribute types will be ignored. A feature can also have a geometry which describes the location and the shape of the
 entity.

 @since 100
 */
@interface AGSFeature : AGSObject <AGSGeoElement>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The dataset that this feature belongs to
 @since 100
 */
@property (nullable, nonatomic, weak, readonly) AGSFeatureTable *featureTable;

/** A dictionary containing all the attributes.
 Attribute types supported are NSNull, NSString, NSDate, and NSNumber.
 Other attribute types will be ignored.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString*,id> *attributes;

/** The geometry that defines shape and location.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSGeometry *geometry;

#pragma mark -
#pragma mark methods

/** Resets the attributes and geometry to the values in the data source. This will discards any in-memory changes to the feature that
 have not been applied to the table, and reloads the feature geometry and all attributes.
 @return a value indicating whether the geometry or attributes were updated.
 @since 100.4
 */
-(BOOL)refresh;

NS_ASSUME_NONNULL_END

@end
