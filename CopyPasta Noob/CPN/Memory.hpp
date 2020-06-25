//#include "core/features/features.hpp"
#include "hazedumper.hpp"
#include <libloaderapi.h>

using namespace hazedumper::signatures;
using namespace hazedumper::netvars;

class Memory
{
public:
	template <class cData>
	static void Write(uintptr_t Address, cData Value)
	{
		*(cData*)(Address) = Value;
	}

	template <class cData>
	static cData Read(uintptr_t Address)
	{
		return *(cData*)(Address);
	}

	static uintptr_t clientBase() {
		return (uintptr_t)GetModuleHandle(TEXT("client.dll"));
	}

	static uintptr_t engineBase() {
		return (uintptr_t)GetModuleHandle(TEXT("engine.dll"));
	}
};