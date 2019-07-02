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

//#import "AGSObject.h"

/** @file AGSSelectionProperties.h */ //Required for Globals API doc

/** @brief Selection properties of an `AGSGeoView`
 
 Instances of this class specify how to visually differentiate content in an `AGSMapView` or `AGSSceneView` that has been selected.
 
 @see `AGSGraphicsOverlay#selectGraphics:` to select content in a graphics overlay
 @see `AGSFeatureLayer#selectFeatures:` to select content in a feature layer
 @since 100.4
 */
@interface AGSSelectionProperties : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize an instance of selection properties
 @return an instance of selection properties
 @since 100.4
 */
+(instancetype)selectionProperties;

/** Initialize the selection properties with the specified color
 @param color to use for displaying selected content
 @return initialized selection properties
 @since 100.4
 */
-(instancetype)initWithColor:(AGSColor*)color;

/** Initialize the selection properties with the specified color
 @param color to use for displaying selected content
 @return initialized selection properties
 @since 100.4
 */
+(instancetype)selectionPropertiesWithColor:(AGSColor*)color;

#pragma mark -
#pragma mark properties 

/** The color to use for drawing a halo around selected content. Defaults to cyan color.
 @since 100.4
 */
@property (nonatomic, strong, readwrite) AGSColor *color;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
