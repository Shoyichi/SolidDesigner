#include "SolidFileNewCommand.h"
#include "AliceIOperation.h"
#include "SolidDesignerCommands.h"
#include "AliceIDocumentManager.h"
#include "AliceIMainWindow.h"
#include "AliceCommandParameter.h"

using namespace alice;
using namespace sdr;

SolidFileNewCommand::~SolidFileNewCommand()
{

}

SolidFileNewCommand::SolidFileNewCommand() noexcept
{

}

const std::string_view& sdr::SolidFileNewCommand::Id() const noexcept
{
	return sdr::Cmd::FILE_NEW;
}

std::string SolidFileNewCommand::DisabledReason() const
{
	return std::string();
}

bool SolidFileNewCommand::IsEnabled() const
{
	return true;
}

bool SolidFileNewCommand::IsVisible() const
{
	return true;
}

bool SolidFileNewCommand::IsSupported() const
{
	return true;
}

std::unique_ptr<alice::IOperation> SolidFileNewCommand::Execute(const alice::CommandParameter& param)
{
	return nullptr;
}
