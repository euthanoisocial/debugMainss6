#pragma once

#include "stdafx.h"
#include "import.h"
#include "Protect.h"
#include "CustomOfflineMode.h"
#define KiemTraCacEvent_1 gInterface.CheckWindow(Character)	|| gInterface.CheckWindow(Warehouse)	|| gInterface.CheckWindow(ChaosBox)	|| gInterface.CheckWindow(Store)	|| gInterface.CheckWindow(OtherStore)	|| gInterface.CheckWindow(Inventory) || gInterface.CheckWindow(ExpandInventory)	|| gInterface.CheckWindow(Shop)	|| gInterface.CheckWindow(Trade)	|| gInterface.CheckWindow(LuckyCoin1)	|| gInterface.CheckWindow(NPC_ChaosMix) || gInterface.CheckWindow(MoveList)
#define KiemTraCacEvent_2 gInterface.CheckWindow(ObjWindow::CashShop) ||gInterface.CheckWindow(ObjWindow::FriendList)||gInterface.CheckWindow(ObjWindow::MoveList)|| gInterface.CheckWindow(ObjWindow::Party)|| gInterface.CheckWindow(ObjWindow::Quest)|| gInterface.CheckWindow(ObjWindow::NPC_Devin)|| gInterface.CheckWindow(ObjWindow::Guild)	|| gInterface.CheckWindow(ObjWindow::Trade)|| gInterface.CheckWindow(ObjWindow::Warehouse)|| gInterface.CheckWindow(ObjWindow::ChaosBox)|| gInterface.CheckWindow(ObjWindow::CommandWindow)|| gInterface.CheckWindow(ObjWindow::PetInfo)|| gInterface.CheckWindow(ObjWindow::Shop)|| gInterface.CheckWindow(ObjWindow::Inventory)|| gInterface.CheckWindow(ObjWindow::Store)|| gInterface.CheckWindow(ObjWindow::OtherStore)|| gInterface.CheckWindow(ObjWindow::Character)	|| gInterface.CheckWindow(ObjWindow::DevilSquare)|| gInterface.CheckWindow(ObjWindow::BloodCastle)|| gInterface.CheckWindow(ObjWindow::CreateGuild)|| gInterface.CheckWindow(ObjWindow::GuardNPC)|| gInterface.CheckWindow(ObjWindow::SeniorNPC)|| gInterface.CheckWindow(ObjWindow::GuardNPC2)|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)|| gInterface.CheckWindow(ObjWindow::CatapultNPC)|| gInterface.CheckWindow(ObjWindow::CrywolfGate)|| gInterface.CheckWindow(ObjWindow::IllusionTemple)|| gInterface.CheckWindow(ObjWindow::HeroList)   || gInterface.CheckWindow(ObjWindow::ChatWindow)|| gInterface.CheckWindow(ObjWindow::FastMenu)|| gInterface.CheckWindow(ObjWindow::Options)|| gInterface.CheckWindow(ObjWindow::Help)|| gInterface.CheckWindow(ObjWindow::FastDial)|| gInterface.CheckWindow(ObjWindow::SkillTree)|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)|| gInterface.CheckWindow(ObjWindow::NPC_Duel)|| gInterface.CheckWindow(ObjWindow::NPC_Titus)|| gInterface.CheckWindow(ObjWindow::CashShop)|| gInterface.CheckWindow(ObjWindow::Lugard)|| gInterface.CheckWindow(ObjWindow::QuestList1)|| gInterface.CheckWindow(ObjWindow::QuestList2)|| gInterface.CheckWindow(ObjWindow::Jerint)|| gInterface.CheckWindow(ObjWindow::FullMap)|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)|| gInterface.CheckWindow(ObjWindow::GensInfo)|| gInterface.CheckWindow(ObjWindow::NPC_Julia)|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)|| gInterface.CheckWindow(ObjWindow::ExpandInventory)|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)|| gInterface.CheckWindow(ObjWindow::MuHelper)

#define MAX_OBJECT 	1010 // 350
#define MAX_WIN_WIDTH 640
#define MAX_WIN_HEIGHT 480
#define MAX_WINDOW_EX 200
#define CS_GET_STRUCT(x, y)	   (1124 * x + *(int*) y)
#define pDrawInterfaceNumBer   ((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)

#define GMT (24 + (gProtect.m_MainInfo.TIME_GMT))
#define ButtonMenuSpk 21
enum ObjectID
{
	//tue add custom user ranking
	//tue add custom user ranking
	eFlag01 = 1,
	eFlag02,
	eFlag03,
	eFlag04,
	eFlag05,
	eFlag06,
	eFlag07,
	eFlag08,
	eFlag09,
	eFlag10,
	eFlag11,
	eFlag12,
	eFlag13,
	eFlag14,
	eFlag15,
	eFlag16,
	eFlag17,
	eFlag18,
	eFlag19,
	eFlag20,
	eFlag21,
	eFlag22,
	//--------
	eMenu_MAIN,
	//-----
	
	eTIME,
	eRankPANEL_MAIN,
	eRanking,
	eSAMPLEBUTTON,
	eSAMPLEBUTTON2,
//tue add ATM BOX
#if (RESETCHANGE ==1)
	SPK_RsChange_Main,
	SPK_RsChange_Btn01,
	SPK_RsChange_Btn02,
	SPK_RsChange_Btn03,
	SPK_RsChange_Btn04,
	SPK_RsChange_Btn05,
#endif
	SPK_ThueFlag_Main,
//----
	#if(BOSS_GUILD == 1)
	eBossGuildWindow,
#endif


	eMenu_CLOSE, // tue add ATM BOX
	#if(MOCNAP == 1)
	EXBEXO_MOCNAP_MAIN,
	EXBEXO_MOCNAP_CLOSE,
	//tue add atm boxxx
	eMenu_OPT1,
	eMenu_OPT2,
	eMenu_OPT3,
	eMenu_OPT4,
	eMenu_OPT5,
	eMenu_OPT6,
	eMenu_OPT7,
	eMenu_OPT8,
	eMenu_OPT9,
	eMenu_OPT10,
	eMenu_OPT11,
	eMenu_OPT12,
	eMenu_OPT13,
	eMenu_OPT14,
	//tue add ATM BOX
	SPK_MAIN_ATM = 53,
	SPK_MAIN_ARESET,
	SPK_MAIN_RSCAM,
	SPK_MAIN_ZMCAM,
	SPK_MAIN_BOXSK,
	eInvasionInfo,
	SPK_CONFIG_BOX,
	SPK_ITEM_BLOCK,
	SPK_PK_LOCK,
	SPK_AUTO_HP,
	SPK_AUTO_BF,
	eMenu_OPT15,
	eMenu_OPT16,
	eMenu_OPT17,
	eMenu_OPT18,
	eMenu_OPT19,
	eMenu_OPT20,
	BOX_MAIN_VONGQUAY,
	// end add -------

	MOCNAP1,
	MOCNAP2,
	MOCNAP3,
	MOCNAP4,
	MOCNAP5,
	MOCNAP6,
	MOCNAP7,
	MOCNAP8,
	MOCNAP9,
	MOCNAP10,
	MOCNAP11,
	MOCNAP12,
	MOCNAP13,
#endif
	eNEWS_MAIN,
	eNEWS_TITLE,
	eNEWS_FRAME,
	eNEWS_FOOTER,
	eNEWS_DIV,
	eNEWS_INFOBG,
	eNEWS_CLOSE,
	eNEWS_BACK,
	
#if(QUAEVENT == 1)
	EXBEXO_QUATOP1_MAIN,
	EXBEXO_QUATOP1_CLOSE,
	QUATOP1,

	EXBEXO_QUATOP2_MAIN,
	EXBEXO_QUATOP2_CLOSE,
	QUATOP2,

