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

#import "AGSMarkerSceneSymbol.h"

/** @file AGSSimpleMarkerSceneSymbol.h */ //Required for Globals API doc

/** @brief A 3D marker symbol based on simple shapes.
 
 Instances of this class represent 3D marker scene symbols such as cone, cube, cylinder, sphere, diamond, and tetrahedron that can be rendered by `AGSSceneView` in a scene.
 
 @since 100
*/
@interface AGSSimpleMarkerSceneSymbol : AGSMarkerSceneSymbol

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a new 3D simple marker scene symbol with the provided arguments
 @param style of the symbol
 @param color of the symbol
 @param height of the symbol, in meters
 @param width of the symbol, in meters
 @param depth of the symbol, in meters
 @param anchorPosition of the symbol in 3D space
 @return Initialized 3D marker scene symbol
 @since 100
 */
-(instancetype)initWithStyle:(AGSSimpleMarkerSceneSymbolStyle)style
                       color:(AGSColor *)color
                      height:(double)height
                       width:(double)width
                       depth:(double)depth
              anchorPosition:(AGSSceneSymbolAnchorPosition)anchorPosition;

+(instancetype)simpleMarkerSceneSymbol;


/** Initialize a new 3D simple marker scene symbol with the provided arguments
 @param style of the symbol
 @param color of the symbol
 @param height of the symbol, in meters
 @param width of the symbol, in meters
 @param depth of the symbol, in meters
 @param anchorPosition of the symbol in 3D space
 @return Initialized 3D marker scene symbol
 @since 100
 */
+(instancetype)simpleMarkerSceneSymbolWithStyle:(AGSSimpleMarkerSceneSymbolStyle)style
                                          color:(AGSColor *)color
                                         height:(double)height
                                          width:(double)width
                                          depth:(double)depth
                                 anchorPosition:(AGSSceneSymbolAnchorPosition)anchorPosition;

/** Initialize a new 3D cone symbol with the provided arguments
 @param color of the symbol
 @param diameter of cone's base, in meters
 @param height of the cone, in meters
 @return Initialized 3D cone symbol
 @since 100
 */
+(instancetype)coneWithColor:(AGSColor*)color
                    diameter:(double)diameter
                      height:(double)height;

/** Initialize a new 3D cone symbol with the provided arguments
 @param color of the symbol
 @param diameter of cone's base, in meters
 @param height of the cone, in meters
 @param anchorPosition of the symbol in 3D space
 @return Initialized 3D cone symbol
 @since 100
 */
+(instancetype)coneWithColor:(AGSColor*)color
                    diameter:(double)diameter
                      height:(double)height
              anchorPosition:(AGSSceneSymbolAnchorPosition)anchorPosition;


/** Initialize a new 3D cube symbol with the provided arguments
 @param color of the symbol
 @param size of the symbol, in meters
 @return Initialized 3D cube symbol
 @since 100
 */
+(instancetype)cubeWithColor:(AGSColor*)color
                        size:(double)size;

/** Initialize a new 3D cube symbol with the provided arguments
 @param color of the symbol
 @param size of the symbol, in meters
 @param anchorPosition of the symbol in 3D space
 @return Initialized 3D cube symbol
 @since 100
 */
+(instancetype)cubeWithColor:(AGSColor*)color
                        size:(double)size
              anchorPosition:(AGSSceneSymbolAnchorPosition)anchorPosition;

/** Initialize a new 3D cylinder symbol with the provided arguments
 @param color of the symbol
 @param diameter of cylinder's base, in meters
 @param height of the cylinder, in meters
 @return Initialized 3D cylinder symbol
 @since 100
 */
+(instancetype)cylinderWithColor:(AGSColor*)color
                        diameter:(double)diameter
                          height:(double)height;

/** Initialize a new 3D cylinder symbol with the provided arguments
 @param color of the symbol
 @param diameter of cylinder's base, in meters
 @param height of the cylinder, in meters
 @param anchorPosition of the symbol in 3D space
 @return Initialized 3D cylinder symbol
 @since 100
 */
+(instancetype)cylinderWithColor:(AGSColor*)color
                        diameter:(double)diameter
                          height:(double)height
                  anchorPosition:(AGSSceneSymbolAnchorPosition)anchorPosition;


/** Initialize a new 3D diamond symbol with the provided arguments
 @param color of the symbol
 @param size of the symbol, in meters
 @return Initialized 3D diamond symbol
 @since 100
 */
+(instancetype)diamondWithColor:(AGSColor*)color
                           size:(double)size
                         height:(double)height;

/** Initialize a new 3D diamond symbol with the provided arguments
 @param color of the symbol
 @param size of the symbol, in meters
 @param anchorPosition of the symbol in 3D space
 @return Initialized 3D diamond symbol
 @since 100
 */
+(instancetype)diamondWithColor:(AGSColor*)color
                           size:(double)size
                         height:(double)height
                 anchorPosition:(AGSSceneSymbolAnchorPosition)anchorPosition;


/** Initialize a new 3D sphere symbol with the provided arguments
 @param color of the symbol
 @param diameter of the symbol, in meters
 @return Initialized 3D sphere symbol
 @since 100
 */
+(instancetype)sphereWithColor:(AGSColor*)color
                      diameter:(double)diameter;

/** Initialize a new 3D sphere symbol with the provided arguments
 @param color of the symbol
 @param diameter of the symbol, in meters
 @param anchorPosition of the symbol in 3D space
 @return Initialized 3D sphere symbol
 @since 100
 */
+(instancetype)sphereWithColor:(AGSColor*)color
                      diameter:(double)diameter
                anchorPosition:(AGSSceneSymbolAnchorPosition)anchorPosition;

/** Initialize a new 3D tetrahedron symbol with the provided arguments
 @param color of the symbol
 @param size of the symbol, in meters
 @param height of the symbol, in meters
 @return Initialized 3D tetrahedron symbol
 @since 100
 */
+(instancetype)tetrahedronWithColor:(AGSColor*)color
                               size:(double)size
                             height:(double)height;

/** Initialize a new 3D tetrahedron symbol with the provided arguments
 @param color of the symbol
 @param size of the symbol, in meters
 @param height of the symbol, in meters
 @param anchorPosition of the symbol in 3D space
 @return Initialized 3D tetrahedron symbol
 @since 100
 */
+(instancetype)tetrahedronWithColor:(AGSColor*)color
                               size:(double)size
                             height:(double)height
                     anchorPosition:(AGSSceneSymbolAnchorPosition)anchorPosition;

#pragma mark -
#pragma mark properties

/** The 3D marker's style
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSSimpleMarkerSceneSymbolStyle style;

#pragma mark -
#pragma mark methods


NS_ASSUME_NONNULL_END

@end






