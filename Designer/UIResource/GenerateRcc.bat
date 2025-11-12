@echo off
setlocal EnableExtensions EnableDelayedExpansion

rem 定位到脚本目录
cd /d "%~dp0"

rem rcc 路径（可改成你的固定路径）
if not defined QTDIR_X64 (
  echo [ERR] QTDIR_X64 not set
  exit /b 1
)
set "rcc=%QTDIR_X64%\bin\rcc.exe"
echo rcc="%rcc%"

rem 输出目录参数，默认使用脚本旁的 out
set "OUTDIR=%~1"
if not defined OUTDIR set "OUTDIR=%~dp0out"
if not exist "%OUTDIR%" (
  md "%OUTDIR%"
  echo mkdir "%OUTDIR%"
)
echo OUTDIR="%OUTDIR%"

rem 收集所有 .qrc（以当前目录为根递归）
set "resources="
for /r "%~dp0" %%F in (*.qrc) do (
  set "resources=!resources! "%%F""
)

if not defined resources (
  echo [ERR] no .qrc found under "%~dp0"
  exit /b 2
)

echo resources=!resources!

rem 生成合并后的 rcc
set "RCC_OUT=%OUTDIR%\SolidDesignerRes.rcc"
"%rcc%" -binary !resources! -o "%RCC_OUT%"
if errorlevel 1 (
  echo [ERR] rcc failed
  exit /b 3
)

echo [OK] generated "%RCC_OUT%"
endlocal
@echo on
