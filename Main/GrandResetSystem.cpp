#include "stdafx.h"
#include "GrandResetSystem.h"
#include "User.h"
#include "Protocol.h"
#include "Interface.h"
#include "PrintPlayer.h"
#include "Util.h"
#include "Offset.h"


GRSystem gGrandResetSystem;

GRSystem::GRSystem()
{
	
}

GRSystem::~GRSystem()
{

}

void GRSystem::BinObeject()
{
	gInterface.BindObject(OBJECT_GRESET_MAIN, 0x7A5A, 222, 303, -1, -1);
	gInterface.BindObject(OBJECT_GRESET_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(OBJECT_GRESET_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(OBJECT_GRESET_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(OBJECT_GRESET_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(OBJECT_GRESET_INFO_BG, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(OBJECT_GRESET_MONEY_BG, 0x7A89, 170, 26, -1, -1);
	gInterface.BindObject(OBJECT_GRESET_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(OBJECT_GRESET_FINISH, 0x7A5E, 128, 29, -1, -1);
}

void GRSystem::draw_grand_reset_system()
{
	if (!gInterface.Data[OBJECT_GRESET_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	gInterface.DrawGUI(OBJECT_GRESET_MAIN, StartX, StartY + 2);
	gInterface.DrawGUI(OBJECT_GRESET_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(OBJECT_GRESET_FRAME, StartX, StartY + 67.0, 13);
	gInterface.DrawGUI(OBJECT_GRESET_FOOTER, StartX, StartY);
	gInterface.DrawGUI(OBJECT_GRESET_CLOSE, StartX + MainWidth - gInterface.Data[OBJECT_GRESET_CLOSE].Width, gInterface.Data[OBJECT_GRESET_TITLE].Height + gInterface.Data[OBJECT_GRESET_CLOSE].Height + 2);
	// ----
	if (gInterface.IsWorkZone(OBJECT_GRESET_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[OBJECT_GRESET_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(OBJECT_GRESET_CLOSE, gInterface.Data[OBJECT_GRESET_CLOSE].X, gInterface.Data[OBJECT_GRESET_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[OBJECT_GRESET_CLOSE].X + 5, gInterface.Data[OBJECT_GRESET_CLOSE].Y + 25, "Đóng");
	}
	// ----
	gInterface.DrawText(eGold, StartX + 10, 110, 210, 3, "Thông Tin ReLife");
	// ----
	gInterface.DrawGUI(OBJECT_GRESET_INFO_BG, StartX + 30, 140);
	gInterface.DrawText(eGold, StartX + 35, 145, 70, 3, "ReLife Lần Tiếp Theo:");
	gInterface.DrawText(eWhite, StartX + 135, 145, 70, 1, "%d", ViewGReset + 1);
	gInterface.DrawGUI(OBJECT_GRESET_INFO_BG, StartX + 30, 160);
	gInterface.DrawText(eGold, StartX + 35, 165, 70, 3, "Số Point Nhận Được:");
	//gInterface.DrawText(eWhite, StartX + 135, 165, 70, 1, "%d", gGrandResetSystem.get_reward_points(1) + gObjUser.m_QuestStat);
	gInterface.DrawText(eWhite, StartX + 135, 165, 70, 1, "%d", gGrandResetSystem.get_reward_points(1) );
	// ----
	gInterface.DrawGUI(OBJECT_GRESET_DIV, StartX, 185);
	// ----
	gInterface.DrawText(eGold, StartX + 30, 200, 210, 1, "Level Cần:");
	// ----
	if (gObjUser.lpPlayer->Level < gGrandResetSystem.m_GRData.ReqLevel)
	{
		gInterface.DrawText(eRed, StartX + 30, 210, 210, 1, "- %d (RS Hiện Tại: %d)",
			gGrandResetSystem.m_GRData.ReqLevel, gObjUser.lpPlayer->Level);
	}
	else
	{
		gInterface.DrawText(eWhite, StartX + 30, 210, 210, 1, "- %d",
			gGrandResetSystem.m_GRData.ReqLevel);
	}
	// ----
	gInterface.DrawText(eGold, StartX + 30, 220, 210, 1, "Số Lần RS Yêu Cầu:");
	// ----
	if (ViewReset < gGrandResetSystem.m_GRData.ReqReset)
	{
		gInterface.DrawText(eRed, StartX + 30, 230, 210, 1, "- %d (RS Hiện Tại: %d)",
			gGrandResetSystem.m_GRData.ReqReset, ViewReset);
	}
	else
	{
		gInterface.DrawText(eWhite, StartX + 30, 230, 210, 1, "- %d",
			gGrandResetSystem.m_GRData.ReqReset);
	}
	// ----
	gInterface.DrawText(eGold, StartX + 30, 240, 210, 1, "Nguyên Liệu ReLife:");
	// ----
	for (int i = 0; i < gGrandResetSystem.m_GRData.ItemCount; i++)
	{
		char ItemNameBuff[150], LevelBuff[25], OptionBuff[25];
		// ----
		ZeroMemory(ItemNameBuff, sizeof(ItemNameBuff));
		// ----
		if (gGrandResetSystem.m_GRData.ItemData[i].IsExcellent)
		{
			strcat(ItemNameBuff, "Đồ Hoàn Hảo");
			ItemNameColor = eExcellent;
		}
		// ----
		if (gGrandResetSystem.m_GRData.ItemData[i].IsAncient)
		{
			strcat(ItemNameBuff, "Đồ Thần");
			ItemNameColor = eAncient;
		}
		// ----
		if (gGrandResetSystem.m_GRData.ItemData[i].IsSocket)
		{
			strcat(ItemNameBuff, "Đồ Socket");
			ItemNameColor = eSocket;
		}
		// ----
		strcat(ItemNameBuff, (char*)(*(DWORD*)0x8128AC0 + 84 *
			gGrandResetSystem.m_GRData.ItemData[i].ID));
		// ----
		if (gGrandResetSystem.m_GRData.ItemData[i].MinLevel
			== gGrandResetSystem.m_GRData.ItemData[i].MaxLevel)
		{
			ZeroMemory(LevelBuff, sizeof(LevelBuff));
			sprintf(LevelBuff, " [+%d, ", gGrandResetSystem.m_GRData.ItemData[i].MinLevel);
			strcat(ItemNameBuff, LevelBuff);
		}
		else
		{
			ZeroMemory(LevelBuff, sizeof(LevelBuff));
			sprintf(LevelBuff, " [+%d~%d, ",
				gGrandResetSystem.m_GRData.ItemData[i].MinLevel,
				gGrandResetSystem.m_GRData.ItemData[i].MaxLevel);
			strcat(ItemNameBuff, LevelBuff);
		}
		// ----
		if (gGrandResetSystem.m_GRData.ItemData[i].MinOption
			== gGrandResetSystem.m_GRData.ItemData[i].MaxOption)
		{
			ZeroMemory(OptionBuff, sizeof(OptionBuff));
			sprintf(OptionBuff, "+%d] ", gGrandResetSystem.m_GRData.ItemData[i].MinOption * 4);
			strcat(ItemNameBuff, OptionBuff);
		}
		else
		{
			ZeroMemory(OptionBuff, sizeof(OptionBuff));
			sprintf(OptionBuff, "+%d~%d] ",
				gGrandResetSystem.m_GRData.ItemData[i].MinOption * 4,
				gGrandResetSystem.m_GRData.ItemData[i].MaxOption * 4);
			strcat(ItemNameBuff, OptionBuff);
		}
		// ----
		if (gGrandResetSystem.m_GRData.ItemData[i].IsLuck == 0)
		{
			strcat(ItemNameBuff, "+ Không Có Luck ");
		}
		else if (gGrandResetSystem.m_GRData.ItemData[i].IsLuck == 1)
		{
			strcat(ItemNameBuff, "+ Có Luck ");
		}
		// ----
		if (gGrandResetSystem.m_GRData.ItemData[i].IsSkill == 0)
		{
			strcat(ItemNameBuff, "+ Không Có Skill");
		}
		else if (gGrandResetSystem.m_GRData.ItemData[i].IsSkill == 1)
		{
			strcat(ItemNameBuff, "+ Có Skill");
		}
		// ----
		if (!gObjUser.m_reset_item_check[i])
		{
			pDrawGUI(0x7BC4, StartX + 22.0, 251 + (i * 8), 7.0, 7.0);
		}
		else
		{
			pDrawGUI(0x7BC1, StartX + 22.0, 251 + (i * 8), 7.0, 7.0);
		}
		// ----
		gInterface.DrawText(ItemNameColor, StartX + 30, 250 + (i * 8), 210, 1, ItemNameBuff);
	}
	// ----
	if (gGrandResetSystem.m_GRData.ItemCount <= 0)
	{
		gInterface.DrawText(eWhite, StartX + 30, 250, 210, 1, "- Không Có");
	}
	// ----
	gInterface.DrawText(eGold, StartX + 30, 295, 210, 1, "Số Zen Cần Có:");
	gInterface.DrawGUI(OBJECT_GRESET_MONEY_BG, StartX + 30, 305);
	// ----
	char MoneyBuff[50], MoneyBuff2[50];
	ZeroMemory(MoneyBuff, sizeof(MoneyBuff));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	// ----
	if (gObjUser.lpPlayer->MoneyInventory
		< gGrandResetSystem.get_reset_money())
	{
		pGetMoneyFormat((double)gGrandResetSystem.get_reset_money(), MoneyBuff, 0);
		pGetMoneyFormat((double)gGrandResetSystem.get_reset_money() - gObjUser.lpPlayer->MoneyInventory, MoneyBuff2, 0);
		gInterface.DrawText(eRed, StartX + 70, 309, 170, 1, "%s\n(Bạn Còn Thiếu %s)", MoneyBuff, MoneyBuff2);
	}
	else
	{
		pGetMoneyFormat((double)gGrandResetSystem.get_reset_money(), MoneyBuff, 0);
		gInterface.DrawText(eGold, StartX + 70, 312, 70, 1, "%s", MoneyBuff);
	}
	// ----
	gInterface.DrawGUI(OBJECT_GRESET_FINISH, ButtonX, gInterface.Data[OBJECT_GRESET_FOOTER].Y + 10);
	gInterface.DrawText(eWhite, StartX + 8, gInterface.Data[OBJECT_GRESET_FOOTER].Y + 20, 210, 3, "Bắt Đầu Relife");
	gInterface.DrawGUI(OBJECT_GRESET_DIV, StartX, gInterface.Data[OBJECT_GRESET_FOOTER].Y - 10);
	// ----
	if (!gGrandResetSystem.check_all_req())
	{
		gInterface.Data[OBJECT_GRESET_FINISH].Attribute = false;
		gInterface.DrawColoredGUI(OBJECT_GRESET_FINISH, gInterface.Data[OBJECT_GRESET_FINISH].X, gInterface.Data[OBJECT_GRESET_FINISH].Y, eGray150);
		return;
	}
	// ----
	gInterface.Data[OBJECT_GRESET_FINISH].Attribute = true;
	// ----
	if (gInterface.IsWorkZone(OBJECT_GRESET_FINISH))
	{
		DWORD Color = eGray100;
		if (gInterface.Data[OBJECT_GRESET_FINISH].OnClick)
		{
			Color = eGray150;
		}
		gInterface.DrawColoredGUI(OBJECT_GRESET_FINISH, gInterface.Data[OBJECT_GRESET_FINISH].X, gInterface.Data[OBJECT_GRESET_FINISH].Y, Color);
	}
}

void GRSystem::EventGrandResetWindow_Main(DWORD Event)
{
	this->EventGrandResetWindow_Close(Event);
	this->EventGrandResetWindow_Finish(Event);
}
// ----------------------------------------------------------------------------------------------

void GRSystem::EventGrandResetWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_GRESET_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[OBJECT_GRESET_MAIN].OnShow || !gInterface.IsWorkZone(OBJECT_GRESET_CLOSE))
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[OBJECT_GRESET_CLOSE].OnClick = true;
		return;
	}
	// ----
	gInterface.Data[OBJECT_GRESET_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	gInterface.Data[OBJECT_GRESET_CLOSE].EventTick = GetTickCount();
	gInterface.Data[OBJECT_GRESET_MAIN].Close();
	// ----
	return;
}
// ----------------------------------------------------------------------------------------------

void GRSystem::EventGrandResetWindow_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_GRESET_FINISH].EventTick);
	// ----
	if (!gInterface.Data[OBJECT_GRESET_MAIN].OnShow || !gInterface.IsWorkZone(OBJECT_GRESET_FINISH)
		|| !gInterface.Data[OBJECT_GRESET_FINISH].Attribute)
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[OBJECT_GRESET_FINISH].OnClick = true;
		return;
	}
	// ----
	gInterface.Data[OBJECT_GRESET_FINISH].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	gInterface.Data[OBJECT_GRESET_FINISH].EventTick = GetTickCount();
	this->req_reset_finish();
	gInterface.Data[OBJECT_GRESET_MAIN].Close();
	// ----
	return;
}

int GRSystem::get_reset_money() const
{
	return this->GResetMoney;
}

bool GRSystem::check_all_req() const
{
	if (gObjUser.lpPlayer->MoneyInventory
		< this->get_reset_money())
	{
		return false;
	}
	// ----
	if (ViewReset < this->m_GRData.ReqReset/*this->m_GroupData[this->GetResetGroup()].ReqReset[ViewAccountLevel]*/)
	{
		return false;
	}
	// ----
	if (gObjUser.lpPlayer->Level < this->m_GRData.ReqLevel/*this->m_GroupData[this->GetResetGroup()].ReqLevel*/)
	{
		return false;
	}
	// ----
	for (int i = 0; i < this->m_GRData.ItemCount/*this->m_GroupData[this->GetResetGroup()].ItemCount*/; i++)
	{
		if (!gObjUser.m_reset_item_check[i])
		{
			return false;
		}
	}
	// ----
	return true;
}

void GRSystem::set_data(GR_ANS_USERDATA* aRecv)
{
	ZeroMemory(gObjUser.m_reset_item_check, sizeof(gObjUser.m_reset_item_check));
	// ----
	ViewReset = aRecv->Reset;
	ViewGReset = aRecv->GrandReset;

	this->GResetMoney = aRecv->GResetMoney;
	this->m_BonusCommand = aRecv->CommandPerGReset;

	//gObjUser.m_QuestStat = aRecv->QuestStat;

	this->m_GRData = aRecv->GrData;

	//console.Log("", "[ResetSystem]\t\tReset=[%d] GReset=[%d]", aRecv->Reset, aRecv->GrandReset);
	// ----
	for (int i = 0; i < 5; i++)
	{
		gObjUser.m_reset_item_check[i] = aRecv->ItemCheck[i];
	}
	// ----
	if (aRecv->ByDialog)
	{
		//this->SwitchStatsWindowState();
		gInterface.Data[OBJECT_GRESET_MAIN].Open();
	}
}

void GRSystem::req_reset_finish()
{
	GR_REQ_USERDATA pRequest;
	pRequest.h.set(0xFF, 0x03, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);
}

void GRSystem::get_reset_result()
{
    //this->SwitchStatsWindowState();
	gInterface.Data[OBJECT_GRESET_MAIN].Close();
}

int GRSystem::get_reward_points(int add) const
{
	return this->m_GRData.RewardData.LevelPoint * (ViewGReset + add);
}
