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

/** @file AGSENCViewingGroupSettings.h */ //Required for Globals API doc

/** @brief View group settings for ENC data
 
 View group settings for ENC data.
 
 @note Changes are applied to the display of all ENC layers in a map
 @since 100.2
 */
@interface AGSENCViewingGroupSettings : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates whether or not to display the "all isolated dangers" view group. Per IHO S-52 Annex A, controls viewing group layer 13, which includes viewing groups 34050 and 34051.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL allIsolatedDangers;

/** Indicates whether or not to display the "archipelagic sea lanes" view group. Per IHO S-52 Annex A, controls viewing group layer 9, which includes viewing group 26260.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL archipelagicSeaLanes;

/** Indicates whether or not to display the "boundaries and limits" view group. Per IHO S-52 Annex A, controls viewing group layer 4, which includes viewing groups 23030, 26050, 26220, 26240, and 26250.

 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL boundariesAndLimits;

/** Indicates whether or not to display the "buoys, beacons, aids to navigation" view group. Per IHO S-52 Annex A, controls viewing group layer 3, which includes viewing groups 21020, 22200 – 22240, 27000, 27010, 27011, 27020, 27025, 27040, 27050, 27070, 27080, 27200, 27210, 27230, 27030, and 27060.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL buoysBeaconsAidsToNavigation;

/** Indicates whether or not to display the "buoys, beacons, structures" view group. Per IHO S-52 Annex A, controls viewing group layer 3.1, which includes viewing groups 21010, 21020, 22200 - 22240, 27000-27050, 27080, 27200 – 27230, 27030, and 27060.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL buoysBeaconsStructures;

/** Indicates whether or not to display the "chart scale boundaries" view group. Per IHO S-52 Annex A, controls viewing group layer 6, which includes viewing group 21030.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL chartScaleBoundaries;

/** Indicates whether or not to display the "depth contours" view group. Per IHO S-52 Annex A, controls viewing group layer 15, which includes viewing group 33020.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL depthContours;

/** Indicates whether or not to display the "drying line" view group. Per IHO S-52 Annex A, controls viewing group layer 2, which includes viewing group 22010
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL dryingLine;

/** Indicates whether or not to display the "lights" view group. Per IHO S-52 Annex A, controls viewing group layer 3.2, which includes viewing group 27070.

 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL lights;

/** Indicates whether or not to display the "magnetic variation" view group. Per IHO S-52 Annex A, controls viewing group layer 14, which includes viewing group 31080.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL magneticVariation;

/** Indicates whether or not to display the "other miscellaneous" view group. Per IHO S-52 Annex A, controls viewing group layer 18, which includes viewing group 30000-39999.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL otherMiscellaneous;

/** Indicates whether or not to display the "prohibited and restricted areas" view group. Per IHO S-52 Annex A, controls viewing group layer 5, which includes viewing groups 26000, 26010, and 26040.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL prohibitedAndRestrictedAreas;

/** Indicates whether or not to display the "seabed" view group. Per IHO S-52 Annex A, controls viewing group layer 16, which includes viewing groups 34010, 34020, and 33040.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL seabed;

/** Indicates whether or not to display the "ships' routing systems and ferry routes" view group. Per IHO S-52 Annex A, controls viewing group layer 8, which includes viewing groups 25010-25060.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL shipsRoutingSystemsAndFerryRoutes;

/** Indicates whether or not to display the "spot soundings" view group. Per IHO S-52 Annex A, controls viewing group layer 11, which includes viewing group 33010.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL spotSoundings;

/** Indicates whether or not to display the "standard miscellaneous" view group. Per IHO S-52 Annex A, controls viewing group layer 10 under the "standard display" viewing group, which includes all objects not covered by viewing groups 20000-29999
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL standardMiscellaneous;

/** Indicates whether or not to display the "submarine cables and pipelines" view group. Per IHO S-52 Annex A, controls viewing group layer 12, which includes viewing groups 34030 and 34070.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL submarineCablesAndPipelines;

/** Indicates whether or not to display the "tidal" view group. Per IHO S-52 Annex A, controls viewing group layer 17, which includes viewing groups 33050 and 33060.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL tidal;

#pragma mark -
#pragma mark methods

/** Resets all view group visibility settings
 @since 100.2
 */
-(void)resetToDefaults;

NS_ASSUME_NONNULL_END

@end
