/**
 * @file multiselect_dropdown.h
 * @brief Multi-select dropdown control.
 */

#pragma once

#include <set>
#include <string>
#include <vector>

#include "view.h"
#include "zui_data_define.h"
#include "dropdown.h"

namespace zui
{
	/**
	 * @class MultiSelectDropdown
	 * @brief A dropdown that allows selecting multiple options simultaneously.
	 *
	 * Each option is rendered with a checkbox; the set of currently checked
	 * indices is exposed via a caller-owned @ref Bind.
	 *
	 * @example
	 * @code
	 * Bind<std::set<int>> selected({0, 2});
	 * Bind<std::vector<std::string>> options({"News", "Sports", "Tech", "Travel"});
	 * MultiSelectDropdown()
	 *   .label("Categories")
	 *   .option(options)
	 *   .selectedIndices(selected)
	 *   .size(Dropdown::Size::kMedium);
	 * @endcode
	 */
	class ZUI_API MultiSelectDropdown : public View
	{
	public:
		MultiSelectDropdown();

		virtual ~MultiSelectDropdown() = default;

		MultiSelectDropdown& label(const Bind<std::string>& label);

		MultiSelectDropdown& unselectedTip(const Bind<std::string>& tip);

		MultiSelectDropdown& option(const Bind<std::vector<std::string>>& options);

		MultiSelectDropdown& size(const Dropdown::Size& size);

		/**
		 * @brief Sets the bound set of selected option indices.
		 *
		 * The bound set is the source of truth for which options are checked.
		 * Out-of-range indices are ignored. The caller owns the bound value's
		 * lifetime.
		 */
		MultiSelectDropdown& selectedIndices(const Bind<std::set<int>>& indices);

		MultiSelectDropdown& fullDisplay();

		MultiSelectDropdown& disableFullDisplay();
	};

namespace p
{
	class ZUI_API multiSelectDropdownLabel : public PipeModifier
	{
	public:
		explicit multiSelectDropdownLabel(const Bind<std::string>& label);
		~multiSelectDropdownLabel();
	protected:
		void apply(View& v) const override;
	private:
		class Impl;
		Impl* _pImpl;
	};

	class ZUI_API multiSelectDropdownUnselectedTip : public PipeModifier
	{
	public:
		explicit multiSelectDropdownUnselectedTip(const Bind<std::string>& tip);
		~multiSelectDropdownUnselectedTip();
	protected:
		void apply(View& v) const override;
	private:
		class Impl;
		Impl* _pImpl;
	};

	class ZUI_API multiSelectDropdownOption : public PipeModifier
	{
	public:
		explicit multiSelectDropdownOption(const Bind<std::vector<std::string>>& options);
		~multiSelectDropdownOption();
	protected:
		void apply(View& v) const override;
	private:
		class Impl;
		Impl* _pImpl;
	};

	class ZUI_API multiSelectDropdownSize : public PipeModifier
	{
	public:
		explicit multiSelectDropdownSize(const Dropdown::Size& size);
		~multiSelectDropdownSize();
	protected:
		void apply(View& v) const override;
	private:
		class Impl;
		Impl* _pImpl;
	};

	class ZUI_API multiSelectDropdownSelectedIndices : public PipeModifier
	{
	public:
		explicit multiSelectDropdownSelectedIndices(const Bind<std::set<int>>& indices);
		~multiSelectDropdownSelectedIndices();
	protected:
		void apply(View& v) const override;
	private:
		class Impl;
		Impl* _pImpl;
	};

	class ZUI_API multiSelectDropdownFullDisplay : public PipeModifier
	{
	public:
		multiSelectDropdownFullDisplay();
		~multiSelectDropdownFullDisplay();
	protected:
		void apply(View& v) const override;
	private:
		class Impl;
		Impl* _pImpl;
	};

	class ZUI_API multiSelectDropdownDisableFullDisplay : public PipeModifier
	{
	public:
		multiSelectDropdownDisableFullDisplay();
		~multiSelectDropdownDisableFullDisplay();
	protected:
		void apply(View& v) const override;
	private:
		class Impl;
		Impl* _pImpl;
	};

	namespace discover {
		namespace by_view {
			namespace multi_select_dropdown {
				using zui::p::multiSelectDropdownLabel;
				using zui::p::multiSelectDropdownUnselectedTip;
				using zui::p::multiSelectDropdownOption;
				using zui::p::multiSelectDropdownSize;
				using zui::p::multiSelectDropdownSelectedIndices;
				using zui::p::multiSelectDropdownFullDisplay;
				using zui::p::multiSelectDropdownDisableFullDisplay;
			}
		}
	}

} // namespace p

} // namespace zui
