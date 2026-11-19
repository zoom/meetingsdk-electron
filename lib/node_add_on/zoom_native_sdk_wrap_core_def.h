#ifndef _zoom_native_sdk_wrap_core_def_h_
#define _zoom_native_sdk_wrap_core_def_h_
#include <string>
#include <vector>
#if (defined BUILD_WIN)
#define ZoomSTRING std::wstring
#else
#define ZoomSTRING std::string
#endif
#ifdef BUILD_WIN
#define ZOOM_HIDE_SYMBOL
#else
#define ZOOM_HIDE_SYMBOL __attribute__((visibility("hidden")))
#endif

/**
 * @brief Enumeration of common errors of SDK.
 */
enum ZNSDKError
{
	/** Success. */
	ZNSDKERR_SUCCESS = 0,
	/** The feature is currently invalid. */
	ZNSDKERR_NO_IMPL,
	/** Incorrect usage of the feature. */
	ZNSDKERR_WRONG_USAGE,
	/** Wrong parameter. */
	ZNSDKERR_INVALID_PARAMETER,
	/** Loading module failed. */
	ZNSDKERR_MODULE_LOAD_FAILED,
	/** No memory is allocated. */
	ZNSDKERR_MEMORY_FAILED,
	/** Internal service error. */
	ZNSDKERR_SERVICE_FAILED,
	/** Not initialized before the usage. */
	ZNSDKERR_UNINITIALIZE,
	/** Not authorized before the usage. */
	ZNSDKERR_UNAUTHENTICATION,
	/** No recording in process. */
	ZNSDKERR_NORECORDINGINPROCESS,
	/** Transcoder module is not found. */
	ZNSDKERR_TRANSCODER_NOFOUND,
	/** The video service is not ready. */
	ZNSDKERR_VIDEO_NOTREADY,
	/** No permission. */
	ZNSDKERR_NO_PERMISSION,
	/** Unknown error. */
	ZNSDKERR_UNKNOWN,
	/** The other instance of the SDK is in process. */
	ZNSDKERR_OTHER_SDK_INSTANCE_RUNNING,
	/** SDK internal error. */
	ZNSDKERR_INTERNAL_ERROR,
	/** No audio device found. */
	ZNSDKERR_NO_AUDIODEVICE_ISFOUND,
	/** No video device found. */
	ZNSDKERR_NO_VIDEODEVICE_ISFOUND,
	/** API calls too frequently. */
	ZNSDKERR_TOO_FREQUENT_CALL,
	/** User can't be assigned with new privilege. */
	ZNSDKERR_FAIL_ASSIGN_USER_PRIVILEGE,
	/** The current meeting doesn't support the feature. */
	ZNSDKERR_MEETING_DONT_SUPPORT_FEATURE,
	/** The current user is not the presenter. */
	ZNSDKERR_MEETING_NOT_SHARE_SENDER,
	/** There is no sharing. */
	ZNSDKERR_MEETING_YOU_HAVE_NO_SHARE,
	/** Incorrect ViewType parameters. */
	ZNSDKERR_MEETING_VIEWTYPE_PARAMETER_IS_WRONG,
	/** Annotation is disabled. */
	ZNSDKERR_MEETING_ANNOTATION_IS_OFF,
	/** Current OS doesn't support the setting. */
	ZNSDKERR_SETTING_OS_DONT_SUPPORT,
	/** Email login is disable. */
	ZNSDKERR_EMAIL_LOGIN_IS_DISABLED,
	/** Computer doesn't meet the minimum requirements to use virtual background feature. */
	ZNSDKERR_HARDWARE_NOT_MEET_FOR_VB,
	/** Need process disclaimer. */
	ZNSDKERR_NEED_USER_CONFIRM_RECORD_DISCLAIMER,
	/** There is no raw data of sharing. */
	ZNSDKERR_NO_SHARE_DATA,
	/** Share can not subscribe myself. */
	ZNSDKERR_SHARE_CANNOT_SUBSCRIBE_MYSELF,
	/** Not in meeting. */
	ZNSDKERR_NOT_IN_MEETING,
	/** Not Joining audio. */
	ZNSDKERR_NOT_JOIN_AUDIO,
	/** The current device doesn't support the feature. */
	ZNSDKERR_HARDWARE_DONT_SUPPORT,
	/** Domain not support. */
	ZNSDKERR_DOMAIN_DONT_SUPPORT,
	/** Remote control is disabled. */
	ZNSDKERR_MEETING_REMOTE_CONTROL_IS_OFF,
	/** File transfer fail. */
	ZNSDKERR_FILETRANSFER_ERROR,
};

/**
 * @brief Enumeration of the text resource type used by the SDK.
 */
enum ZNSDK_LANGUAGE_ID
{
	/** For initialization. */
	ZNLANGUAGE_Unknown = 0,
	/** In English. */
	ZNLANGUAGE_English,
	/** In simplified Chinese. */
	ZNLANGUAGE_Chinese_Simplified,
	/** In traditional Chinese. */
	ZNLANGUAGE_Chinese_Traditional,
	/** In Japanese. */
	ZNLANGUAGE_Japanese,
	/** In Spanish. */
	ZNLANGUAGE_Spanish,
	/** In German. */
	ZNLANGUAGE_German,
	/** In French. */
	ZNLANGUAGE_French,
	/** In Portuguese. */
	ZNLANGUAGE_Portuguese,
	/** In Russian. */
	ZNLANGUAGE_Russian,
	/** In Korean. */
	ZNLANGUAGE_Korean,
	/** In Vietnamese. */
	ZNLANGUAGE_Vietnamese,
	/** In Italian. */
	ZNLANGUAGE_Italian,
	/** In Polish. */
	ZNLANGUAGE_Polish,
	/** In Turkish. */
	ZNLANGUAGE_Turkish,
	/** In Indonesian. */
	ZNLANGUAGE_Indonesian,
	/** In Dutch. */
	ZNLANGUAGE_Dutch,
};

/**
 * @brief Enumeration of SDK authentication result.
 */
enum ZNAuthResult
{
	/** Authentication is successful. */
	ZNAUTHRET_SUCCESS = 0,
	/**  The key or secret to authenticate is empty. */
	ZNAUTHRET_KEYORSECRETEMPTY,
	/** The key or secret to authenticate is wrong */
	ZNAUTHRET_KEYORSECRETWRONG,
	/** The user account does not support. */
	ZNAUTHRET_ACCOUNTNOTSUPPORT,
	/** The user account is not enabled for SDK. */
	ZNAUTHRET_ACCOUNTNOTENABLESDK,
	/** Unknown error. */
	ZNAUTHRET_UNKNOWN,
	/** Service is busy. */
	ZNAUTHRET_SERVICE_BUSY,
	/** Initial status. */
	ZNAUTHRET_NONE,
	/** Time out. */
	ZNAUTHRET_OVERTIME,
	/** Network issues. */
	ZNAUTHRET_NETWORKISSUE,
	/** Account does not support this SDK version. */
	ZNAUTHRET_CLIENT_INCOMPATIBLE, 
	/** The jwt token to authenticate is wrong. */
	ZNAUTHRET_JWTTOKENWRONG, 
	/** The authentication rate limit is exceeded. */
	ZNAUTHRET_LIMIT_EXCEEDED_EXCEPTION, 
};

/**
 * @brief Custom resource type used by the SDK.
 */
enum ZNCustomizedLanguageType
{
	/** No use of the custom resource. */
	ZN_CustomizedLanguage_None,
	/** Use the specified file path to assign the custom resource. */
	ZN_CustomizedLanguage_FilePath,
	/** Use the specified content to assign the custom resource. */
	ZN_CustomizedLanguage_Content,
};

/**
 * @brief The custom resource information used by the SDK.
 */
typedef struct _ZNCustomizedLanguageInfo
{
	/** Resource name. */
	ZoomSTRING langName;
	/** The value should be the full path of the resource file when the langType value is CustomizedLanguage_FilePath, including the file name. When the langType value is CustomizedLanguage_Content, the value saves the content of the resource. */
	ZoomSTRING langInfo;
	/** Use the custom resource type. */
	ZNCustomizedLanguageType langType;
	_ZNCustomizedLanguageInfo()
	{
		langType = ZN_CustomizedLanguage_None;
	}
}ZNCustomizedLanguageInfo;

/**
 * @brief SDK configuration options.
 * @note This structure is used only for the SDK initialization to configure the custom resource file and choose whether to use the UI mode.
 */
typedef struct _ZNConfigurableOptions
{
	/** The custom resource information. */
	ZNCustomizedLanguageInfo customizedLang;
	/** Additional functional configuration. The function currently supports whether to use the custom UI mode only. When the value of the useCustomUI is true, it indicates the custom UI mode will be used. Otherwise, the Zoom UI mode will be used. */
	bool useCustomUI;
	_ZNConfigurableOptions()
	{
		useCustomUI = false;
	}
}ZNConfigurableOptions;

/**
 * @brief Enumeration of locale type.
 */
enum ZNSDK_APP_Locale
{
	ZNSDK_APP_Locale_Default,
	ZNSDK_APP_Locale_CN,
};

/**
 * @brief Enumeration of video render mode. For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0066515.>.
 */
enum ZNZoomSDKVideoRenderMode
{
	/** For initialization. */
	ZNSDKVideoRenderMode_None = 0,
	/** Auto mode. */
	ZNSDKVideoRenderMode_Auto,
	/** D3D11EnableFLIP mode. */
	ZNSDKVideoRenderMode_D3D11EnableFLIP,
	/** D3D11 mode. */
	ZNSDKVideoRenderMode_D3D11,
	/** D3D9 mode. */
	ZNSDKVideoRenderMode_D3D9,
	/** GDI mode. */
	ZNSDKVideoRenderMode_GDI,
};

/**
 * @brief Enumeration of render post processing mode. For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0066515.>.
 */
enum ZNZoomSDKRenderPostProcessing
{
	/** For initialization. */
	ZNZoomSDKRenderPostProcessing_None = 0,
	/** Auto mode. */
	ZNZoomSDKRenderPostProcessing_Auto,
	/** Enable post processing. */
	ZNZoomSDKRenderPostProcessing_Enable,
	/** Disable post processing. */
	ZNZoomSDKRenderPostProcessing_Disable,
};

/**
 * @brief Enumeration of video capturing mode. For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0066515.>.
 */
enum ZNZoomSDKVideoCaptureMethod
{
	/** For initialization. */
	ZNZoomSDKVideoCaptureMethod_None = 0,
	/** Auto mode. */
	ZNZoomSDKVideoCaptureMethod_Auto,
	/** Direct show mode. */
	ZNZoomSDKVideoCaptureMethod_DirectSHow,
	/** Media foundation mode. */
	ZNZoomSDKVideoCaptureMethod_MediaFoundation,
};

/**
 * @brief Video render options. For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0066515.>.
 */
typedef struct tagZNZoomSDKRenderOptions
{
	/** Video render mode. */
	ZNZoomSDKVideoRenderMode    videoRenderMode;
	/** Render post processing mode. */
	ZNZoomSDKRenderPostProcessing renderPostProcessing;
	/** Video capture method. */
	ZNZoomSDKVideoCaptureMethod videoCaptureMethod;
	tagZNZoomSDKRenderOptions()
	{
		videoRenderMode = ZNSDKVideoRenderMode_None;
		renderPostProcessing = ZNZoomSDKRenderPostProcessing_Auto;
		videoCaptureMethod = ZNZoomSDKVideoCaptureMethod_Auto;
	}
}ZNZoomSDKRenderOptions;

/**
 * @brief Enumeration of memory modes for raw data handling.
 */
enum ZNSDKRawDataMemoryMode
{
	/** Use stack memory. */
	ZNSDKRawDataMemoryModeStack,
	/** Use heap memory. */
	ZNSDKRawDataMemoryModeHeap
};

/**
 * @brief Rawdata options.
 */
typedef struct tagZNRawDataOptions
{
	/** false -- YUV420data, true -- intermediate data. */
	bool enableRawdataIntermediateMode;
	/** Video rawdata memory mode. */
	ZNSDKRawDataMemoryMode  videoRawdataMemoryMode;
	/** Share rawdata memory mode. */
	ZNSDKRawDataMemoryMode  shareRawdataMemoryMode;
	/** Audio rawdata memory mode. */
	ZNSDKRawDataMemoryMode  audioRawdataMemoryMode;
	tagZNRawDataOptions()
	{
#if (defined _WIN32)
		enableRawdataIntermediateMode = true;
#else
		enableRawdataIntermediateMode = false;
#endif
		videoRawdataMemoryMode = ZNSDKRawDataMemoryModeStack;
		shareRawdataMemoryMode = ZNSDKRawDataMemoryModeStack;
		audioRawdataMemoryMode = ZNSDKRawDataMemoryModeStack;
	}
}ZNRawDataOptions;

/**
 * @brief Initialize the SDK Parameter.
 */
typedef struct _ZNInitParam
{
	/** The path of sdk.dll */
	ZoomSTRING path;
	/** Web domain. */
	ZoomSTRING domain;
	/** Enable log feature. */
	bool enable_log;
	/** The ID of the SDK language. */
	ZNSDK_LANGUAGE_ID langid;
	/** Support URL. */
	ZoomSTRING strSupportUrl;
	/** Branding name. */
	ZoomSTRING strBrandingName;
	/** The configuration options of the SDK. */
	ZNConfigurableOptions obConfigOpts;
	/** Size of a log file in M(megabyte). The default size is 5M. There are 5 log files in total and the file size varies from 1M to 50M. */
	unsigned int logFileSize;
	/** Enable generate dump file if the app crashed. */
	bool enableGeneratDump;
	/** Locale. */
	ZNSDK_APP_Locale locale;
	/** Per-monitor awareness mode. */
	bool permonitor_awareness_mode;
	/** Render options. */
	ZNZoomSDKRenderOptions renderOpts;
	/** Raw data options. */
	ZNRawDataOptions rawdataOpts;
	/** Only for Mac. */
	ZoomSTRING customLocalizationFilePath;
	/** Wrapper type. */
	unsigned int wrapperType;
	_ZNInitParam(){
		enable_log = true;
		langid = ZNLANGUAGE_Unknown;
		locale = ZNSDK_APP_Locale_Default;
		logFileSize = 5;
		enableGeneratDump = false;
		permonitor_awareness_mode = true;
		wrapperType = 3;
	}
}ZNInitParam;

/**
 * @brief SDK authentication parameter with JWT token or public app key.
 */
typedef struct _ZNAuthContext
{
	/** JWT token. */
	ZoomSTRING jwt_token;
	/** Public app key used for SDK authentication. Alternative to JWT token. */
	ZoomSTRING publicAppKey;
}ZNAuthContext;

/**
 * @brief Enumeration of SDK login status.
 */
enum ZNLOGINSTATUS
{
	/** Unlogged in. */
	ZNLOGIN_IDLE = 0,
	/** In process of login. */
	ZNLOGIN_PROCESSING,
	/** Login successful. */
	ZNLOGIN_SUCCESS,
	/** Login failed. */
	ZNLOGIN_FAILED,
};

/**
 * @brief Enumeration of SDK login failed reason.
 */
