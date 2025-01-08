#include "stdafx.h"
#include "Protocol.h"
#include "Common.h"
#include "CustomEventTime.h"
#include "CustomRankUser.h"
#include "CustomRanking.h"
#include "HealthBar.h"
#include "Interface.h"
#include "ItemShopValue.h"
#include "Offset.h"
#include "OffTrade.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Reconnect.h"
#include "Util.h"
#include "post_item.h"
#include "postInterface.h"
#include "PetProtocol.h"
#include "StatsAdvance.h"
#include "User.h"
#include "PartyBuffs.h"
#include "BuffIcon.h"
#include "Ruud.h"
#include "MiniMapInfo.h"
#include "Central.h"
#include "InterEx.h"
#include "NPCRuud.h"
#include "HWID.h"
#include "ResetSystem.h"
#include "ChangeClass.h"
#include "ServerInfo.h"
#include "GrandResetSystem.h"
#include "CustomLuckySpin.h"
#include "CustomHeThong.h"
#include "CustomOfflineMode.h"
#include "ConnectServer.h"
#include "ShopSearch.h"
#include "LeoThap.h"
#include "MultiCharacter.h"
#include "PartySearch.h"
#include "PartySearchSettings.h"
#include "HuyHieuCuongHoa.h"
#include "CustomCuongHoaWing.h"
#include "CustomVKR.h"
#include "CustomJewelBank.h"
#include "QuickCommandWindow.h"

#include "LoginMainWin.h"
#include "NewsBoard.h"

#include "NewUIMyInventory.h"
//tue add bau cua
#include "CustomBauCua.h"
//-----
//tue add Tu Chan ///////////////////
#include "SPK_TuChan.h"
//tue add Hon Hoan //
#include "SPK_HonHoan.h"
//====================
// //tue add thue flag 
#include "ThueFlag.h"
/////////////////////////////////////

#if(MOCNAP == 1)
struct MOCNAP_UPDATE  // ok
{
	PBMSG_HEAD2 h;
	int MocNapCheck1;
	int MocNapCheck2;
	int MocNapCheck3;
	int MocNapCheck4;
	int MocNapCheck5;
	int MocNapCheck6;
	int MocNapCheck7;
	int MocNapCheck8;
	int MocNapCheck9;
	int MocNapCheck10;
	int MocNapCheck11;
	int MocNapCheck12;
	int MocNapCheck13;
	//--
	int	MOCNAPCOIN;
	int	MOCNAP1;
	int	MOCNAP2;
	int	MOCNAP3;
	int	MOCNAP4;
	int	MOCNAP5;
	int	MOCNAP6;
	int	MOCNAP7;
	int	MOCNAP8;
	int	MOCNAP9;
	int	MOCNAP10;
	int	MOCNAP11;
	int	MOCNAP12;
	int	MOCNAP13;
};
void MocNapRecv(MOCNAP_UPDATE * aRecv)
{
	gObjUser.MocNapCheck1 = aRecv->MocNapCheck1;
	gObjUser.MocNapCheck2 = aRecv->MocNapCheck2;
	gObjUser.MocNapCheck3 = aRecv->MocNapCheck3;
	gObjUser.MocNapCheck4 = aRecv->MocNapCheck4;
	gObjUser.MocNapCheck5 = aRecv->MocNapCheck5;
	gObjUser.MocNapCheck6 = aRecv->MocNapCheck6;
	gObjUser.MocNapCheck7 = aRecv->MocNapCheck7;
	gObjUser.MocNapCheck8 = aRecv->MocNapCheck8;
	gObjUser.MocNapCheck9 = aRecv->MocNapCheck9;
	gObjUser.MocNapCheck10 = aRecv->MocNapCheck10;
	gObjUser.MocNapCheck11 = aRecv->MocNapCheck11;
	gObjUser.MocNapCheck12 = aRecv->MocNapCheck12;
	gObjUser.MocNapCheck13 = aRecv->MocNapCheck13;
	//--
	gObjUser.MOCNAPCOIN = aRecv->MOCNAPCOIN;
	gObjUser.MOCNAP1 = aRecv->MOCNAP1;
	gObjUser.MOCNAP2 = aRecv->MOCNAP2;
	gObjUser.MOCNAP3 = aRecv->MOCNAP3;
	gObjUser.MOCNAP4 = aRecv->MOCNAP4;
	gObjUser.MOCNAP5 = aRecv->MOCNAP5;
	gObjUser.MOCNAP6 = aRecv->MOCNAP6;
	gObjUser.MOCNAP7 = aRecv->MOCNAP7;
	gObjUser.MOCNAP8 = aRecv->MOCNAP8;
	gObjUser.MOCNAP9 = aRecv->MOCNAP9;
	gObjUser.MOCNAP10 = aRecv->MOCNAP10;
	gObjUser.MOCNAP11 = aRecv->MOCNAP11;
	gObjUser.MOCNAP12 = aRecv->MOCNAP12;
	gObjUser.MOCNAP13 = aRecv->MOCNAP13;
}
#endif

//tue add box atm
#if(B_MOCNAP)
CBINFOMOCNAP_CLIENT mDataMocNapClient;
CBLISTPHANTHUONGMOCNAP_CLIENT mDataListItemMocNapClient;
#endif
//---



#if(QUAEVENT == 1)
struct QUATOP1_UPDATE  // ok
{
	PBMSG_HEAD2 h;
	int QuaTop1Check1;
	//--
	int	QUATOP1COIN;
	int	QUATOP1;
};
struct QUATOP2_UPDATE  // ok
{
	PBMSG_HEAD2 h;
	int QuaTop2Check1;
	//--
	int	QUATOP2COIN;
	int	QUATOP2;
};
struct QUATOP3_UPDATE  // ok
{
	PBMSG_HEAD2 h;
	int QuaTop3Check1;
	//--
	int	QUATOP3COIN;
	int	QUATOP3;
};
void QuaTop1Recv(QUATOP1_UPDATE * aRecv)
{
	gObjUser.QuaTop1Check1 = aRecv->QuaTop1Check1;
	//--
	gObjUser.QUATOP1COIN = aRecv->QUATOP1COIN;
	gObjUser.QUATOP1 = aRecv->QUATOP1;
}
void QuaTop2Recv(QUATOP2_UPDATE * aRecv)
{
	gObjUser.QuaTop2Check1 = aRecv->QuaTop2Check1;
	//--
	gObjUser.QUATOP2COIN = aRecv->QUATOP2COIN;
	gObjUser.QUATOP2 = aRecv->QUATOP2;
}
void QuaTop3Recv(QUATOP3_UPDATE * aRecv)
{
	gObjUser.QuaTop3Check1 = aRecv->QuaTop3Check1;
	//--
	gObjUser.QUATOP3COIN = aRecv->QUATOP3COIN;
	gObjUser.QUATOP3 = aRecv->QUATOP3;
}
#endif

