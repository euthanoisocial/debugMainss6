#include "stdafx.h"
#include "User.h"
#include "Interface.h"
#include "CustomBauCua.h"
#include "Defines.h"
#include "Offset.h"
#include "Central.h"
#include "Util.h"
#include "SItemOption.h"
#include "PrintPlayer.h"
#include "CustomJewelBank.h"
//#include "Ranking.h"
//#include "SPK_ChangePass.h"
//tue add
#include "PrintPlayer.h"
//----
#if BAUCUA
CUSTOM_BAUCUA gCUSTOM_BAUCUA;

CUSTOM_BAUCUA::CUSTOM_BAUCUA()
{
	this->type = -1;
	this->WCOINC = false;
	this->WCOINP = false;
	this->BLESS = false;
	this->SOUL = false;
	this->LIFE = false;
	this->CHAO = false;
	this->m_Data.hot1 = -1;
	this->m_Data.hot2 = -1;
	this->m_Data.hot3 = -1;
	this->m_Data.tongtrathuong = -1;
	this->MaxCuoc = 0;
}

void CUSTOM_BAUCUA::LOADBIN()
{

	gInterface.BindObject(BAUCUA_MAIN, 12348, 520, 365, -1, -1);
	gInterface.BindObject(BAUCUA_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(BAUCUA_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(BAUCUA_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(BAUCUA_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(BAUCUA_TEXTBOX01, 400004, 170, 21, -1, -1);
	gInterface.BindObject(BAUCUA_STATBOX01, 12344, 104, 21, -1, -1);
	gInterface.BindObject(BAUCUA_STATBOX02, 12344, 104, 21, -1, -1);
	gInterface.BindObject(BAUCUA_STATBOX03, 12344, 104, 21, -1, -1);
	gInterface.BindObject(BAUCUA_STATBOX04, 12344, 104, 21, -1, -1);
	gInterface.BindObject(BAUCUA_STATBOX05, 12344, 104, 21, -1, -1);
	gInterface.BindObject(BAUCUA_STATBOX06, 12344, 104, 21, -1, -1);
	gInterface.BindObject(BAUCUA_LOAITIENTE01, 12344, 104, 21, -1, -1);
	gInterface.BindObject(BAUCUA_LOAITIENTE02, 12344, 104, 21, -1, -1);
	gInterface.BindObject(BAUCUA_LOAITIENTE03, 12344, 104, 21, -1, -1);
	gInterface.BindObject(BAUCUA_LOAITIENTE04, 12344, 104, 21, -1, -1);
	gInterface.BindObject(BAUCUA_LOAITIENTE05, 12344, 104, 21, -1, -1);
	gInterface.BindObject(BAUCUA_LOAITIENTE06, 12344, 104, 21, -1, -1);
	gInterface.BindObject(BAUCUA_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	gInterface.BindObject(BAUCUA_WC, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(BAUCUA_WP, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(BAUCUA_B, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(BAUCUA_S, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(BAUCUA_L, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(BAUCUA_C, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(BAUCUA_Bau, 11149, 50, 50, -1, -1);
	gInterface.BindObject(BAUCUA_Cua, 11150, 50, 50, -1, -1);
	gInterface.BindObject(BAUCUA_Tom, 11151, 50, 50, -1, -1);
	gInterface.BindObject(BAUCUA_Ca, 11152, 50, 50, -1, -1);
	gInterface.BindObject(BAUCUA_Ga, 11153, 50, 50, -1, -1);
	gInterface.BindObject(BAUCUA_Nai, 11154, 50, 50, -1, -1);
	gInterface.BindObject(eCHARINFO_BTN_STAT, 0x7AA4, 16, 15, -1, -1);
}


void CUSTOM_BAUCUA::DrawStatsAddWindow()
{
	//điều kiện
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(FriendList)
		|| gInterface.CheckWindow(MoveList)
		|| gInterface.CheckWindow(Party)
		|| gInterface.CheckWindow(Quest)
		|| gInterface.CheckWindow(NPC_Devin)
		|| gInterface.CheckWindow(Guild)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(CommandWindow)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(DevilSquare)
		|| gInterface.CheckWindow(BloodCastle)
		|| gInterface.CheckWindow(CreateGuild)
		|| gInterface.CheckWindow(GuardNPC)
		|| gInterface.CheckWindow(SeniorNPC)
		|| gInterface.CheckWindow(GuardNPC2)
		|| gInterface.CheckWindow(CastleGateSwitch)
		|| gInterface.CheckWindow(CatapultNPC)
		|| gInterface.CheckWindow(CrywolfGate)
		|| gInterface.CheckWindow(IllusionTemple)
		|| gInterface.CheckWindow(HeroList)
		|| gInterface.CheckWindow(ChatWindow)
		|| gInterface.CheckWindow(FastMenu)
		|| gInterface.CheckWindow(Options)
		|| gInterface.CheckWindow(FastDial)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(GoldenArcher1)
		|| gInterface.CheckWindow(GoldenArcher2)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(LuckyCoin2)
		|| gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(Lugard)
		|| gInterface.CheckWindow(QuestList1)
		|| gInterface.CheckWindow(QuestList2)
		|| gInterface.CheckWindow(GensInfo)
		|| gInterface.CheckWindow(NPC_ChaosMix)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(MuHelper)
		|| gInterface.CheckWindow(PetInfo)
		|| gInterface.Data[eMenu_MAIN].OnShow
		|| gInterface.Data[eEventTimePANEL_MAIN].OnShow
		|| gInterface.Data[eCommand_MAIN].OnShow
		|| gInterface.Data[eChangePass_Main].OnShow
		|| gInterface.Data[SPK_Ranking_Main].OnShow
		|| gInterface.Data[eCONFIRM_MAIN].OnShow
		|| gInterface.Data[eJewelBank_MAIN].OnShow
		|| gInterface.Data[ePARTYSETTINGS_MAIN].OnShow
		|| gInterface.Data[ePARTYSEARCH_MAIN].OnShow
		//|| gRanking.Show == true
		|| pMapNumber == 40)

	{
		return;//trả về
	}

	if (!gInterface.Data[BAUCUA_MAIN].OnShow)
	{
		return;
	}

	int ObjectCount = 6;
	if ((gObjUser.lpPlayer->Class & 7) == 6)
	{
		ObjectCount = 6;
	}

	char szCharNames[6][32] =
	{
		"CƯỢC NAI",
		"CƯỢC BẦU",
		"CƯỢC GÀ",
		"CƯỢC CÁ",
		"CƯỢC CUA",
		"CƯỢC TÔM",
	};

	int ObjectIDs[6] =
	{
		BAUCUA_STATBOX01,
		BAUCUA_STATBOX02,
		BAUCUA_STATBOX03,
		BAUCUA_STATBOX04,
		BAUCUA_STATBOX05,
		BAUCUA_STATBOX06,
	};

	char LoaiTienTe[6][32] =
	{
		"WCOINC",
		"WCOINP",
		"ƯỚC NGUYỆN",
		"TÂM LINH",
		"SINH MỆNH",
		"HỖN NGUYÊN",
	};

	int ChonTienTe[6] =
	{
		BAUCUA_LOAITIENTE01,
		BAUCUA_LOAITIENTE02,
		BAUCUA_LOAITIENTE03,
		BAUCUA_LOAITIENTE04,
		BAUCUA_LOAITIENTE05,
		BAUCUA_LOAITIENTE06,
	};
	int TickChonTien[6] =
	{
		BAUCUA_WC,
		BAUCUA_WP,
		BAUCUA_B,
		BAUCUA_S,
		BAUCUA_L,
		BAUCUA_C,
	};
	int MatKQ[6] =
	{
		BAUCUA_Bau,
		BAUCUA_Cua,
		BAUCUA_Tom,
		BAUCUA_Ca,
		BAUCUA_Ga,
		BAUCUA_Nai,
	};
	if (gInterface.Data[BAUCUA_MAIN].ByClose == false)
	{
		if (gInterface.Data[BAUCUA_MAIN].OpenedValue < 0)
		{
			gInterface.Data[BAUCUA_MAIN].OpenedValue += gInterface.Data[BAUCUA_MAIN].Speed;

			if (gInterface.Data[BAUCUA_MAIN].OpenedValue >= -150)
			{
				gInterface.Data[BAUCUA_MAIN].Speed = 15;
			}

			if (gInterface.Data[BAUCUA_MAIN].OpenedValue > 0)
			{
				gInterface.Data[BAUCUA_MAIN].OpenedValue = 0;
			}
		}
	}
	else
	{
		if (gInterface.Data[BAUCUA_MAIN].OpenedValue > -226)
		{
			gInterface.Data[BAUCUA_MAIN].OpenedValue -= gInterface.Data[BAUCUA_MAIN].Speed;

			if (gInterface.Data[BAUCUA_MAIN].OpenedValue <= -150)
			{
				gInterface.Data[BAUCUA_MAIN].Speed = 20;
			}

			if (gInterface.Data[BAUCUA_MAIN].OpenedValue <= -226)
			{
				gInterface.Data[BAUCUA_MAIN].Close();

				gInterface.Data[BAUCUA_WC].Attribute = 0;
				gInterface.Data[BAUCUA_WP].Attribute = 0;
				gInterface.Data[BAUCUA_B].Attribute = 0;
				gInterface.Data[BAUCUA_S].Attribute = 0;
				gInterface.Data[BAUCUA_L].Attribute = 0;
				gInterface.Data[BAUCUA_C].Attribute = 0;
				for (int i = 0; i < ObjectCount; i++)
				{
					gInterface.Data[ObjectIDs[i]].Attribute = false;
				}
			}
		}
	}
	pSetCursorFocus = true;
	float MainWidth = 180.0;
	float StartY = 60;
	float StartX = gInterface.Data[BAUCUA_MAIN].OpenedValue;
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	gInterface.DrawAnimatedGUI(BAUCUA_MAIN, StartX, StartY + 2);
	gInterface.DrawAnimatedGUI(BAUCUA_CLOSE, StartX + 333 + MainWidth - gInterface.Data[BAUCUA_CLOSE].Width, gInterface.Data[BAUCUA_MAIN].Y);
	// ----
	if (gInterface.IsWorkZone(BAUCUA_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[BAUCUA_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(BAUCUA_CLOSE, gInterface.Data[BAUCUA_CLOSE].X, gInterface.Data[BAUCUA_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[BAUCUA_CLOSE].X + 5, gInterface.Data[BAUCUA_CLOSE].Y + 25, "Close");
	}

	char Value[50];
	ZeroMemory(Value, sizeof(Value));

//=======================================================================================================================



	if (gInterface.Data[BAUCUA_WC].Attribute == true)
	{
		gInterface.DrawAnimatedButton(BAUCUA_WC, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 72, 0, 15);
		this->type = 0;
	}
	else
	{
		gInterface.DrawAnimatedButton(BAUCUA_WC, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 72, 0, 0);
	}

	if (gInterface.Data[BAUCUA_WP].Attribute == true)
	{
		gInterface.DrawAnimatedButton(BAUCUA_WP, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 102, 0, 15);
		this->type = 1;
	}
	else
	{
		gInterface.DrawAnimatedButton(BAUCUA_WP, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 102, 0, 0);
	}

	if (gInterface.Data[BAUCUA_B].Attribute == true)
	{
		gInterface.DrawAnimatedButton(BAUCUA_B, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 132, 0, 15);
		this->type = 2;
	}
	else
	{
		gInterface.DrawAnimatedButton(BAUCUA_B, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 132, 0, 0);
	}

	if (gInterface.Data[BAUCUA_S].Attribute == true)
	{
		gInterface.DrawAnimatedButton(BAUCUA_S, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 162, 0, 15);
		this->type = 3;
	}
	else
	{
		gInterface.DrawAnimatedButton(BAUCUA_S, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 162, 0, 0);
	}

	if (gInterface.Data[BAUCUA_L].Attribute == true)
	{
		gInterface.DrawAnimatedButton(BAUCUA_L, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 192, 0, 15);
		this->type = 4;
	}
	else
	{
		gInterface.DrawAnimatedButton(BAUCUA_L, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 192, 0, 0);
	}

	if (gInterface.Data[BAUCUA_C].Attribute == true)
	{
		gInterface.DrawAnimatedButton(BAUCUA_C, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 222, 0, 15);
		this->type = 5;
	}
	else
	{
		gInterface.DrawAnimatedButton(BAUCUA_C, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 222, 0, 0);
	}

	if (gInterface.Data[BAUCUA_MAIN].FirstLoad == true)
	{
		gInterface.Data[BAUCUA_STATBOX01].Attribute = 1;
	}

	for (int i = 0; i < ObjectCount; i++)
	{
		if (gInterface.Data[BAUCUA_MAIN].FirstLoad == true)
		{
			sprintf(gInterface.Data[ObjectIDs[i]].StatValue, "0");
		}

		gInterface.DrawAnimatedGUI(ObjectIDs[i], ButtonX + 335, gInterface.Data[BAUCUA_MAIN].Y + 40 + ((i + 1) * 30));
		gInterface.DrawFormat(eBlue, StartX + 300, gInterface.Data[BAUCUA_MAIN].Y + 45 + ((i + 1) * 30), 210, 3, szCharNames[i]);
		gInterface.DrawFormat(eShinyGreen, StartX + 350, gInterface.Data[BAUCUA_MAIN].Y + 45 + ((i + 1) * 30), 210, 3, gInterface.Data[ObjectIDs[i]].StatValue);

		if (gInterface.Data[ObjectIDs[i]].Attribute == 1)
		{
			DWORD Color = eGray100;
			gInterface.DrawColoredAnimatedGUI(ObjectIDs[i], ButtonX + 335, gInterface.Data[BAUCUA_MAIN].Y + 40 + ((i + 1) * 30), Color);
		}
	}

	for (int i = 0; i < ObjectCount; i++)
	{
		gInterface.DrawAnimatedGUI(ChonTienTe[i], ButtonX + 215, gInterface.Data[BAUCUA_MAIN].Y + 40 + ((i + 1) * 30));
		gInterface.DrawFormat(eBlue, StartX + 179, gInterface.Data[BAUCUA_MAIN].Y + 46 + ((i + 1) * 30), 210, 3, LoaiTienTe[i]);
	}
	gInterface.DrawFormat(eExcellent, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 75, 200, 3, "%d", Coin1);
	gInterface.DrawFormat(eExcellent, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 104, 200, 3, "%d", Coin2);
	gInterface.DrawFormat(eExcellent, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 104 + 30, 200, 3, "%d", gCustomJewelBank.m_Data.ItemBank[0]);
	gInterface.DrawFormat(eExcellent, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 104 + 60, 200, 3, "%d", gCustomJewelBank.m_Data.ItemBank[1]);
	gInterface.DrawFormat(eExcellent, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 104 + 90, 200, 3, "%d", gCustomJewelBank.m_Data.ItemBank[2]);
	gInterface.DrawFormat(eExcellent, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 104 + 120, 200, 3, "%d", gCustomJewelBank.m_Data.ItemBank[7]);



	gInterface.DrawAnimatedButton(BAUCUA_BTN_OK, StartX + 410, gInterface.Data[BAUCUA_MAIN].Y + 285, 0, 0);

	int checktongcuoc2 = 0;
	checktongcuoc2	= atoi(gInterface.Data[BAUCUA_STATBOX01].StatValue)
		+ atoi(gInterface.Data[BAUCUA_STATBOX02].StatValue)
		+ atoi(gInterface.Data[BAUCUA_STATBOX03].StatValue)
		+ atoi(gInterface.Data[BAUCUA_STATBOX04].StatValue)
		+ atoi(gInterface.Data[BAUCUA_STATBOX05].StatValue)
		+ atoi(gInterface.Data[BAUCUA_STATBOX06].StatValue);

	if (checktongcuoc2 > Coin1 && type == 0) {
		gInterface.DrawFormat(eRed, StartX + 130 + 1.5, gInterface.Data[BAUCUA_MAIN].Y + 240, 300, 0, "* Chỉ được cược tối đa số WCOINC là : %d ", Coin1);
	}
	if (checktongcuoc2 > Coin2 && type == 1) {
		gInterface.DrawFormat(eRed, StartX + 130 + 1.5, gInterface.Data[BAUCUA_MAIN].Y + 240, 300, 0, "* Chỉ được cược tối đa số WCOINP là : %d ", Coin2);
	}
	if (checktongcuoc2 >  gCustomJewelBank.m_Data.ItemBank[0] && type == 2) {
		gInterface.DrawFormat(eRed, StartX + 130 + 1.5, gInterface.Data[BAUCUA_MAIN].Y + 240, 300, 0, "* Chỉ được cược tối đa số Ước Nguyện là : %d ",  gCustomJewelBank.m_Data.ItemBank[0]);
	}
	if (checktongcuoc2 >  gCustomJewelBank.m_Data.ItemBank[1] && type == 3) {
		gInterface.DrawFormat(eRed, StartX + 130 + 1.5, gInterface.Data[BAUCUA_MAIN].Y + 240, 300, 0, "* Chỉ được cược tối đa số Tâm Linh là : %d ",  gCustomJewelBank.m_Data.ItemBank[1]);
	}
	if (checktongcuoc2 >  gCustomJewelBank.m_Data.ItemBank[2] && type == 4) {
		gInterface.DrawFormat(eRed, StartX + 130 + 1.5, gInterface.Data[BAUCUA_MAIN].Y + 240, 300, 0, "* Chỉ được cược tối đa số Sinh Mệnh là : %d ",  gCustomJewelBank.m_Data.ItemBank[2]);
	}
	if (checktongcuoc2 >  gCustomJewelBank.m_Data.ItemBank[7] && type == 5) {
		gInterface.DrawFormat(eRed, StartX + 130 + 1.5, gInterface.Data[BAUCUA_MAIN].Y + 240, 300, 0, "* Chỉ được cược tối đa số Hỗn Nguyên là : %d ",  gCustomJewelBank.m_Data.ItemBank[7]);
	}
	if (hotkq1 < 0) {

		gInterface.DrawAnimatedGUI(BAUCUA_Bau, StartX + 130 + 1.5, gInterface.Data[BAUCUA_MAIN].Y + 279);
		gInterface.DrawAnimatedGUI(BAUCUA_Bau, StartX + 230, gInterface.Data[BAUCUA_MAIN].Y + 279);
		gInterface.DrawAnimatedGUI(BAUCUA_Bau, StartX + 330 - 1.5, gInterface.Data[BAUCUA_MAIN].Y + 279);
	}
	if (hotkq1 > 0) {
		//=============================================================================================================================================================================
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BAUCUA_BTN_OK].EventTick);
		if (Delay > 2000) {
			gInterface.DrawFormat(eWhite180, StartX + 50 + 1.5, gInterface.Data[BAUCUA_MAIN].Y + 55, 600, 0, "* Bạn vừa đặt cược : NAI x [%d], BẦU x [%d], GÀ x [%d], CÁ x [%d], CUA x [%d], TÔM x [%d] - [%s]", IconMiniGame[0], IconMiniGame[1], IconMiniGame[2], IconMiniGame[3], IconMiniGame[4], IconMiniGame[5], LoaiTienTe[IconMiniGame[7]]);
			gInterface.DrawFormat(eYellow, StartX + 50 + 1.5, gInterface.Data[BAUCUA_MAIN].Y + 45, 300, 0, "* Tổng cược : %d x %s", IconMiniGame[6], LoaiTienTe[IconMiniGame[7]]);
			gInterface.DrawFormat(eExcellent, StartX + 200 + 1.5, gInterface.Data[BAUCUA_MAIN].Y + 45, 300, 0, "* Tổng nhận về : %d x %s", tongtrathuong, LoaiTienTe[IconMiniGame[7]]);//LoaiTienTe[type]
		//=============================================================================================================================================================================

			gInterface.DrawAnimatedGUI(MatKQ[hotkq1 - 1], StartX + 130 + 1.5, gInterface.Data[BAUCUA_MAIN].Y + 279);

			gInterface.DrawAnimatedGUI(MatKQ[hotkq2 - 1], StartX + 230, gInterface.Data[BAUCUA_MAIN].Y + 279);

			gInterface.DrawAnimatedGUI(MatKQ[hotkq3 - 1], StartX + 330 - 1.5, gInterface.Data[BAUCUA_MAIN].Y + 279);
		}
		else {

			for (int i = 0; i < ObjectCount; i++)
			{
				gInterface.DrawAnimatedGUI(ChonTienTe[i], ButtonX + 215, gInterface.Data[BAUCUA_MAIN].Y + 40 + ((i + 1) * 30));
				gInterface.DrawFormat(eBlue, StartX + 179, gInterface.Data[BAUCUA_MAIN].Y + 46 + ((i + 1) * 30), 210, 3, LoaiTienTe[i]);
			}
			gInterface.DrawFormat(eExcellent, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 75, 200, 3, "-------");
			gInterface.DrawFormat(eExcellent, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 104, 200, 3, "-------");
			gInterface.DrawFormat(eExcellent, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 104 + 30, 200, 3, "-------");
			gInterface.DrawFormat(eExcellent, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 104 + 60, 200, 3, "-------");
			gInterface.DrawFormat(eExcellent, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 104 + 90, 200, 3, "-------");
			gInterface.DrawFormat(eExcellent, StartX + 235, gInterface.Data[BAUCUA_MAIN].Y + 104 + 120, 200, 3, "-------");

			gInterface.DrawAnimatedGUI(MatKQ[rand() % 5], StartX + 130 + 1.5, gInterface.Data[BAUCUA_MAIN].Y + 279);

			gInterface.DrawAnimatedGUI(MatKQ[rand() % 5], StartX + 230, gInterface.Data[BAUCUA_MAIN].Y + 279);

			gInterface.DrawAnimatedGUI(MatKQ[rand() % 5], StartX + 330 - 1.5, gInterface.Data[BAUCUA_MAIN].Y + 279);
		}
	}


	if (gInterface.IsWorkZone(BAUCUA_BTN_OK))
	{
		int ScaleY = 30;
		// ----
		if (gInterface.Data[BAUCUA_BTN_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		gInterface.DrawAnimatedButton(BAUCUA_BTN_OK, StartX + 410, gInterface.Data[BAUCUA_MAIN].Y + 285, 0, ScaleY);
	}

	if (gInterface.Data[BAUCUA_MAIN].FirstLoad == true)
	{
		gInterface.Data[BAUCUA_MAIN].FirstLoad = false;
	}
}
// ----------------------------------------------------------------------------------------------


void CUSTOM_BAUCUA::EventStatsAddWindow(DWORD Event)
{
	this->EventStatsAddWindow_Close(Event);
}
void CUSTOM_BAUCUA::NhanKetQuaTuServer(PSBMSG_BAUCUA_RECV* lpMsg)
{
	hotkq1 = lpMsg->hot1;
	hotkq2 = lpMsg->hot2;
	hotkq3 = lpMsg->hot3;
	tongtrathuong = lpMsg->tongtrathuong;
//nhận kết quả
}
void CUSTOM_BAUCUA::EventStatsAddWindow_Close(DWORD Event)
{
	if (!gInterface.Data[BAUCUA_MAIN].OnShow)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	int ObjectIDs[6] =
	{
		BAUCUA_STATBOX01,
		BAUCUA_STATBOX02,
		BAUCUA_STATBOX03,
		BAUCUA_STATBOX04,
		BAUCUA_STATBOX05,
		BAUCUA_STATBOX06,
	};
	int TickChonTien[6] =
	{
		BAUCUA_WC,
		BAUCUA_WP,
		BAUCUA_B,
		BAUCUA_S,
		BAUCUA_L,
		BAUCUA_C,
	};

	int ObjectCount = 6;
	int ObjectCount2 = 6;

	for (int i = 0; i < ObjectCount; i++)
	{
		if (gInterface.IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - gInterface.Data[ObjectIDs[i]].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			gInterface.Data[ObjectIDs[i]].EventTick = GetTickCount();

			for (int j = 0; j < ObjectCount; j++)
			{
				gInterface.Data[ObjectIDs[j]].Attribute = 0;
			}

			gInterface.Data[ObjectIDs[i]].Attribute = 1;
		}
	}

	for (int i = 0; i < ObjectCount2; i++)
	{
		if (gInterface.IsWorkZone(TickChonTien[i]))
		{
			DWORD Delay = (CurrentTick - gInterface.Data[TickChonTien[i]].EventTick);
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[TickChonTien[i]].OnClick = true;
				return;
			}
			gInterface.Data[TickChonTien[i]].OnClick = false;
			if (Delay < 500)
			{
				return;
			}
			gInterface.Data[TickChonTien[i]].EventTick = GetTickCount();

			for (int j = 0; j < ObjectCount2; j++)
			{
				gInterface.Data[TickChonTien[j]].Attribute = 0;
			}

			gInterface.Data[TickChonTien[i]].Attribute = 1;
		}
	}

	if (gInterface.IsWorkZone(BAUCUA_BTN_OK))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[BAUCUA_BTN_OK].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BAUCUA_BTN_OK].OnClick = true;
			return;
		}
		gInterface.Data[BAUCUA_BTN_OK].OnClick = false;
		if (Delay < 5000)
		{
			return;
		}
		if (type< 0)
		{
			return;
		}
		if (atoi(gInterface.Data[BAUCUA_STATBOX01].StatValue)
			+ atoi(gInterface.Data[BAUCUA_STATBOX02].StatValue)
			+ atoi(gInterface.Data[BAUCUA_STATBOX03].StatValue)
			+ atoi(gInterface.Data[BAUCUA_STATBOX04].StatValue)
			+ atoi(gInterface.Data[BAUCUA_STATBOX05].StatValue)
			+ atoi(gInterface.Data[BAUCUA_STATBOX06].StatValue) < 1
			)
		{
			return;
		}

		this->IconMiniGame[0]= atoi(gInterface.Data[BAUCUA_STATBOX01].StatValue);
		this->IconMiniGame[1]= atoi(gInterface.Data[BAUCUA_STATBOX02].StatValue);
		this->IconMiniGame[2]= atoi(gInterface.Data[BAUCUA_STATBOX03].StatValue);
		this->IconMiniGame[3]= atoi(gInterface.Data[BAUCUA_STATBOX04].StatValue);
		this->IconMiniGame[4]= atoi(gInterface.Data[BAUCUA_STATBOX05].StatValue);
		this->IconMiniGame[5]= atoi(gInterface.Data[BAUCUA_STATBOX06].StatValue);
		IconMiniGame[7] = type;
		this->IconMiniGame[6] = atoi(gInterface.Data[BAUCUA_STATBOX01].StatValue)
			+ atoi(gInterface.Data[BAUCUA_STATBOX02].StatValue)
			+ atoi(gInterface.Data[BAUCUA_STATBOX03].StatValue)
			+ atoi(gInterface.Data[BAUCUA_STATBOX04].StatValue)
			+ atoi(gInterface.Data[BAUCUA_STATBOX05].StatValue)
			+ atoi(gInterface.Data[BAUCUA_STATBOX06].StatValue);

		gInterface.Data[BAUCUA_BTN_OK].EventTick = GetTickCount();

		PSBMSG_BAUCUA_SEND pMsg;
		pMsg.IconMiniGame[0] = atoi(gInterface.Data[BAUCUA_STATBOX01].StatValue);
		pMsg.IconMiniGame[1] = atoi(gInterface.Data[BAUCUA_STATBOX02].StatValue);
		pMsg.IconMiniGame[2] = atoi(gInterface.Data[BAUCUA_STATBOX03].StatValue);
		pMsg.IconMiniGame[3] = atoi(gInterface.Data[BAUCUA_STATBOX04].StatValue);
		pMsg.IconMiniGame[4] = atoi(gInterface.Data[BAUCUA_STATBOX05].StatValue);
		pMsg.IconMiniGame[5] = atoi(gInterface.Data[BAUCUA_STATBOX06].StatValue);

		pMsg.IconMiniGame[6] = type;

		pMsg.header.set(0xF3, 0xF9, sizeof(pMsg));

		DataSend((BYTE*)&pMsg, pMsg.header.size);

		for (int i = 0; i < ObjectCount; i++) {
			sprintf(gInterface.Data[ObjectIDs[i]].StatValue, "0");
		}
	}

	if (gInterface.IsWorkZone(BAUCUA_CLOSE))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[BAUCUA_CLOSE].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BAUCUA_CLOSE].OnClick = true;
			return;
		}
		gInterface.Data[BAUCUA_CLOSE].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[BAUCUA_CLOSE].EventTick = GetTickCount();
		gInterface.Data[BAUCUA_MAIN].CloseAnimated(15);
	}

	// ----
	return;
}

void CUSTOM_BAUCUA::EventCharacterWindow(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	if (!gInterface.CheckWindow(Character))
	{
		return;
	}
	// ----
	if (gInterface.IsWorkZone(eCHARINFO_BTN_STAT))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[eCHARINFO_BTN_STAT].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eCHARINFO_BTN_STAT].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[eCHARINFO_BTN_STAT].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[eCHARINFO_BTN_STAT].EventTick = GetTickCount();
		this->SwitchStatsWindowState();
	}
}


bool CUSTOM_BAUCUA::ControlTextBox(DWORD Event)
{
	if (gInterface.Data[BAUCUA_MAIN].OnShow)
	{
		char Value[20];
		int IsBackspace = false;
		int IsDelete = false;
		int IsTab = false;
		int IsArrowUp = false;
		int IsArrowDown = false;
		int IsArrowLeft = false;
		int IsArrowRight = false;

		int Step = 100;

		int ObjectCount = 6;
		int ObjectCount2 = 6;

		int SelectedIndex = 0;

		if (Event == VK_BACK)
		{
			IsBackspace = true;
		}
		else if (Event == VK_DELETE)
		{
			IsDelete = true;
		}
		else if (Event == VK_TAB)
		{
			IsTab = true;
		}
		else if (Event == VK_UP)
		{
			IsArrowUp = true;
		}
		else if (Event == VK_DOWN)
		{
			IsArrowDown = true;
		}
		else if (Event == VK_LEFT)
		{
			IsArrowLeft = true;
		}
		else if (Event == VK_RIGHT)
		{
			IsArrowRight = true;
		}
		else if ((Event >= 0x30 && Event <= 0x39) || (Event >= 0x60 && Event <= 0x69))
		{
			int Symbol = GetSymbolFromVK(Event);
			if (Symbol == 0)
			{
				return true;
			}
			char buff[10];
			sprintf(buff, "%c", Symbol);
			strcpy_s(Value, buff);
		}
		else
		{
			return true;
		}
		int ObjectIDs[6] =
		{
			BAUCUA_STATBOX01,
			BAUCUA_STATBOX02,
			BAUCUA_STATBOX03,
			BAUCUA_STATBOX04,
			BAUCUA_STATBOX05,
			BAUCUA_STATBOX06,
		};

		for (int i = 0; i < ObjectCount; i++)
		{
			if (gInterface.Data[ObjectIDs[i]].Attribute == 1)
			{
				SelectedIndex = i;
				if (IsBackspace == true)
				{
					gInterface.Data[ObjectIDs[i]].StatValue[strlen(gInterface.Data[ObjectIDs[i]].StatValue) - 1] = '\0';

					if (strlen(gInterface.Data[ObjectIDs[i]].StatValue) == 0)
					{
						strcpy_s(gInterface.Data[ObjectIDs[i]].StatValue, "0");
					}
					break;
				}
				else if (IsDelete == true)
				{
					strcpy_s(gInterface.Data[ObjectIDs[i]].StatValue, "0");
				}
				else if (IsTab == true)
				{
					gInterface.Data[ObjectIDs[i]].Attribute = 0;

					if (i == ObjectCount - 1)
					{
						gInterface.Data[ObjectIDs[0]].Attribute = 1;
					}
					else
					{
						gInterface.Data[ObjectIDs[i + 1]].Attribute = 1;
					}
					break;
				}
				else if (IsArrowUp == true)
				{
					if (i > 0)
					{
						gInterface.Data[ObjectIDs[i]].Attribute = 0;
						gInterface.Data[ObjectIDs[i - 1]].Attribute = 1;
					}
					break;
				}
				else if (IsArrowDown == true)
				{
					if (i < ObjectCount - 1)
					{
						gInterface.Data[ObjectIDs[i]].Attribute = 0;
						gInterface.Data[ObjectIDs[i + 1]].Attribute = 1;
					}
					break;
				}
				else if (IsArrowLeft == true)
				{
					int val = atoi(gInterface.Data[ObjectIDs[i]].StatValue);
					val -= Step;
					if (val < 0)
					{
						val = 0;
					}
					strcpy_s(gInterface.Data[ObjectIDs[i]].StatValue, "0");
					sprintf_s(gInterface.Data[ObjectIDs[i]].StatValue, "%d", val);
					break;
				}
				else if (IsArrowRight == true)
				{
					int val = atoi(gInterface.Data[ObjectIDs[i]].StatValue);
					val += Step;
					if (val > 1000000)
					{
						val = 1000000;
					}
					sprintf_s(gInterface.Data[ObjectIDs[i]].StatValue, "%d", val);
					break;
				}
				else
				{
					if (strlen(gInterface.Data[ObjectIDs[i]].StatValue) < 8)
					{
						if (!strcmp(gInterface.Data[ObjectIDs[i]].StatValue, "0"))
						{
							strcpy_s(gInterface.Data[ObjectIDs[i]].StatValue, Value);
						}
						else
						{
							int currentVal = atoi(gInterface.Data[ObjectIDs[i]].StatValue);
							int inputVal = atoi(Value);
							int newVal = currentVal * 10 + inputVal;
							if (newVal > 500000)
							{
								newVal = 500000;
							}
							sprintf_s(gInterface.Data[ObjectIDs[i]].StatValue, "%d", newVal);
						}
					}
				}
			}
		}

		return 1;
	}

	return 0;
}
#endif