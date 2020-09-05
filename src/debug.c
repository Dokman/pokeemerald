#include "debug.h"

#ifdef DEBUG_MENU

#include "global.h"
#include "event_object_movement.h"
#include "international_string_util.h"
#include "item.h"
#include "list_menu.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "pokedex.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "event_data.h"
#include "credits.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/species.h"

#define DEBUG_MAIN_MENU_HEIGHT 9
#define DEBUG_MAIN_MENU_WIDTH 13

#define DEBUG_NUMBER_DISPLAY_WIDTH 10
#define DEBUG_NUMBER_DISPLAY_HEIGHT 3

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
static void DebugAction_SetFlyFlags(u8);
static void DebugAction_SetBadgeFlags(u8);
static void DebugAction_CollisionOnOff(u8);
static void DebugAction_CheckWeekDay(u8);
static void DebugAction_Credits(u8);

static void DebugAction_GiveItem(u8 taskId);
static void DebugAction_Flags(u8 taskId);
static void DebugAction_Variables(u8 taskId);
static void DebugAction_WarpToMap(u8 taskId);
static void GiveItem_SelectItemId(u8 taskId);
static void GiveItem_SelectItemQuantity(u8 taskId);
static void GiveItem_DestroySelectItem(u8 taskId);
static void DebugAction_HealParty(u8 taskId);
static void DebugAction_AccessPC(u8 taskId);
static void DebugAction_GivePokemon(u8 taskId);

static void DebugAction_Cancel(u8);

static void DebugAction_OpenUtilitiesMenu(u8);
static void DebugAction_OpenFlagsMenu(u8);
static void DebugTask_HandleMenuInput_Main(u8);
static void DebugTask_HandleMenuInput_Utilities(u8);

extern u8 Debug_CheckSaveBlock[];
extern u8 PlayersHouse_2F_EventScript_SetWallClock[];
extern u8 PlayersHouse_2F_EventScript_CheckWallClock[];
extern u8 Debug_SetPokedexFlags[];
extern u8 Debug_CheckWeekDay[];

// Main Menu
static const u8 gDebugText_Utilities[] =        _("Utilities");
static const u8 gDebugText_Flags[] =            _("Flags");
static const u8 gDebugText_GiveItem[] =         _("Give Item");
static const u8 gDebugText_Cancel[] =           _("Cancel");

static const u8 gDebugText_Variables[] =        _("Variables");
static const u8 gDebugText_WarpToMap[] =        _("Warp To Map");
static const u8 gDebugText_HealParty[] =        _("Heal Party");
static const u8 gDebugText_AccessPC[] =         _("Access PC");
static const u8 gDebugText_GivePokemon[] =      _("Give Pokemon");

enum {
    DEBUG_MENU_ITEM_UTILITIES,
    DEBUG_MENU_ITEM_FLAGS,
    //DEBUG_MENU_ITEM_VARIABLES,
    //DEBUG_MENU_ITEM_WARP_TO_MAP,
    DEBUG_MENU_ITEM_GIVE_ITEM,
    //DEBUG_MENU_ITEM_HEAL_PARTY,
    //DEBUG_MENU_ITEM_ACCESS_PC,
    //DEBUG_MENU_ITEM_GIVE_POKEMON,
    DEBUG_MENU_ITEM_CANCEL
};

static const u8 gText_ItemQuantity[] =  _("  Quantity:       \n  {STR_VAR_1}    \n{STR_VAR_2}");
static const u8 gText_ItemID[] =        _("Item ID: {STR_VAR_3}\n{STR_VAR_1}    \n{STR_VAR_2}");

static const u8 digitInidicator_1[] =               _("{LEFT_ARROW}x1{RIGHT_ARROW}        ");
static const u8 digitInidicator_10[] =              _("{LEFT_ARROW}x10{RIGHT_ARROW}       ");
static const u8 digitInidicator_100[] =             _("{LEFT_ARROW}x100{RIGHT_ARROW}      ");
static const u8 digitInidicator_1000[] =            _("{LEFT_ARROW}x1000{RIGHT_ARROW}     ");
static const u8 digitInidicator_10000[] =           _("{LEFT_ARROW}x10000{RIGHT_ARROW}    ");
static const u8 digitInidicator_100000[] =          _("{LEFT_ARROW}x100000{RIGHT_ARROW}   ");
static const u8 digitInidicator_1000000[] =         _("{LEFT_ARROW}x1000000{RIGHT_ARROW}  ");
static const u8 digitInidicator_10000000[] =        _("{LEFT_ARROW}x10000000{RIGHT_ARROW} ");
const u8 * const gText_DigitIndicator[] =
{
    digitInidicator_1,
    digitInidicator_10,
    digitInidicator_100,
    digitInidicator_1000,
    digitInidicator_10000,
    digitInidicator_100000,
    digitInidicator_1000000,
    digitInidicator_10000000
};

