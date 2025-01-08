#include "stdafx.h"
#include "CustomEventTime.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"
#include "SItemOption.h"
#include "WindowsStruct.h"
#include "Other.h"

CCustomEventTime::CCustomEventTime()
{
}

CCustomEventTime gCustomEventTime;

void CCustomEventTime::BinObeject()
{
	  #if(EXBEXO_LOAD_TIME_EVENT)

	gInterface.BindObject(eEVENTTABLE_MOVE_01, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_02, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_03, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_04, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_05, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_06, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_07, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_08, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_09, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_10, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_11, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_12, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_13, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_14, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_15, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_16, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_17, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_18, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_19, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_20, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_21, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_22, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_23, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_24, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_25, 0x7906, 16, 12, -1, -1);  // 31461
	gInterface.BindObject(eEVENTTABLE_MOVE_26, 0x7906, 16, 12, -1, -1);  // 31461
#endif
}

void CCustomEventTime::Load(CUSTOM_EVENT_INFO* info) // OK
{
	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomEventTime::SetInfo(CUSTOM_EVENT_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_EVENTTIME)
	{
		return;
	}

	this->m_CustomEventInfo[info.Index] = info;
}

void CCustomEventTime::ClearCustomEventTime() // OK
{
	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		gCustomEventTime[n].time = -1;
	}
	this->count = 0;
	this->EventTimeEnable = 0;
}

void CCustomEventTime::GCReqEventTime(PMSG_CUSTOM_EVENTTIME_RECV* lpMsg) // OK
{
	this->count = lpMsg->count;

	for (int n = 0; n < lpMsg->count; n++)
	{
		CUSTOM_EVENTTIME_DATA* lpInfo = (CUSTOM_EVENTTIME_DATA*)(((BYTE*)lpMsg) + sizeof(PMSG_CUSTOM_EVENTTIME_RECV)+(sizeof(CUSTOM_EVENTTIME_DATA)*n));

		this->gCustomEventTime[n].index = lpInfo->index;
		this->gCustomEventTime[n].time = lpInfo->time;

		if (this->gCustomEventTime[n].index >= 25 && this->gCustomEventTime[n].time != -1);
	}

	this->EventTimeEnable = 1;
}

int NextEvent = 0;
int PreventEvent = 0;