	EXBEXO_QUATOP3_MAIN,
	EXBEXO_QUATOP3_CLOSE,
	QUATOP3,
#endif
	

	eRanking_MAIN,
	eRanking_CLOSE,
	eRanking_TITLE,
	eRanking_FRAME,
	eRanking_FOOTER,
	
	eLogo,

	eTVTHUD,
	eImgID_NUMBER_FONT_BIG2,

	eTIECRUOU_MAIN,
	eTIECRUOU_TITLE,
	eTIECRUOU_FRAME,
	eTIECRUOU_FOOTER,
	eTIECRUOU_DIV,
	eTIECRUOU_CLOSE,
	eTIECRUOU_OK,
	eTIECRUOU_INFOBG2,
	eMUARUOU_OK,	
	eMOIRUOU_MAIN,
	eMOIRUOU_TITLE,
	eMOIRUOU_FRAME,
	eMOIRUOU_FOOTER,
	eMOIRUOU_DIV,
	eMOIRUOU_CLOSE,
	eMOIRUOU_ZEN,
	eMOIRUOU_WC,
	////muun
	eCONFIRM_MUUN,
    eCONFIRM_MUUNBTN_OK,
    eCONFIRM_MUUNBTN_CANCEL,

	eEventTimePANEL_MAIN,
	eEventTime_MAIN,
	eEventTime_TITLE,
	eEventTime_CLOSE,
	eEventTime_FRAME,
	eEventTime_FOOTER,
		////////nutmoi
	SOLAR_BUTTON_HUONGDAN_MAIN,
	SOLAR_BUTTON_HUONGDAN_CLOSE,
	SOLAR_NEW_MENU_MAIN,
	SOLAR_NAPTHE_MAIN,
	SOLAR_NAPTHE_BUTTON_MAIN,
	//////////////////////////
	EXBEXO_DANH_HIEU_MAIN,
	EXBEXO_DANH_HIEU_CLOSE,
    EXBEXO_DANH_HIEU_NANG_CAP,
	eDANH_HIEU2,
	eDANH_HIEU1,
	/////////////////////////
	EXBEXO_QUAN_HAM_MAIN,
	EXBEXO_QUAN_HAM_CLOSE,
	EXBEXO_QUAN_HAM_NANG_CAP,

	eQUAN_HAM1,
	eQUAN_HAM2,
	eWindowDoiItem, // tue add ATM box
///////////////////////////
#if(LEOTHAP == 1)
	// Leo thap
	eLEOTHAP_MAIN,
	eLEOTHAP_TITLE,
	eLEOTHAP_FRAME,
	eLEOTHAP_FOOTER,
	eLEOTHAP_DIV,
	eLEOTHAP_CLOSE,
	eLEOTHAP_POINT,
	eLEOTHAP_BUTTON_GATE1,
	eLEOTHAP_BUTTON_GATE2,
	eLEOTHAP_BUTTON_GATE3,
	eLEOTHAP_BUTTON_GATE4,
	eLEOTHAP_BUTTON_GATE5,
#endif
#if(DOIMK)
		//====Chnage Pass
     eChangePass_Main,
     eChangePass_OLD,
     eChangePass_OLD_HIDE,
     eChangePass_NEW_HIDE,
     eChangePass_NEW,
     eChangePass_BTOK,
     eChangePass_BTCLOSE,
	QUAN_LY_TK_MAIN,
	QUAN_LY_TK_CLOSE,
	eQUAN_LY1,
	eQUAN_LY2,
	eQUAN_LY3,
	eQUAN_LY4,
	eQUAN_LY5,
	eQUAN_LY6,
	eQUAN_LY7,
	eQUAN_LY8,
	eQUAN_LY9,
	eQUAN_LY10,
	eQUAN_LY11,
	eQUAN_LY12,
	eQUAN_LY13,
	eQUAN_LYTK1,
	eQUAN_LYTK2,
#endif
////////////////////////////

////////////////////////////
	SOLAR_SYSTEM_CHUYENSUB_MAIN,
    SOLAR_SYSTEM_CHUYENSUB_CLOSE,
    SYSTEM_CHUYENSUB_1,
    SYSTEM_CHUYENSUB_2,
    SYSTEM_CHUYENSUB_3,
    SYSTEM_CHUYENSUB_4,
    SYSTEM_CHUYENSUB_5,
    SYSTEM_CHUYENSUB_6,
	/////////////////
	ePT_PERSONAL_SEARCH_MAIN,
	ePT_PERSONAL_SEARCH_TITLE,
	ePT_PERSONAL_SEARCH_FRAME, 
	ePT_PERSONAL_SEARCH_FOOTER,
	ePT_PERSONAL_SEARCH_DIV,
	ePT_PERSONAL_SEARCH_CLOSE,
	ePT_PERSONAL_SEARCH_L,
	ePT_PERSONAL_SEARCH_R,
	ePT_PERSONAL_SEARCH_PAGEUP1,
	ePT_PERSONAL_SEARCH_PAGEUP2,
	ePT_PERSONAL_SEARCH_PAGEUP3,
	ePT_PERSONAL_SEARCH_PAGEUP4,
	ePT_PERSONAL_SEARCH_PAGEUP5,
	ePT_PERSONAL_SEARCH_PAGEUP6,
	ePT_PERSONAL_SEARCH_PAGEUP7,
	ePT_PERSONAL_SEARCH_PAGEUP8,
	ePT_PERSONAL_SEARCH_PAGEUP9,
	ePT_PERSONAL_SEARCH_PAGEUP10,
	////////////////////////
	eCTCMiniWindow,
	eOTHERCHAR_POINT,
	eCHAR_POINT,
	/////////////////////
	eTimeCTC,
	eCuaSoCTC,
	////////////////////
	eMenu,
	eMenuBG,
	eRock,
	ePaper,
	eScissors,
	eOFFTRADE_JoB,
	eOFFTRADE_JoS,
	eOFFTRADE_JoC,
	eOFFTRADE_WCC,
	eOFFTRADE_WCP,
	eOFFTRADE_WCG,
	eOFFTRADE_OPEN,
	//Minimap
	ePLAYER_POINT,
	eNULL_MAP,
	SPK_CtcMini_BtnClose, //tue add ATM box
	eLORENCIA_MAP,
	eDUNGEON_MAP,
	eDEVIAS_MAP,
	eNORIA_MAP,
	eLOSTTOWER_MAP,
	eSTADIUM_MAP,
	//tue add ATM BOX
		ChonTopAll,
		ChonTopWC,
		ChonTopEvent,
		ChonTopPK,
		ChonTopGuild,
		ChonTopMT,
	//-----
	eATLANS_MAP,
	eTarkan_MAP,
	eElbeland_MAP,
	eICARUS_MAP,
	eLANDOFTRIALS_MAP,
	eAIDA_MAP,
	eCRYWOLF_MAP,
	eKANTRU_MAP,
	eKANTRU3_MAP,
	eBARRACKS_MAP,
	eCALMNESS_MAP,
	eRAKLION_MAP,
	eVULCANUS_MAP,
	eKALRUTAN_MAP,
	//tue add ATMM box
		 TMC_MAIN,
		 TMC_TITLE,
		 TMC_FRAME,
		 TMC_FOOTER,
	//-----
	eKALRUTAN2_MAP,
	eCONFIRM_MAIN,
	eCONFIRM_BTN_OK,
	eCONFIRM_BTN_CANCEL,
	eCONFIRM_TITLE,
	eCONFIRM_FRAME,
	eCONFIRM_FOOTER,
	eCONFIRM_DIV,
	eNextCommand,
	ePrevCommand,
	eCommand_MAIN,
	eNextEvent,
	ePrevEvent,
//Ex700
	eMainEx700,
	eQuest,
	eCommunity,
	eSystem,
	//--custom
	eSTORE_CLOSE,
	ex_INFO_2,
	eADVANCE_STAT_INFO,
	
