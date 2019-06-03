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

#import "AGSLoadableBase.h"
#import "AGSRemoteResource.h"

@class AGSKMLNode;
@class AGSKMLNetworkLink;

/** @file AGSKMLDataset.h */ //Required for Globals API doc

/** @brief A KML dataset
 
 Instances of this class represent a KML dataset available in a KML/KMZ file on the web or on disk.
 It provides an entry point to traverse the tree of KML nodes that make up the KML document.
 
 @license{Standard, when using local .kml or .kmz file}
 @ingroup licensing
 @since 100.4
 */
@interface AGSKMLDataset : AGSLoadableBase <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this dataset with URL to a KML/KMZ file on the web or on disk.
 @param URL to a KML/KMZ file on the web or on disk.
 @return A new kml dataset
 @license{Standard, when using local .kml or .kmz file}
 @ingroup licensing
 @since 100.4
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize this dataset with a name of a KML or KMZ file, excluding the .kml or .kmz file extension,
 within the application bundle or shared documents directory.
 @param name of the KML or KMZ file (excluding the .kml or .kmz file extension)
 @return A new kml dataset
 @license{Standard, when using local .kml or .kmz file}
 @ingroup licensing
 @since 100.4
 */
-(instancetype)initWithName:(NSString *)name;

/** Initialize this dataset with URL to a KML/KMZ file on the web or on disk.
 @param URL to a KML/KMZ file on the web or on disk.
 @return A new kml dataset
 @license{Standard, when using local .kml or .kmz file}
 @ingroup licensing
 @since 100.4
 */
+(instancetype)KMLDatasetWithURL:(NSURL*)URL;

/** Initialize this dataset with a name of a KML or KMZ file, excluding the .kml or .kmz file extension,
 within the application bundle or shared documents directory.
 @param name of the KML or KMZ file (excluding the .kml or .kmz file extension)
 @return A new kml dataset
 @license{Standard, when using local .kml or .kmz file}
 @ingroup licensing
 @since 100.4
 */
+(instancetype)KMLDatasetWithName:(NSString *)name;

#pragma mark -
#pragma mark properties

/** The root nodes in the KML dataset. Typically, a dataset has only one root node, but some might
 have multiple root nodes. Also, typical KML document will have multiple levels of nested KML nodes.
 Therefore to accurately traverse through all of the KML node information in a Kml dataset, it is recommended
 to recursively test all nodes to see if they contain additional child nodes.
 @since 100.4
 */
@property (nonatomic, copy, readonly) NSArray<AGSKMLNode*> *rootNodes;

/** Block that is invoked whenever KML network link control message is available. KML network
 links may specify messages, such as usage guidelines, to be shown once to application end-user.
 Applications are expected to deliver this message to the end-user, typically in the form of an alert.
 @note The block will be invoked on the same thread on which the event occurred, which could be any
 arbitrary thread. You need to dispatch any UI related work to the main thread.
 @since 100.4
 */
@property (nullable, nonatomic, copy, readwrite) void (^networkLinkMessageHandler)(AGSKMLNetworkLink *networkLink, NSString *message);

/** Block that is invoked whenever KML node refresh status changes.
 @note The block will be invoked on the same thread on which the event occurred, which could be any
 arbitrary thread. You need to dispatch any UI related work to the main thread.
 @since 100.4
 */
@property (nullable, nonatomic, copy, readwrite) void (^nodeRefreshStatusChangedHandler)(AGSKMLNode *node, AGSKMLRefreshStatus refreshStatus);

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

