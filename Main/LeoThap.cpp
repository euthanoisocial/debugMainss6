#include "StdAfx.h"
#if(LEOTHAP == 1)
#include "LeoThap.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"
#include "User.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "Protect.h"
#include "CustomFont.h"
#include "GLFont.h"

LeoThap gLeoThap;

LeoThap::LeoThap(void)
{
}

LeoThap::~LeoThap(void)
{
}

void LeoThap::GCData(PMSG_LEOTHAP_TIME* lpMsg) // OK
{
	this->m_TimeCount = lpMsg->TimeCount;
	this->m_Map = lpMsg->Map;
	this->State = lpMsg->State;
	this->eventTime = lpMsg->eventTime;
}

void LeoThap::GCData2(PMSG_LEOTHAP_TIME2* lpMsg) // OK
{
	this->m_TimeCount2 = lpMsg->TimeCount;
	this->m_Map2 = lpMsg->Map;
	this->State2 = lpMsg->State;
}

void LeoThap::LeoThapCountdown()
{
	float MainWidth = 210.0;
	float MainHeight = 14.0;
	float StartY = 100.0;
	float StartX = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartBody			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	int TxtCount = -1;
	int TxtStart = StartY + 88;

	if(pMapNumber == this->m_Map && this->m_TimeCount > 0)
	{
		pDrawGUI(81528, 518.5, 350, 120.0, 76.0);
		char text1[20];
		int totalseconds;
		int hours;
		int minutes;
		int seconds;
		int days;
		//------------
		
		totalseconds	= this->m_TimeCount;
		if(this->State == 0)
		{
			totalseconds = totalseconds - (this->eventTime/3 * 2 * 60);
		}
		if(this->State == 1)
		{
			totalseconds = totalseconds - (this->eventTime/3 * 60);
		}

		hours			= totalseconds/3600;
		minutes			= (totalseconds/60) % 60;  
		seconds			= totalseconds % 60;
		
		if (hours > 23)
		{
			days = hours/24;
			wsprintf(text1, "%d day(s)+", days);
		}
		else
		{
			wsprintf(text1, "%02d:%02d", minutes, seconds);
		}
		//------------

		CustomFont.Draw(CustomFont.FontNormal, StartX + (MainWidth / 2) + 320 + (/*g_fsFrame.fScreenWinAdd*/ - 110), TxtStart + (33.0f * TxtCount) + 210, 0xFFF370FF, 0x0, 108, 0, 3, "Thời gian còn:" );

		CustomFont.Draw(CustomFont.FontBold, StartX + (MainWidth / 2) + 320 + /*g_fsFrame.fScreenWinAdd*/ - 110, TxtStart + (33.0f * TxtCount) + 235, 0xFFF370FF, 0x0, 108, 0, 3, text1);
	}
}

void LeoThap::LeoThapDelayTime()
{
	if(this->m_TimeCount2 > 0)
	{
		if(this->State2 == 1)
		{
			/*g_pRenderText.SetTextColor(0xFF,0xFF,0xFF,0xFF);
			g_pRenderText.SetFont(m_hFontBold);
			g_pRenderText.CRenderText(-3, 140,"Đăng ký Vượt Tháp : %d (s)", this->m_TimeCount2,0);*/
			CustomFont.Draw(CustomFont.FontBold, -3, 190, 0xD517EBFF, 0x0, 108, 0, 3, "Đăng ký Vượt Tháp : %d (s)", this->m_TimeCount2);
		}
		if(this->State2 == 2)
		{
			CustomFont.Draw(CustomFont.FontBold, -3, 190, 0xD517EBFF, 0x0, 108, 0, 3, "Chuẩn bị chiến đấu: %d (s)", this->m_TimeCount2);
		}
	}
}

void LeoThap::ResetData()
{
	this->m_TimeCount = 0;
	this->m_TimeCount2 = 0;
}
#endif