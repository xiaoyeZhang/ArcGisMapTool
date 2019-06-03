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

#import "AGSKMLNode.h"

/** @file AGSKMLNetworkLink.h */ //Required for Globals API doc

/** @brief A KML Network Link element
 
 An instance of this class represents a KML `<NetworkLink>` element which references
 a KML file or KMZ archive on a local or remote network.
 
 @note A KML network link can have a refresh interval defined to enable regular refresh of data.
 Alternatively, KML network links support a view refresh mode, which fetches network links based on the visible extent.
 @since 100.4
 */
@interface AGSKMLNetworkLink : AGSKMLNode

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Specifies the network link's list item type, which defines how child nodes behave when setting visibility.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSKMLListItemType listItemType;

/** The URL of the KML network link.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) NSURL *URL;

/** Indicates whether the app should zoom to the viewpoint defined on the associated `<NetworkLinkControl>`
 or the network links' top-level `<kml>` node upon refresh of the link.
 @note It is the developer's responsibility to implement this behavior if desired; Runtime
 will not automatically fly to the node on network link refresh.
 @note The viewpoint can be monitored using Key-Value Observing (KVO) to detect when the geoview's viewpoint should be updated.
 @note This value is defined in the flyToView tag in the network link.
 @since 100.4
 */
@property (nonatomic, assign, readonly) BOOL canFlyToNode;

/** The KML network link's child nodes. When the network link is successfully refreshed, this array
 gets populated with new nodes. The child node changes can be monitored using Key-Value Observing (KVO).
 @since 100.4
 */
@property (nonatomic, copy, readonly) NSArray<AGSKMLNode*> *childNodes;

/** Indicates whether Runtime should attempt to maintain the visibility selection of child nodes in the network link after refresh.
 If `true`, Runtime will attempt to maintain any visibility selection for the network link's child nodes after refresh.
 This is the default behavior when `refreshVisibility` is `0` or unset in the source KML file.
 @since 100.4
 */
@property (nonatomic, assign, readonly) BOOL hasRefreshVisibility;

/** Indicates whether the node representing this network link in a table of contents view should be displayed expanded or open.
 @since 100.4
 */
@property (nonatomic, assign, readwrite, getter=isOpen) BOOL open;

/** Indicates whether the KML nodes in this container have mixed visibility.
 @since 100.4
 */
@property (nonatomic, assign, readonly, getter=isPartiallyVisible) BOOL partiallyVisible;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