BOOL ProtocolCoreEx(BYTE head,BYTE* lpMsg,int size,int key) // OK
{
#if(ANTIHACK)	
	if (*(BYTE *)0x004DA3E0 != 40)
	{
		//MessageBoxA(NULL, "BQT khuyen ban khong gian lan khi choi game! 1", "[ElfCheat]", ERROR);	  //hack speed
		ExitProcess(0);
	}

	if (*(BYTE*)0x005DE171 != 137 || *(BYTE*)0x005DE172 != 138
		|| *(BYTE*)0x005DE173 != 160 || *(BYTE*)0x005DE174 != 0
		|| *(BYTE*)0x005DE175 != 0 || *(BYTE*)0x005DE176 != 0
		|| *(BYTE*)0x005B5FFF != 245 || *(BYTE*)0x005B6000 != 0
		|| *(BYTE*)0x005B6001 != 0 || *(BYTE*)0x005B6002 != 0)
	{
		//MessageBoxA(NULL, "BQT khuyen ban khong gian lan khi choi game! 2", "[ElfCheat]", ERROR);	 //delay hack
		ExitProcess(0);
	}

	if (*(BYTE*)0x005A1797 != 141 || *(BYTE*)0x005A1798 != 212
		|| *(BYTE*)0x005A1799 != 247 || *(BYTE*)0x005A179A != 255
		|| *(BYTE*)0x005A179B != 255
		|| *(BYTE*)0x005AD824 != 141 || *(BYTE*)0x005AD825 != 172 || *(BYTE*)0x005AD826 != 239 || *(BYTE*)0x005AD827 != 255 || *(BYTE*)0x005AD828 != 255
		|| *(BYTE*)0x005AF96D != 141 || *(BYTE*)0x005AF96E != 28 || *(BYTE*)0x005AF96F != 142 || *(BYTE*)0x005AF970 != 255 || *(BYTE*)0x005AF971 != 255
		|| *(BYTE*)0x0059C79D != 141 || *(BYTE*)0x0059C79E != 212 || *(BYTE*)0x0059C79F != 247 || *(BYTE*)0x0059C7A0 != 255 || *(BYTE*)0x0059C7A1 != 255
		|| *(BYTE*)0x005AFBF1 != 141 || *(BYTE*)0x005AFBF2 != 4 || *(BYTE*)0x005AFBF3 != 134 || *(BYTE*)0x005AFBF4 != 255 || *(BYTE*)0x005AFBF5 != 255
		|| *(BYTE*)0x0059CEDC != 141 || *(BYTE*)0x0059CEDD != 228 || *(BYTE*)0x0059CEDE != 247 || *(BYTE*)0x0059CEDF != 255 || *(BYTE*)0x0059CEE0 != 255
		|| *(BYTE*)0x005B1CCB != 141 || *(BYTE*)0x005B1CCC != 4 || *(BYTE*)0x005B1CCD != 151 || *(BYTE*)0x005B1CCE != 255 || *(BYTE*)0x005B1CCF != 255
		|| *(BYTE*)0x005B170A != 141 || *(BYTE*)0x005B170B != 52 || *(BYTE*)0x005B170C != 175 || *(BYTE*)0x005B170D != 255 || *(BYTE*)0x005B170E != 255
		|| *(BYTE*)0x005B0C07 != 141 || *(BYTE*)0x005B0C08 != 124 || *(BYTE*)0x005B0C09 != 207 || *(BYTE*)0x005B0C0A != 255 || *(BYTE*)0x005B0C0B != 255
		|| *(BYTE*)0x005B187C != 141 || *(BYTE*)0x005B187D != 36 || *(BYTE*)0x005B187E != 167 || *(BYTE*)0x005B187F != 255 || *(BYTE*)0x005B1880 != 255
		|| *(BYTE*)0x0059D1E2 != 141 || *(BYTE*)0x0059D1E3 == 144 || *(BYTE*)0x0059D1E4 != 231 || *(BYTE*)0x0059D1E5 != 255 || *(BYTE*)0x0059D1E6 != 255
		|| *(BYTE*)0x005B1AA9 != 141 || *(BYTE*)0x005B1AAA != 20 || *(BYTE*)0x005B1AAB != 159 || *(BYTE*)0x005B1AAC != 255 || *(BYTE*)0x005B1AAD != 255
		|| *(BYTE*)0x005AC554 != 141 || *(BYTE*)0x005AC555 != 116 || *(BYTE*)0x005AC556 != 182 || *(BYTE*)0x005AC557 != 255 || *(BYTE*)0x005AC558 != 255
		|| *(BYTE*)0x0059D6AD != 141 || *(BYTE*)0x0059D6AE != 204 || *(BYTE*)0x0059D6AF != 239 || *(BYTE*)0x0059D6B0 != 255 || *(BYTE*)0x0059D6B1 != 255
		|| *(BYTE*)0x005AC22C != 141 || *(BYTE*)0x005AC22D != 252 || *(BYTE*)0x005AC22E != 190 || *(BYTE*)0x005AC22F != 255 || *(BYTE*)0x005AC230 != 255
		|| *(BYTE*)0x00534FD2 != 141 || *(BYTE*)0x00534FD3 == 144 || *(BYTE*)0x00534FD4 != 247 || *(BYTE*)0x00534FD5 != 255 || *(BYTE*)0x00534FD6 != 255
		|| *(BYTE*)0x0059DED9 != 141 || *(BYTE*)0x0059DEDA == 144 || *(BYTE*)0x0059DEDB != 239 || *(BYTE*)0x0059DEDC != 255 || *(BYTE*)0x0059DEDD != 255
		|| *(BYTE*)0x0059DC87 != 141 || *(BYTE*)0x0059DC88 == 144 || *(BYTE*)0x0059DC89 != 247 || *(BYTE*)0x0059DC8A != 255 || *(BYTE*)0x0059DC8B != 255
		//hetsum
		|| *(BYTE*)0x005B2C98 != 141 || *(BYTE*)0x005B2C99 != 108 || *(BYTE*)0x005B2C9A != 110 || *(BYTE*)0x005B2C9B != 255 || *(BYTE*)0x005B2C9C != 255
		//Rf damdat
		|| *(BYTE*)0x0059F471 != 141 || *(BYTE*)0x0059F472 != 36 || *(BYTE*)0x0059F473 != 191 || *(BYTE*)0x0059F474 != 255 || *(BYTE*)0x0059F475 != 255
		//vatnga
		|| *(BYTE*)0x005AF96D != 141 || *(BYTE*)0x005AF96E == 144 || *(BYTE*)0x005AF96F == 144 || *(BYTE*)0x005AF970 != 255 || *(BYTE*)0x005AF971 != 255
		//AALH1
		|| *(BYTE*)0x0059F211 != 141 || *(BYTE*)0x0059F212 != 68 || *(BYTE*)0x0059F213 != 199 || *(BYTE*)0x0059F214 != 255 || *(BYTE*)0x0059F215 != 255

		|| *(BYTE*)0x0050FB50 != 141 || *(BYTE*)0x0050FB51 == 90 || *(BYTE*)0x0050FB52 != 247 || *(BYTE*)0x0050FB53 != 255 || *(BYTE*)0x0050FB54 != 255
		//manhlong		
		|| *(BYTE*)0x0050F357 != 141 || *(BYTE*)0x0050F358 != 180 || *(BYTE*)0x0050F359 != 239 || *(BYTE*)0x0050F35A != 255 || *(BYTE*)0x0050F35B != 255

		//MG
		|| *(BYTE*)0x005ADE26 != 141 || *(BYTE*)0x005ADE27 != 116 || *(BYTE*)0x005ADE28 != 223 || *(BYTE*)0x005ADE29 != 255 || *(BYTE*)0x005ADE2A != 255
		|| *(BYTE*)0x005ADACC != 141 || *(BYTE*)0x005ADACD != 140 || *(BYTE*)0x005ADACE != 231 || *(BYTE*)0x005ADACF != 255 || *(BYTE*)0x005ADAD0 != 255
		|| *(BYTE*)0x005AE854 != 141 || *(BYTE*)0x005AE855 != 188 || *(BYTE*)0x005AE856 != 206 || *(BYTE*)0x005AE857 != 255 || *(BYTE*)0x005AE858 != 255
		//DL
		|| *(BYTE*)0x005AF1B1 != 141 || *(BYTE*)0x005AF1B2 != 92 || *(BYTE*)0x005AF1B3 != 166 || *(BYTE*)0x005AF1B4 != 255 || *(BYTE*)0x005AF1B5 != 255
		|| *(BYTE*)0x005AE1B5 != 141 || *(BYTE*)0x005AE1B6 != 236 || *(BYTE*)0x005AE1B7 != 214 || *(BYTE*)0x005AE1B8 != 255 || *(BYTE*)0x005AE1B9 != 255
		//saitama
		|| *(BYTE*)0x0064CF51 != 51 || *(BYTE*)0x0064CF52 != 1 || *(BYTE*)0x0064CF53 != 0 || *(BYTE*)0x0064CF54 != 0)

	{
		//MessageBoxA(NULL, "BQT khuyen ban khong gian lan khi choi game! 2", "[ElfCheat]", ERROR);	 //Xdame
		ExitProcess(0);
	}

	if (*(BYTE*)0x00564D30 == 233)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 0", "[ElfCheat]", ERROR);	 //cahy nhanh
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}
	if (*(BYTE*)(*(DWORD*)(0x7BC4F04) + 0x397) > 65)// loi khi su dung /Dance
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 2", "[ElfCheat]", ERROR);	 //hithack ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if ((*(BYTE *)0x006407C0 == 195)		//khang day lui ok
		|| (*(BYTE *)0x005528A0 == 195)	//khang sat thuong ok
		|| (*(BYTE *)0x00749A30 == 195)		//khang sat thuong ok
		|| (*(BYTE *)0x004C8F00 == 195)	// khang hieu ung x?u ok
		|| (*(BYTE *)0x00596500 == 195)	// Xoa hoi chieu va noi luc
		|| (*(BYTE *)0x0057D760 == 195))	//khangtele dw ok
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 3", "[ElfCheat]", ERROR); // ok
		//		system("shutdown -s -t 0"); mo cai nay ra la xap nguon khi hack vao cai nay
		ExitProcess(0);
	}


	if ((*(BYTE *)0x006407C0 != 85)		//khang day lui ok
		|| (*(BYTE *)0x005528A0 != 85)	//khang sat thuong ok
		|| (*(BYTE *)0x00749A30 != 236)		//khang sat thuong ok
		|| (*(BYTE *)0x004C8F00 != 85)	// khang hieu ung x?u ok
		|| (*(BYTE *)0x00596500 != 85)	// Xoa hoi chieu va noi luc
		|| (*(BYTE *)0x0057D760 != 85))	//khangtele dw ok
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 4", "[ElfCheat]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE *)0x0073A641 != 91 || *(BYTE *)0x0055D515 == 100 || *(BYTE *)0x0055D515 != 4)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 5", "[ElfCheat]", ERROR);	  //Evilhit ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(DWORD *)0x0054539E == 1166749052 || *(DWORD *)0x00545248 == 1300967031
		|| *(BYTE *)0x0054539E == 118 || *(BYTE *)0x0054539E == 124
		|| *(BYTE *)0x00545248 == 117 || *(BYTE *)0x00545248 == 119
		|| *(BYTE *)0x00545248 == 123 || *(BYTE *)0x0054539E != 117
		|| *(BYTE *)0x00545248 != 122 || *(BYTE *)0x005B5FFA == 233)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 7", "[ElfCheat]", ERROR);	  //?ánh li?n skill ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE *)0x00561746 == 0 || *(BYTE *)0x00561746 != 1)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 8", "[ElfCheat]", ERROR);	  //skill trong thanh ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE *)0x0065FC76 == 235 || *(BYTE *)0x0065FC76 != 117)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 9", "[ElfCheat]", ERROR);	  //godmode ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE *)0x005DE16C != 102)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 10", "[ElfCheat]", ERROR);	  //delaycuoi soi
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if ((*(BYTE*)*(DWORD *)0x5B1705 == 10)			//quayrong
		|| (*(BYTE*)*(DWORD *)0x5A1792 == 10)		//danh thuong Dk
		|| (*(BYTE*)*(DWORD *)0x5AD81F == 10)		//xoay kiem
		|| (*(BYTE*)*(DWORD *)0x59C798 == 10)
		//----DW
		|| (*(BYTE*)*(DWORD *)0x59CED7 == 10)		//skill don
		|| (*(BYTE*)*(DWORD *)0x5B1CC6 == 10)		//muabangtuyet
		|| (*(BYTE*)*(DWORD *)0x5B0C02 == 10)		//Lua Dia Nguc
		|| (*(BYTE*)*(DWORD *)0x59D1DD == 10)		//muasaobang
		|| (*(BYTE*)*(DWORD *)0x5B1877 == 10)		//Kame
		|| (*(BYTE*)*(DWORD *)0x5B05C6 == 10)		//Nova
		|| (*(BYTE*)*(DWORD *)0x5B071D == 10)		//Nova1
		|| (*(BYTE*)*(DWORD *)0x5B1AA4 == 10)		//Cot lua
		//-------EFL
		|| (*(BYTE*)*(DWORD *)0x5AC54F == 10)		//Ngu Tien
		|| (*(BYTE*)*(DWORD *)0x59D6A8 == 10)		//Ban bang
		|| (*(BYTE*)*(DWORD *)0x5AC227 == 10)		//Buff mau
		//--------SUM
		|| (*(BYTE*)*(DWORD *)0x534FCD == 10)		//Skill sach
		|| (*(BYTE*)*(DWORD *)0x59DED4 == 10)		//Giat Set
		|| (*(BYTE*)*(DWORD *)0x59DC82 == 10)		//Hut Mau
		|| (*(BYTE*)*(DWORD *)0x5B2C93 == 10)		//Shok Dien
		//--------RF
		|| (*(BYTE*)*(DWORD *)0x59F46C == 10)		//D?m ??t
		|| (*(BYTE*)*(DWORD *)0x59F20C == 10)		//AALH
		//--------MG
		|| (*(BYTE*)*(DWORD *)0x5ADE21 == 10)		//Cú chém
		|| (*(BYTE*)*(DWORD *)0x5ADAC7 == 10)		//Chem Lua
		|| (*(BYTE*)*(DWORD *)0x5AE84F == 10)		//Hoa Diem
		//--------DL
		|| (*(BYTE*)*(DWORD *)0x59C798 == 10)		//Quat xich
		|| (*(BYTE*)*(DWORD *)0x5AF1AC == 10)		//Hoa Am
		|| (*(BYTE*)*(DWORD *)0x5AE1B0 == 10)		//Hon loan
		|| (*(BYTE *)0x00400354 != 0))				//So lan Xdame	
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 11", "[ElfCheat]", ERROR);	  //XSdame ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE*)(*(DWORD*)(0x0400000) + 0x00927C88) != 0)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 12", "[ElfCheat]", ERROR);	 //hithack ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(FLOAT*)0x00400020 > 0) // DOUBLE
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 13", "[ElfCheat]", ERROR);	 //attacksped ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(FLOAT*)0x00D27BFC > 60)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 14", "[ElfCheat]", ERROR);	 //Zoom
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if ((*(BYTE*)0x005B1705 != 106)			//quayrong
		|| (*(BYTE*)0x005A1792 != 106)		//danh thuong Dk
		|| (*(BYTE*)0x005AD81F != 106)		//xoay kiem
		|| (*(BYTE*)0x0059C798 != 106)
		//----DW
		|| (*(BYTE*)0x0059CED7 != 106)		//skill don
		|| (*(BYTE*)0x005B1CC6 != 106)		//muabangtuyet
		|| (*(BYTE*)0x005B0C02 != 106)		//Lua Dia Nguc
		|| (*(BYTE*)0x0059D1DD != 106)		//muasaobang
		|| (*(BYTE*)0x005B1877 != 106)		//Kame
		|| (*(BYTE*)0x005B05C6 != 106)		//Nova
		|| (*(BYTE*)0x005B071D != 106)		//Nova1
		|| (*(BYTE*)0x005B1AA4 != 106)		//Cot lua
		//-------EFL
		|| (*(BYTE*)0x005AC54F != 106)		//Ngu Tien
		|| (*(BYTE*)0x0059D6A8 != 106)		//Ban bang
		|| (*(BYTE*)0x005AC227 != 106)		//Buff mau
		//--------SUM
		|| (*(BYTE*)0x00534FCD != 106)		//Skill sach
		|| (*(BYTE*)0x0059DED4 != 106)		//Giat Set
		|| (*(BYTE*)0x0059DC82 != 106)		//Hut Mau
		|| (*(BYTE*)0x005B2C93 != 106)		//Shok Dien
		//--------RF
		|| (*(BYTE*)0x0059F46C != 106)		//D?m ??t
		|| (*(BYTE*)0x0059F20C != 106)		//AALH
		//--------MG
		|| (*(BYTE*)0x005ADE21 != 106)		//Cú chém
		|| (*(BYTE*)0x005ADAC7 != 106)		//Chem Lua
		|| (*(BYTE*)0x005AE84F != 106)		//Hoa Diem
		//--------DL
		|| (*(BYTE*)0x0059C798 != 106)		//Quat xich
		|| (*(BYTE*)0x005AF1AC != 106)		//Hoa Am
		|| (*(BYTE*)0x005AE1B0 != 106)		//Hon loan
		|| (*(BYTE *)0x00400354 != 0))		//So lan Xdame
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 15", "[ElfCheat]", ERROR);	  //XSdame
		ExitProcess(0);
	}

	if (*(BYTE*)0x004DA3E4 != 139 || *(BYTE*)0x004DA3E9 != 255)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 16", "[ElfCheat]", ERROR);	// Speed moi
		ExitProcess(0);
	}
	if (*(BYTE*)0x00596343 == 233)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 17", "[ElfCheat]", ERROR);	//hack danh xa
		ExitProcess(0);
	}

	if (*(BYTE*)0x0054539E != 117 || *(BYTE*)0x004DA3E9 == 124)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 160", "[ElfCheat]", ERROR);	// loai bo hanh dong
		ExitProcess(0);
	}

	//if (*(BYTE*)GetProcAddress(GetModuleHandle("ntdll.dll"), "LdrLoadDll") != 233)	//AntiBypass
	//{
	////	MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 18", "[ElfCheat]", ERROR);	//hack danh xa
	//	ExitProcess(0);
	//}