enum ZNLoginFailReason
{
	/** No failure, login successful. */
	ZNLoginFail_None = 0,
	/** Email login is disabled. */
	ZNLoginFail_EmailLoginDisable,
	/** User does not exist. */
	ZNLoginFail_UserNotExist,
	/** Incorrect password. */
	ZNLoginFail_WrongPassword,
	/** Account is locked. */
	ZNLoginFail_AccountLocked,
	/** SDK needs to be updated. */
	ZNLoginFail_SDKNeedUpdate,
	/** Too many failed login attempts. */
	ZNLoginFail_TooManyFailedAttempts,
	/** Incorrect SMS verification code. */
	ZNLoginFail_SMSCodeError,
	/** SMS verification code has expired. */
	ZNLoginFail_SMSCodeExpired,
	/** Invalid phone number format. */
	ZNLoginFail_PhoneNumberFormatInValid,
	/** Invalid login token. */
	ZNLoginFail_LoginTokenInvalid,
	/** Other unspecified issue. */
	ZNLoginFail_OtherIssue = 100,
};

/**
 * @brief Enumeration of user login type.
 */
enum ZNLoginType
{
	/** Unknown type. */
	ZNLoginType_Unknown = 0,
	/** Login with SSO token. */
	ZNLoginType_SSO,
};

/**
 * @brief Account information interface.
 */
typedef struct _ZNAccountInfo {
	/** The screen name of user */
	ZoomSTRING dispaly_name;
	/** The login type */
	ZNLoginType login_type;
}ZNAccountInfo;

/**
 * @brief Meeting failure code.
 * Here are more detailed structural descriptions.
 */
enum ZNMeetingFailCode
{
	/** Start meeting successfully. */
	ZNMEETING_SUCCESS = 0,
	/** The connection with the backend service has errors. */
	ZNMEETING_FAIL_CONNECTION_ERR = 1,
	/** Reconnect error. */
	ZNMEETING_FAIL_RECONNECT_ERR = 2,
	/** Multi-media Router error. */
	ZNMEETING_FAIL_MMR_ERR = 3,
	/** Password is wrong. */
	ZNMEETING_FAIL_PASSWORD_ERR = 4,
	/** Session error. */
	ZNMEETING_FAIL_SESSION_ERR = 5,
	/** Meeting is over. */
	ZNMEETING_FAIL_MEETING_OVER = 6,
	/** Meeting has not begun. */
	ZNMEETING_FAIL_MEETING_NOT_START = 7,
	/** Meeting does not exist. */
	ZNMEETING_FAIL_MEETING_NOT_EXIST = 8,
	/** The capacity of meeting is full. For users that can't join meeting, they can go to watch live stream with the callback IMeetingServiceEvent::onMeetingFullToWatchLiveStream if the host has started. */
	ZNMEETING_FAIL_MEETING_USER_FULL = 9,
	/** The client is incompatible. */
	ZNMEETING_FAIL_CLIENT_INCOMPATIBLE = 10,
	/** The Multi-media router is not founded. */
	ZNMEETING_FAIL_NO_MMR = 11,
	/** The meeting is locked. */
	ZNMEETING_FAIL_CONFLOCKED = 12,
	/** The meeting is failed because of the restriction by the same account. */
	ZNMEETING_FAIL_MEETING_RESTRICTED = 13,
	/** The meeting is restricted by the same account while the attendee is allowed to join before the host. */
	ZNMEETING_FAIL_MEETING_RESTRICTED_JBH = 14,
	/** Unable to send web request. */
	ZNMEETING_FAIL_CANNOT_EMIT_WEBREQUEST = 15,
	/** The token is expired. */
	ZNMEETING_FAIL_CANNOT_START_TOKENEXPIRE = 16,
	/** Video hardware or software error. */
	ZNSESSION_VIDEO_ERR = 17,
	/** Audio autostart error. */
	ZNSESSION_AUDIO_AUTOSTARTERR = 18,
	/** The number of webinar registered has reached the upper limit. */
	ZNMEETING_FAIL_REGISTERWEBINAR_FULL = 19,
	/** Register webinar with the role of webinar host. */
	ZNMEETING_FAIL_REGISTERWEBINAR_HOSTREGISTER = 20,
	/** Register webinar with the role of panelist member. */
	ZNMEETING_FAIL_REGISTERWEBINAR_PANELISTREGISTER = 21,
	/** Register webinar with the denied email. */
	ZNMEETING_FAIL_REGISTERWEBINAR_DENIED_EMAIL = 22,
	/** Webinar request to login. */
	ZNMEETING_FAIL_ENFORCE_LOGIN = 23,
	/** Invalid for Windows SDK. */
	ZNCONF_FAIL_ZC_CERTIFICATE_CHANGED = 24,
	/** Vanity conference ID does not exist. */
	ZNCONF_FAIL_VANITY_NOT_EXIST = 27,
	/** Join webinar with the same email. */
	ZNCONF_FAIL_JOIN_WEBINAR_WITHSAMEEMAIL = 28,
	/** Meeting settings is not allowed to start a meeting. */
	ZNCONF_FAIL_DISALLOW_HOST_MEETING = 29,
	/** Disabled to write the configure file. */
	ZNMEETING_FAIL_WRITE_CONFIG_FILE = 50,
	/** Forbidden to join the internal meeting. */
	ZNMEETING_FAIL_FORBID_TO_JOIN_INTERNAL_MEETING = 60,
	/** Removed by the host. */
	ZNCONF_FAIL_REMOVED_BY_HOST = 61,
	/** Forbidden to join meeting */
	ZNMEETING_FAIL_HOST_DISALLOW_OUTSIDE_USER_JOIN = 62,
	/** To join a meeting hosted by an external Zoom account, your SDK app has to be published on Zoom Marketplace. You can refer to Section 6.1 of Zoom's API License Terms of Use. */
	ZNMEETING_FAIL_UNABLE_TO_JOIN_EXTERNAL_MEETING = 63,
	/** Join failed because this Meeting SDK key is blocked by the host's account admin. */
	ZNMEETING_FAIL_BLOCKED_BY_ACCOUNT_ADMIN = 64,
	/** Need sign in using the same account as the meeting organizer. */
	ZNMEETING_FAIL_NEED_SIGN_IN_FOR_PRIVATE_MEETING = 82,
	/** Join meeting param vanityID is duplicated and needs to be confirmed.For more information about Vanity URLs, see https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0061540#multipleVanity */
	ZNMEETING_FAIL_NEED_CONFIRM_PLINK = 88,
	/** Join meeting param vanityID does not exist in the current account.For more information about Vanity URLs, see https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0061540#multipleVanity */
	ZNMEETING_FAIL_NEED_INPUT_PLINK = 89,
	/** App join token error. */
	ZNMEETING_FAIL_APP_PRIVILEGE_TOKEN_ERROR = 500,
	/** Authorized user not in meeting. */
	ZNMEETING_FAIL_AUTHORIZED_USER_NOT_INMEETING = 501,
	/** On-behalf token error: conflict with login credentials. */
	ZNMEETING_FAIL_ON_BEHALF_TOKEN_CONFLICT_LOGIN_ERROR = 502,
	/** User level privilege token not have host zak/obf. */
	ZNMEETING_FAIL_USER_LEVEL_TOKEN_NOT_HAVE_HOST_ZAK_OBF = 503,
	/** App can not anonymous join meeting. */
	ZNMEETING_FAIL_APP_CAN_NOT_ANONYMOUS_JOIN_MEETING = 504,
	/** On-behalf token invalid. */
	ZNMEETING_FAIL_ON_BEHALF_TOKEN_INVALID = 505,
	/** On-behalf token meeting number not match. */
	ZNMEETING_FAIL_ON_BEHALF_TOKEN_NOT_MATCH_MEETING = 506,
	/** Jmak user email not match */
	ZNMEETING_FAIL_JMAK_USER_EMAIL_NOT_MATCH = 1143,
	ZNMEETING_FAIL_UNKNOWN = 0xffff,
};

/**
 * @brief Meeting end reason.
 * Here are more detailed structural descriptions.
 */
enum ZNMeetingEndReason
{
	/** For initialization */
	ZNEndMeetingReason_None = 0,
	/** Kicked by host */
	ZNEndMeetingReason_KickByHost = 1,
	/** Ended by host */
	ZNEndMeetingReason_EndByHost = 2,
	/** JBH times out */
	ZNEndMeetingReason_JBHTimeOut = 3,
	/** No attendee */
	ZNEndMeetingReason_NoAttendee = 4,
	/** Host starts another meeting */
	ZNEndMeetingReason_HostStartAnotherMeeting = 5,
	/** Free meeting times out */
	ZNEndMeetingReason_FreeMeetingTimeOut = 6,
	/** Represents an undefined end meeting reason, typically used for new error codes introduced by the backend after client release */
	ZNEndMeetingReason_Undefined = 7,
	/** Authorized user left */
	ZNEndMeetingReason_DueToAuthorizedUserLeave = 8,
};

/**
 * @brief Meeting status.
 * Here are more detailed structural descriptions.
 */
enum ZNMeetingStatus
{
	/** No meeting is running */
	ZNMEETING_STATUS_IDLE = 0,
	/** Connect to the meeting server status */
	ZNMEETING_STATUS_CONNECTING,
	/** Waiting for the host to start the meeting */
	ZNMEETING_STATUS_WAITINGFORHOST,
	/** Meeting is ready, in meeting status */
	ZNMEETING_STATUS_INMEETING,
	/** Disconnect the meeting server, leave meeting status */
	ZNMEETING_STATUS_DISCONNECTING,
	/** Reconnecting meeting server status */
	ZNMEETING_STATUS_RECONNECTING,
	/** Failed to connect the meeting server */
	ZNMEETING_STATUS_FAILED,
	/** Meeting ends */
	ZNMEETING_STATUS_ENDED,
	/** Unknown status */
	ZNMEETING_STATUS_UNKNOWN,
	/** Meeting is locked to prevent the further participants to join the meeting */
	ZNMEETING_STATUS_LOCKED,
	/** Meeting is open and participants can join the meeting */
	ZNMEETING_STATUS_UNLOCKED,
	/** Participants who join the meeting before the start are in the waiting room */
	ZNMEETING_STATUS_IN_WAITING_ROOM,
	/** Upgrade the attendees to panelist in webinar */
	ZNMEETING_STATUS_WEBINAR_PROMOTE,
	/** Downgrade the attendees from the panelist */
	ZNMEETING_STATUS_WEBINAR_DEPROMOTE,
	/** Join the breakout room */
	ZNMEETING_STATUS_JOIN_BREAKOUT_ROOM,
	/** Leave the breakout room */
	ZNMEETING_STATUS_LEAVE_BREAKOUT_ROOM,
    /** Audio is connected */
    ZNMEETING_STATUS_AUDIO_READY,
    /** There is another ongoing meeting on the server */
    ZNMEETING_STATUS_OTHER_MEETING_INPROGRESS,
};

/**
 * @brief SDK user type.
 * Here are more detailed structural descriptions.
 */
enum ZNSDKUserType
{
	/** Type of ordinary user who needs to login */
	ZNSDK_UT_NORMALUSER = 100,
	/** Start meeting without login */
	ZNSDK_UT_WITHOUT_LOGIN,
};

/**
 * @brief SDK user type.
 * Here are more detailed structural descriptions.
 */
enum ZNZoomUserType
{
	/** API user */
	ZNZoomUserType_APIUSER,
	/** User logged in with email */
	ZNZoomUserType_EMAIL_LOGIN,
	/** User logged in with Facebook */
	ZNZoomUserType_FACEBOOK,
	/** User logged in with Google */
	ZNZoomUserType_GoogleOAuth,
	/** User logged in with SSO */
	ZNZoomUserType_SSO,
	/** User of unknown type */
	ZNZoomUserType_Unknown,
};

/**
 * @brief The way and the parameter for meeting start.
 * Here are more detailed structural descriptions.
 */
typedef struct _ZNStartParam
{
	/** SDK user type. For more details, see \link ZNSDKUserType \endlink enum */
	ZNSDKUserType userType;
	/** Meeting number */
	unsigned long long meetingNumber;
	/** The window handle of the direct sharing application */
	ZoomSTRING hDirectShareAppWnd;
	/** The customer key that need the app intergrated with sdk to specify. The SDK will set this value when the associated settings are turned on */
	ZoomSTRING customer_key;
	/** Username when logged in */
	ZoomSTRING username;
	/** Meeting vanity ID */
	ZoomSTRING sdkVanityID;
	/** ZOOM access token */
	ZoomSTRING userZAK;
	/** Zoom user type. For more details, see \link ZNZoomUserType \endlink enum */
	ZNZoomUserType zoomUserType;
	/** Turn off the video or not. true indicates to turn off. In addition, this flag is affected by meeting attributes */
	bool isVideoOff;
	/** Turn off the audio or not. true indicates to turn off. In addition, this flag is affected by meeting attributes */
	bool isAudioOff;
	/** Share the desktop directly or not. true indicates to share */
	bool isDirectShareDesktop;
	_ZNStartParam() {
		userType = ZNSDK_UT_WITHOUT_LOGIN;
	}
}ZNStartParam;

/**
 * @brief The way and the parameter of the users when join the meeting.
 * Here are more detailed structural descriptions.
 */
typedef struct _ZNJoinParam
{
	/** SDK user type. For more details, see \link ZNSDKUserType \endlink enum */
	ZNSDKUserType userType;
	/** Meeting number */
	unsigned long long meetingNumber;
	/** App privilege token */
	ZoomSTRING app_privilege_token;
	/** The window handle of the direct sharing application */
	ZoomSTRING hDirectShareAppWnd;
	/** The customer key that need the app intergrated with sdk to specify. The SDK will set this value when the associated settings are turned on */
	ZoomSTRING customer_key;
	/** User ID */
	ZoomSTRING userId;
	/** Username when logged in */
	ZoomSTRING username;
	/** Meeting password */
	ZoomSTRING psw;
	/** Meeting vanity ID */
	ZoomSTRING vanityID;
	/** Webinar token */
	ZoomSTRING webinarToken;
	/** ZOOM access token */
	ZoomSTRING userZAK;
	/** Display ID */
	ZoomSTRING displayID;
	/** Join token */
	ZoomSTRING join_token;
	/** On behalf token */
	ZoomSTRING onBehalfToken;
	/** Turn off the video or not. true indicates to turn off. In addition, this flag is affected by meeting attributes */
	bool isVideoOff;
	/** Turn off the audio or not. true indicates to turn off. In addition, this flag is affected by meeting attributes */
	bool isAudioOff;
	/** Share the desktop directly or not. true indicates to share */
	bool isDirectShareDesktop;
	_ZNJoinParam() {
		userType = ZNSDK_UT_WITHOUT_LOGIN;
	}
}ZNJoinParam;

/**
 * @brief Leave meeting command.
 * Here are more detailed structural descriptions.
 */
enum ZNLeaveMeetingCmd
{
	/** Leave meeting */
	ZNLEAVE_MEETING,
	/** End meeting */
	ZNEND_MEETING,
};

/**
 * @brief Meeting type.
 * Here are more detailed structural descriptions.
 */
enum ZNMeetingType
{
	/** For initialization */
	ZNMEETING_TYPE_NONE,
	/** Ordinary meeting */
	ZNMEETING_TYPE_NORMAL,
	/** Webinar */
	ZNMEETING_TYPE_WEBINAR,
	/** Breakout meeting */
	ZNMEETING_TYPE_BREAKOUTROOM,
};

/**
 * @brief Connection quality.
 * Here are more detailed structural descriptions.
 */
