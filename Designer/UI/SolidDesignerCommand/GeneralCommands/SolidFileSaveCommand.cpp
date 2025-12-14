#include "SolidFileSaveCommand.h"

#include "AliceIMainWindow.h"
#include "AliceIDocumentManager.h"
#include "AliceIDocument.h"
#include "AliceCommandParameter.h"
#include "AliceIOperation.h"
#include "SolidDesignerCommands.h"

using namespace alice;
using namespace sdr;

SolidFileSaveCommand::SolidFileSaveCommand() noexcept
{
}

const std::string_view& SolidFileSaveCommand::Id() const noexcept
{
	return sdr::Cmd::FILE_SAVE;
}

bool SolidFileSaveCommand::IsSupported() const
{
	//return (m_mainWindow != nullptr) && (m_docManager != nullptr);
	return false;
}

bool SolidFileSaveCommand::IsVisible() const
{
	return IsSupported();
}

bool SolidFileSaveCommand::IsEnabled() const
{
	if (!IsSupported())
		return false;

	IDocument* doc = getActiveDocument_();
	return (doc != nullptr);
}

std::string SolidFileSaveCommand::DisabledReason() const
{
	//if (!m_mainWindow)
	//	return "Main window is not available.";

	//if (!m_docManager)
	//	return "Document manager is not available.";

	if (!getActiveDocument_())
		return "There is no active document to save.";

	return {};
}

std::unique_ptr<IOperation> SolidFileSaveCommand::Execute(const CommandParameter& param)
{
	if (!IsEnabled())
		return nullptr;

	IDocument* doc = getActiveDocument_();
	if (!doc)
		return nullptr;

	std::wstring path;
	bool         isSaveAs = false;

	if (hasFilePath_(*doc)) {
		// 已有路径：直接保存
		path = getFilePath_(*doc);
		isSaveAs = false;
	}
	else 
	{
		path = showSaveAsDialog_(L"");
		if (path.empty())
			return nullptr; 
		isSaveAs = true;
	}

	const bool ok = saveDocument_(*doc, path, isSaveAs);
	if (!ok)
	{

	}

	// 保存文件通常不进 Undo/Redo
	return nullptr;
}

IDocument* SolidFileSaveCommand::getActiveDocument_() const
{
	//if (!m_docManager)
	//	return nullptr;

	//return m_docManager->GetActiveDocument(); 
	return false;
}

bool SolidFileSaveCommand::hasFilePath_(IDocument& doc) const
{
	//return doc.HasFilePath();
	return false;
}

std::wstring SolidFileSaveCommand::getFilePath_(IDocument& doc) const
{
	//return doc.GetFilePath();
	return std::wstring();
}

std::wstring SolidFileSaveCommand::showSaveAsDialog_(const std::wstring& hintPath) const
{
	//QWidget* parent = m_mainWindow ? m_mainWindow->AsQMainWindow() : nullptr;

	//QString dir;
	//QString suggested;

	//if (!hintPath.empty()) {
	//	const QString qpath = QString::fromStdWString(hintPath);
	//	QFileInfo fi(qpath);
	//	dir = fi.absolutePath();
	//	suggested = fi.fileName();
	//}

	//const QString filter = QObject::tr("Alice Documents (*.alice);;" "All Files (*.*)");

	//const QString file = QFileDialog::getSaveFileName(parent, QObject::tr("Save File"),
	//		dir.isEmpty() ? suggested : dir + QLatin1Char('/') + suggested,
	//		filter);

	//if (file.isEmpty())
	//	return {};

	//return file.toStdWString();
	return std::wstring();
}

bool SolidFileSaveCommand::saveDocument_(IDocument& doc, const std::wstring& path, bool isSaveAs) const
{
	//if (!m_docManager)
	//	return false;

	//if (isSaveAs)
	//{
	//	return m_docManager->SaveAs(doc, path);   // TODO: 对齐你的 API
	//}
	//else 
	//{
	//	return m_docManager->Save(doc);
	//}
	return false;
}
