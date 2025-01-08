#pragma once
#include "Defines.h"
// ----------------------------------------------------------------------------------------------
#define Main_PrintGlobal 00597630H;


//#define RenderBoolean		((void(__cdecl*)(int a1, int a2, char *a3)) 0x005985F0)
//#define CreateGuildMark		((void(__cdecl*)(int a1, bool a2)) 0x005D30F0)
//#define RenderBitmap		((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)

//#define pRenderCharacter		((void(__cdecl*)(lpViewObj lpObj,  Object* lpObject, int a3)) 0x0056F210)
//#define RenderBoolean									((void(__cdecl*)(int a1, int a2, char *a3)) 0x005985F0)
//#define CreateGuildMark									((void(__cdecl*)(int a1, bool a2)) 0x005D30F0)


#define RenderBoolean									((void(__cdecl*)(int a1, int a2, char *a3)) 0x005985F0)
#define CreateGuildMark									((void(__cdecl*)(int a1, bool a2)) 0x005D30F0)
#define RenderBitmap									((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)
#define pDrawButton				((void(__cdecl*)(DWORD, float, float, float, float, float, float)) 0x00790E40)

#define pSetFont                ((int(__thiscall*)(LPVOID This, int a2)) 0x420120)
#define EnableAlphaTest					((void(__cdecl*)(BYTE Mode)) 0x00635FD0)
#define sub_5984D0						((int (__cdecl*)( char a3 )) 0x005984D0)
#define sub_5BCE80						((bool (__cdecl*)( )) 0x005BCE80)
#define sub_5BD3E0						((bool (__cdecl*)( int a4)) 0x005BD3E0)
#define sub_5BD400						((void *(__cdecl*)( int a4)) 0x005BD400)
#define sub_5BD420						((int (__cdecl*)( int a4)) 0x005BD420)
#define sub_5BD440						((signed int(__cdecl*)( int a4)) 0x005BD440)
#define sub_5D3030						((char(__cdecl*)( int a3)) 0x005D3030)
#define GensPrintLogo					((void(__thiscall*)( int a1, float a5, float a6, char a7, char a8, int a9, float a10)) 0x007C5C20)
#define sub_9D09B0						((int(__cdecl*)( BYTE *a1, BYTE *a2)) 0x009D09B0)
#define sub_8CB0E0						((char(*)( )) 0x008CB0E0)
#define sub_57FB20						((signed int(__cdecl*)(char a1)) 0x0057FB20)
#define sub_57FB70						((signed int(__cdecl*)(char a1)) 0x0057FB70)
#define GetMarkGuild					((void(__cdecl*)(int a4, char a5)) 0x005D30F0)
#define GetAngleCursorX					*(int*)0x879340C
#define GetAngleCursorY					*(int*)0x8793410


class Other
{
public:
	float	Zoom;
	float	RotationY;
	void	Load();
	// ----
	void	Crack();

	char TextVN[500][500];
	char TextVN_SachThuocTinh[120][120];
	char TextVN_RingPedan[120][120];
	char TextVN_NhiemVu[120][120];
	char TextVN_DanhHieu[120][120];
	char TextVN_QuanHam[120][120];
	char TextVN_KepChuot[120] [120];
	char TextVN_ThanMaChien[50][120];
	char TextVN_NangCapRong[120] [120];
	// ----
//	static int GameLoad();
	//static void _FC MoveListInit(LPVOID This, LPVOID EDX, int Arg1, int Arg2);
	// ----


	static HFONT LoadNewFontA(int nHeight,
		int nWidth,
		int nEscapement,
		int nOrientation,
		int fnWeight,
		DWORD fdwItalic,
		DWORD fdwUnderline,
		DWORD fdwStrikeOut,
		DWORD fdwCharSet,
		DWORD fdwOutputPrecision,
		DWORD fdwClipPrecision,
		DWORD fdwQuality,
		DWORD fdwPitchAndFamily,
		LPCTSTR lpszFace);



}; extern Other gOther;

#define TEXTVN_FILE "./Data/Custom/TextVN.dat"

extern int Server;
// ----------------------------------------------------------------------------------------------
