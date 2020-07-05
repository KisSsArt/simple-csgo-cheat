#include <Windows.h>

#include "Hooks/Hooks.h"

extern "C" BOOL WINAPI _CRT_INIT(HMODULE module, DWORD reason, LPVOID reserved);

BOOL APIENTRY DllEntryPoint(HMODULE module, DWORD reason, LPVOID reserved)
{

#ifdef _DEBUG
    AllocConsole();
    SetConsoleTitleA("CPN Console");
#endif

    if (!_CRT_INIT(module, reason, reserved))
        return FALSE;

    if (reason == DLL_PROCESS_ATTACH)
        hooks = std::make_unique<Hooks>(module);

    return TRUE;
}
