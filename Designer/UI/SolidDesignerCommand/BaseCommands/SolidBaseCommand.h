#pragma once
#include "AliceICommand.h"
#include <string>
#include <memory>

namespace alice
{
	struct CommandParameter;
	class IOperation;
}

namespace sdr
{
	/// \brief Base class for all SolidDesigner UI commands.
	///
	/// Responsibilities:
	///   - Provide a stable string identifier (Id) for the command.
	///   - Define default behavior for common query functions
	///     (IsSupported / IsVisible / IsEnabled / IsChecked / DisabledReason).
	///   - Provide a virtual Execute entry that derived classes must override.
	///
	/// This class does not embed any UI objects or application services.
	/// Those are expected to be injected and stored by more specialized
	/// derived bases (e.g. DocumentCommandBase, FileCommandBase, etc.).
	class AppCommandBase : public alice::ICommand
	{
	public:
		/// \brief Default constructor.
		///
		/// Derived classes are expected to call SetId() in their own
		/// constructors if this constructor is used.
		AppCommandBase() noexcept;

		/// \brief Construct with a fixed command identifier.
		///
		/// \param id Stable string identifier (e.g. "file.new").
		explicit AppCommandBase(std::string id) noexcept;

		/// \brief Virtual destructor.
		virtual ~AppCommandBase();

		/// \brief Return the stable command identifier.
		///
		/// The returned reference is valid for the lifetime of the command
		/// instance. If no id was set, an empty string is returned.
		const std::string_view& Id() const noexcept override;

		/// \brief Whether the command is supported in the current environment.
		///
		/// Default implementation returns true. Derived classes should
		/// override this when the command depends on more specific context
		/// (current workbench, license level, platform, etc.).
		bool IsSupported() const override;

		/// \brief Whether the command should be visible.
		///
		/// Default implementation returns IsSupported(). If a command should
		/// remain hidden even when supported, override this method.
		bool IsVisible() const override;

		/// \brief Whether the command is currently enabled (clickable).
		///
		/// Default implementation returns IsSupported(). Derived classes
		/// usually override this to depend on the active document, selection
		/// state, or other runtime conditions.
		bool IsEnabled() const override;

		/// \brief Whether the command is in "checked" state (for toggle buttons).
		///
		/// Default implementation returns false, treating the command as a
		/// non-toggle command. Toggle-style commands should override this.
		bool IsChecked() const override;

		/// \brief If the command is disabled, provide a short reason string.
		///
		/// Default implementation returns an empty string, indicating that
		/// no specific reason is provided. Derived classes may return a
		/// localized explanation for use in status bar or tooltips.
		std::string DisabledReason() const override;

		/// \brief Execute the command.
		///
		/// Default implementation does nothing and returns nullptr.
		/// Real commands *must* override this method and either:
		///   - create and return an IOperation for undo/redo, or
		///   - return nullptr if the command is not undoable.
		std::unique_ptr<alice::IOperation> Execute(const alice::CommandParameter& pCmdParam) override;

	protected:
		/// \brief Set the stable identifier of this command.
		///
		/// This helper is intended to be called from derived class
		/// constructors when using the default AppCommandBase() constructor.
		///
		/// \param id New identifier string to store.
		void SetId(std::string id) noexcept;

	private:
		/// \brief Stable string identifier for this command.
		///
		/// Examples: "file.new", "file.open", "view.fitAll".
		std::string m_id;
	};

} // namespace sdr
