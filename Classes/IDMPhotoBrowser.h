//
//  IDMPhotoBrowser.h
//  IDMPhotoBrowser
//
//  Created by Michael Waterfall on 14/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import "IDMPhoto.h"
#import "IDMPhotoProtocol.h"
#import "IDMCaptionView.h"

// Debug Logging
#if 0 // Set to 1 to enable debug logging
#define IDMLog(x, ...) NSLog(x, ## __VA_ARGS__);
#else
#define IDMLog(x, ...)
#endif

// Delgate
@class IDMPhotoBrowser;
@protocol IDMPhotoBrowserDelegate <NSObject>
@optional
- (void)photoBrowser:(IDMPhotoBrowser *)photoBrowser didDismissActionSheetWithButtonIndex:(NSUInteger)index;
- (IDMCaptionView *)photoBrowser:(IDMPhotoBrowser *)photoBrowser captionViewForPhotoAtIndex:(NSUInteger)index;
@end

// IDMPhotoBrowser
@interface IDMPhotoBrowser : UIViewController <UIScrollViewDelegate, UIActionSheetDelegate, MFMailComposeViewControllerDelegate> 

// Properties
@property (nonatomic, strong) id <IDMPhotoBrowserDelegate> delegate;

//Global
@property (nonatomic) BOOL autoHide;

//Top ToolBar
@property (nonatomic) BOOL displayTopToolbar;
@property (nonatomic) BOOL displayDoneButton;

//Botton ToolBar
@property (nonatomic) BOOL displayToolbar;
@property (nonatomic) BOOL displayArrowButton;
@property (nonatomic) BOOL displayCounterLabel;
@property (nonatomic) BOOL displayActionButton;
@property (nonatomic, retain) NSArray *actionButtonTitles;

// Init
- (id)initWithPhotos:(NSArray *)photosArray;

// Init with animation
- (id)initWithPhotos:(NSArray *)photosArray animatedFromView:(UIView*)view;

// Reloads the photo browser and refetches data
- (void)reloadData;

// Set page that photo browser starts on
- (void)setInitialPageIndex:(NSUInteger)index;

// Get IDMPhoto at index
- (id<IDMPhoto>)photoAtIndex:(NSUInteger)index;

//Dismiss Photo Browser
- (void)dismissPhotoBrowser; //animated by default
- (void)dismissPhotoBrowser:(BOOL)animated;

/** Customizations **/

// Top toolbar item
-(void)addTopToolBarItem:(UIBarButtonItem *)item atPosition:(NSInteger)position;
-(void)addTopToolBarItem:(UIBarButtonItem *)item;
-(void)setTopToolBarItems:(NSArray *)items;

// Toolbar item
-(void)addToolBarItem:(UIBarButtonItem *)item atPosition:(NSInteger)position;
-(void)addToolBarItem:(UIBarButtonItem *)item;
-(void)setToolBarItems:(NSArray *)items;

@end
