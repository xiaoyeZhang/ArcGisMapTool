/*
 COPYRIGHT 2019 ESRI
 
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

/** @file AGSWFSLayerInfo.h */ //Required for Globals API doc

#import "AGSObject.h"

@class AGSEnvelope;

NS_ASSUME_NONNULL_BEGIN

/** @brief An object that represents the WFS Layer info.
 
 Provides metadata (e.g name, title, description, and more) about a WFS feature type.
 @since 100.5
 */
@interface AGSWFSLayerInfo : AGSObject

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

#pragma mark -
#pragma mark properties

/** The layer's description.
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSString *layerDescription;

/** The WFS layer's extent.
 @since 100.5
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *extent;

/** The keywords describing the layer.
 The keywords are returned in an @c NSArray<T> of @c NSString.
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *keywords;

/** The layer's uniquely-identifying name.
 Layers from a @c AGSWFSService, described by @c AGSWFSLayerInfo objects, represent the "feature types" defined in the WFS standard.
 WFS layers have both a uniquely-identifying name and a human-readable title.
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSString *name;

/** The supported spatial references.
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSArray<AGSSpatialReference*> *spatialReferences;

/** The layer's title.
 The title property is intended for use as a human-readable layer identification. See @c name for a unique identifier.
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSString *title;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END

