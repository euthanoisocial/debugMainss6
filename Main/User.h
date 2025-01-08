#pragma once
#include "Object.h"
#include "Protocol.h"
struct BANKEX_USER_DATA
{
	long Money;
	long Bless;
	long Soul;
	long Chaos;
	long Creation;
	long Life;
	long Harmony;
	long GuaStone;//
	long GemStone;//
	long SmallStone;//
	long BigStone;//
	////devsolar
	long SCLHONG;//
	long SCLDO;//
	long SCLXANH;//
	long HQXANHLA;//
	long HQDO;//
	long KUNDUN1;//
	long KUNDUN2;//
	long KUNDUN3;//
	long KUNDUN4;//
	long KUNDUN5;//
	long HQTIM;//
	long CHAOSXANH;//
	long CHAOSDO;//
	long CHAOSTIM;//
	long BOXGM;//

};
#pragma pack(push, 1)
struct PMSG_TARGETDATA_REQ
{
	PSWMSG_HEAD header;
	int			aIndex;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGETDATA_ANS
{
	PSWMSG_HEAD header;
	int aIndex;
    bool isMonster;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGET_MONSTER_DATA : PMSG_TARGETDATA_ANS
{
    int Life;
    int MaxLife;
    short Level;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TARGET_PLAYER_DATA : PMSG_TARGET_MONSTER_DATA
{
    int SD;
    int MaxSD;
    short Reset;
	short RankTitle;
	short Long;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_TVT_UPD
{
	PBMSG_HEAD2 h;
	DWORD m_dwEventTimeTiecRuou;

};
#pragma pack(pop)

struct CUSTOM_LOGO
{
	int Active;
	int	X;
	int	Y;
};
///abcd
struct PMSG_UPD_CAPNHAT_INFO
{
	PSBMSG_HEAD	h;
	int CAPNHAT1;
	int CAPNHAT2;
	int CAPNHAT3;
	int CAPNHAT4;
	int CAPNHAT5;
	int CAPNHAT6;
	int CAPNHAT7;
	int CAPNHAT8;
};

class User
{
public:
	#if(DEV_DAMAGE_TABLE)
	bool m_SecondInfo;
	int m_SecondDamageMax;
	int m_SecondDamage;
	int m_SecondDefence;
	int m_SecondReflect;
	#endif
	void			ToggleAuto();
	void			ToggleAutoTron();
	int CoordenadaX;
	int CoordenadaY;
	int getLevel;
	int getReset;
	char getName[11];
	//-- post item
	int				PostItemID;
	int				PostItemLV;
	int				PostItemExc;
	int				PostItemAcc;
	int				PostItemHarmony;
	int				PostItem380;
	char*			PostItemSocket;
	int				PostItemX;
	int				PostItemY;
	int				GetPet;
	//--
	void			Load();
	void			Refresh();	
	bool			GetTarget();
	lpCharObj		lpPlayer;
	lpViewObj		lpViewPlayer;
	lpViewObj		lpViewTarget;
	BYTE			m_TargetType;	//1 - npc, 2 - attack
	int				m_MapNumber;
	int				m_CursorX;
	int				MagickAttack;
	int				m_CursorY;
	DWORD			m_TargetUpdateTick;
	int				m_QuestStat;
	BYTE			m_reset_item_check[5];
	int				m_MaxWarehouse;
	int				m_WarehouseNumber;
	static char* GetMapName(signed int MapNumber);
	static void ChangeCharInfo(LPVOID This);
	bool InSafeZone;
	static void	AllInOne();
	void DrawHP();
	void DrawRank();
	void SetTargetData(PMSG_TARGETDATA_ANS * lpMsg);
	int GetActiveSkill();
	static void	SetEventEffect(int PreviewStruct);
	CUSTOM_LOGO m_Logo[400];
	BANKEX_USER_DATA BankEx;
	void RenderRuneEffect(DWORD ObjectModel, int ID,int Type, float Z,  float Size);
	static bool	ShowModelBMD(int a1, int a2, int a3);
	//Auto Sendmove
	DWORD		IsSendMove;
	DWORD			MoveToX;
	DWORD			MoveToY;
	BYTE		KhongDiDuoc;
	DWORD m_dwEventTimeTiecRuou;
	static bool UseHasMagicRing();
	static bool CreateManyFlag(ObjectPreview * pChar);
	static void __cdecl HoolCreateManyFlay(ObjectPreview * pChar);

	#if(MOCNAP == 1)
	int MocNapCheck1;
	int MocNapCheck2;
	int MocNapCheck3;
	int MocNapCheck4;
	int MocNapCheck5;
	int MocNapCheck6;
	int MocNapCheck7;
	int MocNapCheck8;
	int MocNapCheck9;
	int MocNapCheck10;
	int MocNapCheck11;
	int MocNapCheck12;
	int MocNapCheck13;
	int	MOCNAPCOIN;
	int	MOCNAP1;
	int	MOCNAP2;
	int	MOCNAP3;
	int	MOCNAP4;
	int	MOCNAP5;
	int	MOCNAP6;
	int	MOCNAP7;
	int	MOCNAP8;
	int	MOCNAP9;
	int	MOCNAP10;
	int	MOCNAP11;
	int	MOCNAP12;
	int	MOCNAP13;
#endif
#if(QUAEVENT == 1)
	int QuaTop1Check1;
	int	QUATOP1COIN;
	int	QUATOP1;

	int QuaTop2Check1;
	int	QUATOP2COIN;
	int	QUATOP2;

	int QuaTop3Check1;
	int	QUATOP3COIN;
	int	QUATOP3;
#endif
	//tue add Hon Hoan ///
#if(SPK_HONHOAN)
	void      CBRenderCharacter(DWORD ObjectPointer, int Effect, float SizeX, float SizeY, vec3_t Color, int Type = 0);
#endif
	// =========================
	//abcd
	int	m_CAPNHAT1;
	int	m_CAPNHAT2;
	int	m_CAPNHAT3;
	int	m_CAPNHAT4;
	int	m_CAPNHAT5;
	int	m_CAPNHAT6;
	int	m_CAPNHAT7;
	int	m_CAPNHAT8;
	void RecvCustomCAPNHATMu(PMSG_UPD_CAPNHAT_INFO * aRecv);//ok	
	/////
	BOOL        is_auto;
	BOOL        is_autotron;
};
extern User gObjUser;