#include "stdafx.h"
#include "WideScreen.h"
#include "Import.h"
#include "Util.h"
#include "OffTrade.h"
#include "Interface.h"
#include "Defines.h"
#include "CChatEx.h"
#include "WindowsStruct.h"
#include "Bytes.h"

CNewFrame QTFrame;

void GLCreateWindowEx( )
{
	int FrameWin;
	int FrameWinMid;
	int FrameWinExt;
	int FrameWinCDepthBox;

	((signed int (*)())0x004D0FC0)( );
	*(float*)0xE7C3D4 = (double)(unsigned int)pWinHeight / 480.0;

	FrameWinCDepthBox = (int)(pWinWidth / pWinHeightReal - 640);
	FrameWin = (int)pWinWidth / pWinHeightReal;
	FrameWinMid = (int)pWinWidth / pWinHeightReal / 2;
	FrameWinExt = (int)pWinWidth / pWinHeightReal / 2 - 320;

	QTFrame.DisplayWinCDepthBox = (int)pWinWidth / pWinHeightReal - 640;
	QTFrame.DisplayWin = (int)pWinWidth / pWinHeightReal;
	QTFrame.DisplayWinMid = (int)pWinWidth / pWinHeightReal / 2;
	QTFrame.DisplayWinExt = (int)pWinWidth / pWinHeightReal / 2 - 320;
	QTFrame.DisplayWinReal = (int)QTFrame.DisplayWin / 640.0;
	//--
	int Win1 = (int)FrameWin - 190;					// - DisplayWin Open1;
	int Win2 = (int)FrameWin - 380;					// - DisplayWin Open2;
	int Win3 = (int)FrameWin - 570;					// - DisplayWin Open3;
	int WinC = (int)FrameWinMid - 50;					// - DisplayWin OpenCentral;
	int BoxGobil = (int)FrameWin - 380;					// - DisplayWin OpenCentral;
	//--
	SetDword(0x0059792D+1,( FrameWinMid - 30 ));			//-- Notice
	//--
	SetDword(0x0094880C+1, (FrameWinMid - 95));		//-- Box0 BuyCash
	SetDword(0x0094880C+1, (FrameWinMid - 99));		//-- Box1 BuyCash
	SetDword(0x0094A2AC+1, (FrameWinMid - 107));	//-- Box2 BuyCash
	SetDword(0x0094B4A7+1, (FrameWinMid - 95));		//-- Box3 BuyCash
	SetDword(0x0094BDCD+1, (FrameWinMid - 95));		//-- Box4 BuyCash
	SetDword(0x0094C89C+1, (FrameWinMid - 105));	//-- Box5 BuyCash
	SetDword(0x0094DA8A+1, (FrameWinMid - 105));	//-- Box6 BuyCash
	SetDword(0x0094F0EA+1, (FrameWinMid - 95));		//-- Box7 BuyCash
	SetDword(0x0094FE7C+1, (FrameWinMid - 105));	//-- Box8 BuyCash
	SetDword(0x00950934+1, (FrameWinMid - 95));		//-- Box9 BuyCash
	SetDword(0x009515B1+1, (FrameWinMid - 95));		//-- Box10 BuyCash
	SetDword(0x0085A10F+1, (FrameWinMid - 95));		//-- WindowsOption
//--
	SetDword((0x0085A6A8+1), Win1);
	SetDword((0x0085A8AE+1), Win1);
	SetDword((0x0085A92D+1), Win1);
	SetDword((0x0085A9AC+1), Win1);
	SetDword((0x0085AA2B+1), Win1);
	SetDword((0x0085AB41+1), Win1);
	SetDword((0x0085ABCF+1), Win1);
	SetDword((0x0085AD78+1), Win1);
	SetDword((0x0085AE06+1), Win1);
	SetDword((0x0085AE94+1), Win1);
	SetDword((0x0085AFB0+1), Win1);
	SetDword((0x0085B048+1), Win1);
	SetDword((0x0085B0D6+1), Win1);
	SetDword((0x0085B4D9+1), Win1);
	SetDword((0x0085B56D+1), Win1);
	SetDword((0x0085C020+1), Win1);
	SetDword((0x0085C0B4+1), Win1);
	SetDword((0x0085C270+1), Win1);
	SetDword((0x0085C4C0+1), Win1);
	SetDword((0x0085C5F2+1), Win1);
	SetDword((0x0085C686+1), Win1);
	SetDword((0x0085C71A+1), Win1);
	SetDword((0x0085C7AE+1), Win1);
	SetDword((0x0085C977+1), Win1);
	SetDword((0x007F8277+3), Win1); //-- skill helper
	//SetDword((0x0085CC36+1), Win1);
	SetDword((0x0085F78B+1), Win1);
	SetDword((0x0085F87A+1), Win1);
	SetDword((0x0085FA1A+1), Win1);
	SetDword((0x0085FA45+1), Win1);
	SetDword((0x0085FA8B+1), Win1);
	SetDword((0x0085FD25+1), Win1);
	SetDword((0x0085FE8D+1), Win1);
	SetDword((0x00860033+1), Win1);
	//--
	//
	SetDword((0x0085A731+1), Win2);
	SetDword((0x0085A7B0+1), Win2);

	SetDword((0x0085A82F+1), Win2);	// seed 

	SetDword((0x0085AAB3+1), Win2);
	SetDword((0x0085AC5F+1), Win2);
	SetDword((0x0085ACEA+1), Win2);
	SetDword((0x0085B1F5+1), Win2);
	SetDword((0x0085C148+1), Win2);
	SetDword((0x0085C1DC+1), Win2);
	SetDword((0x0085CA15+1), Win2);
	SetDword((0x0085CAA9+1), Win2);
	SetDword((0x0085CB3D+1), Win2);
	SetDword((0x0085CCCA+1), Win2);
	SetDword((0x0085ED59+1), Win2);
	SetDword((0x0085EDF7+1), Win2);
	SetDword((0x0085EE7E+1), Win2);
	SetDword((0x0085EEAB+1), Win2);
	SetDword((0x0085F0F1+1), Win2);
	SetDword((0x0085F7B6+1), Win2);
	//--
	SetDword((0x007D5953+1), Win2);
	SetDword((0x007D5997+1), Win2);//<-- Viewport
	SetDword((0x007D59BB+1), Win2);
	SetDword((0x007D59FF+2), Win2);//<-- Viewport
	SetDword((0x007D5A24+1), Win2);
	SetDword((0x007D5A68+2), Win2);//<-- Viewport
	SetDword((0x007D5A8D+1), Win2);
	SetDword((0x007D5AD1+1), Win2);//<-- Viewport
	SetDword((0x007D5AF5+1), Win2);
	SetDword((0x007D5B39+2), Win2);//<-- Viewport
	SetDword((0x007D5B5E+1), Win2);
	SetDword((0x007D5BA2+2), Win2);//<-- Viewport
	SetDword((0x007D5BC9+1), Win2);
	SetDword((0x007D5C0D+1), Win2);//<-- Viewport
	SetDword((0x007D5C59+2), Win2);//<-- Viewport
	SetDword((0x007D5C89+1), Win2);
	SetDword((0x007D5CB5+1), Win2); //-- 
	//--
	SetDword((0x00791B9A+3), BoxGobil); // box ok cancel gobil
	SetDword((0x00791C0A+3), WinC);
	SetDword((0x00792E4A+3), WinC);
	SetDword((0x00792EFA+3), WinC);
	SetDword((0x007A0C1F+3), WinC);
	SetDword((0x007A2266+3), WinC);
	SetDword((0x007A34EF+3), WinC);
	SetDword((0x007A4796+3), WinC);
	SetDword((0x007A5546+3), WinC);
	SetDword((0x007A6FF6+3), WinC);
	SetDword((0x007A81F1+3), WinC);	// Box Esc
	SetDword((0x007A8E9B+3), WinC);
	SetDword((0x007A92FB+3), WinC);
	SetDword((0x007A99DB+3), WinC);
	SetDword((0x007A9E91+3), BoxGobil);	//Box Gobil
	SetDword((0x007AAB21+3), WinC);
	SetDword((0x007AB8B9+3), WinC);
	SetDword((0x007AC5D9+3), WinC);
	SetDword((0x007AD561+3), WinC);
	SetDword((0x007ADDC1+3), WinC);
	SetDword((0x007AE601+3), WinC);
	SetDword((0x007B2681+3), WinC);
	SetDword((0x007B2FB1+3), WinC);
	SetDword((0x007B3A61+3), WinC);
	SetDword((0x007B45F1+3), WinC); // INTERFACE.CPP AND JEWELSBANK.CPP
	SetDword((0x007B52F1+3), WinC);
	SetDword((0x007B5CE1+3), WinC);
	SetDword((0x007B66CD+3), WinC);
	SetDword((0x007B7491+3), WinC);
	SetDword((0x007B8581+3), WinC);
	//-- Add Ext
	/////test
	//SetDword((0x00EBC0F4+3), WinC);
	/////main.exe+EBC0F4 


	SetDword((0x0081A5EA+1), (0x1CA+FrameWinExt));						//-- Check Masterskill tooltip
	SetDword((0x0081A652+1), (0x1DA+FrameWinExt));						//-- tooltip
	SetDword((0x0042B036+1), (0x1EA+FrameWinExt));						//TextBox(CashShop)
	SetDword((0x009448A8+2), (0xA2+FrameWinExt));						//-- Buttons(BUY)InGameShop
	SetDword((0x004D7D99+1), (0x14F+FrameWinExt));						//-- Texto Copy
	SetDword((0x004D7E1D+1), (0x14F+FrameWinExt));						//-- Texto Copy
	SetDword((0x008192C1+6), (0x0B+FrameWinExt));						//MasterSkill Tree1
	SetDword((0x008192DB+6), (0xDD+FrameWinExt));						//MasterSkill Tree2
	SetDword((0x008192F5+6), (0x1AF+FrameWinExt));						//MasterSkill Tree3
	SetDword((0x00819440+1), (0x263+FrameWinExt));						//Button Closed MasterSkill
	//-- Add resto
	
	//-----------------------TEST ILUS plate
	//SetDword((0x0037298), (0xBA+FrameWinCDepthBox));				//ISSLUS 0x00379284
	//0x0085B446

	//SetDword(0x0086E955+3, (0x3C+FrameWinCDepthBox));  //-- TEST
	//SetDword((0x0086CC72+1),(0x199+FrameWinCDepthBox) );  //-- TEST ITME
	//SetDword(0x0086EA00+3,(0x186+FrameWinCDepthBox));  //-- TEST

	//SetDword(0x00865398+3,(0xCA +FrameWinCDepthBox));

	//SetDword((0x00865398), (0xCA+WinC));
	//------------------------------------------------------

	SetDword((0x0085B445+1), (0x199+FrameWinCDepthBox));				//WarScore
	SetDword((0x0085B9EF+1), (0x1FD+FrameWinCDepthBox));				//DuelScore
	SetDword((0x0082AAAD+1), (0x265+FrameWinCDepthBox));				//-- Button Close Map
	SetDword((0x0085ECA6+1), (0x186+FrameWinCDepthBox));				//-- WindowsFriends
	SetDword((0x0085C55E+1), (0x19D+FrameWinCDepthBox));				//BloodCastleTimer
	SetDword((0x0085B3B1+1), (0x201+FrameWinCDepthBox));				//-- ChaosCastle
	SetDword((0x0085BB11+1), (0x1E6+FrameWinCDepthBox));				//-- CastleSiege
	//-- General 0x280
	SetDword((0x004D7D6F+2), (0x280+FrameWinCDepthBox));				//-- Texto Server copy
	SetDword((0x004D7D8B+2), (0x280+FrameWinCDepthBox));				//-- Texto copy
	SetDword((0x004D7E04+2), (0x280+FrameWinCDepthBox));				//-- Texto copy
	SetDword((0x004D7E8A+2), (0x280+FrameWinCDepthBox));				//-- Texto copy
	SetDword((0x004D06F4+4), (0x280+FrameWinCDepthBox));				//-- Cursor Limite
	SetDword((0x004D0700+4), (0x280+FrameWinCDepthBox));				//-- Cursor Limite
	SetDword((0x00779CCD+3), (0x280+FrameWinCDepthBox));				//-- Tooltip Limite
	SetDword((0x00635B5A+2), (0x280+FrameWinCDepthBox));				//-- PlayerDialog
	SetDword((0x006359C2+1), (0x280+FrameWinCDepthBox));				//-- ItemModel
	SetDword((0x0040F7B7+1), (0x280+FrameWinCDepthBox));				//-- Store Dialog
	SetDword((0x0048BC81+2), (0x280+FrameWinCDepthBox));				//-- friend list
	SetDword((0x0048BC8C+1), (0x280+FrameWinCDepthBox));				//-- friend list
}
//////////////////////////////////////////////////////////////////////////////////////////////
//-- WideScreen Principal
//////////////////////////////////////////////////////////////////////////////////////////////
double CNewDisplaYOpenGLW(float a1)
{
	return (float)((double) a1 * pWinHeightReal);
}

