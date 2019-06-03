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

/** @file AGSKMLContainer.h */ //Required for Globals API doc

/** @brief A KML Container element
 
 An instance of this class represents a KML `<Container>` element which contains nested KML nodes organized in a hierarchy.
 
 @since 100.4
 */
@interface AGSKMLContainer : AGSKMLNode

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)KMLContainer;

#pragma mark -
#pragma mark properties

/** Specifies the container type, which determines how visibility and selection should work in a table of contents.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSKMLListItemType listItemType;

/** KML container's child nodes.
 @since 100.4
 */
@property (nonatomic, copy, readonly) NSArray<AGSKMLNode*> *childNodes;

/** Indicates whether the node representing this container in a table of contents view
 should be displayed expanded (open) in a tree view.
 @since 100.4
 */
@property (nonatomic, assign, readwrite, getter=isOpen) BOOL open;

/** Indicates whether the node representing this container in a table of contents view should be
 displayed in manner that conveys that its child nodes have mixed visibility.
 @since 100.4
 */
@property (nonatomic, assign, readonly, getter=isPartiallyVisible) BOOL partiallyVisible;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
