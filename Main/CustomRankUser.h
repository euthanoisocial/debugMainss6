#ifndef _CUSTOM_RANK_USER_H
#define _CUSTOM_RANK_USER_H
// ---
#include "Protocol.h"
#include "Object.h"
// ---
#define pObjPreviewThis        ((DWORD)0x096A4C0)
#define CS_GET_STRUCT(x, y)	   (1124 * x + *(int*) y)
#define Color4f(r, b, g, o)	   ((o << 24) + (g << 16) + (b << 8) + r)
// ---

// ---
struct PMSG_CUSTOM_RANKUSER
{
	PSBMSG_HEAD h;
	char szName[20];
	int iIndex;
	int iLevel;
	int iReset;
	int iMReset;
	int iKills;
	int iDeads;
	int iFor;
	int iEne;
	int iAgi;
	int iVit;
	int iCom;
	int iClasse;
	int iRank;
	// ---
	int irDanhHieu;
	int irQuanHam;
	int irTuLuyen;
	int irThueVip;
	int irNguHanh;
	int iVipIcon;
	// ---
	//tue add Tu Chan ////////////////////
	int m_RankTitle1;
#if SPK_QUANHAM
	int m_RankTitle2;
#endif
#if SPK_TUCHAN
	int irRankTitle3;
#endif
#if SPK_NEWVIP
	int m_RankTitle4;
#endif
#if(SPK_HONHOAN)
	WORD m_RankTitle5;
#endif
#if(HT_THUE_FLAG)
	int m_RankTitle6;
#endif
	//////////////////////////////////////
	char iVip[20];
};
// ---
struct CUSTOM_RANKUSER_DATA
{
	WORD m_Index;
	WORD m_Resets;
	WORD m_MResets;
	WORD m_Level;
	WORD m_Kills;
	WORD m_Deads;
	WORD m_For;
	WORD m_Vit;
	WORD m_Ene;
	WORD m_Agi;
	WORD m_Com;
	WORD m_Classe;
	WORD m_Rank;
	WORD m_iVipIcon;

	int m_rDanhHieu;
	int m_rQuanHam;
	int m_rTuLuyen;
	int m_rThueVip;
	int m_rNguHanh;
	//tue add Tu Chan ///////////////////
	int m_RankTitle1;
#if SPK_QUANHAM
	int m_RankTitle2;
#endif
#if SPK_TUCHAN
	int m_rRankTitle3;
#endif
#if SPK_NEWVIP
	int m_RankTitle4;
#endif
#if(SPK_HONHOAN)
	WORD m_RankTitle5;
#endif
#if(HT_THUE_FLAG)
	int m_RankTitle6;
#endif
	/////////////////////////////////////


	char m_Vip[20];
	BOOL m_Enabled;
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
	char szTitleRank[20];
	//tue add Tu Chan ////
#if SPK_QUANHAM
	//WORD m_RankTitle2;
#endif
#if SPK_TUCHAN
	//WORD m_RankTitle3;
#endif
#if SPK_NEWVIP
	//WORD m_RankTitle4;
#endif
#if(SPK_HONHOAN)
	//WORD m_RankTitle5;
#endif
#if(HT_THUE_FLAG)
	//int m_RankTitle6;
#endif
	////////////////
};
// ---
class CCustomRankUser
{
public:
	CCustomRankUser();
	// ---
	void DrawInfo();
		void	Test();
	int  DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	// ---
	void GCReqRankLevelUser(PMSG_CUSTOM_RANKUSER * aRecv);
	//tue add Tu Chan ////
	void RenderShowLogRank(DWORD ViewPortAddr, int index, int PosX, int PosY);
	///////////////////////

	CUSTOM_RANKUSER_DATA m_Data[14000];

};
extern CCustomRankUser gCustomRankUser;
// ---
class CPreviewManager
{
public:
	bool ObjCheck(int index, int pThis);
	bool ObjSelect(int index, int pThis);
	// ---
	WORD  Index;
	BYTE  Live;
	BYTE  Type;
	BYTE  IsSafeZone;
	// ---
	VAngle Angle;
};
// ---
#endif