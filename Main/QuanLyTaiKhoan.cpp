
#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "QuanLyTaiKhoan.h"
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
#include "DanhHieu.h"
#include "CustomHeThong.h"
#include "MocNap.h"
#include "QuaEvent.h"
#include "QuaEvent1.h"
#include "QuaEvent2.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
QUAN_LY_TK G_QUAN_LY_TK;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#define MAX_TRANG_QUAN_LY    10  // OK

//-----------------------------------------------------------------------------------------------------------------------------------------------------
QUAN_LY_TK::QUAN_LY_TK()
{
	TRANG_QUAN_LY = 1;
	//--------------------------------------------------------------
	HIENTHIQUAN_LY = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void QUAN_LY_TK::DRAW_QUAN_LY()
{
	DRAW_WINDOW_QUAN_LY_TK();
	DRAW_WINDOW_CHANGEPASS();
}

void QUAN_LY_TK::BinObeject()
{
	gInterface.BindObject(QUAN_LY_TK_MAIN, 31461, 640, 419, -1, -1);  // 31461
	gInterface.BindObject(QUAN_LY_TK_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY1, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY2, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY3, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY4, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY5, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY6, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY7, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY8, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY9, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY10, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY11, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY12, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_LY13, 0x7A5E, 108, 29, -1, -1);

}
void QUAN_LY_TK::LoadImages()
{

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void QUAN_LY_TK::CLICK_TRANG_QUAN_LY(DWORD ClickMouse)
{
	if (!gInterface.Data[QUAN_LY_TK_MAIN].OnShow)
	{
		return;
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);

	if (gInterface.Data[QUAN_LY_TK_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_LY1))
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
		if (TRANG_QUAN_LY = 1)

			G_QUAN_LY_TK.OPEN_WINDOW_CHANGEPASS(); //<< on off Changepass
			ClickTick = GetTickCount();
			gInterface.Data[QUAN_LY_TK_MAIN].CloseAnimated(15);
	}
	if (gInterface.Data[QUAN_LY_TK_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_LY2))

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
		if (TRANG_QUAN_LY = 2)

			G_BEXO_MOCNAP.OPEN_WINDOW_MOCNAP();

			ClickTick = GetTickCount();
			gInterface.Data[QUAN_LY_TK_MAIN].CloseAnimated(15);
	}
	if (gInterface.Data[QUAN_LY_TK_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_LY3))

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
		if (TRANG_QUAN_LY = 3)

			G_BEXO_QUATOP1.OPEN_WINDOW_QUATOP1();

			ClickTick = GetTickCount();
			gInterface.Data[QUAN_LY_TK_MAIN].CloseAnimated(15);
	}
	if (gInterface.Data[QUAN_LY_TK_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_LY4))

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
		if (TRANG_QUAN_LY = 4)

			G_BEXO_QUATOP2.OPEN_WINDOW_QUATOP2();

			ClickTick = GetTickCount();
			gInterface.Data[QUAN_LY_TK_MAIN].CloseAnimated(15);
	}
	if (gInterface.Data[QUAN_LY_TK_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_LY5))

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
		if (TRANG_QUAN_LY = 5)

			G_BEXO_QUATOP3.OPEN_WINDOW_QUATOP3();

			ClickTick = GetTickCount();
			gInterface.Data[QUAN_LY_TK_MAIN].CloseAnimated(15);
	}
	if (gInterface.Data[QUAN_LY_TK_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_LY6))

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
		if (TRANG_QUAN_LY = 6)

			ClickTick = GetTickCount();
		    
	}
	if (gInterface.Data[QUAN_LY_TK_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_LY7))

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
		if (TRANG_QUAN_LY = 7)

			ClickTick = GetTickCount();
		
	}
	if (gInterface.Data[QUAN_LY_TK_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_LY8))

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
		if (TRANG_QUAN_LY = 8)

			ClickTick = GetTickCount();
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void QUAN_LY_TK::DRAW_WINDOW_QUAN_LY_TK()
{
	char Cord[256];
	if (gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(MoveList)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(ChatWindow)
		|| gInterface.CheckWindow(ChaosBox)
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
	if (!gInterface.Data[QUAN_LY_TK_MAIN].OnShow)
	{
		return;
	}

		if (gInterface.Data[QUAN_LY_TK_MAIN].ByClose == false)
	{
		if (gInterface.Data[QUAN_LY_TK_MAIN].OpenedValue < 0)
		{
			gInterface.Data[QUAN_LY_TK_MAIN].OpenedValue += gInterface.Data[QUAN_LY_TK_MAIN].Speed;

			if (gInterface.Data[QUAN_LY_TK_MAIN].OpenedValue >= -150)
			{
				gInterface.Data[QUAN_LY_TK_MAIN].Speed = 15;
			}

			if (gInterface.Data[QUAN_LY_TK_MAIN].OpenedValue > 0)
			{
				gInterface.Data[QUAN_LY_TK_MAIN].OpenedValue = 0;
			}
		}
	}
	else
	{
		if (gInterface.Data[QUAN_LY_TK_MAIN].OpenedValue > -226)
		{
			gInterface.Data[QUAN_LY_TK_MAIN].OpenedValue -= gInterface.Data[QUAN_LY_TK_MAIN].Speed;

			if (gInterface.Data[QUAN_LY_TK_MAIN].OpenedValue <= -150)
			{
				gInterface.Data[QUAN_LY_TK_MAIN].Speed = 20;
			}

			if (gInterface.Data[QUAN_LY_TK_MAIN].OpenedValue <= -226)
			{
				gInterface.Data[QUAN_LY_TK_MAIN].Close();

			}
		}
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float StartY = 198;
	float StartX = gInterface.Data[QUAN_LY_TK_MAIN].OpenedValue;
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone(QUAN_LY_TK_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//RenderBitmap(500001,StartX + 104, gInterface.Data[QUAN_LY_TK_MAIN].Y + 50, 150, 370, 0, 0, 1, 1, 1, 1, 0.0);
	RenderBitmap(500001,StartX + 0, gInterface.Data[QUAN_LY_TK_MAIN].Y + 110, 150, 370, 0, 0, 1, 1, 1, 1, 0.0);
	//RenderBitmap(500001,StartX + 230, gInterface.Data[QUAN_LY_TK_MAIN].Y + 50, 370, 470, 0, 0, 1, 1, 1, 1, 0.0);
	//0x7A58

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[QUAN_LY_TK_MAIN].Y + 90, 210, 1, Config.TextVN_DanhHieu[0]);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	
	//gInterface.DrawGUI(eQUAN_LY1, StartX + 115, gInterface.Data[QUAN_LY_TK_MAIN].Y + 80);

	//gInterface.DrawGUI(eQUAN_LY2, StartX + 115, gInterface.Data[QUAN_LY_TK_MAIN].Y + 110);

	gInterface.DrawAnimatedGUI(eQUAN_LY1, StartX + 11, gInterface.Data[eMENU_MAIN].Y +  170);

	gInterface.DrawAnimatedGUI(eQUAN_LY2, StartX + 11, gInterface.Data[eMENU_MAIN].Y +  200);

	gInterface.DrawAnimatedGUI(eQUAN_LY3, StartX + 11, gInterface.Data[eMENU_MAIN].Y +  230);

	gInterface.DrawAnimatedGUI(eQUAN_LY4, StartX + 11, gInterface.Data[eMENU_MAIN].Y +  260);

	gInterface.DrawAnimatedGUI(eQUAN_LY5, StartX + 11, gInterface.Data[eMENU_MAIN].Y +  290);
	
	if( gProtect.m_MainInfo.Disabledanhhieu == 0 )
	{
	//gInterface.DrawGUI(eQUAN_LY3, StartX + 115, gInterface.Data[QUAN_LY_TK_MAIN].Y + 140);
	}
	if( gProtect.m_MainInfo.Disablequanham == 0 )
	{
	//gInterface.DrawGUI(eQUAN_LY4, StartX + 110, gInterface.Data[QUAN_LY_TK_MAIN].Y + 170);
	}
	if( gProtect.m_MainInfo.Disabletuluyen == 0 )
	{
	//gInterface.DrawGUI(eQUAN_LY5, StartX + 110, gInterface.Data[QUAN_LY_TK_MAIN].Y + 200);
	}
	if( gProtect.m_MainInfo.Disablekinhmach == 0 )
	{
	//gInterface.DrawGUI(eQUAN_LY6, StartX + 110, gInterface.Data[QUAN_LY_TK_MAIN].Y + 230);
	}
	if( gProtect.m_MainInfo.Disablenguhanh == 0 )
	{
	//gInterface.DrawGUI(eQUAN_LY7, StartX + 115, gInterface.Data[QUAN_LY_TK_MAIN].Y + 170);
	}
	if( gProtect.m_MainInfo.Disablethuankhiet == 0 )
	{
    //gInterface.DrawGUI(eQUAN_LY8, StartX + 110, gInterface.Data[QUAN_LY_TK_MAIN].Y + 290);
	}

	//-----------------------------------------------------------------------------------------------------------------------------------------------------

	if (gInterface.IsWorkZone(eQUAN_LY1))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eQUAN_LY1, gInterface.Data[eQUAN_LY1].X, gInterface.Data[eQUAN_LY1].Y, Color);
	}
	
	if (gInterface.IsWorkZone(eQUAN_LY2))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eQUAN_LY2, gInterface.Data[eQUAN_LY2].X, gInterface.Data[eQUAN_LY2].Y, Color);
	}

	if (gInterface.IsWorkZone(eQUAN_LY3))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eQUAN_LY3, gInterface.Data[eQUAN_LY3].X, gInterface.Data[eQUAN_LY3].Y, Color);
	}

	if (gInterface.IsWorkZone(eQUAN_LY4))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eQUAN_LY4, gInterface.Data[eQUAN_LY4].X, gInterface.Data[eQUAN_LY4].Y, Color);
	}

	if (gInterface.IsWorkZone(eQUAN_LY5))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eQUAN_LY5, gInterface.Data[eQUAN_LY5].X, gInterface.Data[eQUAN_LY5].Y, Color);
	}
	
	
	if( gProtect.m_MainInfo.Disablekinhmach == 0 )
	{
	if (gInterface.IsWorkZone(eQUAN_LY6))
	{
		DWORD Color = eGray150;
		//gInterface.DrawColoredGUI(eQUAN_LY6, gInterface.Data[eQUAN_LY6].X, gInterface.Data[eQUAN_LY6].Y, Color);
	}
	}
	if( gProtect.m_MainInfo.Disablenguhanh == 0 )
	{
	if (gInterface.IsWorkZone(eQUAN_LY7))
	{
		DWORD Color = eGray150;
		//gInterface.DrawColoredGUI(eQUAN_LY7, gInterface.Data[eQUAN_LY7].X, gInterface.Data[eQUAN_LY7].Y, Color);
	}
	}
	if( gProtect.m_MainInfo.Disablethuankhiet == 0 )
	{
	if (gInterface.IsWorkZone(eQUAN_LY8))
	{
		DWORD Color = eGray150;
		//gInterface.DrawColoredGUI(eQUAN_LY8, gInterface.Data[eQUAN_LY8].X, gInterface.Data[eQUAN_LY8].Y, Color);
	}
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------

	//gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[QUAN_LY_TK_MAIN].Y + 90, 210, 1, "ĐỔI MẬT KHẨU");
	//

	//gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[QUAN_LY_TK_MAIN].Y + 120, 210, 1, "MỐC NẠP");

	gInterface.DrawFormat(eShinyGreen,StartX +65 , gInterface.Data[QUAN_LY_TK_MAIN].Y + 140, 210, 1, "%d",Coin1);
	gInterface.DrawFormat(eYellow,StartX +25, gInterface.Data[QUAN_LY_TK_MAIN].Y + 140, 210, 1, "WcoinC : ");
	gInterface.DrawFormat(eShinyGreen,StartX+65 , gInterface.Data[QUAN_LY_TK_MAIN].Y + 150, 210, 1, "%d",gInterface.m_DanhHieu);
	gInterface.DrawFormat(eYellow,StartX +25, gInterface.Data[QUAN_LY_TK_MAIN].Y + 150, 210, 1, "Danh Hiệu Cấp : ");
	gInterface.DrawFormat(eShinyGreen,StartX+65 , gInterface.Data[QUAN_LY_TK_MAIN].Y + 160, 210, 1, "%d",G_BEXO_HE_THONG.m_rNguHanh);
	gInterface.DrawFormat(eYellow,StartX +25, gInterface.Data[QUAN_LY_TK_MAIN].Y + 160, 210, 1, "Dragon Cấp : ");


	gInterface.DrawFormat(eYellow,StartX +32, gInterface.Data[QUAN_LY_TK_MAIN].Y + 120, 210, 1, "THÔNG TIN TÀI KHOẢN ");
	gInterface.DrawFormat(eYellow,StartX +25, gInterface.Data[QUAN_LY_TK_MAIN].Y + 130, 210, 1, "Xin Chào :  ");
	gInterface.DrawFormat(eExcellent,StartX +65, gInterface.Data[QUAN_LY_TK_MAIN].Y + 130 ,210,1, "%s",gObjUser.lpPlayer->Name);

	gInterface.DrawFormat(eWhite, StartX - 40, gInterface.Data[QUAN_LY_TK_MAIN].Y + 180, 210, 3, "Đổi Mật Khẩu");
	gInterface.DrawFormat(eWhite, StartX - 40, gInterface.Data[QUAN_LY_TK_MAIN].Y + 210, 210, 3, "Mốc Nạp");
	gInterface.DrawFormat(eWhite, StartX - 40, gInterface.Data[QUAN_LY_TK_MAIN].Y + 240, 210, 3, "Quà Top 1 Event");
	gInterface.DrawFormat(eWhite, StartX - 40, gInterface.Data[QUAN_LY_TK_MAIN].Y + 270, 210, 3, "Quà Top 2 Event");
	gInterface.DrawFormat(eWhite, StartX - 40, gInterface.Data[QUAN_LY_TK_MAIN].Y + 300, 210, 3, "Quà Top 3 Event");
	
	if( gProtect.m_MainInfo.Disabledanhhieu == 0 )
	{
	//gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[QUAN_LY_TK_MAIN].Y + 150, 210, 1, gOther.TextVN[26]);
	}
	if( gProtect.m_MainInfo.Disablequanham == 0 )
	{
	//gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[QUAN_LY_TK_MAIN].Y + 180, 210, 1, gOther.TextVN[27]);
	}
	if( gProtect.m_MainInfo.Disabletuluyen == 0 )
	{
	//gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[QUAN_LY_TK_MAIN].Y + 210, 210, 1, gOther.TextVN[28]);
	}
	if( gProtect.m_MainInfo.Disablekinhmach == 0 )
	{
	//gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[QUAN_LY_TK_MAIN].Y + 240, 210, 1, gOther.TextVN[29]);
	}
	if( gProtect.m_MainInfo.Disablenguhanh == 0 )
	{
	//gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[QUAN_LY_TK_MAIN].Y + 180, 210, 1, gOther.TextVN[30]);
	}
	if( gProtect.m_MainInfo.Disablethuankhiet == 0 )
	{
	//gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[QUAN_LY_TK_MAIN].Y + 300, 210, 1, gOther.TextVN[31]);
	}
	
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(QUAN_LY_TK_CLOSE, StartX + 102, 105);
	if (gInterface.IsWorkZone(QUAN_LY_TK_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(QUAN_LY_TK_CLOSE, gInterface.Data[QUAN_LY_TK_CLOSE].X, gInterface.Data[QUAN_LY_TK_CLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float StartBody = 70;
	float XVIPTAIKHOAN = 260;
	float XVIPNHANVAT = 260;
	float XDANHHIEU = 260;
	float XQUANHAM = 260;
	float XTULUYEN = 260;
	float XKINHMACH = 260;
	float XNGUHANH = 260;
	float XTHUANKHIET = 260;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	switch (TRANG_QUAN_LY)
	{

	case 1:

		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	case 5:
		break;

	case 6:
		break;

	case 7:
        break;

	case 8:
	    break;

	default:
		break;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool QUAN_LY_TK::MAIN_QUAN_LY(DWORD Event)
{
	this->CLOSE_QUAN_LY(Event);

#if(DOIMK)
	this->EVENT_CLICK_CHANGEPASS(Event);
#endif

		if (gInterface.Data[QUAN_LY_TK_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_LYTK1) && this->TRANG_QUAN_LY == 1)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUAN_LYTK1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUAN_LYTK1].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUAN_LYTK1].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUAN_LYTK1].EventTick = GetTickCount();
	
		this->CLOSE_WINDOW_QUAN_LY_TK();
	}

	if (gInterface.Data[QUAN_LY_TK_MAIN].OnShow && gInterface.IsWorkZone(eQUAN_LYTK2) && this->TRANG_QUAN_LY == 1)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUAN_LYTK2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUAN_LYTK2].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUAN_LYTK2].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUAN_LYTK2].EventTick = GetTickCount();

		this->CLOSE_WINDOW_QUAN_LY_TK();
	}

	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool QUAN_LY_TK::CLOSE_QUAN_LY(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[QUAN_LY_TK_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[QUAN_LY_TK_MAIN].OnShow || !gInterface.IsWorkZone(QUAN_LY_TK_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[QUAN_LY_TK_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[QUAN_LY_TK_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[QUAN_LY_TK_CLOSE].EventTick = GetTickCount();
	G_QUAN_LY_TK.CLOSE_WINDOW_QUAN_LY_TK();
	// ----
	return false;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
#if(DOIMK)
bool QUAN_LY_TK::EVENT_CLICK_CHANGEPASS(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eChangePass_BTCLOSE].EventTick);
	DWORD Delay_2 = (CurrentTick - gInterface.Data[eChangePass_BTOK].EventTick);
	// ----
	if (!gInterface.Data[eChangePass_Main].OnShow)
	{
		return false;
	}

	if (gInterface.IsWorkZone(eChangePass_OLD))
	{
		gInterface.Data[eChangePass_OLD].Attribute = 1;
	}
	else
	{
		gInterface.Data[eChangePass_OLD].Attribute = 0;
	}

	if (gInterface.IsWorkZone(eChangePass_NEW))
	{
		gInterface.Data[eChangePass_NEW].Attribute = 1;
	}
	else
	{
		gInterface.Data[eChangePass_NEW].Attribute = 0;
	}

	if (gInterface.IsWorkZone(eChangePass_BTCLOSE))
	{
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eChangePass_BTCLOSE].OnClick = true;
			return true;
		}
		// ----
		gInterface.Data[eChangePass_BTCLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		gInterface.Data[eChangePass_BTCLOSE].EventTick = GetTickCount();
		G_QUAN_LY_TK.OPEN_WINDOW_CHANGEPASS();
		sprintf(gInterface.Data[eChangePass_OLD].StatValue, ""); //NONE
		sprintf(gInterface.Data[eChangePass_OLD_HIDE].StatValue, ""); //NONE
		sprintf(gInterface.Data[eChangePass_NEW].StatValue, ""); //NONE
		sprintf(gInterface.Data[eChangePass_NEW_HIDE].StatValue, ""); //NONE
	}
	else if (gInterface.IsWorkZone(eChangePass_BTOK))
	{
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eChangePass_BTOK].OnClick = true;
			return true;
		}
		// ----
		gInterface.Data[eChangePass_BTOK].OnClick = false;
		// ----
		if (Delay_2 < 500)
		{
			return false;
		}
		// ----
		gInterface.Data[eChangePass_BTOK].EventTick = GetTickCount();
		//=== SEND GS
		CSENDGS_DOIMK pMsg;
		pMsg.TYPE = 0x01;
		memcpy(pMsg.PASS_OLD, gInterface.Data[eChangePass_OLD].StatValue, sizeof(pMsg.PASS_OLD));
		memcpy(pMsg.PASS_NEW, gInterface.Data[eChangePass_NEW].StatValue, sizeof(pMsg.PASS_NEW));
		pMsg.Head.set(0xFF, 0x91, sizeof(pMsg));
		DataSend((BYTE*)& pMsg, pMsg.Head.size);
		//===========
		G_QUAN_LY_TK.OPEN_WINDOW_CHANGEPASS();


		sprintf(gInterface.Data[eChangePass_OLD].StatValue, ""); //NONE
		sprintf(gInterface.Data[eChangePass_OLD_HIDE].StatValue, ""); //NONE
		sprintf(gInterface.Data[eChangePass_NEW].StatValue, ""); //NONE
		sprintf(gInterface.Data[eChangePass_NEW_HIDE].StatValue, ""); //NONE
	}
	// ----
	return false;
}
#include "Util.h"

