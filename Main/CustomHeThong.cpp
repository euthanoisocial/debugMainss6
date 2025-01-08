#include "stdafx.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
#include "CustomHeThong.h"
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
#include "QuanHam.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_HE_THONG G_BEXO_HE_THONG;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

#define MAX_TRANG_HE_THONG    10  // OK

//-----------------------------------------------------------------------------------------------------------------------------------------------------
BEXO_HE_THONG::BEXO_HE_THONG()
{
	TRANG_HE_THONG = 1;
	//--------------------------------------------------------------
	HIENTHIHE_THONG = false;
	MainWidth = 640;
	MainHeight = 429;
	StartY = 0;
	StartX = 0;
	ClickTick = 0;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_HE_THONG::DRAW_HE_THONG()
{
	DRAW_WINDOW_HE_THONG();
}

void BEXO_HE_THONG::BinObeject()
{
	gInterface.BindObject(EXBEXO_HE_THONG_MAIN, 31461, 640, 419, -1, -1);  // 31461
	gInterface.BindObject(EXBEXO_HE_THONG_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(eHE_THONG1, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eHE_THONG2, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eHE_THONG3, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eHE_THONG4, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eHE_THONG5, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eHE_THONG6, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eHE_THONG7, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eHE_THONG8, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eHE_THONG9, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eHE_THONG10, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eHE_THONG11, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eHE_THONG12, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eHE_THONG13, 0x7A5E, 108, 29, -1, -1);

	gInterface.BindObject(eVIPTAIKHOAN_SEND_01, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eVIPTAIKHOAN_SEND_03, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eVIPTAIKHOAN_SEND_07, 0x7A5E, 108, 29, -1, -1);

	/*gInterface.BindObject(eVIPNHANVAT_SEND_01, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eVIPNHANVAT_SEND_02, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eVIPNHANVAT_SEND_03, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eVIPNHANVAT_SEND_04, 0x7A5E, 108, 29, -1, -1);*/
#if(DANHHIEU_NEW)
	gInterface.BindObject(EXBEXO_DANH_HIEU_MAIN, 0x0899, 560, 279, -1, -1);
	gInterface.BindObject(EXBEXO_DANH_HIEU_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(EXBEXO_DANH_HIEU_NANG_CAP, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eDANH_HIEU2, 0x7903, 25, 40, -1, -1);
	gInterface.BindObject(eDANH_HIEU1, 0x7904, 25, 40, -1, -1);

	gInterface.BindObject(EXBEXO_QUAN_HAM_MAIN, 0x0899, 560, 279, -1, -1);
	gInterface.BindObject(EXBEXO_QUAN_HAM_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(EXBEXO_QUAN_HAM_NANG_CAP, 0x7A5E, 108, 29, -1, -1);
	gInterface.BindObject(eQUAN_HAM2, 0x7903, 25, 40, -1, -1);
	gInterface.BindObject(eQUAN_HAM1, 0x7904, 25, 40, -1, -1);
#endif

	gInterface.BindObject(eDANHHIEU2, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eDANHHIEU3, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eDANHHIEU4, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eDANHHIEU5, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eDANHHIEU6, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eDANHHIEU7, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eDANHHIEU8, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eDANHHIEU9, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eDANHHIEU10, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eDANHHIEU11, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eDANHHIEU12, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eDANHHIEU13, 10099, 30, 20, -1, -1);

	/*gInterface.BindObject(eQUANHAM9, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eQUANHAM10, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eQUANHAM11, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eQUANHAM12, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eQUANHAM13, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eQUANHAM14, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eQUANHAM15, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eQUANHAM16, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eQUANHAM17, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eQUANHAM18, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eQUANHAM19, 10099, 30, 20, -1, -1);
	gInterface.BindObject(eQUANHAM20, 10099, 30, 20, -1, -1);*/
	
	//gInterface.BindObject(eTULUYEN, 0x7A5E, 108, 29, -1, -1);

#if(DOIMK)
	//===CHange Pass
	gInterface.BindObject(eChangePass_Main, 31461, 640, 419, -1, -1);  // 31461
	gInterface.BindObject(eChangePass_BTCLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(eChangePass_OLD, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eChangePass_NEW, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eChangePass_BTOK, 0x7A5B, 54, 30, -1, -1);
#endif

	gInterface.BindObject(eNGUHANH, 0x7A5E, 108, 29, -1, -1);

}
void BEXO_HE_THONG::LoadImages()
{
	pLoadImage("Custom\\DanhHieu\\Main.tga", 0x0899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\DanhHieu\\Successful.tga", 0x0898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\DanhHieu\\Progress.tga", 0x0897, 0x2601, 0x2901, 1, 0);

	/*pLoadImage("Custom\\RankTitle4\\vip1.tga", 32891, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankTitle4\\vip2.tga", 32893, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankTitle4\\vip3.tga", 32895, 0x2601, 0x2900, 1, 0);*/
	/*pLoadImage("Custom\\RankTitle4\\vipbac.tga", 10100, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankTitle4\\vipdong.tga", 10101, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankTitle4\\vipvang.tga", 10102, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankTitle4\\vipkimcuong.tga", 10103, 0x2601, 0x2900, 1, 0);*/

	pLoadImage("Custom\\DanhHieu\\01.tga", 10104, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\02.tga", 10105, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\03.tga", 10106, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\04.tga", 10107, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\05.tga", 10108, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\06.tga", 10109, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\07.tga", 10110, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\08.tga", 10111, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\09.tga", 10112, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\10.tga", 10113, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\11.tga", 10114, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\12.tga", 10115, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\13.tga", 10116, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\14.tga", 10117, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\15.tga", 10118, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\16.tga", 10119, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\17.tga", 10120, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\18.tga", 10121, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\19.tga", 10122, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\DanhHieu\\20.tga", 10123, 0x2601, 0x2900, 1, 0);


	pLoadImage("Custom\\RankGuild\\lanhdaotranchien.tga", 10124, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankGuild\\phoguild.tga", 10125, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RankGuild\\chuguild.tga", 10126, 0x2601, 0x2900, 1, 0);
	//pLoadImage("Custom\\RankTitle2\\QuanHam_12.tga", 10119, 0x2601, 0x2900, 1, 0);
	//pLoadImage("Custom\\RankTitle2\\QuanHam_13.tga", 10120, 0x2601, 0x2900, 1, 0);
	//pLoadImage("Custom\\RankTitle2\\QuanHam_14.tga", 10121, 0x2601, 0x2900, 1, 0);
	//pLoadImage("Custom\\RankTitle2\\QuanHam_15.tga", 10122, 0x2601, 0x2900, 1, 0);
	//pLoadImage("Custom\\RankTitle2\\QuanHam_16.tga", 10123, 0x2601, 0x2900, 1, 0);
	//pLoadImage("Custom\\RankTitle2\\QuanHam_17.tga", 10124, 0x2601, 0x2900, 1, 0);
	//pLoadImage("Custom\\RankTitle2\\QuanHam_18.tga", 10125, 0x2601, 0x2900, 1, 0);
	//pLoadImage("Custom\\RankTitle2\\QuanHam_19.tga", 10126, 0x2601, 0x2900, 1, 0);
	//pLoadImage("Custom\\RankTitle2\\QuanHam_20.tga", 10127, 0x2601, 0x2900, 1, 0);

	pLoadImage("Custom\\Bmd\\vip1.tga", 32891, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Bmd\\vip2.tga", 32893, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Bmd\\vip3.tga", 32895, 0x2601, 0x2900, 1, 0);

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_HE_THONG::BEXO_CLICK_TRANG_HE_THONG(DWORD ClickMouse)
{
	if (!gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow)
	{
		return;
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);

	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eHE_THONG1))
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
		if (TRANG_HE_THONG = 1)

			ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eHE_THONG2))

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
		if (TRANG_HE_THONG = 2)

			ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eHE_THONG3))

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
		if (TRANG_HE_THONG = 3)

			ClickTick = GetTickCount();

		#if(DANHHIEU_NEW)
		G_BEXO_DANH_HIEU.OPEN_WINDOW_DANH_HIEU();
#endif
		G_BEXO_HE_THONG.CLOSE_WINDOW_HE_THONG();


	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eHE_THONG4))

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
		if (TRANG_HE_THONG = 4)

			ClickTick = GetTickCount();

		#if(DANHHIEU_NEW)
			G_BEXO_QUAN_HAM.OPEN_WINDOW_QUAN_HAM();