void CCustomEventTime::DrawEventTimePanelWindow()
{

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow)
	{
		return;
	}
	if (gInterface.CheckWindow(Inventory)
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
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		return;
	}

	float MainWidth = 40.0;
	float MainHeight = 20.0;
	float StartY = 25.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);

	if (gInterface.IsWorkZone(eEventTimePANEL_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;

	//gCItemSetOption.ItemTooltipS15(StartX - 140, StartY - 20, 380, 360, 0.0, 0);


	DWORD Color = eGray100;
	if (this->EventTimeEnable == 1)
	{

		if ((GetTickCount() - this->EventTimeTickCount) > 1000)
		{
			for (int i = 0; i < this->count; i++)
			{
				if (this->gCustomEventTime[i].time > 0)
				{
					this->gCustomEventTime[i].time = this->gCustomEventTime[i].time - 1;
				}
			}
			this->EventTimeTickCount = GetTickCount();
		}

		char text1[120];
		char text2[130];
		int totalseconds;
		int hours;
		int minutes;
		int seconds;
		int days;

		int line = 0;

		for (int i = 0; i < 25; i++) // Hiển thị event
		{
			if (this->gCustomEventTime[i].time <= -1)
			{
				continue;
			}
			else if (this->gCustomEventTime[i].time == 0)
			{
				wsprintf(text2, "Online");
			}
			else
			{
				totalseconds = this->gCustomEventTime[i].time;
				hours = totalseconds / 3600;
				minutes = (totalseconds / 60) % 60;
				seconds = totalseconds % 60;
				wsprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);

				if (hours > 23)
				{
					days = hours / 24;
					wsprintf(text2, "%d day(s)+", days);
				}
				else
				{
					wsprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);
				}
			}


			if (this->gCustomEventTime[i].time <= -1)
			{
				Color = eRed2;
			}
			else if (this->gCustomEventTime[i].time == 0)
			{
				Color = eExcellent;
			}
			else if (this->gCustomEventTime[i].time < 300)
			{
				Color = eOrange;
			}
			else
			{
				Color = eYellow;
			}

			gCItemSetOption.ItemTooltipS15(StartX - 135, StartY - 22 + (line)+10, 330, 15, 0.0, 0);

			gInterface.DrawFormat(eWhite, StartX - 125, StartY - 11 + (line), 500, 1, this->m_CustomEventInfo[i].Name); // Tên Event

			gInterface.DrawFormat(eBlue, StartX - 15, StartY - 11 + (line), 500, 1, this->m_CustomEventInfo[i].PhanThuong); // Phần Thương

			gInterface.DrawFormat(Color, StartX + 150, StartY - 11 + (line), 80, 1, text2); // Thời gian

			if (i == 0){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_01, StartX + 175, StartY - 12 + (line)); } }
			if (i == 1){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_02, StartX + 175, StartY - 12 + (line)); } }
			if (i == 2){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_03, StartX + 175, StartY - 12 + (line)); } }
			if (i == 3){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_04, StartX + 175, StartY - 12 + (line)); } }
			if (i == 4){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_05, StartX + 175, StartY - 12 + (line)); } }
			if (i == 5){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_06, StartX + 175, StartY - 12 + (line)); } }
			if (i == 6){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_07, StartX + 175, StartY - 12 + (line)); } }
			if (i == 7){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_08, StartX + 175, StartY - 12 + (line)); } }
			if (i == 8){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_09, StartX + 175, StartY - 12 + (line)); } }
			if (i == 9){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_10, StartX + 175, StartY - 12 + (line)); } }
			if (i == 10){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_11, StartX + 175, StartY - 12 + (line)); } }
			if (i == 11){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_12, StartX + 175, StartY - 12 + (line)); } }
			if (i == 12){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_13, StartX + 175, StartY - 12 + (line)); } }
			if (i == 13){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_14, StartX + 175, StartY - 12 + (line)); } }
			if (i == 14){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_15, StartX + 175, StartY - 12 + (line)); } }
			if (i == 15){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_16, StartX + 175, StartY - 12 + (line)); } }
			if (i == 16){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_17, StartX + 175, StartY - 12 + (line)); } }
			if (i == 17){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_18, StartX + 175, StartY - 12 + (line)); } }
			if (i == 18){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_19, StartX + 175, StartY - 12 + (line)); } }
			if (i == 19){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_20, StartX + 175, StartY - 12 + (line)); } }
			if (i == 20){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_21, StartX + 175, StartY - 12 + (line)); } }
			if (i == 21){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_22, StartX + 175, StartY - 12 + (line)); } }
			if (i == 22){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_23, StartX + 175, StartY - 12 + (line)); } }
			if (i == 23){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_24, StartX + 175, StartY - 12 + (line)); } }
			if (i == 24){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_25, StartX + 175, StartY - 12 + (line)); } }
			if (i == 25){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawGUI(eEVENTTABLE_MOVE_26, StartX + 175, StartY - 12 + (line)); } }

			//if (i == 0){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 1){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 2){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 3){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 4){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 5){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 6){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 7){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 8){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 9){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 10){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 11){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 12){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 13){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 14){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 15){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 16){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 17){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 18){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 19){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 20){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 21){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 22){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 23){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 24){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }
			//if (i == 25){ if (this->gCustomEventTime[i].time < 300){ RenderBitmap(61535, StartX + 148, StartY - 12 + (line), Return2X(TransForX(43)), ReturnY(TransForY(15)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0); } }

			if (i == 0){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 1){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 2){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 3){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 4){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 5){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 6){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 7){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 8){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 9){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 10){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 11){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 12){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 13){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 14){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 15){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 16){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 17){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 18){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 19){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 20){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 21){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 22){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 23){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 24){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }
			if (i == 25){ if (this->gCustomEventTime[i].time < 300){ gInterface.DrawFormat(eWhite, StartX + 175, StartY - 11 + (line), 80, 1, ""); } }


			line += 18; // 18
		}
	}
	else
	{
		if (this->EventTimeLoad == 1)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartY + 120, 52, 1, "Loading ..");
			this->EventTimeLoad = 2;
		}
		else if (this->EventTimeLoad == 2)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartY + 120, 52, 1, "Loading ...");
			this->EventTimeLoad = 3;
		}
		else if (this->EventTimeLoad == 3)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartY + 120, 52, 1, "Loading ....");
			this->EventTimeLoad = 4;
		}
		else if (this->EventTimeLoad == 4)
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartY + 120, 52, 1, "Loading .....");
			this->EventTimeLoad = 0;
		}
		else
		{
			gInterface.DrawFormat(eGold, MainCenter + 20, StartY + 120, 52, 1, "Loading .");
			this->EventTimeLoad = 1;
		}
	}
	//}
	//this->OpenWindow();
}

bool CCustomEventTime::EventEventTimeWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eEventTime_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eEventTime_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eEventTime_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eEventTime_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eEventTime_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