enum ZNConnectionQuality
{
	/** Unknown connection status */
	ZNConn_Quality_Unknown,
	/** The connection quality is very poor */
	ZNConn_Quality_Very_Bad,
	/** The connection quality is poor */
	ZNConn_Quality_Bad,
	/** The connection quality is not good */
	ZNConn_Quality_Not_Good,
	/** The connection quality is normal */
	ZNConn_Quality_Normal,
	/** The connection quality is good */
	ZNConn_Quality_Good,
	/** The connection quality is excellent */
	ZNConn_Quality_Excellent,
};

/**
 * @brief Meeting component enumeration.
 * Here are more detailed structural descriptions.
 */
enum ZNMeetingComponentType
{
	/** Default component type. */
	ZNMeetingComponentType_Def = 0,
	/** Audio. */
	ZNMeetingComponentType_AUDIO,
	/** Video. */
	ZNMeetingComponentType_VIDEO,
	/** Share application. */
	ZNMeetingComponentType_SHARE,
};

/**
 * @brief The meeting audio statistic information.
 */
typedef struct tagZNMeetingAudioStatisticInfo
{
	/** This meeting's sent audio frequency in kilohertz (KHz). */
	int sendFrequency;
	/** This meeting's sent band width of audio. */
	int sendBandwidth;
	/** This meeting's sent audio rtt. */
	int sendRTT;
	/** This meeting's sent audio jitter. */
	int sendJitter;
	/** This meeting's average of send audio packet loss. */
	float sendPacketLossAvg;
	/** This meeting's maximum send audio packet loss. */
	float sendPacketLossMax;

	/** This meeting's received audio frequency in kilohertz (KHz). */
	int recvFrequency;
	/** This meeting's received band width of audio. */
	int recvBandwidth;
	/** This meeting's received audio rtt. */
	int recvRTT;
	/** This meeting's received audio jitter. */
	int recvJitter;
	/** This meeting's average of received audio packet loss. */
	float recvPacketLossAvg;
	/** This meeting's maximum received audio packet loss. */
	float recvPacketLossMax;

	tagZNMeetingAudioStatisticInfo()
	{
		sendFrequency = 0;
		sendBandwidth = 0;
		sendRTT = 0;
		sendJitter = 0;
		sendPacketLossAvg = 0;
		sendPacketLossMax = 0;
		recvFrequency = 0;
		recvBandwidth = 0;
		recvRTT = 0;
		recvJitter = 0;
		recvPacketLossAvg = 0;
		recvPacketLossMax = 0;
	}
}ZNMeetingAudioStatisticInfo;

/**
 * @brief The meeting video or share statistic information.
 */
typedef struct tagZNMeetingASVStatisticInfo
{
	/** This meeting's sent band-width for video or sharing. */
	int sendBandwidth;
	/** This meeting's sent frame rate for video or sharing. */
	int sendFps;
	/** This meeting's sent video or sharing rtt data. */
	int sendRTT;
	/** This meeting's sent video or sharing jitter data. */
	int sendJitter;
	/** This meeting's sent video or sharing resolution. HIWORD->height, LOWORD->width. */
	int sendResolution;
	/** This meeting's average video or sharing packet loss for sent data. */
	float sendPacketLossAvg;
	/** This meeting's maximum video or sharing packet loss for sent data. */
	float sendPacketLossMax;

	/** This meeting's received band-width for video or sharing. */
	int recvBandwidth;
	/** This meeting's received frame rate for video or sharing. */
	int recvFps;
	/** This meeting's received video or sharing rtt data. */
	int recvRTT;
	/** This meeting's received video or sharing jitter data. */
	int recvJitter;
	/** This meeting's received video or sharing resolution. HIWORD->height, LOWORD->width. */
	int recvResolution;
	/** This meeting's average video or sharing packet loss for received data. */
	float recvPacketLossAvg;
	/** This meeting's maximum video or sharing packet loss for received data. */
	float recvPacketLossMax;

	tagZNMeetingASVStatisticInfo()
	{
		sendFps = 0;
		sendBandwidth = 0;
		sendRTT = 0;
		sendJitter = 0;
		sendResolution = 0;
		sendPacketLossAvg = 0;
		sendPacketLossMax = 0;
		recvFps = 0;
		recvBandwidth = 0;
		recvRTT = 0;
		recvJitter = 0;
		recvResolution = 0;
		recvPacketLossAvg = 0;
		recvPacketLossMax = 0;
	}
}ZNMeetingASVStatisticInfo;

/**
 * @brief Show chat dialog parameters.
 * Here are more detailed structural descriptions.
 */
typedef struct _ZNShowChatDlgParam
{
	/** Parent window handle */
	ZoomSTRING hParent;
	/** Top rectangle coordinate */
	ZoomSTRING rect_top;
	/** Bottom rectangle coordinate */
	ZoomSTRING rect_bottom;
	/** Left rectangle coordinate */
	ZoomSTRING rect_left;
	/** Right rectangle coordinate */
	ZoomSTRING rect_right;
	/** Chat dialog handle */
	ZoomSTRING hChatWnd;
}ZNShowChatDlgParam;

/**
 * @brief The user interface type of float video.
 * Here are more detailed structural descriptions.
 */
enum ZNSDKFloatVideoType
{
	/** Type of list */
	ZN_FLOATVIDEO_List,
	/** Small */
	ZN_FLOATVIDEO_Small,
	/** Large */
	ZN_FLOATVIDEO_Large,
	/** Minimized */
	ZN_FLOATVIDEO_Minimize,
};

/**
 * @brief Video wall page information.
 * Here are more detailed structural descriptions.
 */
typedef struct _ZNVideoWallPageInfoParam
{
	/** The page in video wall mode for the moment */
	ZoomSTRING currentPage;
	/** The total number of pages in video wall mode */
	ZoomSTRING totalPages;
}ZNVideoWallPageInfoParam;

/**
 * @brief Split screen mode information.
 * Here are more detailed structural descriptions.
 */
typedef struct _ZNSplitScreenInfo
{
	/** The page in video wall mode for the moment */
	bool bZNSupportSplitScreen;
	/** The total number of pages in video wall mode */
	bool bZNInSplitScreenMode;
	_ZNSplitScreenInfo()
	{
		bZNSupportSplitScreen = false;
		bZNInSplitScreenMode = false;
	}
}ZNSplitScreenInfo;

/**
 * @brief SDK View Type, primary displayer and secondary displayer.
 * Here are more detailed structural descriptions.
 */
enum ZNSDKViewType
{
	/** Primary displayer */
	ZNSDK_FIRST_VIEW,
	/** Secondary displayer */
	ZNSDK_SECOND_VIEW,
	ZNSDK_SEND_SHARE_VIEW,
};

/**
 * @brief Types of annotation tool.
 * Here are more detailed structural descriptions.
 */
enum ZNAnnotationToolType
{
	/** Switch to mouse cursor */
	ZN_ANNOTOOL_NONE_DRAWING,
	/** Pen */
	ZN_ANNOTOOL_PEN,
	/** Highlighter */
	ZN_ANNOTOOL_HIGHLIGHTER,
	/** A straight line changes automatically in pace with the mouse cursor */
	ZN_ANNOTOOL_AUTO_LINE,
	/** A rectangle changes automatically in pace with the mouse cursor */
	ZN_ANNOTOOL_AUTO_RECTANGLE,
	/** An ellipse changes automatically in pace with the mouse cursor */
	ZN_ANNOTOOL_AUTO_ELLIPSE,
	/** An arrow changes automatically in pace with the mouse cursor */
	ZN_ANNOTOOL_AUTO_ARROW,
	/** A filled rectangle */
	ZN_ANNOTOOL_AUTO_RECTANGLE_FILL,
	/** A filled ellipse */
	ZN_ANNOTOOL_AUTO_ELLIPSE_FILL,
	/** Laser pointer */
	ZN_ANNOTOOL_SPOTLIGHT,
	/** An arrow showing the name of whom click on the sharing content */
	ZN_ANNOTOOL_ARROW,
	/** An eraser */
	ZN_ANNOTOOL_ERASER,
	/** Insert a textbox in order to input letters */
	ZN_ANNOTOOL_TEXTBOX,
	/** Select the annotations */
	ZN_ANNOTOOL_PICKER,
	/** A fair rectangle changes automatically in pace with the mouse cursor */
	ZN_ANNOTOOL_AUTO_RECTANGLE_SEMI_FILL,
	/** A fair ellipse changes automatically in pace with the mouse cursor */
	ZN_ANNOTOOL_AUTO_ELLIPSE_SEMI_FILL,
	/** A line with double-arrow */
	ZN_ANNOTOOL_AUTO_DOUBLE_ARROW,
	/** An unfilled rhombus */
	ZN_ANNOTOOL_AUTO_DIAMOND,
	/** A fixed-size arrow for marking */
	ZN_ANNOTOOL_AUTO_STAMP_ARROW,
	/** A sign marking that something is correct */
	ZN_ANNOTOOL_AUTO_STAMP_CHECK,
	/** A sign marking that something is wrong */
	ZN_ANNOTOOL_AUTO_STAMP_X,
	/** A star for marking */
	ZN_ANNOTOOL_AUTO_STAMP_STAR,
	/** A heart for marking */
	ZN_ANNOTOOL_AUTO_STAMP_HEART,
	/** A sign for interrogation */
	ZN_ANNOTOOL_AUTO_STAMP_QM,
};

/**
 * @brief Clear types of annotation tools.
 * Here are more detailed structural descriptions.
 */
enum ZNAnnotationClearType
{
	/** Clear all annotations */
	ZN_ANNOCLEAR_ALL,
	/** Clear only your own annotations */
	ZN_ANNOCLEAR_SELF,
	/** Clear only the others' annotations */
	ZN_ANNOCLEAR_OTHER,
};

/**
 * @brief Define the audio status of the user.
 * Here are more detailed structural descriptions.
 */
enum ZNAudioStatus
{
	/** Initialization. */
	ZN_Audio_None,
	/** Muted status. */
	ZN_Audio_Muted,
	/** Unmuted status. */
	ZN_Audio_UnMuted,
	/** Muted by the host. */
	ZN_Audio_Muted_ByHost,
	/** Unmuted by the host. */
	ZN_Audio_UnMuted_ByHost,
	/** The host mutes all. */
	ZN_Audio_MutedAll_ByHost,
	/** The host unmutes all. */
	ZN_Audio_UnMutedAll_ByHost,
};

/**
 * @brief User audio status struct.
 */
typedef struct _ZNUserAudioStatus
{
	/** The user ID. */
	unsigned int userId;
	/** The audio status of the user. */
	ZNAudioStatus audioStauts;
}ZNUserAudioStatus;

/**
 * @brief The video status of the user.
 * Here are more detailed structural descriptions.
 */
enum ZNVideoStatus
{
	/** Video is on. */
	ZN_Video_ON,
	/** Video is off. */
	ZN_Video_OFF,
	/** Video is muted by host. */
	ZN_Video_Mute_ByHost,
	/** The user is still sending, but a previously received video stream is no longer available. Camera-on without a subscribed stream is On. */
	ZN_Video_NotReceiving,
};

/**
 * @brief Enumeration of possible results for pinning a user.
 */
enum ZNPinResult
{
	/** Pinning succeeded. */
	ZN_PinResult_Success = 0,
	/** User counts less than 2. */
	ZN_PinResult_Fail_NotEnoughUsers,
	/** Exceeded the maximum of 9 pinned users. */
	ZN_PinResult_Fail_ToMuchPinnedUsers,
	/** User cannot be pinned (e.g., view-only mode, silent mode, or active speaker). */
	ZN_PinResult_Fail_UserCannotBePinned,
	/** Other reasons. */
	ZN_PinResult_Fail_VideoModeDoNotSupport,
	/** Current user has no privilege to pin. */
	ZN_PinResult_Fail_NoPrivilegeToPin,
	/** Webinar and in view only meeting. */
	ZN_PinResult_Fail_MeetingDoNotSupport,
	/** Too many users in the meeting to allow pinning. */
	ZN_PinResult_Fail_TooManyUsers,
	/** Unknown error. */
	ZN_PinResult_Unknown = 100,
};

/**
 * @brief Enumeration of possible results for spotlighting a user.
 */
enum ZNSpotlightResult
{
	/** Spotlighting succeeded. */
	ZN_SpotResult_Success = 0,
	/** User counts less than 2. */
	ZN_SpotResult_Fail_NotEnoughUsers,
	/** Spotlighted user counts is more than 9. */
	ZN_SpotResult_Fail_ToMuchSpotlightedUsers,
	/** User in view only mode or silent mode or active. */
	ZN_SpotResult_Fail_UserCannotBeSpotlighted,
	/** User doesn't turn on video. */
	ZN_SpotResult_Fail_UserWithoutVideo,
	/** Current user has no privilege to spotlight. */
	ZN_SpotResult_Fail_NoPrivilegeToSpotlight,
	/** User is not spotlighted. */
	ZN_SpotResult_Fail_UserNotSpotlighted,
	ZN_SpotResult_Unknown = 100,
};

/**
 * @brief Recording status.
 * Here are more detailed structural descriptions.
 */
enum ZNRecordingStatus
{
	/** Start recording on local computer or on cloud. */
	ZNRecording_Start,
	/** Stop recording on local computer or on cloud. */
	ZNRecording_Stop,
	/** There is no more space to store both local and cloud recording. */
	ZNRecording_DiskFull,
	/** Pause recording on local or on cloud. */
	ZNRecording_Pause,
	/** Connecting, only for cloud recording. */
	ZNRecording_Connecting,
	/** Saving the recording failed. */
	ZNRecording_Fail,
};

/**
 * @brief Request host to start cloud recording status.
 */
enum ZNRequestStartCloudRecordingStatus
{
	/** Host grants the request. */
	ZNRequestStartCloudRecording_Granted,
	/** Host denies the request. */
	ZNRequestStartCloudRecording_Denied,
	/** The request for cloud recording timed out. */
	ZNRequestStartCloudRecording_TimedOut,
};

/**
 * @brief Share status enumeration.
 */
enum ZNShareStatus
{
	/** For initialization */
	ZN_Sharing_None,
	/** Begin to share by the user himself */
	ZN_Sharing_Self_Send_Begin,
	/** Stop sharing by the user */
	ZN_Sharing_Self_Send_End,
	/** Others begin to share */
	ZN_Sharing_Other_Share_Begin,
	/** Others stop sharing */
	ZN_Sharing_Other_Share_End,
	/** View the sharing of others */
	ZN_Sharing_View_Other_Sharing,
	/** Pause sharing */
	ZN_Sharing_Pause,
	/** Resume sharing */
	ZN_Sharing_Resume,
	/** Sharing content changes. This status is marked as deprecated */
	ZN_Sharing_ContentTypeChange,
	/** The current user begins to share the sounds of computer audio */
	ZN_Sharing_SelfStartAudioShare,
	/** The current user stops to share the sounds of computer audio */
	ZN_Sharing_SelfStopAudioShare,
	/** Other user begins to share the sounds of computer audio */
	ZN_Sharing_OtherStartAudioShare,
	/** Other user stops to share the sounds of computer audio */
	ZN_Sharing_OtherStopAudioShare,
	/** The share is disconnected */
	ZN_Sharing_Disconnected,
};

/**
 * @brief Enumeration of types of shared content. 
 */
