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
	class SolidFileSaveCommand final : public AppCommandBase
	{
	public:
		SolidFileSaveCommand() noexcept;

		~SolidFileSaveCommand() override = default;

		const std::string_view& Id() const noexcept override;

		bool IsSupported() const override;
		bool IsVisible() const override;
		bool IsEnabled() const override;
		std::string DisabledReason() const override;

		std::unique_ptr<alice::IOperation> Execute(const alice::CommandParameter& param) override;

	private:
		alice::IDocument* getActiveDocument_() const;
		bool              hasFilePath_(alice::IDocument& doc) const;
		std::wstring      getFilePath_(alice::IDocument& doc) const;
		std::wstring      showSaveAsDialog_(const std::wstring& hintPath) const;
		bool              saveDocument_(alice::IDocument& doc, const std::wstring& path, bool isSaveAs) const;
	};

} // namespace sdr
