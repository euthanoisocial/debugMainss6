#include "stdafx.h"
#include "resource.h"
#include "Controller.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protocol.h"
#include "Import.h"
#include "Interface.h"
#include "Protect.h"
#include "TMemory.h"
#include "CSCharacterS13.h"
#include "CNewUIMacro.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "Ruud.h"
#include "Central.h"
#include "GrandResetSystem.h"
#include "ResetSystem.h"
#include "NewInterface.h"
#include "CustomLuckySpin.h"
#include "CustomHeThong.h"
#include "ShopSearch.h"
#include "MultiCharacter.h"
#include "PartySearch.h"
#include "PartySearchSettings.h"
#include "MocNap.h"
#include "QuaEvent.h"
#include "QuaEvent1.h"
#include "QuaEvent2.h"
#include "DanhHieu.h"
#include "QuanHam.h"
#include "RegisterMain.h"
#include "QuanLyTaiKhoan.h"
#include "CustomJewelBank.h"
#include "NewsBoard.h"
#include "AutoLoginWin.h"
//tue add
#include "CustomBauCua.h"
// -----
//tue add thue flag
#include "ThueFlag.h" 
// ----------------------------------------------------------------------------------------------

Controller	gController;

HHOOK HookKB;
HHOOK HookMS;
char AutoOn[1024];
char AutoOff[1024];


// ----------------------------------------------------------------------------------------------
void __declspec(naked) iconHook()
{
	static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON1));
	static DWORD dwJmp = 0x004D0E3C;

	_asm
	{
		MOV EAX, dwIcon
		JMP dwJmp
	}
}

