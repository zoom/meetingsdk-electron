//
//  ZMSpellCheckSettingsManager.h
//  zChatComponent
//
//  Created by Yong Zhou on 8/1/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSpellCheckSettingsManager : NSObject

+ (instancetype)shared;

// get continuous spell checking status
- (BOOL)isContinuousSpellCheckingEnabled;

// set continuous spell checking status
- (void)setContinuousSpellCheckingEnabled:(BOOL)enabled sender:(id _Nullable)sender;

// get grammar checking status
- (BOOL)isGrammarCheckingEnabled;

// set grammar checking status
- (void)setGrammarCheckingEnabled:(BOOL)enabled sender:(id _Nullable)sender;

// get automatic spelling correction status
- (BOOL)isAutomaticSpellingCorrectionEnabled;

// set automatic spelling correction status
- (void)setAutomaticSpellingCorrectionEnabled:(BOOL)enabled sender:(id _Nullable)sender;

@end

NS_ASSUME_NONNULL_END 
