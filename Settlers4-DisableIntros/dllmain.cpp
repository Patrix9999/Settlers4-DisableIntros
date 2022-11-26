#include "stdafx.h"

DWORD& playLogoVideos = *(DWORD*)0x007B8E28;

VOID WINAPI onDllAttach(HMODULE hModule)
{
	playLogoVideos = FALSE;
}

VOID WINAPI onDllDetach()
{
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls(hModule);
			onDllAttach(hModule);
			break;

		case DLL_PROCESS_DETACH:
			onDllDetach();
			break;
	}

	return TRUE;
}