double CNewDisplaYOpenGL2W(float a1)
{
	return (float)((double) a1 * 1.25);
}

//////////////////////////////////////////////////////////////////////////////////////////////
//-- DisplaYFrame
//////////////////////////////////////////////////////////////////////////////////////////////
signed int FrameScreenWidth( )
{
	signed int v52; // [sp+0h] [bp-4h]@11

	if ( pCheckWindow((LPVOID)GetInstance( ), 13) && pCheckWindow((LPVOID)GetInstance( ), 16)
	|| pCheckWindow((LPVOID)GetInstance( ), 8)
	|| pCheckWindow((LPVOID)GetInstance( ), 12)
	|| pCheckWindow((LPVOID)GetInstance( ), 9)
	|| pCheckWindow((LPVOID)GetInstance( ), 7)
	|| pCheckWindow((LPVOID)GetInstance( ), 14)
	|| pCheckWindow((LPVOID)GetInstance( ), 15)
	|| pCheckWindow((LPVOID)GetInstance( ), 60)
	|| pCheckWindow((LPVOID)GetInstance( ), 76))
	{
		v52 = 380;
	}
	else
	{
		if ( pCheckWindow((LPVOID)GetInstance( ), 16)
			&& (pCheckWindow((LPVOID)GetInstance( ), 4)
			|| pCheckWindow((LPVOID)GetInstance( ), 69)) )
		{
			v52 = 380;
		}
		else
		{
			if ( pCheckWindow((LPVOID)GetInstance( ), 16) && pCheckWindow((LPVOID)GetInstance( ), 11) )
			{
				v52 = 380;
			}
			else
			{
				if ( pCheckWindow((LPVOID)GetInstance( ), 27) )
				{
					v52 = 380;
				}
				else
				{
					if ( pCheckWindow((LPVOID)GetInstance( ), 13)
					|| pCheckWindow((LPVOID)GetInstance( ), 16)
					|| pCheckWindow((LPVOID)GetInstance( ), 3)
					|| pCheckWindow((LPVOID)GetInstance( ), 21)
					|| pCheckWindow((LPVOID)GetInstance( ), 6)
					|| pCheckWindow((LPVOID)GetInstance( ), 22)
					|| pCheckWindow((LPVOID)GetInstance( ), 23)
					|| pCheckWindow((LPVOID)GetInstance( ), 24)
					|| pCheckWindow((LPVOID)GetInstance( ), 4)
					|| pCheckWindow((LPVOID)GetInstance( ), 18)
					|| pCheckWindow((LPVOID)GetInstance( ), 10)
					|| pCheckWindow((LPVOID)GetInstance( ), 5)
					|| pCheckWindow((LPVOID)GetInstance( ), 25)
					|| pCheckWindow((LPVOID)GetInstance( ), 26)
					|| pCheckWindow((LPVOID)GetInstance( ), 19)
					|| pCheckWindow((LPVOID)GetInstance( ), 20)
					|| pCheckWindow((LPVOID)GetInstance( ), 58)
					|| pCheckWindow((LPVOID)GetInstance( ), 59)
					|| pCheckWindow((LPVOID)GetInstance( ), 62)
					|| pCheckWindow((LPVOID)GetInstance( ), 73)
					|| pCheckWindow((LPVOID)GetInstance( ), 68)
					|| pCheckWindow((LPVOID)GetInstance( ), 69)
					|| pCheckWindow((LPVOID)GetInstance( ), 70)
					|| pCheckWindow((LPVOID)GetInstance( ), 66)
					|| pCheckWindow((LPVOID)GetInstance( ), 75)
					|| pCheckWindow((LPVOID)GetInstance( ), 74) )
					{
						v52 = 190;
					}
					else
					{
						if ( pCheckWindow((LPVOID)GetInstance( ), 79) )
						{
							if ( pCheckWindow((LPVOID)GetInstance( ), 80) )
								v52 = 380;
							else
								v52 = 190;
						}
						else
						{
							v52 = 0;
						}
					}
				}
			}
		}
	}
	if ( pCheckWindow((LPVOID)GetInstance( ), 77) )
	{
		if ( sub_7D6270(*(DWORD *)(GetInstance( ) + 300), 0) )
			v52 = 570;
		else
			v52 = 380;
	}
	else
	{
		if ( pCheckWindow((LPVOID)GetInstance( ), 78) )
			v52 = 570;
	}

	return (int)(QTFrame.DisplayWin - v52);
}

