//
//  ZMSlashCommandMeetingProtocol.h
//  zChatComponent
//
//  Created by dikey.jin on 1/20/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum
{
    ZMUserGroupMeetingCallPermission_None = 0,
    ZMUserGroupMeetingCallPermission_Able,
    ZMUserGroupMeetingCallPermission_Unable,
    ZMUserGroupMeetingCallPermission_UnableWithCMCChannel,
    ZMUserGroupMeetingCallPermission_UnableWithNotAdminOrOwner,
    ZMUserGroupMeetingCallPermission_UnableWithDisable,
    ZMUserGroupMeetingCallPermission_Limit1000Exceeded,
    // Meeting Invitee Restriction Reasons
    ZMUserGroupMeetingCallPermission_BlockContact,      // Single user blocked
    ZMUserGroupMeetingCallPermission_BlockContactMultiple, // Multiple users blocked
    ZMUserGroupMeetingCallPermission_IB,               // Information Barriers
    ZMUserGroupMeetingCallPermission_UnknowError,
} ZMUserGroupMeetingCallPermissionState;

// Callback block for user confirmation action
typedef void(^ZMUserGroupMeetingConfirmationCallback)(BOOL userConfirmed);

@protocol ZMSlashCommandMeetingProtocol <NSObject>
@optional
+ (instancetype)shared;
- (void)releaseInstance;

/**
 * Start meeting v2 with slash command
 * @param input Original input string
 * @param sessionId Session ID for the meeting
 * @param inviteJids Array of JIDs to invite (including those not in channel)
 * @param notInChannelJids Array of JIDs not in channel
 * @param hasAtAll Whether the command contains @all mention
 * @param atUserCells Array of ZMPTAtUserCell objects from input (optional)
 * @return ZMUserGroupMeetingCallPermissionState permission result
 */
- (ZMUserGroupMeetingCallPermissionState)startMeetingV2WithInput:(NSString *)input
                                                       sessionId:(NSString *)sessionId
                                                      inviteJids:(NSArray<NSString *> *)inviteJids
                                                  notInChannelJids:(NSArray<NSString *> *)notInChannelJids
                                                         hasAtAll:(BOOL)hasAtAll
                                                       atUserCells:(nullable NSArray<ZMPTAtUserCell *> *)atUserCells;

/**
 * Check user group meeting permission
 * @param sessionId Session ID for the meeting
 * @param input Original input string
 * @param hasAtAll Whether the input contains @all
 * @return ZMUserGroupMeetingCallPermissionState permission result
 */
- (ZMUserGroupMeetingCallPermissionState)checkUserGroupMeetingPermission:(NSString *)sessionId
                                                                   input:(NSString *)input
                                                                hasAtAll:(BOOL)hasAtAll;

/**
 * Check user group meeting permission with confirmation dialog for Able state
 * @param sessionId Session ID for the meeting
 * @param input Original input string
 * @param hasAtAll Whether the input contains @all
 * @param inviteJids Array of JIDs to invite
 * @param notInChannelJids Array of JIDs not in channel
 * @param callback Callback block called when user confirms or cancels
 * @param atUserCells Array of ZMPTAtUserCell objects from input (optional)
 * @return ZMUserGroupMeetingCallPermissionState permission result
 */
- (ZMUserGroupMeetingCallPermissionState)checkUserGroupMeetingPermissionWithConfirmation:(NSString *)sessionId
                                                                                   input:(NSString *)input
                                                                                hasAtAll:(BOOL)hasAtAll
                                                                              inviteJids:(NSArray<NSString *> *)inviteJids
                                                                          notInChannelJids:(NSArray<NSString *> *)notInChannelJids
                                                                             atUserCells:(nullable NSArray<ZMPTAtUserCell *> *)atUserCells
                                                                                  callback:(nullable ZMUserGroupMeetingConfirmationCallback)callback;

/**
 * Get room meeting list for @ mention
 * @param key Search key
 * @param sessionId Session ID
 * @return Array of room JIDs
 */
- (NSArray<NSString *> *)getRoomMeetingListWithKey:(NSString *)key sessionId:(NSString *)sessionId;

/**
 * Filter invitees and check for meeting restrictions
 * @param sessionId Session ID for the meeting
 * @param isChannelMeetingAction Whether this is a channel meeting action
 * @param allIds Array of all IDs (JIDs, group IDs, @all) from input
 * @param hasAtAll Whether the command contains @all mention
 * @param atUserCells Array of ZMPTAtUserCell objects from input (optional)
 * @return ZMUserGroupMeetingCallPermissionState permission result
 */
- (ZMUserGroupMeetingCallPermissionState)filterInviteesAndCheckRestrictions:(NSString *)sessionId
                                                         isChannelMeetingAction:(BOOL)isChannelMeetingAction
                                                                           allIds:(NSArray<NSString *> *)allIds
                                                                          hasAtAll:(BOOL)hasAtAll
                                                                       atUserCells:(nullable NSArray<ZMPTAtUserCell *> *)atUserCells;

@end

NS_ASSUME_NONNULL_END 
