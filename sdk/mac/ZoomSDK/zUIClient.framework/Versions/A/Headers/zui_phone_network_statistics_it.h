#ifndef _ZUI_PHONE_NETWORK_STATISTICS_IT_H_
#define _ZUI_PHONE_NETWORK_STATISTICS_IT_H_

#include "zSipCallModule/phone_namespace.h"
#include "zUI/model/model.h"

NS_SIPCALL_APP_START
class CmmSIPCallItem;
NS_SIPCALL_APP_END

/**
 * @brief Sink interface for callbacks from the Phone Network Statistics Panel
 * 
 * Implement this interface to receive notifications about user interactions
 * with the network statistics panel.
 */
class IZUIPhoneNetworkStatisticsSink
{
public:
    virtual ~IZUIPhoneNetworkStatisticsSink() = default;

    /**
     * @brief Called when the user clicks the "Report a problem" link
     * 
     * The implementer should handle this callback to open a problem
     * reporting dialog or workflow.
     */
    virtual void OnReportProblem() = 0;
};

/**
 * @brief Network quality type enumeration
 * 
 * Represents the overall network connection quality based on call_quality score (0-5).
 * Uses Zoom's standard thresholds: >= 4 = Strong, >= 2 = Average, > 0 = Poor.
 */
enum class NetworkQualityType
{
    kUnknown = 0,  // No quality data available
    kPoor = 1,     // call_quality > 0 && < 2.0 (weak connection)
    kAverage = 2,  // call_quality >= 2.0 && < 4.0 (medium connection)
    kStrong = 3    // call_quality >= 4.0 (strong connection)
};

/**
 * @brief Internal data model for Phone Network Statistics Panel
 * 
 * Contains reactive State<T> fields that automatically trigger UI updates
 * when values change. All fields are initialized to "--" (no data).
 * 
 * The callItem field enables reactive updates - when a new call item is set,
 * the manager automatically extracts and formats network metrics.
 */
struct PhoneNetworkStatisticsData
{
    // Call item source (reactive, triggers metric extraction when changed)
    zui::State<NS_SIPCALL_APP::CmmSIPCallItem*> _callItem = nullptr;
    
    // Connection quality indicator (enum-based for type safety)
    zui::State<NetworkQualityType> _connectionQuality = NetworkQualityType::kUnknown;
    
    // Bandwidth metrics (formatted strings with units)
    zui::State<std::string> _sendBandwidth = std::string("--");      // e.g., "10.4 kbps"
    zui::State<std::string> _receiveBandwidth = std::string("--");
    
    // Packet loss metrics (formatted percentages)
    zui::State<std::string> _sendPacketLoss = std::string("--");     // e.g., "0.1 %"
    zui::State<std::string> _receivePacketLoss = std::string("--");
    
    // Jitter metrics (formatted with ms units)
    zui::State<std::string> _sendJitter = std::string("--");         // e.g., "1 ms"
    zui::State<std::string> _receiveJitter = std::string("--");
    
    // Quality description strings (loaded from platform resources)
    zui::State<std::string> _qualityStrong;
    zui::State<std::string> _qualityAverage;
    zui::State<std::string> _qualityPoor;
    zui::State<std::string> _qualityUnknown;

    // Network quality icon paths
    zui::State<std::string> _networkIconUnknown;
    zui::State<std::string> _networkIconPoor;
    zui::State<std::string> _networkIconAverage;
    zui::State<std::string> _networkIconStrong;

    // UI labels (loaded from platform resources)
    zui::State<std::string> _windowTitle;             // "Network Statistics"
    zui::State<std::string> _headerItems;             // "Items"
    zui::State<std::string> _headerSend;              // "Send"
    zui::State<std::string> _headerReceive;           // "Receive"
    zui::State<std::string> _labelBandwidth;          // "Bandwidth"
    zui::State<std::string> _labelPacketLoss;         // "Packet loss"
    zui::State<std::string> _labelJitter;             // "Jitter"
    zui::State<std::string> _reportProblemText;       // "Report a problem"
};

/**
 * @brief Manager interface for controlling the Phone Network Statistics Panel
 * 
 * This interface provides methods to show, hide, and update the network
 * statistics panel. The panel is displayed as a popover-style window that
 * automatically hides when clicking outside or when losing focus.
 * 
 * Usage example:
 * @code
 *   IZUIPhoneNetworkStatisticsMgr* mgr = GetPhoneNetworkStatisticsMgr();
 *   mgr->SetSink(mySink);
 *   mgr->ShowAtPosition(100, 100, parentWindow);
 *   mgr->SetCallItem(activeCallItem);
 * @endcode
 */
class ZUIClient_API IZUIPhoneNetworkStatisticsMgr
{
public:
    virtual ~IZUIPhoneNetworkStatisticsMgr() = default;

    /**
     * @brief Displays the network statistics panel as a popover at specified coordinates
     * 
     * @param x Screen X coordinate for panel position
     * @param y Screen Y coordinate for panel position
     * @param parent Optional parent window handle for proper window ownership
     * 
     * The panel will be shown as a topmost popup window at the specified position.
     * If the panel is already visible, this will update its position.
     */
    virtual void ShowAtPosition(int x, int y, void* parent = nullptr) = 0;

    /**
     * @brief Hides the network statistics panel
     * 
     * The panel remains in memory and can be shown again with ShowAtPosition().
     */
    virtual void Hide() = 0;

    /**
     * @brief Closes and destroys the network statistics panel
     * 
     * This releases all resources associated with the panel. To show the panel
     * again after calling Close(), you must call ShowAtPosition().
     */
    virtual void Close() = 0;

    /**
     * @brief Queries the current visibility state of the panel
     * 
     * @return true if the panel is currently visible, false otherwise
     */
    virtual bool IsVisible() = 0;

    /**
     * @brief Returns the native window handle of the panel
     * 
     * @return Platform-specific window handle (HWND on Windows, NSWindow* on macOS)
     */
    virtual void* GetWindowHandle() = 0;

    /**
     * @brief Sets the sink object to receive callbacks from the panel
     * 
     * @param sink Pointer to the sink implementation (can be nullptr to unregister)
     */
    virtual void SetSink(IZUIPhoneNetworkStatisticsSink* sink) = 0;

    /**
     * @brief Sets the call item and extracts network metrics from its session summary
     * 
     * @param callItem Pointer to the active call item (pass nullptr to clear data)
     * 
     * This method extracts network statistics from the call item's session summary
     * (bandwidth, packet loss, jitter) and updates the panel display. If callItem
     * is nullptr or GetCallSessionSummary() returns nullptr, all fields will be
     * reset to "--".
     */
    virtual void SetCallItem(NS_SIPCALL_APP::CmmSIPCallItem* callItem) = 0;

    /**
     * @brief Get the internal data model (for view binding)
     * @return Reference to the data model
     */
    virtual PhoneNetworkStatisticsData& GetDataModel() = 0;

protected:
};

#endif // _ZUI_PHONE_NETWORK_STATISTICS_IT_H_