static const s32 sPowersOfTen[] =
{
             1,
            10,
           100,
          1000,
         10000,
        100000,
       1000000,
      10000000,
     100000000,
    1000000000,
};

static const u8 gDebugText_SaveBlockSpace[] = _("SaveBlock Space");
static const u8 gDebugText_CheckWallClock[] = _("Check Wall Clock");
static const u8 gDebugText_SetWallClock[] = _("Set Wall Clock");
static const u8 gDebugText_CheckWeekDay[] = _("Check Week Day");
static const u8 gDebugText_WatchCredits[] = _("Watch Credits");

static const u8 gDebugText_SetPokedexFlags[] = _("Set Pokédex Flags");
static const u8 gDebugText_SwitchDex[] = _("Pokédex ON/OFF");
static const u8 gDebugText_SwitchNationalDex[] = _("NatDex ON/OFF");
static const u8 gDebugText_SwitchPokeNav[] = _("PokéNav ON/OFF");
static const u8 gDebugText_SetFlyFlags[] = _("Can Fly Anywhere");
static const u8 gDebugText_GetAllBadges[] = _("Get all badges");
static const u8 gDebugText_SwitchCollision[] = _("Collision ON/OFF");

static const u8 gDebugText_None[] = _("None");

static const struct ListMenuItem sDebugMenu_Items_Main[] =
{
    [DEBUG_MENU_ITEM_UTILITIES] = {gDebugText_Utilities, DEBUG_MENU_ITEM_UTILITIES},
    [DEBUG_MENU_ITEM_FLAGS] = {gDebugText_Flags, DEBUG_MENU_ITEM_FLAGS},
    [DEBUG_MENU_ITEM_GIVE_ITEM] = {gDebugText_GiveItem, DEBUG_MENU_ITEM_GIVE_ITEM},
    [DEBUG_MENU_ITEM_CANCEL] = {gDebugText_Cancel, DEBUG_MENU_ITEM_CANCEL}
};
/*
    [DEBUG_MENU_ITEM_VARIABLES] = {gDebugText_Variables, DEBUG_MENU_ITEM_VARIABLES},
    [DEBUG_MENU_ITEM_WARP_TO_MAP] = {gDebugText_WarpToMap, DEBUG_MENU_ITEM_WARP_TO_MAP},
    [DEBUG_MENU_ITEM_HEAL_PARTY] = {gDebugText_HealParty, DEBUG_MENU_ITEM_HEAL_PARTY},
    [DEBUG_MENU_ITEM_ACCESS_PC] = {gDebugText_AccessPC, DEBUG_MENU_ITEM_ACCESS_PC},
    [DEBUG_MENU_ITEM_GIVE_POKEMON] = {gDebugText_GivePokemon, DEBUG_MENU_ITEM_GIVE_POKEMON},
    [DEBUG_MENU_ITEM_CANCEL] = {gDebugText_Cancel, DEBUG_MENU_ITEM_CANCEL}
*/

static const struct ListMenuItem sDebugMenu_Items_Utilities[] =
{
    [0] = {gDebugText_SaveBlockSpace, 0},
    [1] = {gDebugText_CheckWallClock, 1},
    [2] = {gDebugText_SetWallClock, 2},
    [3] = {gDebugText_CheckWeekDay, 3},
    [4] = {gDebugText_WatchCredits, 4},
};

static const struct ListMenuItem sDebugMenu_Items_Flags[] =
{
    [0] = {gDebugText_SetPokedexFlags, 0},
    [1] = {gDebugText_SwitchDex, 1},
    [2] = {gDebugText_SwitchNationalDex, 2},
    [3] = {gDebugText_SwitchPokeNav, 3},
    [4] = {gDebugText_SetFlyFlags, 4},
    [5] = {gDebugText_GetAllBadges, 5},
    [6] = {gDebugText_SwitchCollision, 6},
};

