#include "SolidHelpAboutCommand.h"
#include "SolidDesignerCommands.h"
#include "AliceIOperation.h"
#include "AliceIMainWindow.h"
#include "AliceIDocumentManager.h"
#include "AliceCommandParameter.h"

using namespace sdr;
using namespace alice;

sdr::SolidHelpAboutCommand::SolidHelpAboutCommand() noexcept
{

}

sdr::SolidHelpAboutCommand::~SolidHelpAboutCommand()
{

}

const std::string_view& sdr::SolidHelpAboutCommand::Id() const noexcept
{
	return Cmd::HELP_ABOUT;
}

bool sdr::SolidHelpAboutCommand::IsSupported() const
{
	return false;
}

bool sdr::SolidHelpAboutCommand::IsVisible() const
{
	return false;
}

bool sdr::SolidHelpAboutCommand::IsEnabled() const
{
	return false;
}

std::string sdr::SolidHelpAboutCommand::DisabledReason() const
{
	return {};
}

std::unique_ptr<alice::IOperation> sdr::SolidHelpAboutCommand::Execute(const alice::CommandParameter& param)
{
	return nullptr;
}
