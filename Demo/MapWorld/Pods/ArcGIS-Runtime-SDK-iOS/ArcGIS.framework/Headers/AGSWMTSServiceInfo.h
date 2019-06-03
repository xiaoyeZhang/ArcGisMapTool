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

@class AGSWMTSLayerInfo;
@class AGSWMTSTileMatrixSet;

/** @file AGSWMTSServiceInfo.h */ //Required for Globals API doc

/** @brief Metadata of an OGC-WMTS map service
 
 Instances of this class represent information about an OGC-WMTS map service. For example, http://v2.suite.opengeo.org/geoserver/gwc/service/wmts .

 @since 100.1
 */
@interface AGSWMTSServiceInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Description about the service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *serviceDescription;

/** List of keywords describing the service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *keywords;

/** Information about the layers available in the service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSWMTSLayerInfo*> *layerInfos;

/** Tile matrix sets avaialble in the service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSWMTSTileMatrixSet*> *tileMatrixSets;

/** Title of the service
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *title;

/** Version of the WMTS GetCapabilities operation
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *version;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
