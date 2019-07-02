/*
 COPYRIGHT 2019 ESRI
 
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

/*@file AGSSymbolAnchor.h */

/**
 The anchor of a symbol layer, including placement mode and x, y anchor values.
 
 This struct represents the properties necessary to define the anchor for a symbol layer. These anchor properties define both the anchor values and the placement mode. They can be used with `AGSMarkerSymbolLayer` objects to control marker anchor properties.
 
 @since 100.5
 */
typedef struct AGSSymbolAnchor {
    double x;
    double y;
    AGSSymbolAnchorPlacementMode placementMode;
} AGSSymbolAnchor;

/** Returns a Symbol Anchor.
 @param x The x-component of the anchor point. It can be any real number. The units of the value depend on the anchor's placement mode. The default value is 0, regardless of placement mode.
 @param y The y-component of the anchor point. It can be any real number. The units of the value depend on the anchor's placement mode. The default value is 0, regardless of placement mode.
 @param placementMode The anchor placement mode to use for the anchor values. The default value is `AGSSymbolAnchorPlacementModeRelative`
 
 @since 100.5
 */
static inline AGSSymbolAnchor AGSSymbolAnchorMake(double x, double y, AGSSymbolAnchorPlacementMode placementMode) {
    AGSSymbolAnchor symbolAnchor = {x,y,placementMode};
    return symbolAnchor;
}

