#include "SolidEditUndoCommand.h"
#include "SolidDesignerCommands.h"
#include "AliceIOperation.h"

using namespace sdr;
using namespace alice;

sdr::SolidEditUndoCommand::SolidEditUndoCommand() noexcept
{

}

sdr::SolidEditUndoCommand::~SolidEditUndoCommand()
{

}

const std::string_view& sdr::SolidEditUndoCommand::Id() const noexcept
{
	return Cmd::EDIT_UNDO;
}

bool SolidEditUndoCommand::IsSupported() const
{
	return false;
}

bool SolidEditUndoCommand::IsVisible() const
{
	return false;
}

bool SolidEditUndoCommand::IsEnabled() const
{
	return false;
}

std::string SolidEditUndoCommand::DisabledReason() const
{
	return {};
}

std::unique_ptr<alice::IOperation> SolidEditUndoCommand::Execute(const alice::CommandParameter& param)
{
	return nullptr;
}