#include "debug.h"

#ifdef DEBUG_MENU

#include "global.h"
#include "list_menu.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "pokedex.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "task.h"
#include "event_data.h"
#include "credits.h"
#include "constants/flags.h"
#include "constants/songs.h"
#include "constants/species.h"

#define DEBUG_MAIN_MENU_HEIGHT 9
#define DEBUG_MAIN_MENU_WIDTH 13

static void Debug_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate);
void Debug_ShowMainMenu(void);
static void Debug_DestroyMenu(u8);

static void DebugAction_CheckSaveBlock(u8);
static void DebugAction_CheckWallClock(u8);
static void DebugAction_SetWallClock(u8);
static void DebugAction_SetPokedexFlags(u8);
static void DebugAction_SwitchDex(u8);
static void DebugAction_SwitchNatDex(u8);
static void DebugAction_SwitchPokeNav(u8);
static void DebugAction_Credits(u8);
static void DebugAction_Cancel(u8);

static void DebugAction_OpenUtilitiesMenu(u8);
static void DebugAction_OpenFlagsMenu(u8);
static void DebugAction_OpenSub1(u8);
static void DebugTask_HandleMenuInput_Main(u8);
static void DebugTask_HandleMenuInput_Utilities(u8);

extern u8 Debug_CheckSaveBlock[];
extern u8 PlayersHouse_2F_EventScript_SetWallClock[];
extern u8 PlayersHouse_2F_EventScript_CheckWallClock[];
extern u8 Debug_SetPokedexFlags[];

// Main Menu
static const u8 gDebugText_Utilities[] = _("Utilities");
static const u8 gDebugText_Flags[] = _("Flags");
static const u8 gDebugText_Cancel[] = _("Cancel");

static const u8 gDebugText_SaveBlockSpace[] = _("SaveBlock Space");
static const u8 gDebugText_CheckWallClock[] = _("Check Wall Clock");
static const u8 gDebugText_SetWallClock[] = _("Set Wall Clock");
static const u8 gDebugText_WatchCredits[] = _("Watch Credits");

static const u8 gDebugText_SetPokedexFlags[] = _("Set Pokédex Flags");
static const u8 gDebugText_SwitchDex[] = _("Pokédex ON/OFF");
static const u8 gDebugText_SwitchNationalDex[] = _("NatDex ON/OFF");
static const u8 gDebugText_SwitchPokeNav[] = _("PokéNav ON/OFF");

static const u8 gDebugText_None[] = _("None");

// Sub Menu 1
static const u8 gDebugText__Sub1_OptionA[] = _("Option A");

static const struct ListMenuItem sDebugMenu_Items_Main[] =
{
    [0] = {gDebugText_Utilities, 0},
    [1] = {gDebugText_Flags, 1},
    [2] = {gDebugText_Cancel, 6}
};

static const struct ListMenuItem sDebugMenu_Items_Utilities[] =
{
    [0] = {gDebugText_SaveBlockSpace, 0},
    [1] = {gDebugText_CheckWallClock, 1},
    [2] = {gDebugText_SetWallClock, 2},
    [3] = {gDebugText_WatchCredits, 3},
};

static const struct ListMenuItem sDebugMenu_Items_Flags[] =
{
    [0] = {gDebugText_SetPokedexFlags, 0},
    [1] = {gDebugText_SwitchDex, 1},
    [2] = {gDebugText_SwitchNationalDex, 2},
    [3] = {gDebugText_SwitchPokeNav, 3},
};

static const struct ListMenuItem sDebugMenu_Items_Sub1[] =
{
    [0] = {gDebugText__Sub1_OptionA, 0},
    [1] = {gDebugText_Cancel, 1}
};

static void (*const sDebugMenu_Actions_Main[])(u8) =
{
    [0] = DebugAction_OpenUtilitiesMenu,
    [1] = DebugAction_OpenFlagsMenu,
    [3] = DebugAction_Cancel
};

static void (*const sDebugMenu_Actions_SaveBlocks[])(u8) =
{
    [0] = DebugAction_CheckSaveBlock,
    [1] = DebugAction_CheckWallClock,
    [2] = DebugAction_SetWallClock,
    [3] = DebugAction_Credits,
};

static void (*const sDebugMenu_Actions_Flags[])(u8) =
{
    [0] = DebugAction_SetPokedexFlags,
    [1] = DebugAction_SwitchDex,
    [2] = DebugAction_SwitchNatDex,
    [3] = DebugAction_SwitchPokeNav,
};
static const struct WindowTemplate sDebugMenuWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = DEBUG_MAIN_MENU_WIDTH,
    .height = 2 * DEBUG_MAIN_MENU_HEIGHT,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct ListMenuTemplate sDebugMenu_ListTemplate_Main =
{
    .items = sDebugMenu_Items_Main,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sDebugMenu_Items_Main),
};

static const struct ListMenuTemplate sDebugMenu_ListTemplate_Utilities =
{
    .items = sDebugMenu_Items_Utilities,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sDebugMenu_Items_Utilities),
};