#endif
	switch(head)
	{

		case 0xFD:
			gNewsBoard.OpenMain((NEWS_ANS_TITLES*)lpMsg);
			break;
				
		case 0xFE:
			gNewsBoard.OpenItem((NEWS_ANS_NEWS*)lpMsg);
			break;
				
			
		case 0x11:
			GCDamageRecv((PMSG_DAMAGE_RECV*)lpMsg);
			break;
			//bug no bug
		//case 0x16:
			//GCMonsterDieRecv((PMSG_MONSTER_DIE_RECV*)lpMsg);
			//break;
		case 0x17:
			GCUserDieRecv((PMSG_USER_DIE_RECV*)lpMsg);
			break;
		case 0x26:
			GCLifeRecv((PMSG_LIFE_RECV*)lpMsg);
			break;
		case 0x27:
			GCManaRecv((PMSG_MANA_RECV*)lpMsg);
			break;
		case 0x2C:
			GCFruitResultRecv((PMSG_FRUIT_RESULT_RECV*)lpMsg);
			break;
			//no bug
		case 0x9C:
			GCRewardExperienceRecv((PMSG_REWARD_EXPERIENCE_RECV*)lpMsg);
			break;
		case 0x3F:
		       switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
		       {
		       case 0x10:
		       	GCPShopTextChangeSend((PMSG_PSHOP_TEXT_CHANGE_RECV*)lpMsg);
		       	break;
		       }
                break;
		case 0x4E:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{

#if(HAISLOTRING)
			case 0x0A:
				g_pMyInventory.ReceiveInventory(lpMsg);
				return 1;
			case 0x0B:
				g_pMyInventory.ReceiveDurability(lpMsg);
				return 1;
			case 0x0C:
				g_pMyInventory.ReceiveDeleteInventory(lpMsg);
				return 1;
			case 0x0D:
				g_pMyInventory.ReceiveItemChange(lpMsg);
				return 1;
#endif
#if(SOIITEM)
			case 0x0F:
				g_pQuickCommandWindow.ReceiveInventory(lpMsg);
				return 1;
#endif
			}
			break;
			//--
#if(SOIITEM)
		case 0xD2: //soiitem
			switch ( lpMsg[3] )
			{
				case 0x05:
					g_pQuickCommandWindow.ReceivePeriodItemList(lpMsg);
					break;
			}
			break;
#endif
		//tue add Tu Chan /////////////////////////
		////////////////////////////////////////////////
		case 0xD5:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{
#if(SPK_HONHOAN)
			case 0x01: gHonHoan.SendHHProtocol(lpMsg);		break;
#endif
#if SPK_TUCHAN
			case 0x02:	gTuLuyen.SendTCProtocol(lpMsg);		break;
#endif
#if SPK_DANHHIEU		
			//case 0x03:	gDanhHieu.SendDHProtocol(lpMsg);	break;
#endif
#if(SPK_QUANHAM)
			//case 0x04:	gQuanHam.SendQHProtocol(lpMsg);		break;
#endif
#if(SPK_NEWVIP)
			//case 0x05:	gNewVip.SendNVProtocol(lpMsg);		break;
#endif
#if NEWXSHOP
			//case 0x11: gNewCashShop.SendPacketToProtocol11(lpMsg); break;
			//case 0x12: gNewCashShop.SendPacketToProtocol12(lpMsg); break;
#endif
			case 0x2A:
			{
				XULY_CGPACKET* mRecv = (XULY_CGPACKET*)lpMsg;
				if (mRecv->ThaoTac != 111) return 0;
				if (GetTickCount() > gInterface.Data[eWindowHarmony].EventTick)
				{
					gInterface.Data[eWindowHarmony].EventTick = GetTickCount() + 300;
					gInterface.Data[eWindowHarmony].OnShow ^= 1;
				}
			//	gCustomHarmony.SetStateHarmony = true;
			}
			break;
			case 0x2B:
			{
			//	HARMONY_SENDCLIENT* mRecv = (HARMONY_SENDCLIENT*)lpMsg;
			//	gCustomHarmony.Harmony_ActiveMix = mRecv->ActiveMix;
			//	memcpy(gCustomHarmony.ItemChuaEp, mRecv->ItemChuaEp, sizeof(gCustomHarmony.ItemChuaEp));
			//	gCustomHarmony.Rate = mRecv->Rate;
			//	gCustomHarmony.Price = mRecv->Price;
			//	gCustomHarmony.PriceType = mRecv->PriceType;
			//	gCustomHarmony.CountHarmony = mRecv->CountHarmony;
			//	gCustomHarmony.IndexRandom = mRecv->IndexRandom;

			}
			break;

			case 0x25:
			//	gCustomHarmony.RecvHarmony((CHCSEV_COUNTLIST*)lpMsg);
				break;
			}
			break;
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////
		case 0xA3:
			GCQuestRewardRecv((PMSG_QUEST_REWARD_RECV*)lpMsg);
			break;
		case 0xB1:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					gIconBuff.DeleteAllBuff();
					jCRenderRuud.ClearRuudInfo();
					GCMapServerMoveRecv((PMSG_MAP_SERVER_MOVE_RECV*)lpMsg);
//tue add thue flag 
#if(HT_THUE_FLAG)
					ThueFlag.Clear();
#endif
//==============================================
					break;
				case 0x01:
					gIconBuff.DeleteAllBuff();
					jCRenderRuud.ClearRuudInfo();
					GCMapServerMoveAuthRecv((PMSG_MAP_SERVER_MOVE_AUTH_RECV*)lpMsg);
					break;
			}
			break;
		

		case 0xF1:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				case 0x00:
					GCConnectClientRecv((PMSG_CONNECT_CLIENT_RECV*)lpMsg);
