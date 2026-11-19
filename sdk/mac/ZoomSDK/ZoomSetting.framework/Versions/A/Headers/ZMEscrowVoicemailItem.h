//
//  ZMEscrowVoicemailItem.h
//  ZoomSetting
//
//  Created by ares.lin on 2023/6/21.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

namespace ZOOM_PT_KB_CRYPTO_NS {
    class ZmSIPVoiceMailItem;
};

@interface ZMEscrowVoicemailItem : NSObject

@property (nonatomic, copy) NSString *voicemailID;
@property (nonatomic, assign) long long createTime;
@property (nonatomic, copy) NSString *fromUserName;
@property (nonatomic, copy) NSString *fromPhoneNumber;
@property (nonatomic, copy) NSString *fromJid;
@property (nonatomic, copy) NSString *fwdExtID;
@property (nonatomic, copy) NSString *fwdExtName;
@property (nonatomic, assign) BOOL isRestricted;
@property (nonatomic, assign) BOOL isPhoneNumberVerified;
@property (nonatomic, assign) BOOL isAdvanceEncrypted;
@property (nonatomic, copy, nullable) NSString *encryptionMetadata;
@property (nonatomic, copy) NSString *mediaFileID;
@property (nonatomic, copy) NSString *playUrl;
@property (nonatomic, copy) NSString *downloadUrl;
@property (nonatomic, assign) long long mediaFileDuration;
@property (nonatomic, copy) NSString *mediaFormat;
@property (nonatomic, copy) NSString *ownerUserID;

- (instancetype)initWithItem:(ZOOM_PT_KB_CRYPTO_NS::ZmSIPVoiceMailItem)item;

@end

NS_ASSUME_NONNULL_END
