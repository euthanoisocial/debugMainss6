#pragma once

typedef unsigned __int64 QWORD;

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define VERSION	"1.0.0.0"

// System Include
#include <windows.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <winsock2.h>
#include <Mmsystem.h>
#include <time.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "detours.h"
#include <Shellapi.h>
#include <vector>
#include <map>
#include <Windows.h>
#include <algorithm>
#include <winioctl.h>
#include <algorithm>
//--MaxGameInstances Main.exe
#include <tlhelp32.h>
#include <tchar.h>
#include <windef.h>
#include <atltime.h>
#include "MVec.h"

#define va_start _crt_va_start
#define va_arg _crt_va_arg
#define va_end _crt_va_end

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"detours.lib")
#pragma comment(lib,"cg.lib")
#pragma comment(lib,"cgGL.lib")
#pragma comment(lib,"wzMUQuiz.lib")
//tue add ATM box
#define MENU_GAME_FILE "./Data/WZen/Message/Messenger.ini"
#define MENU_NOTE_FILE  ".\\data\\Custom\\Notice.ini"
#define MENU_OPTN_FILE  "./Settings.ini"
//------
#define PREMIUN	1
#define MAX_CHAT_TYPE1			10
#define PARTYSEARCH		1

#define MAX_CUSTOM_GLOVES	50
#define MAX_CUSTOM_BOW		50
#define MAX_PET_ITEM		300
#define MAX_CUSTOMCLOAK		20
	
#define MAX_CUSTOM_WING			300
#define MAX_REMAKE_EFFECT		100
#define MAX_CUSTOM_ITEM_INFO	1000
#define MAX_POSITION_ITEM		1000
//--
#define MAX_CUSTOPETEFFECT			2000
#define MAX_DYNAMIC_WING_EFFECT		5000
#define MAX_CUSTOM_WING_EFFECT		5000

#define UPDATE 15
#define LODWORD(h)					((DWORD)(__int64(h) & __int64(0xffffffff)))

#define MENU_NEW                1 // ON
#define VONGQUAY_NEW            1 // ON 
#define NGANHANGNGOC_NEW        1 // ON 
#define ANTIHACK                1 // ON
#define DEV_DAMAGE_TABLE		0 // OFF
#define QUAN_HAM_NEW            1 // ON
#define DANHHIEU_NEW            1 // ON
#define THUE_VIP_NEW	        1 // ON
#define VIP_TAI_KHOAN_NEW	    1 // ON
#define NGU_HANH_NEW            1 // ON
#define CHARACTER_NEW           1 // ON 
#define SACHTHUOCTINH_NEW       1 // ON 
#define RINGPEDAN_NEW           1 // ON 
#define OFFLINE_MODE_NEW	    1 // ON
#define EXBEXO_LOAD_TIME_EVENT  1 // ON
#define OANTUTY                 1 // ON/ OFF 
//tue add
#define BAUCUA					1 //ON
//------
#define ANTI_CRACK_MAIN         1 // ON
#define HIDE                    1 // ON
#define SHOPSEARCH              1 // ON
#define LEOTHAP                 1 // ON
#define SELECTCHARACTER         0 // OFF
#define CHIEN_TRUONG_CO         1 // ON
#define BOSS_GUILD              1 // ON
#define SHOWNAME				1 // ON
#define CUSTOM_FLAGS            1 // OFF
#define MOCNAP                  1 // ON
#define QUAEVENT                1 // ON
#define DANGKYTK                0 // OFF
#define DOIMK                   1 // ON
#define SOIITEM                 1 // ON
#define THANMA                  1 // ON
#define HAISLOTRING             1 // ON
//tue add ATM box
#ifndef TEXTVN_NEW
#define TEXTVN_NEW					1
#endif
#define MAXSIZEMOCNAP			15
//--------------
//tue add Tu Chan ///
#define	SPK_HONHOAN				1
#define SPK_DANHHIEU			1
#define SPK_QUANHAM				1
#define SPK_TUCHAN				1
#define SPK_NEWVIP				1
#define SELECT_CHAR_INFO		1
#define CongHuongV2				1
#define LUC_CHIEN				1
#define BXH_LUCHIEN				1 
#define SPK_DANHHIEU_IMG		1677300
#define MAX_LEVEL_DANH_HIEU		25

#define SPK_QUANHAM_IMG			1677400
#define MAX_LEVEL_QUAN_HAM		20