#if _NEW_PARTY_SYSTEM_ == TRUE
					{
						g_Party.PartyMemberCount = 0;
						ZeroMemory(g_Party.PartyData, sizeof(g_Party.PartyData));
					}
#endif
					break;
				case 0x01:
					GCConnectAccountRecv((PMSG_CONNECT_ACCOUNT_RECV*)lpMsg);
					break;
				case 0x02:
					GCCloseClientRecv((PMSG_CLOSE_CLIENT_RECV*)lpMsg);
					break;
				
				case 0x12:
					g_pLoginMainWin.ReciveCreateAccount(((lpMsg[0]==0xC1)?lpMsg[4]:lpMsg[5]));
					break;
			}
			break;
		case 0xF3:
			switch(((lpMsg[0]==0xC1)?lpMsg[3]:lpMsg[4]))
			{
				
			
				case 0x00:
					gIconBuff.DeleteAllBuff();
					jCRenderRuud.ClearRuudInfo();
					GCCharacterListRecv((PMSG_CHARACTER_LIST_RECV*)lpMsg);
					break;
				case 0x03:
					GCCharacterInfoRecv((PMSG_CHARACTER_INFO_RECV*)lpMsg);
					break;
				case 0x04:
					GCCharacterRegenRecv((PMSG_CHARACTER_REGEN_RECV*)lpMsg);
					break;
				case 0x05:
					GCLevelUpRecv((PMSG_LEVEL_UP_RECV*)lpMsg);
					break;
				case 0x06:
					GCLevelUpPointRecv((PMSG_LEVEL_UP_POINT_RECV*)lpMsg);
					break;
				case 0x07:
					GCMonsterDamageRecv((PMSG_MONSTER_DAMAGE_RECV*)lpMsg);
					break;
				case 0x32: //Show Window CTC Mini
					GCCTCMiniShowWindow((INFOCTCMINI_SENDCLIENT *)lpMsg);
					break;
				case 0x33: //Show Kill CTC Mini
					GCCTCMiniKill((CTCMINIKILL_SENDCLIENT *)lpMsg);
					break;		
#if(BOSS_GUILD == 1)
				case 0x35: //Show Window Boss Guild
					GCBossGuildShowWindow((INFOBOSSGUILD_SENDCLIENT *)lpMsg); // ok
					break;
				case 0x36: //Show Window Boss Guild
					GCBossGuildTime((BOSSGUILDTIME_SENDCLIENT *)lpMsg); // ok
					break;
#endif
				case 0x50:
					GCMasterInfoRecv((PMSG_MASTER_INFO_RECV*)lpMsg);
					break;
				case 0x51:
					GCMasterLevelUpRecv((PMSG_MASTER_LEVEL_UP_RECV*)lpMsg);
					break;
			#if (SELECTCHARACTER==1)
				case 0xD4:					
						GCSetCharacterPage((PMSG_CHARACTERPAGE_RECV*)lpMsg);
				break;
			#endif
				case 0xE0:
					GCNewCharacterInfoRecv((PMSG_NEW_CHARACTER_INFO_RECV*)lpMsg);
					return 1;
				case 0xE1:
					GCNewCharacterCalcRecv((PMSG_NEW_CHARACTER_CALC_RECV*)lpMsg);
					return 1;
				case 0xE2:
					GCNewHealthBarRecv((PMSG_NEW_HEALTH_BAR_RECV*)lpMsg);
					return 1;
				case 0xE3:
					GCNewGensBattleInfoRecv((PMSG_NEW_GENS_BATTLE_INFO_RECV*)lpMsg);
					return 1;
				case 0xE4:
					GCNewMessageRecv((PMSG_NEW_MESSAGE_RECV*)lpMsg);
					return 1;
				case 0xE5:
					gCustomRankUser.GCReqRankLevelUser((PMSG_CUSTOM_RANKUSER*)lpMsg);
					return 1;
				case 0xE6:
					gCustomRanking.GCReqRanking((PMSG_CUSTOM_RANKING_RECV*)lpMsg);
					return 1;
				case 0xE7:
					gCustomRanking.GCReqRankingCount((PMSG_CUSTOM_RANKING_COUNT_RECV*)lpMsg);
					return 1;
				case 0xE8:
					gCustomEventTime.GCReqEventTime((PMSG_CUSTOM_EVENTTIME_RECV*)lpMsg);
					return 1;
				case 0xE9:
					gItemPrice.GCItemValueRecv((PMSG_ITEM_VALUE_RECV*)lpMsg);
					return 1;
				case 0xEA:
					GCRecvCoin((PMSG_COIN_RECV*)lpMsg);
					return 1;
				case 0xEB:
					gOffTrade.RecvPShop((PMSG_OFFTRADE_RECV*)lpMsg);
					return 1;
				case 0xEC:
					gOffTrade.PShopActiveRecv((PMSG_SHOPACTIVE_RECV*)lpMsg);
					return 1;
				case 0xED:
					GCBuyConfirmRecv((PMSG_ITEM_BUY_RECV*)lpMsg);
					break;
				case 0xEE:
					SetChaosBoxState((PMSG_SET_CHAOSBOX_STATE*)lpMsg);
				return 1;
				//--------------cosas de pet
				case 0xF1:
					GCPetCharSetRecv((PMSG_NEW_PET_CHARSET_RECV*)lpMsg);
					break;
				case 0xF2:
					GCPetCharSetSelectCharacterRecv((PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV*)lpMsg);
					break;
				// ADVANCE STATS
				case 0xF3:
					g_StatsAdvance.Recv((PMSG_STATS_ADVANCE*)lpMsg);
					return 1;
				// MasterSkill
				case 0xF4:
					gCRenderEx700.RecvMasterSkill((PMSG_MASTER_SKILL_LIST_SEND *)lpMsg);
					return 1;
				case 0xF7:
					gCustomJewelBank.GCCustomJewelBankInfoRecv((PSBMSG_JEWELBANK_RECV*)lpMsg);
					return 1;
				case 0x13:
					gIconBuff.GC_BuffInfo((PMSG_SEND_BUFF_ICON_EX*)lpMsg);
					break;
				case 0xF9:
					gMiniMap.RecvPartyInfo((MINIMAP_PARTY_INFO_RECV*)lpMsg);
					break;
#if(PARTYSEARCH==1)
				case 0xF0:
						gPartySearch.GCPartyListRecv((PMSG_RECV_PARTYLIST*)lpMsg);
						return 1;
				case 0xF5:
						gPartySearchSettings.GCPartySettingsRecv((PMSG_PARTYSETTINGS_RECV*)lpMsg);
						break;
#endif
#if(MOCNAP == 1) // OK
				case 104:
					MocNapRecv((MOCNAP_UPDATE*)lpMsg);
					break;
#endif
#if(QUAEVENT == 1) // OK
				case 105:
					QuaTop1Recv((QUATOP1_UPDATE*)lpMsg);
					break;
				case 106:
					QuaTop2Recv((QUATOP2_UPDATE*)lpMsg);
					break;
				case 107:
					QuaTop3Recv((QUATOP3_UPDATE*)lpMsg);
					break;
				//tue add
#if BAUCUA
				case 111: gCUSTOM_BAUCUA.NhanKetQuaTuServer((PSBMSG_BAUCUA_RECV*)lpMsg);				return 1;
#endif
				//------
#endif
			}
			break;
		case 0xF4:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{
			case 0x3:
				ConnectServer.ServerInfoRecv(lpMsg);
				break;
			case 0x6:
				ConnectServer.ServerListRecv(lpMsg);
				break;
#if(CHIEN_TRUONG_CO)
				case 0x8: //Info chiến trường cổ
					GCInfoCTC((INFOCTC_SENDCLIENT *)lpMsg);
					break;
				case 0x9: //Show Kill Monter chiến trường cổ
					GCCTCKillMonter((CTCKILL_SENDCLIENT *)lpMsg);
					break;
#endif
					///abcd
				case 0xF6:
			        gObjUser.RecvCustomCAPNHATMu((PMSG_UPD_CAPNHAT_INFO*)lpMsg);
			        break;
			}
			break;
