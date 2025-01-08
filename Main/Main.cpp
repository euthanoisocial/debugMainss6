#include "stdafx.h"
#include "resource.h"
#include "Main.h"
#include "..\\..\\Util\\CCRC32.H"
#include "Common.h"
#include "Controller.h"
#include "CustomBuyVip.h"
#include "CustomEventTime.h"
#include "CustomItem.h"
#include "CustomJewel.h"
#include "CustomMap.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomWing.h"
#include "Fix.h"
#include "StaticEffect.h"
#include "DynamicEffect.h"
#include "HackCheck.h"
#include "HealthBar.h"
#include "Item.h"
#include "ItemShopValue.h" 
#include "ItemSmoke.h"
#include "Interface.h"
#include "OffTrade.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Protocol.h"
#include "Reconnect.h"
#include "Resolution.h"
#include "User.h"
#include "Util.h"
#include "TMemory.h"
//--
#include "InterEx.h"
#include "SelectChar.h"
#include "postInterface.h"
#include "StatsAdvance.h"
#include "CustomBow.h"
#include "CustomGloves.h"
#include "CustomPet.h"
#include "Pet.h"
#include "PetHook.h"
#include "CustomCloak.h"
#include "cape.h"
#include "ItemTRSData.h"
#include "CustomEffectRemake.h"
#include "ItemRemake.h"
#include "ItemManager.h"
#include "ItemInfoEx.h"
#include "CSCharacterS13.h"
#include "CustomItemPrice.h"
#include "MonsterGlow.h"
#include "CustomMonsterGlow.h"
#include "ModelEffect.h"
#include "CChatEx.h"
#include "CustomPetEffect.h"
#include "CChatClassic.h"
#include "CNewUIMacro.h"
#include "TrayModeNew.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "SItemOption.h"
#include "ItemTooltip.h"
#include "PetMontura.h"
#include "Central.h"
#include "BuffIcon.h"
#include "MuHelper.h"
//--
#include "Inter3.h"
#include "CChatClassic.h"
#include "cCPetRenderMesh.h"
#include "MultiSelect.h"
#include "ItemTooltip.h"
#include "JCRendernoItemGlow.h"
#include "ItemGlow.h"
#include "MonsterHpBar.h"
#include "Map.h"
#include "Font.h"
#include "CNewUIScene.h"
#include "Graphics.h"
#include "CustomNPC.h"
#include "GLFont.h"
#include "Other.h"
#include "Antilag.h"
#include "SlideHelp.h"
#include "UIControl.h"
#include "PartyBar.h"
#include "ConnectServer.h"
#include "ServerInfo.h"
#include "ShopSearch.h"
#include "GetBarPlayer.h"
#include "WideScreen.h"
#include "InterfaceS6.h"
#include "Luna_CNewFlag.h"
#include "CustomNotice.h"
#include "WingInvisible.h"
#include "CUIMng.h"
#include "RegisterMain.h"
#include "CustomJewelBank.h"
#include "QuickCommandWindow.h"
#include "NewUIMyInventory.h"
#include "WSclient.h"
#include "LoginMainWin.h"
#include "AutoLoginWin.h"
#include "DrawRenderTipTex.h"
#include "Store.h"
//tue add atm boxx
#include "Config.h"
#include "CMacroUIEx.h"
//------
// tue add Hieu ung duoi chan nhan vat
#include "CustomMoveEffect.h"
//tue add thue flag 
#include "ThueFlag.h"
#include "CustomModelFlag.h"
#include "Luna_CNewflag.h"

////////////////////////////////////////
HINSTANCE hins;

void StartAddress(LPVOID lpThreadParameter)
{
	HANDLE v1;
	HANDLE v2;

	while ( TRUE )
	{
		Sleep(5000);

		v1 = GetCurrentProcess();
		SetProcessWorkingSetSize(v1, 0xFFFFFFFF, 0xFFFFFFFF);

		v2 = GetCurrentProcess();
		SetThreadPriority(v2, -2);
	}
}

__declspec(naked) void OffButtonQuestInStats()
{
	static DWORD ButtonAddress = 0x0077EBB5;
	_asm{jmp ButtonAddress}
}

