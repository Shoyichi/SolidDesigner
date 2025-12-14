#pragma once

#include "BaseCommands/SolidBaseCommand.h"
#include <memory>
#include <string>

namespace alice
{
	class IMainWindow;
	class IDocument;
	class IDocumentManager;
	struct CommandParameter;
	class IOperation;
}

namespace sdr
{
	class SolidFileOpenCommand final : public AppCommandBase
	{
	public:
		SolidFileOpenCommand() noexcept;

		~SolidFileOpenCommand() override = default;

		const std::string_view& Id() const noexcept override;

		bool IsSupported() const override;
		bool IsVisible() const override;
		bool IsEnabled() const override;
		std::string DisabledReason() const override;

		std::unique_ptr<alice::IOperation> Execute(const alice::CommandParameter& param) override;

	private:
		std::wstring showOpenFileDialog_() const;
		alice::IDocument* openDocument_(const std::wstring& filePath) const;
		//QWidget* openViewForDocument_(alice::IDocument* doc, const std::wstring& filePath) const;
	};

} // namespace sdr
