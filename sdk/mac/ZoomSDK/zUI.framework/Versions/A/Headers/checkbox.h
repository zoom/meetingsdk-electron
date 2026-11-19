/**
 * @file checkbox.h
 * @brief Checkbox control component
 * 
 * Provides checkbox functionality for multi-selection and boolean states.
 */

#pragma once

#include <memory>
#include "view.h"
#include "text.h"
#include "zui_data_define.h"

namespace zui
{
	/**
	 * @class Checkbox
	 * @brief A view component that allows users to select one or more items from a set.
	 * @ingroup controls_input
	 * 
	 * The Checkbox component is used to represent boolean states in the interface. It supports:
	 * - Multiple states (unselected, selected, indeterminate)
	 * - Custom labels
	 * - Interactive events
	 * 
	 * @example
	 * @code
	 * // Basic checkbox with label
	 * Checkbox("Accept terms")
	 *   .status(Checkbox::Status::kSelected);
	 * 
	 * // Checkbox with indeterminate state
	 * Checkbox("Select all")
	 *   .status(Checkbox::Status::kIndeterminate);
	 * @endcode
	 */
	class ZUI_API Checkbox
		: public View
	{
	public:
		/**
		 * @enum Status
		 * @brief Defines the possible states of a Checkbox
		 */
		enum class Status
		{
			kUnselected,    ///< Checkbox is not selected
			kSelected,      ///< Checkbox is selected
			kIndeterminate  ///< Checkbox is in an indeterminate state
		};

		/**
		 * @brief Constructs a new Checkbox object with the given label
		 * @param label The text label that describes the checkbox
		 */
		explicit Checkbox(const Bind<std::string>& label);

		/// @brief Virtual destructor
		virtual ~Checkbox() = default;

		/**
		 * @brief Sets the status of the checkbox
		 * @param status The desired status of the checkbox
		 * @return Reference to this checkbox for method chaining
		 */
		Checkbox& status(const Bind<Checkbox::Status>& status);
	};

namespace p
{

  class ZUI_API checkboxStatus : public PipeModifier
  {
  public:
    explicit checkboxStatus(const Bind<Checkbox::Status>& status);
    ~checkboxStatus();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace checkbox {
        using zui::p::checkboxStatus;
      }
    }
  }

} // namespace p

}
