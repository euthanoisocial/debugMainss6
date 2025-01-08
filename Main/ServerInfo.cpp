#include "stdafx.h"
#include "ServerInfo.h"
#include "Camera.h"
#include "MiniMap.h"
#include "Interface.h"
#include "TMemory.h"
#include "ConnectServer.h"
#include "ReadScript.h"
#include "PartySearch.h"

CServerInfo gServerInfo;

CServerInfo::CServerInfo()
{

}


//Naked(DynamicTypeServer)
//{
//	static DWORD Address1 = 0x08128ADC;
//	static DWORD Address2 = 0x00402320;
//	static DWORD Address3 = 0x00D4F798;
//	static DWORD Address4 = 0x009CF6AA;
//	static DWORD Address5 = 0x0095415C;
//	static DWORD SubCode = 0;
//	static char * formatText;
//	_asm{
//		mov edx, [ebp + 0x0C]
//			mov SubCode, edx
//	}
//	switch (ConnectServer.getServerType(SubCode))
//	{
//	case 0:
//		formatText = "%s-%d(PvP) %s";
//		break;
//	case 1:
//		formatText = "%s-%d(Non-PvP) %s";
//		break;
//	default:
//		formatText = "%s-%d %s";
//		break;
//	}
//
//	_asm{
//		mov edx, [ebp - 0x10]
//			push edx
//			mov ecx, Address1
//			call Address2
//			push eax
//			mov eax, [ebp - 0x14]
//			mov ecx, [eax + 0x08]
//			push ecx
//			mov edx, [ebp + 0x08]
//			add edx, 0x2D
//			push edx
//			push formatText
//			mov eax, [ebp - 0x14]
//			add eax, 0x15
//			push eax
//			call Address4
//			add esp, 0x14
//			jmp Address5
//
//	}
//}

void CServerInfo::Load()
{
	//SetRange((LPVOID)0x00954071, 10, ASM::NOP);
	//SetOp((LPVOID)0x00954071, DynamicTypeServer, ASM::JMP);

	//00953CFC - hook
   this->m_data.clear();

   this->Read("Data/Custom/ServerList.txt");

    SetOp((LPVOID)0x009540B8, this->ServerDrawTextHook, ASM::CALL); //1.04E
    SetOp((LPVOID)0x009540EE, this->ServerDrawTextHook, ASM::CALL); //1.04E
    SetOp((LPVOID)0x00954121, this->ServerDrawTextHook, ASM::CALL); //1.04E
    SetOp((LPVOID)0x00954154, this->ServerDrawTextHook, ASM::CALL); //1.04E
}

void CServerInfo::Read(char* filename)
{
   SMDToken Token;

   SMDFile = fopen(filename, "r");

   if(!SMDFile)
   {
      return;
   }

   while(true)
   {
      Token = GetToken();

      if( Token == END || !strcmp(TokenString, "end") )
      {
         break;
      }

      SERVERINFO_DATA list;

      memcpy(list.ServerName, TokenString, sizeof(list.ServerName));

      Token = GetToken();
      list.SubServerNum = TokenNumber;

      Token = GetToken();
      memcpy(list.ServerText, TokenString, sizeof(list.ServerText));

      this->m_data.push_back(list);
   }

   fclose(SMDFile);
}


void CServerInfo::ServerDrawTextHook(int a1, char *a2, char* ServerName, int SubServerNum, char* TextConnect)
{
   for(int i = 0; i < gServerInfo.m_data.size(); i++)
   {
      if(!strcmp(ServerName, gServerInfo.m_data[i].ServerName))
      {
         if(SubServerNum == gServerInfo.m_data[i].SubServerNum)
         {
            pSetItemTextLine(a1, gServerInfo.m_data[i].ServerText);
            return;
         }   
      }
   }

   pSetItemTextLine(a1, a2, ServerName, SubServerNum, TextConnect);

   
}

void CServerInfo::RecvServerInfo(PMSG_SERVER_INFO_RECV* Data)
{
	for (int i = 0; i < MAX_ACCOUNT_LEVEL; i++)
	{
		this->m_custom_char_interface_[i] = Data->CustomCharInterface[i];
		this->m_max_stat_point_[i] = Data->MaxStatPoint[i];
		//gPartySearch.CanOpenSettings[i] = Data->CanOpenSettings[i];
		//gPartySearch.CanOpenMain[i] = Data->CanOpenMain[i];
	}
	this->AnimatedWarehouse = Data->CustomWarehouseAnimated;

	this->m_strength_ = Data->Strength;
	this->m_dexterity_ = Data->Dexterity;
	this->m_vitality_ = Data->Vitality;
	this->m_energy_ = Data->Energy;
	this->m_leadership_ = Data->Leadership;
	this->m_PartyTeleportSwitch = Data->PartyTeleportSwitch;
	this->m_PartyTeleportMoney = Data->PartyTeleportMoney;

}


int CServerInfo::get_char_interface(int AccountLevel)
{
	return this->m_custom_char_interface_[AccountLevel];
}

int CServerInfo::get_max_stat_point(int AccountLevel)
{
	return this->m_max_stat_point_[AccountLevel];
}