#define SPK_TULUYEN_IMG			1677500
#define MAX_LEVEL_TU_LUYEN		40

#define SPK_NEWVIP_IMG			1677600
#define MAX_LEVEL_NEW_VIP		5
//tue add hon hoan
#define LevelHH					50
#define MOVE_ITEMBANK_DIR		0 //Trừ trực tiếp vào bank ( DH )
//tue add thue flag
#define HT_THUE_FLAG			1
//////////////////////
enum SPK_RenderFile
{
	BTN_NEX_NEW = 0x7E59,
	BTN_PREV_NEW = 0x7E5A,

	BTN_MENU_OFFSET = 0x17A3C,
	BG_IMG_OFFSET = 0x17A3D,
	MP_IMG_OFFSET = 0x17A40,
	MP_IMG_ENDSET = 0x1C92D,
	HP_IMG_ENDSET = 0x1C92E,
	HP_IMG_GRESET = 0x17A41,
	HP_IMG_REDSET = 0x17A42,
	BG_IMG_HDLSET = 0x17A43,
	BG_IMG_HDRSET = 0x17A44,
	BG_IMG_CHARIC = 0x17A45,

	BG_IMG_PERS = 0x17AEE,
	BG_IMG_NUM2 = 0x17AEF,

	HP_FACER = 0x17AF0,
	HP_FACEB = 0x17AF1,
	HP_MANA = 0x17AF2,
	HP_SDFACE = 0x17AF3,
};
#define	RESETCHANGE				1
#define RELIFE					1
#define NEWXSHOP				1
#define CheckSPK_WINDOWS gInterface.CheckWindow(ObjWindow::CashShop)				|| gInterface.CheckWindow(ObjWindow::FriendList)	|| gInterface.CheckWindow(ObjWindow::MoveList)		|| gInterface.CheckWindow(ObjWindow::Party)				|| gInterface.CheckWindow(ObjWindow::Quest)			|| gInterface.CheckWindow(ObjWindow::NPC_Devin)		|| gInterface.CheckWindow(ObjWindow::Guild)				|| gInterface.CheckWindow(ObjWindow::Trade)			|| gInterface.CheckWindow(ObjWindow::Warehouse)		|| gInterface.CheckWindow(ObjWindow::ChaosBox)			|| gInterface.CheckWindow(ObjWindow::CommandWindow) || gInterface.CheckWindow(ObjWindow::PetInfo)		|| gInterface.CheckWindow(ObjWindow::Shop)				|| gInterface.CheckWindow(ObjWindow::Inventory)		|| gInterface.CheckWindow(ObjWindow::Store)		|| gInterface.CheckWindow(ObjWindow::OtherStore)		|| gInterface.CheckWindow(ObjWindow::Character)		|| gInterface.CheckWindow(ObjWindow::DevilSquare)		|| gInterface.CheckWindow(ObjWindow::BloodCastle)		|| gInterface.CheckWindow(ObjWindow::CreateGuild)	|| gInterface.CheckWindow(ObjWindow::GuardNPC)		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)			|| gInterface.CheckWindow(ObjWindow::GuardNPC2)		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)	|| gInterface.CheckWindow(ObjWindow::IllusionTemple)		|| gInterface.CheckWindow(ObjWindow::HeroList)			|| gInterface.CheckWindow(ObjWindow::ChatWindow)	|| gInterface.CheckWindow(ObjWindow::FastMenu)		|| gInterface.CheckWindow(ObjWindow::Options)			|| gInterface.CheckWindow(ObjWindow::Help)			|| gInterface.CheckWindow(ObjWindow::FastDial)		|| gInterface.CheckWindow(ObjWindow::SkillTree)			|| gInterface.CheckWindow(ObjWindow::GoldenArcher1) || gInterface.CheckWindow(ObjWindow::GoldenArcher2)		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)	|| gInterface.CheckWindow(ObjWindow::NPC_Duel)		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)			|| gInterface.CheckWindow(ObjWindow::CashShop)		|| gInterface.CheckWindow(ObjWindow::Lugard)		|| gInterface.CheckWindow(ObjWindow::QuestList1)		|| gInterface.CheckWindow(ObjWindow::QuestList2)	|| gInterface.CheckWindow(ObjWindow::Jerint)		|| gInterface.CheckWindow(ObjWindow::FullMap)			|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)	|| gInterface.CheckWindow(ObjWindow::GensInfo)		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)			|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)	|| gInterface.CheckWindow(ObjWindow::ExpandInventory)		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)	|| gInterface.CheckWindow(ObjWindow::MuHelper)
#define CheckSPK_WINDOWSX gInterface.CheckWindow(ObjWindow::CashShop)				|| gInterface.CheckWindow(ObjWindow::FriendList)	|| gInterface.CheckWindow(ObjWindow::MoveList)		|| gInterface.CheckWindow(ObjWindow::Party)				|| gInterface.CheckWindow(ObjWindow::Quest)			|| gInterface.CheckWindow(ObjWindow::NPC_Devin)		|| gInterface.CheckWindow(ObjWindow::Guild)				|| gInterface.CheckWindow(ObjWindow::Trade)			|| gInterface.CheckWindow(ObjWindow::Warehouse)		|| gInterface.CheckWindow(ObjWindow::ChaosBox)			|| gInterface.CheckWindow(ObjWindow::CommandWindow) || gInterface.CheckWindow(ObjWindow::PetInfo)		|| gInterface.CheckWindow(ObjWindow::Shop)				|| gInterface.CheckWindow(ObjWindow::Store)		|| gInterface.CheckWindow(ObjWindow::OtherStore)		|| gInterface.CheckWindow(ObjWindow::Character)		|| gInterface.CheckWindow(ObjWindow::DevilSquare)		|| gInterface.CheckWindow(ObjWindow::BloodCastle)		|| gInterface.CheckWindow(ObjWindow::CreateGuild)	|| gInterface.CheckWindow(ObjWindow::GuardNPC)		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)			|| gInterface.CheckWindow(ObjWindow::GuardNPC2)		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)	|| gInterface.CheckWindow(ObjWindow::IllusionTemple)		|| gInterface.CheckWindow(ObjWindow::HeroList)			|| gInterface.CheckWindow(ObjWindow::ChatWindow)	|| gInterface.CheckWindow(ObjWindow::FastMenu)		|| gInterface.CheckWindow(ObjWindow::Options)			|| gInterface.CheckWindow(ObjWindow::Help)			|| gInterface.CheckWindow(ObjWindow::FastDial)		|| gInterface.CheckWindow(ObjWindow::SkillTree)			|| gInterface.CheckWindow(ObjWindow::GoldenArcher1) || gInterface.CheckWindow(ObjWindow::GoldenArcher2)		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)	|| gInterface.CheckWindow(ObjWindow::NPC_Duel)		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)			|| gInterface.CheckWindow(ObjWindow::CashShop)		|| gInterface.CheckWindow(ObjWindow::Lugard)		|| gInterface.CheckWindow(ObjWindow::QuestList1)		|| gInterface.CheckWindow(ObjWindow::QuestList2)	|| gInterface.CheckWindow(ObjWindow::Jerint)		|| gInterface.CheckWindow(ObjWindow::FullMap)			|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)	|| gInterface.CheckWindow(ObjWindow::GensInfo)		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)			|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)	|| gInterface.CheckWindow(ObjWindow::ExpandInventory)		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)	|| gInterface.CheckWindow(ObjWindow::MuHelper)
#define CheckSPK_WINDOWS2 gInterface.CheckWindow(CashShop)|| gInterface.CheckWindow(SkillTree)|| gInterface.CheckWindow(FullMap)|| gInterface.CheckWindow(MoveList)|| gInterface.CheckWindow(Inventory)|| gInterface.CheckWindow(ExpandInventory)|| gInterface.CheckWindow(Store)|| gInterface.CheckWindow(Inventory)|| gInterface.CheckWindow(Party)	|| gInterface.CheckWindow(Trade)	|| gInterface.CheckWindow(Warehouse)|| gInterface.CheckWindow(ExpandWarehouse)
#define CheckSPK_WINDOWS3 gInterface.CheckWindow(ObjWindow::CashShop)|| gInterface.CheckWindow(ObjWindow::FriendList)|| gInterface.CheckWindow(ObjWindow::MoveList)|| gInterface.CheckWindow(ObjWindow::Party)|| gInterface.CheckWindow(ObjWindow::Quest)|| gInterface.CheckWindow(ObjWindow::NPC_Devin)|| gInterface.CheckWindow(ObjWindow::Guild)|| gInterface.CheckWindow(ObjWindow::Trade)|| gInterface.CheckWindow(ObjWindow::Warehouse)|| gInterface.CheckWindow(ObjWindow::ChaosBox)|| gInterface.CheckWindow(ObjWindow::CommandWindow)|| gInterface.CheckWindow(ObjWindow::PetInfo)|| gInterface.CheckWindow(ObjWindow::Shop)|| gInterface.CheckWindow(ObjWindow::Store)|| gInterface.CheckWindow(ObjWindow::OtherStore)|| gInterface.CheckWindow(ObjWindow::Character)|| gInterface.CheckWindow(ObjWindow::DevilSquare)|| gInterface.CheckWindow(ObjWindow::BloodCastle)|| gInterface.CheckWindow(ObjWindow::CreateGuild)|| gInterface.CheckWindow(ObjWindow::GuardNPC)|| gInterface.CheckWindow(ObjWindow::SeniorNPC)|| gInterface.CheckWindow(ObjWindow::GuardNPC2)|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)|| gInterface.CheckWindow(ObjWindow::CatapultNPC)|| gInterface.CheckWindow(ObjWindow::CrywolfGate)|| gInterface.CheckWindow(ObjWindow::IllusionTemple)|| gInterface.CheckWindow(ObjWindow::HeroList)|| gInterface.CheckWindow(ObjWindow::ChatWindow)|| gInterface.CheckWindow(ObjWindow::FastMenu)|| gInterface.CheckWindow(ObjWindow::Options)|| gInterface.CheckWindow(ObjWindow::Help)|| gInterface.CheckWindow(ObjWindow::FastDial)|| gInterface.CheckWindow(ObjWindow::SkillTree)|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)|| gInterface.CheckWindow(ObjWindow::NPC_Duel)|| gInterface.CheckWindow(ObjWindow::NPC_Titus)|| gInterface.CheckWindow(ObjWindow::CashShop)|| gInterface.CheckWindow(ObjWindow::Lugard)|| gInterface.CheckWindow(ObjWindow::QuestList1)|| gInterface.CheckWindow(ObjWindow::QuestList2)|| gInterface.CheckWindow(ObjWindow::Jerint)|| gInterface.CheckWindow(ObjWindow::FullMap)|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)|| gInterface.CheckWindow(ObjWindow::GensInfo)|| gInterface.CheckWindow(ObjWindow::NPC_Julia)|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)|| gInterface.CheckWindow(ObjWindow::ExpandInventory)|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)|| gInterface.CheckWindow(ObjWindow::MuHelper)
#define CheckSPK_WINDOWS4 gInterface.CheckWindow(Inventory)|| gInterface.CheckWindow(Character)|| gInterface.CheckWindow(Warehouse)|| gInterface.CheckWindow(Shop) || gInterface.CheckWindow(ChaosBox)|| gInterface.CheckWindow(Trade)|| gInterface.CheckWindow(Store)|| gInterface.CheckWindow(OtherStore)|| gInterface.CheckWindow(LuckyCoin1) || gInterface.CheckWindow(NPC_ChaosMix)|| gInterface.CheckWindow(MoveList)
#define CheckSPK_WINDOWS5 gInterface.CheckWindow(ObjWindow::MoveList) || gInterface.CheckWindow(ObjWindow::CashShop) || gInterface.CheckWindow(ObjWindow::SkillTree) || gInterface.CheckWindow(ObjWindow::FullMap)|| (gInterface.CheckWindow(Inventory)&& gInterface.CheckWindow(ExpandInventory)&& gInterface.CheckWindow(Store))|| (gInterface.CheckWindow(Inventory)&& gInterface.CheckWindow(Warehouse)&& gInterface.CheckWindow(ExpandWarehouse))
#define CheckSPK_WINDOWS6 gInterface.CheckWindow(Inventory)|| gInterface.CheckWindow(Character)|| gInterface.CheckWindow(Warehouse)|| gInterface.CheckWindow(Shop)|| gInterface.CheckWindow(ChaosBox)|| gInterface.CheckWindow(Trade)|| gInterface.CheckWindow(Store)|| gInterface.CheckWindow(OtherStore)|| gInterface.CheckWindow(LuckyCoin1)|| gInterface.CheckWindow(NPC_ChaosMix)|| gInterface.CheckWindow(MoveList)
#define SO_LUONG_BOSS			1
#define B_MOCNAP				1
#define SPK_ITEMLOCK			1
#define LUC_CHIEN				1
#define BXH_LUCHIEN				1 
#define NEWXSHOP				1
//-----

typedef void (*PUSHEVENT_CALLBACK)(int);
