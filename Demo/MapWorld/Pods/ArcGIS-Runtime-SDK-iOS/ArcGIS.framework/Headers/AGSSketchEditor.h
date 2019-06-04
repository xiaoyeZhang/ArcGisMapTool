/*
 COPYRIGHT 2015 ESRI
 
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

@class AGSGeometry;
@class AGSSketchStyle;
@class AGSSketchEditConfiguration;
@class AGSPoint;
@class AGSSketchVertex;

/** @file AGSSketchEditor.h */ //Required for Globals API doc

/** Notification that indicates that the geometry of @c AGSSketchEditor changed.
 
 <h3>Notifications</h3>
 The class posts @c AGSSketchEditorGeometryDidChangeNotification when its geometry changes.
 @since 100
 */
AGS_EXTERN NSNotificationName __nonnull const AGSSketchEditorGeometryDidChangeNotification;

/** @brief A class that allows the user to sketch geometries on the map.
 
Instances of this class represent a sketch editor that allows the user to interactively sketch geometries. You can sketch point, polygon, and polyline geometries from scratch, modify existing geometries, insert and remove vertices, undo and redo changes, and so on.
 
 The sketch editor must be set on the view (`AGSMapView#sketchEditor`) and then started to perform the sketch based on user interactions.
 
 
 @since 100
 */
@interface AGSSketchEditor : NSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)sketchEditor;

#pragma mark -
#pragma mark properties

/** Mode specifying which type of geometry will be sketched and what type of user interaction is used to create it.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSSketchCreationMode creationMode;

/** A manager to undo/redo changes to the sketch geometry. This manager keeps track of all the changes performed through user interactions with the view.
 @since 100
 */
@property (nonatomic, strong, readonly) NSUndoManager *undoManager;

/** Opacity of the sketch
 @since 100
 */
@property (nonatomic, assign, readwrite) float opacity;

/** Indicates whether the sketch will be visible or not
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isVisible) BOOL visible;

/** Indicates whether the sketch editor is started and will respond to user interactions with the view.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isStarted) BOOL started;

/** The geometry currently being sketched. It is updated as the user interacts with the view.
 An `AGSSketchEditorGeometryDidChangeNotification` is posted whenever the geometry changes.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSGeometry *geometry;

/**
 Indicates whether the sketch's geometry is valid. It is valid if :
 - It is a point and contains x & y coordinates.
 - It is a polyline and contains atleast one part of 2 or more vertices.
 - It is a polygon and contains atleast one part of 3 or more vertices which form a closed ring.
 - It is a multipoint and contains atleast one vertex.
 - It is an envelope and it contains xmin, ymin, xmax, & ymax coordinates.
 
 @return YES if the sketch's geometry is valid.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isSketchValid) BOOL sketchValid;

/** Visual appearance of the sketch
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSketchStyle *style;

/** Specifies which options and interactions are supported to edit geometry
 @since 100.2
*/
@property (nullable, nonatomic, strong, readwrite) AGSSketchEditConfiguration *editConfiguration;

/** The vertex of the geometry that is currently selected (if any)
 @since 100.2
 */
@property (nullable, nonatomic, strong, readwrite) AGSSketchVertex *selectedVertex;

#pragma mark -
#pragma mark methods

#pragma mark start/stop methods

/** Starts a sketch based on the provided geometry. The sketch editor begins responding to user interactions with the `AGSGeoView` to perform the sketch.
 The `#creationMode` defaults to `AGSSketchCreationModePoint`, `AGSSketchCreationModePolyline`, or `AGSSketchCreationModePolygon` depending upon the type of geometry provided.
 @param geometry to start the sketch with
 @since 100
 */
-(BOOL)startWithGeometry:(AGSGeometry*)geometry;


/** Starts a sketch based on the provided geometry and creation mode. The sketch editor begins responding to user interactions with the `AGSGeoView` to perform the sketch.

 @param geometry to use as a starting point to begin the sketch with
 @param creationMode representing the type of geometry that the user can sketch, and what type of user interaction will be used to create it. This must be compatible with the geometry being provided
 @since 100
 */
-(BOOL)startWithGeometry:(nullable AGSGeometry*)geometry
            creationMode:(AGSSketchCreationMode)creationMode;

/** Starts a sketch based on the provided geometry, creation mode, and edit configuration. The sketch editor begins responding to user interactions with the `AGSGeoView` to perform the sketch.
 
 @param geometry to use as a starting point to begin the sketch with
 @param creationMode representing the type of geometry that the user can sketch, and what type of user interaction will be used to create it. This must be compatible with the geometry being provided
 @param editConfiguration specifying which options and interactions are supported to edit the geometry
 @since 100.2
 */
-(BOOL)startWithGeometry:(nullable AGSGeometry*)geometry
            creationMode:(AGSSketchCreationMode)creationMode
       editConfiguration:(nullable AGSSketchEditConfiguration*)editConfiguration;

/** Starts a sketch based on the provided geometry and edit configuration. The sketch editor begins responding to user interactions with the `AGSGeoView` to perform the sketch.
 
 @param geometry to use as a starting point to begin the sketch with
 @param editConfiguration specifying which options and interactions are supported to edit the geometry
 @since 100.2
 */
-(BOOL)startWithCreationMode:(AGSSketchCreationMode)creationMode
           editConfiguration:(nullable AGSSketchEditConfiguration*)editConfiguration;

/** Starts a sketch based on the provided creation mode. The sketch editor begins responding to user interactions with the `AGSGeoView` to perform the sketch.
 @param creationMode representing the type of geometry that the user can sketch, and what type of user interaction will be used to create it.
 @since 100
 */
-(BOOL)startWithCreationMode:(AGSSketchCreationMode)creationMode;


/** Starts a sketch based on the provided geometry. The sketch editor begins responding to user interactions with the `AGSGeoView` to perform the sketch.
 The `#creationMode` defaults to `AGSSketchCreationModePoint`, `AGSSketchCreationModePolyline`, or `AGSSketchCreationModePolygon` depending upon the type of geometry provided.
 
 @param geometryType the type of geometry that the user can create
 @since 100
 */
-(BOOL)startWithGeometryType:(AGSGeometryType)geometryType;

/** Stops the sketch by making the sketch editor no longer respond to user interaction. This also clears the `#geometry` and resets the `#undoManager`.
 @since 100
 */
-(void)stop;

#pragma mark mutate geometry methods

/** Clears the current geometry. This is an undo-able operation.
 @since 100
 */
-(void)clearGeometry;

/** Replaces the current geometry with `geometry`. These
 geometries must be matching in type. This is an undo-able operation.
 @param geometry The new geometry to be used.
 @since 100
 */
-(void)replaceGeometry:(AGSGeometry*)geometry;

/** Adds a new vertex, and selects it. If geometry is empty, this adds a new point.
 @since 100.2
 */
-(BOOL)insertVertexAfterSelectedVertexWithPoint:(AGSPoint*)point;

/** Moves selected vertex
 @since 100.2
 */
-(BOOL)moveSelectedVertexToPoint:(AGSPoint*)point;

/** Removes the selected vertex
 @since 100.2
 */
-(BOOL)removeSelectedVertex;

NS_ASSUME_NONNULL_END
@end