	//tue add ATM box
		eWindow_NangCapHonHoan = 225,
		eWindow_NangCapDanhHieu,
		eWindow_NangCapQuanHam,
		eWindow_NangCapTuChan,
		eWindow_NangCapNewVip,
	//-----
	
	//--s2
	eMainS2right,
	eMainS2middle,
	eMainS2left,
	eSkillBox,
	eDragonLeft,
	eDragonRight,
	eCharacter,
	eInventory,
	eParty,
	eFriend,
	eWindowNPCArenaPvP, //tue add ATM box
		eWindowBXHArenaPvP, //tue add ATM box
	eFastMenu,
	eShop,
	eTopDame,
	eGuild,
	eCommandWindow,
	//--custom money
	eMoney1,
	eMoney2,
	CharacterSelect,
	CharacterSelect_Button1,
	ATM_BOX_MAIN, // tue add ATM box
	CharacterSelect_Button2,
	CharacterSelect_Button3,
	CharacterSelect_Button4,
	CharacterSelect_Button5,
	CharacterCreate_Button1,
	CharacterCreate_Button2,
	CharacterCreate_Button3,
	CharacterCreate_Button4,
	CharacterCreate_Button5,
	CharacterCreate_Button6,
	CharacterCreate_Button7,
	CharacterCreate_SEND,
	CharacterCreate_CANCEL,
	//chat
	chatbackground,
	MINIMAP_FRAME,
	MINIMAP_TIME_FRAME,
	MINIMAP_BUTTOM,
	ButtonSettings,
	ButtonStart,
	ButtonStop,
	ButtonStartAttack,
	eCamera3DInit,
	eCamera3DSwitch,
	strucMoveInv,
	eMainEx700Exp,
	RuudShopListIzq,
	RuudShopListDer,
	RuudShopWindow,
	RuudShopExit,
	eButton1,
	eButton2,
	eButton3,
	eButton4,
	eButton5,

	OBJECT_RESET_MAIN,
	OBJECT_RESET_TITLE,
	OBJECT_RESET_FRAME,
	OBJECT_RESET_FOOTER,
	OBJECT_RESET_DIV,
	OBJECT_RESET_INFO_BG,
	OBJECT_RESET_MONEY_BG,
	OBJECT_RESET_CLOSE,
	OBJECT_RESET_FINISH,
	OBJECT_GRESET_MAIN,
	OBJECT_GRESET_TITLE,
	OBJECT_GRESET_FRAME,
	OBJECT_GRESET_FOOTER,
	OBJECT_GRESET_DIV,
	OBJECT_GRESET_INFO_BG,
	OBJECT_GRESET_MONEY_BG,
	OBJECT_GRESET_CLOSE,
	OBJECT_GRESET_FINISH,

	OBJECT_ACHIEVEMENTS_MAIN,
	OBJECT_ACHIEVEMENTS_PROGRESS_BG,
	OBJECT_ACHIEVEMENTS_PANEL,
	OBJECT_ACHIEVEMENTS_CLOSE,
	OBJECT_ACHIEVEMENTS_MISSIONS,
	OBJECT_ACHIEVEMENTS_DAMAGE,
	OBJECT_ACHIEVEMENTS_DEFENSE,
	OBJECT_ACHIEVEMENTS_LIFE,
	OBJECT_ACHIEVEMENTS_EXCELLENT,
	OBJECT_ACHIEVEMENTS_CRITICAL,

	OBJECT_WIN_QUEST_MAIN,
	OBJECT_WIN_QUEST_TITLE,
	OBJECT_WIN_QUEST_FRAME,
	OBJECT_WIN_QUEST_FOOTER,
	OBJECT_WIN_QUEST_DIV,
	OBJECT_WIN_QUEST_CLOSE,
	OBJECT_WIN_QUEST_TAB,
	OBJECT_WIN_QUEST_TAB1,
	OBJECT_WIN_QUEST_TAB2,
	OBJECT_WIN_QUEST_TAB3,
	OBJECT_WIN_QUEST_FINISH,
	OBJECT_WIN_QUEST_COUNT1,
	OBJECT_WIN_QUEST_COUNT2,
	OBJECT_WIN_QUEST_COUNT3,
	OBJECT_WIN_QUEST_INFOBG,
	OBJECT_WIN_QUEST_INFOBG2,
	OBJECT_WIN_QUEST_LINE1,
	OBJECT_WIN_QUEST_POINT1,
	OBJECT_WIN_QUEST_INFO,
	OBJECT_WIN_QUEST_INFOBG3,

	eCHANGINGCLASS_MAIN,
	eCHANGINGCLASS_TITLE,
	eCHANGINGCLASS_FRAME,
	eCHANGINGCLASS_FOOTER,
	eCHANGINGCLASS_DIV,
	eCHANGINGCLASS_INFOBG,
	eCHANGINGCLASS_MONEYBG,
	eCHANGINGCLASS_CLOSE,
	eCHANGINGCLASS_DW,
	eCHANGINGCLASS_DK,
	eCHANGINGCLASS_ELF,
	eCHANGINGCLASS_MG,
	eCHANGINGCLASS_DL,
	eCHANGINGCLASS_SUM,
	eCHANGINGCLASS_RF,

	eWAREHOUSE,
	eWAREHOUSE1,
	eWAREHOUSE_MAIN,
	eWAREHOUSE_TITLE,
	eWAREHOUSE_FRAME,
	eWAREHOUSE_FOOTER,
	eWAREHOUSE_DIV,
	eWAREHOUSE_CLOSE,
	eWAREHOUSE_NUM1,
	eWAREHOUSE_NUM2,
	eWAREHOUSE_NUM3,
	eWAREHOUSE_NUM4,
	eWAREHOUSE_NUM5,
	eWAREHOUSE_NUM6,
	eWAREHOUSE_NUM7,
	eWAREHOUSE_NUM8,

	eSTATSADD_MAIN,
	eSTATSADD_TITLE,
	eSTATSADD_FRAME,
	eSTATSADD_FOOTER,
	eSTATSADD_CLOSE,
	eSTATSADD_TEXTBOX01,
	eSTATSADD_STATBOX01,
	eSTATSADD_STATBOX02,
	eSTATSADD_STATBOX03,
	eSTATSADD_STATBOX04,
	eSTATSADD_STATBOX05,
	eSTATSADD_BTN_OK,
	eSTATSADD_STEP10,
	eSTATSADD_STEP100,
	eSTATSADD_STEP1000,

	eCHARINFO_BTN_STAT,

	eMAX_VALUE,