static void (*const sDebugMenu_Actions_Main[])(u8) =
{
    [DEBUG_MENU_ITEM_UTILITIES] = DebugAction_OpenUtilitiesMenu,
    [DEBUG_MENU_ITEM_FLAGS] = DebugAction_OpenFlagsMenu,
    [DEBUG_MENU_ITEM_GIVE_ITEM] = DebugAction_GiveItem,
    [DEBUG_MENU_ITEM_CANCEL] = DebugAction_Cancel
};
/*
    [DEBUG_MENU_ITEM_FLAGS] = DebugAction_Flags,
    [DEBUG_MENU_ITEM_VARIABLES] = DebugAction_Variables,
    [DEBUG_MENU_ITEM_WARP_TO_MAP] = DebugAction_WarpToMap,
    [DEBUG_MENU_ITEM_HEAL_PARTY] = DebugAction_HealParty,
    [DEBUG_MENU_ITEM_ACCESS_PC] = DebugAction_AccessPC,
    [DEBUG_MENU_ITEM_GIVE_POKEMON] = DebugAction_GivePokemon,
    [DEBUG_MENU_ITEM_CANCEL] = DebugAction_Cancel
*/

static void (*const sDebugMenu_Actions_Utilities[])(u8) =
{
    [0] = DebugAction_CheckSaveBlock,
    [1] = DebugAction_CheckWallClock,
    [2] = DebugAction_SetWallClock,
    [3] = DebugAction_CheckWeekDay,
    [4] = DebugAction_Credits,
};

