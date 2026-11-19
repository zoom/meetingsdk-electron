/**
 * @file video_player.h
 * @brief VideoPlayer component for playing video files
 * 
 * Provides video playback functionality with basic controls.
 */

#pragma once

#include <memory>
#include "view.h"
#include "zui_data_define.h"

namespace zui
{
  enum class VideoPlayerState : int
  {
    kUnknown = -1,
    kPlaying,
    kPaused,
    kStopped,
    kPlaybackEnded,
  };

  /**
   * @class VideoPlayer
   * @brief A view component for playing video files.
   * @ingroup controls_media
   * 
   * The VideoPlayer component provides functionality for video playback.
   * It supports:
   * - Video file loading from paths
   * - Volume control
   * - Playback state management
   * - Auto-replay configuration
   * 
   * @example
   * @code
   * VideoPlayer(videoPathBinding)
   *   .width(640)
   *   .height(480)
   *   .volume(1.0);
   * @endcode
   */
  class ZUI_API VideoPlayer : public View
  {
  public:

    /**
     * @brief Constructs a VideoPlayer with the specified video path
     * @param videoPath The path to the video file to play
     */
    explicit VideoPlayer(const Bind<std::string>& videoPath);

    virtual ~VideoPlayer() = default;

    /**
     * @brief Sets the volume level of the video player
     * @param volume The volume level (0.0 = mute, 1.0 = full volume)
     * @return Reference to this video player for method chaining
     */
    VideoPlayer& volume(const Bind<float>& volume);

    /**
     * @brief Sets whether the video should automatically replay
     * @param autoReplay True to enable auto-replay, false to disable
     * @return Reference to this video player for method chaining
     */
    VideoPlayer& autoReplay(const Bind<bool>& autoReplay);

    /**
     * @brief Controls the playing state of the video (declarative)
     * @param play Bind variable controlling play/pause state
     *        - true: video plays
     *        - false: video pauses
     * @return Reference to this video player for method chaining
     * @note This is a declarative binding - when the bound value changes,
     *       the video player automatically plays or pauses
     */
    VideoPlayer& play(const Bind<bool>& play);

    /**
     * @brief Sets the callback for video player state changes
     * @param callback The callback function to invoke when state changes
     * @return Reference to this video player for method chaining
     */
    VideoPlayer& onStateChanged(std::function<void(VideoPlayerState)> callback);
  };

}
