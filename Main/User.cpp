#include "stdafx.h"
#include "CustomNpcName.h"
#include "Offset.h"
#include "User.h"
#include "TMemory.h"
#include "Interface.h"
#include "Protocol.h"
#include "Object.h"
#include "Import.h"
#include "Defines.h"
#include "Util.h"
#include "User.h"
#include "PrintPlayer.h"
#include "Camera.h"
#include "ServerInfo.h"
#include "Common.h"
#include "CustomPetEffect.h"
#include "HealthBar.h"
#include "WideScreen.h"
#include "CustomRankUser.h"
#include "HuyHieuCuongHoa.h"
#include "CustomVKR.h"
#include "CustomCuongHoaWing.h"
#include "Other.h"

User gObjUser;

DWORD LastTime = 0;

void User::Load()
{
	#if(DEV_DAMAGE_TABLE)
	this->m_SecondDamageMax = 0;
	this->m_SecondDamage = 0;
	this->m_SecondDefence = 0;
	this->m_SecondReflect = 0;
	#endif
	this->m_TargetUpdateTick	= 0;
	this->m_TargetType			= false;
	this->m_CursorX				= -1;
	this->m_CursorY				= -1;
	this->m_MapNumber			= -1;
	//Auto Move
	this->IsSendMove = 0;
	this->MoveToX = 0;
	this->MoveToY = 0;
	this->KhongDiDuoc = 0;
	//===========================
	this->m_QuestStat			= 0;
	ZeroMemory(this->m_reset_item_check, sizeof(this->m_reset_item_check));

	SetCompleteHook(0xFF, 0x0077F822, &this->ChangeCharInfo);

	SetCompleteHook(0xFF, 0x00520ECF, &this->GetMapName);
	SetCompleteHook(0xFF, 0x00520F1F, &this->GetMapName);
	SetCompleteHook(0xFF, 0x0063E743, &this->GetMapName);
	SetCompleteHook(0xFF, 0x00640EB2, &this->GetMapName);
	SetCompleteHook(0xFF, 0x007D2DD9, &this->GetMapName);
	SetCompleteHook(0xFF, 0x007E6C0F, &this->GetMapName);
	SetCompleteHook(0xFF, 0x0084AEF7, &this->GetMapName);
	//==========

	SetOp((LPVOID)0x0057D513, (LPVOID)this->ShowModelBMD, ASM::CALL); //An NHan Vat
	SetOp((LPVOID)0x0057D4FF, (LPVOID)this->ShowModelBMD, ASM::CALL);//An NHan Vat

	SetOp((LPVOID)0x00588511, (LPVOID)User::HoolCreateManyFlay, ASM::CALL);

}
#define preturnModel						((bool(__cdecl*)(int a1, int a2, int a3)) 0x0056F210)
bool User::ShowModelBMD(int a1, int a2, int a3) //An Nguoi Choi OK
{
	int result; // eax

	if (DisablePlayer == 1 && pPlayerState == 5 && oUserPreviewStruct != a1 && (*(BYTE *)(a2 + 24) == 1))
		result = 0;
	else
		result = preturnModel(a1, a2, a3);
	return result;
}

