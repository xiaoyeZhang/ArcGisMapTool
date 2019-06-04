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

/** @file AGSFeatureTemplate.h */ //Required for Globals API doc

/** @brief Represents all of the information needed to create a feature.
 
 Instances of this class represent a feature template. A feature template
 defines all the information required to create a feature: the layer where a
 feature will be stored and the attributes a feature is created with.
 
 @since 100
 */
@interface AGSFeatureTemplate : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Supported drawing tool to create a feature.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSDrawingTool drawingTool;

/** Description of the template.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *featureDescription;

/** Name of the template.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

/** The attributes of a prototypical feature associated with the template. The template specifies
 default values for many of the attributes and can be used to
 easily create new features.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary<NSString*,id> *prototypeAttributes;

NS_ASSUME_NONNULL_END

@end
