#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, EPCalloutArrowDirection) {
    EPCalloutArrowDirectionNone   = 0,
    EPCalloutArrowDirectionTop    = 1,
    EPCalloutArrowDirectionLeft   = 1 << 1,
    EPCalloutArrowDirectionBottom = 1 << 2,
    EPCalloutArrowDirectionRight  = 1 << 3
};

extern NSInteger const EPCalloutPermittedArrowDirectionAny;

@class EPCalloutView;

@protocol EPCalloutViewDelegate <NSObject>
/**
 *  Used to notify the delegate when the callout is forced to position outside of the constraining view
 *
 *  @param calloutView     the view that is positioned offscreen
 *  @param offscreenOffset a CGPoint indicating the offset from screen ie: {-4,-8} is 4 pts left, and 8 points above the constraining view.  {10, 5} is 10 points to the right and 5 points below the constraining view
 */
- (void)calloutView:(EPCalloutView *)calloutView positionedOffscreenWithOffset:(CGPoint)offscreenOffset;

/**
 *  Called when the callout has been tapped
 *
 *  @param calloutView the callout that was tapped
 */
- (void)calloutViewTapped:(EPCalloutView *)calloutView;

/**
 *  Called when the callout is removed from the view hierarchy.
 *
 *  @param calloutView the callout that was removed
 */
- (void)calloutViewRemovedFromViewHierarchy:(EPCalloutView *)calloutView;
@end

@interface EPCalloutView : UIView

/**
 *  Callout delegate
 */
@property (nonatomic, weak) id<EPCalloutViewDelegate>delegate;

/**
 *  View that will be displayed inside the callout. When this is set, the contentViewPreferredSize is set to the current bounds.size of the incoming content view. If you want a different size, for now you must manually override contentViewPreferredSize AFTER setting the contentView.
 */
@property (nonatomic, strong) UIView *contentView;

/**
 *  When drawing the content view, these will indicate distance from each side
 */
@property (nonatomic) UIEdgeInsets internalInsets;

/**
 *  When positioning the popover, these are the distances from the constraining view to position
 */
@property (nonatomic) UIEdgeInsets externalInsets;

/**
 *  The preferred size of the contentView contained within the callout when using a custom content view
 *  @warning must be set AFTER setting the contentView
 */
@property (nonatomic) CGSize contentViewPreferredSize;

/**
 *  The corner radius to use for the container view
 */
@property (nonatomic) CGFloat cornerRadius;

/**
 *  The size to draw the arrow
 */
@property (nonatomic) CGSize arrowSize;

/**
 *  The amount of space the callout should leave between itself and the horizontal edges of its constraining view. This is the total padding, not per side, and is split evenly between left and right.
 */
@property (nonatomic) CGFloat contentViewConstraintPaddingHorizontal;

/**
 *  The amount of space the callout should leave between itself and the vertical edges of its constraining view. This is the total padding, not per side, and is split evenly between top and bottom.
 */
@property (nonatomic) CGFloat contentViewConstraintPaddingVertical;

/**
 *  Whether or not to highlight in response to user touch.  Defaults to YES.
 */
@property (nonatomic) BOOL shouldHighlightOnTouch;

/**
 *  The current arrow direction of the callout
 */
@property (nonatomic, readonly) EPCalloutArrowDirection currentArrowDirection;

/**
 *  The available arrow directions declared w/ bitwise or -- EPCalloutArrowDirectionTop | EPCalloutArrowDirectionBottom
 *  @default - EPCalloutPermittedArrowDirectionAny
 */
@property (nonatomic) NSInteger permittedArrowDirections;

/**
 *  If the constraining view has changed, and you want the callout to readjust itself based on new parameters.
 */
- (void)updatePresentation;

/**
 *  Present the callout
 *
 *  @param rect the rectangle to position off of
 *  @param view the view to add the callout and constrain it within
 */
- (void)presentFromRect:(CGRect)presentationRect inView:(UIView *)view;

/**
 *  Present the callout
 *
 *  @param rect             the rectangle to position off of
 *  @param view             the view to add the callout to
 *  @param constrainingView the view to constrain the callout positioning
 */
- (void)presentFromRect:(CGRect)presentationRect inView:(UIView *)view withConstrainingView:(UIView *)constrainingView;

/**
 *  Dismiss the callout
 */
- (void)dismissCalloutAnimated:(BOOL)animated;

@end