enum ZNShareType
{
	/** Type unknown. */
	ZNSHARE_TYPE_UNKNOWN,
	/** Type of sharing the application. */
	ZNSHARE_TYPE_AS,
	/** Type of sharing the desktop. */
	ZNSHARE_TYPE_DS,
	/** Type of sharing the white-board. */
	ZNSHARE_TYPE_WB,
	/** Type of sharing data from the device connected WIFI. */
	ZNSHARE_TYPE_AIRHOST,
	/** Type of sharing the camera. */
	ZNSHARE_TYPE_CAMERA,
	/** Type of sharing the data. */
	ZNSHARE_TYPE_DATA,
	/** Type of sharing the video file. */
	ZNSHARE_TYPE_VIDEO_FILE,
	/** Type of sharing the frame. */
	ZNSHARE_TYPE_FRAME,
	/** Type of sharing the document. */
	ZNSHARE_TYPE_DOCUMENT,
	/** Type of sharing the computer audio. */
	ZNSHARE_TYPE_COMPUTER_AUDIO
};

/**
 * @brief Status of live stream.
 * Here are more detailed structural descriptions.
 */
enum ZNLiveStreamStatus
{
	/** Only for initialization. */
	ZN_LiveStreamStatus_None,
	/** In progress. */
	ZN_LiveStreamStatus_InProgress,
	/** Be connecting. */
	ZN_LiveStreamStatus_Connecting,
	/** Connect timeout. */
	ZN_LiveStreamStatus_Start_Failed_Timeout,
	/** Failed to start live streaming. */
	ZN_LiveStreamStatus_Start_Failed,
	/** Live stream ends. */
	ZN_LiveStreamStatus_Ended,
};

/**
 * @brief Live stream item information structure.
 */
typedef struct _ZNLiveStreamItemInfo
{
	/** The URL of the live stream meeting */
	ZoomSTRING liveStreamURL;
	/** The descriptions of live stream */
	ZoomSTRING liveStreamURLDescription;
	/** The viewer URL of the live stream meeting */
	ZoomSTRING liveStreamViewerURL;
}ZNLiveStreamItemInfo;

/**
 * @brief Raw live stream information structure.
 */
struct ZNRawLiveStreamInfo
{
	/** User ID */
	unsigned int userId;
	/** Broadcast URL */
	ZoomSTRING broadcastUrl;
	ZNRawLiveStreamInfo()
	{
		userId = 0xffff;
	}
};

/**
 * @brief Camera device information structure.
 */
typedef struct _ZNCameraInfo
{
	/** The camera device ID. */
	ZoomSTRING deviceId;
	/** The camera device name. */
	ZoomSTRING deviceName;
	/** Is the current device is selected to use or not. */
	bool isSelectedDevice;
}ZNCameraInfo;

/**
 * @brief Microphone information structure.
 */
typedef struct _ZNMicInfo
{
	/** The microphone device ID. */
	ZoomSTRING deviceId;
	/** The microphone device name. */
	ZoomSTRING deviceName;
	/** Is the current device is selected to use or not. */
	bool isSelectedDevice;
}ZNMicInfo;

/**
 * @brief Audio speaker device information structure.
 */
typedef struct _ZNSpeakerInfo
{
	/** The speaker device ID. */
	ZoomSTRING deviceId;
	/** The speaker device name. */
	ZoomSTRING deviceName;
	/** Is the current device is selected to use or not. */
	bool isSelectedDevice;
}ZNSpeakerInfo;

/**
 * @brief Enumeration of the shown tab page at the top of the displayed setting dialog.
 */
enum ZNSettingTabPage
{
	/** General setting page is on top. */
	ZN_SettingTabPage_General,
	/** Audio setting page is on top. */
	ZN_SettingTabPage_Audio,
	/** Video setting page is on top. */
	ZN_SettingTabPage_Video,
};

/**
 * @brief The parameter to show the meeting setting dialog in Zoom UI.
 */
typedef struct _ZNShowSettingDlgParam
{
	/** Parent window handle */
	ZoomSTRING hParent;
	/** The Y-axis value of the top-left corner of the dialog uses the coordinate system of the monitor */
	ZoomSTRING top;
	/** The X-axis value of the top-left corner of the dialog uses the coordinate system of the monitor */
	ZoomSTRING left;
	/** Window handle of the dialog setting */
	ZoomSTRING hSettingWnd;
	/** Enable to display or not */
	bool bShow;
	/** The tab page shown at the top of the displayed setting dialog */
	ZNSettingTabPage eTabPageType;
	_ZNShowSettingDlgParam()
	{
		bShow = true;
		eTabPageType = ZN_SettingTabPage_General;
	}
}ZNShowSettingDlgParam;

/**
 * @brief Custom string type.
 * Here are more detailed structural descriptions.
 * @note Read the description of the each type carefully. You must follow the format to custom your own string. Wrong usage may cause unpredictable crash.
*/
enum ZNSDKCustomizedStringType
{
	/** The new string must end up with "%s" so that the menu item can show correctly. This type is used to define a string to replace the menu item ON %S on live streaming. */
	ZN_SDK_Customized_LiveStream_MenuString_LiveOn_String = 0,
	/** The new string must end up with "%s" so that the menu item can show correctly. This type is used to define a string to replace the menu item VIEW STREAM ON %S on live streaming. */
	ZN_SDK_Customized_LiveStream_MenuString_LiveView_String,
	/** The new string must be a pure string so that it can show correctly. This type is used to define a string to replace the menu item STOP LIVE STREAM on live streaming. */
	ZN_SDK_Customized_LiveStream_MenuString_LiveStop_String,
	/** The new string must be a pure string so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI. */
	ZN_SDK_Customized_Title_App,
	/** The new string must be the same format as "Zoom Participant ID: %s   Meeting ID: %s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI. */
	ZN_SDK_Customized_Title_ZoomVideo,
	/** The new string must be the same format as "Zoom Participant ID: %s  %d-Minutes Meeting ID:%s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI when the user is free user and in view-only status.  */
	ZN_SDK_Customized_Title_FreeZoomVideo,
	/** The new string must be the same format as "Zoom %d-Minutes Meeting ID: %s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI when the user is free user and in view-only status.  */
	ZN_SDK_Customized_Title_ViewOnly_FreeZoomVideo,
};

/**
 * @brief Custom URL type.
 * Here are more detailed structural descriptions.
 * @note The URL must remain intact and should contain 'http' or https'.
 */
enum ZNSDKCustomizedURLType
{
	/** Set the custom help URL in the virtual background tab page. */
	ZN_SDKCustomizedURL_VITRULBG_HELP,
	/** Set the custom Learn More URL in the virtual background tab page. */
	ZN_SDKCustomizedURL_VITRULBG_LEARN_MORE,
	/** Set the Support URL in the meeting. */
	ZN_SDKCustomizedURL_SUPPORTURL,
};

/**
 * @brief H.323 Callout status.
 * Here are more detailed structural descriptions.
 */
enum ZNH323CalloutStatus
{
	/** Used only for initialization. */
	ZN_H323Callout_Unknown,
	/** Call out successfully. */
	ZN_H323Callout_Success,
	/** Bell during the call. */
	ZN_H323Callout_Ring,
	/** Call timeout. */
	ZN_H323Callout_Timeout,
	/** Call fails. */
	ZN_H323Callout_Failed,
	/** Busy. */
	ZN_H323Callout_Busy,
	/** Decline. */
	ZN_H323Callout_Decline,
};

/**
 * @brief H.323 device type.
 * Here are more detailed structural descriptions.
 */
enum ZNH323DeviceType
{
	/** Unknown device, only for initialization. */
	ZN_H323DeviceType_Unknown,
	/** H.323 device. */
	ZN_H323DeviceType_H323,
	/** SIP device. */
	ZN_H323DeviceType_SIP,
	/** H.323 device and SIP device. */
	ZN_H323DeviceType_BOTH,
};

/**
 * @brief Meeting H.323 device structure.
 */
typedef struct _ZNH323DeviecInfo
{
	/** The H.323 device ID. */
	ZoomSTRING h323_deviceName;
	/** The H.323 device IP. */
	ZoomSTRING h323_deviceIP;
	/** The H.323 device E164 name. */
	ZoomSTRING h323_deviceE164Name;
	/** The H.323 device type. For more information, see ZNH323DeviceType enum. */
	ZNH323DeviceType h323_DeviceType;
}ZNH323DeviecInfo;

/**
 * @brief The position of the window. The coordinate of position is that of monitor when the parent window is null. If the the parent window is not null, the position coordinate is that of the parent window.
 */
typedef struct _ZNWndPosition
{
	/** Specifies the X-axis coordinate of the top-left corner of the window. */
	ZoomSTRING z_left;
	/** Specifies the Y-axis coordinate of the top-left of the window. */
	ZoomSTRING z_top;
#if (defined BUILD_WIN)
	/** Specifies the window handle of the window itself. */
	ZoomSTRING z_hSelfWnd;
	/** Specifies the window handle of the parent window. If the value is NULL, the position coordinate is the monitor coordinate */
	ZoomSTRING z_hParent;
#else
	ZoomSTRING z_height;
	ZoomSTRING z_width;
#endif
}ZNWndPosition;

/**
 * @brief Upgrade types of free meeting.
 * Here are more detailed structural descriptions. 
 */
enum ZNFreeMeetingNeedUpgradeType
{
	/** Initialization. */
	ZN_FreeMeetingNeedUpgradeType_NONE,
	/** It is necessary for administrator to upgrade the free meeting. */
	ZN_FreeMeetingNeedUpgradeType_BY_ADMIN,
	/** Upgrade the free meeting by the gift link. */
	ZN_FreeMeetingNeedUpgradeType_BY_GIFTURL,
};

/**
 * @brief Premeeting API result enumeration.
 */
enum ZNPremeetingAPIResult
{
	/** API returns unknown error */
	ZN_PREMETAPIRET_UNKNOW,
	/** Calls API successfully */
	ZN_PREMETAPIRET_SUCCESS,
	ZN_PREMETAPIRET_FAILED,
	ZN_PREMETAPIRET_TIMEOUT,
};

/**
 * @brief Direct sharing status.
 * Here are more detailed structural descriptions.
 */
enum ZNDirectShareStatus
{
	/** Only for initialization. */
	ZN_DirectShare_Unknown = 0,
	/** Waiting for enabling the direct sharing. */
	ZN_DirectShare_Connecting,
	/** In direct sharing mode. */
	ZN_DirectShare_In_Direct_Share_Mode,
	/** End the direct sharing. */
	ZN_DirectShare_Ended,
	/** Re-enter the meeting ID/paring code. */
	ZN_DirectShare_Need_MeetingID_Or_PairingCode,
	/** Network error. Please try again later. */
	ZN_DirectShare_NetWork_Error,
	/** Other errors. Mainly occur in SIP call mode. */
	ZN_DirectShare_Other_Error,
	/** Wrong meeting id or sharing key. */
	ZN_DirectShare_WrongMeetingID_Or_SharingKey,
	/** Please input new paring code. */
	ZN_DirectShare_InputNewParingCode,
	/** Prepare to share data. */
	ZN_DirectShare_Prepared,
};

/**
 * @brief Define the audio type of the user.
 * Here are more detailed structural descriptions.
 */
enum ZNAudioType
{
	/** Normal audio type. */
	ZN_AUDIOTYPE_NONE,
	/** In VoIP mode. */
	ZN_AUDIOTYPE_VOIP,
	/** In telephone mode. */
	ZN_AUDIOTYPE_PHONE,
	/** Unknown mode. */
	ZN_AUDIOTYPE_UNKNOWN,
};

/**
 * @brief Role of user.
 * Here are more detailed structural descriptions.
 */
enum ZNUserRole
{
	/** For initialization. */
	ZN_USERROLE_NONE,
	/** Role of the host. */
	ZN_USERROLE_HOST,
	/** Role of co-host. */
	ZN_USERROLE_COHOST,
	/** Role of the panelist, valid only in webinar. */
	ZN_USERROLE_PANELIST,
	/** Host role in breakout room. */
	ZN_USERROLE_BREAKOUTROOM_MODERATOR,
	/** Role of attendee. */
	ZN_USERROLE_ATTENDEE,
};

enum ZNSDKUserInfoType
{
	ZN_REAL_USERINFO,
	ZN_FAKE_USERINFO,
};

/**
 * @brief Status of webinar attendee.
 * Here are more detailed structural descriptions.
 */
typedef struct tagWebinarAttendeeStatus
{
	/** true indicates that it is able to talk. */
	bool allow_talk;
}ZNWebinarAttendeeStatus;

/**
 * @brief Specify the emoji feedback type.
 * Here are more detailed enum descriptions.
 */
typedef enum tagSDKEmojiFeedbackType
{
	ZNSDKEmojiFeedbackType_None,
	ZNSDKEmojiFeedbackType_Yes,
	ZNSDKEmojiFeedbackType_No,
	ZNSDKEmojiFeedbackType_SpeedUp,
	ZNSDKEmojiFeedbackType_SlowDown,
	ZNSDKEmojiFeedbackType_Away
}ZNSDKEmojiFeedbackType;

/**
 * @brief User information structure.
 */
typedef struct _ZNUserInfomation
{
	/** The username matched with the current user information. */
	ZoomSTRING userName;
	/** Whether the member corresponding with the current information is the host or not */
	bool isHost;
	/** The user ID matched with the current user information. */
	unsigned int userID;
	/** The avatar file path matched with the current user information. */
	ZoomSTRING avatarPath;
	/** The user persistent id matched with the current user information. */
	ZoomSTRING persistentId;
	/** The customer_key matched with the current user information. */
	ZoomSTRING customerKey;
	/** The video status of the user specified by the current information */
	bool isVideoOn;
	/** The audio status of the user specified by the current information */
	bool isAudioMuted;
	/** Whether the current information corresponds to the user himself or not */
	bool isMySelf;
	/** The type of role of the user specified by the current information. For more information, see \link ZNUserRole \endlink enum */
	ZNUserRole userRole;
	/** Whether the user corresponding to the current information joins the meeting by telephone or not */
	bool isPurePhoneUser;
	/** Whether the user is talking */
	bool isTalking;
	/** Whether the member corresponding with the current information is the h323 user or not */
	bool isH323User;
	/** The webinar status of the user specified by the current information. true indicates that it is able to talk */
	ZNWebinarAttendeeStatus webinarAttendeeStatus;
	/** Local recording status */
	ZNRecordingStatus localRecordingStatus;
	/** User info type */
	ZNSDKUserInfoType userInfoType;
	/** Whether the user is raw live streaming */
	bool isRawLiveStreaming;
	/** Whether the user has raw live stream privilege */
	bool HasRawLiveStreamPrivilege;
	/** Whether the user has camera */
	bool hasCamera;
	/** The audio type of the user specified by the current information when joins the meeting. For more information, see \link ZNAudioType \endlink enum */
	ZNAudioType audioJoinType;
	/** Whether the user specified by the current information raises hand or not */
	bool isRaiseHand;
	/** Whether the user is interpreter */
	bool isInterpreter;
	/** Whether the user is sign language interpreter */
	bool isSignLanguageInterpreter;
	/** Interpreter active language */
	ZoomSTRING interpreterActiveLanguage;
	/** Emoji feedback type */
	ZNSDKEmojiFeedbackType emojiFeedbackType;
	/** Whether the user specified by the current information is bot user or not */
	bool isBotUser;
	/** The bot app name */
	ZoomSTRING botAppName;
	/** Whether the user is in webinar backstage */
	bool isInWebinarBackstage;
	/** Whether the user specified by the current information is in the waiting room or not */
	bool isInWaitingRoom;
	/** Whether the user corresponding to the current information is the sender of Closed Caption or not */
	bool isClosedCaptionSender;
	/** Whether the participant enabled virtual name tag. */
	bool isVirtualNameTagEnabled;
	/** Whether the specified user is an audio only user. */
	bool isAudioOnlyUser;
#if (!defined TARGET_OS_MAC)
	/** The Mic level of the user corresponding to the current information */
	int audioVoiceLevel;
#endif
	_ZNUserInfomation()
	{
		userInfoType = ZN_FAKE_USERINFO;
		isHost = false;
		isVideoOn = false;
		isAudioMuted = false;
		isMySelf = false;
		userRole = ZN_USERROLE_NONE;
		isPurePhoneUser = false;
		isTalking = false;
		isH323User = false;
		isRawLiveStreaming = false;
		HasRawLiveStreamPrivilege = false;
		hasCamera = false;
		audioJoinType = ZN_AUDIOTYPE_NONE;
		isRaiseHand = false;
		isInterpreter = false;
		isSignLanguageInterpreter = false;
		emojiFeedbackType = ZNSDKEmojiFeedbackType_None;
		isBotUser = false;
		isInWebinarBackstage = false;
		isInWaitingRoom = false;
		isClosedCaptionSender = false;
		isVirtualNameTagEnabled = false;
		isAudioOnlyUser = false;
	}
}ZNUserInfomation;

