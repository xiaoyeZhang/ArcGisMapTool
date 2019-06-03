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

@class AGSWMSLayerInfo;

/** @file AGSWMSServiceInfo.h */ //Required for Globals API doc

/** @brief Information about an OGC-WMS service
 
 An instance of this class represents information about an OGC-WMS service.
 
 @since 100.2
 */
@interface AGSWMSServiceInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** A brief narrative description of the WMS service.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *serviceDescription;

/** The image formats (`AGSMapServiceImageFormat`) supported by the WMS service.
 @since 100.2
 @see NSValue#ags_mapServiceImageFormatValue
*/
@property (nonatomic, copy, readonly) NSArray<NSValue*> *imageFormats;

/** An unordered list of commonly used words to describe this dataset.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *keywords;

/** Layers available in the service.
 @since 100.2
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSWMSLayerInfo*> *layerInfos;

/** Name of the service.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Title of the service.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *title;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

