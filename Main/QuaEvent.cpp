#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "QUAEVENT.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "CustomMessage.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
#include "Other.h"
#include "PrintPlayer.h"
#include "SItemOption.h"
#include "Import.h"
#include "Central.h"
#include "User.h"

#if(QUAEVENT == 1)
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_QUATOP1 G_BEXO_QUATOP1;
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_QUATOP1::BEXO_QUATOP1()
{
	//--------------------------------------------------------------
	HIENTHIQUATOP1 = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_QUATOP1::BIND()
{
	gInterface.BindObject(EXBEXO_QUATOP1_MAIN, 31461, 640, 419, -1, -1);  // 31461
	gInterface.BindObject(EXBEXO_QUATOP1_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(QUATOP1, 10099, 30, 20, -1, -1);

}
// ----------------------------------------------------------------------------------------------


void BEXO_QUATOP1::DRAW_QUATOP1()
{
	DRAW_WINDOW_QUATOP1();
}

void BEXO_QUATOP1::DRAW_WINDOW_QUATOP1()
{

	if (gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(MoveList)
		|| gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Party)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ExpandWarehouse))
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (!gInterface.Data[EXBEXO_QUATOP1_MAIN].OnShow)
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone(StartX, StartY, StartX + MainWidth, StartY + MainHeight)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	RenderBitmap(500001,StartX + 180, gInterface.Data[EXBEXO_QUATOP1_MAIN].Y + 25, 315, 580, 0, 0, 1, 1, 1, 1, 0.0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_QUATOP1_CLOSE, StartX + 410, gInterface.Data[EXBEXO_QUATOP1_MAIN].Y + 23);
	if (gInterface.IsWorkZone(EXBEXO_QUATOP1_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_QUATOP1_CLOSE, gInterface.Data[EXBEXO_QUATOP1_CLOSE].X, gInterface.Data[EXBEXO_QUATOP1_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float XQUATOP1 = 150;

	gInterface.DrawFormat(eGold, XQUATOP1 + 57, gInterface.Data[EXBEXO_QUATOP1_MAIN].Y + 35, 200, 3, "Quà Top 1 Event");
	gInterface.DrawFormat(eBlue, XQUATOP1 + 55, gInterface.Data[EXBEXO_QUATOP1_MAIN].Y + 45, 200, 3, "Để trống hòm đồ trước khi nhận!");

	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 1
	gCItemSetOption.ItemTooltipS15(XQUATOP1 + 50, gInterface.Data[EXBEXO_QUATOP1_MAIN].Y + 60, 200, 15, 0.0, 0);
	//----
	int QuaTop1;
	if (gObjUser.QuaTop1Check1 > 0)
	{
		QuaTop1 = (gObjUser.QUATOP1COIN * gObjUser.QuaTop1Check1) / gObjUser.QuaTop1Check1;
		if (QuaTop1 > gObjUser.QuaTop1Check1)
		{
			QuaTop1 = gObjUser.QuaTop1Check1;
		}
	}
	float TyLeNap1 = (199.0 * QuaTop1) / gObjUser.QuaTop1Check1;
	if (TyLeNap1 > 199.0) { TyLeNap1 = 199.0; }
	//RenderBitmap(0x0897, 201.0f, 60.0f, TyLeNap1, 18, 0, 0, 1, 1, 1, 1, 0.0);
		pDrawGUI(0x0897, 201.0f, 60.0f, TyLeNap1, 14.0f);
	gInterface.DrawFormat(eRed, XQUATOP1 + 55, gInterface.Data[EXBEXO_QUATOP1_MAIN].Y + 62, 200, 3, "Khi Bạn Đạt Top 1 Event Thì Nhận Quà Tại Đây", gObjUser.QuaTop1Check1);
	//----
	if (gObjUser.QUATOP1 == 1)
	{
		gInterface.DrawFormat(eExcellent, XQUATOP1 + 168, gInterface.Data[EXBEXO_QUATOP1_MAIN].Y + 62, 200, 3, "Đã Nhận");
	}
	if (gObjUser.QUATOP1 == 0)
	{
		if (gObjUser.QUATOP1COIN >= gObjUser.QuaTop1Check1)
		{
			gInterface.DrawGUI(QUATOP1, XQUATOP1 + 250, gInterface.Data[EXBEXO_QUATOP1_MAIN].Y + 57);
			gInterface.DrawFormat(eGold, XQUATOP1 + 168, gInterface.Data[EXBEXO_QUATOP1_MAIN].Y + 62, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(QUATOP1))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(QUATOP1, gInterface.Data[QUATOP1].X, gInterface.Data[QUATOP1].Y, Color);
			}
		}
	}
	/// ket thuc
	
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_QUATOP1::MAIN_QUATOP1(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_QUATOP1(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_QUATOP1_MAIN].OnShow && gInterface.IsWorkZone(QUATOP1))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[QUATOP1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[QUATOP1].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[QUATOP1].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[QUATOP1].EventTick = GetTickCount();
		this->CLOSE_WINDOW_QUATOP1();
		gInterface.BUY_TINH_NANG_GAME(34);
	}
	
	//------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_QUATOP1::CLOSE_QUATOP1(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_QUATOP1_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_QUATOP1_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_QUATOP1_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_QUATOP1_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_QUATOP1_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_QUATOP1_CLOSE].EventTick = GetTickCount();
	G_BEXO_QUATOP1.CLOSE_WINDOW_QUATOP1();
	// ----
	return false;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
#endif