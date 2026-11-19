//
//  ZMFilePreViewItem.h
//  FilePreviewDemo
//
//  Created by groot.ding on 2/6/20.
//  Copyright © 2020 groot.ding. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ZMButtonItem;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMFileDownLoadState) {
    ZMFileDownLoadNone, //it's ok add default None
    ZMFileDownLoaded,
    ZMFileDownLoading,
    ZMFileDownLoadedFail,
};

@interface ZMFilePreViewItem : NSObject

@property (nonatomic, copy) NSString *fileId;

@property (nonatomic, copy) NSString *filePath;

@property (nonatomic, copy) NSString *previewPath;

@property (nonatomic, retain) id representedObject;

@property (nonatomic, assign) ZMFileDownLoadState downloadState;

@property (nonatomic, retain) NSArray <ZMButtonItem *> *hoverButtonItems;

@property (nonatomic, copy, nullable) NSString *reqID;
@property (nonatomic ,retain, nullable) NSImage *image;
@property (nonatomic ,retain, nullable) NSImage *thumbnailImage;

@end

NS_ASSUME_NONNULL_END