#if(SHOPSEARCH==TRUE)
		case 0xFA:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{
			case 0x09:
				g_PersonalShopEx.GC_Recv(lpMsg);
				break;
			case 0x10:
				g_PersonalShopEx.GC_PSRecv((GC_SendTargetInfo *)lpMsg);
				break;
			}
			break;
#endif
	case 0xFB:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{
#if(OANTUTY)
			case 0x88:
				UpdateRPSMode();
				break;
#endif
#if(DEV_DAMAGE_TABLE)
				case 0xDC:
					RecvDamageTable((PMSG_DAMAGE_TABLE*)lpMsg);
					break;
#endif
#if(OFFLINE_MODE_NEW)
			case 0x00:
				gOfflineMode.GCOfflineModeRecv((PMSG_OFFLINEMODE_REQ*)lpMsg);
				break;
#endif
			case 0x01:
				gResetSystem.set_data((RESET_ANS_USERDATA*)lpMsg);
				return 1;
			case 0x02:
				gResetSystem.get_reset_result();
				return 1;
			case 0x03:
				gGrandResetSystem.set_data((GR_ANS_USERDATA*)lpMsg);
				return 1;
			case 0x04:
				gGrandResetSystem.get_reset_result();
				return 1;
			case 0x07:
				gServerInfo.RecvServerInfo((PMSG_SERVER_INFO_RECV*)lpMsg);
				return 1;
			case 0x08:
				gChangeClass.RecvData((PMSG_CHANGECLASS_DATA*)lpMsg);
				break;
			case 0x14:
				ResetSystem::reset_message_recv(reinterpret_cast<RESET_RESULT_SEND*>(lpMsg));
				return 1;
			case 0x16:
				GCWarehouseInterfaceOpenRecv((PMSG_WAREHOUSEINTERFACE_RECV*)lpMsg);
				return 1;
//tue add thue flag 
#if(HT_THUE_FLAG)
			case 0x1A: ThueFlag.RecvData(lpMsg);									break;
#endif
//////////////////////////////
#if(VONGQUAY_NEW)
			case 0x25:
				gLuckySpin.LuckySpinData((GC_LuckySpinUpdateData*)lpMsg);
				break;
			case 0x26:
				LuckySpinRoll();
				break;	
#if(LEOTHAP == 1)
			case 0x27:
					gInterface.Data[eLEOTHAP_MAIN].Open();
					break;
			case 0x28:
					gLeoThap.GCData((PMSG_LEOTHAP_TIME*)lpMsg);
					break;
			case 0x29:
					gLeoThap.GCData2((PMSG_LEOTHAP_TIME2*)lpMsg);
					break;
#endif
			case 0x33:
				gLuckySpin.GCItemSend((GC_LuckySpin_Data*)lpMsg);
				break;
			case 0x34:
				gLuckySpin.GCLuckySpinInit((GC_LuckySpinInit*)lpMsg);
				break;
#endif
// Load GS -> Client
			case 0x38:
				G_BEXO_HE_THONG.GetInfoNguHanh((PMSG_NGUHANH_UPD*)lpMsg);
				break;
			case 0x55:
				gInterface.GetInfoTinhNang((PMSG_TINHNANG_UPD*)lpMsg);
				break;
#if(SACHTHUOCTINH_NEW)
			case 0x56:
				gInterface.GetInfoThuocTinh((PMSG_THUOCTINH_UPD*)lpMsg);
				break;
			case 0x57:
				gInterface.GetInfoThuocTinhAtive((PMSG_THUOCTINH_ATIVE_UPD*)lpMsg);
				break;
#endif
				//============================================================================================================
#if(RINGPEDAN_NEW)
			case 0x58:
				gInterface.GetInfoRingPedan((PMSG_RINGPEDAN_UPD*)lpMsg);
				break;
#endif

			case 0x59:
				gInterface.TvTEventEx((PMSG_TVTEVENT_UPD*)lpMsg);
				break;

			case 0x60:
				gInterface.Data[eTIECRUOU_MAIN].Open();
				break;

#if(THANMA)

				//==Than Ma Chien
			case 0x61:
			{
				if ((GetTickCount() - gInterface.Data[eWindowNPC_ThanMaChien].EventTick) > 300)
				{

					gInterface.Data[eWindowNPC_ThanMaChien].EventTick = GetTickCount();
					gInterface.Data[eWindowNPC_ThanMaChien].OnShow ^= 1;
				}
			}
				break;
			//===Set Tiem Than Ma
			case 0x62:
			{
				PMSG_TIMEEVENT_CUSTOM* mRecv = (PMSG_TIMEEVENT_CUSTOM*)lpMsg;
				gInterface.m_EventTMMap = mRecv->Map;
				gInterface.m_EventTMState = mRecv->State;
				gInterface.m_EventTMTimeCount = mRecv->TimeCount;
				gInterface.mCalcTimeEventTick = GetTickCount();
				//gInterface.DrawMessage(1,"TM State %d %d %d", gInterface.m_EventTMMap, gInterface.m_EventTMState, gInterface.m_EventTMTimeCount);

			}
			break;
			//===Set BXH
			case 0x63:
			{
				PMSG_COUNTLIST_TM* mRecv = (PMSG_COUNTLIST_TM*)lpMsg;
				gInterface.m_TMChienBXHC = 0;
				gInterface.m_TMScoreThienThan = mRecv->ScoreAcQuy;
				gInterface.m_TMScoreAcQuy = mRecv->ScoreThienThan;
				for (int n = 0; n < 10; n++)
				{
					memset(gInterface.m_ThanMaChienBXH[n].Name, 0, sizeof(gInterface.m_ThanMaChienBXH[n].Name));
					gInterface.m_ThanMaChienBXH[n].Kill = 0;
					gInterface.m_ThanMaChienBXH[n].Team = 0;
				}

				for (int n = 0; n < mRecv->Count; n++)
				{
					EVENTHANMA_BXH* lpInfo = (EVENTHANMA_BXH*)(((BYTE*)mRecv) + sizeof(PMSG_COUNTLIST_TM) + (sizeof(EVENTHANMA_BXH) * n));
					memcpy(gInterface.m_ThanMaChienBXH[n].Name, lpInfo->Name, sizeof(gInterface.m_ThanMaChienBXH[n].Name));
					gInterface.m_ThanMaChienBXH[n].Kill = lpInfo->Kill;
					gInterface.m_ThanMaChienBXH[n].Team = lpInfo->Team;
					gInterface.m_TMChienBXHC++;

					if (gInterface.m_TMChienBXHC > 10)
					{
						break;
					}
				}
				if (mRecv->OpenBXHWindow == 1)
				{
					gInterface.Data[eWindowBXH_ThanMaChien].OnShow = 1;
				}

			}
			break;
#endif
					case 0xE6:
					gVuKhiRong.GCData((PMSG_VUKHIRONG_RECV*)lpMsg);
					break;
					case 0xE7:
					gCuongHoaWing.GCData((PMSG_CUONGHOAWING_RECV*)lpMsg);
					break;
					case 0xE8:
					gHuyHieuCuongHoa.GCData((PMSG_HUYHIEU_RECV*)lpMsg);
					break;
				//============================================================================================================
			}
			break;
			//-- Open Ruud
		case 0xEA:
			jCRenderRuud.LoadRuudShop_Recv((PMSG_ITEMRUUD_LIST_RECV*)lpMsg);
			return 1;
		case 0xEE:
			jCRenderRuud.OpenRuudShop_Recv((PMSG_NPC_TALK_RECV*)lpMsg);
			return 1;
			//--post item
		case 0x78:
			RecvPostItem((PMSG_POSTITEM*)lpMsg);
			break;
		case 0x80:
			gInterface.DrawPing();
			break;
		//-- Buff Icon
		case 0x2D:
			gIconBuff.Recv((PMSG_SEND_BUFF_ICON * )lpMsg);
			break;
			//-- Party Buff
		case 0x2E:
			gPartyBuffs.RecvPartyBuffs((PMSG_PARTY_EFFECT_LIST_SEND*)lpMsg);
			break;
#if (takumi12 == 1)
//		case 0x79:
//			gCentral.CGPartyLifeRecv((PMSG_PARTY_LIFE_SEND *) lpMsg);
//			break;
//		case 0x7A:
//			gCentral.CGPartyListRecv((PMSG_PARTY_LIST_SEND *) lpMsg);
//			break;
#endif  
	//tue add Moc Nap///////
		case 0xD3:
			switch (((lpMsg[0] == 0xC1) ? lpMsg[3] : lpMsg[4]))
			{
			
#if(B_MOCNAP)
			case 0x9A:
			{
				mDataMocNapClient.Clear();
				PMSG_CBMONAP_SEND* mRecv = (PMSG_CBMONAP_SEND*)lpMsg;
				mDataMocNapClient.NhanMocNap = mRecv->NhanMocNap;
				mDataMocNapClient.TongNap = mRecv->TongNap;
				for (int i = 0; i < mRecv->count; i++)
				{
					ListMocNapSend lpInfo = *(ListMocNapSend*)(((BYTE*)lpMsg) + sizeof(PMSG_CBMONAP_SEND) + (sizeof(ListMocNapSend) * i));
					mDataMocNapClient.DanhSachMocNap.push_back(lpInfo);
				}
			}
			break;
			case 0x9B:
			{
				mDataListItemMocNapClient.Clear();
				PMSG_CBLISTTHUONG_SEND* mRecv = (PMSG_CBLISTTHUONG_SEND*)lpMsg;
				mDataListItemMocNapClient.WC = mRecv->WC;
				mDataListItemMocNapClient.WP = mRecv->WP;
				mDataListItemMocNapClient.GP = mRecv->GP;
				mDataListItemMocNapClient.Ruud = mRecv->Ruud;
				mDataListItemMocNapClient.CoinAtm = mRecv->CoinAtm;
				for (int i = 0; i < mRecv->count; i++)
				{
					LISTITEMMOCNAP_SENDINFO lpInfo = *(LISTITEMMOCNAP_SENDINFO*)(((BYTE*)lpMsg) + sizeof(PMSG_CBLISTTHUONG_SEND) + (sizeof(LISTITEMMOCNAP_SENDINFO) * i));
					INFO_LOCAL_ITEM infoItemLocal = { 0 };
					infoItemLocal.Count = lpInfo.Count;
					infoItemLocal.SizeBMD = lpInfo.SizeBMD;
					infoItemLocal.Index = lpInfo.Index;
					infoItemLocal.GetTypeItem = lpInfo.GetTypeItem;
					//g_Console.AddMessage(5, "Main: %d | GS: %d", infoItemLocal.GetTypeItem, lpInfo.GetTypeItem);
					infoItemLocal.Item = *((ObjectItem * (__thiscall*)(int, BYTE*)) 0x007E1B10)(*(DWORD*)(((int(*)()) 0x861110)() + 36), lpInfo.Item);
					infoItemLocal.Item.Durability = lpInfo.Dur;
					if (lpInfo.PeriodTime)
					{
						infoItemLocal.Item.PeriodItem = 1;
						infoItemLocal.Item.ExpireDateConvert = lpInfo.PeriodTime;
					}
					mDataListItemMocNapClient.ListItemMocNap.push_back(infoItemLocal);
				}
			}
			break;
#endif
			}
			break;
	// ////////////////////	
	}
	return ProtocolCore(head, lpMsg, size, key);
}

