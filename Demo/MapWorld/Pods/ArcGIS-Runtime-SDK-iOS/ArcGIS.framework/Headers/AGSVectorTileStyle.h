/*
 COPYRIGHT 2016 ESRI
 
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

/** @file AGSVectorTileStyle.h */ //Required for Globals API doc

/** @brief Style information for a source of vector tiles
 
 Instances of this class represent style information of a source of vector tiles
 
 @since 100
 */

@interface AGSVectorTileStyle : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** URL to a stylesheet for an ArcGIS Vector Tile service
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *sourceURL;

/** Version of the stylesheet
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *version;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end

