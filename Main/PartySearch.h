#pragma once

#include "Protocol.h"
#include "Interface.h"

#if(PARTYSEARCH==1)

#define MAX_PARTYLIST 100

struct PARTYLIST{
	int Index;
	char Name[11];
	int Map;
	int X;
	int Y;
	int Level;
	bool DarkWizard;
	bool DarkKnight;
	bool Elf;
	bool MagicGladiator;
	bool DarkLord;
	bool Summoner;
	bool RageFighter;
	bool OnlyGuild;
	bool OnlyAlliance;
	bool IsSameGuild;
	bool IsSameAlliance;
	bool RequirePassword;
	int Count;
	bool ButtonActive;
};

struct PMSG_PARTY_REQ_SEND{
	PSBMSG_HEAD header;
	char Name[11];
	bool needPassword;
	char Password[20];
};

struct PMSG_RECV_PARTYLIST
{
	PSWMSG_HEAD header;
	int Count;
};

struct PMSG_PARTYSEARCH_PARTYLIST
{
	char Name[11];
	int Map;
	int X;
	int Y;
	int Level;
	bool DarkWizard;
	bool DarkKnight;
	bool Elf;
	bool MagicGladiator;
	bool DarkLord;
	bool Summoner;
	bool RageFighter;
	bool OnlyGuild;
	bool OnlyAliiance;			   
	bool IsSameGuild;
	bool IsSameAlliance;
	bool RequirePassword;
	int Count;
};

struct UP_PARTYSEARCH_REQ
{
	PSBMSG_HEAD h;
};


class cPartySearch{
public:
	cPartySearch();
	~cPartySearch();
	void ClearPartyList();
	void InsertPartyList(PMSG_PARTYSEARCH_PARTYLIST* lpInfo);
	/*Draw*/
	void DrawPartySettingsWindow();
	void SwitchPartySettingsWindowState();
	bool EventPartySettingsWindow_Main(DWORD Event);
	bool EventPartySettingsWindow_Close(DWORD Event);
	bool EventPartySettingsWindow_All(DWORD Event);
	void DrawPartySearchWindow();
		void OpenWindow();
	void ClosePartySearchWindow() { gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false; pSetCursorFocus = false; }
		 
	void SwitchPartySearchWindowState() { (gInterface.Data[ePARTYSEARCH_MAIN].OnShow == true) ? gInterface.Data[ePARTYSEARCH_MAIN].Close() : gInterface.Data[ePARTYSEARCH_MAIN].Open(); };
	
	void SwitchPartySearchWindowState2() { (gInterface.Data[ePARTYSEARCH_MAIN].OnShow == true) ? gInterface.Data[ePARTYSEARCH_MAIN].Close(), gInterface.Data[ePARTYSEARCH_MAIN].Open() : gInterface.Data[ePARTYSEARCH_MAIN].Open(); };
	
	void EventPartySearchWindow_All(DWORD Event);
	int	 DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...);
	bool IsWorkZone(float X, float Y, float MaxX, float MaxY);
	void DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color);
	void loadBind();
	void LoadImgPT();
	//--
	void SendPartyRequest(int index, char* password);
	void party_search_password_switch_state(){gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].OnShow == true ? gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Close() : gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Open();}
	void event_party_search_password_window(DWORD Event);
	void draw_party_password();
	bool ControlTextBoxPTSearch(DWORD Event);
	//---
	bool ClickRefresh(DWORD Event);
	bool ClickReSetting(DWORD Event);
	void CheckSetting(){gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == true ? gInterface.Data[ePARTYSEARCH_MAIN].Close() : gInterface.Data[ePARTYSEARCH_MAIN].Close(),gInterface.Data[ePARTYSETTINGS_MAIN].Open();}
	//---
	
	void GCPartyListRecv(PMSG_RECV_PARTYLIST* lpMsg);
	/*FinDraw*/
	PARTYLIST* GetPartyList(int index);
	void SendPartyRequest(int index);
	PARTYLIST gPartyList[MAX_PARTYLIST];
	int ListsCount;
	int Page;
	int CountPages;
	int currentIndex;
}; extern cPartySearch gPartySearch;

#endif