		ePARTYSETTINGS_MAIN,
		ePARTYSETTINGS_TITLE,
		ePARTYSETTINGS_FRAME,
		ePARTYSETTINGS_FOOTER,
		ePARTYSETTINGS_DIV,
		ePARTYSETTINGS_CLOSE,
		ePARTYSETTINGS_SYSTEM_ACTIVE,
		ePARTYSETTINGS_ONLY_GUILD,
		ePARTYSETTINGS_ONE_CLASS,
		ePARTYSETTINGS_DARK_WIZARD,
		ePARTYSETTINGS_DARK_KNIGHT,
		ePARTYSETTINGS_ELF,
		ePARTYSETTINGS_MAGIC_GLADIATOR,
		ePARTYSETTINGS_DARK_LORD,
		FormPassLock,//tue add ATM Box
		ePARTYSETTINGS_SUMMONER,
		ePARTYSETTINGS_RAGE_FIGHTER,
		ePARTYSETTINGS_LEVEL_MINUS,
		ePARTYSETTINGS_LEVEL_PLUS,
		ePARTYSETTINGS_OK,
		ePARTYSEARCH_LEFT,
		ePARTYSEARCH_RIGHT,
		ePARTYSEARCH_MAIN,
		ePARTYSEARCH_TITLE,
		ePARTYSEARCH_FRAME,
		ePARTYSEARCH_FOOTER,
		ePARTYSEARCH_DIV,
		ePARTYSEARCH_CLOSE,
		OBJECT_PARTYSETTINGS_PASSWORD,
	OBJECT_PARTYSEARCH_IMAGE1,
	OBJECT_PARTYSEARCH_IMAGE2,
	OBJECT_PARTYPASSWORD_MAIN,
	OBJECT_PARTYPASSWORD_TITLE,
	//tue add ATM BOX
		eRESETSTATS_MAIN,
		eRESETSTATS_TITLE,
		eRESETSTATS_FRAME,
		eRESETSTATS_FOOTER,
		eRESETSTATS_CLOSE,
		eRESETSTATS_POINT,
		eRESETSTATS_BTN_OK,
    //-------------
	OBJECT_PARTYPASSWORD_FRAME,
	OBJECT_PARTYPASSWORD_FOOTER,
	OBJECT_PARTYPASSWORD_CLOSE,
	//tue add ATM BOX
#if RELIFE
		SpkRelife_MainBox,
		SpkRelife_CloseBox,
		SpkRelifeButton, // 425 -> 434
#endif
#if NEWXSHOP
		eCustomShop = 435,
		eWindowMessageBox,
		eCustomShop_CLOSE,
#endif
		eWindowMocNap,
		eWindowMocNapList,
		eWindowMocNapClose,
		eWindowIntros,
		eWindowIntrosList,
		eWindowIntrosClose,
		eWindowInfo,
		eWindowInfoClose,
		eWindowHarmony,
		eWindowDungLuyenItem,
		Arena_CLOSE,
		Option_Main,
    //-----
	OBJECT_PARTYPASSWORD_TEXTBOX,
	OBJECT_PARTYPASSWORD_OK,
	OBJECT_PARTYPASSWORD_REFRESH,
	OBJECT_PARTYPASSWORD_RESETTING,

	//---------------------------------------------------------------------
#if(MENU_NEW)
	eMENU_MAIN,
	eMENU_CLOSE,
	eBUTTON_MENU_1,
	eBUTTON_MENU_2,
	eBUTTON_MENU_3,
	eBUTTON_MENU_4,
	eBUTTON_MENU_5,
	eBUTTON_MENU_6,
	eBUTTON_MENU_7,
	eBUTTON_MENU_8,
	eBUTTON_MENU_9,
	eBUTTON_MENU_10,
	eBUTTON_MENU_11,
	eBUTTON_MENU_12,
	eBUTTON_MENU_13,
	eBUTTON_MENU_14,
	eBUTTON_MENU_15,
	eBUTTON_MENU_16,
	eBUTTON_MENU_17,
	eBUTTON_MENU_18,
	eBUTTON_MENU_19,
	eBUTTON_MENU_20,
	eBUTTON_MENU_21,
	eBUTTON_MENU_22,
#endif

#if(VONGQUAY_NEW)
	eLuckySpin,
	eLuckySpinRoll,
	eLuckySpinClose,
#endif
	 
	EXBEXO_THUONG_GIA_MAIN,
	EXBEXO_THUONG_GIA_CLOSE,
	eTHUONG_GIA1,
	eTHUONG_GIA2,
	//eWindowInfo, // tue add ATM box
	eTHUONG_GIA3,

	eTHUONGGIA_01,
	eTHUONGGIA_02,
	eTHUONGGIA_03,

	EXBEXO_HE_THONG_MAIN,
	EXBEXO_HE_THONG_CLOSE,
	//tue add bau cua
		SPK_Ranking_Main,
#if(BAUCUA)
		BAUCUA_MAIN,
		BAUCUA_TITLE,
		BAUCUA_FRAME,
		BAUCUA_FOOTER,
		BAUCUA_CLOSE,
		BAUCUA_TEXTBOX01,
		BAUCUA_STATBOX01,
		BAUCUA_STATBOX02,
		BAUCUA_STATBOX03,
		BAUCUA_STATBOX04,
		BAUCUA_STATBOX05,
		BAUCUA_STATBOX06,
		BAUCUA_LOAITIENTE01,
		BAUCUA_LOAITIENTE02,
		BAUCUA_LOAITIENTE03,
		BAUCUA_LOAITIENTE04,
		BAUCUA_LOAITIENTE05,
		BAUCUA_LOAITIENTE06,
		BAUCUA_BTN_OK,
		BAUCUA_WC,
		BAUCUA_WP,
		BAUCUA_B,
		BAUCUA_S,
		BAUCUA_L,
		BAUCUA_C,
		BAUCUA_Bau,
		BAUCUA_Cua,
		BAUCUA_Tom,
		BAUCUA_Ca,
		BAUCUA_Ga,
		BAUCUA_Nai,
#endif
		//----
	//tue add ATM box
			SPK_Ranking_BtnClose,
			SPK_Comment_BtnClose,
			SPK_TuChan_BtnClose,
			SPK_DanhHieu_BtnClose,
			SPK_QuanHam_BtnClose,
			SPK_HonHoan_BtnClose,
			SPK_ThueFlag_BtnClose,
			SPK_Relife_BtnClose,
			SPK_LSpin_BtnClose,
			SPK_MocNap_BtnClose,
			SPK_CuaHang_BtnClose,
			SPK_RsChange_BtnClose,
			SPK_NewVip_BtnClose,
			SPK_Harmony_BtnClose,
			SPK_ItemTrade_BtnClose,
			SPK_BoxAtm_BtnClose,
			SPK_EventTime_BtnClose,
			SPK_DungLuyen_BtnClose,
			SPK_BxhArena_BtnClose,
			SPK_Option_BtnClose,
			TUE_VONGQUAY_BtnClose,
	//-----

	eHE_THONG1,
	eHE_THONG2,
	eHE_THONG3,
	eHE_THONG4,
	eHE_THONG5,
	eHE_THONG6,
	eHE_THONG7,
	eHE_THONG8,
	eHE_THONG9,
	eHE_THONG10,
	eHE_THONG11,
	eHE_THONG12,
	eHE_THONG13,
	
	eVIPTAIKHOAN_SEND_01,
	eVIPTAIKHOAN_SEND_03,
	eVIPTAIKHOAN_SEND_07,

	eVIPNHANVAT_SEND_01,
	eVIPNHANVAT_SEND_02,
	eVIPNHANVAT_SEND_03,
	eVIPNHANVAT_SEND_04,
	eVip_MAIN,

	eDANHHIEU2,
	eDANHHIEU3,
	eDANHHIEU4,
	eDANHHIEU5,
	eDANHHIEU6,
	eDANHHIEU7,
	eDANHHIEU8,
	eDANHHIEU9,
	eDANHHIEU10,
	eDANHHIEU11,
	eDANHHIEU12,
	eDANHHIEU13,

	eQUANHAM9,
	eQUANHAM10,
	eQUANHAM11,
	eQUANHAM12,
	eQUANHAM13,
	eQUANHAM14,
	eQUANHAM15,
	eQUANHAM16,
	eQUANHAM17,
	eQUANHAM18,
	eQUANHAM19,
	eQUANHAM20,

	eTULUYEN,

	eKINHMACH1,
	eKINHMACH2,
	eKINHMACH3,
	eKINHMACH4,
	eKINHMACH5,
	eKINHMACH6,
	eKINHMACH7,
	eKINHMACH8,

	eNGUHANH,

	eCheck,
	eUnCheck,

