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
#import "AGSLoadableBase.h"
#import "AGSLayerContent.h"
#import "AGSPopupSource.h"

@class AGSPopupDefinition;
@class AGSArcGISMapServiceSublayerInfo;
@class AGSRenderer;

/** @file AGSArcGISSublayer.h */ //Required for Globals API doc

/** @brief Information about an individual layer or table in ArcGIS Map Service.
 
 Instances of this class represent information about an individual layer or table in an ArcGIS Map Service.
 
 @since 100
 */

@interface AGSArcGISSublayer : AGSLoadableBase <AGSLayerContent, AGSPopupSource, NSCopying>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers
 
#pragma mark -
#pragma mark properties

/** The definition expression in the syntax of a SQL where clause by which to limit which features are displayed for the sublayer.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *definitionExpression;

/** Information about the source this sublayer originates from.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSArcGISMapServiceSublayerInfo *mapServiceSublayerInfo;

/** The opacity of this sublayer as a value between 0 (fully transparent) and 1 (fully opaque).
 @since 100.1
 */
@property (nonatomic, assign, readonly) float opacity;

/** The renderer specifying how the features should be symbolized
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSRenderer *renderer;

/** Indicates whether the sublayer renderers its symbols based on a reference scale. If enabled, symbols are resized when the map's scale changes.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL scaleSymbols;

/** Indicates whether the sublayer's labels are turned on/off.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL labelsEnabled;

/** The ID of this sublayer.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger sublayerID;

/** This sublayer's max scale.
 @since 100
 */
@property (nonatomic, assign, readonly) double maxScale;

/** This sublayer's min scale.
 @since 100
 */
@property (nonatomic, assign, readonly) double minScale;

/** This sublayer's nested (child) sublayers.
 @note This array does not allow duplicate objects.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSArcGISSublayer*> *sublayers;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