#endif

			G_BEXO_HE_THONG.CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eHE_THONG5))

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
		if (TRANG_HE_THONG = 5)

			ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eHE_THONG6))

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
		if (TRANG_HE_THONG = 6)

			ClickTick = GetTickCount();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eHE_THONG7))

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
		if (TRANG_HE_THONG = 7)

			ClickTick = GetTickCount();
		this->BUY_NGU_HANH(2);
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eHE_THONG8))

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
		if (TRANG_HE_THONG = 8)

			ClickTick = GetTickCount();
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BEXO_HE_THONG::DRAW_WINDOW_HE_THONG()
{

	if (gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(MoveList)
		|| gInterface.CheckWindow(Trade)
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
	if (!gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow)
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
	pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//-----------------------------------------------------------------------------------------------------------------------------------------------------

	RenderBitmap(631177,StartX + 100, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 50, 650, 470, 0, 0, 1, 1, 1, 1, 0.0);

	//0x7A58

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 90, 210, 1, Config.TextVN_DanhHieu[0]);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if( gProtect.m_MainInfo.Disableviptaikhoan == 0 )
	{
	gInterface.DrawGUI(eHE_THONG1, StartX + 115, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 90);
	}
	if( gProtect.m_MainInfo.Disablevipnhanvat == 0 )
	{
		gInterface.DrawGUI(eHE_THONG2, StartX + 115, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 110);
	}
	if( gProtect.m_MainInfo.Disabledanhhieu == 0 )
	{
	gInterface.DrawGUI(eHE_THONG3, StartX + 115, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 120);
	}
	if( gProtect.m_MainInfo.Disablequanham == 0 )
	{
	gInterface.DrawGUI(eHE_THONG4, StartX + 115, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 150);
	}
	if( gProtect.m_MainInfo.Disabletuluyen == 0 )
	{
		gInterface.DrawGUI(eHE_THONG5, StartX + 110, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 200);
	}
	if( gProtect.m_MainInfo.Disablekinhmach == 0 )
	{
		gInterface.DrawGUI(eHE_THONG6, StartX + 110, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 230);
	}
	if( gProtect.m_MainInfo.Disablenguhanh == 0 )
	{
	gInterface.DrawGUI(eHE_THONG7, StartX + 115, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 180);
	}
	if( gProtect.m_MainInfo.Disablethuankhiet == 0 )
	{
		gInterface.DrawGUI(eHE_THONG8, StartX + 110, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 290);
	}

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if( gProtect.m_MainInfo.Disableviptaikhoan == 0 )
	{
	if (gInterface.IsWorkZone(eHE_THONG1))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eHE_THONG1, gInterface.Data[eHE_THONG1].X, gInterface.Data[eHE_THONG1].Y, Color);
	}
	}
	if( gProtect.m_MainInfo.Disablevipnhanvat == 0 )
	{
	if (gInterface.IsWorkZone(eHE_THONG2))
	{
		DWORD Color = eGray150;

		gInterface.DrawColoredGUI(eHE_THONG2, gInterface.Data[eHE_THONG2].X, gInterface.Data[eHE_THONG2].Y, Color);
	}
	}
	if( gProtect.m_MainInfo.Disabledanhhieu == 0 )
	{
	if (gInterface.IsWorkZone(eHE_THONG3))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eHE_THONG3, gInterface.Data[eHE_THONG3].X, gInterface.Data[eHE_THONG3].Y, Color);
	}
	}
	if( gProtect.m_MainInfo.Disablequanham == 0 )
	{
	if (gInterface.IsWorkZone(eHE_THONG4))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eHE_THONG4, gInterface.Data[eHE_THONG4].X, gInterface.Data[eHE_THONG4].Y, Color);
	}
	}
	if( gProtect.m_MainInfo.Disabletuluyen == 0 )
	{
	if (gInterface.IsWorkZone(eHE_THONG5))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eHE_THONG5, gInterface.Data[eHE_THONG5].X, gInterface.Data[eHE_THONG5].Y, Color);
	}
	}
	if( gProtect.m_MainInfo.Disablekinhmach == 0 )
	{
	if (gInterface.IsWorkZone(eHE_THONG6))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eHE_THONG6, gInterface.Data[eHE_THONG6].X, gInterface.Data[eHE_THONG6].Y, Color);
	}
	}
	if( gProtect.m_MainInfo.Disablenguhanh == 0 )
	{
	if (gInterface.IsWorkZone(eHE_THONG7))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eHE_THONG7, gInterface.Data[eHE_THONG7].X, gInterface.Data[eHE_THONG7].Y, Color);
	}
	}
	if( gProtect.m_MainInfo.Disablethuankhiet == 0 )
	{
	if (gInterface.IsWorkZone(eHE_THONG8))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eHE_THONG8, gInterface.Data[eHE_THONG8].X, gInterface.Data[eHE_THONG8].Y, Color);
	}
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	if( gProtect.m_MainInfo.Disableviptaikhoan == 0 )
	{
	gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 100, 210, 1, gOther.TextVN[24]);
	}
	if( gProtect.m_MainInfo.Disablevipnhanvat == 0 )
	{
	 gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 120, 210, 1, gOther.TextVN[25]);
	}
	if( gProtect.m_MainInfo.Disabledanhhieu == 0 )
	{
	gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 130, 210, 1, gOther.TextVN[26]);
	}
	if( gProtect.m_MainInfo.Disablequanham == 0 )
	{
	gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 160, 210, 1, gOther.TextVN[27]);
	}
	if( gProtect.m_MainInfo.Disabletuluyen == 0 )
	{
	 gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 210, 210, 1, gOther.TextVN[28]);
	}
	if( gProtect.m_MainInfo.Disablekinhmach == 0 )
	{
	 gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 240, 210, 1, gOther.TextVN[29]);
	}
	if( gProtect.m_MainInfo.Disablenguhanh == 0 )
	{
	gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 190, 210, 1, gOther.TextVN[30]);
	}
	if( gProtect.m_MainInfo.Disablethuankhiet == 0 )
	{
	 gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 300, 210, 1, gOther.TextVN[31]);
	}
	
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	gInterface.DrawGUI(EXBEXO_HE_THONG_CLOSE, StartX + 500, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 48);
	if (gInterface.IsWorkZone(EXBEXO_HE_THONG_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(EXBEXO_HE_THONG_CLOSE, gInterface.Data[EXBEXO_HE_THONG_CLOSE].X, gInterface.Data[EXBEXO_HE_THONG_CLOSE].Y, Color);
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
	switch (TRANG_HE_THONG)
	{
if( gProtect.m_MainInfo.Disableviptaikhoan == 0 )
{
	case 1:
		//--------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eYellow, XVIPTAIKHOAN + 50, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 78, 210, 1, gOther.TextVN[32], gObjUser.lpPlayer->Name); // "Hệ thống cửa hàng VIP Tài Khoản, chào %s!"
		//--------------------------------------------------------------------------------------------
		//gInterface.DrawFormat(eBlue, XVIPTAIKHOAN + 80, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 68, 210, 1, gOther.TextVN[34]); // "Thông Tin Vip Tài Khoản"
		//--------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 75, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 98, 210, 1, gOther.TextVN[39]);  // Tất cả tỷ lệ đập đồ tăng + 20%%!"
		gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 70, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 118, 210, 1, gOther.TextVN[40]); // Exp được cộng tính cho cả cấp Master!"
		gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 80, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 138, 210, 1, gOther.TextVN[41]); // Không có tác dụng khi party!"
		//--------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 10, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 175, 300, 1, gOther.TextVN[42]); // "Name                   Exp                   Drop                  Time"
		gInterface.DrawFormat(eYellow, XVIPTAIKHOAN + 10, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 195, 300, 1, gOther.TextVN[43]); // "Vip 1 Ngày          +30%%              +10%%               1 Ngày"
		gInterface.DrawFormat(eYellow, XVIPTAIKHOAN + 10, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 215, 300, 1, gOther.TextVN[44]); // "Vip 3 Ngày          +30%%              +10%%               3 Ngày"
		gInterface.DrawFormat(eYellow, XVIPTAIKHOAN + 10, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 235, 300, 1, gOther.TextVN[45]); // "Vip 7 Ngày          +30%%              +10%%               7 Ngày"
		//--------------------------------------------------------------------------------------------
		pDrawGUI(71520, XVIPTAIKHOAN + 23, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 160, 200, 1); //-- Divisor
		pDrawGUI(71520, XVIPTAIKHOAN + 23, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 255, 200, 1); //-- Divisor
		//--------------------------------------------------------------------------------------------
		gInterface.DrawGUI(eVIPTAIKHOAN_SEND_01, XVIPTAIKHOAN + 70, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 260); // Cột 1
		gInterface.DrawGUI(eVIPTAIKHOAN_SEND_03, XVIPTAIKHOAN + 70, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 288); // Cột 2
		gInterface.DrawGUI(eVIPTAIKHOAN_SEND_07, XVIPTAIKHOAN + 70, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 316); // Cột 2
		//--------------------------------------------------------------------------------------------
		gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 110, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 265, 210, 1, gOther.TextVN[36]); // "Vip Đồng"
		gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 110, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 293, 210, 1, gOther.TextVN[37]); // "Vip Bạc"
		gInterface.DrawFormat(eWhite, XVIPTAIKHOAN + 110, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 321, 210, 1, gOther.TextVN[38]); // "Vip Vàng"
		//--------------------------------------------------------------------------------------------
		//==>>
		if (gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_01))
		{
			DWORD Color = eGray150;

			gInterface.DrawColoredGUI(eVIPTAIKHOAN_SEND_01, gInterface.Data[eVIPTAIKHOAN_SEND_01].X, gInterface.Data[eVIPTAIKHOAN_SEND_01].Y, Color);
		}
		if (gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_03))
		{
			DWORD Color = eGray150;

			gInterface.DrawColoredGUI(eVIPTAIKHOAN_SEND_03, gInterface.Data[eVIPTAIKHOAN_SEND_03].X, gInterface.Data[eVIPTAIKHOAN_SEND_03].Y, Color);
		}
		if (gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_07))
		{
			DWORD Color = eGray150;

			gInterface.DrawColoredGUI(eVIPTAIKHOAN_SEND_07, gInterface.Data[eVIPTAIKHOAN_SEND_07].X, gInterface.Data[eVIPTAIKHOAN_SEND_07].Y, Color);
		}
		break;

	   case 2:
		break;
}
	case 3:
		break;
	case 4:
		break;

	case 5:

		break;
		

	case 6:

		break;
	case 7:
