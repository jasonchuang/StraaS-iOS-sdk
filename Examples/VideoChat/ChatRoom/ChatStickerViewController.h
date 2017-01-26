//
//  ChatStickerViewController.h
//  VideoChat
//
//  Created by Lee on 04/11/2016.
//  Copyright © 2016 StraaS.io. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ChatViewController.h"
#import <StraaSMessagingSDK/STSChatroomConnectionOptions.h>

/**
 ChatStickerViewController is a StraaS.io chatroom UI with sticker input. It is meant to be subclassed.
 If you don't want to use our sticker input feature, use ChatViewController instead.
 */
@interface ChatStickerViewController : UIViewController <STSChatEventDelegate, ChatStickerDelegate>

/**
 ChatVC is kind of ChatViewController object.
 You may customize its UI by setting its property.
 */
@property (nonatomic, readonly) ChatViewController * chatVC;

/**
 Current member token.
 */
@property (nonatomic, readonly) NSString * JWT;

/**
 Current chatroom name.
 */
@property (nonatomic, readonly) NSString * chatroomName;

/**
 Current connection options.
 */
@property (nonatomic, readonly) STSChatroomConnectionOptions connectionOptions;

/**
 StraaS Chat manager.
 */
@property (nonatomic, readonly) STSChatManager * manager;

/**
 StickerViewShowingHeight is the height of stickerView as stickerView is showing.
 */
@property (nonatomic) NSUInteger stickerViewShowingHeight;

/**
 Return a ChatStickerViewController object with default ChatViewController object as property.
 If you wanna override ChatViewController's method, use chatStickerViewControllerWithJWT:chatroomName:connectionOptions:chatViewController: instead.

 @param JWT The StraaS member token.
 @param chatroomName The chatroom name you want to connect to.
 @param connectionOptions The connection options to connect to the chat you want.
 @return An instance of ChatStickerViewController.
 */
+ (instancetype)chatStickerViewControllerWithJWT:(NSString *)JWT
                                    chatroomName:(NSString *)chatroomName
                               connectionOptions:(STSChatroomConnectionOptions)connectionOptions;

/**
 Return a ChatStickerViewController object with subClass of ChatViewController as property.
 If you do not have the needs to subclass ChatViewController, use chatStickerViewControllerWithJWT:chatroomName:connectionOptions: instead.
 
 @param JWT The StraaS member token.
 @param chatroomName The chatroom name you want to connect to.
 @param connectionOptions The connection options to connect to the chat you want.
 @param chatViewController A subclass of ChatViewController object.
 @return An instance of ChatStickerViewController.
 */
+ (instancetype)chatStickerViewControllerWithJWT:(NSString *)JWT
                                    chatroomName:(NSString *)chatroomName
                               connectionOptions:(STSChatroomConnectionOptions)connectionOptions
                              chatViewController:(id)chatViewController;

/**
 Return a ChatStickerViewController object initialized from JWT, chatroomName and connectionOptionsjo.
 If you wanna override ChatViewController's method, use chatStickerViewControllerWithJWT:chatroomName:connectionOptions:chatViewController: instead.
 
 @param JWT The StraaS member token.
 @param chatroomName The chatroom name you want to connect to.
 @param connectionOptions The connection options to connect to the chat you want.
 @return An instance of ChatStickerViewController.
 */
- (instancetype)initWithJWT:(NSString *)JWT
               chatroomName:(NSString *)chatroomName
          connectionOptions:(STSChatroomConnectionOptions)connectionOptions;

/**
 Return a ChatStickerViewController object initialized from JWT, chatroomName and connectionOptionsjo.
 If you do not have the needs to subclass ChatViewController, use chatStickerViewControllerWithJWT:chatroomName:connectionOptions: instead.
 
 @param JWT The StraaS member token.
 @param chatroomName The chatroom name you want to connect to.
 @param connectionOptions The connection options to connect to the chat you want.
 @param chatViewController A subClass of ChatViewController object.
 @return An instance of ChatStickerViewController.
 */
