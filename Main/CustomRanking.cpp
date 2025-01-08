#include "stdafx.h"
#include "CustomRanking.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"
#include "SItemOption.h"

CCustomRanking::CCustomRanking()
{
}

CCustomRanking gCustomRanking;

void CCustomRanking::ClearCustomRanking() // OK
{
	for(int n=0;n < MAX_RANK;n++)
	{
		memset(gCustomRanking[n].szName,0,sizeof(gCustomRanking[n].szName));
		gCustomRanking[n].valor = -1;
	}
	this->RankEnable = 0;
}

void CCustomRanking::GCReqRanking(PMSG_CUSTOM_RANKING_RECV* lpMsg) // OK
{
	memcpy(this->rankname,lpMsg->rankname,sizeof(this->rankname)); 
	memcpy(this->col1,lpMsg->col1,sizeof(this->col1)); 
	memcpy(this->col2,lpMsg->col2,sizeof(this->col2));
	this->RankEnable = 1;

	this->count = lpMsg->count;

	for(int n=0;n < lpMsg->count;n++)
	{
		CUSTOM_RANKING_DATA* lpInfo = (CUSTOM_RANKING_DATA*)(((BYTE*)lpMsg)+sizeof(PMSG_CUSTOM_RANKING_RECV)+(sizeof(CUSTOM_RANKING_DATA)*n));

		memcpy(gCustomRanking[n].szName,lpInfo->szName,sizeof(gCustomRanking[n].szName));
		gCustomRanking[n].valor = lpInfo->valor;
		memcpy(gCustomRanking[n].value3,lpInfo->value3,sizeof(gCustomRanking[n].value3));
	}
}

void CCustomRanking::GCReqRankingCount(PMSG_CUSTOM_RANKING_COUNT_RECV* lpMsg) // OK
{
	this->RankingCount = (lpMsg->count > 0) ? lpMsg->count : 0;
}
int NextRanking = 0;
int PrevRanking = 0;

void CCustomRanking::DrawRankPanelWindow()
{
	if( !gInterface.Data[eRankPANEL_MAIN].OnShow )
	{
		return;
	}

	if ( gInterface.CheckWindow(Inventory)
	|| gInterface.CheckWindow(Character) //-- 13 & 16
	|| gInterface.CheckWindow(Warehouse) //-- 8
	|| gInterface.CheckWindow(Shop) //-- 12
	|| gInterface.CheckWindow(ChaosBox) //-- 9
	|| gInterface.CheckWindow(Trade) //-- 7
	|| gInterface.CheckWindow(Store) //-- 14
	|| gInterface.CheckWindow(OtherStore) //-- 15
	|| gInterface.CheckWindow(LuckyCoin1) //-- 60
	|| gInterface.CheckWindow(NPC_ChaosMix)
	|| gInterface.CheckWindow(MoveList) 
	) //-- 76
	{
		gInterface.Data[eRankPANEL_MAIN].OnShow = false;
		return;
	}

	float MainWidth			= 230.0;
	float MainHeight		= 240.0;
	float StartBody			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);
	//--
	DWORD Color = eGray100;

	//if (gInterface.IsWorkZone(eRankPANEL_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	//{
	//	pSetCursorFocus = true;
	//}
	//else pSetCursorFocus = false;

	RenderBitmap(531116,StartX, gInterface.Data[eRankPANEL_MAIN].Y + 85, 380, 400, 0, 0, 1, 1, 1, 1, 0.0);

	gInterface.DrawFormat(eGold, (int)StartX + 55, (int)StartBody + 10, 210, 3, "Bảng Xếp Hạng %s", this->rankname);

	gInterface.DrawGUI(eRanking_CLOSE, StartX + 280, 93);
	if (gInterface.IsWorkZone(eRanking_CLOSE))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(eRanking_CLOSE, gInterface.Data[eRanking_CLOSE].X, gInterface.Data[eRanking_CLOSE].Y, Color);
	}

	if (this->RankingType > 0 )
	{
		gInterface.DrawGUI(eSAMPLEBUTTON2, StartX + 5, 220);
	}
	else 
	{
		gInterface.ResetDrawIMG(eSAMPLEBUTTON2);
	}

	if (this->RankingType < this->RankingCount-1)
	{
		gInterface.DrawGUI(eSAMPLEBUTTON, StartX + 305, 220);
	}
	else
	{
		gInterface.ResetDrawIMG(eSAMPLEBUTTON);
	}
	
	if (this->RankEnable == 1)
	{

		gInterface.DrawFormat(eWhite,  StartX + 30, StartBody + 35, 52, 1,"Top:");

		gInterface.DrawFormat(eWhite,  StartX + 80, StartBody + 35, 52, 1,"%s", this->col1);

		gInterface.DrawFormat(eWhite,  StartX + 145, StartBody + 35, 52, 1,"%s", this->col2);

		if(RankingType == 0 || RankingType == 1)
		gInterface.DrawFormat(eWhite,  StartX + 225, StartBody + 35, 52, 1,"Thời Gian");

		char* name = (char*)(oUserPreviewStruct+0x38);

		for (int i=0; i < this->count; i++)
		{
			Color = eGold;

			if (strcmp(name,this->gCustomRanking[i].szName) == 0)
			{
				Color = eExcellent;
			}

			gInterface.DrawFormat(Color,  StartX + 30, StartBody + 48 + (20*i), 52, 1,"%dº", (i+1));

			gInterface.DrawFormat(Color,  StartX + 80, StartBody + 48 + (20*i), 52, 1,"%s", this->gCustomRanking[i].szName);

			gInterface.DrawFormat(Color,  StartX + 145, StartBody + 48 + (20*i), 52, 1,"%d", this->gCustomRanking[i].valor);

			if(RankingType == 0 || RankingType == 1)
			gInterface.DrawFormat(Color,  StartX + 225, StartBody + 48 + (20*i), 52, 1,"%s", this->gCustomRanking[i].value3);

		}
	}
	else 
	{
		if (this->RankLoad == 1)
		{
			gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2)+30, StartBody + 120, 52, 1,"Loading ..");
			this->RankLoad = 2;
		}
		else if(this->RankLoad == 2)
		{
			gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2)+30, StartBody + 120, 52, 1,"Loading ...");
			this->RankLoad = 3;
		}
		else if(this->RankLoad == 3)
		{
			gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2)+30, StartBody + 120, 52, 1,"Loading ....");
			this->RankLoad = 4;
		}
		else if(this->RankLoad == 4)
		{
			gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2)+30, StartBody + 120, 52, 1,"Loading .....");
			this->RankLoad = 0;
		}
		else
		{
			gInterface.DrawFormat(eGold, MainCenter - (sizeof(this->rankname) / 2)+30, StartBody + 120, 52, 1,"Loading .");
			this->RankLoad = 1;
		}
	}
}

