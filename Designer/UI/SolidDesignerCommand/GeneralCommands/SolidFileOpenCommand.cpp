#include "SolidFileOpenCommand.h"

#include "AliceIMainWindow.h"
#include "AliceIDocumentManager.h"
#include "AliceIDocument.h"
#include "AliceCommandParameter.h"
#include "AliceIOperation.h"
#include "SolidDesignerCommands.h"

using namespace alice;
using namespace sdr;

SolidFileOpenCommand::SolidFileOpenCommand() noexcept
{
}

const std::string_view& SolidFileOpenCommand::Id() const noexcept
{
	return sdr::Cmd::FILE_OPEN;
}

bool SolidFileOpenCommand::IsSupported() const
{
	//return (m_mainWindow != nullptr) && (m_docManager != nullptr);
	return false;
}

bool SolidFileOpenCommand::IsVisible() const
{
	return IsSupported();
}

bool SolidFileOpenCommand::IsEnabled() const
{
	return IsSupported();
}

std::string SolidFileOpenCommand::DisabledReason() const
{
	//if (!m_mainWindow)
	//	return "Main window is not available.";

	//if (!m_docManager)
	//	return "Document manager is not available.";

	return {};
}

std::unique_ptr<IOperation> SolidFileOpenCommand::Execute(const CommandParameter& param)
{
	if (!IsEnabled())
		return nullptr;

	std::wstring filePath = showOpenFileDialog_();
	if (filePath.empty())
		return nullptr; // 用户取消

	IDocument* doc = openDocument_(filePath);
	if (!doc) 
	{
		//if (QWidget* parent = m_mainWindow ? m_mainWindow->AsQMainWindow() : nullptr) {
		//	QMessageBox::critical(parent,
		//		QObject::tr("Open File"),
		//		QObject::tr("Failed to open file."));
		//}
		return nullptr;
	}

	//openViewForDocument_(doc, filePath);

	return nullptr;
}

std::wstring SolidFileOpenCommand::showOpenFileDialog_() const
{
	//QWidget* parent = m_mainWindow ? m_mainWindow->AsQMainWindow() : nullptr;

	//// 过滤可以从 UiApplicationConfig / CommandsConfig 的 profile 中拿，此处给一个
	//// 针对 .alice + 常规 CAD 格式的示例。
	//const QString filter =
	//	QObject::tr("Alice Documents (*.alice);;"
	//		"STEP Files (*.step *.stp);;"
	//		"IGES Files (*.iges *.igs);;"
	//		"All Files (*.*)");

	//const QString file =
	//	QFileDialog::getOpenFileName(parent,
	//		QObject::tr("Open File"),
	//		QString(),  
	//		filter);

	//if (file.isEmpty())
	//	return {};

	//return file.toStdWString();
	return {};
}

IDocument* SolidFileOpenCommand::openDocument_(const std::wstring& filePath) const
{
	//if (!m_docManager)
	//	return nullptr;

	//return m_docManager->OpenFromFile(filePath);
	return nullptr;
}

//QWidget* SolidFileOpenCommand::openViewForDocument_(IDocument* doc,
//	const std::wstring& filePath) const
//{
//	if (!m_mainWindow || !doc)
//		return nullptr;
//
//	const std::string viewKind = "view.default.fromDocKind"; 
//	const QString     title = QString::fromStdWString(filePath);
//
//	QWidget* w = m_mainWindow->OpenView(viewKind, static_cast<void*>(doc), title);
//	return w;
//}
