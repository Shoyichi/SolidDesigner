// SolidFileNewCommand.h
#pragma once
#include "BaseCommands/SolidBaseCommand.h" 
#include <memory>
#include <string>

namespace alice
{
	class IMainWindow;
	class IDocumentManager;
	struct CommandParameter;
	class IOperation;
}

namespace sdr
{
	class SolidFileNewCommand final : public AppCommandBase
	{
	public:
		SolidFileNewCommand() noexcept;

		~SolidFileNewCommand() override;

		/// \brief Logical command id, must match CommandsConfig.xml: id="file.new"
		const std::string_view& Id() const noexcept override;

		bool IsSupported() const override;
		bool IsVisible() const override;
		bool IsEnabled() const override;
		std::string DisabledReason() const override;

		std::unique_ptr<alice::IOperation> Execute(const alice::CommandParameter& param) override;
	};

} // namespace sdr