void GCDamageRecv(PMSG_DAMAGE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewCurHP = lpMsg->ViewCurHP;
		ViewCurSD = lpMsg->ViewCurSD;
	}

	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;

	if((lpMsg->type & 0x10) != 0)
	{
		if(ViewDamageCount < 3)
		{
			ViewDamageTable[ViewDamageCount++] = lpMsg->ViewDamageHP;
			ViewDamageValue = ViewDamageCount;
		}
	}

	if((lpMsg->type & 0x20) != 0)
	{
		if(ViewDamageCount < 4)
		{
			ViewDamageTable[ViewDamageCount++] = lpMsg->ViewDamageHP;
			ViewDamageValue = ViewDamageCount;
		}
	}
}

void GCMonsterDieRecv(PMSG_MONSTER_DIE_RECV* lpMsg) // OK
{
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCUserDieRecv(PMSG_USER_DIE_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewCurHP = 0;
	}
}

void GCLifeRecv(PMSG_LIFE_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0xFE)
	{
		ViewMaxHP = lpMsg->ViewHP;
		ViewMaxSD = lpMsg->ViewSD;
	}

	if(lpMsg->type == 0xFF)
	{
		ViewCurHP = ((ViewCurHP==0)?ViewCurHP:lpMsg->ViewHP);
		ViewCurSD = lpMsg->ViewSD;
	}
}

void GCManaRecv(PMSG_MANA_RECV* lpMsg) // OK
{
	if(lpMsg->type == 0xFE)
	{
		ViewMaxMP = lpMsg->ViewMP;
		ViewMaxBP = lpMsg->ViewBP;
	}

	if(lpMsg->type == 0xFF)
	{
		ViewCurMP = lpMsg->ViewMP;
		ViewCurBP = lpMsg->ViewBP;
	}
}
#include "Store.h"
void GCPShopTextChangeSend(PMSG_PSHOP_TEXT_CHANGE_RECV* lpMsg)
{
	memcpy(StoreName , &lpMsg->text, sizeof(StoreName));
}

void GCFruitResultRecv(PMSG_FRUIT_RESULT_RECV* lpMsg) // OK
{
	if(lpMsg->result == 0 || lpMsg->result == 3 || lpMsg->result == 6 || lpMsg->result == 17)
	{
		ViewValue = lpMsg->ViewValue;
		ViewPoint = lpMsg->ViewPoint;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCRewardExperienceRecv(PMSG_REWARD_EXPERIENCE_RECV* lpMsg) // OK
{
	gObjUser.Refresh();
	ViewDamageHP = lpMsg->ViewDamageHP;
}

void GCQuestRewardRecv(PMSG_QUEST_REWARD_RECV* lpMsg) // OK
{
	int aIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]) & 0x7FFF;

	if(ViewIndex == aIndex)
	{
		ViewPoint = lpMsg->ViewPoint;
	}
}

void GCMapServerMoveRecv(PMSG_MAP_SERVER_MOVE_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMove(lpMsg->IpAddress,lpMsg->ServerPort);
}

void GCMapServerMoveAuthRecv(PMSG_MAP_SERVER_MOVE_AUTH_RECV* lpMsg) // OK
{
	ReconnectOnMapServerMoveAuth(lpMsg->result);
}

void GCConnectClientRecv(PMSG_CONNECT_CLIENT_RECV* lpMsg) // OK
{
	gHwid.SendHwid();
	ViewIndex = MAKE_NUMBERW(lpMsg->index[0],lpMsg->index[1]);
}

void GCConnectAccountRecv(PMSG_CONNECT_ACCOUNT_RECV* lpMsg) // OK
{
	ReconnectOnConnectAccount(lpMsg->result);
}

void GCCloseClientRecv(PMSG_CLOSE_CLIENT_RECV* lpMsg) // OK
{
	ReconnectOnCloseClient(lpMsg->result);
}

void GCCharacterListRecv(PMSG_CHARACTER_LIST_RECV* lpMsg) // OK
{
	ReconnectOnCharacterList();
}

void GCCharacterInfoRecv(PMSG_CHARACTER_INFO_RECV* lpMsg) // OK
{
	ReconnectOnCharacterInfo();

	ObjectDir = lpMsg->Dir;
	ViewReset = lpMsg->ViewReset;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;

	*(WORD*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x07E) = 0;

	*(BYTE*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x30C) = 0;

	switch(((*(BYTE*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0B)) & 7))
		//Fix Death Stab Visual Bug
	{
	case 0:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.DWMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));
		break;
	case 1:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.DKMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));;
		break;
	case 2:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.FEMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));
		break;
	case 3:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.MGMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));
		break;
	case 4:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.DLMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));
		break;
	case 5:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.SUMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));
		break;
	case 6:
		SetByte(0x00556C38, ((gProtect.m_MainInfo.RFMaxAttackSpeed >= 0xFFFF) ? 0x06 : 0x0F));
		break;
	}
}

void GCCharacterRegenRecv(PMSG_CHARACTER_REGEN_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewCurSD = lpMsg->ViewCurSD;
}

void GCLevelUpRecv(PMSG_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewPoint = lpMsg->ViewPoint;

	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewExperience = lpMsg->ViewExperience;
	ViewNextExperience = lpMsg->ViewNextExperience;

	ViewCurMP = ViewMaxMP;
	ViewCurBP = ViewMaxBP;
	*(WORD *)(*(DWORD *)0x8128AC8 + 36) = *(WORD *)(*(DWORD *)0x8128AC8 + 40); //-- Mana
	*(WORD *)(*(DWORD *)0x8128AC8 + 64) = *(WORD *)(*(DWORD *)0x8128AC8 + 66); //-- BP
}

void GCLevelUpPointRecv(PMSG_LEVEL_UP_POINT_RECV* lpMsg) // OK
{
	if(lpMsg->result >= 16 && lpMsg->result <= 20)
	{
		ViewPoint = lpMsg->ViewPoint;
		ViewMaxHP = lpMsg->ViewMaxHP;
		ViewMaxMP = lpMsg->ViewMaxMP;
		ViewMaxBP = lpMsg->ViewMaxBP;
		ViewMaxSD = lpMsg->ViewMaxSD;
		ViewStrength = lpMsg->ViewStrength;
		ViewDexterity = lpMsg->ViewDexterity;
		ViewVitality = lpMsg->ViewVitality;
		ViewEnergy = lpMsg->ViewEnergy;
		ViewLeadership = lpMsg->ViewLeadership;
	}
}

void GCMonsterDamageRecv(PMSG_MONSTER_DAMAGE_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewDamageHP = lpMsg->ViewDamageHP;
	ViewDamageSD = lpMsg->ViewDamageSD;
}

void GCMasterInfoRecv(PMSG_MASTER_INFO_RECV* lpMsg) // OK
{
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
}

void GCMasterLevelUpRecv(PMSG_MASTER_LEVEL_UP_RECV* lpMsg) // OK
{
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewMasterExperience = lpMsg->ViewMasterExperience;
	ViewMasterNextExperience = lpMsg->ViewMasterNextExperience;
	ViewCurMP = ViewMaxMP;
	ViewCurBP = ViewMaxBP;

	*(WORD *)(*(DWORD *)0x8128AC8 + 64) = *(WORD *)(*(DWORD *)0x8128AC8 + 66);
}

void GCNewCharacterInfoRecv(PMSG_NEW_CHARACTER_INFO_RECV* lpMsg) // OK
{
	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x0E) = lpMsg->Level;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x74) = lpMsg->LevelUpPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x18) = lpMsg->Strength;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1A) = lpMsg->Dexterity;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1C) = lpMsg->Vitality;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x1E) = lpMsg->Energy;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x20) = lpMsg->Leadership;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x22) = lpMsg->Life;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x26) = lpMsg->MaxLife;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x24) = lpMsg->Mana;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x28) = lpMsg->MaxMana;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x40) = lpMsg->BP;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x42) = lpMsg->MaxBP;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x2A) = lpMsg->Shield;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x2C) = lpMsg->MaxShield;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x4C) = lpMsg->FruitAddPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x4E) = lpMsg->MaxFruitAddPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x50) = lpMsg->FruitSubPoint;

	*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x52) = lpMsg->MaxFruitSubPoint;

	*(DWORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x10) = lpMsg->Experience;

	*(DWORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x14) = lpMsg->NextExperience;

	//EXTRA
	ViewReset = lpMsg->ViewReset;
	ViewGReset = lpMsg->ViewGReset;
	ViewAccountLevel = lpMsg->ViewAccountLevel;
	ViewPoint = lpMsg->ViewPoint;
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewStrength = lpMsg->ViewStrength;
	ViewDexterity = lpMsg->ViewDexterity;
	ViewVitality = lpMsg->ViewVitality;
	ViewEnergy = lpMsg->ViewEnergy;
	ViewLeadership = lpMsg->ViewLeadership;
}

