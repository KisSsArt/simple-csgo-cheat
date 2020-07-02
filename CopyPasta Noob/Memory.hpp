#pragma once

#include <d3dx9.h>
#include <d3d9.h>

#pragma comment (lib, "d3dx9")  // link D3DX DLL

#include "core/features/features.hpp"
#include "hazedumper.hpp"

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

	//pDevice ptr : shaderapidx9.dll + 0x1B6E88
	static uintptr_t d3dBase() {
		return (uintptr_t)GetModuleHandle(TEXT("shaderapidx9.dll"));
	}

	static LPDIRECT3DDEVICE9 pDevice() {
		return Memory::Read<LPDIRECT3DDEVICE9>(d3dBase() + dwppDirect3DDevice9);
	}
};