void User::ToggleAuto() {


	if((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000)
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	this->is_auto = !this->is_auto;
}

void User::ToggleAutoTron() {


	if((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000)
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	this->is_autotron = !this->is_autotron;
}

void User::Refresh()
{
	
	this->lpPlayer			= &*(ObjectCharacter*)oUserObjectStruct;
	this->lpViewPlayer		= &*(ObjectPreview*)oUserPreviewStruct;
	this->GetTarget();

	this->m_CursorX			= pCursorX;
	this->m_CursorY			= pCursorY;
	this->m_MapNumber		= pMapNumber;

	if (pMapNumber == 62)
	{
		//gInterface.DrawMessage(1, "Camera Restore [DEFAULT]");
		gCamera.Restore();
	}

	this->CoordenadaX = this->lpViewPlayer->MapPosX;
	this->CoordenadaY = this->lpViewPlayer->MapPosY;
	this->getLevel = gObjUser.lpPlayer->Level;
	this->GetPet = this->lpViewPlayer->PetSlot;


	this->InSafeZone = this->lpViewPlayer->InSafeZone;

	sprintf(this->getName,"%s",gObjUser.lpPlayer->Name);

	if ( gObjUser.GetActiveSkill() == 261 || 
		gObjUser.GetActiveSkill() == 552 || 
		gObjUser.GetActiveSkill() == 555 )
	{
		SetDouble(&pFrameSpeed1, 0.0004000);
		SetDouble(&pFrameSpeed2, 0.0002000);
	}
	else
	{
		SetDouble(&pFrameSpeed1, 0.0040000);
		SetDouble(&pFrameSpeed2, 0.0020000);
	}

	if (this->is_autotron != 1 && this->is_auto == 1) 
	{
		SetByte((PVOID)0x08793383, 1);

		gInterface.DrawFormat(eBlue, 5,100, 200, 1,gOther.TextVN_KepChuot[0]);
			
		gInterface.DrawFormat(eBlue,  5,110, 100, 1,gOther.TextVN_KepChuot[1]);
		
		gInterface.DrawFormat(eYellow,  5,120, 200, 1,gOther.TextVN_KepChuot[2]);
	}

	if (this->is_autotron == 1 && this->is_auto == 1) {
			SetByte((PVOID)0x08793383, 1);

			gInterface.DrawFormat(eBlue, 5,100, 200, 1,gOther.TextVN_KepChuot[0]);
			
			gInterface.DrawFormat(eBlue,  5,110, 100, 1,gOther.TextVN_KepChuot[1]);
			
			gInterface.DrawFormat(eExcellent,  5,120, 200, 1,gOther.TextVN_KepChuot[3]);


          pCursorX = (int)pWinWidth / pWinWidthReal / 2;
          pCursorY = (int)pWinHeight / pWinHeightReal / 2.1;

          int radius;
         
          (*(float*)gCamera.m_Address.Zoom <= 50)?radius = 120 -(*(float*)gCamera.m_Address.Zoom): (*(float*)gCamera.m_Address.Zoom >= 56)?radius = 120 -(*(float*)gCamera.m_Address.Zoom):radius = 110;

          int alpha = 100;
          static double angle = 0;
          angle += 0.1;  // or some other value.  Higher numbers = circles faster
         
          int Rand = rand() % 100;
          double x;
          double y;
          //(Rand % 2 == 0)?
          ////ve hinh tron
          x = cos(angle) * radius;
          y = sin(angle) * radius;
          ////:(Rand % 3 == 0)?
          //// //ve bong hoa
          //// x = (radius - alpha) * (2+sin(radius*angle)) * cos(angle),
          //// y = (radius - alpha) * (2+sin(radius*angle)) * sin(angle)
          //:
          //ve so 8
          /* x = (cos(angle) * sin(angle)  * radius) * (cos(angle) * cos(angle));
          y = (sin(angle) * cos(angle)  * radius) * (sin(angle) * sin(angle));*/
          pCursorX -= x;
          pCursorY -= y;

			// gInterface.DrawFormat(eGold, pCursorX+20,pCursorY, 200, 1,gCustomMessage.GetMessage(85));
			//
			//gInterface.DrawFormat(eGold,  pCursorX+20,pCursorY+15, 100, 1,"END: Táº¯t Auto");
			//
			//gInterface.DrawFormat(eExcellent,  pCursorX+20,pCursorY+30, 200, 1,"INSERT: Tá»± xoay [ON]");
	}

	if (gProtect.m_MainInfo.AntiHackOnOff == 1)
	{
		if (GetModuleHandle(gProtect.m_MainInfo.HackName) == 0)
		{
			ExitProcess(100); // 5 giây
		}
	}
}

bool User::GetTarget()
{
	if( pViewNPCTargetID != -1 )
	{
		this->lpViewTarget	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), pViewNPCTargetID);

		this->m_TargetType	= 1;
		return true;
	}
	else if( pViewAttackTargetID != -1 )
	{
		this->lpViewTarget	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), pViewAttackTargetID);
		this->m_TargetType	= 2;
		return true;
	}
	
	if( this->lpViewTarget != 0 )
	{
		ZeroMemory(&this->lpViewTarget, sizeof(this->lpViewTarget));
	}
	
	this->m_TargetType = 0;
	return false;
}

