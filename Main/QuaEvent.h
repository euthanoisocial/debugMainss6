#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"

#if(QUAEVENT == 1)

//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_QUATOP1
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_QUATOP1();
	void DRAW_QUATOP1();
	void BIND();
	bool HIENTHIQUATOP1;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_QUATOP1() { gInterface.Data[EXBEXO_QUATOP1_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_QUATOP1() { gInterface.Data[EXBEXO_QUATOP1_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_QUATOP1() { return gInterface.Data[EXBEXO_QUATOP1_MAIN].OnShow; };

	void		DRAW_WINDOW_QUATOP1();

	bool		MAIN_QUATOP1(DWORD Event);
	bool		CLOSE_QUATOP1(DWORD Event);

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_QUATOP1 G_BEXO_QUATOP1;
//===================================================================================================================================================================

#endif