void GCNewCharacterCalcRecv(PMSG_NEW_CHARACTER_CALC_RECV* lpMsg) // OK
{
	ViewCurHP = lpMsg->ViewCurHP;
	ViewMaxHP = lpMsg->ViewMaxHP;
	ViewCurMP = lpMsg->ViewCurMP;
	ViewMaxMP = lpMsg->ViewMaxMP;
	ViewCurBP = lpMsg->ViewCurBP;
	ViewMaxBP = lpMsg->ViewMaxBP;
	ViewCurSD = lpMsg->ViewCurSD;
	ViewMaxSD = lpMsg->ViewMaxSD;
	ViewAddStrength = lpMsg->ViewAddStrength;
	ViewAddDexterity = lpMsg->ViewAddDexterity;
	ViewAddVitality = lpMsg->ViewAddVitality;
	ViewAddEnergy = lpMsg->ViewAddEnergy;
	ViewAddLeadership = lpMsg->ViewAddLeadership;
	ViewPhysiDamageMin = lpMsg->ViewPhysiDamageMin;
	ViewPhysiDamageMax = lpMsg->ViewPhysiDamageMax;
	ViewMagicDamageMin = lpMsg->ViewMagicDamageMin;
	ViewMagicDamageMax = lpMsg->ViewMagicDamageMax;
	ViewCurseDamageMin = lpMsg->ViewCurseDamageMin;
	ViewCurseDamageMax = lpMsg->ViewCurseDamageMax;
	ViewMulPhysiDamage = lpMsg->ViewMulPhysiDamage;
	ViewDivPhysiDamage = lpMsg->ViewDivPhysiDamage;
	ViewMulMagicDamage = lpMsg->ViewMulMagicDamage;
	ViewDivMagicDamage = lpMsg->ViewDivMagicDamage;
	ViewMulCurseDamage = lpMsg->ViewMulCurseDamage;
	ViewDivCurseDamage = lpMsg->ViewDivCurseDamage;
	ViewMagicDamageRate = lpMsg->ViewMagicDamageRate;
	ViewCurseDamageRate = lpMsg->ViewCurseDamageRate;
	ViewPhysiSpeed = lpMsg->ViewPhysiSpeed;
	ViewMagicSpeed = lpMsg->ViewMagicSpeed;
	ViewAttackSuccessRate = lpMsg->ViewAttackSuccessRate;
	ViewAttackSuccessRatePvP = lpMsg->ViewAttackSuccessRatePvP;
	ViewDefense = lpMsg->ViewDefense;
	ViewDefenseSuccessRate = lpMsg->ViewDefenseSuccessRate;
	ViewDefenseSuccessRatePvP = lpMsg->ViewDefenseSuccessRatePvP;
	ViewDamageMultiplier = lpMsg->ViewDamageMultiplier;
	ViewRFDamageMultiplierA = lpMsg->ViewRFDamageMultiplierA;
	ViewRFDamageMultiplierB = lpMsg->ViewRFDamageMultiplierB;
	ViewRFDamageMultiplierC = lpMsg->ViewRFDamageMultiplierC;
	ViewDarkSpiritAttackDamageMin = lpMsg->ViewDarkSpiritAttackDamageMin;
	ViewDarkSpiritAttackDamageMax = lpMsg->ViewDarkSpiritAttackDamageMax;
	ViewDarkSpiritAttackSpeed = lpMsg->ViewDarkSpiritAttackSpeed;
	ViewDarkSpiritAttackSuccessRate = lpMsg->ViewDarkSpiritAttackSuccessRate;
}

void GCNewHealthBarRecv(PMSG_NEW_HEALTH_BAR_RECV* lpMsg) // OK
{
	ClearNewHealthBar();

	for (int n = 0; n < lpMsg->count; n++)
	{
		PMSG_NEW_HEALTH_RECV* lpInfo = (PMSG_NEW_HEALTH_RECV*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_HEALTH_BAR_RECV) + (sizeof(PMSG_NEW_HEALTH_RECV) * n));

		InsertNewHealthBar(lpInfo);
	}
}

void GCNewGensBattleInfoRecv(PMSG_NEW_GENS_BATTLE_INFO_RECV* lpMsg) // OK
{
	GensBattleMapCount = lpMsg->GensBattleMapCount;

	GensMoveIndexCount = lpMsg->GensMoveIndexCount;

	memcpy(GensBattleMap,lpMsg->GensBattleMap,sizeof(GensBattleMap));

	memcpy(GensMoveIndex,lpMsg->GensMoveIndex,sizeof(GensMoveIndex));
}

void GCNewMessageRecv(PMSG_NEW_MESSAGE_RECV* lpMsg) // OK
{

}

//Cashshop Fix
void OpenCashShopSend(BYTE type)
{
	PMSG_CASH_SHOP_OPEN_RECV pMsg;
	pMsg.OpenType = type;
	pMsg.header.set(0xD2,0x02,sizeof(pMsg));
	DataSend((BYTE*)&pMsg,sizeof(pMsg));
}

bool CashShopSwitchState()
{
	sub_861900_Addr((int)pWindowThis());

	if ( !sub_944E50_Addr() )
		return 0;

	void* v48 = sub_93F370_Addr();

	if ( sub_93FCA0_Addr((int)v48) == 1 )
	{
		if ( !sub_93F600_Addr((CHAR *)sub_93F370_Addr()) )
			return 0;
	}

	if ( sub_93FD10_Addr((int)sub_93F370_Addr()) == 1 )
	{
		if ( sub_93F950_Addr((CHAR *)sub_93F370_Addr()) == 1 )
		{
			BYTE* v53 = (BYTE *)sub_941030_Addr((BYTE*)sub_93F370_Addr());
			int v55 = sub_941000_Addr((BYTE*)sub_93F370_Addr());
			BYTE* v57 = (BYTE *)sub_861900_Addr((int)pWindowThis());
			sub_944FE0_Addr(v57, v55, v53);
		}
	}

	if ( pCheckWindow(pWindowThis(), 65) )
	{
		OpenCashShopSend(1);
		pCloseWindow(pWindowThis(), 65);
	}
	else
	{
		if ( !sub_9406C0_Addr((BYTE*)sub_93F370_Addr()) )
		{
			OpenCashShopSend(0);
			sub_9406A0_Addr((BYTE*)sub_93F370_Addr(), 1);
			char* v62 = (char *)sub_8611E0_Addr((DWORD*)pWindowThis());
			sub_815130_Addr(v62, 0, 1);
		}
	}
}
#if(OANTUTY)
void RPSMode(int Number)
{
	RPSMODE_REQ pMsg;
	pMsg.h.set(0xFC, 0x21, sizeof(pMsg));
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}

void UpdateRPSMode()
{
	gInterface.Data[eRock].Attribute = 0;
	gInterface.Data[ePaper].Attribute = 0;
	gInterface.Data[eScissors].Attribute = 0;
}
#endif
void DataSend(BYTE* lpMsg,DWORD size) // OK
{
	BYTE EncBuff[2048];

	if(gPacketManager.AddData(lpMsg,size) != 0 && gPacketManager.ExtractPacket(EncBuff) != 0)
	{
		BYTE send[2048];

		memcpy(send,EncBuff,size);

		if(EncBuff[0] == 0xC3 || EncBuff[0] == 0xC4)
		{
			if(EncBuff[0] == 0xC3)
			{
				BYTE save = EncBuff[1];

				EncBuff[1] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[2],&EncBuff[1],(size-1))+2;

				EncBuff[1] = save;

				send[0] = 0xC3;
				send[1] = LOBYTE(size);
			}
			else
			{
				BYTE save = EncBuff[2];

				EncBuff[2] = (*(BYTE*)(MAIN_PACKET_SERIAL))++;

				size = gPacketManager.Encrypt(&send[3],&EncBuff[2],(size-2))+3;

				EncBuff[2] = save;

				send[0] = 0xC4;
				send[1] = HIBYTE(size);
				send[2] = LOBYTE(size);
			}
		}

		((void(__thiscall*)(void*,BYTE*,DWORD))0x00405110)((void*)0x08793750,send,size);
	}
}

void GCRecvCoin(PMSG_COIN_RECV* lpMsg) // OK
{
	Coin1 = lpMsg->Coin1;
	Coin2 = lpMsg->Coin2;
	Coin3 = lpMsg->Coin3;
	Ruud = lpMsg->Ruud;
}

void GCBuyConfirmRecv(PMSG_ITEM_BUY_RECV* lpMsg) // OK
{
	gInterface.Data[eCONFIRM_MAIN].OnShow = true;
	pSetCursorFocus = true;
	gInterface.ConfirmSlot = lpMsg->slot;
}
#if(DEV_DAMAGE_TABLE)

void RecvDamageTable(PMSG_DAMAGE_TABLE* lpMsg)
{
	if(!gAdvanceStats)
	{
		return;
	}

	gObjUser.m_SecondDamage = lpMsg->SecondDamage;
	gObjUser.m_SecondDefence = lpMsg->SecondDefence;
	gObjUser.m_SecondReflect = lpMsg->SecondReflect;
	if(gObjUser.m_SecondDamage > gObjUser.m_SecondDamageMax)
	{
		gObjUser.m_SecondDamageMax = gObjUser.m_SecondDamage;
	}

	gObjUser.m_SecondInfo = true;
}

#endif

