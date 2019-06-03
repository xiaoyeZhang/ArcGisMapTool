/*
 COPYRIGHT 2009 ESRI
 
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

@protocol AGSCalloutDelegate;
@class AGSPoint;
@class AGSLayer;
@class AGSLocationDisplay;
@class AGSFeature;
@class AGSFeatureLayer;
@class AGSGraphic;
@class AGSGraphicsOverlay;

NS_ASSUME_NONNULL_BEGIN

#if TARGET_OS_IPHONE
/** Supported positions of the callout's leader. The position is relative
 to the callout itself.
 @since 100
 */
typedef NS_OPTIONS(NSUInteger, AGSCalloutLeaderPosition) {
    AGSCalloutLeaderPositionBottom = 1UL << 0,          /*!< Leader is placed on the bottom edge of the callout  */
    AGSCalloutLeaderPositionTop = 1UL << 1,             /*!< Leader is placed on the top edge of the callout */
    AGSCalloutLeaderPositionLeft = 1UL << 2,            /*!< Leader is placed on the left edge of the callout */
    AGSCalloutLeaderPositionRight = 1UL << 3,           /*!< Leader is placed on the right edge of the callout */
    AGSCalloutLeaderPositionAny = AGSCalloutLeaderPositionBottom | AGSCalloutLeaderPositionTop | AGSCalloutLeaderPositionLeft | AGSCalloutLeaderPositionRight                   /*!< Best leader position such that the callout is completely visible on the map without panning the map. For iPad, precedence is based on the order - Left, Right, Top, Bottom. For other devices precedence is based on the order - Bottom, Top, Left, Right. */
} ;
#endif

/** @file AGSCallout.h */ //Required for Globals API doc

/** @brief A callout window.
 
 Instances of this class represent a callout window. A callout can be used to 
 display information on a map. The callout can display a title and a detail string.
 It can also display a picture to the left of the title and detail, and
 an accessory button to the right which can be used to present a secondary
 view with more details. 
 
 You can change the content and look of the callout by setting its properties. You can also embed a custom view
 if you want to completely customize the layout.
 
 @extends UIView
 @see @concept{map-callout.htm, Displaying a Callout}
 @see @c AGSCalloutDelegate
 @since 100
 */

#if TARGET_OS_IPHONE
@interface AGSCallout : AGSView

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Callout width. This property is ignored if using a custom view.
 @since 100
 */
@property (nonatomic) CGFloat width;

/** The custom view to display in the callout. If this property is specified,
 the developer is responsible for the content displayed in the callout. The callout will expand
 to fit the dimensions of the custom view. Most of the other properties related to the look (such as @c #width, #color, etc.) and content
 of the callout (such as @c #title, @c #detail, @c #image, @c #accessoryButtonImage, etc.) will be ignored.
 @since 100
 */
@property (nullable, nonatomic, strong) AGSView *customView;


/** The type of button for the accessory button.
 @since 100
 */
@property (nonatomic) UIButtonType accessoryButtonType;

/** The optional image used for the accessory button.
 @since 100
 */
@property (nullable, nonatomic, strong) UIImage *accessoryButtonImage;


/** The optional image used for displaying content to the left of the text labels.
 The image will be scaled to 40x40 points.
 @since 100
 */
@property (nullable, nonatomic, strong) AGSImage *image;

/** This is a parameter than specifies that the width of the callout should adjust to the size
 of the text. This parameter is ignored if using a custom view.
 @since 100
 */
@property (nonatomic) BOOL autoAdjustWidth;

/** Indicates whether the accessory button is hidden.
 Default is NO.
 @since 100
 */
@property (nonatomic, assign, getter=isAccessoryButtonHidden) BOOL accessoryButtonHidden;

