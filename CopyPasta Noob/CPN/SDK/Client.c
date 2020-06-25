#include "Client.h"
#include "../Base/Interfaces/Interfaces.h"
#include "Utils.h"

struct ClientClass* Client_getAllClasses(VOID)
{
    return CALL_VIRTUAL_METHOD(struct ClientClass*(__fastcall*)(PVOID, PVOID), interfaces.client, 8);
}
