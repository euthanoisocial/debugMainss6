#pragma once
#include "Import.h"
#include "Interface.h"
#include "Protocol.h"



//======================================================
struct PMSG_NGUHANH_UPD
{
	PSBMSG_HEAD	h;
	int		rNguHanh;
	int		rTuLuyen;

};
//======================================================
//======================================================
struct BUY_THUE_VIP_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
//======================================================
//======================================================
struct BUY_QUAN_HAM_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
//======================================================
struct BUY_TU_LUYEN_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
//======================================================
//======================================================
struct BUY_NGU_HANH_REQ
{
	PSBMSG_HEAD h;
	int			Number;
};
//======================================================
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class BEXO_HE_THONG
{
public:
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	BEXO_HE_THONG();
	void DRAW_HE_THONG();
	bool HIENTHIHE_THONG;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	int TRANG_HE_THONG;
	void BEXO_CLICK_TRANG_HE_THONG(DWORD ClickMouse);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	float MainWidth;
	float MainHeight;
	float StartY;
	float StartX;
	DWORD ClickTick;
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	void		OPEN_WINDOW_HE_THONG() { gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CLOSE_WINDOW_HE_THONG() { gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CHECK_WINDOW_HE_THONG() { return gInterface.Data[EXBEXO_HE_THONG_MAIN].OnShow; };

	void		DRAW_WINDOW_HE_THONG();

	bool		MAIN_HE_THONG(DWORD Event);
	bool		CLOSE_HE_THONG(DWORD Event);


	int PageNguHanh;

	void BinObeject();

	void LoadImages();
	//-----------------------------

	//-----------------------------
	void GetInfoNguHanh(PMSG_NGUHANH_UPD * aRecv);
	int m_rNguHanh;
	int m_rRankTitle3;
//-----------------------------
	char m_iVip[20];


	void BUY_THUE_VIP(int Number);
	void BUY_QUAN_HAM(int Number);
	void BUY_TU_LUYEN(int Number);
	void BUY_NGU_HANH(int Number);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
}; extern BEXO_HE_THONG G_BEXO_HE_THONG;
//===================================================================================================================================================================

