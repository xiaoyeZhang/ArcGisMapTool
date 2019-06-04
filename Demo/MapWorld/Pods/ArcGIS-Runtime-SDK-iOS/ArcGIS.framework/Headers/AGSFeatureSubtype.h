/*
 COPYRIGHT 2018 ESRI
 
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

@class AGSDomain;

/** @file AGSFeatureSubtype.h */ //Required for Globals API doc

/** @brief Encapsulates properties of types of features in a feature layer.
 
 Instances of this class represent a feature subtype. A feature subtype describes the
 various types of features that can belong to a feature layer.
 @since 100.3
 @see (A quick tour of subtypes)[http://resources.arcgis.com/en/help/main/10.2/index.html#//005r00000001000000]
 */
@interface AGSFeatureSubtype : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The code used by this subtype.
 @since 100.3
 */
@property (nullable, nonatomic, copy, readonly) id code;

/** Domains describing permissible attribute values for features of this subtype.
 This property is a dictionary containing key-value pairs of field name and a
 corresponding @c AGSDomain object for this type.
 @since 100.3
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString*,AGSDomain*> *domains;

/** The name of this subtype.
 @since 100.3
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Prototypical attrbutes used for creating new features for this subtype
 @since 100.3
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString*,id> *prototypeAttributes;

#pragma mark -
#pragma mark methods


NS_ASSUME_NONNULL_END

@end
