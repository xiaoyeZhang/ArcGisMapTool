/*
 COPYRIGHT 2018 ESRI
 
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

@class AGSKMLViewpoint;
@class AGSEnvelope;

/** @file AGSKMLNode.h */ //Required for Globals API doc

/** @brief A single node within a KML document.
 
 @since 100.4
 */
@interface AGSKMLNode : AGSObject
    
NS_ASSUME_NONNULL_BEGIN
    
#pragma mark -
#pragma mark initializers
    
+(instancetype)KMLNode;
    
#pragma mark -
#pragma mark properties

/** The KML node's balloon background color, which should be used when showing a popup.
 @note This color can be used for the UI "chrome" that presents the `#balloonContent`, such as the border and background of a Callout.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) AGSColor *balloonBackgroundColor;

/** The content that should be displayed in a balloon popup of the KML node as HTML.
 @since 100.4
 */
@property (nonatomic, copy, readonly) NSString *balloonContent;

/** The description of the KML node.
 @since 100.4
 */
@property (nonatomic, copy, readonly) NSString *nodeDescription;

/** The KML node's bounding extent.
 @note All coordinates in KML are expressed in latitude and longitude (using decimal degrees)
 and are in the WGS84 geographic coordinate system.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *extent;

/** Indicates whether the KML node is highlighted. This controls whether the default style or an
 alternate 'highlighted' style (if present) is used for rendering the node.
 @note This is unrelated to the concept of selection in ArcGIS Runtime.
 @since 100.4
 */
@property (nonatomic, assign, readwrite, getter=isHighlighted) BOOL highlighted;

/** Indicates whether the KML node is visible or not.
 @note In order for a node to be visible, the visibility of the node and all ancestors must be `true`.
 Changing the visibility of one node may affect the other nodes in the dataset's node hierarchy, including child nodes.
 @since 100.4
 */
@property (nonatomic, assign, readwrite, getter=isVisible) BOOL visible;

/** The name of the KML node.
 @since 100.4
 */
@property (nonatomic, copy, readonly) NSString *name;

/** The error that was encountered during the most recent KML node refresh operation. Will be nil if the operation succeeded.
 The refresh error changes can be monitored using Key-Value Observing (KVO).
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) NSError *refreshError;

/** The refresh status of the KML node. The refresh status changes can be monitored using Key-Value Observing (KVO).
 Use this to update the node's properties and application UI. Please take following actions for different refresh statuses,
 AGSKMLRefreshStatusNone - No action required.
 AGSKMLRefreshStatusInProgress - Application may show an appropriate UI, such as a spinning wheel on top of the node's table of contents (TOC) icon to indicate in progress status and to restrict user interaction with the node.
 AGSKMLRefreshStatusCompleted - Read and update the node's properties and its children. The `AGSKMLNetworkLink#childNodes` changes can be monitored using Key-Value Observing (KVO).
 AGSKMLRefreshStatusFailed - Check `#refreshError` to get the reason for failure and show the error message. Also, applications may show an appropriate UI cue such as a red X with the node's TOC icon to indicate the failed status.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSKMLRefreshStatus refreshStatus;

/** The KML node's parent or `nil` if the node is a root node.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) AGSKMLNode *parentNode;

/** The KML node's snippet, if specified.
 @note A snippet is a short description that can optionally be specified for a KML Feature,
 either instead of or in addition to a full description.
 @since 100.4
 */
@property (nonatomic, copy, readonly) NSString *snippet;

/** The maximum number of lines of snippet to be shown in the UI.
 @note If no snippet is specified for the node, a short description can be
 created by taking the first few lines of the description.
 @since 100.4
 */
@property (nonatomic, assign, readonly) NSInteger snippetMaxLines;

/** The ID of KML node's UX icon.
 @since 100.4
 */
@property (nonatomic, assign, readonly) NSInteger UXIconID;

/** The KML node's UX icon. Use this icon to represent the KML node in the
 table of contents (TOC) or anywhere else you need to display the node in the UI.
 The icon changes can be monitored using Key-Value Observing (KVO).
 @note The icon can change during the lifetime of the node.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) AGSImage *UXIcon;

/** The color mask that can be used to blend the image associated with `#UXIcon`.
 Pixels in the image are multiplied by this color channel-by-channel.
 @note When no icon is specified (#UXIcon is `nil`), you can use the icon color to draw a placeholder image in the UI (for example, the TOC).
 @note Runtime does not pre-tint the `#UXIcon`; it is the application's responsibility to tint the image before displaying it.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) AGSColor *UXIconColor;

/** The KML node's viewpoint, or `nil` if no Camera or LookAt viewpoint is specified on the node.
 It specifies the vantage point for looking at the node. This can be used to show a particular node
 in the view (for example, if a user selected it in a TOC).
 @note You can convert from a KML viewpoint to a Runtime viewpoint in order to use it with a GeoView.
 See the guide documentation and samples for details.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) AGSKMLViewpoint *viewpoint;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