__declspec(naked) void OffButtonPetsInStats()
{
	static DWORD ButtonAddress = 0x0077EC5E;
	_asm{jmp ButtonAddress}
}

__declspec(naked) void OffButtonSkillMasterInStats()
{
	static DWORD ButtonAddress = 0x0077ECE7;
	_asm{jmp ButtonAddress}
}

__declspec(naked) void OffButtonInventoryExt()
{
	static DWORD ButtonAddress = 0x00836A28;
	_asm{jmp ButtonAddress}
}

__declspec(naked) void OffButtonOpenStore()
{
	static DWORD ButtonAddress = 0x008369B4;
	_asm{jmp ButtonAddress}
}
__declspec(naked) void OffButtonRepeirInInventory()
{
	static DWORD ButtonAddress = 0x00836941;
	_asm{jmp ButtonAddress}
}

//----- (005977E0) --------------------------------------------------------
int NoticeInverse;
//----- (005977E0) --------------------------------------------------------
int RenderNotices()
{	
	 int MoveY = 335;
    
	int result; // eax@1
	if ( pPlayerState == 5 )
	{
		result = (unsigned __int8)pCheckWindow((int *)GetInstance(), 65);
		if ( (unsigned __int8)result != 1 )
		{
			EnableAlphaTest(1);
			pSetTextSize(pTextThis(), (HFONT)pFontBold);
			glColor3f(1.0, 1.0, 1.0);
			for (signed int i = 0; i < 6; ++i )
			{
				if ( *((_BYTE *)0x813DDD0 + 264 * i + 260) )
				{
					pSetTextColor(pTextThis(), 0x64u, 0xFFu, 0xC8u, 0xFFu);
					pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x00u);
				}else{
					pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x00u);
					if ( NoticeInverse % 10 >= 5 ){
						pSetTextColor(pTextThis(), 249, 244, 0, 0xFFu);
					}else{
						pSetTextColor(pTextThis(), 249, 244, 0, 0x80u);
					}
				}
				pDrawText(pTextThis(), 320, 13 * i + MoveY, (LPCTSTR)0x813DDD0 + 264 * i, 0, 0, (LPINT)8, 0);
			}
			NoticeInverse = NoticeInverse + 1;
			result = NoticeInverse + 1;
		}
		return result;
	}
	
}
extern "C" _declspec(dllexport) void EntryProc() // OK
{
#if(CUSTOM_FLAGS)
	Flag.Load();
#endif
//tue add flag

#if(HT_THUE_FLAG)
	Flag.Load();
#endif
//////////////////////////
//tue add  atm boxx
	gConfig.Load();
//
	SetCompleteHook(0xE9,0x005880F0,0x0058811F); //Fix gm wing on Blood castle

    SetDword(0x00588444+3,4095);

	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, 0, 0, 0);

	WingInvisible();

	if(gProtect.ReadMainFile("Licencia") == 0)
	{
		MessageBox(0,"Licencia corrupt!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(gProtect.ReadTooltipTRSData( "Data\\Local\\TooltipTRSData.bmd" ) == 0)
	{
		MessageBox(0, "Data\\Local\\TooltipTRSData.bmd missing or File corrupt!" ,"Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(gProtect.ReadMakeViewTRSData("Data\\Local\\MakeWorldTRSData.bmd") == 0)
	{
		MessageBox(0,"Data\\Local\\MakeWorldTRSData.bmd missing or File corrupt!","Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(gProtect.ReadPetEffectBMD("Data\\Local\\EffectTRSData.bmd") == 0)
	{
		MessageBox(0,"Data\\Local\\EffectTRSData.bmd missing or File corrupt!","Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}


	//gInfoLog.Load();
	SetByte(0x00E61144,0xA0); // Accent
	SetByte(0x004D1E69,0xEB); // Crack (mu.exe)
	SetByte(0x004D228D,0xE9); // Crack (GameGuard)
	SetByte(0x004D228E,0x8B); // Crack (GameGuard)
	SetByte(0x004D228F,0x00); // Crack (GameGuard)
	SetByte(0x004D2290,0x00); // Crack (GameGuard)
	SetByte(0x004D2291,0x00); // Crack (GameGuard)
	SetByte(0x004D559C,0xEB); // Crack (ResourceGuard)
	SetByte(0x00633F7A,0xEB); // Crack (ResourceGuard)
	SetByte(0x00634403,0xEB); // Crack (ResourceGuard)
	SetByte(0x0063E6C4,0xEB); // Crack (ResourceGuard)
	SetByte(0x004D2246,0xEB); // Crack (ResourceGuard)
	SetByte(0x00501163,0xEB); // Crack (ResourceGuard)
	SetByte(0x0040AF0A,0x00); // Crack (ResourceGuard)
	SetByte(0x0040B4BC,0x50); // Login Screen
	SetByte(0x0040B4C5,0x50); // Login Screen
	SetByte(0x0040B4CF,0x18); // Login Screen
	SetByte(0x0040AF0A,0x00); // Login Screen
	SetByte(0x0040AFD5,0xEB); // Login Screen
	SetByte(0x00777FD6,0x70); // Item Text Limit
	SetByte(0x00777FD7,0x17); // Item Text Limit
	SetByte(0x004EBEC7,0x3C); // Item Text Limit
	SetByte(0x005C4004,0x3C); // Item Text Limit
	SetByte(0x007E40BB,0x3C); // Item Text Limit
	SetByte(0x0081B546,0x3C); // Item Text Limit
	SetByte(0x0081B58D,0x3C); // Item Text Limit
	SetByte(0x0086E284,0x3C); // Item Text Limit
	SetByte(0x0086E44C,0x3C); // Item Text Limit
	SetByte(0x0086E573,0x3C); // Item Text Limit
	SetByte(0x0086F8FC,0x3C); // Item Text Limit
	SetByte(0x007DA373,0xB7); // Item Type Limit
	SetByte(0x007E1C44,0xB7); // Item Type Limit
	SetByte(0x0052100D,0xEB); // Ctrl Fix
	SetByte(0x009543C4,0x00); // Move Vulcanus

	SetByte(0x00649E24 + 3, 14);   //-> Fix Agi Test 1
	SetByte(0x00556C32 + 6, 2);   //-> Fix Agi Test 2
	SetByte(0x004D128F, 0x1D); // Fix Resolucion 640x480
	SetCompleteHook(0xE9, 0x004D1CF0, 0x004D1DC2); //-- Remoce MuError.DMP
	MemorySet(0x00D20170, 0x90, 0x1B); //-- Remove Creation MuError.log
	SetByte(0x0064CBD1,((gProtect.m_MainInfo.HelperActiveAlert==0) ? 0xEB : 0x75)); //-- Helper Message Box
	SetByte(0x0064CBD0,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); //-- Helper Active Level
	SetByte(0x0095CEEF,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); //-- Helper Active Level
	SetByte(0x0095CF14,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); //-- Helper Active Level
	SetByte(0x00E61F68,(gProtect.m_MainInfo.ClientVersion[0]+1)); //-- Version
	SetByte(0x00E61F69,(gProtect.m_MainInfo.ClientVersion[2]+2)); //-- Version
	SetByte(0x00E61F6A,(gProtect.m_MainInfo.ClientVersion[3]+3)); //-- Version
	SetByte(0x00E61F6B,(gProtect.m_MainInfo.ClientVersion[5]+4)); //-- Version
	SetByte(0x00E61F6C,(gProtect.m_MainInfo.ClientVersion[6]+5)); //-- Version
	//Remover Limite de Zen Storage
	SetByte((PVOID)(0x007AF175 + 1), 9);
	SetByte((PVOID)(0x007AF415 + 1), 9);
	SetByte((PVOID)(0x007AF795 + 1), 9);
	SetByte((PVOID)(0x007B0315 + 1), 9);
	//--
	//SetWord(0x00E609E4,(gProtect.m_MainInfo.IpAddressPort)); //-- IpAddressPort
	//tue fix
	SetWord(0x00E609E4,(gProtect.m_MainInfo.IpAddressPort)); //-- IpAddressPort
	//--------------------------
	SetDword(0x004D9D3B,(DWORD)&FrameValue);
	SetDword(0x004DAC60,(DWORD)&FrameValue);
	SetDword(0x7B55338,(DWORD)10);
	SetDword(0x004D597B,(DWORD)&MainTickCount);
	SetDword(0x004DA289,(DWORD)&MainTickCount);
	SetDword(0x004DA297,(DWORD)&MainTickCount);
	SetDword(0x004DA3A2,(DWORD)&MainTickCount);
	SetDword(0x004DA3CE,(DWORD)&MainTickCount);
	SetDword(0x004DA3D9,(DWORD)&MainTickCount);
	SetDword(0x0063D326,(DWORD)&MainTickCount);
	SetDword(0x00642112,(DWORD)&MainTickCount);
	SetDword(0x004D0E09,(DWORD)gProtect.m_MainInfo.WindowName);
	SetDword(0x004D9F55,(DWORD)gProtect.m_MainInfo.ScreenShotPath);
	
	SetDword(0x00954148 + 1, (DWORD)gProtect.m_MainInfo.ServerName1); //-> (Gold)
	SetDword(0x00954115 + 1, (DWORD)gProtect.m_MainInfo.ServerName2); //-> (Gold PVP)
	SetDword(0x009540E2 + 1, (DWORD)gProtect.m_MainInfo.ServerName3); //-> (Non-PVP)
	SetDword(0x009540AC + 1, (DWORD)gProtect.m_MainInfo.ServerName4); //-> Sem Nada
	SetByte(0x004030D4, (BYTE)gProtect.m_MainInfo.CharsCount); // Create character max chars (default: 7)

	SetByte(0x005C914B+3, 0x00); //-- LuckItemmove

	MemorySet(0x0063E908,0x90,20); //-- C1:F3:04

	SetCompleteHook(0xE9,0x0064452A,0x00644537); //-- Fix montura

	//MemoryCpy(0x00E611B2,gProtect.m_MainInfo.IpAddress,sizeof(gProtect.m_MainInfo.IpAddress)); //-- IpAddress
	//tue fixx
	MemoryCpy(0x00E611B2, "mu-tue.com", sizeof("mu-tue.com")); //-- IpAddress
	//------
	MemoryCpy(0x00E61F70,gProtect.m_MainInfo.ClientSerial,sizeof(gProtect.m_MainInfo.ClientSerial)); //-- ClientSerial

	SetCompleteHook(0xE8, 0x0059AFFA, 0x0059B00E); // Fix Monster Trabe

	SetCompleteHook(0xFF,0x0065FD79,&ProtocolCoreEx);

	SetCompleteHook(0xE9,0x004DA280,&CheckTickCount1);

	SetCompleteHook(0xE9,0x004DA3A1,&CheckTickCount2);

	SetCompleteHook(0xE8,0x005B96E8,&DrawHealthBar);

	SetCompleteHook(0xE8, 0x004D5EC3, &RenderNotices);

	SetFloat((PVOID)0x0D27B1C, 1000.0000);// cam

	VirtualizeOffset(0x004D9D39,12);

	VirtualizeOffset(0x004D9D45,7);

	VirtualizeOffset(0x004D9EFC,15);

	VirtualizeOffset(0x004DAC5C,8);

	VirtualizeOffset(0x005451F7,5);

	VirtualizeOffset(0x00545230,8);

	VirtualizeOffset(0x005A52E9,8);

	LoadReferenceAddressTable((HMODULE)hins, MAKEINTRESOURCE(IDR_BIN1),(DWORD)&NewAddressData1);

	LoadReferenceAddressTable((HMODULE)hins, MAKEINTRESOURCE(IDR_BIN2),(DWORD)&NewAddressData2);

	LoadReferenceAddressTable((HMODULE)hins, MAKEINTRESOURCE(IDR_BIN3),(DWORD)&NewAddressData3);
	//--Muun
	//g_pRenderText.Init();
	//StoreFixload();
	//--Custom NPC
	gNPC.Load(); //NPC CUSTOM 
	gCustomJewelBank.Load();

#if(DANGKYTK)
	InitRegistro();
	gRegisterMain.LoadIMG();
#endif

	InitNotices();

	gCUIMng.Load();

	gCustomMessage.LoadEng(gProtect.m_MainInfo.EngCustomMessageInfo);

	gCustomMessage.LoadPor(gProtect.m_MainInfo.PorCustomMessageInfo);

	gCustomMessage.LoadSpn(gProtect.m_MainInfo.SpnCustomMessageInfo);

	gCustomJewel.Load(gProtect.m_MainInfo.CustomJewelInfo);

	gCustomWing.Load(gProtect.m_MainInfo.CustomWingInfo);

	gCustomItem.Load(gProtect.m_MainInfo.CustomItemInfo);

	gCustomBuyVip.Load(gProtect.m_MainInfo.CustomBuyVipInfo);

	gCustomEventTime.Load(gProtect.m_MainInfo.CustomEventInfo);

	gFog.Load(gProtect.m_MainInfo.CustomFog);

	gSmokeEffect.Load(gProtect.m_MainInfo.CustomSmokeEffect);

	gCustomMonster.Load(gProtect.m_MainInfo.CustomMonsters);

	gNPCName.Load(gProtect.m_MainInfo.CustomNPCName);
	//--
	gCustomBattleGloves.Load(gProtect.m_MainInfo.CustomGloves);

	gCustomBow.Load(gProtect.m_MainInfo.CustomBowInfo);

	gCustomPet2.Load(gProtect.m_MainInfo.CustomPetInfo);

	gCloak.Load(gProtect.m_MainInfo.m_CustomCloak);

	ItemTRSData.Load(gProtect.m_MainInfo.CustomPosition);

	gCustomRemake.Load(gProtect.m_MainInfo.CustomRemake);

	gItemManager.Load(gProtect.m_MainInfo.m_ItemInfoEx);

	gCustomModelEffect.Load(gProtect.m_MainInfo.m_CustomModelInfo);
	//--
	gCustomCEffectPet.Load(gProtect.m_ReadBMD.m_PetCEffectBMD);

	gCustomWingEffect.Load(gProtect.m_ReadBMD.CustomWingEffectInfo);

	gDynamicWingEffect.Load(gProtect.m_ReadBMD.DynamicWingEffectInfo);

	cRender.Load(gProtect.m_ReadBMD.RenderMeshPet);

	gCustomMonsterGlow.LoadGlow(gProtect.m_ReadBMD.m_CustomMonsterGlow);

	gCustomMonsterGlow.LoadBrightness(gProtect.m_ReadBMD.m_CustomMonsterbrightness);

	JCEffectMonster.Load( gProtect.m_ReadBMD.m_CustomMonsterEffect );

	JCRemoveGlow.Load( gProtect.m_ReadBMD.m_JCWRemoveGlow );
	//tue add thue flag 
#if(HT_THUE_FLAG)
	gCustomModelFlag.SetInfo(gProtect.m_MainInfo.m_mModelFlagData);
	gCustomModelFlag.SetInfoJPG(gProtect.m_MainInfo.m_mJPGFlagData);
#endif
	/////////////////////
#if UPDATE > 15
	JCRender.Load( gProtect.m_ReadBMD.m_JCWRenderMesh );
#endif
//--
	gIconBuff.LoadEng(gProtect.m_ReadTooltipTRSData.m_TooltipTRSDataEng);
	
	gIconBuff.LoadSpn(gProtect.m_ReadTooltipTRSData.m_TooltipTRSDataSpn);
	
	gIconBuff.LoadPor(gProtect.m_ReadTooltipTRSData.m_TooltipTRSDataPor);

	GInfo.loadnInformation( gProtect.m_ReadTooltipTRSData.m_TRSTooltipData );

	GInfo.loadnText( gProtect.m_ReadTooltipTRSData.m_TRSTooltipText );
//--
#if UPDATE >= 15
	gSelectCharRamdon.LoadMultiChar(gProtect.m_MakeViewTRSData.m_RenderSelect);
#endif

	gCustomMap.Load(gProtect.m_MainInfo.CustomMapInfo);

	gMonsterHpBar.Load(gProtect.m_MainInfo.CustomHpBar);
//--
	gPacketManager.LoadEncryptionKey("Data\\Enc1.dat");

	gPacketManager.LoadDecryptionKey("Data\\Dec2.dat");

	InitHackCheck();

	gTrayMode.Load();
	
	JumPlayer.Load();

	gSlide.Load();

#if (SHOPSEARCH)
	g_PersonalShopEx.Load();
#endif

	InitCommon();

	JCRemoveGlow.Init();

#if UPDATE > 15
	JCRender.Init();
#endif
	gCentral.InitCentral();//-- Control: camara||mouse

	QTPary.Load();

	gItemInfoEx.Load();

	gOther.Load();

	g_pRenderText.Init();

	gMuHelper.LoadHelper();

	if(gProtect.m_MainInfo.SelectCharAnimate == 1)
	{
		gSelectChar.Load();
	}

	#if UPDATE >= 15
	gSelectCharRamdon.InitMultiChar();
	#endif

	if(gProtect.m_MainInfo.SelectCharS13 == 1)
	{
		gCSCharacterS13.Load();
	}

	ItemTRSData.Init();

	if(gProtect.m_MainInfo.DisableCustomCloack == 0)
	{
		//gCapeAnimation.Load();
	}
	//tue fixx
	gCapeAnimation.Load();
	//-------------------------
	//tue add Hieu ung duoi chan nhan vat /////////
	gMoveEffect.Init();
	///////////////////////////////////////////////
	if(gProtect.m_MainInfo.DisableCustomPet == 0)
	{
		gCustomPet.Load();

		gObjCreatePetExHook();

		gCustomCEffectPet.Init();

		initmontura();
	}

	gRenderMap.MiniMapload();

	InitItem();

	InitJewel();

	InitPrintPlayer();

	InitReconnect();

	InitResolution();

	gController.Load(hins);

	InitWing();

	gObjUser.Load();

	gInterface.RenderObjectSystem();

	gInterface.RenderObjectSystem2();

	gCMacroUIEx.Load();
	//tue add atm box test
	//gCMacroUIExSPK.Load();
	//------

	//==CHuyen Sub
	ConnectServer.Load();

	gServerInfo.Load();

	switch(gProtect.m_MainInfo.CustomInterfaceType)
	{
		case 1:
		case 2:
			InitInter3();
			gCChatClassic.Load();
			break;
		case 3:
			InitSeason15();
		case 4:
			InitSeason15();
			gCRenderEx700.Init();
			gCChatEx.Load();
			break;
	}
	
	if(gProtect.m_MainInfo.DisableAdvance == 0)
	{
		g_StatsAdvance.Load();	//<-- Advanced
	}

	InitReduceCPU();

	gOffTrade.Init();

	gFog.Init();

	if(gProtect.m_MainInfo.CustomMonsterEnable == 1)
	{
		gCustomMonster.InitMonster();// 
	}

	InitloadGlow();

	InitFonts();

	if(gProtect.m_MainInfo.DisableCustomBow == 0)
	{
		gCustomBow.Init();
	}

	if(gProtect.m_MainInfo.DisableCustomClaws == 0)
	{
		gCustomBattleGloves.Init();
	}

	InitMap();

	if(gProtect.m_MainInfo.EnableShopValueSystem == 1)
	{
		gItemPrice.Init();
	}

	if(gProtect.m_MainInfo.CsSkill == 1)
	{
		//Liberar CS Skills
		SetByte((0x005B89C3+3), 0x00);
		SetByte((0x005B89C9+3), 0x00);
		SetByte((0x005B89CF+3), 0x00);
		SetByte((0x005B89D5+3), 0x00);
		SetByte((0x005B89DB+3), 0x00);
		SetByte((0x005B89E1+3), 0x00);
		SetWord((0x005B89E7+3), 0x00);
		SetByte((0x005C6314+2), 0x00);
		SetByte((0x005C6327+2), 0x00);
		SetByte((0x005C633A+2), 0x00);
		SetByte((0x005C634D+2), 0x00);
		SetByte((0x005C6360+2), 0x00);
		SetByte((0x005C6373+2), 0x00);
		SetWord((0x005C6386+2), 0x00);
	}

	if(gProtect.m_MainInfo.RemoveClass == 3)
	{
		SetByte(0x004030D1+3,6);
	}

	if(gProtect.m_MainInfo.RemoveClass == 2)
	{
		SetByte(0x004030D1+3,5);
	}
	if(gProtect.m_MainInfo.RemoveClass == 1)
	{
		SetByte(0x004030D1+3,4);
	}

	SetWord(0x00405B7C, gProtect.m_MainInfo.ReduceMemory);
	
	SetWord(0x0040CC40, gProtect.m_MainInfo.ReduceMemory);
	
	if(gProtect.m_MainInfo.DisableTree == 1)
	{
		MemorySet(0x008193F0,0x90,0xC8); //Remove Master Skill Tree Window(A Buttom)
	}

	if(gProtect.m_MainInfo.EffectPlus15 == 0)
	{
		MemorySet(0x006097B0,0x90,0x69D);
	}

	if(gProtect.m_MainInfo.DisableGens == 1)
	{
		MemorySet(0x007C5AD2, 0x90, 0x05);			//-> Disable Gens (Key B)
	}

	if(gProtect.m_MainInfo.DisableTabMap == 1)
	{
		MemorySet(0x0062F876, 0x90, 0x30);			//-> Disable ViewMap (Key TAB)
	}
	//-- disables
	if(gProtect.m_MainInfo.DisableRepeirInInventory == 1)
	{
		SetCompleteHook(0xE9, 0x0083693C, &OffButtonRepeirInInventory);
	}

	if(gProtect.m_MainInfo.DisableButtonOpenStore == 1)
	{
		SetCompleteHook(0xE9, 0x008369AF, &OffButtonOpenStore);
	}

	if(gProtect.m_MainInfo.DisableButtonInventoryExt == 1)
	{
		SetCompleteHook(0xE9, 0x00836A23, &OffButtonInventoryExt);
	}

	if(gProtect.m_MainInfo.DisableButtonQuestInStats == 1)
	{
		SetCompleteHook(0xE9, 0x0077EBB0, &OffButtonQuestInStats);
	}

	if(gProtect.m_MainInfo.DisableButtonPetsInStats == 1)
	{
		SetCompleteHook(0xE9, 0x0077EC59, &OffButtonPetsInStats);
	}

	if(gProtect.m_MainInfo.DisableButtonSkillMaster == 1)
	{
		SetCompleteHook(0xE9, 0x0077ECE2, &OffButtonSkillMasterInStats);
	}

	if(gProtect.m_MainInfo.DisableEffectRemake == 0)
	{
		gCreateEffect.Load();
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 1)
	{
		SetByte(0x005528A0, 0xC3); // [Fix] Remover Recuo PVP
		MemorySet(0x008684F0, 0x90, 0x52);			//-> Disable FastMenu (Key U)
	}

	if(gProtect.m_MainInfo.DisableHelper == 1)
	{
		MemorySet(0x0085B6AC, 0x90, 0x05);			//-> Remove Helper Top Screen
		MemorySet(0x0085CC50, 0x90, 0x05);			//-> Disable Helper (Key Z)
		MemorySet(0x007D40A2, 0x90, 0x05);			//-> Disable Helper (Key Home)
	}

	if(gProtect.m_MainInfo.DisableSocketInvetori == 1)
	{
		RemoveSocket();
	}
	gPostInterface.Load();	//<-- post item

	gCItemSetOption.Load();

	SetCompleteHook(0xE9, 0x0071B1A3, 0x00720894); //-- Fix RF

	InitAttackSpeed(); //-- Fix Agilidad

	gGraphics.Load();

	SetCompleteHook(0xE9, 0x0095DFBE, 0x0095DFD3); //-- Fix RF

	gProtect.CheckLauncher();

	gProtect.CheckInstance();

	gProtect.CheckClientFile();

	gProtect.CheckHackFile();

	gProtect.CheckPluginFile1();

	gProtect.CheckPluginFile2();

	gProtect.CheckPluginFile3();

	gProtect.CheckPluginFile4();

	gProtect.CheckPluginFile5();

	gProtect.CheckCameraFile();

	if (gProtect.m_MainInfo.Unicode == 1)
	{
		SetByte((0x00958D4C + 3), 0xA8);	//1 Codepage utf China lang
		SetByte((0x00958D4C + 4), 0x03);	//2	Codepage utf China lang

		SetByte(0x004215A7, 0xEB);	//[0-9A-Za-z] Name
		SetByte((0x00507AEA + 1), 0x72); //can not use symbol
		SetByte(0x00507AFD, 0xEB);	//[0-9A-Za-z] Guild

		SetByte((0x00958D56 + 0x3), 0x04); //  Message Limit
	}

	if (gProtect.m_MainInfo.MiniMapHover == 1)
	{
		//Minimap hover
		SetByte(0x0082BAB5 + 1, 0); // Âêëþ÷åíèå îòîáðàæåíèÿ âñåõ íïö íà ìèíèêàðòå
		SetRange(0x0082BAB7, 0x2, ASM::NOP);
		SetRange(0x0082B7FA, 0xA0, ASM::NOP);
	}

	if(gProtect.m_MainInfo.CustomSelectServerX700 == 1)
	{
		    CScene();
	}

	//SetFloat(0x0D27B1C, 1200.000); // 1100.000

	SetCompleteHook(0xE9, 0x007D399F, 0x007D39D8); // 关闭任务 (T)

	SetCompleteHook(0xE9, 0x0077EB65, 0x0077EC0E); // 在角色状态下关闭任务

	SetByte((0x00597691 + 4), 0x04); // 消息大小
	
	//MemorySet(0x0062EF95, 0x90, 0x15);
	//MemorySet(0x0062EFDC, 0x90, 0x00); //-- ENC
	//MemorySet(0x0062EEB7, 0x90, 0x00); //-- ENC
	//MemorySet(0x0062F025, 0x90, 0x2C);
	//MemorySet(0x0062F03C, 0x90, 0x15);
	//MemorySet(0x0062F053, 0x90, 0x15);
	//MemorySet(0x0062F06A, 0x90, 0x34);
	////--
	//MemorySet(0x0062F14B, 0x90, 0x18);
	//MemorySet(0x0062F17F, 0x90, 0x34);
	//MemorySet(0x0062F1BE, 0x90, 0x18);
	//MemorySet(0x0062F1F2, 0x90, 0x34);
	//MemorySet(0x0062F26F, 0x90, 0x36);
	//MemorySet(0x0062F385, 0x90, 0x34);
	//MemorySet(0x0062F3BB, 0x90, 0x18);
	//MemorySet(0x0062F429, 0x90, 0x14);
	//MemorySet(0x0062F45A, 0x90, 0x8D);


	if (MinimizarFenrir == 0)
		{
			////Fenrir SafeZone (Struct +14)
			//SetByte(0x00501955 + 2, 0);
			//MemorySet(0x0054EAE1, 0x90, 0x06);//SetPlayerStop
			//MemorySet(0x0054FC92, 0x90, 0x06);//SetPlayerWalk

			////Horse SafeZone (Struct +14)
			//SetByte(0x00502269 + 2, 0);
			//MemorySet(0x0054ECA3, 0x90, 0x6);
			//MemorySet(0x0054FCEC, 0x90, 0x6);

			////Dinorant e Uniria (Struct +14)
			//SetByte(0x00502C4B + 2, 0);
			//MemorySet(0x0054ED6D, 0x90, 0x6);
			//MemorySet(0x0054FD5F, 0x90, 0x6);
			//MemorySet(0x0054FE3E, 0x90, 0x6);

			////Raven (Struct +14)
			//MemorySet(0x0054FD23, 0x90, 0x6);
		}
#if(SOIITEM)
	g_pQuickCommandWindow.szInit();
#endif

#if(HAISLOTRING)
	g_pMyInventory.Init();
	g_pWSclient.Init();
#endif
    g_pLoginMainWin.Init();

	AutoLogin.Load();

	//g_pTipTextList.Init();
}

BOOL APIENTRY DllMain(HMODULE hModule,DWORD ul_reason_for_call,LPVOID lpReserved) // OK
{
	switch(ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			hins = (HINSTANCE)hModule;
			gController.Instance = hModule;
			break;
		case DLL_PROCESS_DETACH:
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
	}

	return 1;
}
