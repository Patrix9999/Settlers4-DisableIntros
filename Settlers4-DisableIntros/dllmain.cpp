#include "stdafx.h"

DWORD& playVideos = *(DWORD*)0x007B8E28;

bool GameStateHandlerInit();
HOOK Ivk_GameStateHandlerInit AS(0x004EADF0, GameStateHandlerInit);
bool GameStateHandlerInit()
{
	Ivk_GameStateHandlerInit.Detach();

	// disable movies playing
	playVideos = FALSE;
	bool result = Ivk_GameStateHandlerInit();

	return result;
}

VOID WINAPI onDllAttach(HMODULE hModule)
{
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

