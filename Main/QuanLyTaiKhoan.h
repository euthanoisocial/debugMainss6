#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class QUAN_LY_TK
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	QUAN_LY_TK();
	void DRAW_QUAN_LY();
	bool HIENTHIQUAN_LY;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	int TRANG_QUAN_LY;
	void CLICK_TRANG_QUAN_LY(DWORD ClickMouse);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_QUAN_LY_TK() { gInterface.Data[QUAN_LY_TK_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_QUAN_LY_TK() { gInterface.Data[QUAN_LY_TK_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_QUAN_LY_TK() { return gInterface.Data[QUAN_LY_TK_MAIN].OnShow; };

	void		DRAW_WINDOW_QUAN_LY_TK();

	bool		MAIN_QUAN_LY(DWORD Event);
	bool		CLOSE_QUAN_LY(DWORD Event);
	void BinObeject();

	void LoadImages();
	#if(DOIMK)
		//========== CHange Pass
	void		DRAW_WINDOW_CHANGEPASS();
	void		OPEN_WINDOW_CHANGEPASS() { gInterface.Data[eChangePass_Main].OnShow ^= true; pSetCursorFocus ^= true; gInterface.Data[eChangePass_Main].FirstLoad = true; *(BYTE*)0xE8C5AC ^= 1;};
	bool		EVENT_CLICK_CHANGEPASS(DWORD Event);
	bool		CHANGEPASS_TEXTBOX(DWORD Event);
#endif
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern QUAN_LY_TK G_QUAN_LY_TK;
//===================================================================================================================================================================

