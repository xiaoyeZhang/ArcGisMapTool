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

@class AGSTimeValue;

/** @file AGSShapefileInfo.h */ //Required for Globals API doc

/** @brief Metadata for a shapefile dataset
 
 Instances of this class respresent metadata for a shapefile dataset. The metadata is only available if the dataset contains an associated .xml file.
 
 @since 100.2
 */
@interface AGSShapefileInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Copyright text of the shapefile.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *copyrightText;

/** Credits of the shapefile.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *credits;

/** Description of the shapefile.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *shapefileDescription;

/** Summary of the shapefile.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *summary;

/** Tags of the shapefile.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *tags;

/** Thumbnail of the shapefile.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSImage *thumbnail;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