static const struct ListMenuTemplate sDebugMenu_ListTemplate_Flags =
{
    .items = sDebugMenu_Items_Flags,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sDebugMenu_Items_Flags),
};

static const struct ListMenuTemplate sDebugMenu_ListTemplate_Sub1 =
{
    .items = sDebugMenu_Items_Sub1,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sDebugMenu_Items_Sub1),
};

void Debug_ShowMainMenu(void)
{
    Debug_ShowMenu(DebugTask_HandleMenuInput_Main, sDebugMenu_ListTemplate_Main);
}

static void Debug_ShowMenu(void (*HandleInput)(u8), struct ListMenuTemplate LMtemplate)
{
    struct ListMenuTemplate menuTemplate;
    u8 windowId;
    u8 menuTaskId;
    u8 inputTaskId;

    // create window
    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugMenuWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    // create list menu
    menuTemplate = LMtemplate;
    menuTemplate.maxShowed = DEBUG_MAIN_MENU_HEIGHT;
    menuTemplate.windowId = windowId;
    menuTemplate.header_X = 0;
    menuTemplate.item_X = 8;
    menuTemplate.cursor_X = 0;
    menuTemplate.upText_Y = 1;
    menuTemplate.cursorPal = 2;
    menuTemplate.fillValue = 1;
    menuTemplate.cursorShadowPal = 3;
    menuTemplate.lettersSpacing = 1;
    menuTemplate.itemVerticalPadding = 0;
    menuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    menuTemplate.fontId = 1;
    menuTemplate.cursorKind = 0;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // draw everything
    CopyWindowToVram(windowId, 3);

    // create input handler task
    inputTaskId = CreateTask(HandleInput, 3);
    gTasks[inputTaskId].data[0] = menuTaskId;
    gTasks[inputTaskId].data[1] = windowId;
}

static void Debug_DestroyMenu(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].data[0], NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].data[1], TRUE);
    RemoveWindow(gTasks[taskId].data[1]);
    DestroyTask(taskId);
}

// Handle Inputs
static void DebugTask_HandleMenuInput_Main(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if ((func = sDebugMenu_Actions_Main[input]) != NULL)
            func(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        Debug_DestroyMenu(taskId);
        EnableBothScriptContexts();
    }
}
static void DebugTask_HandleMenuInput_Utilities(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if ((func = sDebugMenu_Actions_SaveBlocks[input]) != NULL)
            func(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        Debug_DestroyMenu(taskId);
        Debug_ShowMainMenu();
    }
}
static void DebugTask_HandleMenuInput_Flags(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if ((func = sDebugMenu_Actions_Flags[input]) != NULL)
            func(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        Debug_DestroyMenu(taskId);
        Debug_ShowMainMenu();
    }
}

// Open sub-menus
static void DebugAction_OpenUtilitiesMenu(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    Debug_ShowMenu(DebugTask_HandleMenuInput_Utilities, sDebugMenu_ListTemplate_Utilities);
}
static void DebugAction_OpenFlagsMenu(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    Debug_ShowMenu(DebugTask_HandleMenuInput_Flags, sDebugMenu_ListTemplate_Flags);
}

// Actions
static void DebugAction_Cancel(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    EnableBothScriptContexts();
}
static void DebugAction_CheckSaveBlock(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(Debug_CheckSaveBlock);
}
static void DebugAction_SetWallClock(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(PlayersHouse_2F_EventScript_SetWallClock);
}
static void DebugAction_CheckWallClock(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(PlayersHouse_2F_EventScript_CheckWallClock);
}
static void DebugAction_SetPokedexFlags(u8 taskId)
{
    u16 i;
    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        GetSetPokedexFlag(i + 1, FLAG_SET_CAUGHT);
        GetSetPokedexFlag(i + 1, FLAG_SET_SEEN);
    }
    Debug_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(Debug_SetPokedexFlags);
}
static void DebugAction_SwitchDex(u8 taskId)
{
    if(FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        FlagClear(FLAG_SYS_POKEDEX_GET);
        PlaySE(SE_PC_OFF);
    }
    else
    {
        FlagSet(FLAG_SYS_POKEDEX_GET);
        PlaySE(SE_PC_LOGIN);
    }
}
static void DebugAction_SwitchNatDex(u8 taskId)
{
    if(IsNationalPokedexEnabled())
    {
        DisableNationalPokedex();
        PlaySE(SE_PC_OFF);
    }
    else
    {
        EnableNationalPokedex();
        PlaySE(SE_PC_LOGIN);
    }
}
static void DebugAction_SwitchPokeNav(u8 taskId)
{
    if(FlagGet(FLAG_SYS_POKENAV_GET))
    {
        FlagClear(FLAG_SYS_POKENAV_GET);
        PlaySE(SE_PC_OFF);
    }
    else
    {
        FlagSet(FLAG_SYS_POKENAV_GET);
        PlaySE(SE_PC_LOGIN);
    }
}
static void DebugAction_Credits(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    Debug_DestroyMenu(taskId);
    SetMainCallback2(CB2_StartCreditsSequence);
}

#endif