	RAGE_1,
	RAGE_2,
	RAGE_3,
	RAGE_4,
	RAGE_5,
	RAGE_6,
	RAGE_7,
	RAGE_8,
	RAGE_9,
	RAGE_10,
	RAGE_11,
	RAGE_12,
	RAGE_13,
	RAGE_14,
	RAGE_15,
	RAGE_16,
	RAGE_17,
	RAGE_18,
	RAGE_19,
	RAGE_20,
	RAGE_21,
	RAGE_22,
	RAGE_23,
	RAGE_24,
	RAGE_25,
	RAGE_26,
	RAGE_27,
	RAGE_28,
	RAGE_29,
	RAGE_30,

#if(CHARACTER_NEW)
	XOAHOMDO_CHARACTER,
	TINHNANG_CHARACTER,
	RINGPEDAN_CHARACTER,
#endif

	XOAHOMDO_MAIN,
	TINHNANG_MAIN,
	RINGPEDAN_MAIN,

	eAUTORESET,
	eATTACK,

	BUTTON_YES,
	BUTTON_NO,

	BUTTON_YES1,
	BUTTON_NO1,
	BUTTON_YES2,
	BUTTON_NO2,
	BUTTON_YES3,
	BUTTON_NO3,
	BUTTON_YES4,
	BUTTON_NO4,
	BUTTON_YES5,
	BUTTON_NO5,

	eClickViewDame,
	eDameGray,
	CheckeDameColor,
	eDameColor,
	//---------------------------------------------------------------------

#if(OFFLINE_MODE_NEW)
	eOFFEXP_MAIN,
	eOFFEXP_TITLE,
	eOFFEXP_FRAME,
	eOFFEXP_FOOTER,
	eOFFEXP_DIV,
	eOFFEXP_CLOSE,
	eOFFEXP_POINT,
	eOFFEXP_CHECKBOX_BUFF,
	eOFFEXP_CHECKBOX_PICK_ZEN,
	eOFFEXP_CHECKBOX_PICK_JEWELS,
	eOFFEXP_CHECKBOX_PICK_EXC,
	eOFFEXP_CHECKBOX_PICK_ANC,
	eOFFEXP_CHECKBOX_SELECTED_HELPER,
	eOFFEXP_BTN_OK,

	eOFFEXP_SKILL1,
	eOFFEXP_SKILL2,
	eOFFEXP_SKILL3,
#endif

	//---------------------------------------------------------------------
#if(SACHTHUOCTINH_NEW)
	eSACHTHUOCTINH_INTERFACE,
	eSACHTHUOCTINH_MAIN,
	eSACHTHUOCTINH_02,
	eSACHTHUOCTINH_03,
	eSACHTHUOCTINH_04,
	eSACHTHUOCTINH_05,
	eSACHTHUOCTINH_06,
	eSACHTHUOCTINH_07,
#endif
	//-------------------------------------------------------------------
#if(RINGPEDAN_NEW)
	ePEDAN_01_INTERFACE,
	ePEDAN_02_INTERFACE,
	eRING_01_INTERFACE,
	eRING_02_INTERFACE,

	eSEND_PEDAN_01_INTERFACE,
	eSEND_PEDAN_02_INTERFACE,
	eSEND_RING_01_INTERFACE,
	eSEND_RING_02_INTERFACE,

#endif
	//-------------------------------------------------------------------
	//**********************************************************************//
#if(EXBEXO_LOAD_TIME_EVENT)
	eEVENTTABLE_MOVE_01,
	eEVENTTABLE_MOVE_02,
	eEVENTTABLE_MOVE_03,
	eEVENTTABLE_MOVE_04,
	eEVENTTABLE_MOVE_05,
	eEVENTTABLE_MOVE_06,
	eEVENTTABLE_MOVE_07,
	eEVENTTABLE_MOVE_08,
	eEVENTTABLE_MOVE_09,
	eEVENTTABLE_MOVE_10,
	eEVENTTABLE_MOVE_11,
	eEVENTTABLE_MOVE_12,
	eEVENTTABLE_MOVE_13,
	eEVENTTABLE_MOVE_14,
	eEVENTTABLE_MOVE_15,
	eEVENTTABLE_MOVE_16,
	eEVENTTABLE_MOVE_17,
	eEVENTTABLE_MOVE_18,
	eEVENTTABLE_MOVE_19,
	eEVENTTABLE_MOVE_20,
	eEVENTTABLE_MOVE_21,
	eEVENTTABLE_MOVE_22,
	eEVENTTABLE_MOVE_23,
	eEVENTTABLE_MOVE_24,
	eEVENTTABLE_MOVE_25,
	eEVENTTABLE_MOVE_26,
#endif
	eToolTip_ID,
	//**********************************************************************//
	#if (SELECTCHARACTER==1)
		eSELECTCHAR_LEFT,
		eSELECTCHAR_RIGHT,
	#endif
#if(THANMA)
		//===Than Ma Chien
     eWindowNPC_ThanMaChien,
     eWindowBXH_ThanMaChien,
#endif
		////bank
		eJewelBank_MAIN,
		eJewelBank_TITLE,
		eJewelBank_FRAME,
		eJewelBank_FOOTER,
		eJewelBank_DIV,
		eJewelBank_CLOSE,
		eJewelBank_NEXT,
		eJewelBank_PREV,
		eJewelBank_WITHDRAW, 
		
};

//========================================================================================================================================
// Advanced Stats
//========================================================================================================================================
enum ObjWindowsEx
{
	exWinNews = 1,
	exWinReset = 2,
	exWinGrandReset = 3,
	exWinRanking = 4,
	exWinDonate = 5,
	exWinPremium = 6,
	exWinMiniMenu = 7,
	exWinSettings = 8,
	exWinPTSearchMaster = 9,
	exWinPTSearchUser = 10,
	exWinPersonalSearch = 12,
	exWinPersonalPrice = 13,
	exWinNPCBuffer,
	exWinSmithy,
	exWinSmithyCheck,
	exWinCheckOffAfk,
	exWinMarriage,
	exWinAddPoints,
	exWinAddResetPoint,
	exWinCustomMenu,
	exWinCustomMenuChangeClass,
	exWinDungeonSiege,
	exWinTeamVsTeam,
	exWinTeamVsTeamStatistic,
	exWinAchievements,
	exWinAchievementsPower,
	exWinTeleport,
	exWinTeleportEvo,
	exWinResetRage,
	exWinDonateCheck,
	exWinPKClear,
	exWinAccWarning,
	exWinAccMenu,
	exWinAccOption,
	exWinAccPC,
	exWinAccMessage,
	exWinAccNumber,
	exWinReferralMenu,
	exWinReferralSystem,
	exWinReferralSystem2,
	exWinQuest,
	exWinLottery,
	exWinItemMarket,
	exWinItemMarket2,
	exWinMenuV3,
	exWinStatsAdvance,
};

struct InterfaceElement
{
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
	long	OpenedValue;
	BYTE	Speed;
	char	StatValue[20];
	bool	ByClose;
	bool	FirstLoad;
	//tue add atm box
	float  curX;
	float	curY;
	bool	Hover;
	//--
	void Open()
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->ByClose = false;
	};

	void Open(int Value, int Speed)
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
		this->FirstLoad = true;
	};

	void Close()
	{
		this->OnShow = false;
		pSetCursorFocus = false;
		this->ByClose = false;
	};

	void Close(int Value, int Speed)
	{
		this->OnShow = false; pSetCursorFocus = false;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
	}

	void CloseAnimated(int Speed)
	{
		pSetCursorFocus = false;
		//this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = true;
	}

	bool Check()
	{
		return this->OnShow;
	}
};


struct NewUISlot
{
	int DirTexture;
	int DirPathX;
	int DirPathY;
	int DirPathW;
	int DirPathH;
	int Target;
	int draggable;
	void * ItemStrl;
};


