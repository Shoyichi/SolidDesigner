#include "SolidHelpContentsCommand.h"
#include "SolidDesignerCommands.h"
#include "AliceIOperation.h"
#include "AliceCommandParameter.h"
#include "AliceIDocumentManager.h"
#include "AliceIMainWindow.h"

using namespace alice;
using namespace sdr;

sdr::SolidHelpContentsCommand::SolidHelpContentsCommand() noexcept
{

}

SolidHelpContentsCommand::~SolidHelpContentsCommand()
{

}

const std::string_view& SolidHelpContentsCommand::Id() const noexcept
{
	return sdr::Cmd::CMD_HELP_CONTENTS;
}

bool SolidHelpContentsCommand::IsSupported() const
{
	return false;
}

bool SolidHelpContentsCommand::IsEnabled() const
{
	return false;
}

bool SolidHelpContentsCommand::IsVisible() const
{
	return false;
}

std::string SolidHelpContentsCommand::DisabledReason() const
{
	return {};
}

std::unique_ptr<alice::IOperation> SolidHelpContentsCommand::Execute(const alice::CommandParameter& param)
{
	return nullptr;
}