bool QUAN_LY_TK::CHANGEPASS_TEXTBOX(DWORD Event)
{
	if (gInterface.Data[eChangePass_Main].OnShow && gInterface.Data[eChangePass_OLD].Attribute == 1)
	{
		char value[20];
		int is_backspace = false;
		int is_enter = false;
		int IsDelete = false;

		if (Event == VK_BACK)
		{
			is_backspace = true;
		}
		else if (Event == VK_RETURN)
		{
			is_enter = true;
		}
		else if (Event == VK_DELETE)
		{
			IsDelete = true;
		}
		else if ((Event >= 0x30 && Event <= 0x39) || (Event >= 0x60 && Event <= 0x69) || (Event >= 0x41 && Event <= 0x5A))
		{
			const int symbol = GetSymbolFromVK(Event);
			if (symbol == 0)
			{
				return 1;
			}
			char buff[10];
			sprintf(buff, "%c", symbol);
			strcpy_s(value, buff);
		}
		else
		{
			return true;
		}

		if (is_backspace == true)
		{
			if (!strcmp(gInterface.Data[eChangePass_OLD].StatValue, ""))
			{
				return true;
			}
			gInterface.Data[eChangePass_OLD].StatValue[strlen(gInterface.Data[eChangePass_OLD].StatValue) - 1] = '\0';
			gInterface.Data[eChangePass_OLD_HIDE].StatValue[strlen(gInterface.Data[eChangePass_OLD_HIDE].StatValue) - 1] = '\0';
		}
		else if (IsDelete == true)
		{
			strcpy_s(gInterface.Data[eChangePass_OLD].StatValue, "");
			strcpy_s(gInterface.Data[eChangePass_OLD_HIDE].StatValue, "");
		}
		else
		{
			if (strlen(gInterface.Data[eChangePass_OLD].StatValue) < 10)
			{
				if (!strcmp(gInterface.Data[eChangePass_OLD].StatValue, ""))
				{
					strcpy_s(gInterface.Data[eChangePass_OLD].StatValue, value);
					strcpy_s(gInterface.Data[eChangePass_OLD_HIDE].StatValue, "*");
				}
				else
				{
					strcat_s(gInterface.Data[eChangePass_OLD].StatValue, value);
					strcat_s(gInterface.Data[eChangePass_OLD_HIDE].StatValue, "*");
				}
			}
		}
	}
	
	else if (gInterface.Data[eChangePass_Main].OnShow && gInterface.Data[eChangePass_NEW].Attribute == 1)
	{
		char value[20];
		int is_backspace = false;
		int is_enter = false;
		int IsDelete = false;

		if (Event == VK_BACK)
		{
			is_backspace = true;
		}
		else if (Event == VK_RETURN)
		{
			is_enter = true;
		}
		else if (Event == VK_DELETE)
		{
			IsDelete = true;
		}
		else if ((Event >= 0x30 && Event <= 0x39) || (Event >= 0x60 && Event <= 0x69) || (Event >= 0x41 && Event <= 0x5A))
		{
			const int symbol = GetSymbolFromVK(Event);
			if (symbol == 0)
			{
				return 1;
			}
			char buff[10];
			sprintf(buff, "%c", symbol);
			strcpy_s(value, buff);
		}
		else
		{
			return true;
		}

		if (is_backspace == true)
		{
			if (!strcmp(gInterface.Data[eChangePass_NEW].StatValue, ""))
			{
				return true;
			}
			gInterface.Data[eChangePass_NEW].StatValue[strlen(gInterface.Data[eChangePass_NEW].StatValue) - 1] = '\0';
			gInterface.Data[eChangePass_NEW_HIDE].StatValue[strlen(gInterface.Data[eChangePass_NEW_HIDE].StatValue) - 1] = '\0';
		}
		//else if (is_enter == true)
		//{
		//	//gPartySearch.SendPartyRequest(gPartySearch.currentIndex, gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue);
		//	//gPartySearch.party_search_password_switch_state();
		//	return 1;
		//}
		else if (IsDelete == true)
		{
			strcpy_s(gInterface.Data[eChangePass_NEW].StatValue, "");
			strcpy_s(gInterface.Data[eChangePass_NEW_HIDE].StatValue, "");
		}
		else
		{
			if (strlen(gInterface.Data[eChangePass_NEW].StatValue) < 10)
			{
				if (!strcmp(gInterface.Data[eChangePass_NEW].StatValue, ""))
				{
					strcpy_s(gInterface.Data[eChangePass_NEW].StatValue, value);
					strcpy_s(gInterface.Data[eChangePass_NEW_HIDE].StatValue, "*");
				}
				else
				{
					strcat_s(gInterface.Data[eChangePass_NEW].StatValue, value);
					strcat_s(gInterface.Data[eChangePass_NEW_HIDE].StatValue, "*");
				}
			}
		}
	}
	return false;
}