LRESULT Controller::Mouse(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
	}
	// ----
	MOUSEHOOKSTRUCTEX * Mouse	= (MOUSEHOOKSTRUCTEX*)lParam;

	switch(wParam)
	{
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
		{
			//tue add
#if BAUCUA
		gCUSTOM_BAUCUA.EventStatsAddWindow(wParam);
#endif
			//----	
	

			if (pCursorX <= 55 && pCursorY <=25) {
				return 1;
			}
			if (GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
			{
				gController.ProcInterface(wParam);
				if (gNewInterface.EventAllWindow(wParam, Mouse) == true)
				{
					return 1;
				}
			}
			//===========================================//
#if(DANGKYTK)
			gRegisterMain.ButtonsController(wParam);//add
#endif
			gNewsBoard.EventNewsWindow_Main(wParam);
			gNewsBoard.EventNewsWindow_Close(wParam);

#if(MOCNAP == 1)
				G_BEXO_MOCNAP.MAIN_MOCNAP(wParam);
#endif
#if(QUAEVENT == 1)
				G_BEXO_QUATOP1.MAIN_QUATOP1(wParam);
				G_BEXO_QUATOP2.MAIN_QUATOP2(wParam);
				G_BEXO_QUATOP3.MAIN_QUATOP3(wParam);
#endif
#if(MENU_NEW)
			gInterface.EventMenuWindow(wParam);
#endif
#if(VONGQUAY_NEW)
			gLuckySpin.EventWindow_Main(wParam);
#endif
#if(OFFLINE_MODE_NEW)
			gInterface.EventOffExpWindow_Main(wParam);
#endif
#if(OANTUTY)
				gInterface.EventRPS_Main(wParam);
#endif
				
				gInterface.EventTiecRuouWindow_Main(wParam);
                gInterface.EventMoiRuouWindow_Main(wParam);
				
			    G_BEXO_HE_THONG.BEXO_CLICK_TRANG_HE_THONG(wParam);
			    G_BEXO_HE_THONG.MAIN_HE_THONG(wParam);
		        G_QUAN_LY_TK.CLICK_TRANG_QUAN_LY(wParam);
		        G_QUAN_LY_TK.MAIN_QUAN_LY(wParam);

				gCustomJewelBank.CommandNext(wParam);
				gCustomJewelBank.CommandPrev(wParam);
				gCustomJewelBank.EventJewelBankWindow_Close(wParam);
				gCustomJewelBank.EventJewelBankWithDraw(wParam);

#if(PARTYSEARCH==1)
						
				gPartySearch.EventPartySearchWindow_All(wParam);
				gPartySearch.EventPartySettingsWindow_Main(wParam);
				gPartySearch.event_party_search_password_window(wParam);
				gPartySearch.ClickRefresh(wParam);
				gPartySearch.ClickReSetting(wParam);
#endif
#if(DANHHIEU_NEW)
			    G_BEXO_DANH_HIEU.BEXO_CLICK_TRANG_DANH_HIEU(wParam);
			    G_BEXO_DANH_HIEU.MAIN_DANH_HIEU(wParam);
			    G_BEXO_QUAN_HAM.BEXO_CLICK_TRANG_QUAN_HAM(wParam);
			    G_BEXO_QUAN_HAM.MAIN_QUAN_HAM(wParam);
#endif

#if(CHARACTER_NEW)
			gInterface.EventCharacterWindow_XoaHomDo(wParam);
			gInterface.EventCharacterWindow_TinhNang(wParam);
			//gInterface.EventCharacterWindow_RingPedan(wParam);
#endif
			gInterface.EventXoaHomDoWinDow(wParam);
			gInterface.EventTinhNangWinDow(wParam);

#if (SACHTHUOCTINH_NEW)
			gInterface.EventSachThuocTinhInterface(wParam);
			gInterface.EventSachThuocTinh(wParam);
#endif
#if (RINGPEDAN_NEW)
			gInterface.EventRingPedanInterface(wParam);
#endif

			gInterface.EventLeoThap_All(wParam);
			gInterface.EventLeoThap_Close(wParam);
			

#if _NEW_PARTY_SYSTEM_ == TRUE
			g_Party.MouseController(wParam);
			g_Party.MouseControllerD(wParam);
			g_Party.MouseControllerPage(wParam);
			g_Party.MouseControllerLeader(wParam);
#endif
			//===========================================//
			gCustomRanking.EventRankingNext(wParam);
			gCustomRanking.EventRankingBack(wParam);
			gCustomRanking.EventRankingWindow_Close(wParam);
			//===========================================//
			gCustomEventTime.EventEventTimeWindow_Close(wParam);
			gCustomEventTime.EventNext(wParam);
			gCustomEventTime.EventPrev(wParam);
			gInterface.EventDrawMenu_Open(wParam);
			gInterface.EventConfirm_CANCEL(wParam);
			gInterface.EventConfirm_OK(wParam);
			gCRuudShop.RuudShopEventButton(wParam);
			gCSCharacterS13.SelectCharButton(wParam);
			EventMuOffhelper(wParam);
			//tue add BOX ATM
			gInterface.SPK_BoxAtm_Close(wParam);
			gInterface.SPKEventClick(wParam);
			gInterface.EventDrawMenu_Open(wParam);
			gInterface.SPK_DrawMenu_Close(wParam);
			gInterface.SPK_ResetAuto(wParam);
			gInterface.SPK_BomMauAuto(wParam);
			gInterface.SPK_BuffAuto(wParam);
			gInterface.SPK_Camera3D(wParam);
			gInterface.SPK_RsCamera3D(wParam);
			gInterface.SPK_OpenBoxAtm(wParam);
			gInterface.SPK_OpenBoxBSK(wParam);
			gInterface.SPK_OpenBoxCfg(wParam);
			gInterface.SPK_ItemBlock(wParam);
			gInterface.SPK_Pklock(wParam);
			//add Vong Quay Open Box
			gInterface.SPK_OpenVongQuay(wParam);
			//------
			////////////////////////////////////
			//tue add Tu Chan /////
			gInterface.SPK_TuChan_Close(wParam);
			///////////////////////
			//tue add Hon Hoan ///
			gInterface.SPK_HonHoan_Close(wParam);
			//tue add thue flag
			gInterface.SPK_ThueFlag_Close(wParam);
			//============================


			#if (SELECTCHARACTER==1)
				gMultiCharacter.EventSelectChar(wParam);
			#endif
			if(gCRuudShop.RuudRender.Open)
			{
				if ( pCheckMouseOver(gCRuudShop.RuudRender.x, gCRuudShop.RuudRender.y + 10, gCRuudShop.RuudRender.w, 40.0f) == 1 )
				{
					gCRuudShop.RuudRender.Cursor.x = (double)*(DWORD*)0x879340C - gCRuudShop.RuudRender.x;
					gCRuudShop.RuudRender.Cursor.y = (double)*(DWORD*)0x8793410 - gCRuudShop.RuudRender.y;
					if(wParam == WM_LBUTTONDOWN)
					{
						gCRuudShop.RuudRender.Move = 1;
					}
					else
					{
						gCRuudShop.RuudRender.Move = 0;
					}
				}
				else
				{
					gCRuudShop.RuudRender.Move = 0;
				}
			}
			else if(gProtect.m_MainInfo.CustomInterfaceType == 1)
			{
				gInterface.EventNewInterface97_All(wParam);
			}
			else if(gProtect.m_MainInfo.CustomInterfaceType == 2)
			{
				gInterface.EventNewInterface_All(wParam);
			}
			gCMacroUIEx.Button(wParam);
			gOffTrade.EventOffTradeWindow_Main(wParam);
			gOffTrade.EventCloseTradeWindow_Main(wParam);
		}
		
		break;
		case WM_MOUSEMOVE:

			gCRuudShop.MoveWindows(&gCRuudShop.RuudRender,
				((double)*(DWORD*)0x879340C) - gCRuudShop.RuudRender.Cursor.x,
				((double)*(DWORD*)0x8793410) - gCRuudShop.RuudRender.Cursor.y);

			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.Move(Mouse);
			}
			break;
		case WM_MBUTTONDOWN:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.SetIsMove(1);
				gCamera.SetCursorX(Mouse->pt.x);
				gCamera.SetCursorY(Mouse->pt.y);
			}
			break;
		case WM_MBUTTONUP:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.SetIsMove(0);
			}
			break;
		case WM_MOUSEWHEEL:
			if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
			{
				gCamera.Zoom(Mouse);
			}
			break;
	}

	
	// ----
	return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Keyboard(int nCode, WPARAM wParam, LPARAM lParam) // OK
{
	if (nCode == HC_ACTION && (wParam == WM_KEYDOWN) || (wParam == WM_SYSKEYDOWN))
	{
		if (((DWORD)lParam & (1 << 30)) != 0 && ((DWORD)lParam & (1 << 31)) != 0)
		{
			switch (wParam)
			{
				
			case VK_F10:
						{
							gInterface.SwitchCamera();
						}
						break;
			case VK_F11:
						{
							gInterface.CameraInit();
						}
						break;
			case VK_F12:
						{
							if( gTrayMode.TempWindowProc == NULL )
							{
								gTrayMode.TempWindowProc = SetWindowLong(pGameWindow, GWL_WNDPROC, (long)gController.Window);
							}
							// ----
							gTrayMode.SwitchState();
						}
						break;

			case VK_ESCAPE:
			{

							  if (gCustomRanking.CHECK_WINDOW_RANKING())
							  {
								  gCustomRanking.CLOSE_WINDOW_RANKING();
								  return -1;
							  }

							  if (G_QUAN_LY_TK.CHECK_WINDOW_QUAN_LY_TK())
							  {
								  G_QUAN_LY_TK.CLOSE_WINDOW_QUAN_LY_TK();
								  return -1;
							  }

							  if (gInterface.CheckTinhNangWindow())
							  {
								  gInterface.CloseTinhNangWindow();
								  return -1;
							  }

							  if (gInterface.CheckXoaHomDoWindow())
							  {
								  gInterface.CloseXoaHomDoWindow();
								  return -1;
							  }
							  //tue add thue flag 
							  if (gInterface.Data[SPK_ThueFlag_Main].OnShow)
							  {
								  gInterface.Data[SPK_ThueFlag_Main].Close();
								  return -1;
							  }
							  /////////////////////////

			}
				break;

				//case VK_SNAPSHOT:
				//{
				//	gInterface.Data[eLogo].EventTick = GetTickCount()+1500;
				//	return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
				//}
				//break;

			default:
				break;
			}
		}

	}

	if(GetForegroundWindow() == pGameWindow && pPlayerState == GameProcess) // đây là trong game này vag
	{
		if(nCode == HC_ACTION)
		{
			if(((DWORD)lParam & (1 << 30)) != 0 && ((DWORD)lParam & (1 << 31)) != 0)
			{
				if( GetForegroundWindow() == *(HWND*)(MAIN_WINDOW) )
				{
					gPartySearch.ControlTextBoxPTSearch(wParam);
#if(DOIMK)
					G_QUAN_LY_TK.CHANGEPASS_TEXTBOX(wParam);
#endif
					//tue add
#if BAUCUA
					gCUSTOM_BAUCUA.ControlTextBox(wParam);
#endif
					//---


				}
			}
		}
	}

	return CallNextHookEx(HookKB, nCode, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------


LRESULT Controller::Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{

	case TRAYMODE_ICON_MESSAGE:
		{
			switch(lParam)
			{
			case WM_LBUTTONDBLCLK:
				{
					gTrayMode.SwitchState();
				}
				break;
			}
		}
		break;
	}
	// ----
	return CallWindowProc((WNDPROC)gTrayMode.TempWindowProc, Window, Message, wParam, lParam);
}


void Controller::ProcInterface(WPARAM wParam)
{

	#if(SHOPSEARCH==TRUE)
			g_PersonalShopEx.Button(wParam);
#endif

	gInterface.EventEventTimeWindow_Move_01(wParam);
	gInterface.EventEventTimeWindow_Move_02(wParam);
	gInterface.EventEventTimeWindow_Move_03(wParam);
	gInterface.EventEventTimeWindow_Move_04(wParam);
	gInterface.EventEventTimeWindow_Move_05(wParam);
	gInterface.EventEventTimeWindow_Move_06(wParam);
	gInterface.EventEventTimeWindow_Move_07(wParam);
	gInterface.EventEventTimeWindow_Move_08(wParam);
	gInterface.EventEventTimeWindow_Move_09(wParam);
	gInterface.EventEventTimeWindow_Move_10(wParam);
	gInterface.EventEventTimeWindow_Move_11(wParam);
	gInterface.EventEventTimeWindow_Move_12(wParam);
	gInterface.EventEventTimeWindow_Move_13(wParam);
	gInterface.EventEventTimeWindow_Move_14(wParam);
	gInterface.EventEventTimeWindow_Move_15(wParam);
	gInterface.EventEventTimeWindow_Move_16(wParam);
	gInterface.EventEventTimeWindow_Move_17(wParam);
	gInterface.EventEventTimeWindow_Move_18(wParam);
	gInterface.EventEventTimeWindow_Move_19(wParam);
	gInterface.EventEventTimeWindow_Move_20(wParam);
	gInterface.EventEventTimeWindow_Move_21(wParam);
	gInterface.EventEventTimeWindow_Move_22(wParam);
	gInterface.EventEventTimeWindow_Move_23(wParam);
	gInterface.EventEventTimeWindow_Move_24(wParam);
	gInterface.EventEventTimeWindow_Move_25(wParam);
	gInterface.EventEventTimeWindow_Move_26(wParam);

	gInterface.EventDrawAutoReset_Open(wParam);

	gInterface.EventDrawAttack_Open(wParam);

	gResetSystem.EventResetWindow_Main(wParam);

	gGrandResetSystem.EventGrandResetWindow_Main(wParam);

	gInterface.EventCharacterWindow(wParam);

	gInterface.EventChangingClassWindow_Main(wParam);

	gInterface.EventWarehouseWindow_Main(wParam);
	
	gInterface.EventStatsAddWindow(wParam);

	if (wParam == WM_LBUTTONUP)
	{
		for (int i = 0; i<eMAX_VALUE; i++)
		{
			gInterface.Data[i].OnClick = false;
		}
	}

}

void Controller::Load(HINSTANCE Instance)
{
	HookKB = SetWindowsHookEx(WH_KEYBOARD, Keyboard, Instance, GetCurrentThreadId());

	if (!this->MouseHook)
	{
		this->MouseHook = SetWindowsHookEx(WH_MOUSE, this->Mouse, gController.Instance, GetCurrentThreadId());
		// ----
		if (!this->MouseHook)
		{
			return;
		}
	}
	// ----
	if (!this->KeyboardHook)
	{

	}
	// ----
	SetOp((LPVOID)0x004D0E2F, iconHook, ASM::CALL);
	return;

}