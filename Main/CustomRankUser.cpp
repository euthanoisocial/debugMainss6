#include "stdafx.h"
#include "Defines.h"
#include "Interface.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"
#include "HealthBar.h"
#include "Offset.h"
#include "Object.h"
#include "PrintPlayer.h"
#include "Interface.h"
#include "Import.h"
#include "GLFont.h"
#include "WindowsStruct.h"
#include "User.h"
#include "CustomRankUser.h"
#include "CustomVKR.h"
//tue add Tu Chan ////
#include "SPK_TuChan.h"
//tue Hon Hoan
#include "SPK_HonHoan.h"
////////////////////
//tue fixx
#include "InfoLog.h"
#include "Console.h"
///

CCustomRankUser::CCustomRankUser()
{
}

CCustomRankUser gCustomRankUser;
int ImgTagEx18 = 11600; //Rank Dynamic
int ImgTagEx19 = 11609; //Rank Dynamic
int ImgTagEx20 = 11618; //Rank Dynamic
int ImgTagEx40 = 631117; //Rank Dynamic
DWORD RunEffectTickTime[10] = { 0 };

void CCustomRankUser::DrawInfo()
{	
	VAngle Angle;
	// ---
	int PosX, PosY;

	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		DWORD ViewportAddress = ((DWORD(__thiscall*)(void*, DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(), n);

		ObjectPreview* Object = &*(ObjectPreview*)(ViewportAddress);

		if (!ViewportAddress)
		{
			continue;
		}

		int index = *(WORD*)(ViewportAddress + 0x7E);

		char* name = (char*)(ViewportAddress + 0x38);

		if (this->m_Data[index].m_Enabled == false)
		{
			continue;
		}

		if (*(BYTE*)(ViewportAddress + 0x30C) == 0)
		{
			continue;
		}

		if (*(BYTE*)(ViewportAddress + 0xE) == 0 && gProtect.m_MainInfo.RankUserOnlyOnSafeZone != 0)
		{
			continue;
		}

		if ((((pMapNumber)<18) ? 0 : ((pMapNumber)>23) ? (((pMapNumber) == 53) ? 1 : 0) : 1) == 1) //Disable in Chaos Castle
		{
			continue;
		}

		// ---

		Angle.X = *(float*)(ViewportAddress + 0x404);

		Angle.Y = *(float*)(ViewportAddress + 0x408);

		Angle.Z = *(float*)(ViewportAddress + 0x40C) + *(float*)(ViewportAddress + 0x3E8) + 100.0f;

		pGetPosFromAngle(&Angle, &PosX, &PosY);
		// ---
		PosX -= 42;
		//if (this->m_Data[index].m_rThueVip != 0 && !pCheckEffectPlayer((DWORD *)(ViewportAddress + 0x4EC), 28))
		//{
		//	if ((GetTickCount() - RunEffectTickTime[index]) > 500)
		//	{
		//		//32378 2.0 Type: 2 //VIP
		//		//441 Type 1
		//		//32404 Type 1 //Admin
		//		gObjUser.RenderRuneEffect((int)&Object->m_Model, 408, 1, 10, 2.0);
		//		RunEffectTickTime[index] = GetTickCount();
		//	}
		//}
		
		// ///////////////////////////////////////
		//tue add Tu Chan /////////
		////////////////////////////////////////

		//DWORD ViewportAddress = ((DWORD(__thiscall*)(void*, DWORD))0x0096A4C0)(((void* (*)())0x00402BC0)(), n);
		gObjUser.m_Logo[n].Active = 0;
		/*if (!ViewportAddress)
		{
			continue;
		}
		if (*(BYTE*)(ViewportAddress + 0x30C) == 0)
		{
			continue;
		}*/
		//Angle.X = *(float*)(ViewportAddress + 0x404);
		//Angle.Y = *(float*)(ViewportAddress + 0x408);
		//Angle.Z = *(float*)(ViewportAddress + 0x40C) + *(float*)(ViewportAddress + 0x3E8) + 100.0f;
		//pGetPosFromAngle(&Angle, &PosX, &PosY);
		if (*(BYTE*)(ViewportAddress + 0x320) == 1) //Check User Type
		{
			gObjUser.m_Logo[n].Active = 1;
			gObjUser.m_Logo[n].X = PosX;
			gObjUser.m_Logo[n].Y = PosY;
			gCustomRankUser.RenderShowLogRank(ViewportAddress, *(WORD*)(ViewportAddress + 0x7E), PosX - 42, PosY);
		}
		gCustomRankUser.RenderShowLogRank(ViewportAddress, *(WORD*)(ViewportAddress + 0x7E), PosX - 42, PosY);
		pGLSwitch();
		////////////////////////////////////////////
		if (gProtect.m_MainInfo.RankUserShowOverHead != 0)
		{
			//if (ImgTag > 600) ImgTag = 0;
			//======================================
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			
			if (MinimizarOfRank == 1)
			{
			}
			if (MinimizarOfRank == 0)
			{
				switch (this->m_Data[index].m_rDanhHieu)
				{
				case 0:
					break;
				case 1:
					RenderBitmap(10104, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 2:
					RenderBitmap(10105, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);	
					break;
				case 3:
					RenderBitmap(10106, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 4:
					RenderBitmap(10107, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 5:
					RenderBitmap(10108, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 6:
					RenderBitmap(10109, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 7:
					RenderBitmap(10110, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 8:
					RenderBitmap(10111, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 9:
					RenderBitmap(10112, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 10:
					RenderBitmap(10113, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 11:
					RenderBitmap(10114, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 12:
					RenderBitmap(10115, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 13:
					RenderBitmap(10116, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
                case 14:
					RenderBitmap(10117, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 15:
					RenderBitmap(10118, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 16:
					RenderBitmap(10119, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 17:
					RenderBitmap(10120, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 18:
					RenderBitmap(10121, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 19:
					RenderBitmap(10122, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 20:
                    RenderBitmap(10123, (float)PosX - 5.0f, (float)PosY - 63.0f, 113, 45, 0, 0, 1, 1, 1, 1, 0.0);
					break;
					pGLSwitchBlend();
				}
			}
			//======================================
			
			//

			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			if (MinimizarOfRank == 1)
			{
			}
			if (MinimizarOfRank == 0)
			{
				switch (this->m_Data[index].m_rQuanHam)
				{
				case 0:
					break;
				case 1:
					RenderBitmap(10124, (float)PosX - 18.0f, (float)PosY - 105.0f, 120, 57, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 2:
					RenderBitmap(10125, (float)PosX - 18.0f, (float)PosY - 105.0f, 120, 57, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 3:
					RenderBitmap(10126, (float)PosX - 18.0f, (float)PosY - 105.0f, 120, 57, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				
					pGLSwitchBlend();
				}
			}
			//======================================
			/*glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			if (MinimizarOfRank == 1)
			{
			}
			if (MinimizarOfRank == 0)
			{
				switch (this->m_Data[index].m_rTuLuyen)
				{
				case 0:
					break;
				case 1:
					RenderBitmap(10128, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 2:
					RenderBitmap(10129, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 3:
					RenderBitmap(10130, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 4:
					RenderBitmap(10131, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 5:
					RenderBitmap(10132, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 6:
					RenderBitmap(10133, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 7:
					RenderBitmap(10134, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 8:
					RenderBitmap(10135, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 9:
					RenderBitmap(10136, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 10:
					RenderBitmap(10137, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 11:
					RenderBitmap(10138, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 12:
					RenderBitmap(10139, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 13:
					RenderBitmap(10140, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 14:
					RenderBitmap(10141, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 15:
					RenderBitmap(10142, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 16:
					RenderBitmap(10143, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 17:
					RenderBitmap(10144, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 18:
					RenderBitmap(10145, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 19:
					RenderBitmap(10146, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 20:
					RenderBitmap(10147, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 21:
					RenderBitmap(10148, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 22:
					RenderBitmap(10149, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 23:
					RenderBitmap(10150, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 24:
					RenderBitmap(10151, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 25:
					RenderBitmap(10152, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 26:
					RenderBitmap(10153, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 27:
					RenderBitmap(10154, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 28:
					RenderBitmap(10155, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 29:
					RenderBitmap(10156, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 30:
					RenderBitmap(10157, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 31:
					RenderBitmap(10158, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 32:
					RenderBitmap(10159, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 33:
					RenderBitmap(10160, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 34:
					RenderBitmap(10161, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 35:
					RenderBitmap(10162, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 36:
					RenderBitmap(10163, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 37:
					RenderBitmap(10164, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 38:
					RenderBitmap(10165, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 39:
					RenderBitmap(10166, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;
				case 40:
					RenderBitmap(10167, (float)PosX + 17.0f, (float)PosY - 94.0f, 75, 20, 0, 0, 1, 1, 1, 1, 0.0);
					break;

					pGLSwitchBlend();
				}
			}*/
			//======================================
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			if (MinimizarOfRank == 1)
			{
			}
			if (MinimizarOfRank == 0)
			{
				//switch (this->m_Data[index].m_rThueVip)
				//{
				//case 0:
				//	break;
				//case 1:
				//	RenderBitmap(10100, (float)PosX + 22.0f, (float)PosY - 114.0f, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 2:
				//	RenderBitmap(10101, (float)PosX + 22.0f, (float)PosY - 114.0f, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 3:
				//	RenderBitmap(10102, (float)PosX + 22.0f, (float)PosY - 114.0f, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;
				//case 4:
				//	RenderBitmap(10103, (float)PosX + 22.0f, (float)PosY - 114.0f, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);
				//	break;

				//	pGLSwitchBlend();
				//}
			}

			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			if (MinimizarOfRank == 1)
			{
			}
			if (MinimizarOfRank == 0)
			{
				switch (this->m_Data[index].m_rNguHanh)
				{
				case 0:
					break;
				case 1:
		
					break;
				case 2:
					
					break;
				case 3:
					
					break;
				case 4:
					
					break;
				case 5:
					
					//RenderBitmap(500004, (float)PosX + 60.0f, (float)PosY - 33.0f, 20, 20, 0, 0, 1, 1, 1, 1, 0.0);
					
				if (ImgTagEx40 >= 631117)
			     {                                                                //  215,77
				RenderBitmap(ImgTagEx40, (float)PosX + 65.0f, (float)PosY - 33.0f, 45, 45, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx40++;
				if (ImgTagEx40 == 631176)
				{
					ImgTagEx40 = 631117;
				}
			     }

					break;

					pGLSwitchBlend();
				}
			}

			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			if (MinimizarOfRank == 1)
			{
			}
			if (MinimizarOfRank == 0)
			{
			       if(this->m_Data[index].m_iVipIcon  == 1)
					{
						pDrawImage(32891, (float)PosX + 31.5f, (float)PosY - 88.0f, 20, 20, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
					}
					else if(this->m_Data[index].m_iVipIcon == 2)
					{
						pDrawImage(32893, (float)PosX + 31.5f, (float)PosY - 88.0f, 20, 20,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
					}
					else if(this->m_Data[index].m_iVipIcon == 3)
					{
						pDrawImage(32895, (float)PosX + 31.5f, (float)PosY - 88.0f, 20, 20,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
					}

					pGLSwitchBlend();
				
			}
			// ---
			//tue fix uncomment
			//gInterface.DrawIMG(this->m_Data[index].m_Rank+1, (float)PosX+15, (float)PosY -80,1.5,1.5);
			//--
			//pDrawImage(gInterface.Data[this->m_Data[index].m_Rank + 1].ModelID, (float)PosX + 24, (float)PosY - 68, 60.0, 60.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(true);
			pGLSwitchBlend();
			pDrawImage(12359, (float)PosX + 24, (float)PosY - 118, 35.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 1.0);
			//RenderBitmap(12359, (float)PosX + 24, (float)PosY - 118, 35.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 1.0);
			pGLSwitch();
			//-------
			pGLSwitch();
			// ---
			glColor3f(1.0, 1.0, 1.0);
			//}
		}
		//tue add
		// ---
		if ((pCursorX >= PosX) && ((float)pCursorX <= (float)PosX + 50) && (pCursorY >= PosY + 20) && (pCursorY < PosY + 85))
		{

			if (gProtect.m_MainInfo.RankUserType != 4 && gProtect.m_MainInfo.RankUserShowOverHead != 0)
			{
				pSetBlend(true);

				glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
				//pDrawBarForm((float)(PosX + 2), (float)(PosY - 76), 75.0f, 10.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eGold, PosX + 7, PosY - 75, 70, 3, "%s", this->m_Data[index].szTitleRank);
				//tue fix uncomment
				//gInterface.DrawIMG(this->m_Data[index].m_Rank+1, (float)PosX+15, (float)PosY -80,1,1);
				//--
				//pDrawImage(gInterface.Data[this->m_Data[index].m_Rank + 1].ModelID, (float)PosX + 24, (float)PosY - 68, 60.0, 60.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				//pDrawImage(12359, (float)PosX + 24, (float)PosY - 68, 60.0, 60.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);


			}

			if (gProtect.m_MainInfo.RankUserNeedAltKey != 0 && !(GetKeyState(VK_MENU) & 0x8000))
			{
				continue;
			}

			pSetBlend(true);
			//tue fix uncomment
			//gInterface.DrawItem(PosX+45,PosY-30,4,4,10,SET_ITEMOPT_LEVEL(0),0,0,0);
			//tue fix uncomment
			char classename[20] = { 0 };

			//switch (this->m_Data[index].m_Classe)
			switch (gCustomRankUser.m_Data[index].m_Classe)
			{
			case 1:
				sprintf(classename, "Phu Thuy");
				break;
			case 2:
				sprintf(classename, "Phap Su");
				break;
			case 16:
				sprintf(classename, "Chien Binh");
				break;
			case 17:
				sprintf(classename, "Ky Sy");
				break;
			case 18:
				sprintf(classename, "Thien Kiem");
				break;
			case 32:
				sprintf(classename, "Tien Nu");
				break;
			case 33:
				sprintf(classename, "Thanh Nu");
				break;
			case 34:
				sprintf(classename, "Thien Nu");
				break;
			case 48:
				sprintf(classename, "Đau Sy");
				break;
			case 50:
				sprintf(classename, "Thien Tuong");
				break;
			case 64:
				sprintf(classename, "Chua Te");
				break;
			case 66:
				sprintf(classename, "Thien Vuong");
				break;
			case 80:
				sprintf(classename, "Thiet Binh");
				break;
			case 81:
				sprintf(classename, "Quyen Vuong");
				break;
			case 82:
				sprintf(classename, "Thuong Thu");
				break;
			case 96:
				sprintf(classename, "Thanh Ky Sy");
				break;
			case 98:
				sprintf(classename, "Thuat Sy");
				break;
			default:
				sprintf(classename, "Phu Thuy");
				break;
			}

			if (gProtect.m_MainInfo.RankUserType == 2)
			{
				glColor4f(0.0, 0.0, 0.0, 0.8);
				pDrawBarForm((float)(PosX + 40), (float)(PosY - 8), 135.0f, 80.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eRed2, PosX + 60, PosY - 4, 90, 3, "Rank: %s", this->m_Data[index].szTitleRank);

				this->DrawFormat(eWhite, PosX + 60, PosY + 8, 15, 1, "Lvl:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 18, 15, 1, "Str:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 28, 15, 1, "Agi:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 38, 15, 1, "Vit:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 48, 15, 1, "Ene:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 58, 15, 1, "Com:");

				this->DrawFormat(eGold, PosX + 80, PosY + 8, 45, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold, PosX + 80, PosY + 18, 45, 1, "%d ", this->m_Data[index].m_For);
				this->DrawFormat(eGold, PosX + 80, PosY + 28, 45, 1, "%d ", this->m_Data[index].m_Agi);
				this->DrawFormat(eGold, PosX + 80, PosY + 38, 45, 1, "%d ", this->m_Data[index].m_Vit);
				this->DrawFormat(eGold, PosX + 80, PosY + 48, 45, 1, "%d ", this->m_Data[index].m_Ene);
				this->DrawFormat(eGold, PosX + 80, PosY + 58, 45, 1, "%d ", this->m_Data[index].m_Com);

				int posM = 0;

				if (gProtect.m_MainInfo.RankUserShowReset != 0)
				{
					this->DrawFormat(eWhite, PosX + 120, PosY + 8, 25, 1, "Resets:");
					this->DrawFormat(eGold, PosX + 147, PosY + 8, 37, 1, "%d", this->m_Data[index].m_Resets);
				}
				else
				{
					posM -= 10;
				}

				if (gProtect.m_MainInfo.RankUserShowMasterReset != 0)
				{
					this->DrawFormat(eWhite, PosX + 120, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
					this->DrawFormat(eGold, PosX + 147, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
				}
				else
				{
					posM -= 10;
				}

				this->DrawFormat(eWhite, PosX + 120, PosY + 28 + posM, 25, 1, "Kills:");
				this->DrawFormat(eWhite, PosX + 120, PosY + 38 + posM, 25, 1, "Deaths:");
				this->DrawFormat(eGold, PosX + 147, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
				this->DrawFormat(eGold, PosX + 147, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

				this->DrawFormat(eAncient, PosX + 120, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
				this->DrawFormat(eOrange, PosX + 120, PosY + 58 + posM, 60, 1, "%s", classename);

			}
			else if (gProtect.m_MainInfo.RankUserType == 1)
			{

				glColor4f(0.0, 0.0, 0.0, 0.8);
				pDrawBarForm((float)(PosX + 40), (float)(PosY - 8), 120.0f, 80.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eWhite, PosX + 50, PosY - 2, 15, 1, "Lvl:");

				int posM = 0;

				if (gProtect.m_MainInfo.RankUserShowReset != 0)
				{
					this->DrawFormat(eWhite, PosX + 50, PosY + 8, 25, 1, "Resets:");
					this->DrawFormat(eGold, PosX + 87, PosY + 8, 37, 1, "%d", this->m_Data[index].m_Resets);
				}
				else
				{
					posM -= 10;
				}

				if (gProtect.m_MainInfo.RankUserShowMasterReset != 0)
				{
					this->DrawFormat(eWhite, PosX + 50, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
					this->DrawFormat(eGold, PosX + 87, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
				}
				else
				{
					posM -= 10;
				}

				this->DrawFormat(eWhite, PosX + 50, PosY + 28 + posM, 25, 1, "Kills:");
				this->DrawFormat(eWhite, PosX + 50, PosY + 38 + posM, 25, 1, "Deaths:");

				this->DrawFormat(eGold, PosX + 87, PosY - 2, 45, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold, PosX + 87, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
				this->DrawFormat(eGold, PosX + 87, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

				this->DrawFormat(eAncient, PosX + 50, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
				this->DrawFormat(eOrange, PosX + 50, PosY + 58 + posM, 60, 1, "%s", classename);

				this->DrawFormat(eGold, PosX + 100, PosY - 5, 70, 3, "%s", this->m_Data[index].szTitleRank);
				this->DrawFormat(eGold, PosX + 100, PosY + 59, 70, 3, "%s", name);

				gInterface.DrawIMG(this->m_Data[index].m_Rank + 1, PosX + 110, PosY + 9, 1, 1);
			}
			else if (gProtect.m_MainInfo.RankUserType == 3)
			{

				glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
				pDrawBarForm((float)(PosX + 40), (float)(PosY - 5), 100.0f, 125.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eSocket, PosX + 20, PosY - 4, 80, 3, "Thông tin: ");
				this->DrawFormat(eWhite, PosX + 50, PosY + 8, 15, 1, "Level:");

				int posM = 0;

				//tue add
				this->DrawFormat(eRed2, PosX + 60, PosY - 4, 90, 3, "%s", this->m_Data[index].szTitleRank);
				//this->DrawFormat(eWhite, PosX + 60, PosY + 8, 15, 1, "Lvl:");
				this->DrawFormat(eWhite, PosX + 50, PosY + 18, 15, 1, "Str:");
				this->DrawFormat(eWhite, PosX + 50, PosY + 28, 15, 1, "Agi:");
				this->DrawFormat(eWhite, PosX + 50, PosY + 38, 15, 1, "Vit:");
				this->DrawFormat(eWhite, PosX + 50, PosY + 48, 15, 1, "Ene:");
				this->DrawFormat(eWhite, PosX + 50, PosY + 58, 15, 1, "Com:");

				//this->DrawFormat(eGold, PosX + 80, PosY + 8, 45, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold, PosX + 80, PosY + 18, 45, 1, "%s%d", "XX/", this->m_Data[index].m_For);
				this->DrawFormat(eGold, PosX + 80, PosY + 28, 45, 1, "%s%d", "XX/", this->m_Data[index].m_Agi);
				this->DrawFormat(eGold, PosX + 80, PosY + 38, 45, 1, "%s%d", "XX/", this->m_Data[index].m_Vit);
				this->DrawFormat(eGold, PosX + 80, PosY + 48, 45, 1, "%s%d", "XX/", this->m_Data[index].m_Ene);
				this->DrawFormat(eGold, PosX + 80, PosY + 58, 45, 1, "%s%d", "XX/", this->m_Data[index].m_Com);
				/*

				this->DrawFormat(eGold, PosX + 80, PosY + 18, 45, 1, "%d ", this->m_Data[index].m_For);
				this->DrawFormat(eGold, PosX + 80, PosY + 28, 45, 1, "%d ", this->m_Data[index].m_Agi);
				this->DrawFormat(eGold, PosX + 80, PosY + 38, 45, 1, "%d ", this->m_Data[index].m_Vit);
				this->DrawFormat(eGold, PosX + 80, PosY + 48, 45, 1, "%d ", this->m_Data[index].m_Ene);
				this->DrawFormat(eGold, PosX + 80, PosY + 58, 45, 1, "%d ", this->m_Data[index].m_Com);
				*/
				//-----
				if (gProtect.m_MainInfo.RankUserShowReset != 0)
				{
					this->DrawFormat(eWhite, PosX + 50, PosY + 68, 25, 1, "Reset:");
					this->DrawFormat(eGold, PosX + 87, PosY + 68, 37, 1, "XX/%d", this->m_Data[index].m_Resets);
					//this->DrawFormat(eGold, PosX + 87, PosY + 18, 37, 1, "Khong biet");
				}
				else
				{
					posM -= 10;
				}

				if (gProtect.m_MainInfo.RankUserShowMasterReset != 0)
				{
					this->DrawFormat(eWhite, PosX + 50, PosY + 78 + posM, 25, 1, gCustomMessage.GetMessage(68));
					this->DrawFormat(eGold, PosX + 87, PosY + 78 + posM, 37, 1, "XX/%d", this->m_Data[index].m_MResets);
					//this->DrawFormat(eGold, PosX + 87, PosY + 28 + posM, 37, 1, "Khong biet");
				}
				else
				{
					posM -= 10;
				}

				this->DrawFormat(eWhite, PosX + 50, PosY + 88 + posM, 35, 1, "Diet Quai:");
				this->DrawFormat(eWhite, PosX + 50, PosY + 98 + posM, 25, 1, "SL Chet:");

				this->DrawFormat(eGold, PosX + 87, PosY + 8, 45, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold, PosX + 87, PosY + 88 + posM, 37, 1, "XX/%d", this->m_Data[index].m_Kills);
				this->DrawFormat(eGold, PosX + 87, PosY + 98 + posM, 37, 1, "XX/%d", this->m_Data[index].m_Deads);
				//this->DrawFormat(eGold, PosX + 87, PosY + 38 + posM, 37, 1, "Khong biet");
				//this->DrawFormat(eGold, PosX + 87, PosY + 48 + posM, 37, 1, "Khong biet");

				//this->DrawFormat(eAncient, PosX + 50, PosY + 58 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
				this->DrawFormat(eAncient, PosX + 50, PosY + 108 + posM, 60, 1, "VIP: XX/%d", this->m_Data[index].m_iVipIcon);
				//this->DrawFormat(eOrange, PosX + 50, PosY + 68 + posM, 60, 1, "%s", classename);
			}
			else if (gProtect.m_MainInfo.RankUserType == 4)
			{

				glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
				pDrawBarForm((float)(PosX + 2), (float)(PosY - 76), 75.0f, 10.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eGold, PosX + 7, PosY - 75, 70, 3, "%s", this->m_Data[index].szTitleRank);

				pDrawImage(gInterface.Data[this->m_Data[index].m_Rank + 1].ModelID, (float)PosX + 24, (float)PosY - 68, 60.0, 60.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			}
			else
			{
				glColor4f(0.0, 0.0, 0.0, 0.8);
				pDrawBarForm((float)(PosX + 40), (float)(PosY - 8), 185.0f, 80.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eSocket, PosX + 20, PosY - 6, 105, 3, "Thông tin NV:");

				this->DrawFormat(eWhite, PosX + 60, PosY + 8, 30, 1, "C.Do:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 18, 30, 1, "S.Manh:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 28, 30, 1, "N.Nhen:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 38, 30, 1, "The Luc:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 48, 30, 1, "N.Luong:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 58, 30, 1, "Lanh dao:");
				//
				this->DrawFormat(eWhite, PosX + 60, PosY + 88, 30, 1, "Tu Luyen SPK:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 98, 30, 1, "Ngu Hanh:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 108, 30, 1, "Tu Luyen2:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 118, 30, 1, "Quan Ham:");
				this->DrawFormat(eWhite, PosX + 60, PosY + 128, 30, 1, "Danh Hieu:");

				this->DrawFormat(eGold, PosX + 90, PosY + 8, 65, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold, PosX + 90, PosY + 18, 65, 1, "%d ", this->m_Data[index].m_For);
				this->DrawFormat(eGold, PosX + 90, PosY + 28, 65, 1, "%d ", this->m_Data[index].m_Agi);
				this->DrawFormat(eGold, PosX + 90, PosY + 38, 65, 1, "%d ", this->m_Data[index].m_Vit);
				this->DrawFormat(eGold, PosX + 90, PosY + 48, 65, 1, "%d ", this->m_Data[index].m_Ene);
				this->DrawFormat(eGold, PosX + 90, PosY + 58, 65, 1, "%d ", this->m_Data[index].m_Com);
				//
				this->DrawFormat(eGold, PosX + 90, PosY + 88, 65, 1, "%d ", this->m_Data[index].m_rRankTitle3);
				this->DrawFormat(eGold, PosX + 90, PosY + 98, 65, 1, "%d ", this->m_Data[index].m_rNguHanh);
				this->DrawFormat(eGold, PosX + 90, PosY + 108, 65, 1, "%d ", this->m_Data[index].m_rTuLuyen);
				this->DrawFormat(eGold, PosX + 90, PosY + 118, 65, 1, "%d ", this->m_Data[index].m_rQuanHam);
				this->DrawFormat(eGold, PosX + 90, PosY + 128, 65, 1, "%d ", this->m_Data[index].m_rDanhHieu);
				

				int posM = 0;

				if (gProtect.m_MainInfo.RankUserShowReset != 0)
				{
					this->DrawFormat(eWhite, PosX + 120, PosY + 8, 25, 1, "Reset:");
					this->DrawFormat(eGold, PosX + 147, PosY + 8, 37, 1, "%d", this->m_Data[index].m_Resets);
				}
				else
				{
					posM -= 10;
				}

				if (gProtect.m_MainInfo.RankUserShowMasterReset != 0)
				{
					this->DrawFormat(eWhite, PosX + 120, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
					this->DrawFormat(eGold, PosX + 147, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
				}
				else
				{
					posM -= 10;
				}

				this->DrawFormat(eWhite, PosX + 120, PosY + 28 + posM, 25, 1, "Da Kill:");
				this->DrawFormat(eWhite, PosX + 120, PosY + 38 + posM, 25, 1, "Da Die:");
				this->DrawFormat(eGold, PosX + 147, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
				this->DrawFormat(eGold, PosX + 147, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

				this->DrawFormat(eAncient, PosX + 120, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
				this->DrawFormat(eOrange, PosX + 120, PosY + 58 + posM, 60, 1, "%s", classename);

				this->DrawFormat(eGold, PosX + 133, PosY - 5, 126, 3, "%s", this->m_Data[index].szTitleRank);
				this->DrawFormat(eGold, PosX + 133, PosY + 59, 126, 3, "%s", name);

				//gInterface.DrawIMG(this->m_Data[index].m_Rank + 1, PosX + 170, PosY + 9, 1, 1);
				//gInterface.DrawIMG(this->m_Data[index].m_Rank+1, (float)PosX+15, (float)PosY -80,1,1);
				//pDrawImage(gInterface.Data[this->m_Data[index].m_Rank + 1].ModelID, (float)PosX + 24, (float)PosY - 68, 60.0, 60.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				//tue fixx scale img
				//pDrawImage(gInterface.Data[this->m_Data[index].m_Rank + 1].ModelID, PosX + 170, PosY + 9, 60.0, 60.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				//glColor3f(1.0, 1.0, 1.0);
				//pSetBlend(true);
				//pGLSwitchBlend();
				//pDrawImage(12359, (float)PosX + 24, (float)PosY - 118, 35.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 1.0);
				//RenderBitmap(12359, (float)PosX + 24, (float)PosY - 118, 35.0, 35.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 1.0);
				
				//gInterface.DrawIMG(this->m_Data[index].m_Rank + 1, (float)PosX + 24, (float)PosY - 68, 1, 1);
				gInterface.DrawGUI3(this->m_Data[index].m_Rank + 1, PosX + 170, PosY + 9, 1, 1);
				RenderBitmap(eImgHonHoan + this->m_Data[index].m_rNguHanh, PosX + 170, PosY + 89, 100, 100, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				//vẽ img tren đầu n.vật
				//pDrawImage(gInterface.Data[this->m_Data[index].m_Rank + 1].ModelID, PosX + 170, PosY + 9, 60.0, 60.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 1.0);
				//pGLSwitch();
				//-------
				//pGLSwitch();
				//glColor3f(1.0, 1.0, 1.0);
				//----end fixx
			}


		}
		else
		{
		}
		//end add fix------------------
	}
}

int CCustomRankUser::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048] = {0};
	// ---
	int BuffLen = sizeof(Buff)-1;
	// ---
	ZeroMemory(Buff, BuffLen);
	// ---
	va_list args;
	// ---
	va_start(args, Text);
	// ---
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	// ---
	va_end(args);
	// ---
	int LineCount = 0;
	// ---
	char * Line = strtok(Buff, "\n");
	// ---
	while(Line != NULL)
	{
		pDrawColorText(Line, PosX, PosY, Width, 5, Color, 9, Align);
		// ---
		PosY += 10;
		// ---
		Line = strtok(NULL, "\n");
	}
	// ---
	return PosY;
}

void CCustomRankUser::Test() // OK
{
	((void(*)())0x00576E40)();
	// ---
	gCustomRankUser.DrawInfo();
	// ---
	int PosX, PosY, LifeProgress, ShieldProgress;
	// ---
	float LifeBarWidth = 38.0f;
	// ---
	char LifeDisplay[20];
	// ---
	VAngle Angle;
	// --
	CPreviewManager * gPreview = new CPreviewManager;

	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{

		gPreview->ObjSelect(n, pObjPreviewThis); // -> Coletar Informações da ObjPreview

		DWORD ViewportAddress = ((DWORD(__thiscall*)(void*,DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(),n);

		if(!ViewportAddress)
		{
			continue;
		}


		if(*(BYTE*)(ViewportAddress+0x268) == 0 || *(BYTE*)(ViewportAddress+0x0E) == 1)
		{
			continue;
		}
	}
}
void CCustomRankUser::GCReqRankLevelUser(PMSG_CUSTOM_RANKUSER * aRecv)
{
	if(aRecv == NULL)
	{
		return;
	}
	
	// ---
	this->m_Data[aRecv->iIndex].m_Enabled = true;
	this->m_Data[aRecv->iIndex].m_Level = aRecv->iLevel;
	this->m_Data[aRecv->iIndex].m_Resets = aRecv->iReset;
	this->m_Data[aRecv->iIndex].m_MResets = aRecv->iMReset;
	this->m_Data[aRecv->iIndex].m_Kills = aRecv->iKills;
	this->m_Data[aRecv->iIndex].m_Deads = aRecv->iDeads;
	this->m_Data[aRecv->iIndex].m_For = aRecv->iFor;
	this->m_Data[aRecv->iIndex].m_Agi = aRecv->iAgi;	
	this->m_Data[aRecv->iIndex].m_Ene = aRecv->iEne;
	this->m_Data[aRecv->iIndex].m_Vit = aRecv->iVit;
	this->m_Data[aRecv->iIndex].m_Com = aRecv->iCom;
	this->m_Data[aRecv->iIndex].m_Classe = aRecv->iClasse;
	this->m_Data[aRecv->iIndex].m_Rank = aRecv->iRank;
	// ---
	this->m_Data[aRecv->iIndex].m_rDanhHieu = aRecv->irDanhHieu;
	this->m_Data[aRecv->iIndex].m_rQuanHam = aRecv->irQuanHam;
	//this->m_Data[aRecv->iIndex].m_rTuLuyen = aRecv->irTuLuyen;
	this->m_Data[aRecv->iIndex].m_rTuLuyen = aRecv->irTuLuyen;
	this->m_Data[aRecv->iIndex].m_rThueVip = aRecv->irThueVip;
	this->m_Data[aRecv->iIndex].m_rNguHanh = aRecv->irNguHanh;
	//this->m_Data[aRecv->iIndex].m_rNguHanh = 5;
	this->m_Data[aRecv->iIndex].m_iVipIcon = aRecv->iVipIcon;
	// ---
	//tue add Tu Chan /////////////////////////////////
	//this->m_Data[aRecv->iIndex].m_RankTitle1 = aRecv->m_RankTitle1;
	#if SPK_QUANHAM
		//this->m_Data[aRecv->iIndex].m_RankTitle2 = aRecv->m_RankTitle2;
	#endif
	#if SPK_TUCHAN
		this->m_Data[aRecv->iIndex].m_rRankTitle3 = aRecv->irRankTitle3;
		//gInfoLog.Output(LOG_CHAT, "Gia tri cua irRankTitle3 gui ve là %d", aRecv->irRankTitle3);
		g_Console.AddMessage(5, "Gia tri cua irRankTitle3 gui ve là %d", aRecv->irRankTitle3);
		
		
	#endif
	#if SPK_NEWVIP
		//this->m_Data[aRecv->iIndex].m_RankTitle4 = aRecv->m_RankTitle4;
	#endif
	#if SPK_HONHOAN
		//this->m_Data[aRecv->iIndex].m_RankTitle5 = aRecv->m_RankTitle5;
	#endif
	#if HT_THUE_FLAG
		this->m_Data[aRecv->iIndex].m_RankTitle6 = aRecv->m_RankTitle6;
	#endif
	///////////////////////////////////////////////////
	memcpy(this->m_Data[aRecv->iIndex].szTitleRank, aRecv->szName, sizeof(this->m_Data[aRecv->iIndex].szTitleRank));
	memcpy(this->m_Data[aRecv->iIndex].m_Vip, aRecv->iVip, sizeof(this->m_Data[aRecv->iIndex].m_Vip));
}

bool CPreviewManager::ObjCheck(int index, int pThis)
{
	if(pThis == NULL)
	{
		return false;
	}
	// ---
	if(!CS_GET_STRUCT(index, pThis))
	{
		return false;
	}
	// ---
	return true;
}

bool CPreviewManager::ObjSelect(int index, int pThis)
{
	if(pThis == NULL)
	{
		return false;
	}
	// ---
	this->Index = *(WORD*)(CS_GET_STRUCT(index, pThis) + 86);
	this->Live = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 616);
	this->Type = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 634);
	this->IsSafeZone = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 14);
	// ---
	this->Angle.X = *(float*)(CS_GET_STRUCT(index, pThis) + 864);
	this->Angle.Y = *(float*)(CS_GET_STRUCT(index, pThis) + 868);
	this->Angle.Z = *(float*)(CS_GET_STRUCT(index, pThis) + 872) + *(float*)(CS_GET_STRUCT(index, pThis) + 836) + 100.0f;
	// ---
	return true;
}
//tue add Tu Chan ///////////////
void CCustomRankUser::RenderShowLogRank(DWORD ViewPortAddr, int index, int PosX, int PosY)
{
	if (*(BYTE*)(ViewPortAddr + 0xE) == 0 && gProtect.m_MainInfo.RankUserOnlyOnSafeZone != 0)
	{
		return;
	}
	if ((((pMapNumber) < 18) ? 0 : ((pMapNumber) > 23) ? (((pMapNumber) == 53) ? 1 : 0) : 1) == 1) //Disable in Chaos Castle
	{
		return;
	}
	if (gProtect.m_MainInfo.RankUserShowOverHead != 0 || *(int*)0x0E609E8 == 4)
	{
		pSetBlend(true);
		glColor3f(1.0, 1.0, 1.0);
		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
	}
#if SPK_TUCHAN
	gTuLuyen.ShowTuLuyenSPK(index, PosX, PosY);
#endif
	//if (MinimizarOfRank == 0)
	{
#if SPK_DANHHIEU
		//gDanhHieu.ShowDanhHieuSPK(index, PosX, PosY);
#endif
#if SPK_QUANHAM
		//gQuanHam.ShowQuanHamSPK(index, PosX, PosY);
#endif

#if SPK_NEWVIP
		//gNewVip.ShowNewVipSPK(index, PosX, PosY);
#endif
	}
}
/////////////////////////////////