void QUAN_LY_TK::DRAW_WINDOW_CHANGEPASS()
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
	if (!gInterface.Data[eChangePass_Main].OnShow)
	{
		return;
	}

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainW = 200;
	float MainH = 170;
	float CP_StartX = (MAX_WIN_WIDTH / 2) - (MainW / 2)-30;
	float MainCenter = StartX + (MainWidth / 2);
	float ButtonX = MainCenter - (29.0 / 2);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if (gInterface.IsWorkZone(StartX, StartY, StartX + MainWidth, StartY + MainHeight)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gCItemSetOption.ItemTooltipS15(CP_StartX, gInterface.Data[eChangePass_Main].Y + 50, MainW, MainH, 0.0, 0);
	float CP_StartY = gInterface.Data[eChangePass_Main].Y + 50;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(eChangePass_BTCLOSE, CP_StartX+ MainW-35, gInterface.Data[eChangePass_Main].Y + 58);
	if (gInterface.IsWorkZone(eChangePass_BTCLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eChangePass_BTCLOSE, gInterface.Data[eChangePass_BTCLOSE].X, gInterface.Data[eChangePass_BTCLOSE].Y, Color);
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawFormat(eWhite, CP_StartX, gInterface.Data[eChangePass_Main].Y + 70, MainW, 3, "Thay Đổi Mật Khẩu Tài Khoản");
	if (gInterface.Data[eChangePass_Main].FirstLoad == true)
	{
		if (strlen(gInterface.Data[eChangePass_OLD].StatValue) == 0)
			sprintf(gInterface.Data[eChangePass_OLD].StatValue, ""); //NONE

		if (strlen(gInterface.Data[eChangePass_NEW].StatValue) == 0)
			sprintf(gInterface.Data[eChangePass_NEW].StatValue, ""); //NONE
	}
	//=== Pass Cu
	gInterface.DrawGUI(eChangePass_OLD, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_OLD].Width / 2), CP_StartY + 50);
	if (gInterface.Data[eChangePass_OLD].Attribute == 1)
	{
		gInterface.DrawColoredGUI(eChangePass_OLD, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_OLD].Width / 2), CP_StartY + 50, eBlue);
	}
	gInterface.DrawText(eWhite, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_OLD].Width / 2)+10, CP_StartY + 55, 170, 1, "Mật Khẩu (Cũ)");
	gInterface.DrawText(eWhite, (CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_NEW].Width / 2)) + 60, CP_StartY + 55, 100, 3, gInterface.Data[eChangePass_OLD_HIDE].StatValue);
	//=== Pass Moi
	gInterface.DrawGUI(eChangePass_NEW, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_NEW].Width / 2), CP_StartY + 80);

	if (gInterface.Data[eChangePass_NEW].Attribute == 1)
	{
		gInterface.DrawColoredGUI(eChangePass_NEW, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_NEW].Width / 2), CP_StartY + 80, eBlue);
	}

	gInterface.DrawText(eWhite, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_NEW].Width / 2) + 10, CP_StartY + 85, 170, 1, "Mật Khẩu (Mới)");
	gInterface.DrawText(eWhite, (CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_NEW].Width / 2))+60, CP_StartY + 85, 100, 3, gInterface.Data[eChangePass_NEW_HIDE].StatValue);
	gInterface.DrawButton(eChangePass_BTOK, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_BTOK].Width / 2), CP_StartY+ MainH -(50), 0, 0);

	if (gInterface.IsWorkZone(eChangePass_BTOK))
	{
		int ScaleY = 30;
		// ----
		if (gInterface.Data[eChangePass_BTOK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		gInterface.DrawButton(eChangePass_BTOK, CP_StartX + (MainW / 2) - (gInterface.Data[eChangePass_BTOK].Width / 2), CP_StartY + MainH - (50), 0, ScaleY);
	}
	//==============
	if (gInterface.Data[eChangePass_Main].FirstLoad == true)
	{
		gInterface.Data[eChangePass_Main].FirstLoad = false;
	}
}
#endif
