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

/** @file AGSENCTextGroupVisibilitySettings.h */ //Required for Globals API doc

/** @brief Text group settings for ENC data
 
 Text group settings for ENC data.
 
 @note Changes are applied to the display of all ENC layers in a map
 @since 100.2
 */
@interface AGSENCTextGroupVisibilitySettings : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates whether or not the "berth number" text group should be visible. Per IHO S-52 Annex A, controls text group 29, which includes OBJNAM from BERTHS and ACHBRT.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL berthNumber;

/** Indicates whether or not the "current velocity" text group should be visible. Per IHO S-52 Annex A, controls text group 30, which includes CURVEL.

 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL currentVelocity;

/** Indicates whether or not the "geographic names" text group should be visible. Per IHO S-52 Annex A, controls text group 26, which includes OBJNAM from ACHARE, BRIDGE, BUAARE, BUISGL, DOCARE, FAIRWY, LNDARE, LNDMARK, LNDRGN, SEAARE, TIDEWY, and PILBOP.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL geographicNames;

/** Indicates whether or not the "height of islet or land feature" text group should be visible. Per IHO S-52 Annex A, controls text group 28, which includes HEIGHT of LNDARE.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL heightOfIsletOfLandFeature;

/** Indicates whether or not the "important text" text group should be visible. Per IHO S-52 Annex A, controls text groups 10 and 11.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL importantText;

/** Indicates whether or not the "light descriptions" text group should be visible. Per IHO S-52 Annex A, controls text group 23.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL lightDescription;

/** Indicates whether or not the "magnetic variation and swept depth" text group should be visible. Per IHO S-52 Annex A, controls text group 27, which includes MAGVAR, VALMAG, SWPARE, and DRVAL1.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL magneticVariationAndSweptDepth;

/** Indicates whether or not the "names for position reporting" text group should be visible. Per IHO S-52 Annex A, controls text group 21.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL namesForPositionReporting;

/** Indicates whether or not the "nature of seabed" text group should be visible. Per IHO S-52 Annex A, controls text group 25 (SBDARE, NATSUR).
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL natureOfSeabed;

/** Indicates whether or not the "note on chart data" text group should be visible. Per IHO S-52 Annex A, controls text group 24.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL noteOnChartData;

#pragma mark -
#pragma mark methods

/** Resets all text group visibility settings
 @since 100.2
 */
-(void)resetToDefaults;

NS_ASSUME_NONNULL_END

@end