#if(NGU_HANH_NEW)

		gInterface.DrawFormat(eGold, XNGUHANH + 90, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 75, 70, 3, "HỆ THỐNG NÂNG CẤP RỒNG");

		gInterface.DrawFormat(eGold, XNGUHANH + 85, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 90, 70, 3, gOther.TextVN[100]);
		//
		gInterface.DrawFormat(eWhite, XNGUHANH + 145, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 90, 70, 1, "%d/5", m_rNguHanh);
		//
		gInterface.DrawFormat(eYellow, XNGUHANH + 77, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 100, 150, 1, "Tổng Cộng 5 Cấp Độ Rồng");

		gInterface.DrawFormat(eYellow, XNGUHANH + 77, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 110, 150, 1, "VKR +13 Kích Hoạt 3 Rồng");

		gInterface.DrawFormat(eYellow, XNGUHANH + 77, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 120, 150, 1, "VKR +14 Kích Hoạt Rồng Xanh Nhạt");

		gInterface.DrawFormat(eYellow, XNGUHANH + 77, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 130, 150, 1, "VKR +15 Kích Hoạt Rồng Vàng");

		gInterface.DrawFormat(eYellow, XNGUHANH + 77, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 140, 150, 1, "Không Thể Kích Hoạt Vượt Cấp");

		gInterface.DrawFormat(eYellow, XNGUHANH + 77, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 150, 150, 1, "Lưu Ý: VKR Cấp Nào Kích Hoạt Cấp Đó");

		//======

		gCItemSetOption.ItemTooltipS15(XNGUHANH-10, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 90, 85, 100, 0.0, 0);

		gInterface.DrawFormat(eYellow, XNGUHANH +15, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 95, 150, 1, gOther.TextVN[121]);

		gInterface.DrawFormat(eExcellent, XNGUHANH +10, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 140, 150, 1, "ĐIỀU KIỆN KÍCH HOẠT : ");

		gInterface.DrawFormat(eShinyGreen, XNGUHANH +5, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 155, 150, 1, "-> VŨ KHÍ RỒNG 1,2,3(+13)");


		RenderBitmap(500004, XNGUHANH, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 105, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);

		pDrawGUI(0x9992, XNGUHANH + 50, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 113, 15, 15);

		if (this->m_rNguHanh >= 1)
		{
			pDrawGUI(0x9991, XNGUHANH + 50, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 113, 15, 15);
		gInterface.DrawFormat(eBlowPink, XNGUHANH +10, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 170, 150, 1, "Kích Hoạt Thành Công");

		gInterface.DrawFormat(eBlowPink, XNGUHANH +5, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 180, 150, 1, "Xuất Hiện Rồng Trắng");
		}
		else
		{
		gInterface.DrawFormat(eGray100, XNGUHANH +15, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 170, 150, 1, "Chưa Kích Hoạt");

		}

		//======

		gCItemSetOption.ItemTooltipS15(XNGUHANH-10, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 245, 85, 100, 0.0, 0);

		gInterface.DrawFormat(eYellow, XNGUHANH + 15, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 250, 150, 1, gOther.TextVN[122]);

		gInterface.DrawFormat(eExcellent, XNGUHANH +10, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 295, 150, 1, "ĐIỀU KIỆN KÍCH HOẠT : ");

		gInterface.DrawFormat(eShinyGreen, XNGUHANH +5, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 310, 150, 1, "-> VŨ KHÍ RỒNG 1,2,3(+13)");

		RenderBitmap(500004, XNGUHANH, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 260, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);

		pDrawGUI(0x9992, XNGUHANH + 50, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 268, 15, 15);

		if (this->m_rNguHanh >= 2)
		{
			pDrawGUI(0x9991, XNGUHANH + 50, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 268, 15, 15);
		gInterface.DrawFormat(eBlowPink, XNGUHANH +10, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 325, 150, 1, "Kích Hoạt Thành Công");

		gInterface.DrawFormat(eBlowPink, XNGUHANH +5, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 335, 150, 1, "Xuất Hiện Rồng Xanh Đậm");
		}
		else
		{
		gInterface.DrawFormat(eGray100, XNGUHANH +15, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 325, 150, 1, "Chưa Kích Hoạt");

		}

		//===

		gCItemSetOption.ItemTooltipS15(XNGUHANH + 180, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 90, 85, 100, 0.0, 0);

		gInterface.DrawFormat(eYellow, XNGUHANH + 200, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 95, 150, 1, gOther.TextVN[123]);

		gInterface.DrawFormat(eExcellent, XNGUHANH +195, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 140, 150, 1, "ĐIỀU KIỆN KÍCH HOẠT : ");

		gInterface.DrawFormat(eShinyGreen, XNGUHANH +190, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 155, 150, 1, "-> VŨ KHÍ RỒNG 1,2,3(+13)");

		RenderBitmap(500004, XNGUHANH + 195, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 105, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);

		pDrawGUI(0x9992, XNGUHANH + 245, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 113, 15, 15);

		if (this->m_rNguHanh >= 3)
		{
			pDrawGUI(0x9991, XNGUHANH + 245, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 113, 15, 15);
		gInterface.DrawFormat(eBlowPink, XNGUHANH +195, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 170, 150, 1, "Kích Hoạt Thành Công");

		gInterface.DrawFormat(eBlowPink, XNGUHANH +190, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 180, 150, 1, "Xuất Hiện Rồng Đỏ");
		}
		else
		{
		gInterface.DrawFormat(eGray100, XNGUHANH +200, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 170, 150, 1, "Chưa Kích Hoạt");

		}

		//==

		gCItemSetOption.ItemTooltipS15(XNGUHANH + 180, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 245, 85, 100, 0.0, 0);

		gInterface.DrawFormat(eYellow, XNGUHANH + 200, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 250, 150, 1, gOther.TextVN[124]);

		gInterface.DrawFormat(eExcellent, XNGUHANH +195, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 295, 150, 1, "ĐIỀU KIỆN KÍCH HOẠT : ");

		gInterface.DrawFormat(eShinyGreen, XNGUHANH +190, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 310, 150, 1, "-> VŨ KHÍ RỒNG 1,2,3(+14)");

		RenderBitmap(500004, XNGUHANH +195, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 260, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);

		pDrawGUI(0x9992, XNGUHANH + 245, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 268, 15, 15);

		if (this->m_rNguHanh >= 4)
		{
			pDrawGUI(0x9991, XNGUHANH + 245, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 268, 15, 15);
		gInterface.DrawFormat(eBlowPink, XNGUHANH +195, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 325, 150, 1, "Kích Hoạt Thành Công");

		gInterface.DrawFormat(eBlowPink, XNGUHANH +190, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 335, 150, 1, "Xuất Hiện Rồng Xanh Nhạt");
		}
		else
		{
		gInterface.DrawFormat(eGray100, XNGUHANH +200, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 325, 150, 1, "Chưa Kích Hoạt");

		}

		//==

		gCItemSetOption.ItemTooltipS15(XNGUHANH+85, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 160, 85, 100, 0.0, 0);

		gInterface.DrawFormat(eYellow, XNGUHANH +110, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 165, 150, 1, gOther.TextVN[125]);

		gInterface.DrawFormat(eExcellent, XNGUHANH +105, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 205, 150, 1, "ĐIỀU KIỆN KÍCH HOẠT : ");

		gInterface.DrawFormat(eShinyGreen, XNGUHANH +100, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 220, 150, 1, "-> VŨ KHÍ RỒNG 1,2,3(+15)");

		RenderBitmap(500004, XNGUHANH + 95, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 170, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);

		pDrawGUI(0x9992, XNGUHANH + 145, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 175, 15, 15);

		if (this->m_rNguHanh >= 5)
		{
			pDrawGUI(0x9991, XNGUHANH + 145, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 175, 15, 15);
		gInterface.DrawFormat(eBlowPink, XNGUHANH +105, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 235, 150, 1, "Kích Hoạt Thành Công");

		gInterface.DrawFormat(eBlowPink, XNGUHANH +100, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 245, 150, 1, "Xuất Hiện Rồng Vàng");
		}
		else
		{
		gInterface.DrawFormat(eGray100, XNGUHANH +110, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 235, 150, 1, "Chưa Kích Hoạt");

		}

		gInterface.DrawGUI(eNGUHANH, XNGUHANH + 75, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 290);
		gInterface.DrawFormat(eGold, XNGUHANH + 45, gInterface.Data[EXBEXO_HE_THONG_MAIN].Y + 298, 160, 3, "KÍCH HOẠT");

		if (gInterface.IsWorkZone(eNGUHANH))
		{
			DWORD Color = eGray150;

			gInterface.DrawColoredGUI(eNGUHANH, gInterface.Data[eNGUHANH].X, gInterface.Data[eNGUHANH].Y, Color);
		}
		