int User::GetActiveSkill()
{
 lpCharObj lpPlayer  = &*(ObjectCharacter*)*(int*)(MAIN_CHARACTER_STRUCT);
 lpViewObj lpViewPlayer  = &*(ObjectPreview*)*(int*)(MAIN_VIEWPORT_STRUCT);
 return lpPlayer->pMagicList[lpViewPlayer->ActiveMagic];
}


void User::SetEventEffect(int PreviewStruct)
{

	lpViewObj lpPreview = &*(ObjectPreview*)PreviewStruct;

	if(lpPreview)
	{
		if(*(DWORD*)(MAIN_SCREEN_STATE) == GameProcess)
		{
			if (lpPreview->m_Model.ObjectType == emPlayer)
			{
				VAngle Angle;
				int PosX;
				int PosY;

				Angle.X = *(float*)(PreviewStruct+0x404);

				Angle.Y = *(float*)(PreviewStruct+0x408);

				Angle.Z = *(float*)(PreviewStruct+0x40C) + *(float*)(PreviewStruct+0x3E8) + 100.0f;

				pGetPosFromAngle(&Angle, &PosX, &PosY);

				gObjUser.Refresh();

			//	if(gCustomRankUser.m_Data[lpPreview->aIndex].m_iVipIcon  >= 3)
			//{
			//	lpPreview->Unknown23 = 5;
			//		
			//}
			
			
			}
		}
	}

	// ----
	if( lpPreview->CtlCode == 32 )
	{
		if( *(DWORD*)(PreviewStruct + 672) && lpPreview->Unknown23 !=5 )
		{
			pInitEventStatus(PreviewStruct);
		}
		// ----
		lpPreview->Unknown23 = 5;
	}
	// ----
	if( *(DWORD*)(PreviewStruct + 672) != 0 || !lpPreview->Unknown23 )
	{
		return;
	}
	// ----
	switch(lpPreview->Unknown23)
	{
	case 5:	//-> GM
		{
			//if( pEventEffectThis(668) )
			//{
			//	DWORD ModelID = 349;
			//	if(gCustomRankUser.m_Data[lpPreview->aIndex].m_iVipIcon  >= 3 )
			//        {
			//			
			//			ModelID = 408;
			//			
			//	    }
			//	*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect(pEventEffectThis(668), ModelID, 20, 8, 430.0, -5.0, 0.0, 0.0, 0.0, 45.0);
			//}
		}
		break;
		// --
	case 6:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 1, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 7:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 1, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 8:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 2, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 9:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 3, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 10:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 4, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 11:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 5, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 12:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 6, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 13:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 7, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
	default:
		{
			lpPreview->Unknown23 = 0;
		}
		break;
	}
}

char* User::GetMapName(int MapNumber)
{
	if (MapNumber >= 83 && MapNumber <= 104)
	{
		return pGetTextLine(pTextLineThis, (3160 + MapNumber - 83));
	}
	return pGetMapName(MapNumber);
}

