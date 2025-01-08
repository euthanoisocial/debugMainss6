#include "StdAfx.h"
#include "Luna_CNewFlag.h"
#include "CustomVKR.h"
//tue add thue flag 
#include "ThueFlag.h"
#include "CustomModelFlag.h"
#include "CustomRankUser.h"
#include "Common.h"
//=====================
#if(CUSTOM_FLAGS)

CFlagEquip Flag;

CFlagEquip::CFlagEquip( )
{
	this->Clearviewport( );
}


CFlagEquip::~CFlagEquip( )
{

}

void CFlagEquip::Clearviewport( )
{
	this->count = 0;
	for(int j = 0; j < 76; j++ )
	{
		this->FlagEquip[ j ].aIndex = 0xFFFF;
	}
}

void CFlagEquip::Inserviewport(PMSG_FLAG_TEC_RECV * lpMsg)
{
	this->Clearviewport( );
	this->count = lpMsg->count;

	for(int n = 0; n < lpMsg->count; n++)
	{
		FLAG_TEC* info = (FLAG_TEC*)(((BYTE*)lpMsg)+sizeof(PMSG_FLAG_TEC_RECV)+(sizeof(FLAG_TEC)*n));

		this->FlagEquip[ n ].aIndex = info->aIndex;
		this->FlagEquip[ n ].Flag = info->Flag;
	}

}

int CFlagEquip::ShowFlag(WORD aIndex)
{
	for(int m = 0; m < this->count; m++)
	{
		if(this->FlagEquip[ m ].aIndex == aIndex )
		{
			return this->FlagEquip[ m ].Flag;
		}
	}

	return 1;
}
// test OK ////////////////
int HoolCreateManyFlay(int thisa)
{
	if(pPlayerState == 5)
	{
		int v5; // ST48_4@11
		float *v15; // [sp+38h] [bp-5Ch]@13
		float *v24; // [sp+80h] [bp-14h]@12

		v5 = Flag.ShowFlag(*(WORD *)(thisa + 126));
		//tue add
		int FlagID = gCustomRankUser.m_Data[*(WORD*)(thisa + 126)].m_rQuanHam;
		/////////////
		if( v5 == 0 && *(DWORD *)(thisa + 764))
		{
			sub_9CEA6C(thisa, *(LPVOID *)(thisa + 764));
			*(DWORD *)(thisa + 764) = 0;
		}
		if ( !*(DWORD *)(thisa + 764) && v5 == 1 )
		{
			v24 = (float *)Operator_new(0x29Cu);
			//if ( v24 && gVuKhiRong.vukhirong == 5 )
			if (v24 && FlagID) {
			
				v15 = (FlagID == 1) ? CSParts2D(v24, 7780, 20, 0, -45.0, -5.0, -0.0, 0.0, 0.0, 1): 
					  CSParts2D(v24, gProtect.m_MainInfo.m_mModelFlagData[FlagID].ModelIndex + 1171, 20, 0, -45.0, -5.0, -0.0, 0.0, 0.0, 1);
				//v15 = CSParts2D(v24, 1175, 20, 0, -45.0, -5.0, -0.0, 0.0, 0.0, 1);
			}
			else 
                v15 = 0;
			

			*(DWORD *)(thisa + 764) = (DWORD)v15;
			
		}
	}
	return CreatePartsFactory(thisa);
}

/*
int HoolCreateManyFlay(int thisa)
{
	int v5; // ST48_4@11
	float* v15; // [sp+38h] [bp-5Ch]@13
	float* v24; // [sp+80h] [bp-14h]@12

	v5 = 1;
	//int FlagID = gCustomRankUser.m_Data[*(WORD*)(thisa + 126)].m_RankTitle6 - 1;
	//int FlagID = gCustomRankUser.m_Data[*(WORD*)(thisa + 126)].m_rDanhHieu - 1;
	int FlagID = 1;
	v5 = (FlagID != -1) ? 1 : 0;

	if (v5 == 0 && *(DWORD*)(thisa + 764))
	{
		sub_9CEA6C(thisa, *(LPVOID*)(thisa + 764));
		*(DWORD*)(thisa + 764) = 0;
	}
	//if (DisableFlag == 0)
	{
		//if (!*(DWORD*)(thisa + 764) && v5 == 1 && gCustomModelFlag.CheckFlagModelIsLoad(gProtect.m_MainInfo.m_mModelFlagData[FlagID].ModelIndex))
		//if (!*(DWORD*)(thisa + 764) && v5 == 1 && gCustomModelFlag.CheckFlagModelIsLoad(1))
		if (!*(DWORD*)(thisa + 764) && v5 == 1 && 1)
		{
			v24 = (float*)Operator_new(0x29Cu);
			if (v24)
			{
				//v15 = CSParts2D(v24, gProtect.m_MainInfo.m_mModelFlagData[FlagID].ModelIndex + 1171, 20, 0, -45.0, -5.0, -0.0, 0.0, 0.0, 1);
				v15 = CSParts2D(v24, 2 + 1171, 20, 0, -45.0, -5.0, -0.0, 0.0, 0.0, 1);
			}
			else
			{
				v15 = 0;
			}
			*(DWORD*)(thisa + 764) = (DWORD)v15;
		}
	}
	return CreatePartsFactory(thisa);

}

*/



void CFlagEquip::Load( ){
	SetCompleteHook(0xE8, 0x00588511, &HoolCreateManyFlay);
}

#endif
#if(HT_THUE_FLAG == 0)
#include "Luna_CNewFlag.h"
#include "CustomRankUser.h"
#include "Interface.h"
#include "WindowsStruct.h"
#include "User.h"
#include "Common.h"
#include "ThueFlag.h"
#include "CustomModelFlag.h"

CFlagEquip Flag;

int HoolCreateManyFlay(int thisa)
{
	int v5; // ST48_4@11
	float* v15; // [sp+38h] [bp-5Ch]@13
	float* v24; // [sp+80h] [bp-14h]@12

	v5 = 1;
	//int FlagID = gCustomRankUser.m_Data[*(WORD*)(thisa + 126)].m_RankTitle6 - 1;
	int FlagID = gCustomRankUser.m_Data[*(WORD*)(thisa + 126)].m_rQuanHam - 1;
	v5 = (FlagID != -1) ? 1 : 0;

	if (v5 == 0 && *(DWORD*)(thisa + 764))
	{
		sub_9CEA6C(thisa, *(LPVOID*)(thisa + 764));
		*(DWORD*)(thisa + 764) = 0;
	}
	if (DisableFlag == 0)
	{
		if (!*(DWORD*)(thisa + 764) && v5 == 1 && gCustomModelFlag.CheckFlagModelIsLoad(gProtect.m_MainInfo.m_mModelFlagData[FlagID].ModelIndex))
		{
			v24 = (float*)Operator_new(0x29Cu);
			if (v24)
			{
				v15 = CSParts2D(v24, gProtect.m_MainInfo.m_mModelFlagData[FlagID].ModelIndex + 1171, 20, 0, -45.0, -5.0, -0.0, 0.0, 0.0, 1);
			}
			else
			{
				v15 = 0;
			}
			*(DWORD*)(thisa + 764) = (DWORD)v15;
		}
	}
	return CreatePartsFactory(thisa);

}
void CFlagEquip::Load()
{
	SetCompleteHook(0xE8, 0x00588511, &HoolCreateManyFlay);
}
#endif