/**
 * @brief The type of minimize user interface mode.
 * Here are more detailed structural descriptions.
 */
enum ZNSDKMinimizeUIMode
{
	/** For initialization. */
	ZN_MinimizeUIMode_NONE,
	/** Minimized mode for sharing. */
	ZN_MinimizeUIMode_SHARE,
	/** Minimized mode for video. */
	ZN_MinimizeUIMode_VIDEO,
	/** Minimized mode for speaking. */
	ZN_MinimizeUIMode_ACTIVESPEAKER,
};

/**
 * @brief Define the strategy to show the tab pages in the setting dialog.
 */
typedef struct _ZNSettingDlgShowTabPageOption
{
	/** true indicates to show general page. */
	bool z_bShowGeneral;
	/** true indicates to show video page. */
	bool z_bShowVideo;
	/** true indicates to show audio page. */
	bool z_bShowAudio;
	/** true indicates to show virtual background page. */
	bool z_bShowVirtualBackGround;
	/** true indicates to show recording page. */
	bool z_bSHowRecording;
	/** true indicates to show advance feature page. */
	bool z_bShowAdvancedFeature;
	/** true indicates to show statistics page. */
	bool z_bShowStatistics;
	/** true indicates to show feedback page. */
	bool z_bShowFeedback;
	/** true indicates to show accessibility page. */
	bool z_bShowAccessibility;
	_ZNSettingDlgShowTabPageOption()
	{
		z_bShowGeneral = true;
		z_bShowVideo = true;
		z_bShowAudio = true;
		z_bShowVirtualBackGround = true;
		z_bSHowRecording = true;
		z_bShowStatistics = true;
		z_bShowAccessibility = true;
		z_bShowAdvancedFeature = false;
		z_bShowFeedback = false;
	}

}ZNSettingDlgShowTabPageOption;

/**
 * @brief SMS verification error types.
 * Here are more detailed structural descriptions.
 */
enum ZNSMSVerificationCodeErr
{
	/** For initialization. */
	ZNSMSVerificationCodeErr_Unknown,
	/** Success. */
	ZNSMSVerificationCodeErr_Success,
	/** Send SMS Failed. */
	ZNSMSVerificationCodeErr_Retrieve_SendSMSFailed,
	/** Invalid phone number. */
	ZNSMSVerificationCodeErr_Retrieve_InvalidPhoneNum,
	/** The phone number is already bound. */
	ZNSMSVerificationCodeErr_Retrieve_PhoneNumAlreadyBound,
	/** Send phone number too frequently. */
	ZNSMSVerificationCodeErr_Retrieve_PhoneNumSendTooFrequent,
	/** Verification code is incorrect. */
	ZNSMSVerificationCodeErr_Verify_CodeIncorrect,
	/** Verification code is expired. */
	ZNSMSVerificationCodeErr_Verify_CodeExpired,
	/** Unknown error for verification. */
	ZNSMSVerificationCodeErr_Verify_UnknownError,
};

/**
 * @brief struct of country information that supports real name auth.
 */
typedef struct _ZNZoomRealNameAuthCountryInfo
{
	ZoomSTRING countryID;
	ZoomSTRING countryName;
	ZoomSTRING countryCode;
}ZNZoomRealNameAuthCountryInfo;

enum ZNSDKInviteDlgTabPage
{
	/** 'Invite by Email' tab page. */
	SDK_INVITEDLG_TAB_EMAILCONTACT = 0,
	/** 'Invite by Phone' tab page. */
	SDK_INVITEDLG_TAB_PHONECONTACT,
	/** 'Invite a Room System' tab page. */
	SDK_INVITEDLG_TAB_ROOMSYSTEM,
};

enum ZNSDKH323TabPage
{
	/** 'Dial In' sub-tab page under Room System invitation tab page. */
	SDK_INVITEDLG_H323_DIALIN = 0,
	/** 'Call Out' sub-tab page under Room System invitation tab page. */
	SDK_INVITEDLG_H323_CALLOUT,
};

/**
 * @brief Determines if the user handles the corresponding type of the warning message with user's own program.
 * Here are more detailed structural descriptions.
 */
typedef struct _ZNZoomRedirectWarningMsgOption
{
	/** true indicates the user will handle the warning message of bad network with its own program. */
	bool bRedirectBadNetwork;
	/** true indicates the user will handle the warning message of high cpu with its own program. */
	bool bRedirectWarnHighCPU;
	_ZNZoomRedirectWarningMsgOption()
	{
		bRedirectBadNetwork = false;
		bRedirectWarnHighCPU = false;
	}
}ZNZoomRedirectWarningMsgOption;

//SettingDlgShowTabPageOptionDef
#define SETTING_DLG_SHOW_VIRTUAL_BACK_GROUND_TABPAGE 1UL
#define SETTING_DLG_SHOW_VIDEO_TABPAGE (1UL << 1)
#define SETTING_DLG_SHOW_STATISTICS_TABPAGE (1UL << 2)
#define SETTING_DLG_SHOW_RECORDING_TABPAGE (1UL << 3)
#define SETTING_DLG_SHOW_GENERAL_TABPAGE (1UL << 4)
#define SETTING_DLG_SHOW_FEEDBACK_TABPAGE (1UL << 5)
#define SETTING_DLG_SHOW_AUDIO_TABPAGE (1UL << 6)
#define SETTING_DLG_SHOW_ADVANCED_FEATURE_TABPAGE (1UL << 7)
#define SETTING_DLG_SHOW_ACCESSIBILITY_TABPAGE (1UL << 8)

//SettingDlgShowURLOptionDef
#define ZNSettingDlgURL_General_ViewMoreSettings 1UL
#define ZNSettingDlgURL_Video_SupportCenter (1UL << 1)
#define ZNSettingDlgURL_Audio_LearnMore (1UL << 2)
#define ZNSettingDlgURL_Share_and_VB_LearnMore (1UL << 3)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Enumeration of the network type.
 */
enum ZNSettingsNetWorkType
{
	/** Wired LAN. */
	ZNSETTINGS_NETWORK_WIRED = 0,
	/** WIFI. */
	ZNSETTINGS_NETWORK_WIFI = 1,
	/** PPP. */
	ZNSETTINGS_NETWORK_PPP = 2,
	/** 3G. */
	ZNSETTINGS_NETWORK_3G = 3,
	/** Others. */
	ZNSETTINGS_NETWORK_OTHERS = 4,
	/** Unknown network. */
	ZNSETTINGS_NETWORK_UNKNOWN = -1,
};

/**
 * @brief Enumeration of the connection type.
 */
enum ZNSettingConnectionType
{
	/** Cloud connection. */
	ZNSETTINGS_CONNECTION_TYPE_CLOUD,
	/** Direct connection. */
	ZNSETTINGS_CONNECTION_TYPE_DIRECT,
	/** Unknown connection. */
	ZNSETTINGS_CONNECTION_TYPE_UNKNOWN = -1,
};

/**
 * @brief Overall statistic information.
 */
typedef struct _ZNOverallStatisticInfo
{
	/** Network type. */
	ZNSettingsNetWorkType net_work_type;
	/** Connection type. */
	ZNSettingConnectionType connection_type;
	/** Proxy address. */
	ZoomSTRING proxy_addr;
	_ZNOverallStatisticInfo()
	{
		net_work_type = ZNSETTINGS_NETWORK_UNKNOWN;
		connection_type = ZNSETTINGS_CONNECTION_TYPE_UNKNOWN;
	}
}ZNOverallStatisticInfo;

/**
 * @brief The audio status information.
 */
typedef struct _ZNAudioSessionStatisticInfo
{
	/** Sending frequency, unit: KHz. */
	int frequency_send;
	/** Receiving frequency, unit: KHz. */
	int frequency_recv;
	/** Sending latency, unit: ms. */
	int latency_send;
	/** Receiving latency, unit: ms. */
	int latency_recv;
	/** Sending jitter, unit: ms. */
	int jitter_send;
	/** Receiving jitter, unit: ms. */
	int jitter_recv;
	/** Sending packet loss, unit: %. */
	float packetloss_send;
	/** Receiving packet loss, unit: %. */
	float packetloss_recv;
}ZNAudioSessionStatisticInfo;

/**
 * @brief The video status information.
 */
typedef struct ZNASVSessionStatisticInfo
{
	/** Sending latency, unit: ms. */
	int latency_send;
	/** Receiving latency, unit: ms. */
	int latency_recv;
	/** Sending jitter, unit: ms. */
	int jitter_send;
	/** Receiving jitter, unit: ms. */
	int jitter_recv;
	/** Sending max packet loss, unit: %. */
	float packetloss_send_max;
	/** Receiving max packet loss, unit: %. */
	float packetloss_recv_max;
	/** Sending average packet loss, unit: %. */
	float packetloss_send_avg;
	/** Receiving average packet loss, unit: %. */
	float packetloss_recv_avg;
	/** Sending resolution, HIWORD->height, LOWORD->width. */
	int resolution_send;
	/** Receiving resolution, HIWORD->height, LOWORD->width. */
	int resolution_recv;
	/** Frame per second sending. */
	int fps_send;
	/** Frame per second receiving. */
	int fps_recv;
}ZNASVSessionStatisticInfo;

typedef enum
{
	ZNZoomSDKWallpaperLayoutMode_None,
	ZNZoomSDKWallpaperLayoutMode_Fill,
	ZNZoomSDKWallpaperLayoutMode_Fit
}ZNZoomSDKWallpaperLayoutMode;

typedef enum
{
	ZNZoomSDKWallpaperSettingStatus_None,
	ZNZoomSDKWallpaperSettingStatus_Downloading,
	ZNZoomSDKWallpaperSettingStatus_Downloaded,
	ZNZoomSDKWallpaperSettingStatus_DownloadFail
}ZNZoomSDKWallpaperSettingStatus;

/**
 * @brief Wall-paper item struct.
 */
typedef struct tagWallpaperItem
{
	/** The layout mode of the wallpaper. */
	ZNZoomSDKWallpaperLayoutMode wallpaperLayoutMode;
	/** The wallpaper id. */
	ZoomSTRING wallpaperId;
	/** The wallpaper title. */
	ZoomSTRING title;
	/** The wallpaper thumbnail path. */
	ZoomSTRING thumbnailPath;
	/** The full image path of the wallpaper. */
	ZoomSTRING path;
	/** The transparency of the wallpaper. */
	int32_t transparency;
	tagWallpaperItem()
	{
		wallpaperLayoutMode = ZNZoomSDKWallpaperLayoutMode_None;
		transparency = -1;
	}
}ZNWallpaperItem;

/**
 * @brief Virtual background image information structure.
 */
typedef struct tagVirtualBGImageInfo
{
	/** Determine the usage of current image */
	bool isSelected;
	/** Determine the current image can be deleted from the list */
	bool isAllowDelete;
	/** The file path of current image */
	ZoomSTRING imageFilePath;
	/** The name of current image */
	ZoomSTRING imageName;
	/** Image handle */
	int64_t imageHandle;
	tagVirtualBGImageInfo()
	{
		isSelected = false;
		isAllowDelete = false;
		imageHandle = -1;
	}
}ZNVirtualBGImageInfo;

enum ZNVBVideoError
{
	ZNVB_VideoError_None = 0,
	ZNVB_VideoError_UnknownFormat,
	ZNVB_VideoError_ResolutionHigh1080P,
	ZNVB_VideoError_ResolutionHigh720P,
	ZNVB_VideoError_ResolutionLow,
	ZNVB_VideoError_PlayError,
	ZNVB_VideoError_OpenError,
};

/**
 * @brief Type of necessary information to join the meeting.
 * Here are more detailed structural descriptions.
 */
enum ZNRequiredInfoType
{
	/** Initialization. */
	ZNREQUIRED_INFO_TYPE_NONE,
	/** The user needs to enter the password when joins the meeting. Via the InputMeetingPasswordAndScreenName() to specify the password information. */
	ZNREQUIRED_INFO_TYPE_Password,
	/** If the password is invalid, the user needs to re-enter it. Via the InputMeetingPasswordAndScreenName() to specify the password information. */
	ZNREQUIRED_INFO_TYPE_Password4WrongPassword,
	/** The user needs to enter the screen name and the password,via the InputMeetingPasswordAndScreenName() to specify the necessary information. */
	ZNREQUIRED_INFO_TYPE_PasswordAndScreenName,
	/** The user needs to enter the screen name. Via the InputMeetingPasswordAndScreenName() to specify the screen name information. */
	ZNREQUIRED_INFO_TYPE_ScreenName,
	/** The user needs to enter the screen name and the meeting id,via the InputMeetingMeetingIDAndScreenName() to specify the necessary information. */
	ZNREQUIRED_INFO_TYPE_MeetingIDAndScreenName,
};

/**
 * @brief Register type of webinar.
 * Here are more detailed structural descriptions.
 */
enum ZNWebinarNeedRegisterType
{
	/** Initialization. */
	ZNWebinarReg_NONE,
	/** Register webinar account by URL. */
	ZNWebinarReg_By_Register_Url,
	/** Register webinar account by email and the screen name. */
	ZNWebinarReg_By_Email_and_DisplayName,
};

/**
 * @brief The action user suggested to take after getting the callback event "IMeetingUIControllerEvent::onAudioBtnClicked()"
 * Here are more detailed structural descriptions.
 */
enum ZNAudioCallbackActionInfo
{
	/** For initialization. */
	ZNACTION_INFO_NONE = 0,
	/** Choose audio device because no audio device is connected yet. */
	ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_NOAUDIODEVICECONNECTTED,
	/** Choose audio device because there is an error in the connected computer audio device. */
	ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_COMPUTERAUDIODEVICEERROR,
	/** Choose audio device because there is an error in the connected phone call device. */
	ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_PHONECALLDEVICEERROR,
	/** Need to join voip. */
	ZNACTION_INFO_NEED_JOIN_VOIP,
	/** Mute or unmute some user's audio according to the "AudioBtnClickedCallbackInfo::userid_MuteUnmute". */
	ZNACTION_INFO_MUTE_UNMUTE_AUDIO,
	/** Show audio setting window. */
	ZNACTION_INFO_SHOW_AUDIO_SETTING_WINDOW,
};