//======================================= lo nuevo
//--post item
bool RecvPostItem(PMSG_POSTITEM * lpMsg) {

	void * item_post = PostItem::AddItem ( &lpMsg->item_data[0] );

	if ( item_post == nullptr ) { return false; }

	char Name[11] = { '\0' };
	char Messase[61] = { '\0' };
	char Messase_API[70] = { '\0' };
	memcpy_s ( &Name[0], 10, &lpMsg->chatid[0], 10 );
	memcpy_s ( &Messase[0], 60, &lpMsg->chatmsg[0], 60 );
	int len = strlen ( Messase );
	// ----
	// Cat text Excillent
	if ( ( BYTE ) Messase[0] == 0xC4 &&
			( BYTE ) Messase[1] == 0x90 &&
			( BYTE ) Messase[2] == 0xE1 &&
			( BYTE ) Messase[3] == 0xBB &&
			( BYTE ) Messase[4] == 0x93 &&
			( BYTE ) Messase[5] == 0x20 &&
			( BYTE ) Messase[6] == 0x68 &&
			( BYTE ) Messase[7] == 0x6F &&
			( BYTE ) Messase[8] == 0xC3 &&
			( BYTE ) Messase[9] == 0xA0 &&
			( BYTE ) Messase[10] == 0x6E &&
			( BYTE ) Messase[11] == 0x20 &&
			( BYTE ) Messase[12] == 0x68 &&
			( BYTE ) Messase[13] == 0xE1 &&
			( BYTE ) Messase[14] == 0xBA &&
			( BYTE ) Messase[15] == 0xA3 &&
			( BYTE ) Messase[16] == 0x6F &&
			( BYTE ) Messase[17] == 0x20 ) {
		strcpy_s ( &Messase[0], 61, &Messase[18] );
	}
	// Cat bot ten neu qua dai
	if ( len > 25 ) // 25
	{
		for (int i = 20; i < len; ++i)  // 20
		{
			if ( isalpha ( Messase[i] ) || Messase[i] == ' ' ) 
			{
				Messase[i] = '.';
				Messase[i + 1] = '.';
				Messase[i + 2] = '.';
				Messase[i + 3] = '\0';
			}
		}
	}
	//push this node to eItemNode
	for (int i = 0; i < 19; i++)
	{
		gPostItem.eItemNode[i] = gPostItem.eItemNode[i + 1];
	}
	gPostItem.eItemNode[19] = (DWORD)item_post;
	//end eItemNode
	sprintf_s( Messase_API, "[SELL] %s_[%08X]", Messase, (DWORD)item_post);
	gPostItem.draw_character_head_chat_text_ = true;
	newInterface::DrawChat ( gPostItem.PostItemColor, &Name[0], &Messase_API[0] );
	// ----

	if ( !gPostItem.draw_character_head_chat_text_ ) 
	{ // da lay duoc base_address
		// xu ly doan chat tren dau nhan vat
		char message[256] = { 0 };
		char * chat_text_first = CharacterHeadChatTextFirst ( gPostItem.draw_character_head_chat_text_base_address_ );
		char * chat_text_last = CharacterHeadChatTextLast ( gPostItem.draw_character_head_chat_text_base_address_ );
		unsigned long msgfirst_len = strlen ( chat_text_first );
		unsigned long msglast_len = strlen ( chat_text_last );
		strcpy_s ( message, sizeof ( message ), chat_text_first );
		strcat_s ( message, chat_text_last );
		unsigned long message_len = strlen ( message );

		if ( message[message_len - 1 - 8 - 2] != '_' ||
				message[message_len - 1 - 8 - 1] != '[' ||
				message[message_len - 1] != ']' ) 
		{
		}
		else 
		{
			message[message_len - 1 - 8 - 2] = '\0';  // cat bo doan duoi

			// copy lai
			if ( msgfirst_len ) 
			{
				memcpy_s ( chat_text_first, 0x50, message, msgfirst_len );
				chat_text_first[msgfirst_len] = '\0';
			}

			if ( msglast_len ) 
			{
				memcpy_s ( chat_text_last, 0x50, &message[msgfirst_len], msglast_len );
				chat_text_last[msglast_len] = '\0';
			}
		}
	}
	return true;
}

//--- pet
void GCPetCharSetRecv(PMSG_NEW_PET_CHARSET_RECV* lpMsg)
{
	ClearNewPetCharSet();

	for (int n = 0; n < lpMsg->count; n++)
	{
		NEW_PET_STRUCT* lpInfo = (NEW_PET_STRUCT*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_PET_CHARSET_RECV)+(sizeof(NEW_PET_STRUCT)*n));

		InsertNewPetCharSet(lpInfo->index, lpInfo->PetCharSet);
	}
}

void GCPetCharSetSelectCharacterRecv(PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV* lpMsg)
{
	ClearNewPetCharSetSelectCharacter();

	for (int n = 0; n < lpMsg->count; n++)
	{
		PMSG_NEW_CHARACTER_CHARSET_RECV* lpInfo = (PMSG_NEW_CHARACTER_CHARSET_RECV*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV)+(sizeof(PMSG_NEW_CHARACTER_CHARSET_RECV)*n));

		InsertNewPetCharSetSelectCharacter(lpInfo->Name, lpInfo->PetCharSet);
	}
}

void SetChaosBoxState(PMSG_SET_CHAOSBOX_STATE* Data){
	pChaosBoxState = Data->state;
	return;
}

void GCWarehouseInterfaceOpenRecv(PMSG_WAREHOUSEINTERFACE_RECV* lpMsg)
{
	gObjUser.m_MaxWarehouse = lpMsg->MaxWarehouse;
	gInterface.Data[eWAREHOUSE_MAIN].Open(MAX_WIN_HEIGHT, 20);
	/*gInterface.Data[eWAREHOUSE_MAIN].Attribute = MAX_WIN_HEIGHT;
	gInterface.Data[eWAREHOUSE_MAIN].Speed = 20;*/
	gInterface.Data[eWAREHOUSE_MAIN].EventTick = GetTickCount();
}

void CGSendWarehouseOpen(int Number)
{
	PMSG_WAREHOUSEINTERFACE_SEND pMsg;
	pMsg.header.set(0xFF, 0x08, sizeof(pMsg));
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CGSendStatsAdd(PMSG_UPDATE_STATS_SEND pMsg)
{
	pMsg.header.set(0xFF, 0x09, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

#if(VONGQUAY_NEW)
void LuckySpinRoll()
{
	gLuckySpin.StartRoll = 1;
}
#endif

void ThuongGiaZenRoll()
{
	//G_BEXO_THUONG_GIA.StartRollZen = 1;
}

void UPDATEMENU(MENU_SEND lpMsg)
{
	lpMsg.header.set(0xF4,0x02,sizeof(lpMsg));
	DataSend((BYTE*)&lpMsg,lpMsg.header.size);
}
// Protocol.cpp
// =========== CTC Mini
void GCCTCMiniShowWindow(INFOCTCMINI_SENDCLIENT* lpMsg) // OK
{
	if((GetTickCount()-gInterface.Data[eCTCMiniWindow].EventTick) > 300)
	{
		gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
		gInterface.Data[eCTCMiniWindow].OnShow ^= 1;
	}
	CheckVaoLanhDia = lpMsg->GuildWinOld;
	//lpMsg->OpenWindow;
}

void GCCTCMiniKill(CTCMINIKILL_SENDCLIENT* lpMsg) // OK
{
	CTCMINI_TimeCTCMini = lpMsg->TimeCTCMini;
	for(int n=0;n < 3;n++) //Them Cong
	{
		CTCMINI_Cong[n] = lpMsg->Cong[n];
		CTCMINI_Tru[n] = lpMsg->Tru[n];
	}

}
#if(CHIEN_TRUONG_CO)
void GCInfoCTC(INFOCTC_SENDCLIENT* lpMsg) // OK
{
	//if((GetTickCount()-gInterface.Data[eCuaSoCTC].EventTick) > 1000)
	{
		CTC_TimeConLai = lpMsg->TimeConLai;
		CTC_PointKillQuai = lpMsg->PointKillQuai;
		CTC_PartyKillPoint = lpMsg->PartyKillPoint;
		CTC_MonterYeuCau = lpMsg->MonterYeuCau;
		gInterface.Data[eCuaSoCTC].OnShow = lpMsg->TYPE;
		gInterface.Data[eCuaSoCTC].EventTick = GetTickCount();
	}
}

void GCCTCKillMonter(CTCKILL_SENDCLIENT* lpMsg) // OK
{
	CTC_QuaiVatDaKill = lpMsg->QuaiKill;
}
#endif
#if (SELECTCHARACTER==1)
void GCSetCharacterPage(PMSG_CHARACTERPAGE_RECV* lpMsg)
{
	gMultiCharacter.m_CharacterPage = lpMsg->Page;
}

void CGSendMultiChar(int Page)
{
	PMSG_REQ_MULTI_CHAR_SEND pMsg;
	pMsg.header.set(0xF3, 0xD3, sizeof(pMsg));
	pMsg.Page = Page;
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}
#endif

#if(BOSS_GUILD == 1) // ok
void GCBossGuildShowWindow(INFOBOSSGUILD_SENDCLIENT* lpMsg) // OK
{
	if ((GetTickCount() - gInterface.Data[eBossGuildWindow].EventTick) > 300)
	{
		gInterface.Data[eBossGuildWindow].EventTick = GetTickCount();
		gInterface.Data[eBossGuildWindow].OnShow ^= 1;
	}
}

void GCBossGuildTime(BOSSGUILDTIME_SENDCLIENT* lpMsg) // OK
{
	BossGuild_TimeConLai = lpMsg->TimeBossGuild;
	for(int n=0;n < 3;n++)
	{
		
		BossGuild_Boss[n] = lpMsg->Boss[n];
	}
}
#endif