struct BUY_TINH_NANG_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

struct PMSG_TINHNANG_UPD
{
	PSBMSG_HEAD	h;
	int  rResetLife;
	int CommandResetPoint_WCoinC;
	int CommandResetMaster_WCoinC;
	int CommandChange_WCoinC;
	int CommandRelife_Check_Level;
	int CommandRelife_Check_Reset;
	int CommandRelife_Point;
	int CommandRelife_MaxClient;
};

//--------------------------------------

struct SACHTHUOCTINH_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

//--------------------------------------

struct BUY_RINGPEDAN_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};

//--------------------------------------
struct MOVE_EVENT_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
//--------------------------------------
//======================================================

struct PMSG_THUOCTINH_UPD
{
	PSBMSG_HEAD	h;
	int SachThuocTinh_02;
	int SachThuocTinh_03;
	int SachThuocTinh_04;
	int SachThuocTinh_05;
	int SachThuocTinh_06;
	int SachThuocTinh_07;
};

struct PMSG_THUOCTINH_ATIVE_UPD
{
	PSBMSG_HEAD	h;
	int OPTION_LEVEL_01;
	int OPTION_LEVEL_02;
	int OPTION_LEVEL_03;
	int OPTION_LEVEL_04;
	int OPTION_LEVEL_05;
	int OPTION_LEVEL_06;
	int OPTION_LEVEL_07;
	int OPTION_LEVEL_08;
	int OPTION_LEVEL_09;
	int OPTION_LEVEL_10;
	int OPTION_LEVEL_11;
	int OPTION_LEVEL_12;
	int OPTION_ACTIVE_01;
	int OPTION_ACTIVE_02;
	int OPTION_ACTIVE_03;
	int OPTION_ACTIVE_04;
	int OPTION_ACTIVE_05;
	int OPTION_ACTIVE_06;
	int OPTION_ACTIVE_07;
	int OPTION_ACTIVE_08;
	int OPTION_ACTIVE_09;
	int OPTION_ACTIVE_10;
	int OPTION_ACTIVE_11;
	int OPTION_ACTIVE_12;
};

//======================================================

struct PMSG_RINGPEDAN_UPD
{
	PSBMSG_HEAD	h;
	int SachThuocTinh_01;
	int RingPedan1;
	int RingPedan2;
	int RingPedan3;
	int RingPedan4;
	int AutoResetEnable;
	int AttackCustom;
	int GHRS;
	int Money;
	int DanhHieu;
	int QuanHam;
};


//======================================================
struct PMSG_TVTEVENT_UPD
{
	PSBMSG_HEAD	h;
	int ScoreRed;
	int ScoreBlue;
	int KillCount;
	int DieCount;
	int TotalPlayer;
};
//======================================================

class Interface
{
public:
	float		VariableInterfazON;
	float		RightMiniInfoY;
	int ConfirmSlot;
	float PetY;
	float PetX;
	int lastReport;
	int frameCount;
	int frameRate;
	char FPS_REAL[30];
	void UPDATE_FPS();
	void guiMonitore();
	int iniciador;
	int msPing;
	int lastSend;
	int validar;
	char ServerPing[50];
	char ultimoPing[50];
	int ultimo_Ping;
	char ServerRTT[50];
	char ultimoRTT[50];
	int ultimo_RTT;
	InterfaceElement Data[MAX_OBJECT];
public:
	Interface();
	virtual ~Interface();
	void RenderObjectSystem();
	void RenderObjectSystem2();
	static void LoadImages();
	static void LoadModels();
	static void Work();

//--
	#if(DEV_DAMAGE_TABLE)
	bool m_EnableDamageTable;
	void DrawDamageTable();
	#endif
	bool QuayLai;
	/////////////////////////////
	//--------------------------------------
	void TvTEventEx(PMSG_TVTEVENT_UPD * aRecv);
	int m_ScoreRed;
	int m_ScoreBlue;
	int m_KillCount;
	int m_DieCount;
	int m_TotalPlayer;
	//--------------------------------------
#if(SACHTHUOCTINH_NEW)
	void BUG_SACHTHUOCTINH(int Number);
#endif
	//--------------------------------------
#if(RINGPEDAN_NEW)
	void BUG_RINGPEDAN(int Number);
#endif
	//--------------------------------------
	//-----------------------------
	void GetInfoThuocTinh(PMSG_THUOCTINH_UPD * aRecv);
	int m_SachThuocTinh_01;
	int m_SachThuocTinh_02;
	int m_SachThuocTinh_03;
	int m_SachThuocTinh_04;
	int m_SachThuocTinh_05;
	int m_SachThuocTinh_06;
	int m_SachThuocTinh_07;

	void GetInfoThuocTinhAtive(PMSG_THUOCTINH_ATIVE_UPD * aRecv);
	int m_OPTION_LEVEL_01;
	int m_OPTION_LEVEL_02;
	int m_OPTION_LEVEL_03;
	int m_OPTION_LEVEL_04;
	int m_OPTION_LEVEL_05;
	int m_OPTION_LEVEL_06;
	int m_OPTION_LEVEL_07;
	int m_OPTION_LEVEL_08;
	int m_OPTION_LEVEL_09;
	int m_OPTION_LEVEL_10;
	int m_OPTION_LEVEL_11;
	int m_OPTION_LEVEL_12;
	int m_OPTION_ACTIVE_01;
	int m_OPTION_ACTIVE_02;
	int m_OPTION_ACTIVE_03;
	int m_OPTION_ACTIVE_04;
	int m_OPTION_ACTIVE_05;
	int m_OPTION_ACTIVE_06;
	int m_OPTION_ACTIVE_07;
	int m_OPTION_ACTIVE_08;
	int m_OPTION_ACTIVE_09;
	int m_OPTION_ACTIVE_10;
	int m_OPTION_ACTIVE_11;
	int m_OPTION_ACTIVE_12;
	//-----------------------------
	//tue add
	void DrawShowIcon();
	int TimeInterface;
	void DrawTimeUI();
	//tue add ATM Box
	bool SPKEventClick(DWORD Event);
	/////
	//tue add Tu Chan ////
	int SPKText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	/////////////////
	bool HandleCloseEvent(DWORD Event, int btnCloseID, int windowID);
	bool SPK_DrawMenu_Close(DWORD Event);
	bool SPK_CtcMini_Close(DWORD Event);
	bool SPK_Ranking_Close(DWORD Event);
	bool SPK_Comment_Close(DWORD Event);
	bool SPK_TuChan_Close(DWORD Event);
	bool SPK_DanhHieu_Close(DWORD Event);
	bool SPK_QuanHam_Close(DWORD Event);
	bool SPK_HonHoan_Close(DWORD Event);
	bool SPK_ThueFlag_Close(DWORD Event);
	bool SPK_Relife_Close(DWORD Event);
	bool SPK_LSpin_Close(DWORD Event);
	bool SPK_MocNap_Close(DWORD Event);
	bool SPK_CuaHang_Close(DWORD Event);
	bool SPK_RsChange_Close(DWORD Event);
	bool SPK_NewVip_Close(DWORD Event);
	bool SPK_Harmony_Close(DWORD Event);
	bool SPK_ItemTrade_Close(DWORD Event);
	bool SPK_Arena_Close(DWORD Event);
	bool SPK_BoxAtm_Close(DWORD Event);
	//tue add VOng Quay
	bool TUE_VONGQUAY_Close(DWORD Event);
	/// 
	bool SPK_EventTime_Close(DWORD Event);
	bool SPK_DungLuyen_Close(DWORD Event);
	bool SPK_Option_Close(DWORD Event);
	bool SPK_BxhArena_Close(DWORD Event);

	//void DrawMenuOpen();

	//bool SPKEventClick(DWORD Event);

