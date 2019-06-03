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
#import "AGSLayerContent.h"

@class AGSWMSLayerInfo;

/** @file AGSWMSSublayer.h */ //Required for Globals API doc

/** @brief Represents an individual layer in an OGC-WMS service
 
 An instance of this class represents an individual layer in an OGC-WMS service.
 
 @since 100.2
 */
@interface AGSWMSSublayer : AGSObject <AGSLayerContent>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

    /** Name of the current style of this sublayer. Setting current style to an empty string indicates the default style will be used. For a list of available styles for this sublayer, refer to `AGSWMSLayerInfo#styles`.
 @since 100.2
 */
@property (nonatomic, copy, readwrite) NSString *currentStyle;

/** Metadata about the sublayer
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSWMSLayerInfo *sublayerInfo;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