#endif

    break;

	case 8:

		break;

	default:
		break;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_HE_THONG::MAIN_HE_THONG(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	this->CLOSE_HE_THONG(Event);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
#if(VIP_TAI_KHOAN_NEW)
	// TRANG 1
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_01) && this->TRANG_HE_THONG == 1)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPTAIKHOAN_SEND_01].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPTAIKHOAN_SEND_01].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPTAIKHOAN_SEND_01].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPTAIKHOAN_SEND_01].EventTick = GetTickCount();
		gCustomBuyVip.BuyStatus(1);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_03) && this->TRANG_HE_THONG == 1)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPTAIKHOAN_SEND_03].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPTAIKHOAN_SEND_03].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPTAIKHOAN_SEND_03].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPTAIKHOAN_SEND_03].EventTick = GetTickCount();
		gCustomBuyVip.BuyStatus(2);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eVIPTAIKHOAN_SEND_07) && this->TRANG_HE_THONG == 1)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPTAIKHOAN_SEND_07].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPTAIKHOAN_SEND_07].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPTAIKHOAN_SEND_07].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPTAIKHOAN_SEND_07].EventTick = GetTickCount();
		gCustomBuyVip.BuyStatus(3);
		this->CLOSE_WINDOW_HE_THONG();
	}
#endif
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
#if(THUE_VIP_NEW)
	// TRANG 2
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eVIPNHANVAT_SEND_01) && this->TRANG_HE_THONG == 2)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPNHANVAT_SEND_01].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPNHANVAT_SEND_01].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPNHANVAT_SEND_01].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPNHANVAT_SEND_01].EventTick = GetTickCount();
		this->BUY_THUE_VIP(1);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eVIPNHANVAT_SEND_02) && this->TRANG_HE_THONG == 2)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPNHANVAT_SEND_02].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPNHANVAT_SEND_02].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPNHANVAT_SEND_02].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPNHANVAT_SEND_02].EventTick = GetTickCount();
		this->BUY_THUE_VIP(2);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eVIPNHANVAT_SEND_03) && this->TRANG_HE_THONG == 2)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPNHANVAT_SEND_03].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPNHANVAT_SEND_03].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPNHANVAT_SEND_03].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPNHANVAT_SEND_03].EventTick = GetTickCount();
		this->BUY_THUE_VIP(3);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eVIPNHANVAT_SEND_04) && this->TRANG_HE_THONG == 2)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eVIPNHANVAT_SEND_04].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eVIPNHANVAT_SEND_04].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eVIPNHANVAT_SEND_04].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eVIPNHANVAT_SEND_04].EventTick = GetTickCount();
		this->BUY_THUE_VIP(4);
		this->CLOSE_WINDOW_HE_THONG();
	}
