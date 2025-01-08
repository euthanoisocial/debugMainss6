#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "QUAEVENT1.h"
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
BEXO_QUATOP2 G_BEXO_QUATOP2;
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_QUATOP2::BEXO_QUATOP2()
{
	//--------------------------------------------------------------
	HIENTHIQUATOP2 = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_QUATOP2::BIND()
{
	gInterface.BindObject(EXBEXO_QUATOP2_MAIN, 31461, 640, 419, -1, -1);  // 31461
	gInterface.BindObject(EXBEXO_QUATOP2_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(QUATOP2, 10099, 30, 20, -1, -1);

}
// ----------------------------------------------------------------------------------------------


void BEXO_QUATOP2::DRAW_QUATOP2()
{
	DRAW_WINDOW_QUATOP2();
}

void BEXO_QUATOP2::DRAW_WINDOW_QUATOP2()
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
	if (!gInterface.Data[EXBEXO_QUATOP2_MAIN].OnShow)
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
	RenderBitmap(500001,StartX + 180, gInterface.Data[EXBEXO_QUATOP2_MAIN].Y + 25, 315, 580, 0, 0, 1, 1, 1, 1, 0.0);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_QUATOP2_CLOSE, StartX + 410, gInterface.Data[EXBEXO_QUATOP2_MAIN].Y + 23);
	if (gInterface.IsWorkZone(EXBEXO_QUATOP2_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_QUATOP2_CLOSE, gInterface.Data[EXBEXO_QUATOP2_CLOSE].X, gInterface.Data[EXBEXO_QUATOP2_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float XQUATOP2 = 150;

	gInterface.DrawFormat(eGold, XQUATOP2 + 57, gInterface.Data[EXBEXO_QUATOP2_MAIN].Y + 35, 200, 3, "Quà Top 2 Event");
	gInterface.DrawFormat(eBlue, XQUATOP2 + 55, gInterface.Data[EXBEXO_QUATOP2_MAIN].Y + 45, 200, 3, "Để trống hòm đồ trước khi nhận!");

	//======================================================================================================================
	//======================================================================================================================
	/// Moc Nap 1
	gCItemSetOption.ItemTooltipS15(XQUATOP2 + 50, gInterface.Data[EXBEXO_QUATOP2_MAIN].Y + 60, 200, 15, 0.0, 0);
	//----
	int QuaTop2;
	if (gObjUser.QuaTop2Check1 > 0)
	{
		QuaTop2 = (gObjUser.QUATOP2COIN * gObjUser.QuaTop2Check1) / gObjUser.QuaTop2Check1;
		if (QuaTop2 > gObjUser.QuaTop2Check1)
		{
			QuaTop2 = gObjUser.QuaTop2Check1;
		}
	}
	float TyLeNap1 = (199.0 * QuaTop2) / gObjUser.QuaTop2Check1;
	if (TyLeNap1 > 199.0) { TyLeNap1 = 199.0; }
	//RenderBitmap(0x0897, 201.0f, 60.0f, TyLeNap1, 18, 0, 0, 1, 1, 1, 1, 0.0);
		pDrawGUI(0x0897, 201.0f, 60.0f, TyLeNap1, 14.0f);
	gInterface.DrawFormat(eRed, XQUATOP2 + 55, gInterface.Data[EXBEXO_QUATOP2_MAIN].Y + 62, 200, 3, "Khi Bạn Đạt Top 2 Event Thì Nhận Quà Tại Đây", gObjUser.QuaTop2Check1);
	//----
	if (gObjUser.QUATOP2 == 1)
	{
		gInterface.DrawFormat(eExcellent, XQUATOP2 + 168, gInterface.Data[EXBEXO_QUATOP2_MAIN].Y + 62, 200, 3, "Đã Nhận");
	}
	if (gObjUser.QUATOP2 == 0)
	{
		if (gObjUser.QUATOP2COIN >= gObjUser.QuaTop2Check1)
		{
			gInterface.DrawGUI(QUATOP2, XQUATOP2 + 250, gInterface.Data[EXBEXO_QUATOP2_MAIN].Y + 57);
			gInterface.DrawFormat(eGold, XQUATOP2 + 168, gInterface.Data[EXBEXO_QUATOP2_MAIN].Y + 62, 200, 3, "Nhận");
			if (gInterface.IsWorkZone(QUATOP2))
			{
				DWORD Color = eGray150;

				gInterface.DrawColoredGUI(QUATOP2, gInterface.Data[QUATOP2].X, gInterface.Data[QUATOP2].Y, Color);
			}
		}
	}
	/// ket thuc
	
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_QUATOP2::MAIN_QUATOP2(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_QUATOP2(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.Data[EXBEXO_QUATOP2_MAIN].OnShow && gInterface.IsWorkZone(QUATOP2))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[QUATOP2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[QUATOP2].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[QUATOP2].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[QUATOP2].EventTick = GetTickCount();
		this->CLOSE_WINDOW_QUATOP2();
		gInterface.BUY_TINH_NANG_GAME(36);
	}
	
	//------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_QUATOP2::CLOSE_QUATOP2(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_QUATOP2_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_QUATOP2_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_QUATOP2_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_QUATOP2_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_QUATOP2_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_QUATOP2_CLOSE].EventTick = GetTickCount();
	G_BEXO_QUATOP2.CLOSE_WINDOW_QUATOP2();
	// ----
	return false;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
#endif