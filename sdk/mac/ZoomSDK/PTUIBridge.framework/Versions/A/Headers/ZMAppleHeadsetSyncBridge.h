//
//  ZMAppleHeadsetSyncBridge.h
//  PTUIBridge
//
//  Thin C bridge that lets the Meeting process create/destroy the native Apple
//  headset (AirPods) sync instance through PTUIBridge's single libzzhostlib
//  copy. VideoUI links PTUIBridge (already present in the meeting process) and
//  calls these instead of linking libzzhostlib itself, so there is exactly one
//  copy of the native stack per process.
//
//  Opaque void* is used so this public header does not pull in the non-modular
//  zzhost_ifc.h. Callers cast:
//    - callback : IAppleHeadsetSyncCallback *
//    - return   : IAppleHeadsetSync *
//

#ifndef ZMAppleHeadsetSyncBridge_h
#define ZMAppleHeadsetSyncBridge_h

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((visibility("default"))) void *ZMPTCreateAppleHeadsetSync(void *callback);
__attribute__((visibility("default"))) void ZMPTDestroyAppleHeadsetSync(void *instance);

#ifdef __cplusplus
}
#endif

#endif /* ZMAppleHeadsetSyncBridge_h */