enum ZNZoomSDKResolution
{
	ZNZoomSDKResolution_90P = 0,
	ZNZoomSDKResolution_180P,
	ZNZoomSDKResolution_360P,
	ZNZoomSDKResolution_720P,
	ZNZoomSDKResolution_1080P,
	ZNZoomSDKResolution_NoUse = 100
};

enum ZNZoomSDKRawDataType
{
	ZNRAW_DATA_TYPE_VIDEO = 0,
	ZNRAW_DATA_TYPE_SHARE,
};

enum ZNRawDataStatus
{
	ZNRawData_On,
	ZNRawData_Off,
};

enum ZNZoomSDKVideoSubscribeFailReason
{
	ZNZoomSDKVideoSubscribe_Fail_None = 0,
	ZNZoomSDKVideoSubscribe_Fail_ViewOnly,
	ZNZoomSDKVideoSubscribe_Fail_NotInMeeting,
	ZNZoomSDKVideoSubscribe_Fail_HasSubscribe1080POr720,
	ZNZoomSDKVideoSubscribe_Fail_HasSubscribeTwo720P,
	ZNZoomSDKVideoSubscribe_Fail_HasSubscribeExceededLimit,
	ZNZoomSDKVideoSubscribe_Fail_TooFrequentCall,
};

/**
 * @brief The suggested action information for user to handle after getting the callback event "IMeetingUIControllerEvent::onAudioBtnClicked()"
 * Here are more detailed structural descriptions.
 */
typedef struct tagZNAudioBtnClickedCallbackInfo
{
	/** The id of the user that should be muted or unmuted. When no mute or unmute operation is required, the value is 0 */
	unsigned int userid_MuteUnmute;
	/** The suggested action for user to take. */
	ZNAudioCallbackActionInfo audio_clicked_action;
	tagZNAudioBtnClickedCallbackInfo()
	{
		userid_MuteUnmute = 0;
		audio_clicked_action = ZNACTION_INFO_NONE;
	}

}ZNAudioBtnClickedCallbackInfo;

/**
 * @brief Enumeration of hardware acceleration. For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0066515>.
 */
typedef enum
{
	/** Utilizes hardware resources to improve rendering of received video feeds. */
	ZN_VIDEO_HARDWARE_ENCODE_RECEIVING = 0,
	/** Utilizes hardware resources to improve rendering of the video feed being sent out. */
	ZN_VIDEO_HARDWARE_ENCODE_SENDING,
	/** Utilizes hardware resources to improve rendering of the overall video feeds. */
	ZN_VIDEO_HARDWARE_ENCODE_PROCESSING,
}ZN_VIDEO_HARDWARE_ENCODE_TYPE;

/**
 * @brief Enumeration for echo cancellation.  For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0066398>. 
 */
typedef enum {
	/** Automatically adjust echo cancellation, balancing CPU and performance */
	ZN_SDK_ECHO_CANCELLATION_DEFAULT = 0,
	/** Better echo limitation, taking into account multiple people talking at the same time, low CPU utilization */
	ZN_SDK_ECHO_CANCELLATION_LOW,
	/** Best experience when multiple people are talking at the same time. Enabling this option may increase CPU utilization */
	ZN_SDK_ECHO_CANCELLATION_HIGH
}ZN_SDK_ECHO_CANCELLATION_LEVEL;

/**
 * @brief Webinar Legal notices explained.
 * Here are more detailed structural descriptions.
 */
typedef struct _ZNWebinarLegalNoticesExplainedInfo
{
	ZoomSTRING explained_content;
	ZoomSTRING url_register_account_owner;
	ZoomSTRING url_register_terms;
	ZoomSTRING url_register_privacy_policy;
}ZNWebinarLegalNoticesExplainedInfo;

/**
 * @brief Meeting statistics warning type.
 * Here are more detailed structural descriptions.
 */
enum ZNStatisticsWarningType
{
	/** No warning */
	ZNStatistics_Warning_None,
	/** The network connection quality is bad */
	ZNStatistics_Warning_Network_Quality_Bad,
	/** The system is busy */
	ZNStatistics_Warning_Busy_System,
};

/**
 * @brief Meeting parameter.
 * Here are more detailed structural descriptions.
 */
typedef struct tagZNMeetingParameter
{
	/** Meeting type */
	ZNMeetingType meeting_type;
	/** View only or not. true indicates to view only */
	bool is_view_only;
	/** Auto local recording or not. true indicates to auto local recording */
	bool is_auto_recording_local;
	/** Auto cloud recording or not. true indicates to auto cloud recording */
	bool is_auto_recording_cloud;
	/** Meeting number */
	uint64_t meeting_number;
	/** Meeting topic */
	ZoomSTRING meeting_topic;
	/** Meeting host */
	ZoomSTRING meeting_host;
	tagZNMeetingParameter()
	{
		meeting_type = ZNMEETING_TYPE_NONE;
		is_view_only = true;
		is_auto_recording_local = false;
		is_auto_recording_cloud = false;
		meeting_number = 0;
	}
}ZNMeetingParameter;

/**
 * @brief Audio share mode.
 * Here are more detailed structural descriptions.
 */
enum ZNAudioShareMode
{
	/** Mono mode. */
	ZNAudioShareMode_Mono,
	/** Stereo mode. */
	ZNAudioShareMode_Stereo
};

/**
 * @brief Visible shared source information.
 * Here are more detailed structural descriptions..
 */
typedef struct tagZoomSDKSharingSourceInfo
{
	/** User ID. */
	unsigned int userid;
	/** Share source ID. */
	unsigned int shareSourceID;
	/** The values of sharing status. */
	ZNShareStatus status;
	/** Display or not on the primary view. Available only for Zoom UI mode. */
	bool isShowingInFirstView;
	/** Display or not on the secondary view. Available only for Zoom UI mode. */
	bool isShowingInSecondView;
	/** Enable or disable the remote control. */
	bool isCanBeRemoteControl;
	/** Enable or disable the optimizing video. */
	bool bEnableOptimizingVideoSharing;
	/** Type of sharing.
	 * @note In early share status callbacks, for example, ZN_Sharing_Self_Send_Begin or ZN_Sharing_Other_Share_Begin,
	 *       this value can be ZNSHARE_TYPE_UNKNOWN temporarily. The finalized content type is available after
	 *       onShareContentNotification is received.
	 */
	ZNShareType contentType;
#if (defined __MACOS__)
	/** Handle of sharing application or white-board. It is invalid unless the value of the eShareType is SHARE_TYPE_AS or SHARE_TYPE_WB. */
	uint32_t windowID;
	/** The ID of screen to be shared. It is invalid unless the value of the eShareType is SHARE_TYPE_DS. */
	uint32_t monitorID;
#else
	/** Handle of sharing application or white-board. It is invalid unless the value of the eShareType is SHARE_TYPE_AS or SHARE_TYPE_WB. */
	uint64_t windowID;
	/** The ID of screen to be shared. It is invalid unless the value of the eShareType is SHARE_TYPE_DS. */
	ZoomSTRING monitorID;
#endif

	tagZoomSDKSharingSourceInfo()
	{
		userid = 0;
		shareSourceID = 0;
		contentType = ZNSHARE_TYPE_UNKNOWN;
		status = ZN_Sharing_None;
		isShowingInFirstView = false;
		isShowingInSecondView = false;
		isCanBeRemoteControl = false;
		bEnableOptimizingVideoSharing = false;
	}
}ZNZoomSDKSharingSourceInfo;

/**
 * @brief The type for disclaimer dialog.
 * Here are more detailed structural descriptions.
 */
enum ZNMeetingReminderType
{
	/** Reminder type of login. */
	ZNTYPE_LOGIN_REQUIRED,
	/** Reminder type of start or join meeting. */
	ZNTYPE_START_OR_JOIN_MEETING,
	/** Reminder type of record reminder. */
	ZNTYPE_RECORD_REMINDER,
	/** Reminder type of record disclaimer. */
	ZNTYPE_RECORD_DISCLAIMER,
	/** Reminder type of live stream disclaimer. */
	ZNTYPE_LIVE_STREAM_DISCLAIMER,
	/** Reminder type of archive disclaimer. */
	ZNTYPE_ARCHIVE_DISCLAIMER,
	/** Reminder type of join webinar as panelist. */
	ZNTYPE_WEBINAR_AS_PANELIST_JOIN,
	/** Reminder type of Terms of service or privacy statement changed. */
	ZNTYPE_TERMS_OF_SERVICE,
	/** Reminder type of smart summary disclaimer. */
	ZNTYPE_SMART_SUMMARY_DISCLAIMER,
	/** Reminder type of query disclaimer. */
	ZNTYPE_QUERY_DISCLAIMER = 10,
	/** Reminder type of webinar promote attendee. */
	ZNTYPE_WEBINAR_ATTENDEE_PROMOTE_REMINDER = 13,
	/** Reminder type of joining a meeting with private mode. */
	ZNTYPE_JOIN_PRIVATE_MODE_MEETING_REMINDER,
	/** Reminder type to enable smart recording request. This type is marked as deprecated. */
	ZNTYPE_SMART_RECORDING_ENABLE_REQUEST_REMINDER,
	/** Reminder type to enable smart recording. This type is marked as deprecated. */
	ZNTYPE_ENABLE_SMART_RECORDING_REMINDER,
	/** Reminder type of Close Caption disclaimer. */
	ZNTYPE_CLOSED_CAPTION_DISCLAIMER = 18,
	/** Reminder type of disclaimers combination. */
	ZNTYPE_MULTI_DISCLAIMER,
	/** Reminder type for a join meeting connector with guest mode. */
	ZNTYPE_JOIN_MEETING_CONNECTOR_AS_GUEST_REMINDER,
	/** Reminder type of common disclaimer. */
	ZNTYPE_COMMON_DISCLAIMER,
	/** Reminder type of custom AI companion disclaimer. */
	ZNTYPE_CUSTOM_AI_COMPANION_DISCLAIMER,
	/** Reminder type of AI Companion restrict notify disclaimer. */
	ZNTYPE_AIC_RESTRICT_NOTIFY_DISCLAIMER,
};

/**
 * @brief The option for meeting feature enumeration.
 */
enum ZNFeatureEnableOption
{
	/** Do not enable */
	ZNEnableOption_None,
	/** Enable for this meeting */
	ZNEnableOption_Once,
	/** Enable for this and all future meetings on this account */
	ZNEnableOption_Always,
};

/**
 * @brief Enumeration of action type which user should take.
 * Here are more detailed structural descriptions.
 */
enum ZNActionType
{
	/** Need no more action. */
	ZNActionType_None,
	/** Need to sign in. */
	ZNActionType_NeedSignIn,
	/** Need to switch account. */
	ZNActionType_NeedSwitchAccount,
};

/**
 * @brief structure of reminder dialog content.
 */
typedef struct _ZNMeetingReminderContent
{
	/** The type of the reminder */
	ZNMeetingReminderType type;
	/** The title of the reminder dialog content */
	ZoomSTRING title;
	/** The detail content of the reminder dialog content */
	ZoomSTRING content;
	/** Determines whether block the user join or stay in the meeting. true indicates block the user join or stay in the meeting. Otherwise, false. */
	bool is_blocking;
	/** The type of the action which user should take after receiving this reminder content */
	ZNActionType actionType;
}ZNMeetingReminderContent;

/** 
 * @brief The authority to chat in the normal meeting.  
 * Here are more detailed structural descriptions..
 */
typedef struct _ZNNormalMeetingChatStatus
{
	/** true indicates that the user owns the authority to send message to chat */
	bool can_chat;
	/** true indicates that the user owns the authority to send message to all */
	bool can_chat_to_all;
	/** true indicates that the user owns the authority to send message to an individual attendee in the meeting */
	bool can_chat_to_individual;
	/** true indicates that the user owns the authority to send message only to the host */
	bool is_only_can_chat_to_host;
}ZNNormalMeetingChatStatus;

/** 
 * @brief The authority to chat for the normal attendee in the webinar.
 * Here are more detailed structural descriptions..
 */
typedef struct _ZNWebinarAttendeeChatStatus
{
	/** true indicates that the attendee can send message to chat */
	bool can_chat;
	/** true indicates that the user owns the authority to send message to all the panelists and attendees */
	bool can_chat_to_all_panellist_and_attendee;
	/** true indicates that the user owns the authority to send message to all the panelists */
	bool can_chat_to_all_panellist;
}ZNWebinarAttendeeChatStatus;

/** 
 * @brief The authority to chat for the host, co-host and panelist to chat in webinar.
 * Here are more detailed structural descriptions..
 */
typedef struct _ZNWebinarOtherUserRoleChatStatus
{
	/** true indicates that the user owns the authority to send message to all the panelists */
	bool can_chat_to_all_panellist;
	/** true indicates that the user owns the authority to send message to all */
	bool can_chat_to_all_panellist_and_attendee;
	/** true indicates that the user owns the authority to send message to individual attendee */
	bool can_chat_to_individual;
}ZNWebinarOtherUserRoleChatStatus;

/** 
 * @brief The authority to chat in the specified meeting.
 * Here are more detailed structural descriptions..
 */
typedef struct _ZNChatStatus
{
	/**
	 * The ut value depends on the value of the other members in the structure. 
	 * When the value of is_webinar_meeting is false, the ut value is the NormalMeetingChatStausnormal_meeting_status. 
	 * When the values of the is_webinar_meeting and the is_webinar_attendee is true, the ut value is WebinarAttendeeChatStatus webinar_attendee_status. 
	 * The value of is_webinar_meeting is true while the is_webinar_attendee is false, the ut value is WebinarOtherUserRoleChatStatus webinar_other_status.
	 */
	union
	{
		ZNNormalMeetingChatStatus normal_meeting_status;
		ZNWebinarAttendeeChatStatus webinar_attendee_status;
		ZNWebinarOtherUserRoleChatStatus webinar_other_status;
	}ut;
	/** true indicates that it is disabled to chat in the specified meeting */
	bool is_chat_off;
	/** true indicates that the owner of the current message is the attendee of the webinar */
	bool is_webinar_attendee;
	/** true indicates that the current meeting is webinar */
	bool is_webinar_meeting;

	_ZNChatStatus()
	{
		Reset();
	}

	void Reset()
	{
		memset(this, 0, sizeof(_ZNChatStatus));  //checked safe
	}
}ZNChatStatus;

/**
 * @brief Enumerations of the chat privilege.
 */
typedef enum {
	/** allow attendee to chat with everyone [meeting & webinar]. */
	ZNSDK_CHAT_PRIVILEGE_ALL = 1,
	/** allow attendee to chat with all panelists only, but cannot to "all panelists and attendees" [webinar]. */
	ZNSDK_CHAT_PRIVILEGE_ALL_PANELIST = 2,
	/** allow attendee to chat with host only [meeting]. */
	ZNSDK_CHAT_PRIVILEGE_HOST = 3,
	/** allow attendee to chat with no one [meeting & webinar]. */
	ZNSDK_CHAT_PRIVILEGE_DISABLE_ATTENDEE_CHAT = 4,
	/** allow attendee to chat with host and public [meeting]. */
	ZNSDK_CHAT_PRIVILEGE_HOST_PUBLIC = 5,
	ZNSDK_CHAT_PRIVILEGE_END
} ZNSDKChatPrivilege;

/**
 * @brief Enumerations of the type for chat message.
 */
