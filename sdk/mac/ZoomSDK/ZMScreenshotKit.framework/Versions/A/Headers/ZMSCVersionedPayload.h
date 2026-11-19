//
//  ZMSCVersionedPayload.h
//  ZMScreenshotKit
//
//  Envelope carrying a schema version alongside an opaque payload blob
//  (the payload is itself an NSKeyedArchiver-encoded object, produced by
//  the caller). On-disk layout:
//      [optional ZMSCDataEncryptor envelope]( NSKeyedArchiver(ZMSCVersionedPayload) )
//  Legacy files (no wrapper) unarchive directly to the payload type and
//  are treated as schemaVersion 0 by the caller.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSCVersionedPayload : NSObject <NSSecureCoding>

@property (nonatomic, readonly) NSInteger schemaVersion;
@property (nonatomic, readonly, nullable) NSData *payloadData;

- (instancetype)initWithSchemaVersion:(NSInteger)schemaVersion
                          payloadData:(nullable NSData *)payloadData NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