signed int FrameOpenGLWidth( )
{
	return 640;
}

signed int FrameOpenGLWidthView( )
{
	if((gInterface.CheckWindow(Inventory) || gInterface.CheckWindow(ExpandInventory) || gInterface.CheckWindow(Character)))
	{
		glColor4f(0.0, 0.0, 0.0, 0.0); 
		return 860;
	}
	else
	{
			glColor4f(0.0, 0.0, 0.0, 0.0); 
			return 1000;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////
int FrameMasterSkill(int thisa)
{
	int result; // eax@1

	*(DWORD *)(thisa + 20) = QTFrame.DisplayWinExt;
	*(DWORD *)(thisa + 24) = 0;
	*(DWORD *)(thisa + 28) = 640;
	result = thisa;
	*(DWORD *)(thisa + 32) = 428;
	return result;
}

void FrameMasterDisplay(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(id, x, y, w, 428);
}

int PaintMatrixModel(float PosX, float PosY, float Width, float Height, int ItemID, int a6, int a7, int a8, char a9)
{
	int v4; // ST10_4@1

	v4 = *(DWORD *)(GetInstance( ) + 252);

	return pDrawItemModel(PosX + *(DWORD *)(v4 + 36), PosY, Width, Height, ItemID, a6, a7, a8, a9);
}

void FrameShopDisplayBuy(float x, float y, float w, float h, float arg5, int arg6 )
{
	pDrawBarForm(x, y, (double)QTFrame.DisplayWin, h, arg5, arg6);
}

BYTE __thiscall CNewFrame::FrameHelperDisplay(int thisa, int a2, int x, int y)
{
	int DisplayFrameX;

	DisplayFrameX = QTFrame.DisplayWin - 190;

	return CNewUIMainFrameHelper(thisa, a2, DisplayFrameX, y);
}

BYTE __thiscall CNewFrame::FrameShopDisplay(int thisa, int a2, int x, int y)
{
	int DisplayFrameX;

	DisplayFrameX = x + QTFrame.DisplayWinExt;

	return InitCashShop(thisa, a2, DisplayFrameX, y);
}

int __thiscall CNewFrame::GetDisplayPosX(BYTE * thisa)
{
	*(signed int *)((int)(thisa + 4) + 0) = QTFrame.DisplayWinMid - 105;

	return (int)(thisa + 4);
}

bool CheckBannerShop(int x, int y, int w, int h)
{
	int v4; // eax@1

	v4 = *(DWORD *)(GetInstance( ) + 252);

	return pCheckMouseOver(*(DWORD *)(v4 + 36) + x, y, w, h);
}

void PaintBannerShop(int ImageID, float PosX, float PosY, float Width, float Height)
{
	int v4; // ST10_4@1

	v4 = *(DWORD *)(GetInstance( ) + 252);

	pDrawGUI(ImageID, *(DWORD *)(v4 + 36) + PosX, PosY, Width,  Height);
}

int __thiscall CNewFrame::CNewUIMainFrameOpenStore(int thisa, int PosX, int PosY, int Ext)
{
	return CNewUIMainFrameStoreMove(thisa, PosX + QTFrame.DisplayWinCDepthBox, PosY, Ext);
}

int __thiscall CNewFrame::CNewUIMainFrameOpenChaos(int thisa, int PosX, int PosY, int Ext)
{
	return CNewUIMainFrameChaosMove(thisa, PosX + QTFrame.DisplayWinCDepthBox , PosY, Ext);
}

BYTE * __thiscall CNewFrame::CNewUIMainFrameOpenShop(int thisa, int PosX, int PosY, int Ext)
{
	return CNewUIMainFrameShopMove(thisa, PosX + QTFrame.DisplayWinCDepthBox, PosY, Ext);
}

int __thiscall CNewFrame::CNewUIMainFrameOpenOtherStore(int thisa, int PosX, int PosY, int Ext)
{
	return CNewUIMainFrameOtherStoreMove(thisa, PosX + QTFrame.DisplayWinCDepthBox, PosY, Ext);
}

int __thiscall CNewFrame::CNewUIMainFrameOpenLucky(int thisa, int PosX, int PosY, int Ext)
{
	return CNewUIMainFrameLuckyMove(thisa, PosX + QTFrame.DisplayWinCDepthBox, PosY, Ext);
}

int __thiscall CNewFrame::CNewUIMainFrameOpenExt(int thisa, int PosX, int PosY)
{
	return CNewUIMainFrameInvExtMove(thisa, PosX + QTFrame.DisplayWinCDepthBox, PosY);
}

int __thiscall CNewFrame::CNewUIMainFrameOpenBault(int thisa, int PosX, int PosY, int Ext)
{
	return CNewUIMainFrameBaulMove(thisa, PosX + QTFrame.DisplayWinCDepthBox, PosY, Ext);
}

int __thiscall CNewFrame::CNewUIMainFrameOpenTrade(int thisa, int PosX, int PosY, int Ext)
{
	return CNewUIMainFrameTradeMove(thisa, PosX + QTFrame.DisplayWinCDepthBox, PosY, Ext);
}

BYTE * __thiscall CNewFrame::CNewUIMainFrameOpenBaultExt(int thisa, int PosX, int PosY)
{
	return CNewUIMainFrameBaulExtMove(thisa, PosX + QTFrame.DisplayWinCDepthBox, PosY);
}

int __thiscall CNewFrame::CNewUIMainFrameView(int thisa, int PosX, int PosY)
{
	return CNewUIMainFrameControl(thisa, PosX + QTFrame.DisplayWinCDepthBox, PosY);
}

int __thiscall CNewFrame::CNewUIMainInfoButtonGens(char *thisa, int X, int Y, int Width, int Height)
{
	return ChangeButtonInfo(thisa, X + QTFrame.DisplayWinCDepthBox, Y, Width, Height);
}

int __thiscall CNewFrame::CNewUIMainPaintFont(int thisa, int PosX, int PosY, LPCTSTR Text, int nCount, int nTabPositions, int lpnTabStopPositions, int nTabOrigin)
{
	return CNewPictureFont(thisa, PosX + QTFrame.DisplayWinExt, PosY, Text, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin);
}
//////////////////////////////////////////////////////////////////////////////////////////////
void CNewRenderSands(int Picture, float PictureX, float PictureY, float Widht, float a5, float a6, float a7, float a8, float a9)
{
	RenderBitmapUV(Picture, PictureX, PictureY, Widht + QTFrame.DisplayWinCDepthBox, 480.0, a6, a7, a8, a9);
}

void PictureMuLogo(int ImageID, float PosX, float PosY, float Width, float Height, float Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, float ScaleAlpha)
{
	RenderBitmap(ImageID,  PosX + QTFrame.DisplayWinExt, PosY, Width,  Height,  Arg6,  Arg7,  ScaleX,  ScaleY,  ScaleSize,  ScalePosition, ScaleAlpha);
}



//----- (00636480) --------------------------------------------------------
void CNewLogoPaint(GLint a1, int a2, GLsizei width, GLsizei height)
{
	float JCWinWidth; // ST04_4@3
	unsigned int x; // [sp+20h] [bp+8h]@1
	
	JCWinWidth = (double)(unsigned int)pWinWidth / 640.0;
	
	x = ( a1 * pWinWidthReal ) / JCWinWidth;
	width =  410.0 / JCWinWidth;

	JCBeginOpengl(x, a2, width, height);
}

void SeedEmpy(int ImageID, float PosX, float PosY, float Width, float Height)
{
	pDrawGUI(ImageID,  PosX + QTFrame.DisplayWinExt + 50, PosY, Width,  Height);
	glColor4f(0.0, 0.0, 0.0, 1.0); //--
}
//-------
DWORD dword_ConvertX(float a1)
{
	//return a1 * 1.25;
	return (DWORD) ( pWinWidthReal <= 1.25 ) ? a1 * pWinWidthReal : a1 * pWinHeightReal;
}
__declspec (naked) void ObjDialogBox()
{
	static DWORD main_addr = 0x00635B6C;
	static int renderWin = 0x280u;
	static int a2;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+0XC]
		MOV EAX,DWORD PTR DS:[EDX]
		MOV a2, EAX
	}

		renderWin = pWinWidth / pWinHeightReal;
		a2 = renderWin * a2 / pWinWidth;

	_asm
	{
		MOV EAX, a2
		MOV ECX,DWORD PTR SS:[EBP+0xC]
		MOV DWORD PTR DS:[ECX],EAX
		JMP[main_addr]
	}
}