#endif
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
#if(QUAN_HAM_NEW)
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eQUANHAM9) && this->TRANG_HE_THONG == 4)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUANHAM9].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUANHAM9].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUANHAM9].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUANHAM9].EventTick = GetTickCount();
		this->BUY_QUAN_HAM(9);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eQUANHAM10) && this->TRANG_HE_THONG == 4)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUANHAM10].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUANHAM10].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUANHAM10].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUANHAM10].EventTick = GetTickCount();
		this->BUY_QUAN_HAM(10);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eQUANHAM11) && this->TRANG_HE_THONG == 4)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUANHAM11].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUANHAM11].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUANHAM11].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUANHAM11].EventTick = GetTickCount();
		this->BUY_QUAN_HAM(11);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eQUANHAM12) && this->TRANG_HE_THONG == 4)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUANHAM12].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUANHAM12].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUANHAM12].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUANHAM12].EventTick = GetTickCount();
		this->BUY_QUAN_HAM(12);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eQUANHAM13) && this->TRANG_HE_THONG == 4)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUANHAM13].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUANHAM13].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUANHAM13].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUANHAM13].EventTick = GetTickCount();
		this->BUY_QUAN_HAM(13);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eQUANHAM14) && this->TRANG_HE_THONG == 4)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUANHAM14].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUANHAM14].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUANHAM14].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUANHAM14].EventTick = GetTickCount();
		this->BUY_QUAN_HAM(14);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eQUANHAM15) && this->TRANG_HE_THONG == 4)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUANHAM15].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUANHAM15].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUANHAM15].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUANHAM15].EventTick = GetTickCount();
		this->BUY_QUAN_HAM(15);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eQUANHAM16) && this->TRANG_HE_THONG == 4)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUANHAM16].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUANHAM16].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUANHAM16].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUANHAM16].EventTick = GetTickCount();
		this->BUY_QUAN_HAM(16);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eQUANHAM17) && this->TRANG_HE_THONG == 4)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUANHAM17].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUANHAM17].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUANHAM17].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUANHAM17].EventTick = GetTickCount();
		this->BUY_QUAN_HAM(17);
		this->CLOSE_WINDOW_HE_THONG();
	}	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eQUANHAM18) && this->TRANG_HE_THONG == 4)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUANHAM18].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUANHAM18].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUANHAM18].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUANHAM18].EventTick = GetTickCount();
		this->BUY_QUAN_HAM(18);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eQUANHAM19) && this->TRANG_HE_THONG == 4)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUANHAM19].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUANHAM19].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUANHAM19].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUANHAM19].EventTick = GetTickCount();
		this->BUY_QUAN_HAM(19);
		this->CLOSE_WINDOW_HE_THONG();
	}
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eQUANHAM20) && this->TRANG_HE_THONG == 4)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eQUANHAM20].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eQUANHAM20].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eQUANHAM20].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eQUANHAM20].EventTick = GetTickCount();
		this->BUY_QUAN_HAM(20);
		this->CLOSE_WINDOW_HE_THONG();
	}
