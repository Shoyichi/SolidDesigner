#include "AliceIAppLauncher.h"
#include "AliceDiagnosticMacro.h"

using namespace alice;

int main(int argc, char *argv[])
{
    OwningPtr<IAppLauncher> opLauncher = IAppLauncher::Create();
    DIAG_RETURN_IF_FALSE(opLauncher, 0, "", "hananiah", "2025.11.1");
    opLauncher->SetAppConfigFile(L"");
    opLauncher->SetUiAppConfigFile(L"UiApplicationConfig.xml");
    int nResult = opLauncher->Run(argc, argv);
    return nResult;
}