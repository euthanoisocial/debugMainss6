#pragma once

#include "Protocol.h"
#include "Interface.h"

#if BAUCUA
struct PSBMSG_BAUCUA_SEND
{
	PSBMSG_HEAD header; 
	int IconMiniGame[7];
};
struct PSBMSG_BAUCUA_RECV
{
	PSBMSG_HEAD h;
	int hot1;
	int hot2;
	int hot3;
	int tongtrathuong;
};
struct CUSTOM_BAUCUA_DATA
{
	int Bless;
	int Soul;
	int Life;
	int Creation;
	int Guardian;
	int GemStone;
	int Harmony;
	int Chaos;
	int LowStone;
	int HighStone;
};
class CUSTOM_BAUCUA
{
	public:
	CUSTOM_BAUCUA();
	void LOADBIN();
	void DrawStatsAddWindow();
	void EventCharacterWindow(DWORD Event);
	void EventStatsAddWindow_Close(DWORD Event);
	void EventStatsAddWindow(DWORD Event);
	void NhanKetQuaTuServer(PSBMSG_BAUCUA_RECV* lpMsg);
	void		SwitchStatsWindowState() { (gInterface.Data[BAUCUA_MAIN].OnShow == true) ? gInterface.Data[BAUCUA_MAIN].CloseAnimated(15) : gInterface.Data[BAUCUA_MAIN].Open(-226, 20); };
	bool ControlTextBox(DWORD Event);
	bool WCOINC;
	bool WCOINP;
	bool BLESS;
	bool SOUL;
	bool LIFE;
	bool CHAO;
	int type;

	int MaxCuoc;
	int IconMiniGame[8];
	private:
	PSBMSG_BAUCUA_RECV m_Data;
}; extern CUSTOM_BAUCUA gCUSTOM_BAUCUA;
#endif