/** Flags specifying the possible leader locations when showing the callout. Possible values include:
 
 @li @c AGSCalloutLeaderPositionLeft
 @li @c AGSCalloutLeaderPositionRight
 @li @c AGSCalloutLeaderPositionTop
 @li @c AGSCalloutLeaderPositionBottom
 @li @c AGSCalloutLeaderPositionAny
 
 
 These values can be combined with the bitwise OR operator. The default value
 is  @c AGSCalloutLeaderPositionBottom .
 
 <code>AGSCalloutLeaderPositionAny</code> will attempt to find the best location for the given
 point. On the iPad, precedence is given based on the following sequence - left, right, bottom, top. On all other iOS devices,
 it is - bottom, top, left, right.
 
 @since 100
 */
@property (nonatomic, assign) AGSCalloutLeaderPosition leaderPositionFlags;

/** Callout's border color. Default is nil.
 @since 100
 */
@property (nullable, nonatomic, strong) AGSColor *borderColor;

/** Callout's border width. Default is 0.
 @since 100
 */
@property (nonatomic, assign) CGFloat  borderWidth;


#elif (TARGET_OS_MAC && !TARGET_OS_IPHONE)
@interface AGSCallout : NSObject

@property (nonatomic, assign, getter = isHidden) BOOL hidden;

/** Determines if the top or bottom is highlighted.
 @since 100
*/
@property (nonatomic, assign) BOOL highlightTop;

#endif

/** Location in map coordinates where the callout's leader should point to. If 
 the callout is shown in response to a user tap, this property contains the 
 tapped location. If the callout is shown in response to a AGSLocationDisplay location update,
 this property contains that location. 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPoint *mapLocation;

/** Offset in screen coordinates from the map location that the callout
 leader should point to. This is generally used with Marker symbols that have
 offsets so that the callout will display in the correct location as the map is
 scaled (zoomed in or out). A positive x-value shifts the callout to the right.
 A positive y-value shifts the callout down.
 @since 100
 */
@property (nonatomic, readonly) CGPoint screenOffset;

/** Text for title label.
 @since 100
 */
@property (nullable, nonatomic, copy) NSString *title;

/** Text for detail label.
 @since 100
 */
@property (nullable, nonatomic, copy) NSString *detail;

/** Background color of callout. Default is black with .8 alpha.
 @since 100
 */
@property (nonatomic, strong) AGSColor *color;

/** Highlight color of callout. Default is white with .15 alpha.
 @since 100
 */
@property (nullable, nonatomic, strong) AGSColor *highlight;

/** Text color. Default is white.
 @since 100
 */
@property (nonatomic, strong) AGSColor *titleColor;

/** Detail text color. Default is white.
 @since 100
 */
@property (nonatomic, strong) AGSColor *detailColor;

/** The callout's delegate.
 @since 100
 */
@property (nullable, nonatomic, weak) id<AGSCalloutDelegate> delegate;

/** The margin in points around the text or the custom view.
 @since 100
 */
@property (nonatomic) CGSize margin;

/** The corner radius in points for the rounded corners.
 This property is ignored if not using a custom view.
 @since 100
 */
@property (nonatomic) CGFloat cornerRadius;

/** The maximum width of the callout if the callout is autosizing to the text.
 To autosize to the text width, set the autoAdjustWidth property to YES. This property is ignored
 if using a custom view.
 @since 100
 */
@property (nonatomic) CGFloat maxWidth;

/** The object that the callout is shown for. Could be a `AGSFeature`, `AGSGraphic` or `AGSLocationDisplay`.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) id representedObject;

#pragma mark -
#pragma mark methods

/** Shows the callout at the specified location for the provided feature.
 The callout's @c #delegate, if it exists, is informed just before the callout is shown through
 @c AGSCalloutDelegate#callout:willShowAtMapPoint:
 @param feature for which callout is to be shown. This then becomes the `#representedObject`
 @param mapTapLocation at which the callout should be shown
 @param animated Flag to determine if action should be animated.
 @return Value indicating whether or not the callout did actually show.
 @since 100
 */
-(BOOL)showCalloutForFeature:(AGSFeature*)feature tapLocation:(nullable AGSPoint*)mapTapLocation animated:(BOOL)animated;