static void (*const sDebugMenu_Actions_Flags[])(u8) =
{
    [0] = DebugAction_SetPokedexFlags,
    [1] = DebugAction_SwitchDex,
    [2] = DebugAction_SwitchNatDex,
    [3] = DebugAction_SwitchPokeNav,
    [4] = DebugAction_SetFlyFlags,
    [5] = DebugAction_SetBadgeFlags,
    [6] = DebugAction_CollisionOnOff,
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

static const struct WindowTemplate sDebugNumberDisplayWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 4 + DEBUG_MAIN_MENU_WIDTH,
    .tilemapTop = 1,
    .width = DEBUG_NUMBER_DISPLAY_WIDTH,
    .height = 2 * DEBUG_NUMBER_DISPLAY_HEIGHT,
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
        if ((func = sDebugMenu_Actions_Utilities[input]) != NULL)
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
static void DebugAction_SetFlyFlags(u8 taskId)
{
    FlagSet(FLAG_VISITED_LITTLEROOT_TOWN);
    FlagSet(FLAG_VISITED_OLDALE_TOWN);
    FlagSet(FLAG_VISITED_DEWFORD_TOWN);
    FlagSet(FLAG_VISITED_LAVARIDGE_TOWN);
    FlagSet(FLAG_VISITED_FALLARBOR_TOWN);
    FlagSet(FLAG_VISITED_VERDANTURF_TOWN);
    FlagSet(FLAG_VISITED_PACIFIDLOG_TOWN);
    FlagSet(FLAG_VISITED_PETALBURG_CITY);
    FlagSet(FLAG_VISITED_SLATEPORT_CITY);
    FlagSet(FLAG_VISITED_MAUVILLE_CITY);
    FlagSet(FLAG_VISITED_RUSTBORO_CITY);
    FlagSet(FLAG_VISITED_FORTREE_CITY);
    FlagSet(FLAG_VISITED_LILYCOVE_CITY);
    FlagSet(FLAG_VISITED_MOSSDEEP_CITY);
    FlagSet(FLAG_VISITED_SOOTOPOLIS_CITY);
    FlagSet(FLAG_VISITED_EVER_GRANDE_CITY);

    FlagSet(FLAG_VISITED_ROUTE101);
    FlagSet(FLAG_VISITED_ROUTE102);
    FlagSet(FLAG_VISITED_ROUTE103);
    FlagSet(FLAG_VISITED_ROUTE104);
    FlagSet(FLAG_VISITED_ROUTE105);
    FlagSet(FLAG_VISITED_ROUTE106);
    FlagSet(FLAG_VISITED_ROUTE107);
    FlagSet(FLAG_VISITED_ROUTE108);
    FlagSet(FLAG_VISITED_ROUTE109);
    FlagSet(FLAG_VISITED_ROUTE110);
    FlagSet(FLAG_VISITED_ROUTE111);
    FlagSet(FLAG_VISITED_ROUTE112);
    FlagSet(FLAG_VISITED_ROUTE113);
    FlagSet(FLAG_VISITED_ROUTE114);
    FlagSet(FLAG_VISITED_ROUTE115);
    FlagSet(FLAG_VISITED_ROUTE116);
    FlagSet(FLAG_VISITED_ROUTE117);
    FlagSet(FLAG_VISITED_ROUTE118);
    FlagSet(FLAG_VISITED_ROUTE119);
    FlagSet(FLAG_VISITED_ROUTE120);
    FlagSet(FLAG_VISITED_ROUTE121);
    FlagSet(FLAG_VISITED_ROUTE122);
    FlagSet(FLAG_VISITED_ROUTE123);
    FlagSet(FLAG_VISITED_ROUTE124);
    FlagSet(FLAG_VISITED_ROUTE125);
    //FlagSet(FLAG_VISITED_ROUTE126);
    FlagSet(FLAG_VISITED_ROUTE127);
    FlagSet(FLAG_VISITED_ROUTE128);
    //FlagSet(FLAG_VISITED_ROUTE129);
    //FlagSet(FLAG_VISITED_ROUTE130);
    //FlagSet(FLAG_VISITED_ROUTE131);
    FlagSet(FLAG_VISITED_ROUTE132);
    FlagSet(FLAG_VISITED_ROUTE133);
    FlagSet(FLAG_VISITED_ROUTE134);
    FlagSet(FLAG_VISITED_MT_CHIMNEY);
}
static void DebugAction_SetBadgeFlags(u8 taskId)
{
    FlagSet(FLAG_BADGE01_GET);
    FlagSet(FLAG_BADGE02_GET);
    FlagSet(FLAG_BADGE03_GET);
    FlagSet(FLAG_BADGE04_GET);
    FlagSet(FLAG_BADGE05_GET);
    FlagSet(FLAG_BADGE06_GET);
    FlagSet(FLAG_BADGE07_GET);
    FlagSet(FLAG_BADGE08_GET);
}
static void DebugAction_CollisionOnOff(u8 taskId)
{
    if(FlagGet(FLAG_SYS_NO_COLLISION))
    {
        FlagClear(FLAG_SYS_NO_COLLISION);
        PlaySE(SE_PC_OFF);
    }
    else
    {
        FlagSet(FLAG_SYS_NO_COLLISION);
        PlaySE(SE_PC_LOGIN);
    }
}

static void DebugAction_CheckWeekDay(u8 taskId)
{
    Debug_DestroyMenu(taskId);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(Debug_CheckWeekDay);
}
static void DebugAction_Credits(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    Debug_DestroyMenu(taskId);
    SetMainCallback2(CB2_StartCreditsSequence);
}

static void DebugAction_GiveItem(u8 taskId)
{
    u8 windowId;

    ClearStdWindowAndFrame(gTasks[taskId].data[1], TRUE);
    RemoveWindow(gTasks[taskId].data[1]);

    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sDebugNumberDisplayWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    CopyWindowToVram(windowId, 3);

    //Display initial ID
    StringCopy(gStringVar2, gText_DigitIndicator[0]);
    ConvertIntToDecimalStringN(gStringVar3, 1, STR_CONV_MODE_LEADING_ZEROS, 4);
    CopyItemName(1, gStringVar1);
    StringCopyPadded(gStringVar1, gStringVar1, CHAR_SPACE, 15);
    StringExpandPlaceholders(gStringVar4, gText_ItemID);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, 1, 1, 0, NULL);

    gTasks[taskId].func = GiveItem_SelectItemId;
    gTasks[taskId].data[2] = windowId;
    gTasks[taskId].data[3] = 1;            //Current ID
    gTasks[taskId].data[4] = 0;            //Digit Selected
}

