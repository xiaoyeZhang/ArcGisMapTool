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

@class AGSEnvelope;
@class AGSWMTSTileMatrixSet;

/** @file AGSWMTSLayerInfo.h */ //Required for Globals API doc

/** @brief A layer in an OGC-WMTS service
 
 Instances of this class represent a layer in an OGC-WMTS service.
 
 @since 100.1
 */
@interface AGSWMTSLayerInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Description of the layer
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *layerDescription;

/** Image formats supported by the layer
 @since 100.1
 @see NSValue#ags_tileImageFormatValue
 */
@property (nonatomic, copy, readonly) NSArray<NSValue*> *imageFormats;

/** Unique indentifier of the layer in the service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *layerID;

/** Keywords describing the layer
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *keywords;

/** Styles available for the layer
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *styles;

/** Tile matrix sets avaialable for the layer
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSWMTSTileMatrixSet*> *tileMatrixSets;

/** Title of the layer
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *title;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