- (instancetype)initWithJWT:(NSString *)JWT
               chatroomName:(NSString *)chatroomName
          connectionOptions:(STSChatroomConnectionOptions)connectionOptions
         chatViewController:(id)chatViewController;

/**
 Configure application to use StraaS.io serveice.

 @param success A block object to be executed when the configuration finishes successfully.
 @param failure A block object to be executed when the task finishes unsuccessfully.
 */
- (void)configureApplication:(void(^)())success
                     failure:(void(^)(NSError * error))failure NS_REQUIRES_SUPER;

/**
 Connect to the chatroom with current JWT, chatroom name, and connection options.
 */
- (void)connectToChat NS_REQUIRES_SUPER;

/**
 Connect to the chatroom with specific JWT, chatroom name, and connection options.
 Note: ChatStickerViewController is designed to connect one chatroom only.
 This method would disconnect current connection and make a new connection to the chatroom.

 @param JWT The StraaS member JWT.
 @param chatroomName The chatroom name you want to connect to.
 @param connectionOptions The connection options to connect to the chat you want.
 */
- (void)connectToChatWithJWT:(NSString *)JWT
                chatroomName:(NSString *)chatroomName
           connectionOptions:(STSChatroomConnectionOptions)connectionOptions NS_REQUIRES_SUPER;


+ (instancetype)new __attribute__((unavailable("Use chatStickerViewControllerWithJWT:chatroomName:connectionOptions: instead.")));
- (instancetype)init  __attribute__((unavailable("Use initWithJWT:chatroomName:connectionOptions: instead.")));

#pragma mark - STSChatEventDelegate
/**
 The following methods are as same as STSChatEventDelegate.
 You may override any of this to do some customizations when the method is called.
*/
- (void)chatroomConnected:(STSChat *)chatroom NS_REQUIRES_SUPER;
- (void)chatroomDisconnected:(STSChat *)chatroom NS_REQUIRES_SUPER;
- (void)chatroom:(STSChat *)chatroom failToConnect:(NSError *)error NS_REQUIRES_SUPER;
- (void)chatroom:(STSChat *)chatroom error:(NSError *)error NS_REQUIRES_SUPER;
- (void)chatroomInputModeChanged:(STSChat *)chatroom NS_REQUIRES_SUPER;
- (void)chatroom:(STSChat *)chatroom usersJoined:(NSArray<STSChatUser *> *)users NS_REQUIRES_SUPER;
- (void)chatroom:(STSChat *)chatroom usersUpdated:(NSArray<STSChatUser *> *)users NS_REQUIRES_SUPER;
- (void)chatroom:(STSChat *)chatroom usersLeft:(NSArray<NSNumber *> *)userLabels NS_REQUIRES_SUPER;
- (void)chatroomUserCount:(STSChat *)chatroom NS_REQUIRES_SUPER;
- (void)chatroom:(STSChat *)chatroom messageAdded:(STSChatMessage *)message NS_REQUIRES_SUPER;
- (void)chatroom:(STSChat *)chatroom messageRemoved:(NSString *)messageId NS_REQUIRES_SUPER;
- (void)chatroomMessageFlushed:(STSChat *)chatroom NS_REQUIRES_SUPER;
- (void)chatroom:(STSChat *)chatroom aggregatedDataAdded:(NSDictionary *)aggregatedData NS_REQUIRES_SUPER;
- (void)chatroom:(STSChat *)chatroom rawDataAdded:(id)rawData NS_REQUIRES_SUPER;

#pragma mark - ChatStickerDelegate
/**
 The following methods are as same as ChatStickerDelegate.
 You may override any of this to do some customizations when the method is called.
 */
- (void)chatStickerDidLoad:(NSArray *)stickers NS_REQUIRES_SUPER;
- (void)showStickerView:(BOOL)animated NS_REQUIRES_SUPER;
- (void)dismissStickerView:(BOOL)animated NS_REQUIRES_SUPER;
- (BOOL)isStickerViewShowing NS_REQUIRES_SUPER;

@end
