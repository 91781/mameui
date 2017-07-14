// For licensing and usage information, read docs/winui_license.txt
//****************************************************************************

#ifndef WINUI_H
#define WINUI_H

#include <commctrl.h>
#include <commdlg.h>
#include "emu.h"
#include "pool.h"
#include "screenshot.h"
#include "drivenum.h"

// Make sure all MESS features are included
#define MESS

#define MAMENAME "MAME"
#define UI_INI_FILENAME "MAMEUI.ini"

#ifdef PTR64
#define MAMEUINAME MAMENAME "UI64"
#else
#define MAMEUINAME MAMENAME "UI32"
#endif

#define SEARCH_PROMPT ""
#define SHOW_COLUMN_ROMS
#define SHOW_COLUMN_SAMPLES

enum
{
	UNKNOWN = -1,
	TAB_PICKER = 0,
	TAB_DISPLAY,
	TAB_MISC,
	NUM_TABS
};

enum
{
	FILETYPE_INPUT_FILES = 1,
	FILETYPE_SAVESTATE_FILES,
	FILETYPE_WAVE_FILES,
	FILETYPE_AVI_FILES,
	FILETYPE_MNG_FILES,
	FILETYPE_EFFECT_FILES,
	FILETYPE_JOYMAP_FILES,
	FILETYPE_DEBUGSCRIPT_FILES,
	FILETYPE_CHEAT_FILE,
	FILETYPE_HISTORY_FILE,
	FILETYPE_MAMEINFO_FILE
};


typedef struct
{
	INT resource;
	const char *icon_name;
} ICONDATA;

struct _driverw
{
	WCHAR *name;
	WCHAR *description;
	WCHAR *modify_the;
	WCHAR *manufacturer;
	WCHAR *year;
	WCHAR *source_file;
};
extern struct _driverw **driversw;

extern TCHAR last_directory[MAX_PATH];

typedef BOOL (WINAPI *common_file_dialog_proc)(LPOPENFILENAME lpofn);
BOOL CommonFileDialog(common_file_dialog_proc cfd, WCHAR *filename, int filetype);

HWND GetMainWindow(void);
HWND GetTreeView(void);
HIMAGELIST GetLargeImageList(void);
HIMAGELIST GetSmallImageList(void);
void SetNumOptionFolders(int count);
void GetRealColumnOrder(int order[]);
HICON LoadIconFromFile(const char *iconname);
void UpdateScreenShot(void);
void ResizePickerControls(HWND hWnd);
void MamePlayGame(void);
int FindIconIndex(int nIconResource);
int FindIconIndexByName(const char *icon_name);
int GetSelectedPick(void);
object_pool *GetMameUIMemoryPool(void);

void UpdateListView(void);

// Move The in "The Title (notes)" to "Title, The (notes)"
char * ModifyThe(const char *str);

// Convert Ampersand so it can display in a static control
LPTSTR ConvertAmpersandString(LPCTSTR s);

// globalized for painting tree control
HBITMAP GetBackgroundBitmap(void);
HPALETTE GetBackgroundPalette(void);
MYBITMAPINFO* GetBackgroundInfo(void);
BOOL GetUseOldControl(void);
BOOL GetUseXPControl(void);

int GetMinimumScreenShotWindowWidth(void);

// we maintain an array of drivers sorted by name, useful all around
int GetParentIndex(const game_driver *driver);
int GetCompatIndex(const game_driver *driver);
int GetParentRomSetIndex(const game_driver *driver);
int GetGameNameIndex(const char *name);

// sets text in part of the status bar on the main window
void SetStatusBarText(int part_index, const WCHAR *message);
void SetStatusBarTextF(int part_index, const WCHAR *fmt, ...);

int MameUIMain(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow);

BOOL MouseHasBeenMoved(void);

const char * GetSearchText(void);

//mamep
#include "translate.h"
#define UI_MSG_UI	5//UI_MSG_OSD1
#define UI_MSG_EXTRA	6//UI_MSG_OSD2

#ifndef MAME_DEBUG
#undef _
#endif
#undef _LST
#undef _READINGS
#undef _MANUFACT
#undef _WINDOWS
#undef _UI

#define _W(str)		w_lang_message(UI_MSG_MAME, str)
#define _LSTW(str)	w_lang_message(UI_MSG_LIST, str)
#define _READINGSW(str)	w_lang_message(UI_MSG_READINGS, str)
#define _MANUFACTW(str)	w_lang_message(UI_MSG_MANUFACTURE, str)
#define _WINDOWSW(str)	w_lang_message(UI_MSG_OSD0, str)
#define _UIW(str)	w_lang_message(UI_MSG_UI, str)

#endif
