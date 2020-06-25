#include <Windows.h>

#include "../Base/Config/Config.h"
#include "../Base/Hooks/Hooks.h"
#include "../Base/Interfaces/Interfaces.h"
#include "Memory.h"
#include "../Base/Netvars/Netvars.h"

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        Config_init("CopyPastaNoobs");
        Interfaces_init();
        Memory_init();
        Hooks_init();
    }
    return TRUE;
}