bool CCustomRanking::EventRankingNext(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eSAMPLEBUTTON].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eSAMPLEBUTTON2].EventTick);

	if( !gInterface.Data[eRankPANEL_MAIN].OnShow || NextRanking == -1)
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eSAMPLEBUTTON) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eSAMPLEBUTTON].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}

	if( Delay < 1000 || Delay2 < 1000 )
	{
		return false;
	}
	
	this->ClearCustomRanking();
	
	gInterface.Data[eSAMPLEBUTTON].OnClick = false;
	pSetCursorFocus = false;

	gInterface.Data[eSAMPLEBUTTON].EventTick = GetTickCount();
	
	PMSG_CUSTOM_RANKING_SEND pMsg;

	pMsg.header.set(0xF3, 0xE6,sizeof(pMsg));

	RankingType++;
	pMsg.type = RankingType;

	DataSend((BYTE*)&pMsg,pMsg.header.size);



	return true;
}

bool CCustomRanking::EventRankingBack(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eSAMPLEBUTTON].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eSAMPLEBUTTON2].EventTick);

	if( !gInterface.Data[eRankPANEL_MAIN].OnShow || PrevRanking == -1)
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eSAMPLEBUTTON2) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eSAMPLEBUTTON2].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}

	if( Delay < 1000 || Delay2 < 1000 )
	{
		return false;
	}

	this->ClearCustomRanking();
	
	gInterface.Data[eSAMPLEBUTTON2].OnClick = false;
	pSetCursorFocus = false;

		gInterface.Data[eSAMPLEBUTTON2].EventTick = GetTickCount();
	
		PMSG_CUSTOM_RANKING_SEND pMsg;

		pMsg.header.set(0xF3, 0xE6,sizeof(pMsg));

		RankingType--;
		pMsg.type = RankingType;

		DataSend((BYTE*)&pMsg,pMsg.header.size);
		return true;
}

bool CCustomRanking::EventRankingWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eRanking_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eRankPANEL_MAIN].OnShow || !gInterface.IsWorkZone(eRanking_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eRanking_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eRanking_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eRanking_CLOSE].EventTick = GetTickCount();

	this->CLOSE_WINDOW_RANKING();

	gInterface.Data[eRankPANEL_MAIN].OnShow = false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 0)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

void CCustomRanking::OpenWindow()
{

	if((GetTickCount() - gInterface.Data[eRankPANEL_MAIN].EventTick) < 1500 )
	{
		//gInterface.Data[eRankPANEL_MAIN].OnShow = false;
		return;
	}

	gInterface.Data[eRankPANEL_MAIN].EventTick = GetTickCount();

	if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eRankPANEL_MAIN].OnShow = false;
		
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
		return;
	}

	gInterface.CloseCustomWindow();

	this->ClearCustomRanking();

	this->RankingCount = 0;

	PMSG_CUSTOM_RANKING_COUNT_SEND pMsg1;

	pMsg1.header.set(0xF3, 0xE7,sizeof(pMsg1));

	DataSend((BYTE*)&pMsg1,pMsg1.header.size);

	PMSG_CUSTOM_RANKING_SEND pMsg;

	pMsg.header.set(0xF3, 0xE6,sizeof(pMsg));

	this->RankingType = 0;

	pMsg.type = 0;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	//gInterface.Data[eRankPANEL_MAIN].EventTick = GetTickCount();
	gInterface.Data[eRankPANEL_MAIN].OnShow = true;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}


}