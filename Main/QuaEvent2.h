#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"

#if(QUAEVENT == 1)

//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_QUATOP3
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_QUATOP3();
	void DRAW_QUATOP3();
	void BIND();
	bool HIENTHIQUATOP3;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_QUATOP3() { gInterface.Data[EXBEXO_QUATOP3_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_QUATOP3() { gInterface.Data[EXBEXO_QUATOP3_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_QUATOP3() { return gInterface.Data[EXBEXO_QUATOP3_MAIN].OnShow; };

	void		DRAW_WINDOW_QUATOP3();

	bool		MAIN_QUATOP3(DWORD Event);
	bool		CLOSE_QUATOP3(DWORD Event);

	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_QUATOP3 G_BEXO_QUATOP3;
//===================================================================================================================================================================

#endif