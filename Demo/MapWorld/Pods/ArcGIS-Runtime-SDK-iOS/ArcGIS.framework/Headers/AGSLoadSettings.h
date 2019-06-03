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

/** @file AGSLoadSettings.h */ //Required for Globals API doc

/** @brief Settings for layers in a Map or Scene
 
 Instances of this class represent settings that are applied to layers while loading a map or a scene. Making changes to these settings does not affect maps or scenes that have already been loaded.
 
 @since 100.2
 */
@interface AGSLoadSettings : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)loadSettings;

#pragma mark -
#pragma mark properties

/** Preferred rendering mode for feature layers containing point features. Defaults to `Automatic`
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSFeatureRenderingMode preferredPointFeatureRenderingMode;

/** Preferred rendering mode for feature layers containing polygon features. Defaults to `Automatic`
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSFeatureRenderingMode preferredPolygonFeatureRenderingMode;

/** Preferred rendering mode for feature layers containing polyline features. Defaults to `Automatic`
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSFeatureRenderingMode preferredPolylineFeatureRenderingMode;

/** Indicates whether feature layers should be visualized using advanced CIM symbols.
 The default is `true`. Servers which don't support this simply ignore
 the parameter and return regular symbols instead.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL useAdvancedSymbology;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