	void CloseEventTimeWindow() { this->Data[eEventTimePANEL_MAIN].OnShow = false; }

	//void DrawConfirmOpen();
	//bool EventConfirm_OK(DWORD Event);
	//bool EventConfirm_CANCEL(DWORD Event);
	bool SPK_ResetAuto(DWORD Event);
	bool SPK_BomMauAuto(DWORD Event);
	bool SPK_BuffAuto(DWORD Event);
	bool SPK_Camera3D(DWORD Event);
	bool SPK_RsCamera3D(DWORD Event);
	bool SPK_OpenBoxAtm(DWORD Event);
	void SPK_OpenVongQuay(DWORD Event);
	bool SPK_OpenBoxBSK(DWORD Event);
	bool SPK_OpenBoxCfg(DWORD Event);
	bool SPK_ItemBlock(DWORD Event);
	bool SPK_Pklock(DWORD Event);
	//
	void CloseMenuWindow() { 
		this->Data[eMenu_MAIN].OnShow = false; 
	//tue add Vong Quay
		//this->Data[eLuckySpin].OnShow = false;
	// --	
	};
	//end add ------------------------------


	void GetInfoRingPedan(PMSG_RINGPEDAN_UPD * aRecv);
	int m_RingPedan1;
	int m_RingPedan2;
	int m_RingPedan3;
	int m_RingPedan4;

	int m_AutoResetEnable;
	int m_AttackCustom;
	int m_GHRS;
	int m_Money;
	int m_DanhHieu;
	int m_QuanHam;
	int m_VuKhiRong;
	//tue add tu chan
	int m_TuLuyen;
	//