void User::ChangeCharInfo(LPVOID This)
{
	int Addradd;
	Addradd = QTFrame.DisplayWinExt;
	if (!gInterface.CheckWindow(Character))
	{
		return;
	}
	if (gServerInfo.get_char_interface(ViewAccountLevel))
	{
		gInterface.DrawText(eShinyGreen, 470, 58, 100, 1, "Level: %d", gObjUser.lpPlayer->Level);
		gInterface.DrawText(eExcellent, 510, 50, 100, 1, "Reset: %d", ViewReset);
		gInterface.DrawText(eExcellent, 510, 60, 100, 1, "Grand Reset: %d", ViewGReset);

		if (gServerInfo.get_char_interface(ViewAccountLevel))
		{
			pDrawGUI(400001, 565, 51, 50, 16);

			char Value[50];
			ZeroMemory(Value, sizeof(Value));
			pGetMoneyFormat((double)ViewPoint, Value, 0);
			GetFormat(Value, ',', ' ');

		gInterface.DrawFormat(eBlue, 540, 55, 100, 3, "%s", Value);

		if (gInterface.m_DanhHieu == 1)
		{
			RenderBitmap(10104, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 2)
		{
			RenderBitmap(10105, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 3)
		{
			RenderBitmap(10106, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 4)
		{
			RenderBitmap(10107, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 5)
		{
			RenderBitmap(10108, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 6)
		{
			RenderBitmap(10109, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 7)
		{
			RenderBitmap(10110, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 8)
		{
			RenderBitmap(10111, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 9)
		{
			RenderBitmap(10112, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 10)
		{
			RenderBitmap(10113, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 11)
		{
			RenderBitmap(10114, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 12)
		{
			RenderBitmap(10115, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 13)
		{
			RenderBitmap(10116, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 14)
		{
			RenderBitmap(10117, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 15)
		{
			RenderBitmap(10118, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 16)
		{
			RenderBitmap(10119, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 17)
		{
			RenderBitmap(10120, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 18)
		{
			RenderBitmap(10121, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 19)
		{
			RenderBitmap(10122, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		if (gInterface.m_DanhHieu == 20)
		{
			RenderBitmap(10123, 480, 70, 146, 75, 0, 0, 1, 1, 1, 1, 0.0);
		}
		}
	}
	else
	{
		((BOOL(__thiscall*)(LPVOID This))0x0077FAE0)(This);
	}
}
void User::RenderRuneEffect(DWORD ObjectModel, int ID, int Type, float Z, float Size)
{
	int Iterator = 0;

	MU3Float lBone[MAX_MODEL_EFFECT];

    MU3Float lBone2[MAX_MODEL_EFFECT];

	vec3_t Color;

	vec3_t ColorRandom;

	Vector(1.0, 1.0, 1.0, Color);

	Vector(((float)(rand() % 100) / 100), ((float)(rand() % 100) / 100), ((float)(rand() % 100) / 100), ColorRandom);

	lBone[Iterator].X = *(float*)(ObjectModel + 252);

	lBone[Iterator].Y = *(float*)(ObjectModel + 256);

	lBone[Iterator].Z = *(float*)(ObjectModel + 520);

	//lBone2[Iterator].X = *(float*)(ObjectModel + 264);

	//lBone2[Iterator].Y = *(float*)(ObjectModel + 268);

	//lBone2[Iterator].Z = *(float*)(ObjectModel + 272);

	//lBone[Iterator].Z = lBone[Iterator].Z + (float)(Z);

	//lBone2[Iterator].Z = lBone2[Iterator].Z + (float)(Z);



	CreateEffect(ID, (int)&lBone, (int)&lBone, ColorRandom, 2, 0, -1, 0, 0, 0, 1.0, -1);
	
}


bool User::UseHasMagicRing()
{
	DWORD  pCharData = *(DWORD*)MAIN_CHARACTER_STRUCT;
	if (pCharData)
	{
		for (size_t i = 0; i < 6; i++)
		{
		if (gVuKhiRong.vukhirong >= 1 )
		{
			ObjectItem2* pRing = (ObjectItem2*)GetCharacterItem(i);
			if ( 
				   pRing->ItemID == ITEM(0,19)
				|| pRing->ItemID == ITEM(0,51)
				|| pRing->ItemID == ITEM(0,56)
				|| pRing->ItemID == ITEM(0,105)
				|| pRing->ItemID == ITEM(0,106)
				|| pRing->ItemID == ITEM(0,110)
				|| pRing->ItemID == ITEM(2,13)
				|| pRing->ItemID == ITEM(2,25)
				|| pRing->ItemID == ITEM(2,31)
				|| pRing->ItemID == ITEM(4,18)
				|| pRing->ItemID == ITEM(4,30)
				|| pRing->ItemID == ITEM(4,33)
				|| pRing->ItemID == ITEM(5,10)
				|| pRing->ItemID == ITEM(5,49)
				|| pRing->ItemID == ITEM(5,65)
				|| pRing->ItemID == ITEM(5,36)
				|| pRing->ItemID == ITEM(5,50)
				|| pRing->ItemID == ITEM(5,66)
				&& pRing->Opt.opt_level >= 13)
			{
				return true;
			}
		}
		

		}
	}
	return false;
}
bool User::CreateManyFlag(ObjectPreview * pChar)
{
					DWORD ModelID = 10005;
				if(gCustomRankUser.m_Data[pChar->aIndex].m_rNguHanh  >= 1 )
			        {
						
						ModelID = 10001; // xanh
						
				    }
				if(gCustomRankUser.m_Data[pChar->aIndex].m_rNguHanh  >= 2 )
			        {
						
						ModelID = 10002; // trắng
						
				    }
				if(gCustomRankUser.m_Data[pChar->aIndex].m_rNguHanh  >= 3 )
			        {
						
						ModelID = 10003; // đỏ
						
				    }
				if(gCustomRankUser.m_Data[pChar->aIndex].m_rNguHanh  >= 4 )
			        {
						
						ModelID = 10004; //green
						
				    }
				if(gCustomRankUser.m_Data[pChar->aIndex].m_rNguHanh  >= 5 )
			        {
						
						ModelID = 348; // vàng
						
				    }
	
	if (!pChar->Unknown764 && (pChar == (ObjectPreview *)*(DWORD*)MAIN_VIEWPORT_STRUCT && UseHasMagicRing()  || PlayerHasManyFlag(pChar->aIndex)))
	{
		void* pMem = ((void*(__cdecl*)(int))(0x9D00C5))(668);

		pChar->Unknown764 = (DWORD)((void*(__thiscall*)(void *this1, int modeType, int ParentBoneIndex, bool bFllowParentRotate, float ox, float oy, float oz, float rx, float ry, float rz))(0x4EFFF0))
			
		(pMem, ModelID, 20, 0, -45.0, -5.0, -0.0, 0.0, 0.0, 1);
			
		return true;
	}
	return false;
}
void User::HoolCreateManyFlay(ObjectPreview*  pChar)
{
	User::CreateManyFlag(pChar);
	((void(__cdecl*)(ObjectPreview*))(0x4EF9A0))(pChar);
}

//abcd
 void User::RecvCustomCAPNHATMu(PMSG_UPD_CAPNHAT_INFO * aRecv)
{
	this->m_CAPNHAT1 = 0;
	this->m_CAPNHAT1 = aRecv->CAPNHAT1;
	this->m_CAPNHAT2 = 0;
	this->m_CAPNHAT2 = aRecv->CAPNHAT2;
	this->m_CAPNHAT3 = 0;
	this->m_CAPNHAT3 = aRecv->CAPNHAT3;
	this->m_CAPNHAT4 = 0;
	this->m_CAPNHAT4 = aRecv->CAPNHAT4;
	this->m_CAPNHAT5 = 0;
	this->m_CAPNHAT5 = aRecv->CAPNHAT5;
	this->m_CAPNHAT6 = 0;
	this->m_CAPNHAT6 = aRecv->CAPNHAT6;
	this->m_CAPNHAT7 = 0;
	this->m_CAPNHAT7 = aRecv->CAPNHAT7;
	this->m_CAPNHAT8 = 0;
	this->m_CAPNHAT8 = aRecv->CAPNHAT8;
}
//==================================================================
//tue add Hon Hoan 
#if(SPK_HONHOAN)
#define WorldTime					*(float*)0x005EF5A1C
#define EnableAlphaBlend			((void(__cdecl*)()) 0x636070)
#define DisableAlphaBlend			((void(__cdecl*)()) 0x00635F50)
#define RenderTerrainAlphaBitmap    ((void(__cdecl*)(int Texture,float xf,float yf,float SizeX,float SizeY,vec3_t Light,float Xoay,float Alpha,float Height, int DoCao)) 0x005DAD80)
 void User::CBRenderCharacter(DWORD ObjectPointer, int Effect, float SizeX, float SizeY, vec3_t Color, int Type)
 {  
	//pDrawMessage("User::CBRenderCharacter.... ", 1); // for debug
	 //lpViewObj a4 = &*(ObjectPreview*)(ObjectPointer);
	 //vec3_t vLight;
	 //float fLumi = sinf(WorldTime * 0.0015f) * 0.3f + 0.5f;
	 //Vector(fLumi * Color[0], fLumi * Color[1], fLumi * Color[2], vLight); //7 Mau
	 //EnableAlphaBlend();
	 //if (Type == 0)
	 //{
		// RenderTerrainAlphaBitmap(Effect, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, SizeX, SizeY, Color, WorldTime * 0.02f, 1.0, 5, 1);
	 //}
	 //else {
		// RenderTerrainAlphaBitmap(Effect, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, SizeX, SizeY, Color, -WorldTime * 0.02f, 1.0, 5, 1);
	 //}

	 //DisableAlphaBlend();
	 lpViewObj a4 = &*(ObjectPreview*)(ObjectPointer);
	 vec3_t vLight;
	 float fLumi = sinf(WorldTime * 0.0015f) * 0.3f + 0.5f;
	 Vector(fLumi * Color[0], fLumi * Color[1], fLumi * Color[2], vLight); //7 Mau
	 EnableAlphaBlend();
	 //RenderTerrainAlphaBitmap(Effect, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, SizeX, SizeY, Color, WorldTime * 0.11f, 1.0, 5, 1);
	 if (Type == 0)
	 {
		 RenderTerrainAlphaBitmap(Effect, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, SizeX, SizeY, Color, WorldTime * 0.11f, 1.0, 5, 1);
	 }
	 else {
		 RenderTerrainAlphaBitmap(Effect, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, SizeX, SizeY, Color, -WorldTime * 0.01f, 1.0, 5, 1);
	 }

	 DisableAlphaBlend();

	// lpViewObj a4 = &*(ObjectPreview*)(ObjectPointer);
	 //vec3_t vLight;
	 //Vector(1.0f, 1.0f, 1.f, vLight);
	 //float fLumi = sinf(WorldTime * 0.0015f) * 0.3f + 0.5f;
	 //Vector(fLumi * vLight[0], fLumi * vLight[1], fLumi * vLight[2], vLight);
	 //EnableAlphaBlend();
	 //RenderTerrainAlphaBitmap(32280, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, 5.8f, 5.8f, vLight, WorldTime * 0.11f, 1.0, 5, 1);
	 //RenderTerrainAlphaBitmap(32280, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, 3.8f, 3.8f, vLight, -WorldTime * 0.01f, 1.0, 5, 1);
	 
	// RenderTerrainAlphaBitmap(3, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, 5.8f, 5.8f, vLight, WorldTime * 0.11f, 1.0, 5, 1);
	// RenderTerrainAlphaBitmap(3, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, 3.8f, 3.8f, vLight, -WorldTime * 0.01f, 1.0, 5, 1);
	// DisableAlphaBlend();

	 //pDrawMessage("11111111111111111111", 1);


 }
#endif
 //abcd
//-------------------------------------------------------------------

/////

