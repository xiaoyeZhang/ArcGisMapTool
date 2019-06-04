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

@class AGSMapView;
@class AGSPoint;

/** @file AGSENCFeature.h */ //Required for Globals API doc

/** @brief An ENC feature
 
 Instances of this class represent a feature in ENC (Electronic Navigational Chart) data.
 
 @since 100.2
 */
@interface AGSENCFeature : AGSObject <AGSGeoElement>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** A dictionary containing all the attributes.
 Attribute types supported are NSNull, NSString, NSDate, and NSNumber.
 Other attribute types will be ignored.
 @since 100.2
 */
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString*,id> *attributes;

/** The geometry that defines shape and location of the feature
 @since 100.2
 */
@property (nullable, nonatomic, strong, readwrite) AGSGeometry *geometry;

/** Acronym of the feature
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *acronym;

/** Description of the feature
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *featureDescription;

#pragma mark -
#pragma mark methods

/** The description of an ENC feature's acronym, given the acronym string as the key.
 @param acronym for which attribute description is required
 @return attribute description of the specified acronym
 @since 100.2
 */
-(NSString*)attributeDescriptionForAcronym:(NSString*)acronym;

NS_ASSUME_NONNULL_END

@end