typedef enum
{
	/** For initialize. */
	ZNSDKChatMessageType_To_None,
	/** Chat message is send to all. */
	ZNSDKChatMessageType_To_All,
	/** Chat message is send to all panelists. */
	ZNSDKChatMessageType_To_All_Panelist,
	/** Chat message is send to individual attendee and cc panelists. */
	ZNSDKChatMessageType_To_Individual_Panelist,
	/** Chat message is send to individual user. */
	ZNSDKChatMessageType_To_Individual,
	/** Chat message is send to waiting room user. */
	ZNSDKChatMessageType_To_WaitingRoomUsers,
}ZNSDKChatMessageType;

/**
 * @brief Enumerations of the chat message delete type.
 */
typedef enum
{
	/** none. */
	ZNSDK_CHAT_DELETE_BY_NONE,
	/** delete by self. */
	ZNSDK_CHAT_DELETE_BY_SELF,
	/** delete by host. */
	ZNSDK_CHAT_DELETE_BY_HOST,
	/** delete by DLP when the message goes against the host organization's compliance policies. */
	ZNSDK_CHAT_DELETE_BY_DLP,
}ZNSDKChatMessageDeleteType;

/**
 * @brief Enumerations of the content rich text style type for chat message.
 */
typedef enum
{
	/** Chat message rich text style normal. */
	ZNTextStyle_None,
	/** Chat message rich text style bold. */
	ZNTextStyle_Bold,
	/** Chat message rich text style italic. */
	ZNTextStyle_Italic,
	/** Chat message rich text style strike through. */
	ZNTextStyle_Strikethrough,
	/** Chat message rich text style bulleted list. */
	ZNTextStyle_BulletedList,
	/** Chat message rich text style numbered list. */
	ZNTextStyle_NumberedList,
	/** Chat message rich text style underline. */
	ZNTextStyle_Underline,
	/** Chat message rich text style font size. */
	ZNTextStyle_FontSize,
	/** Chat message rich text style font color. */
	ZNTextStyle_FontColor,
	/** Chat message rich text style background color. */
	ZNTextStyle_BackgroundColor,
	/** Chat message rich text style indent. */
	ZNTextStyle_Indent,
	/** Chat message rich text style paragraph. */
	ZNTextStyle_Paragraph,
	/** Chat message rich text style quote. */
	ZNTextStyle_Quote,
	/** Chat message rich text style insert link. */
	ZNTextStyle_InsertLink
}ZNRichTextStyle;

/**
 * @brief Chat message rich text style offset.
 */
typedef struct _ZNRichTextStyleOffset
{
	/** A certain rich-text style's start position. */
	unsigned int positionStart;
	/** The end position of a certain style in rich text. */
	unsigned int positionEnd;
	/** A certain rich-text style's supplementary information. */
	ZoomSTRING reserve;
}ZNRichTextStyleOffset;

/**
 * @brief Chat message rich text item of a certain style.
 */
typedef struct _ZNRichTextStyleItem
{
	/** The rich text type of a portion of the current message. */
	ZNRichTextStyle textStyle;
	/** The current message's rich text position info list of a certain style. */
	std::vector<ZNRichTextStyleOffset> textStyleOffsetList;
}ZNRichTextStyleItem;

/**
 * @brief Chat message information structure.
 */
typedef struct _ZNChatMsgInfo
{
	/** The message ID of the current message. */
	ZoomSTRING messageID;
	/** The sender ID of the current message. */
	unsigned int senderUserId;
	/** The sender screen name of the current message. */
	ZoomSTRING senderDisplayName;
	/** The receiver ID of the current message. */
	unsigned int receiverUserId;
	/** The receiver screen name of the current message. */
	ZoomSTRING receiverDisplayName;
	/** The content of the current message. */
	ZoomSTRING content;
	/** The timestamps of the current message. */
	time_t timeStamp;
	/** If the current message is sent to all. */
	bool isChatToAll;
	/** If the current message is sent to all the panelists. */
	bool isChatToAllPanelist;
	/** If the current message is sent to waiting room. */
	bool isChatToWaitingroom;
	/** The chat message type of the current message. */
	ZNSDKChatMessageType chatMessageType;
	/** If the current message is a reply to another message. */
	bool isComment;
	/** If the current message is part of a message thread, and can be directly replied to. */
	bool isThread;
	/** The current message's chat message font style list. */
	std::vector<ZNRichTextStyleItem> textStyleItemList;
	/** The current message's thread ID. */
	ZoomSTRING threadID;
}ZNChatMsgInfo;

typedef enum
{
	/** The file transfer has no state. */
	ZNSDKFileTransferState_None = 0,
	/** The file transfer is ready to start. */
	ZNSDKFileTransferState_ReadyToTransfer,
	/** The file transfer is in progress. */
	ZNSDKFileTransferState_Transfering,
	/** The file transfer failed. */
	ZNSDKFileTransferState_TransferFailed,
	/** The file transfer completed successfully. */
	ZNSDKFileTransferState_TransferDone,
}ZNSDKFileTransferStatus;

/**
 * @brief The basic information of transfer file.
 */
typedef struct tagSDKFileTransferInfo
{
	/** The message identify of transfer file. */
	ZoomSTRING messageID;
	/** The status of the file transfer. */
	ZNSDKFileTransferStatus trans_status;
	/** The time stamp of the file. */
	time_t time_stamp;
	/** Is the file send to all user in meeting. */
	bool is_send_to_all;
	/** The bytes of transfer file size. */
	unsigned int file_size;
	/** The file name of transfer file. */
	ZoomSTRING file_name;
	/** The percentage of the file transfer completed. */
	unsigned int complete_percentage;
	/** The size of the file transferred so far in bytes. */
	unsigned int complete_size;
	/** The speed of the file transfer in bits per second. */
	unsigned int bit_per_second;
	tagSDKFileTransferInfo()
	{
		Reset();
	}

	void Reset()
	{
		memset(this, 0, sizeof(tagSDKFileTransferInfo));  //checked safe
	}
}ZNSDKFileTransferInfo;

/**
 * @brief WaitingRoom LayoutType.
 * Here are more detailed structural descriptions.
 */
enum ZNWaitingRoomLayoutType
{
	ZNWaitingRoomLayoutType_Default,
	ZNWaitingRoomLayoutType_Logo,
	ZNWaitingRoomLayoutType_Video
};

/**
 * @brief Download Status of CustomWaitingRoomData.
 * Here are more detailed structural descriptions.
 */
enum ZNCustomWaitingRoomDataStatus
{
	ZNCustomWaitingRoomDataStatus_Init,
	ZNCustomWaitingRoomDataStatus_Downloading,
	ZNCustomWaitingRoomDataStatus_Download_OK,
	ZNCustomWaitingRoomDataStatus_Download_Failed
};

/**
 * @brief Zoom SDK color. The standard RGB color model has a value range of 0-255.
 */
struct ZNZoomSDKColor {
	/** Font color R value. */
	unsigned int red = 0;
	/** Font color G value. */
	unsigned int green = 0;
	/** Font color B value. */
	unsigned int blue = 0;
};

/**
 * @brief The waiting room page color.
 */
struct ZNWaitingRoomBrandingPageColor {
	ZNZoomSDKColor background_color;
};

/**
 * @brief The waiting room text color.
 */
struct ZNWaitingRoomBrandingTextColor {
	ZNZoomSDKColor primary_color;
	ZNZoomSDKColor secondary_color;
	ZNZoomSDKColor paragraph_color;
	ZNZoomSDKColor hyperlink_color;
};

/**
 * @brief The waiting room button color.
 */
struct ZNWaitingRoomBrandingButtonColor {
	ZNZoomSDKColor primary_button_color;
};

/**
 * @brief The WaitingRoom Customize Data Info.
 * Here are more detailed structural descriptions.
 */
typedef struct CustomWaitingRoomData_s
{
	ZoomSTRING title;
	ZoomSTRING description;
	ZoomSTRING logo_path;
	ZoomSTRING video_path;
	ZoomSTRING image_path;
	ZNWaitingRoomLayoutType type;
	ZNCustomWaitingRoomDataStatus status;

	ZNWaitingRoomBrandingPageColor page_color;
	ZNWaitingRoomBrandingTextColor text_color;
	ZNWaitingRoomBrandingButtonColor button_color;
	CustomWaitingRoomData_s()
	{
		type = ZNWaitingRoomLayoutType_Default;
		status = ZNCustomWaitingRoomDataStatus_Init;
	}
}ZNCustomWaitingRoomData;

/** 
 * @brief Webinar Meeting Status.
 * Here are more detailed structural descriptions.
 */
typedef struct tagWebinarMeetingStatus
{
	/** true indicates that the panelist is able to turn on the video. Otherwise, false. */
	bool allow_panellist_start_video;
	/** true indicates that the attendee is able to chat. Otherwise, false. */
	bool allow_attendee_chat;
	/** true indicates that the attendee is able to emoji reaction. Otherwise, false. */
	bool allow_emoji_reaction;
	/** true indicates that the attendee is able to raise hand. Otherwise, false. */
	bool allow_attendee_raise_hand;
	/** true indicates that the attendee is able to view participant count. Otherwise, false. */
	bool allow_attendee_view_participant_count;
	tagWebinarMeetingStatus()
	{
		Reset();
	}

	void Reset()
	{
		allow_panellist_start_video = false;
		allow_attendee_chat = false;
		allow_emoji_reaction = false;
		allow_attendee_raise_hand = false;
		allow_attendee_view_participant_count = false;
	}
}ZNWebinarMeetingStatus;

/**
 * @brief Enumerations of the panelist chat privilege.
 */
enum ZNSDKPanelistChatPrivilege
{
	/** Allow panelists only to chat with each other */
	ZNSDKPanelistChatPrivilege_PanelistOnly = 1,
	/** Allow panelist to chat with everyone */
	ZNSDKPanelistChatPrivilege_All = 2
};

/**
 * @brief Enumerations of the attendee view display mode.
 */
enum ZNSDKAttendeeViewMode
{
	/** Attendee view display mode is invalid */
	ZNSDKAttendeeViewMode_None,
	/** Follow host */
	ZNSDKAttendeeViewMode_FollowHost,
	/** Always view active speaker */
	ZNSDKAttendeeViewMode_Speaker,
	/** Always view gallery */
	ZNSDKAttendeeViewMode_Gallery,
	/** Attendee can manually switch between gallery and active speaker */
	ZNSDKAttendeeViewMode_Standard,
	/** Attendee view sharing side by side speaker */
	ZNSDKAttendeeViewMode_SidebysideSpeaker,
	/** Attendee view sharing side by side gallery */
	ZNSDKAttendeeViewMode_SidebysideGallery
};

/**
 * @brief Enumeration of AI companion feature.
 */
enum ZNAICompanionFeature
{
	/** Meeting summary with AI Companion generates summary assets */
	ZNSMART_SUMMARY,
	/** Meeting questions with AI Companion generates transcript assets */
	ZNQUERY,
	/** Smart recording with AI Companion generates recording assets */
	ZNSMART_RECORDING,
};

/**
 * @brief Enumeration of feedback types for AI Companion queries in a meeting.
 */
enum ZNMeetingAICompanionQueryFeedbackType
{
	/** No feedback provided. */
	ZNMeetingAICompanionQueryFeedbackType_None = 0,
	/** The feedback indicates the query response was helpful or satisfactory. */
	ZNMeetingAICompanionQueryFeedbackType_Good,
	/** The feedback indicates the query response was unhelpful or unsatisfactory. */
	ZNMeetingAICompanionQueryFeedbackType_Bad
};

/**
 * @brief Enumeration of possible error codes when requesting an AI Companion query during a meeting.
 */
enum ZNMeetingAICompanionQueryRequestError
{
	/** Request succeeded with no error. */
	ZNMeetingAICompanionQueryRequestError_OK = 0,
	/** The provided parameter(s) are invalid. */
	ZNMeetingAICompanionQueryRequestError_InvalidParam,
	/** Failed to send the query request. */
	ZNMeetingAICompanionQueryRequestError_SendFailed,
	/** The AI Companion web service is unavailable. */
	ZNMeetingAICompanionQueryRequestError_WebUnAvailable,
	/** Permission verification failed for the request. */
	ZNMeetingAICompanionQueryRequestError_PermissionVerifyFailed,
	/** The query request was rate-limited due to excessive frequency. */
	ZNMeetingAICompanionQueryRequestError_QueryRateLimitError,
	/** The query request timed out. */
	ZNMeetingAICompanionQueryRequestError_Timeout,
	/** An unknown error occurred. */
	ZNMeetingAICompanionQueryRequestError_Unknown = 100
};

/**
 * @brief Enumeration of config who in the meeting can interact with AI Companion by asking questions about the meeting. please visit https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0057749
 */
enum ZNMeetingAICompanionQuerySettingOptions
{
	/** Initialization. */
	ZNMeetingAICompanionQuerySettingOptions_None = 0,
	/** Allows all participants and attendee to ask questions about all discussions since AI Companion was active. */
	ZNMeetingAICompanionQuerySettingOptions_WhenQueryStarted,
	/** Allows all participants to ask questions about the discussion since they joined the current meeting. */
	ZNMeetingAICompanionQuerySettingOptions_WhenParticipantsJoin,
	/** Allow only the host, alternative host, and users with host privileges assigned before the meeting starts to ask questions about all discussions since AI Companion is active. */
	ZNMeetingAICompanionQuerySettingOptions_OnlyHost,
	/** Allows only participants and invitees from your organization to ask questions about all discussions since AI Companion was active. */
	ZNMeetingAICompanionQuerySettingOptions_ParticipantsAndInviteesInOurOrganization,
	/** Allows only participants from your organization to ask questions about the discussion since they joined the current meeting. */
	ZNMeetingAICompanionQuerySettingOptions_WhenParticipantsAndOrganizationJoin,
	/** Hosts and all panelists can ask question, and answers are based on the meeting's start until now. */
	ZNMeetingAICompanionQuerySettingOptions_HostAndPanelists = 10,
	/** Hosts and all panelists in our organization can ask question, and answers are based on the meeting's start until now. */
	ZNMeetingAICompanionQuerySettingOptions_HostAndPanelistsInOurOrganization
};

/**
 * @brief AI companion query item information.
 */
typedef struct _ZNMeetingAICompanionQueryItem
{
	/** The query question ID. */
	ZoomSTRING queryID;
	/** The query question content. */
	ZoomSTRING qustionContent;
	/** The query answer content. */
	ZoomSTRING answerContent;
	/** The error code. */
	ZNMeetingAICompanionQueryRequestError errorCode;
	/** The error message. */
	ZoomSTRING errorMsg;
	/** The timestamp. */
	time_t timeStamp;
}ZNMeetingAICompanionQueryItem;

/**
 * @brief Select and use any of the defined preference mode below when initializing the SDKVideoPreferenceSetting.
 * Video preference modes determined the video frame rate and resolution based on the user's bandwidth.
 * Here are more detailed structural descriptions.
 */
typedef enum
{
	/** Balance mode. Default Preference, no additional parameters needed. Zoom will do what is best under the current bandwidth situation and make adjustments as needed. */
	ZNSDKVideoPreferenceMode_Balance,
	/** Sharpness mode. Prioritizes a smooth video frame transition by preserving the frame rate as much as possible. */
	ZNSDKVideoPreferenceMode_Sharpness,
	/** Smoothness mode. Prioritizes a sharp video image by preserving the resolution as much as possible. */
	ZNSDKVideoPreferenceMode_Smoothness,
	/** Custom mode. Allows customization by providing the minimum and maximum frame rate. Use this mode if you have an understanding of your network behavior and a clear idea on how to adjust the frame rate to achieve the desired video quality. */
	ZNSDKVideoPreferenceMode_Custom
}ZNSDKVideoPreferenceMode;

