#include <windows.h>
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")
#include <filesystem>

int main(int, char**) 
{
    const auto ghidra_env_path = R"(%USERPROFILE%\AppData\Local\Programs\Ghidra\ghidraRun.bat)";
    CHAR ghidra_path[MAX_PATH + 1]{0};
    ExpandEnvironmentStringsA(ghidra_env_path, ghidra_path, sizeof(ghidra_path) - 1);
    SHELLEXECUTEINFOA si{
        sizeof(si),
        0, 
        HWND_DESKTOP,
        "Open",
        ghidra_path, 
        NULL,
        NULL,
        SW_SHOWNORMAL 
    };
    return ShellExecuteExA(&si);
}