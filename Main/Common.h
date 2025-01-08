#pragma once

#define Offset_CreateFontA1 0x004060D0
#define Offset_CreateFontA2 0x004D2882
#define Offset_CreateFontA3    0x004D28EB
#define Offset_CreateFontA4 0x004D2957
#define Offset_CreateFontA5 0x004D29C1


void InitCommon();
BOOL CheckIsLuckyItem(int ItemID);
BOOL CheckGensBattleMap(int map);
BOOL CheckGensMoveIndex(int idx);
void LoginTab();
void CheckMasterLevel();
void CompareGensMoveIndex();
void DrawEffectsPic(int &EffectID, float StartX, float StartY, float StartWidth, float StartHeight );
void Copyright();

extern BYTE GensBattleMapCount;
extern BYTE GensMoveIndexCount;
extern BYTE GensBattleMap[120];
extern BYTE GensMoveIndex[120];

extern int DisableStaticEffect;
extern int DisableDynamicEffect;
extern int DisableSkillEffect;
extern int DisableGlowEffect;
extern int DisableObject;
extern int DisablePlayer;
extern int DisableShadow;
extern int Anisotropy;
extern int MaxAnisotropy;
extern int Linear;
extern int Fog;
extern int Tron;
extern int MiniMap;
extern int SeparateChat;
extern int TimerBar;
extern int HpMonsterBar;
extern int HPMonster;
extern char Main_Font_Name[100];
extern int Main_Font_Bold;
extern int Main_Font_Height;
extern int Main_Font_Italic;
extern int Main_Font_Unicode;
extern int Main_Font_Width;
extern int Main_Font_Underline;
extern int Main_Font_Quality;
extern int Main_Font_StrikeOut;
extern int SellPostColor;
extern int offhelper;
extern int OpenSwicthSkill;
extern int SkillPage;
extern int MinimizarParty;
extern int MinimizarMiniMapa;
extern int MiniMapType;
extern bool gAdvanceStats;
extern bool gDamageTable;
extern int EnableEffect15;
extern int EnableObjects;
extern int Transparency1;
extern int Transparency2;
extern int Transparency3;
extern int Invisibility;
extern int NewStaticEffect;
extern int NewDynamicEffect;
extern int NewActiveShades;
//tue add ATM box
extern int PVPAttack;
//tue add thue Flag
#if(HT_THUE_FLAG)
extern int DisableFlag;
#endif
//---