	//-----------------------------
	//---------------------------------------------------------------------------------------
#if(MENU_NEW)
	void		DrawMenuWindow();
	void		EventMenuWindow(DWORD Event);
	void		EventMenuWindow_Close(DWORD Event);
	//----------------------------------------------------------------
	void		SwitchMenuWindowState() { (Data[eMENU_MAIN].OnShow == true) ? Data[eMENU_MAIN].CloseAnimated(15) : Data[eMENU_MAIN].Open(-226, 20); };
	void		OPEN_MENU() { Data[eMENU_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_MENU() { Data[eMENU_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_MENU() { return Data[eMENU_MAIN].OnShow; };
#endif

	void BUY_QUEST(int Number);
	void BUY_TINH_NANG_GAME(int Number);
	void MOVE_EVENT_GAME(int Number);


	void GetInfoTinhNang(PMSG_TINHNANG_UPD * aRecv);

	int m_rResetLife;
	int m_CommandResetPoint_WCoinC;
	int m_CommandResetMaster_WCoinC;
	int m_CommandChange_WCoinC;
	int m_CommandRelife_Check_Level;
	int m_CommandRelife_Check_Reset;
	int m_CommandRelife_Point;
	int m_CommandRelife_MaxClient;

#if(CHARACTER_NEW)
	void		DrawCharacterWindow();
	bool		EventCharacterWindow_XoaHomDo(DWORD Event);
	bool		EventCharacterWindow_TinhNang(DWORD Event);
	//bool		EventCharacterWindow_RingPedan(DWORD Event);
	//-----
	void		DrawXoaHomDoWinDow();
	void	    OpenXoaHomDoWindow() { this->Data[XOAHOMDO_MAIN].OnShow = true; };
	void	    CloseXoaHomDoWindow() { this->Data[XOAHOMDO_MAIN].OnShow = false; };
	bool	    CheckXoaHomDoWindow() { return this->Data[XOAHOMDO_MAIN].OnShow; };
	bool		EventXoaHomDoWinDow(DWORD Event);
	//-----
	void		DrawTinhNangWinDow();
	void	    OpenTinhNangWindow() { this->Data[TINHNANG_MAIN].OnShow = true; };
	void	    CloseTinhNangWindow() { this->Data[TINHNANG_MAIN].OnShow = false; };
	bool	    CheckTinhNangWindow() { return this->Data[TINHNANG_MAIN].OnShow; };
	bool		EventTinhNangWinDow(DWORD Event);
	//-----
	void DrawAutoReset();
	void DrawAttack();
	bool		EventDrawAutoReset_Open(DWORD Event);
	bool		EventDrawAttack_Open(DWORD Event);

#endif

	//---------------------------------------------------------------------------------------
#if(SACHTHUOCTINH_NEW)
	void		DrawSachThuocTinhInterface();
	bool		EventSachThuocTinhInterface(DWORD Event);

	void		DrawSachThuocTinh();
	void	    OpenSachThuocTinhWindow() { this->Data[eSACHTHUOCTINH_MAIN].OnShow = true; };
	void	    CloseSachThuocTinhWindow() { this->Data[eSACHTHUOCTINH_MAIN].OnShow = false; };
	bool	    CheckSachThuocTinhWindow() { return this->Data[eSACHTHUOCTINH_MAIN].OnShow; };

	bool		EventSachThuocTinh(DWORD Event);

#endif

	//---------------------------------------------------------------------------------------
#if(RINGPEDAN_NEW)

	//-----
	void		DrawRingPedanWinDow();
	void	    OpenRingPedanWindow() { this->Data[RINGPEDAN_MAIN].OnShow = true; };
	void	    CloseRingPedanWindow() { this->Data[RINGPEDAN_MAIN].OnShow = false; };
	bool	    CheckRingPedanWindow() { return this->Data[RINGPEDAN_MAIN].OnShow; };
	//-----
	bool		EventRingPedanInterface(DWORD Event);
#endif

	//=====================================================================================
	
	//=====================================================================================
#if(EXBEXO_LOAD_TIME_EVENT)

	void		DrawEventTimeWindow();
	bool		EventEventTimeWindow_Move_01(DWORD Event);
	bool		EventEventTimeWindow_Move_02(DWORD Event);
	bool		EventEventTimeWindow_Move_03(DWORD Event);
	bool		EventEventTimeWindow_Move_04(DWORD Event);
	bool		EventEventTimeWindow_Move_05(DWORD Event);
	bool		EventEventTimeWindow_Move_06(DWORD Event);
	bool		EventEventTimeWindow_Move_07(DWORD Event);
	bool		EventEventTimeWindow_Move_08(DWORD Event);
	bool		EventEventTimeWindow_Move_09(DWORD Event);
	bool		EventEventTimeWindow_Move_10(DWORD Event);
	bool		EventEventTimeWindow_Move_11(DWORD Event);
	bool		EventEventTimeWindow_Move_12(DWORD Event);
	bool		EventEventTimeWindow_Move_13(DWORD Event);
	bool		EventEventTimeWindow_Move_14(DWORD Event);
	bool		EventEventTimeWindow_Move_15(DWORD Event);
	bool		EventEventTimeWindow_Move_16(DWORD Event);
	bool		EventEventTimeWindow_Move_17(DWORD Event);
	bool		EventEventTimeWindow_Move_18(DWORD Event);
	bool		EventEventTimeWindow_Move_19(DWORD Event);
	bool		EventEventTimeWindow_Move_20(DWORD Event);
	bool		EventEventTimeWindow_Move_21(DWORD Event);
	bool		EventEventTimeWindow_Move_22(DWORD Event);
	bool		EventEventTimeWindow_Move_23(DWORD Event);
	bool		EventEventTimeWindow_Move_24(DWORD Event);
	bool		EventEventTimeWindow_Move_25(DWORD Event);
	bool		EventEventTimeWindow_Move_26(DWORD Event);
#endif
	#if(OANTUTY)
	void		DrawRPS();
	void		EventRPS_Main(DWORD Event);
#endif
#if(OFFLINE_MODE_NEW)
	void		DrawOffExpWindow();
	bool		EventOffExpWindow_Main(DWORD Event);
	void		SwitchOffExpWindoState() { (Data[eOFFEXP_MAIN].OnShow == true) ? Data[eOFFEXP_MAIN].Close() : gOfflineMode.CGOfflineModeSend(); };
#endif
#if(OFFLINE_MODE_NEW >1  )
	bool		IsWorkZone4(float X, float Y, float MaxX, float MaxY);
	int			DrawToolTipEx4(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...);
	void		DrawColoredButton4(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color);
#endif
	//=====================================================================================
	//=====================================================================================
	//--
	void DrawMenu();
	bool EventDrawMenu_Open(DWORD Event);
	//--
	void DrawConfirmOpen();
	bool EventConfirm_OK(DWORD Event);
	bool EventConfirm_CANCEL(DWORD Event);
	void        WindowsKG();
	void DrawTextTTTTTT();
//	bool		CheckWindowEx(int WindowID);
//	void		OpenWindowEx(int WindowID);
//	void		CloseWindowEx(int WindowID);
//-- Funtions
	void BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	void DrawGUI(short ObjectID, float PosX, float PosY);
	void DrawGUI2(short ObjectID, float PosX, float PosY);
	void DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	//void DrawTimeUI();
	int DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void ResetDrawIMG(short ObjectID);
	int DrawMessage(int Mode, LPCSTR Text, ...);
	void DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
#if(VONGQUAY_NEW)
	static void DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	static bool DrawItem3(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, char ScaleUp, float ScaleX = 1.0f, float ScaleY = 1.0f);
	
#endif
	bool CheckWindow(int WindowID);
	int CloseWindow(int WindowID);
	int OpenWindow(int WindowID);
	bool IsWorkZone2(float X, float Y, float MaxX, float MaxY);
	bool IsWorkZone3(float X, float Y, float MaxX, float MaxY, bool a5 = false);
	bool IsWorkZone5(float X, float Y, float MaxX, float MaxY,bool f=true);
	bool IsWorkZone(short ObjectID);
	float GetResizeX(short ObjectID);
	int DrawToolTip(int X, int Y, LPCSTR Text, ...);
	float DrawRepeatGUI(short MonsterID, float X, float Y, int Count);
	float DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count);
	void DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color);
	void DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawLogo(bool active);
	void CloseCustomWindow();
	//Mini Map
	void DrawMiniMap();
	bool MiniMapCheck();
	bool CombinedChecks();
	bool CheckMap();
	void SwitchMiniMap();
	// ex700
	void DrawInterfaceCustom();
	// s2
	void DrawInterfaceS2Menu();
	void DrawInterface97Menu();
	void EventNewInterface_All(DWORD Event);
	void EventNewInterface97_All(DWORD Event);
	void DrawCoord();
	void DrawInterfaceDragonLS3();
	void DrawInterfaceDragonRS3();
	// Advanced Stats
	bool WindowEx[MAX_WINDOW_EX];
	bool CheckWindowEx(int WindowID);
	void DrawBarForm(float PosX,float PosY,float Width,float Height,GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	//--
	void OpenConfig(int type);
	void SwitchCamera();
	void SwitchChatExpand();
	void CameraInit();
	bool Button(DWORD Event, int WinID, int ButtonID, bool Type);
	void DrawPing();
	void SendPingRecv();

	static void DrawZenAndRud(int a1, int a2, int a3, int a4);
	void		DrawWarehouseUI();
	void NewLoadInterface();
	void		EventWarehouseUI(DWORD Event);
	// ----
	void		DrawWarehouseWindow();
	void		EventWarehouseWindow_Main(DWORD Event);
	void		EventWarehouseWindow_Close(DWORD Event);
	// ----
	void		DrawStatsAddWindow();
	void		EventStatsAddWindow(DWORD Event);
	void		EventStatsAddWindow_Close(DWORD Event);
	void		SwitchStatsWindowState() { (Data[eSTATSADD_MAIN].OnShow == true) ? Data[eSTATSADD_MAIN].CloseAnimated(15) : Data[eSTATSADD_MAIN].Open(-226, 20); };
	// ----
	void		DrawChangingClassWindow();
	bool		EventChangingClassWindow_Main(DWORD Event);
	bool		EventChangingClassWindow_Close(DWORD Event);
	bool		EventChangingClassWindow_DW(DWORD Event);
	bool		EventChangingClassWindow_DK(DWORD Event);
	bool		EventChangingClassWindow_ELF(DWORD Event);
	bool		EventChangingClassWindow_MG(DWORD Event);
	bool		EventChangingClassWindow_DL(DWORD Event);
	bool		EventChangingClassWindow_SUM(DWORD Event);
	bool		EventChangingClassWindow_RF(DWORD Event);
	// ----
	BOOL        is_auto;
	BOOL        is_autotron;
	// ----
	bool		ControlTextBox(KBDLLHOOKSTRUCT Hook);
	void		EventCharacterWindow(DWORD Event);
	
	void		DrawAnimatedGUI(short ObjectID, float X, float Y);
	void		DrawAnimatedButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void		DrawColoredAnimatedGUI(short ObjectID, float X, float Y, DWORD Color);
	void		DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color);
	int			DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...);
	void		DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	bool		ButtonEx(DWORD Event, int ButtonID, bool Type);
	void		DrawMessageBox(LPCSTR Text, ...);
	//-- Party Bar ex700
	void		BarPartyNew();
	//-- Minimizar MiniMapa
	void		MiniMapMini();
	//////CTCmini//////////
	void		DrawCTCMiNiMap();
	void		DrawCTCMiniWindow();
#if(CHIEN_TRUONG_CO)
	void		DrawChienTruongCo();
	void		DrawTimeCTC();
#endif
	//////////////
	void	    TvTEvent();

	void		DrawTiecRuouWindow();
	bool		EventTiecRuouWindow_Main(DWORD Event);
	bool		EventTiecRuouWindow_Close(DWORD Event);
	bool		EventTiecRuouWindow_All(DWORD Event);
	void		DrawEventTiecRuou();
	void		DrawMoiRuouWindow();
	bool		EventMoiRuouWindow_Main(DWORD Event);
	bool		EventMoiRuouWindow_Close(DWORD Event);
	bool		EventMoiRuouWindow_Zen(DWORD Event);
	bool		EventMoiRuouWindow_WC(DWORD Event);

#if(LEOTHAP == 1)
	// Leo thap
	void		DrawLeoThap();
	bool		EventLeoThap_Main(DWORD Event);
	bool		EventLeoThap_Close(DWORD Event);
	bool		EventLeoThap_All(DWORD Event);
#endif

#if(BOSS_GUILD == 1)
	void		DrawBossGuildWindow();
	void		DrawBossGuildMap();
#endif
	//-- Mover MiniMapa
	bool		IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5 = false);
	void SwitchFenrir();

	void HideNameinCC();
	static void DrawBuffColor(int a1, int a2, int a3, int a4);
	bool IsWorkZone4(short ObjectID,float X, float Y, float MaxX, float MaxY);
#if (THANMA)
		//=== Event Chien Truong Than Ma
	void DrawTMAllWindows();
	int	m_EventTMTimeCount;
	int m_EventTMState;
	int m_EventTMMap;
	int mCalcTimeEventTick;
	int m_TMScoreThienThan;
	int m_TMScoreAcQuy;
	int m_TMChienBXHC;
	EVENTHANMA_BXH m_ThanMaChienBXH[10];
	void TMReset() // OK
	{
		this->m_TMChienBXHC = 0;
		this->m_TMScoreThienThan = 0;
		this->m_TMScoreAcQuy = 0;
		this->mCalcTimeEventTick = 0;
		this->m_EventTMTimeCount = 0;
	}
#endif

	void Interface::OpenConfig2(int type);
};

void InitAllSeason();

extern Interface gInterface;
			///scolltest
