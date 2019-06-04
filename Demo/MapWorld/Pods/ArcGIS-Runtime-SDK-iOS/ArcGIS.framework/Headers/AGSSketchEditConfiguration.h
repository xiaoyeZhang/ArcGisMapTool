/*
 COPYRIGHT 2016 ESRI
 
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

#import <Foundation/Foundation.h>

/** @file AGSSketchEditConfiguration.h */ //Required for Globals API doc

/** @brief Represents edit configuration for `AGSSketchEditor`.
 
 Instances of this class represent edit configuration for  `AGSSketchEditor` specifying which options and interactions are supported to edit geometries.
 
 @since 100.2
 */
@interface AGSSketchEditConfiguration : NSObject

/** Indicates whether a part in a multipart geometry (multipoint, polyline, or polygon) can be selected.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL allowPartSelection;

/** Indicates whether or not a vertex or a part must first be selected before it can be dragged. Defaults to true.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) BOOL requireSelectionBeforeDrag;

/** Mode specifying what actions are permitted on vertices
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSSketchVertexEditMode vertexEditMode;

#if TARGET_OS_IPHONE && !TARGET_OS_TV
/** Indicates whether or not a context menu should be displayed when users double-tap a vertex or a part.
 @since 100.2
*/
@property (nonatomic, assign, readwrite, getter=isContextMenuEnabled) BOOL contextMenuEnabled;
#endif

/** Whether or not vertex editing is allowed
 @since 100.3
 */
@property (nonatomic, assign, readwrite) BOOL allowVertexEditing;

/** Whether or not part rotation is allowed
 @since 100.3
 */
@property (nonatomic, assign, readwrite) BOOL allowRotate;

/** Whether or not part moving is allowed
 @since 100.3
 */
@property (nonatomic, assign, readwrite) BOOL allowMoveParts;

/** The mode for part resizing
 @since 100.3
 */
@property (nonatomic, assign, readwrite) AGSSketchResizeMode resizeMode;

@end