/** Shows the callout at the specified location for the provided graphic.
 The callout's @c #delegate, if it exists, is informed just before the callout is shown through
 @c AGSCalloutDelegate#callout:willShowAtMapPoint:
 @param graphic for which callout is to be shown. This then becomes the `#representedObject`
 @param mapTapLocation at which the callout should be shown
 @param animated Flag to determine if action should be animated.
 @return Value indicating whether or not the callout did actually show.
 @since 100
 */
-(BOOL)showCalloutForGraphic:(AGSGraphic*)graphic tapLocation:(nullable AGSPoint*)mapTapLocation animated:(BOOL)animated;

/** Shows the callout for the AGSLocationDisplay on the map.
 The callout's @c #delegate, if it exists, is informed just before the callout is shown through
 @c AGSCalloutDelegate#callout:willShowForLocationDisplay:
 @return Value indicating whether or not the callout did actually show.
 @since 100
 */
-(BOOL)showCalloutForLocationDisplay;

/** Shows the callout at the specified map location with the specified screen offset.
 @param mapLocation The location on the map to move to.
 @param screenOffset The offset from the map location to place the callout in screen points.
 @param rotateOffsetWithMap Whether or not the screenOffset should be translated by an amount equal to the map's rotation.
 @param animated Flag to determine if action should be animated.
 @since 100
 */
-(void)showCalloutAt:(AGSPoint*)mapLocation screenOffset:(CGPoint)screenOffset rotateOffsetWithMap:(BOOL)rotateOffsetWithMap animated:(BOOL)animated;

/** Dismisses the callout.
  @since 100
*/
-(void)dismiss;

@end



#pragma mark -

/** @brief A delegate of @c AGSCallout.
 
 A protocol which must be adopted by a class wishing to control the behavior of displaying a callout for a map's features, graphics, or location display symbol. The delegate is also notified when a user
 interacts with the callout. An instance of the class must be set as @c AGSCallout#delegate.
 
 All of the methods of this protocol are optional.
 
 @define{AGSCallout.h, ArcGIS}
 @since 100
 */
@protocol AGSCalloutDelegate <NSObject>

@optional

/** Informs the delegate that a callout is about to be shown at the specfied map location.  The delegate should return NO if it wants to abort showing the callout.
 @param callout The callout that will show.
 @param mapPoint The location at which the callout will show.
 @return Value indicating whether or not the callout should actually show.
 @since 100
 */
-(BOOL)callout:(AGSCallout*)callout willShowAtMapPoint:(AGSPoint *)mapPoint;

/** Informs the delegate that a callout is about to be shown for the map's location display symbol. The delegate should return NO if it wants to abort showing the callout.
 @param callout The callout that will show.
 @param locationDisplay The locationDisplay to display the callout for.
 @return Value indicating whether or not the callout should actually show.
 @since 100
 */
-(BOOL)callout:(AGSCallout*)callout willShowForLocationDisplay:(AGSLocationDisplay*)locationDisplay;

/** Informs the delegate that the callout will be dismissed.
 @since 100
 */
-(void)calloutWillDismiss:(AGSCallout*)callout;

/** Informs the delegate that the callout was dismissed.
 @since 100
 */
-(void)calloutDidDismiss:(AGSCallout*)callout;

#if TARGET_OS_IPHONE

/** Informs the delegate the user tapped on the accessory button in the callout.
 You can check the @c AGSCallout#representedObject to find out what object the callout was being displayed for
 @param callout Callout containing accessory button.
 @since 100
 */
- (void)didTapAccessoryButtonForCallout:(AGSCallout *)callout;

#elif TARGET_OS_MAC && (!TARGET_OS_IPHONE)

/** Informs the delegate the user tapped on the callout.
 @param callout Callout that was clicked.
 @since 100
 */
-(void)didTapCallout:(AGSCallout*)callout;

#endif

@end

NS_ASSUME_NONNULL_END