void CCustomEventTime::OpenWindow()
{

	if (gInterface.CheckWindow(ObjWindow::CreateGuild) || gInterface.CheckWindow(ObjWindow::ChatWindow) || gInterface.CheckWindow(ObjWindow::FriendList) || gInterface.CheckWindow(ObjWindow::NPC_Dialog) || gInterface.CheckWindow(ObjWindow::MuHelper) || gInterface.CheckWindow(ObjWindow::Store) || gInterface.CheckWindow(ObjWindow::Warehouse) || gInterface.CheckWindow(ObjWindow::Trade) || gInterface.CheckWindow(ObjWindow::CashShop))
	{
		return;
	}

	if ((GetTickCount() - gInterface.Data[eEventTimePANEL_MAIN].EventTick) < 500)
	{
		return;
	}

	gInterface.Data[eEventTimePANEL_MAIN].EventTick = GetTickCount();


	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

		if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		{
			pSetCursorFocus = false;
		}
		return;
	}

	gInterface.CloseCustomWindow();

	this->ClearCustomEventTime();

	gInterface.Data[eEventTimePANEL_MAIN].OnShow = true;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}

void CCustomEventTime::Notice(){
	if (gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::MuHelper)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		)
	{
		return;
	}

	PMSG_CUSTOM_EVENTTIME_SEND pMsg;
	pMsg.header.set(0xF3, 0xE8,sizeof(pMsg));
	DataSend((BYTE*)&pMsg,pMsg.header.size);
	this->EventTimeTickCount = GetTickCount();
	char text1[20];
	char text2[30];
	int totalseconds, hours, minutes, seconds, days, line = 0;
	for (int i=0; i < this->count; i++)

	{
	if (this->gCustomEventTime[i].time <= -1)
	{
			continue;
	}
	else if (this->gCustomEventTime[i].time == 0)
	{
			wsprintf(text2, "Online");
		}
	else
	{
			totalseconds	= this->gCustomEventTime[i].time;
			hours			= totalseconds/3600;
			minutes			= (totalseconds/60) % 60;  
			seconds			= totalseconds % 60;
			wsprintf(text2, gTime, minutes, seconds);
			if (hours > 23){
				days = hours/24;
				wsprintf(text2, "%d day(s)+", days);
			}else
			{
				wsprintf(text2, gTime, minutes, seconds);
			}
		}
		DWORD Color;
		if (this->gCustomEventTime[i].time <= -1)
		{
			Color = eRed2;
		}
		else if (this->gCustomEventTime[i].time == 0)
		{
			Color = eExcellent;
		}
		else if (this->gCustomEventTime[i].time < 300)
		{

			Color = eExcellent;
			float StartX = MAX_WIN_WIDTH;
			float StartY = MAX_WIN_HEIGHT;

			RenderBitmap(91990,  StartX / 5+70, StartY / 4+ 290, 470, 50, 0.0, 0.0, 1.1, 1.2, -0.5, 1, 0.0);
			RenderBitmap(91991,  StartX / 5+228, StartY / 4+ 291, 160, 50, 0.0, 0.0, 1.4, 1.4, -0.5, 1, 0.0);
			gInterface.DrawFormat(eWhite,  StartX / 5+ 240, StartY / 4+ 295, 100, 1,gSy2);
			gInterface.DrawFormat(eExcellent,  StartX / 5+ 220, StartY / 4+ 295, 100, 1,text2);
			gInterface.DrawFormat(eExcellent,  StartX / 5+95, StartY / 4+ 295, 120, 1,this->m_CustomEventInfo[i].Name);
			



		}else{
			Color = eYellow;
		}

		line += 0;
	}
}

bool CCustomEventTime::EventNext(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNextEvent].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[ePrevEvent].EventTick);

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || NextEvent == -1)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(eNextEvent))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNextEvent].OnClick = true;
		return true;
	}

	if (Delay < 100 || Delay2 < 100)
	{
		return false;
	}

	gInterface.Data[eNextEvent].OnClick = false;

	this->Page++;

	gInterface.Data[eNextEvent].EventTick = GetTickCount();


	return true;
}

bool CCustomEventTime::EventPrev(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[ePrevEvent].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[eNextEvent].EventTick);

	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || PreventEvent == -1)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(ePrevEvent))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[ePrevEvent].OnClick = true;
		return true;
	}

	if (Delay < 100 || Delay2 < 100)
	{
		return false;
	}

	gInterface.Data[ePrevEvent].OnClick = false;

	gInterface.Data[ePrevEvent].EventTick = GetTickCount();

	this->Page--;

	return true;
}

