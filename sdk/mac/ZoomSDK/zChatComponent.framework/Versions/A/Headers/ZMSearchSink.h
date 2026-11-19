//
//  ZMSearchSink.h
//  zChatComponent
//
//  Created by Yong Zhou on 10/27/25.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#ifndef ZMSearchSink_h
#define ZMSearchSink_h

#include "cmmlib/CmmDef.h"
#include "zChatApp/search/SearchMgr.h"

/**
 * ZMSearchSink - Dedicated sink for handling all search-related callbacks
 * This class inherits from SearchMgrUICallBack and provides a clean separation
 * of search functionality from the main messenger UI sink hierarchy.
 */
class ZMSearchSink : public ns_zoom_messager::SearchMgrUICallBack
{
public:
    ZMSearchSink();
    virtual ~ZMSearchSink();
    
    /**
     * Register / Unregister this sink with the SearchMgr to receive search callbacks
     */
    void registerUISink();
    void unregisterUISink();
    
    void setSinkDelegate(ns_zoom_messager::SearchMgrUICallBack * sink) { m_sink = sink; }
    
    // Pure virtual functions from SearchMgrUICallBack that must be implemented
    virtual void Indicate_SearchMessageResponse(const CString& reqID, CmmUInt32 result, const ns_zoom_messager::MessageContentSearchResponse& response) override;
    virtual void Indicate_SearchFileResponse(const CString& reqID, CmmUInt32 result, const ns_zoom_messager::SearchFileResult& response) override;
    
    virtual void Indicate_LocalSearchContactResponse(const CString& reqID, const std::vector<CString>& results) override;
    
    // Optional virtual functions from SearchMgrUICallBack with default implementations
    virtual void Indicate_SearchMessageBySenderResponse(const CString& reqID, CmmUInt32 result, const ns_zoom_messager::SearchMessageBySenderResponse& response) override;
    virtual void Indicate_QueryLocalMsgCtxResponse(const CString& reqID, const std::vector<CString>& msgIDs) override;
    virtual void Indicate_SearchChannelResponse(const CString& reqID, CmmUInt32 result, const ns_zoom_messager::ChannelSearchResponse& response) override;
    virtual void Indicate_SearchChannelResponse(const CString& reqID, CmmUInt32 result, const CAString& response) override;
    virtual void Indicate_SearchChannelMemberResponse(const CString& reqID, CmmUInt32 result, const ns_zoom_messager::ChannelMemberSearchResponse& response) override;
    virtual void Indicate_BatchSearchContactsResponse(const CString& reqID, CmmUInt32 result, const ns_zoom_messager::arrContactSearchResult& contacts) override;
    virtual void Indicate_LocalSearchMSGResponse(const CString& reqID, const ns_zoom_messager::MessageContentSearchResponse& response) override;
    virtual void Indicate_LocalSearchFileResponse(const CString& reqID, const ns_zoom_messager::SearchFileResult& result) override;
    virtual void Indicate_ExhaustiveSearchContactResponse(const CString& reqID, CmmUInt32 result, const ns_zoom_messager::ExhaustiveContactSearchResult& response) override;
    virtual void Indicate_SearchContactAndChannelResponse(const CString& reqID, CmmUInt32 result, const ns_zoom_messager::ContactAndChannelSearchResult& response) override;
    virtual void Indicate_SearchContactFromAsyncResponse(const CString& reqID, CmmUInt32 result, const CmmChat::arrContactSearchResult& searchResult) override;
    
private:
    bool m_isRegistered;
    ns_zoom_messager::SearchMgrUICallBack *m_sink;
};

#endif /* ZMSearchSink_h */

