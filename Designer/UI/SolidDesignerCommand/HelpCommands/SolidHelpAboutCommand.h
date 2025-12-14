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
	class SolidHelpAboutCommand final : public AppCommandBase
	{
	public:
		SolidHelpAboutCommand() noexcept;

		~SolidHelpAboutCommand() override;

		const std::string_view& Id() const noexcept override;

		bool IsSupported() const override;
		bool IsVisible() const override;
		bool IsEnabled() const override;
		std::string DisabledReason() const override;

		std::unique_ptr<alice::IOperation> Execute(const alice::CommandParameter& param) override;
	};

} // namespace sdr