static void GiveItem_SelectItemId(u8 taskId)
{
    if (gMain.newKeys & DPAD_ANY)
    {
        PlaySE(SE_SELECT);

        if(gMain.newKeys & DPAD_UP)
        {
            gTasks[taskId].data[3] += sPowersOfTen[gTasks[taskId].data[4]];
            if(gTasks[taskId].data[3] >= ITEMS_COUNT){
                gTasks[taskId].data[3] = ITEMS_COUNT - 1;
            }
        }
        if(gMain.newKeys & DPAD_DOWN)
        {
            gTasks[taskId].data[3] -= sPowersOfTen[gTasks[taskId].data[4]];
            if(gTasks[taskId].data[3] < 0){
                gTasks[taskId].data[3] = 0;
            }
        }
        if(gMain.newKeys & DPAD_LEFT)
        {
            if(gTasks[taskId].data[4] > 0)
            {
                gTasks[taskId].data[4] -= 1;
            }
        }
        if(gMain.newKeys & DPAD_RIGHT)
        {
            if(gTasks[taskId].data[4] < 3)
            {
                gTasks[taskId].data[4] += 1;
            }
        }

        StringCopy(gStringVar2, gText_DigitIndicator[gTasks[taskId].data[4]]);
        CopyItemName(gTasks[taskId].data[3], gStringVar1);
        StringCopyPadded(gStringVar1, gStringVar1, CHAR_SPACE, 15);
        ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].data[3], STR_CONV_MODE_LEADING_ZEROS, 4);
        StringExpandPlaceholders(gStringVar4, gText_ItemID);

        AddTextPrinterParameterized(gTasks[taskId].data[2], 1, gStringVar4, 1, 1, 0, NULL);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        gTasks[taskId].data[5] = gTasks[taskId].data[3];
        gTasks[taskId].data[3] = 0;
        gTasks[taskId].data[4] = 0;

        StringCopy(gStringVar2, gText_DigitIndicator[gTasks[taskId].data[4]]);
        ConvertIntToDecimalStringN(gStringVar1, gTasks[taskId].data[3], STR_CONV_MODE_LEADING_ZEROS, 2);
        StringCopyPadded(gStringVar1, gStringVar1, CHAR_SPACE, 15);
        StringExpandPlaceholders(gStringVar4, gText_ItemQuantity);
        AddTextPrinterParameterized(gTasks[taskId].data[2], 1, gStringVar4, 1, 1, 0, NULL);

        gTasks[taskId].func = GiveItem_SelectItemQuantity;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        GiveItem_DestroySelectItem(taskId);
    }
}

static void GiveItem_SelectItemQuantity(u8 taskId)
{
    if (gMain.newKeys & DPAD_ANY)
    {
        PlaySE(SE_SELECT);

        if(gMain.newKeys & DPAD_UP)
        {
            gTasks[taskId].data[3] += sPowersOfTen[gTasks[taskId].data[4]];
            if(gTasks[taskId].data[3] >= 100){
                gTasks[taskId].data[3] = 99;
            }
        }
        if(gMain.newKeys & DPAD_DOWN)
        {
            gTasks[taskId].data[3] -= sPowersOfTen[gTasks[taskId].data[4]];
            if(gTasks[taskId].data[3] < 0){
                gTasks[taskId].data[3] = 0;
            }
        }
        if(gMain.newKeys & DPAD_LEFT)
        {
            if(gTasks[taskId].data[4] > 0)
            {
                gTasks[taskId].data[4] -= 1;
            }
        }
        if(gMain.newKeys & DPAD_RIGHT)
        {
            if(gTasks[taskId].data[4] < 2)
            {
                gTasks[taskId].data[4] += 1;
            }
        }

        StringCopy(gStringVar2, gText_DigitIndicator[gTasks[taskId].data[4]]);
        ConvertIntToDecimalStringN(gStringVar1, gTasks[taskId].data[3], STR_CONV_MODE_LEADING_ZEROS, 2);
        StringCopyPadded(gStringVar1, gStringVar1, CHAR_SPACE, 15);
        StringExpandPlaceholders(gStringVar4, gText_ItemQuantity);

        AddTextPrinterParameterized(gTasks[taskId].data[2], 1, gStringVar4, 1, 1, 0, NULL);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(MUS_FANFA4);
        AddBagItem(gTasks[taskId].data[5], gTasks[taskId].data[3]);
        GiveItem_DestroySelectItem(taskId);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        GiveItem_DestroySelectItem(taskId);
    }
}

static void GiveItem_DestroySelectItem(u8 taskId)
{

    ClearStdWindowAndFrame(gTasks[taskId].data[1], TRUE);
    RemoveWindow(gTasks[taskId].data[1]);

    ClearStdWindowAndFrame(gTasks[taskId].data[2], TRUE);
    RemoveWindow(gTasks[taskId].data[2]);

    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static void DebugAction_HealParty(u8 taskId)
{
    PlaySE(SE_KAIFUKU);
    HealPlayerParty();
    Debug_DestroyMenu(taskId);
}

#endif