__declspec (naked) void ConverCursor()
{
	static DWORD main_addr = 0x004D06B7;
	static DWORD main_call = 0x009CEBF0;

	_asm
	{
		FILD DWORD PTR SS:[EBP-0x10C4]
		FDIV DWORD PTR DS:[0xE7C3D8]
		CALL main_call
		MOV DWORD PTR DS:[0x879340C],EAX
		JMP[main_addr]
	}
}
__declspec (naked) void ConvertModelX()
{
	static DWORD main_addr = 0x006359CC;
	static DWORD ModelX;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOV ModelX, EAX
	}

	ModelX = dword_ConvertX( ModelX );

	_asm
	{
		MOV EAX,ModelX
		MOV DWORD PTR SS:[EBP+8],EAX
		JMP[main_addr]
	}
}

void CNewFrame::InitFrameOpenGL( )
{
	//-- Seed

	SetCompleteHook(0xE8, 0x00934286, &SeedEmpy);
	SetCompleteHook(0xE8, 0x00855868, &SeedEmpy);
	SetCompleteHook(0xE8, 0x0085589F, &SeedEmpy);
	SetCompleteHook(0xE8, 0x0088643F, &SeedEmpy);
	SetCompleteHook(0xE8, 0x008863F9, &SeedEmpy);
	//----
	SetCompleteHook(0xE8, 0x0040464E, &CNewLogoPaint);					//-- Print Logo

	SetCompleteHook(0xE8, 0x004D7C0D, &PictureMuLogo);					//-- Logo SelectServer
	SetCompleteHook(0xE8, 0x004D7C98, &PictureMuLogo);					//-- Logo SelectServer
	SetCompleteHook(0xE8, 0x0081AA9C, &CNewUIMainPaintFont);			//-- Texto masterskill
	SetCompleteHook(0xE8, 0x0081AA42, &CNewUIMainPaintFont);			//-- Texto masterskill
	SetCompleteHook(0xE8, 0x0081A9E8, &CNewUIMainPaintFont);			//-- Texto masterskill
	SetCompleteHook(0xE8, 0x0081A977, &CNewUIMainPaintFont);			//-- Texto masterskill
	SetCompleteHook(0xE8, 0x0081A944, &CNewUIMainPaintFont);			//-- Texto masterskill
	SetCompleteHook(0xE8, 0x0081A73D, &CNewUIMainPaintFont);			//-- Texto masterskill
	SetCompleteHook(0xE8, 0x0081A6F4, &CNewUIMainPaintFont);			//-- Texto masterskill
	//////////////////////////////////////////////////////////////////////////////////////////////
	//-- Open Windows 3
	//////////////////////////////////////////////////////////////////////////////////////////////
	SetCompleteHook(0xE8, 0x007C57B9, &CNewUIMainInfoButtonGens);		//-- Boton Gens
	SetCompleteHook(0xE8, 0x00856486, &CNewUIMainFrameOpenBaultExt);	//-- BaultExt
	SetCompleteHook(0xE8, 0x0085F1B9, &CNewUIMainFrameOpenBaultExt);	//-- BaultExt
	SetCompleteHook(0xE8, 0x007D61EF, &CNewUIMainFrameView);			//-- Trade
	SetCompleteHook(0xE8, 0x007D619E, &CNewUIMainFrameView);			//-- Trade
	SetCompleteHook(0xE8, 0x007D6150, &CNewUIMainFrameOpenTrade);		//-- Trade
	SetCompleteHook(0xE8, 0x007D6100, &CNewUIMainFrameView);			//-- Baul
	SetCompleteHook(0xE8, 0x007D60B0, &CNewUIMainFrameOpenBault);		//-- Baul
	SetCompleteHook(0xE8, 0x007D6060, &CNewUIMainFrameOpenExt);			//-- Ext
	SetCompleteHook(0xE8, 0x007D601C, &CNewUIMainFrameView);			//-- Lucky
	SetCompleteHook(0xE8, 0x007D5FCE, &CNewUIMainFrameOpenLucky);		//-- Lucky
	SetCompleteHook(0xE8, 0x007D5F7E, &CNewUIMainFrameView);			//-- OtherStore
	SetCompleteHook(0xE8, 0x007D5F30, &CNewUIMainFrameOpenOtherStore);	//-- OtherStore
	SetCompleteHook(0xE8, 0x007D5EE0, &CNewUIMainFrameView);			//-- Shop
	SetCompleteHook(0xE8, 0x007D5E92, &CNewUIMainFrameOpenShop);		//-- Shop
	SetCompleteHook(0xE8, 0x007D5E42, &CNewUIMainFrameView);			//-- Chaos
	SetCompleteHook(0xE8, 0x007D5DF4, &CNewUIMainFrameOpenChaos);		//-- Chaos
	SetCompleteHook(0xE8, 0x007D5DA4, &CNewUIMainFrameView);			//-- Store
	SetCompleteHook(0xE8, 0x007D5D56, &CNewUIMainFrameOpenStore);		//-- Store
//////////////////////////////////////////////////////////////////////////////////////////////
	//-- Init FrameWin General
	SetCompleteHook(0xE8, 0x0081A146, &FrameMasterDisplay);				//-- Letter Print
	SetCompleteHook(0xE8, 0x0081A199, &FrameMasterDisplay);				//-- Letter Print
	SetCompleteHook(0xE8, 0x00819415, &FrameMasterSkill);				//-- Letter Print
	SetCompleteHook(0xE8, 0x0085CC50, &FrameHelperDisplay);				//-- Letter Print
	SetCompleteHook(0xE8, 0x0085C446, &FrameShopDisplay);				//-- Letter Print
	SetCompleteHook(0xE8, 0x00943D7F, &PaintMatrixModel);				//-- ItemModel CashShop
	SetCompleteHook(0xE8, 0x008240A9, &FrameShopDisplayBuy);			//-- Letter Print
	SetCompleteHook(0xE8, 0x00945114, &PaintBannerShop);				//-- Model CashShop
	SetCompleteHook(0xE8, 0x00945180, &CheckBannerShop);				//-- Model CashShop
	//--
	SetCompleteHook(0xE9, 0x005C6E80, &FrameScreenWidth);
	//--
	SetCompleteHook(0xE8, 0x004D2180, &GLCreateWindowEx);				//-- Letter Print
	//--
	//////////////////////////////////////////////////////////////////////////////////////////////
	//-- Auto Scale Screen principal
	//////////////////////////////////////////////////////////////////////////////////////////////
	SetCompleteHook(0xE9, 0x00636420, &CNewDisplaYOpenGLW);
	//////////////////////////////////////////////////////////////////////////////////////////////
	//-- Paint FrameOpenGl
	//////////////////////////////////////////////////////////////////////////////////////////////
	//--
	SetDword(0x004D9746 + 3, 480); //Size Background
	SetCompleteHook(0xE8, 0x0040F2E9, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x004D714E, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x004D79E7, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x004D9756, &FrameOpenGLWidth); //-- Camara General Renderizado Live View  // FrameOpenGLWidthView
	//--
	SetCompleteHook(0xE8, 0x005DB4D5, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB1AA, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB22F, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB322, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB3A7, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB46D, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB4AD, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB534, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB5C4, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB628, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB68C, &FrameOpenGLWidth); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB6ED, &FrameOpenGLWidth); //-- Camara General Renderizado
//////////////////////////////////////////////////////////////////////////////////////////////
// Cursor Wide
//////////////////////////////////////////////////////////////////////////////////////////////
	SetCompleteHook(0xE8, 0x005B97DC,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x005B984C,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x005B9904,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x008C2E0F,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x008C2E7F,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x008CC713,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x008CC788,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x008D99B8,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x008D9A2D,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x008EF47B,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x008EF4ED,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x008EF5C5,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x008EF65A,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x00914FC9,&CNewRenderSands);
	SetCompleteHook(0xE8, 0x0091503E,&CNewRenderSands);

	//----

	SetCompleteHook(0xE9, 0x00635B55, &ObjDialogBox);   // 
	SetCompleteHook(0xE9, 0x004D06A1, &ConverCursor);   //
	//--
	SetCompleteHook(0xE9, 0x006359B6, &ConvertModelX);		//-- Model Print //
}