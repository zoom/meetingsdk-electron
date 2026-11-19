#pragma once

#include <functional>
#include <memory>
#include <vector>
#include <string>
#include <list>
#include "view.h"
#include "types.h"

namespace zui
{
  class ZUI_API FileUploader : public View
  {
  public:
    enum class Type{
      kBasic,
      kDragAndDrop,
      kSingleFile
    };
  
    FileUploader();
    ~FileUploader() = default;

    FileUploader& type(const Type& type);
    FileUploader& filters(const Bind<std::list<std::string>>& filter);
    FileUploader& limitSize(const Bind<int>& limitSize); //in MB
    FileUploader& text(const Bind<std::string>& text);
    FileUploader& promptText(const Bind<std::string>& promptText);
    FileUploader& onSelect(const std::function<void(const std::string& filePath)>& onSelectFinished);
  };

namespace p
{

  // FileUploader-specific pipe modifiers
  class ZUI_API fileUploaderType : public PipeModifier
  {
  public:
    explicit fileUploaderType(const FileUploader::Type& type);
    ~fileUploaderType();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API fileUploaderFilters : public PipeModifier
  {
  public:
    explicit fileUploaderFilters(const Bind<std::list<std::string>>& filter);
    ~fileUploaderFilters();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API fileUploaderLimitSize : public PipeModifier
  {
  public:
    explicit fileUploaderLimitSize(const Bind<int>& limitSize);
    ~fileUploaderLimitSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API fileUploaderText : public PipeModifier
  {
  public:
    explicit fileUploaderText(const Bind<std::string>& text);
    ~fileUploaderText();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API fileUploaderPromptText : public PipeModifier
  {
  public:
    explicit fileUploaderPromptText(const Bind<std::string>& promptText);
    ~fileUploaderPromptText();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API fileUploaderOnSelect : public PipeModifier
  {
  public:
    explicit fileUploaderOnSelect(const std::function<void(const std::string& filePath)>& onSelectFinished);
    ~fileUploaderOnSelect();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace file_uploader {
        using zui::p::fileUploaderType;
        using zui::p::fileUploaderFilters;
        using zui::p::fileUploaderLimitSize;
        using zui::p::fileUploaderText;
        using zui::p::fileUploaderPromptText;
        using zui::p::fileUploaderOnSelect;
      }
    }
  }

} // namespace p

}
