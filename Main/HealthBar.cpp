#include "stdafx.h"
#include "HealthBar.h"
#include "Offset.h"
#include "Util.h"
#include "Object.h"
#include "User.h"
#include "Defines.h"
#include "MonsterHpBar.h"
#include "Import.h"
#include "CustomRankUser.h"
#include "Protect.h"
#include "Import.h"
#include "Common.h"

NEW_HEALTH_BAR gNewHealthBar[MAX_MAIN_VIEWPORT];

void ClearNewHealthBar() // OK
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		gNewHealthBar[n].index = 0xFFFF;
		gNewHealthBar[n].type = 0;
		gNewHealthBar[n].rate = 0;
		gNewHealthBar[n].bHasManyFlag = 0;
	}
}

void InsertNewHealthBar(PMSG_NEW_HEALTH_RECV* lpInfo) // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		if (gNewHealthBar[n].index == 0xFFFF)
		{
			gNewHealthBar[n].index = lpInfo->index;
			gNewHealthBar[n].type = lpInfo->type;
			gNewHealthBar[n].rate = lpInfo->rate;
			gNewHealthBar[n].monsterid = lpInfo->monsterid;
			gNewHealthBar[n].Life = lpInfo->Life;
			gNewHealthBar[n].MaxLife = lpInfo->MaxLife;
			gNewHealthBar[n].Level = lpInfo->Level;
			gNewHealthBar[n].Reset = lpInfo->Reset;
			gNewHealthBar[n].Shield = lpInfo->Shield;
			gNewHealthBar[n].MaxShield = lpInfo->MaxShield;
			gNewHealthBar[n].SDrate = lpInfo->SDrate;
			gNewHealthBar[n].isSameGuild = lpInfo->isSameGuild;
			gNewHealthBar[n].HaveGuild = lpInfo->HaveGuild;
			gNewHealthBar[n].bHasManyFlag =  lpInfo->bHasManyFlag;
			gNewHealthBar[n].ItemID = lpInfo->ItemID;
			if (lpInfo->type == emPlayer && lpInfo->HaveGuild)
			{
				memcpy(gNewHealthBar[n].GuildName, lpInfo->GuildName, sizeof(gNewHealthBar[n].GuildName));
				char kek[65];

				for (int i = 0; i < 32; i++)
				{
					sprintf(&kek[i * 2], "%02x", lpInfo->Mark[i]);
				}
				kek[64] = '\0';

				for (int i = 0; i < 64; i++)
				{
					if (kek[i] >= 97)
					{
						gNewHealthBar[n].Mark[i] = (int)kek[i] - 87;
					}
					else
					{
						gNewHealthBar[n].Mark[i] = (int)kek[i] - 48;
					}
				
				}

				//g_Console.AddMessage(5,"Logo setted!");
			}
			return;
		}
	}
}
#include "Interface.h"
NEW_HEALTH_BAR* GetNewHealthBar(WORD index, BYTE type) // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		if (gNewHealthBar[n].index != 0xFFFF)
		{
			if (gNewHealthBar[n].index == index && gNewHealthBar[n].type == type)
			{
				return &gNewHealthBar[n];
			}
		}
	}

	return 0;
}
void DrawHealthBar(void * item_data)
{
	((void(*)())0x005BA770)();
	int PosX, PosY;
	float LifeBarWidth = 66.95;	
	VAngle Angle;

	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		lpViewObj lpObj = &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), n);
		lpViewObj lpTarget	= gObjUser.lpViewTarget;

		bool isTarget = 1;

		if (!lpTarget || (lpTarget->m_Model.ObjectType != emMonster && lpTarget->m_Model.ObjectType != emPlayer) || !lpTarget->m_Model.Unknown4 || lpTarget->aIndex != lpObj->aIndex)
		{
			isTarget = 0;
		}

		if (!lpObj)
		{
			continue;
		}

		if (lpObj->m_Model.Unknown4 == 0)
		{
			continue;
		}

		NEW_HEALTH_BAR* lpNewHealthBar = GetNewHealthBar(lpObj->aIndex, lpObj->m_Model.ObjectType);

		if (lpNewHealthBar == 0)
		{
			continue;
		}

		int LifePercent = lpNewHealthBar->rate / 10;
		float BarWidth = (((66.95 - 1) / 100.0f) * lpNewHealthBar->rate) - 1;
		float SDBarWidth = (((66.95 - 1) / 100.0f) * lpNewHealthBar->SDrate) - 1;

		Angle.X = lpObj->m_Model.VecPos.X;
		Angle.Y = lpObj->m_Model.VecPos.Y;
		Angle.Z = lpObj->m_Model.VecPos.Z + lpObj->m_Model.Unknown216.Z + 100.0;

		pGetPosFromAngle(&Angle, &PosX, &PosY);
		PosX -= (int)floor(LifeBarWidth / (double)2.0);

		pSetBlend(true);
		
		if (lpNewHealthBar->type == emPlayer/* && istarget*/)
		{
			bool isPartyMember = IsPartyMember(n);
			if (!isTarget && !isPartyMember && !lpNewHealthBar->isSameGuild)
			{
				continue;
			}
			
			
			if (isPartyMember)
			{
				
			}
			else if (lpNewHealthBar->isSameGuild)
			{
				
			}
			else
			{
				
			}

			if (!isTarget)
			{
				
			}
			else
			{
				
			}

			if (!isTarget)
			{

			}
			else
			{

			}

			//show shift player
				if (GetKeyState ( VK_SHIFT ) & 0x8000 && isTarget)
					{

						ObjectItem * item_data = (ObjectItem*)item_data;
						float width = LifeBarWidth * 1.5;
						int pos_x = PosX - 1 - (width - LifeBarWidth) / 2;

						gInterface.DrawBarForm(pos_x, PosY + 6, LifeBarWidth * 1.5, 50, 0.0, 0.0, 0.0, 0.6);

						gInterface.DrawFormat(eExcellentS15,  (float)(PosX - 15),(float)(PosY + 07), LifeBarWidth + 30, 3,  "%s", lpObj->Name);
						gInterface.DrawFormat(eGold,  (float)(PosX),(float)(PosY + 17), LifeBarWidth, 3,  "HP:%2d.0%%", lpNewHealthBar->rate);
						
					

						int Index = item_data->ItemID;
						int Type  = item_data->ItemID%512;
						int Level = item_data->Level;
						
					
				
				}
		}
		else
		{
			if (!isTarget)
			{
				continue;
			}
			CUSTOM_HPBAR* HpBarEx = gMonsterHpBar.GetHpBar(lpNewHealthBar->monsterid);

			if (HpBarEx == 0)
			{
				glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Öâåò ôîíà äëÿ èìåíè

				if (!isTarget)
				{
					pDrawBarForm((float)(PosX - 1), (float)(PosY - 12), 66.95, 10, 0.0, 0); // Ôîí äëÿ èìåíè
				}
				else
				{
					pDrawBarForm((float)(PosX - 1), (float)(PosY - 22), 66.95, 20, 0.0, 0); // Ôîí äëÿ èìåíè
				}

				glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Öâåò ôîíà äëÿ õïáàðà
				pDrawBarForm((float)(PosX - 1), (float)(PosY - 1.5), 66.95, 6, 0.0, 0); // Ôîí õïáàðà

				glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f / 100.0f) * lpNewHealthBar->rate) - 255.0f)), RGBTOGLFLOAT(0), 0.8); // Öâåò ÕÏ Áàðà

				pDrawBarForm((float)(PosX), (float)(PosY), BarWidth, 3, 0.0, 0); // ÕïÁàð

				if (!isTarget)
				{
					DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 11, 66.95, 1, eWhite, 9, 3); // Äðàâ èìåíè
				}
				else
				{
					char Text[100];
					sprintf(Text, "LV:%d HP:%2d.0%%", lpNewHealthBar->Level,lpNewHealthBar->rate);

					DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 21, 67, 1, eWhite, 9, 3); // Äðàâ èìåíè
					DrawInterfaceText(Text, PosX - 1, PosY - 11, 67, 1, eWhite, 9, 3); // Äðàâ èíôû
				}
				
			}
			else
			{
				glColor4f(RGBTOGLFLOAT(HpBarEx->Red), RGBTOGLFLOAT(HpBarEx->Green), RGBTOGLFLOAT(HpBarEx->Blue), HpBarEx->Opacity); // Öâåò ôîíà äëÿ èìåíè

				if (!isTarget)
				{
					pDrawBarForm((float)(PosX - 1), (float)(PosY - 22), 66.95, 20, 0.0, 0); // Ôîí äëÿ èìåíè
				}
				else
				{
					pDrawBarForm((float)(PosX - 1), (float)(PosY - 32), 66.95, 30, 0.0, 0); // Ôîí äëÿ èìåíè
				}

				glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Öâåò ôîíà äëÿ õïáàðà
				pDrawBarForm((float)(PosX - 1), (float)(PosY - 1.5), 66.95, 6, 0.0, 0); // Ôîí õïáàðà

				glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f / 100.0f) * lpNewHealthBar->rate) - 255.0f)), RGBTOGLFLOAT(0), 0.8); // Öâåò ÕÏ Áàðà

				pDrawBarForm((float)(PosX), (float)(PosY), BarWidth, 3, 0.0, 0); // ÕïÁàð

				if (!isTarget)
				{
					DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 11, 66.95, 1, eWhite, 9, 3); // Äðàâ èìåíè
					DrawInterfaceText(HpBarEx->Name, PosX - 1, PosY - 21, 66.95, 1, eWhite, 9, 3); // Äðàâ èìåíè
				}
				else
				{
					char Text[100];
					sprintf(Text, "LV:%d HP:%2d.0%%", lpNewHealthBar->Level,lpNewHealthBar->rate);


					DrawInterfaceText(HpBarEx->Name, PosX - 1, PosY - 31, 66.95, 1, eWhite, 9, 3); // Äðàâ ñàáèìåíè
					DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 21, 66.95, 1, eWhite, 9, 3); // Äðàâ èìåíè
					DrawInterfaceText(Text, PosX - 1, PosY - 11, 66.95, 1, eWhite, 9, 3); // Äðàâ èíôû
				}

				
			}

			//show shift monster
				if (GetKeyState ( VK_SHIFT ) & 0x8000 && isTarget)
					{
						float width = LifeBarWidth * 1.5;
						int pos_x = PosX - 1 - (width - LifeBarWidth) / 2;

						gInterface.DrawBarForm(pos_x, PosY + 6, LifeBarWidth * 1.5, 50, 0.0, 0.0, 0.0, 0.6);

						gInterface.DrawFormat(eExcellentS15,  (float)(PosX - 15),(float)(PosY + 07), LifeBarWidth + 30, 3,  "%s", lpObj->Name);
						gInterface.DrawFormat(eGold,  (float)(PosX),(float)(PosY + 17), LifeBarWidth, 3,  "HP:%2d.0%%", lpNewHealthBar->rate);
				}
		}

		//tue add Tu Chan /////////
		////////////////////////////////////////

		DWORD ViewportAddress = ((DWORD(__thiscall*)(void*, DWORD))0x0096A4C0)(((void* (*)())0x00402BC0)(), n);
		gObjUser.m_Logo[n].Active = 0;
		if (!ViewportAddress)
		{
			continue;
		}
		if (*(BYTE*)(ViewportAddress + 0x30C) == 0)
		{
			continue;
		}
		//Angle.X = *(float*)(ViewportAddress + 0x404);
		//Angle.Y = *(float*)(ViewportAddress + 0x408);
		//Angle.Z = *(float*)(ViewportAddress + 0x40C) + *(float*)(ViewportAddress + 0x3E8) + 100.0f;
		pGetPosFromAngle(&Angle, &PosX, &PosY);
		if (*(BYTE*)(ViewportAddress + 0x320) == 1) //Check User Type
		{
			gObjUser.m_Logo[n].Active = 1;
			gObjUser.m_Logo[n].X = PosX;
			gObjUser.m_Logo[n].Y = PosY;
			gCustomRankUser.RenderShowLogRank(ViewportAddress, *(WORD*)(ViewportAddress + 0x7E), PosX - 42, PosY);
		}
		gCustomRankUser.RenderShowLogRank(ViewportAddress, *(WORD*)(ViewportAddress + 0x7E), PosX - 42, PosY);
		pGLSwitch();
		///////////////////////

		pGLSwitch();
	}


	gCustomRankUser.DrawInfo();

	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
}

bool IsPartyMember(int ViewportID)
{

	
#if (_NEW_PARTY_SYSTEM_ == TRUE )
	for (int PartySlot = 0; PartySlot < g_Party.PartyMemberCount; PartySlot++)
#else
	for (int PartySlot = 0; PartySlot < pPartyMemberCount; PartySlot++)
#endif
	{
		PartyList PartyMember = *(PartyList*)((char*)&pPartyListStruct + sizeof(PartyList) * PartySlot);
		//lpViewObj lpPartyObj	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), PartyMember.ViewportID);
		if (ViewportID == PartyMember.ViewportID)
		{
			return true;
		}
	}

	return false;
}

bool PlayerHasManyFlag(WORD index)
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		if (gNewHealthBar[n].index != 0xFFFF)
		{
			if (gNewHealthBar[n].index == index && gNewHealthBar[n].bHasManyFlag > 0)
			{
				return 1;
			}
		}
	}
	return 0;
}