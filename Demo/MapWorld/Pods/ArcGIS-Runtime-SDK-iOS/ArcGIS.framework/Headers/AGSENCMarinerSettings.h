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

@class AGSENCDisplayCategories;

/** @file AGSENCMarinerSettings.h */ //Required for Globals API doc

/** @brief Mariner settings for ENC data
 
 Mariner settings for ENC data.

 @note Changes are applied to the display of all ENC layers in a map
 @since 100.2
 */
@interface AGSENCMarinerSettings : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The type of area symbolization (plain/symbolized) to use. "Symbolized" area symbolization renders area symbols using the traditional paper chart symbology. Plain reduces clutter.
 Defaults to symbolized.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSENCAreaSymbolizationType areaSymbolizationType;

/** The color scheme (day/dusk/night) to use. Defaults to day.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSENCColorScheme colorScheme;

/** Indicates whether or not to symbolize data quality (M_QUAL) for S-57 features. Defaults to false, meaning quality of data will not be displayed. 
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL dataQuality;

/** The depth of the deep contour in meters.
 This must be greater than or equal to the `#safetyContour`.
 When four (rather than two) depth shades are used, this controls the boundary between safe and deep areas.
 Defaults to 30 meters.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double deepContour;

/** The ENC S-52 display categories. Categories are base, standard, and other. This can be used to configure display settings for categories of objects.
 All display categories are enabled by default. 
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSENCDisplayCategories *displayCategories;

/** The display depth units (meters/feet/fathoms). Defaults to meters.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSENCDisplayDepthUnits displayDepthUnits;

/** Indicates whether or not to display national names. This is text group 31 per IHO S-52 Annex A. Defaults to true, meaning national names will be displayed.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL displayNOBJNM;

/** Indicates whether the 'SCAMIN' (scale min) S-57 feature attribute will be used. If disabled, all ENC features will be rendered regardless of scale.
 Defaults to true, meaning the scale min attribute will be respected. 
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL honorSCAMIN;

/** Indicates whether or not to display isolated dangers in shallow water. This is viewing group 24020, 24050 per IHO 2-52 Annex A. Defaults to false,
 meaning isolated dangers will not be shown in shallow water.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL isolatedDangers;

/** Indicates whether or not to display depth contour labels, including safety contour labels. This is viewing group 33021, 33022 per IHO S-52 Annex A.
 Defaults to true, meaning the depth contour labels will be displayed. 
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL labelContours;

/** Indicates whether or not to display safety contour labels. Defaults to true, which means that safety contour labels will be displayed.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL labelSafetyContours;

/** Indicates whether or not to use low accuracy symbols (CATZOC). This is viewing group 31010 per IHO S-52 Annex A. Defaults to true, meaning
 vectors marked as 'low accuracy data' will be symbolized differently. When low accuracy is set to false, low accuracy data will be visually 
 indistinguishable from other data.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL lowAccuracy;

/** The S-52 point feature symbolization type (simplified/paperchart). Paperchart symbolization is based on traditional paper charts. Simplified symbols are more compact and visible.
 Defaults to paperchart.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSENCPointSymbolizationType pointSymbolizationType;

/** The depth of the safety contour in meters. The safety contour separates safe and unsafe areas. Defaults to 30 meters.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double safetyContour;

/** The depth of the shallow contour in meters. This must be less than or equal to the safety contour value. When four (rather than two) depth shades are used,
 this value controls the separation between shallow and unsafe areas. Defaults to two meters. 
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double shallowContour;

/** Indicates whether the shallow depth pattern will be symbolized. Defaults to false, meaning the shallow depth pattern will not be symbolized. 
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL shallowDepthPattern;

/** Indicates whether two or four depth shades will be used; true is the default, which means that two depth shades will be used.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL twoDepthShades;

#pragma mark -
#pragma mark methods

/** Resets all ENC Mariner Settings
 @since 100.2
 */
-(void)resetToDefaults;

NS_ASSUME_NONNULL_END

@end
