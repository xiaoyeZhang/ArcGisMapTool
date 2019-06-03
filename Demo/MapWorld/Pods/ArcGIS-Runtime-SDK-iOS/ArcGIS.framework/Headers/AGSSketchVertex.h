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

NS_ASSUME_NONNULL_BEGIN

@class AGSPoint;

/** @file AGSSketchVertex.h */ //Required for Globals API doc

/** @brief A class that represents a vertex or mid-vertex in the AGSSketchEditor.
 
 Instances of this class represent a vertex or mid-vertex in the AGSSketchEditor.
 If the pointIndex is greater or equal to 0, then it's a vertex.
 If the insertionIndex is greater or equal to 0, then it's a mid-vertex.
 This object cannot have both pointIndex and insertionIndex greater or equal to 0.
 When the associated sketch editor is modifying a point geometry, the partIndex and pointIndex will both be 0 for a valid vertex.
 Mid-vertices are not allowed for a single point geometry.
 When the associated sketch editor is modifying a multi-point geometry, the partIndex will be 0 for a valid vertex.
 Mid-vertices are not allowed for a multi-point geometry.
 @since 100.2
 */
@interface AGSSketchVertex : NSObject

#pragma mark -
#pragma mark initializers

/**
 Initializes a vertex for a given part index and point index in the sketch editor's geometry.
 @param partIndex The index of the part in the sketch editor's geometry to which this vertex can be found.
 @param pointIndex The index of the point in the sketch editor's geometry to which this vertex can be found.
 @since 100.2
 */
-(instancetype)initWithPartIndex:(NSInteger)partIndex pointIndex:(NSInteger)pointIndex;

/**
 Initializes a mid-vertex for a given part index and insertion index.
 When using this initializer the vertex object represents a mid-vertex which doesn't have a
 representation in the sketch editor's geometry.
 @param partIndex The index of the part in the sketch editor's geometry to which this vertex can be found.
 @param insertionIndex The point index at which a vertex would be inserted if this mid-vertex were to be turned into an actual vertex.
 @since 100.2
 */
-(instancetype)initWithPartIndex:(NSInteger)partIndex insertionIndex:(NSInteger)insertionIndex;

/**
 Initializes a vertex for a given part index and point index in the sketch editor's geometry.
 @param partIndex The index of the part in the sketch editor's geometry to which this vertex can be found.
 @param pointIndex The index of the point in the sketch editor's geometry to which this vertex can be found.
 @since 100.2
 */
+(instancetype)sketchVertexWithPartIndex:(NSInteger)partIndex pointIndex:(NSInteger)pointIndex;

/**
 Initializes a mid-vertex for a given part index and insertion index.
 When using this initializer the vertex object represents a mid-vertex which doesn't have a
 representation in the sketch editor's geometry.
 @param partIndex The index of the part in the sketch editor's geometry to which this vertex can be found.
 @param insertionIndex The point index at which a vertex would be inserted if this mid-vertex were to be turned into an actual vertex.
 @since 100.2
 */
+(instancetype)sketchVertexWithPartIndex:(NSInteger)partIndex insertionIndex:(NSInteger)insertionIndex;

#pragma mark -
#pragma mark properties

/**
 The index of the part in the sketch editor's geometry to which this vertex can be found.
 @since 100.2
 */
@property (nonatomic, assign, readonly) NSInteger partIndex;

/** The index of the point in the sketch editor's geometry to which this vertex can be found.
 This will return -1 if this vertex is a mid-vertex.
 @since 100.2
 */
@property (nonatomic, assign, readonly) NSInteger pointIndex;

/** The point index at which a vertex would be inserted if this mid-vertex were to be turned into an actual vertex.
 This will return -1 if this vertex is a real vertex and not a mid-vertex
 @since 100.2
 */
@property (nonatomic, assign, readonly) NSInteger insertionIndex;

/**
 The actual point geometry that this vertex can be found on the map.
 This property is null until the vertex is bound to the sketch editor via selection.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSPoint *point;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END