/**
 * @brief When setting custom modes, the developer provides the maximum and minimum frame rates.
 * If the current bandwidth cannot maintain the minimum frame rate, the video system will drop to the next lower resolution.
 * The default maximum and minimum frame rates for other modes are 0.
 */
typedef struct tagSDKVideoPreferenceSetting
{
	/** 0: Balance mode; 1: Smoothness mode; 2: Sharpness mode; 3: Custom mode. */
	ZNSDKVideoPreferenceMode mode;
	/** 0 for the default value, minimum_frame_rate should be less than maximum_frame_rate, range: from 0 to 30. Out of range for frame-rate will use default frame-rate of Zoom. */
	uint32_t minimumFrameRate;
	/** 0 for the default value, maximum_frame_rate should be less and equal than 30, range: from 0 to 30. Out of range for frame-rate will use default frame-rate of Zoom. */
	uint32_t maximumFrameRate;
	tagSDKVideoPreferenceSetting()
	{
		mode = ZNSDKVideoPreferenceMode_Balance;
		minimumFrameRate = 0;
		maximumFrameRate = 0;
	}
}ZNSDKVideoPreferenceSetting;

/**
 * @brief Enumeration of video sharing quality options.
 * Used to control resolution and frame rate when "Optimize for video sharing" is enabled.
 */
typedef enum tagZNSDKVideoSharingQuality
{
	/** Not set or invalid value.
	 * @note Cannot be used as valid input for video sharing quality setters.
	 */
	ZNSDKVideoSharingQuality_None = 0,
	/** 720p at 30fps quality option. */
	ZNSDKVideoSharingQuality_720p_30fps,
	/** 720p at 60fps quality option. Requires the device to support high frame rate. */
	ZNSDKVideoSharingQuality_720p_60fps,
	/** 1080p at 30fps quality option. Requires the meeting to support Full HD. */
	ZNSDKVideoSharingQuality_1080p_30fps,
	/** 1080p at 60fps quality option. Requires Full HD and device 1080p60 capability. */
	ZNSDKVideoSharingQuality_1080p_60fps,
}ZNSDKVideoSharingQuality;

/**
 * @brief Answer item struct.
 */
typedef struct _ZNAnswerItem {
    /** The timestamp of the answer. */
    time_t timeStamp;
    /** The text of the answer. */
    ZoomSTRING text;
    /** The sender's name of the answer. */
    ZoomSTRING senderName;
    /** The related question's id of the answer. */
    ZoomSTRING questionID;
    /** The answer id. */
    ZoomSTRING answerID;
    /** Determines if the answer is private or not. */
    bool isPrivate;
    /** Determines if the answer is live or not. */
    bool isLiveAnswer;
    /** Determines whether the answer's sender is the user himself or not. */
    bool isSenderMyself;
}ZNAnswerItem;

/**
 * @brief Question item struct.
 */
typedef struct _ZNQAItemInfo {
    /** The timestamp of the question. */
    time_t timeStamp;
    /** The number of the up_voters of the question. */
    unsigned int upvoteNum;
    /** The text of the question. */
    ZoomSTRING text;
    /** The sender's name of the question. */
    ZoomSTRING senderName;
    /** The question id. */
    ZoomSTRING questionID;
    /** Determines if the question is anonymous. */
    bool isAnonymous;
    /** Determines if the question is marked as answered. */
    bool isMarkedAsAnswered;
    /** Determines if the question is marked as dismissed. */
    bool isMarkedAsDismissed;
    /** Determines if the question's sender is the user himself or not. */
    bool isSenderMyself;
    /** Determines if the user himself is an up_voter of the question or not. */
    bool isMySelfUpvoted;
    /** Determines if the question has live answers or not. */
    bool hasLiveAnswers;
    /** Determines if the question has text answers or not. */
    bool hasTextAnswers;
    /** Determines if the user himself is answering the question live or not. */
    bool amILiveAnswering;
    /** Get all the users' names who answers the question live. */
    ZoomSTRING liveAnswerName;
    /** Determines if the question is being answered live or not. */
    bool isLiveAnswering;
    /** Get the list of all the answers to the question. */
    std::vector<ZNAnswerItem> answerList;
}ZNQAItemInfo;

/**
 * @brief Specify the emoji reaction type.
 * Here are more detailed enum descriptions.
 */
typedef enum
{
    ZNSDKEmojiReactionType_Unknow,
    ZNSDKEmojiReactionType_Clap,
    ZNSDKEmojiReactionType_Thumbsup,
    ZNSDKEmojiReactionType_Heart,
    ZNSDKEmojiReactionType_Joy,
    ZNSDKEmojiReactionType_Openmouth,
    ZNSDKEmojiReactionType_Tada,
}ZNSDKEmojiReactionType;

typedef enum
{
	ZNSDKEmojiReactionSkinTone_Unknow,
	ZNSDKEmojiReactionSkinTone_Default,
	ZNSDKEmojiReactionSkinTone_Light,
	ZNSDKEmojiReactionSkinTone_MediumLight,
	ZNSDKEmojiReactionSkinTone_Medium,
	ZNSDKEmojiReactionSkinTone_MediumDark,
	ZNSDKEmojiReactionSkinTone_Dark,
}ZNSDKEmojiReactionSkinTone;

/**
 * @brief Enumerations of the type for live transcription operation type.
 */
typedef enum
{
	ZNSDK_LiveTranscription_OperationType_None,
	ZNSDK_LiveTranscription_OperationType_Add,
	ZNSDK_LiveTranscription_OperationType_Update,
	ZNSDK_LiveTranscription_OperationType_Delete,
	ZNSDK_LiveTranscription_OperationType_Complete,
    ZNSDK_LiveTranscription_OperationType_NotSupported,
}ZNSDKLiveTranscriptionOperationType;

/**
 * @brief live transcription message structure.
 */
typedef struct _ZNLiveTranscriptionMessageInfo {
    ZoomSTRING messageID;
    unsigned int speakerID;
    ZoomSTRING speakerName;
    ZoomSTRING messageContent;
    time_t timeStamp;
    ZNSDKLiveTranscriptionOperationType messageType;
}ZNLiveTranscriptionMessageInfo;

/**
 * @brief live transcription language.
 */
typedef struct _ZNLiveTranscriptionLanguage {
    /** The name of the language. */
    ZoomSTRING languageName;
    /** The ID of the language. */
    int languageID;
}ZNLiveTranscriptionLanguage;

/**
 * @brief Status of polling.
 */
typedef enum
{
    /** The initial status. */
    ZNSDKPollingStatus_Initial,
    /** User started polling. */
    ZNSDKPollingStatus_Started,
    /** User shared polling result. */
    ZNSDKPollingStatus_ShareResult,
    /** User stopped polling. */
    ZNSDKPollingStatus_Stopped,
}ZNSDKPollingStatus;

/**
 * @brief Type of polling.
 */
typedef enum
{
    ZNSDKPollingType_Unknown,
    ZNSDKPollingType_Poll,
    ZNSDKPollingType_Quiz,
}ZNSDKPollingType;

/**
 * @brief Type of polling question.
 */
typedef enum
{
    ZNSDKPollingQuestionType_Unknown,
    ZNDKPollingQuestionType_Single,
    ZNSDKPollingQuestionType_Multi,
    ZNSDKPollingQuestionType_Matching,
    ZNSDKPollingQuestionType_RankOrder,
    ZNSDKPollingQuestionType_ShortAnswer,
    ZNSDKPollingQuestionType_LongAnswer,
    ZNSDKPollingQuestionType_FillBlank,
    ZNSDKPollingQuestionType_NPS,
    ZNSDKPollingQuestionType_Dropdown,
}ZNSDKPollingQuestionType;

/**
 * @brief Type of polling action.
 */
typedef enum
{
    ZNSDKPollingActionType_Unknown,
    ZNSDKPollingActionType_Start,
    ZNSDKPollingActionType_Stop,
    ZNSDKPollingActionType_ShareResult,
    ZNSDKPollingActionType_StopShareResult,
    ZNSDKPollingActionType_Duplicate,
    ZNSDKPollingActionType_Delete,
    ZNSDKPollingActionType_Submit,
    ZNSDKPollingActionType_Error
}ZNSDKPollingActionType;

/**
 * @brief Polling item structure.
 */
typedef struct _ZNSDKPollingItem {
    ZoomSTRING pollingID;
    ZoomSTRING pollingName;
    ZNSDKPollingType pollingType;
    ZNSDKPollingStatus pollingStatus;
    unsigned int pollingQuestionCount;
    unsigned int totalVotedUserCount;
    bool isLibraryPolling;
}ZNSDKPollingItem;

/**
 * @brief Polling answer item struct.
 */
typedef struct _ZNSDKPollingAnswerItem {
    ZoomSTRING pollingID;
    ZoomSTRING pollingQuestionID;
    ZoomSTRING pollingSubQuestionID;
    ZoomSTRING pollingAnswerID;
    ZoomSTRING pollingAnswerName;
    ZoomSTRING pollingAnsweredContent;
    bool isChecked;
}ZNSDKPollingAnswerItem;

/**
 * @brief Polling answer result item structure.
 */
typedef struct _ZNSDKPollingAnswerResultItem {
    ZoomSTRING pollingID;
    ZoomSTRING pollingQuestionID;
    ZoomSTRING pollingSubQuestionID;
    ZoomSTRING pollingAnswerID;
    ZoomSTRING pollingAnswerName;
    unsigned int selectedCount;
}ZNSDKPollingAnswerResultItem;

/**
 * @brief Polling question item struct.
 */
typedef struct _ZNSDKPollingQuestionItem {
    ZoomSTRING pollingID;
    ZoomSTRING pollingQuestionID;
    ZoomSTRING pollingQuestionName;
    ZNSDKPollingQuestionType pollingQuestionType;
    unsigned int answeredCount;
    bool isRequired;
    std::vector<_ZNSDKPollingQuestionItem> pollingSubQuestionItemList;
    std::vector<ZNSDKPollingAnswerItem> pollingAnswerItemList;
}ZNSDKPollingQuestionItem;

/**
 * @brief Enumeration of reasons why sharing is not allowed.
 */
enum ZNCannotShareReasonType
{
    /** For initialization. */
    ZNCannotShareReasonType_None,
    /** Only the host is allowed to share. */
    ZNCannotShareReasonType_Locked,
    /** Sharing is disabled. */
    ZNCannotShareReasonType_Disabled,
    /** Another participant is currently sharing their screen. */
    ZNCannotShareReasonType_Other_Screen_Sharing,
    /** Another participant is currently sharing their whiteboard. */
    ZNCannotShareReasonType_Other_WB_Sharing,
    /** The user is sharing screen, and can grab. To grab, call EnableGrabShareWithoutReminder(true) before starting the share. */
    ZNCannotShareReasonType_Need_Grab_Myself_Screen_Sharing,
    /** Another is sharing their screen, and can grab. To grab, call EnableGrabShareWithoutReminder(true) before starting share. */
    ZNCannotShareReasonType_Need_Grab_Other_Screen_Sharing,
    /** Another is sharing pure computer audio, and can grab. To grab, call EnableGrabShareWithoutReminder(true) before starting share. */
    ZNCannotShareReasonType_Need_Grab_Audio_Sharing,
    /** Other or myself is sharing whiteboard, and can Grab. To grab, call EnableGrabShareWithoutReminder(true) before starting share. */
    ZNCannotShareReasonType_Need_Grap_WB_Sharing,
    /** The meeting has reached the maximum allowed screen share sessions. */
    ZNCannotShareReasonType_Reach_Maximum,
    /** Other share screen in main session. */
    ZNCannotShareReasonType_Have_Share_From_Mainsession,
    /** Another participant is sharing their zoom docs. */
    ZNCannotShareReasonType_Other_DOCS_Sharing,
    /** Other or myself is sharing docs, and can grab. To grab, call EnableGrabShareWithoutReminder(true) before starting share. */
    ZNCannotShareReasonType_Need_Grab_DOCS_Sharing,
    /** UnKnown reason. */
    ZNCannotShareReasonType_UnKnown,
};

/**
 * @brief Whiteboard who can share setting type.
 */
typedef enum
{
	/** Only the host can share a whiteboard. */
	ZNSDKWhiteboardShareOption_HostShare,
	/** Anyone can share a whiteboard, but only one can share at a time, and only the host can take another's sharing role. */
	ZNSDKWhiteboardShareOption_HostGrabShare,
	/** Anyone can share a whiteboard, but only one can share at a time, and anyone can take another's sharing role. */
	ZNSDKWhiteboardShareOption_AllGrabShare
}ZNSDKWhiteboardShareOption;

/**
 * @brief Whiteboard who can initiate new whiteboard setting type.
 */
typedef enum
{
	/** Only the host can initiate a new whiteboard. */
	ZNSDKWhiteboardCreateOption_HostOnly,
	/** Users under the same account as the meeting owner can initiate a new whiteboard. */
	ZNSDKWhiteboardCreateOption_AccountUsers,
	/** All participants can initiate a new whiteboard. */
	ZNSDKWhiteboardCreateOption_All
}ZNSDKWhiteboardCreateOption;

/**
 * @brief Status of whiteboard.
 */
typedef enum
{
	/** User started sharing their whiteboard. */
	ZNSDKWhiteboardStatus_Started,
	/** User stopped sharing their whiteboard. */
	ZNSDKWhiteboardStatus_Stopped,
}ZNSDKWhiteboardStatus;

/**
 * @brief Docs share status.
 */
typedef enum
{
    ZNSDKDocsStatus_None, 
    /** User starts sharing docs. */
    ZNSDKDocsStatus_Start,
    /** User stops sharing docs. */
    ZNSDKDocsStatus_Stop
}ZNSDKDocsStatus;

/**
 * @brief Docs share option.
 */
typedef enum
{
    /** A wrong option, such as the meeting not supporting docs. */
    ZNSDKDocsShareOption_None,
    /** Only host can share docs. */
    ZNSDKDocsShareOption_HostShare,
    /** Anyone can share docs, but only one doc can be shared at a time, and only host can take over another's sharing. */
    ZNSDKDocsShareOption_HostGrabShare,
    /** Anyone can share docs, but only one doc can be shared at a time, and anyone can take over another's sharing. */
    ZNSDKDocsShareOption_AllGrabShare
}ZNSDKDocsShareOption;

/**
 * @brief Docs create option.
 */
typedef enum
{
    /** A wrong option, maybe the meeting does not support docs. */
    ZNSDKDocsCreateOption_None,
    /** Only the host can initiate new docs. */
    ZNSDKDocsCreateOption_HostOnly,
    /** Users under the same account can initiate new docs. */
    ZNSDKDocsCreateOption_AccountUsers,
    /** All participants can initiate new docs. */
    ZNSDKDocsCreateOption_All
}ZNSDKDocsCreateOption;

/**
 * @brief Share source info of Zoom docs.
 */
typedef struct _ZNZoomSDKDocSharingSourceInfo
{
	/** The status of Zoom docs sharing. */
	ZNSDKDocsStatus status;
	/** The title of the sharing Zoom docs. */
	ZoomSTRING docTitle;
	/** The share source id of the sharing Zoom docs. */
	unsigned int shareSourceID;
	/** The user id who is sharing Zoom docs. */
	unsigned int userID;
}ZNZoomSDKDocSharingSourceInfo;

////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ZNList std::vector
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
#if (defined BUILD_WIN)
#define JS_WRAP
//#define UserInterfaceClass
#endif
