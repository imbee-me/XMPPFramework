//
//  XMPPIQ+OMEMO.h
//  XMPPFramework
//
//  Created by Chris Ballinger on 4/21/16.
//
//

#import <Foundation/Foundation.h>
#import "XMPPIQ.h"
#import "OMEMOBundle.h"

NS_ASSUME_NONNULL_BEGIN
@interface XMPPIQ (OMEMO)

/** iq stanza for manually fetching deviceIds list. This should be handled automatically by PEP. */
+ (XMPPIQ*) omemo_iqFetchDeviceIdsForJID:(XMPPJID*)jid
                               elementId:(nullable NSString*)elementId;

/** iq stanza for publishing your device ids. The Device IDs are integers between 1 and 2^31 - 1 */
+ (XMPPIQ*) omemo_iqPublishDeviceIds:(NSArray<NSNumber*>*)deviceIds
                       elementId:(nullable NSString*)elementId;

/** iq stanza for publishing bundle for device */
+ (XMPPIQ*) omemo_iqPublishBundle:(OMEMOBundle*)bundle
                 elementId:(nullable NSString*)elementId;

/** iq stanza for fetching remote bundle */
+ (XMPPIQ*) omemo_iqFetchBundleForDeviceId:(uint32_t)deviceId
                                       jid:(XMPPJID*)jid
                                 elementId:(nullable NSString*)elementId;

/** Serialize bundle from IQ */
- (nullable OMEMOBundle*) omemo_bundle;

@end
NS_ASSUME_NONNULL_END