#endif
	//-----------------------------------------------------------------------------------------------------------------------------------------------------

#if(NGU_HANH_NEW)
	if (gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow && gInterface.IsWorkZone(eNGUHANH) && this->TRANG_HE_THONG == 7)
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eNGUHANH].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eNGUHANH].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eNGUHANH].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eNGUHANH].EventTick = GetTickCount();
		this->BUY_NGU_HANH(1);
	}
#endif
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
bool BEXO_HE_THONG::CLOSE_HE_THONG(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[EXBEXO_HE_THONG_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow || !gInterface.IsWorkZone(EXBEXO_HE_THONG_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[EXBEXO_HE_THONG_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[EXBEXO_HE_THONG_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[EXBEXO_HE_THONG_CLOSE].EventTick = GetTickCount();
	G_BEXO_HE_THONG.CLOSE_WINDOW_HE_THONG();
	// ----
	return false;
}
//---------------------------------------------------------
void BEXO_HE_THONG::BUY_THUE_VIP(int Number)
{
	BUY_THUE_VIP_REQ pMsg;
	pMsg.h.set(0xFC, 0x02, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
void BEXO_HE_THONG::BUY_QUAN_HAM(int Number)
{
	BUY_QUAN_HAM_REQ pMsg;
	pMsg.h.set(0xFC, 0x04, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}

void BEXO_HE_THONG::BUY_NGU_HANH(int Number)
{
	BUY_NGU_HANH_REQ pMsg;
	pMsg.h.set(0xFC, 0x07, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
//---------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void BEXO_HE_THONG::GetInfoNguHanh(PMSG_NGUHANH_UPD * aRecv)
{
	//-----------------------------
	this->m_rNguHanh = aRecv->rNguHanh;
	this->m_rRankTitle3 = aRecv->rTuLuyen;
	//-----------------------------
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------