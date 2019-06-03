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

@class AGSFeatureTemplate;
@class AGSDomain;

/** @file AGSFeatureType.h */ //Required for Globals API doc

/** @brief Encapsulates properties of types of features in a feature layer.
 
 Instances of this class represent a feature type. A feature type describes the
 various types of features that can belong to a feature layer.
 @since 100
 @see (A quick tour of subtypes)[http://resources.arcgis.com/en/help/main/10.2/index.html#//005r00000001000000]
 */
@interface AGSFeatureType : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The ID of this type.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) id typeID;

/** The name of this type.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Templates that can be used for creating new features of this type.
 This property is an array of @c AGSFeatureTemplate objects.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureTemplate*> *templates;

/** Domains describing permissible attribute values for features of this type.
 This property is a dictionary containing key-value pairs of field name and a
 corresponding @c AGSDomain object for this type.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary<NSString*,AGSDomain*> *domains;

NS_ASSUME_NONNULL_END

@end
