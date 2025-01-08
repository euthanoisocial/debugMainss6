#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"

#if(QUAEVENT == 1)

//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_QUATOP2
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_QUATOP2();
	void DRAW_QUATOP2();
	void BIND();
	bool HIENTHIQUATOP2;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_QUATOP2() { gInterface.Data[EXBEXO_QUATOP2_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_QUATOP2() { gInterface.Data[EXBEXO_QUATOP2_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_QUATOP2() { return gInterface.Data[EXBEXO_QUATOP2_MAIN].OnShow; };

	void		DRAW_WINDOW_QUATOP2();

	bool		MAIN_QUATOP2(DWORD Event);
	bool		CLOSE_QUATOP2(DWORD Event);

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_QUATOP2 G_BEXO_QUATOP2;
//===================================================================================================================================================================

#endif