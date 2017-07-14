// For licensing and usage information, read docs/winui_license.txt
//****************************************************************************
#ifndef WINUI
#define WINUI
#endif

// import the main() from MAME, but rename it so we can call it indirectly
#undef main
#undef wmain
#define main mame_main
#define wmain mame_main
#include "windows/main.cpp"
#undef main
#undef wmain

#include "winui.h"


int WINAPI wWinMain(HINSTANCE    hInstance,
                   HINSTANCE    hPrevInstance,
                   LPWSTR       lpCmdLine,
                   int          nCmdShow)
{
	int nRet = 0;
//#ifdef _DEBUG
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
//#endif

	printf("--------------------------Console created for log!!!--------------------------\n");
	printf("osd_messui-->mui_main.cpp-->wWinMain\n");
	nRet = MameUIMain(hInstance, lpCmdLine, nCmdShow);

//#ifdef _DEBUG
	FreeConsole();
//#endif
	return nRet;
}
