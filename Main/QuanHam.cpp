#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "QuanHam.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "CustomMessage.h"
#include "Defines.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
#include "Other.h"
#include "PrintPlayer.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_QUAN_HAM G_BEXO_QUAN_HAM;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#define MAX_TRANG_QUAN_HAM    1  // OK

//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_QUAN_HAM::BEXO_QUAN_HAM()
{
	TRANG_QUAN_HAM = 1;
	//--------------------------------------------------------------
	HIENTHIQUAN_HAM = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_QUAN_HAM::DRAW_QUAN_HAM()
{
	DRAW_WINDOW_QUAN_HAM();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_QUAN_HAM::BEXO_CLICK_TRANG_QUAN_HAM(DWORD ClickMouse)
{
	if (!gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow)
	{
		return;
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);
	if (gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_HAM1))
	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (1 < TRANG_QUAN_HAM && TRANG_QUAN_HAM <= MAX_TRANG_QUAN_HAM)
		{
			TRANG_QUAN_HAM--;
		}
		ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_HAM2))

	{
		if (ClickMouse == WM_LBUTTONDOWN)
		{
			pSetCursorFocus = true;
			return;
		}
		pSetCursorFocus = false;
		if (Delay < 300)
		{
			return;
		}
		if (1 <= TRANG_QUAN_HAM && TRANG_QUAN_HAM < MAX_TRANG_QUAN_HAM)
		{
			TRANG_QUAN_HAM++;
		}
		ClickTick = GetTickCount();
	}
	if (TRANG_QUAN_HAM < 1)
	{
		TRANG_QUAN_HAM = 1;
	}
	if (TRANG_QUAN_HAM > TRANG_QUAN_HAM)
	{
		TRANG_QUAN_HAM = TRANG_QUAN_HAM;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_QUAN_HAM::DRAW_WINDOW_QUAN_HAM()
{

	if (gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(MoveList)
		|| (gInterface.CheckWindow(Inventory)
		&& gInterface.CheckWindow(ExpandInventory)
		&& gInterface.CheckWindow(Store))
		|| (gInterface.CheckWindow(Inventory)
		&& gInterface.CheckWindow(Warehouse)
		&& gInterface.CheckWindow(ExpandWarehouse)))
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (!gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow)
	{
		return;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	pDrawGUFULL(0x0899, StartX + 70, StartY + 50, 900, 550, 0, 0, 1, 1, 1, 1, 0.0); // MENU
	//gInterface.DrawGUI(EXBEXO_QUAN_HAM_MAIN, StartX, StartY);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone(StartX, StartY, StartX + MainWidth, StartY + MainHeight)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 90, 210, 1, gOther.TextVN_QuanHam[0]);
	if(gInterface.m_QuanHam == 0)
	{
			gInterface.DrawFormat(eYellow, StartX + 102, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 105, 210, 1, "Dành Cho Guild Đạt");
	}
	if(gInterface.m_QuanHam == 1)
	{
			gInterface.DrawFormat(eYellow, StartX + 102, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 105, 210, 1, "Dành Cho Guild Đạt");
	}
	if(gInterface.m_QuanHam == 2)
	{
			gInterface.DrawFormat(eYellow, StartX + 102, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 105, 210, 1, "Dành Cho Guild Đạt");
	}
	if(gInterface.m_QuanHam == 3)
	{
			gInterface.DrawFormat(eYellow, StartX + 102, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 105, 210, 1, "Dành Cho Guild Đạt");
	}
	gInterface.DrawFormat(eSocket, StartX + 85, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 120, 210, 1, gOther.TextVN_QuanHam[2]);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_QUAN_HAM_NANG_CAP, StartX + 435, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 100);

	if (gInterface.IsWorkZone(EXBEXO_QUAN_HAM_NANG_CAP))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(EXBEXO_QUAN_HAM_NANG_CAP, gInterface.Data[EXBEXO_QUAN_HAM_NANG_CAP].X, gInterface.Data[EXBEXO_QUAN_HAM_NANG_CAP].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eAncient, StartX + 440, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 110, 210, 1, gOther.TextVN_QuanHam[3]);

	gInterface.DrawFormat(eYellow, StartX + 270, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 132, 210, 1, gOther.TextVN_QuanHam[4], gInterface.m_QuanHam);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eQUAN_HAM1, StartX + 70, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eQUAN_HAM1))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eQUAN_HAM1, gInterface.Data[eQUAN_HAM1].X, gInterface.Data[eQUAN_HAM1].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eQUAN_HAM2, StartX + 535, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210);

	if (gInterface.IsWorkZone(eQUAN_HAM2))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eQUAN_HAM2, gInterface.Data[eQUAN_HAM2].X, gInterface.Data[eQUAN_HAM2].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_QUAN_HAM_CLOSE, StartX + 532, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 52);
	if (gInterface.IsWorkZone(EXBEXO_QUAN_HAM_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_QUAN_HAM_CLOSE, gInterface.Data[EXBEXO_QUAN_HAM_CLOSE].X, gInterface.Data[EXBEXO_QUAN_HAM_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (Coin1 >= 50000)
	{
		RenderBitmap(0x0897, StartX + 197, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 109, 50, 14, 0, 0, 1, 1, 1, 1, 0.0);
	}
	if (Coin1 >= 200000)
	{
		RenderBitmap(0x0897, StartX + 245, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 109, 50, 14, 0, 0, 1, 1, 1, 1, 0.0);
	}
	if (Coin1 >= 400000)
	{
		RenderBitmap(0x0897, StartX + 293, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 109, 50, 14, 0, 0, 1, 1, 1, 1, 0.0);
	}
	if (Coin1 >= 600000)
	{
		RenderBitmap(0x0897, StartX + 341, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 109, 20, 14, 0, 0, 1, 1, 1, 1, 0.0);
	}
	if (Coin1 >= 800000)
	{
		RenderBitmap(0x0897, StartX + 359, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 109, 20, 14, 0, 0, 1, 1, 1, 1, 0.0);
	}
	if (Coin1 >= 1000000)
	{
		RenderBitmap(0x0897, StartX + 377, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 109, 23, 14, 0, 0, 1, 1, 1, 1, 0.0);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eRed, StartX + 270, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 108, 210, 1, gOther.TextVN_QuanHam[5], Coin1);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	switch (TRANG_QUAN_HAM) //====================================================================================================================================
	{
		case 1:
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		if (gInterface.m_QuanHam >= 1)
		{
			RenderBitmap(0x0898, StartX + 96, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 2)
		{
			RenderBitmap(0x0898, StartX + 208, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_QuanHam >= 3)
		{
			RenderBitmap(0x0898, StartX + 320, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 155, 106, 259, 0, 0, 1, 1, 1, 1, 0.0);
		}
		//-----------------------------------------------------------------------------------------------------------------------------------------------------
		RenderBitmap(10124, StartX + 115, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 160, 65, 60, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10125, StartX + 227, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 160, 65, 60, 0, 0, 1, 1, 1, 1, 0.0);
		RenderBitmap(10126, StartX + 335, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 160, 75, 60, 0, 0, 1, 1, 1, 1, 0.0);

		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gOther.TextVN_QuanHam[6]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gOther.TextVN_QuanHam[7]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gOther.TextVN_QuanHam[8]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gOther.TextVN_QuanHam[9]);
		gInterface.DrawFormat(eWhite, StartX + 110, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gOther.TextVN_QuanHam[10]);

		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gOther.TextVN_QuanHam[11]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gOther.TextVN_QuanHam[12]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gOther.TextVN_QuanHam[13]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gOther.TextVN_QuanHam[14]);
		gInterface.DrawFormat(eWhite, StartX + 225, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gOther.TextVN_QuanHam[15]);

		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 210, 210, 1, gOther.TextVN_QuanHam[16]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 230, 210, 1, gOther.TextVN_QuanHam[17]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 250, 210, 1, gOther.TextVN_QuanHam[18]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 270, 210, 1, gOther.TextVN_QuanHam[19]);
		gInterface.DrawFormat(eWhite, StartX + 338, gInterface.Data[EXBEXO_QUAN_HAM_MAIN].Y + 290, 210, 1, gOther.TextVN_QuanHam[20]);
		//=============================================================================================================================================================
		break;
	default:
		break;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_QUAN_HAM::MAIN_QUAN_HAM(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_QUAN_HAM(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	// TRANG 1
	if (gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow && gInterface.IsWorkZone(EXBEXO_QUAN_HAM_NANG_CAP))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_QUAN_HAM_NANG_CAP].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[EXBEXO_QUAN_HAM_NANG_CAP].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		//gInterface.Data[EXBEXO_QUAN_HAM_NANG_CAP].OnClick = false;
		//pSetCursorFocus = false;
		//// ----
		//if (Delay < 5000)
		//{
		//	return false;
		//}
		//gInterface.Data[EXBEXO_QUAN_HAM_NANG_CAP].EventTick = GetTickCount();
		//this->BUY_QUAN_HAM(1);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_QUAN_HAM::CLOSE_QUAN_HAM(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_QUAN_HAM_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_QUAN_HAM_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_QUAN_HAM_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_QUAN_HAM_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_QUAN_HAM_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_QUAN_HAM_CLOSE].EventTick = GetTickCount();
	G_BEXO_QUAN_HAM.CLOSE_WINDOW_QUAN_HAM();
	// ----
	return false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
//void BEXO_QUAN_HAM::BUY_QUAN_HAM(int Number)
//{
//	BUY_QUAN_HAM_REQ pMsg;
//	pMsg.h.set(0xFC, 0x04, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
//	pMsg.Number = Number;
//	DataSend((BYTE*)&pMsg, pMsg.h.size);
//}