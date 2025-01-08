#include "stdafx.h"
#include "PartySearch.h"
#include "User.h"
#include "Interface.h"
#include "PartySearchSettings.h"
#include "Defines.h"
#include "Offset.h"
#include "Central.h"
#include "Util.h"
#include "SItemOption.h"

#if(PARTYSEARCH==1)

cPartySearch gPartySearch;

cPartySearch::cPartySearch(){
	this->ClearPartyList();
}

cPartySearch::~cPartySearch(){
}

void cPartySearch::loadBind(){

	gInterface.BindObject(ePARTYSETTINGS_MAIN, 0x7A5A, 600, 600, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_SYSTEM_ACTIVE, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_ONLY_GUILD, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_ONE_CLASS, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_DARK_WIZARD, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_DARK_KNIGHT, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_ELF, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_MAGIC_GLADIATOR, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_DARK_LORD, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_SUMMONER, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_RAGE_FIGHTER, 0x7BAE, 15, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_LEVEL_MINUS, 0x7C0D, 16, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_LEVEL_PLUS, 0x7AA4, 16, 15, -1, -1);
	gInterface.BindObject(ePARTYSETTINGS_OK, 0x7A5B, 54, 30, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_MAIN, 0x7A5A, 600, 600, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_LEFT, 0x7E56, 20, 23, -1, -1);
	gInterface.BindObject(ePARTYSEARCH_RIGHT, 0x7E57, 20, 23, -1, -1);

	gInterface.BindObject(OBJECT_PARTYPASSWORD_MAIN, 0x7A5A, 222, 122, -1, -1);
	gInterface.BindObject(OBJECT_PARTYPASSWORD_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(OBJECT_PARTYPASSWORD_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(OBJECT_PARTYPASSWORD_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(OBJECT_PARTYPASSWORD_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(OBJECT_PARTYPASSWORD_TEXTBOX, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(OBJECT_PARTYPASSWORD_OK, 0x7A5B, 54, 30, -1, -1);
	gInterface.BindObject(OBJECT_PARTYSEARCH_IMAGE1, 0x7898, -1, -1, -1, -1);
	gInterface.BindObject(OBJECT_PARTYSEARCH_IMAGE2, 0x7899, -1, -1, -1, -1);
	gInterface.BindObject(OBJECT_PARTYSETTINGS_PASSWORD, 0x7AA3, 170, 21, -1, -1);
	memset(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, 0, sizeof(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue));
	gInterface.BindObject(OBJECT_PARTYPASSWORD_REFRESH, 81552, 18, 14, -1, -1);
	gInterface.BindObject(OBJECT_PARTYPASSWORD_RESETTING, 81553, 18, 14, -1, -1);
	

}


void cPartySearch::LoadImgPT()
{
	pLoadImage("Custom\\Interface\\bt_reset.tga", 81552, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\bt_setting.tga", 81553, 0x2601, 0x2901, 1, 0);
}

void cPartySearch::ClearPartyList(){
	for (int i = 0; i<MAX_PARTYLIST; i++){
		this->gPartyList[i].Index = 0xFFFF;
		memset(&this->gPartyList[i].Name, 0, sizeof(this->gPartyList[i].Name));
		this->gPartyList[i].Map = -1;
		this->gPartyList[i].X = -1;
		this->gPartyList[i].Y = -1;
		this->gPartyList[i].Count = -1;
		this->gPartyList[i].ButtonActive = true;
	}
	this->Page = 0;
	this->CountPages = 0;
	this->ListsCount = 0;
	this->currentIndex = -1;
}

void cPartySearch::InsertPartyList(PMSG_PARTYSEARCH_PARTYLIST* lpInfo){
	memcpy(this->gPartyList[this->ListsCount].Name, lpInfo->Name, sizeof(this->gPartyList[this->ListsCount].Name));
	this->gPartyList[this->ListsCount].Map = lpInfo->Map;
	this->gPartyList[this->ListsCount].X = lpInfo->X;
	this->gPartyList[this->ListsCount].Y = lpInfo->Y;
	this->gPartyList[this->ListsCount].Level = lpInfo->Level;
	this->gPartyList[this->ListsCount].DarkWizard = lpInfo->DarkWizard;
	this->gPartyList[this->ListsCount].DarkKnight = lpInfo->DarkKnight;
	this->gPartyList[this->ListsCount].Elf = lpInfo->Elf;
	this->gPartyList[this->ListsCount].MagicGladiator = lpInfo->MagicGladiator;
	this->gPartyList[this->ListsCount].DarkLord = lpInfo->DarkLord;
	this->gPartyList[this->ListsCount].Summoner = lpInfo->Summoner;
	this->gPartyList[this->ListsCount].RageFighter = lpInfo->RageFighter;
	this->gPartyList[this->ListsCount].OnlyGuild = lpInfo->OnlyGuild;
	this->gPartyList[this->ListsCount].IsSameGuild = lpInfo->IsSameGuild;
	this->gPartyList[this->ListsCount].OnlyAlliance = lpInfo->OnlyAliiance;
	this->gPartyList[this->ListsCount].IsSameAlliance = lpInfo->IsSameAlliance;
	this->gPartyList[this->ListsCount].RequirePassword = lpInfo->RequirePassword;
	this->gPartyList[this->ListsCount].Count = lpInfo->Count;
	this->gPartyList[this->ListsCount].Index = this->ListsCount;
	this->ListsCount++;
}

PARTYLIST* cPartySearch::GetPartyList(int index){
	if (this->gPartyList[index].Index == 0xFFFF){
		return 0;
	}
	this->CountPages = ((this->ListsCount - 1) / 10) + 1;
	if (this->CountPages <= 0){
		this->CountPages = 1;
	}
	for (int i = 0; i<this->ListsCount; i++){
		if (strcmp(this->gPartyList[i].Name, gObjUser.lpPlayer->Name) == 0){
			gPartySearchSettings.m_SystemActive = true;
			break;
		}
	}
	switch (gObjUser.lpPlayer->Class & 7){
	    case 0:{
		    if (this->gPartyList[index].DarkWizard == false){
			    this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
	    case 1:{
		    if (this->gPartyList[index].DarkKnight == false){
			    this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
	    case 2:{
			if (this->gPartyList[index].Elf == false){
				this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
        case 3:{
			if (this->gPartyList[index].MagicGladiator == false){
				this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
	    case 4:{
			if (this->gPartyList[index].DarkLord == false){
				this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
	    case 5:{
			if (this->gPartyList[index].Summoner == false){
				this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
	    case 6:{
			if (this->gPartyList[index].RageFighter == false){
				this->gPartyList[index].ButtonActive = false;
			}
	    }
		break;
	}
	if (gPartyList[index].OnlyGuild == true && gPartyList[index].IsSameGuild == false){
		this->gPartyList[index].ButtonActive = false;
	}
	if (gPartyList[index].Count >= 10){  //so luong max party
		gPartyList[index].ButtonActive = false;
	}
	if (*(DWORD*)(MAIN_PARTY_MEMBER_COUNT) > 0){
		gPartyList[index].ButtonActive = false;
	}
	if (gObjUser.lpPlayer->Level > gPartyList[index].Level){
		gPartyList[index].ButtonActive = false;
	}
	if (gPartySearchSettings.m_SystemActive == true){
		gPartyList[index].ButtonActive = false;
	}
	return &this->gPartyList[index];
}

void cPartySearch::SendPartyRequest(int index){
	PARTYLIST* info = gPartySearch.GetPartyList(index);
	if (info == 0){
		return;
	}
	this->currentIndex = index;
	PMSG_PARTY_REQ_SEND pMsg;
	pMsg.header.set(0xF3, 0xF2, sizeof(pMsg));
	memcpy(pMsg.Name, info->Name, sizeof(pMsg.Name));

	pMsg.needPassword = false;
	memset(pMsg.Password, 0, sizeof(pMsg.Password));

	DataSend((BYTE*)&pMsg, pMsg.header.size);
}


void cPartySearch::SendPartyRequest(int index, char* password)
{
	PARTYLIST* info = gPartySearch.GetPartyList(index);

	if (info == nullptr)
	{
		return;
	}

	this->currentIndex = index;

	PMSG_PARTY_REQ_SEND pMsg;

	pMsg.header.set(0xF3, 0xF3, sizeof(pMsg));

	memcpy(pMsg.Name, info->Name, sizeof(pMsg.Name));
	pMsg.needPassword = true;
	memcpy(pMsg.Password, password, sizeof(pMsg.Password));

	DataSend((BYTE*)&pMsg, pMsg.header.size);
}


void cPartySearch::GCPartyListRecv(PMSG_RECV_PARTYLIST* lpMsg){
	gPartySearch.ClearPartyList();
	for (int n = 0; n<lpMsg->Count; n++){
		PMSG_PARTYSEARCH_PARTYLIST* lpInfo = (PMSG_PARTYSEARCH_PARTYLIST*)(((BYTE*)lpMsg) + sizeof(PMSG_RECV_PARTYLIST)+(sizeof(PMSG_PARTYSEARCH_PARTYLIST)*n));
		gPartySearch.InsertPartyList(lpInfo);
	}
	//gPartySearch.SwitchPartySearchWindowState();
	gPartySearch.SwitchPartySearchWindowState2();
}


void cPartySearch::SwitchPartySettingsWindowState(){
	gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == true ? gInterface.Data[ePARTYSETTINGS_MAIN].Close() : gInterface.Data[ePARTYSETTINGS_MAIN].Open();
}

void cPartySearch::DrawPartySettingsWindow(){
	
	if (!gInterface.Data[ePARTYSETTINGS_MAIN].OnShow){
		return;
	}
	if (gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Character) //-- 13 & 16
		|| gInterface.CheckWindow(Warehouse) //-- 8
		|| gInterface.CheckWindow(Shop) //-- 12
		|| gInterface.CheckWindow(ChaosBox) //-- 9
		|| gInterface.CheckWindow(Trade) //-- 7
		|| gInterface.CheckWindow(Store) //-- 14
		|| gInterface.CheckWindow(OtherStore) //-- 15
		|| gInterface.CheckWindow(LuckyCoin1) //-- 60
		|| gInterface.CheckWindow(NPC_ChaosMix)
		|| gInterface.CheckWindow(MoveList)
		) //-- 76
	{
		gInterface.Data[ePARTYSETTINGS_MAIN].OnShow = false;
		return;
	}
	float MainWidth			= 230.0;
	float MainHeight		= 320.0;
	float StartBody			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY			= 22.0;
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);
	// ----
 	if (gInterface.IsWorkZone(ePARTYSETTINGS_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;

	 //gCItemSetOption.ItemTooltipS15(StartX, StartY, MainWidth, MainHeight, 0, 0);
	  RenderBitmap(500001,StartX-7, StartY-5, MainWidth+50, MainHeight+185, 0, 0, 1, 1, 1, 1, 0.0);

	if (gInterface.IsWorkZone(ePARTYSETTINGS_CLOSE))
	{
		if (gInterface.Data[ePARTYSETTINGS_CLOSE].OnClick)
		{
			PlayBuffer(25, 0, 0);
			gInterface.DrawButtonRender(ePARTYSETTINGS_CLOSE, (int)StartX + 205, (int)StartY - 10, 0 , 28);
			//pSetCursorFocus = false;
		}
		else
		{
			gInterface.DrawButtonRender(ePARTYSETTINGS_CLOSE, (int)StartX + 205, (int)StartY - 10, 0 , 0);
			//pSetCursorFocus = false;
		}
	}
	else
	{
		gInterface.DrawButtonRender(ePARTYSETTINGS_CLOSE, (int)StartX + 205, (int)StartY - 10, 0 , 0);
		//pSetCursorFocus = false;
	}
	gInterface.DrawFormat(eWhite, (int)StartX + 205, (int)StartY - 10, 59, 3, "");
	gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartY + 10, 210, 3, "Party Search Settings");
	gInterface.DrawFormat(eWhite, StartX + 40, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 33, 200, 1, "Active System");
	if (gPartySearchSettings.m_SystemActive == false){
		gInterface.DrawButton(ePARTYSETTINGS_SYSTEM_ACTIVE, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 30, 0, 0);
	}else{
		gInterface.DrawButton(ePARTYSETTINGS_SYSTEM_ACTIVE, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 30, 0, 15);
	}
	gInterface.DrawGUI(ePARTYSETTINGS_DIV, StartX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 40);
	gInterface.DrawFormat(eWhite, StartX + 40, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 60, 200, 1, "Max Level");
	gInterface.DrawGUI(ePARTYSETTINGS_DIV, StartX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 67);
	gInterface.DrawToolTip(StartX + 174, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 62, "%d", gPartySearchSettings.m_Level);
	if (gPartySearchSettings.m_SystemActive == 0){
		this->DrawColoredButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0, eGray150);
	}else{
		gInterface.DrawButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0);
		if (gInterface.IsWorkZone(ePARTYSETTINGS_LEVEL_MINUS)){
			if (gInterface.Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick){
				gInterface.DrawButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 16);
			}
		}
	}
	if (gPartySearchSettings.m_SystemActive == 0){
		DrawColoredButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0, eGray150);
	}else{
		gInterface.DrawButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0);
		if (gInterface.IsWorkZone(ePARTYSETTINGS_LEVEL_PLUS)){
			if (gInterface.Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick){
				gInterface.DrawButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 16);
			}
		}
	}

	/////////////////////////////////////////////PASSWORD//////////////////////////////////////////////
	int XXX = 0;
	int YYY = 206;
	if (gPartySearchSettings.m_SystemActive == 0){
		
	}else{
		if (gInterface.Data[ePARTYSETTINGS_MAIN].FirstLoad == true)
		{
			if (strlen(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue) == 0)
				sprintf(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, ""); //NONE
		}

		gInterface.DrawGUI(OBJECT_PARTYSETTINGS_PASSWORD, StartX + 28 + XXX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 76 + YYY);
		if (gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].Attribute == 1)
		{
			gInterface.DrawColoredGUI(OBJECT_PARTYSETTINGS_PASSWORD, StartX + 28 + XXX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 76 + YYY, eGray100);
		}

		gInterface.DrawText(eWhite, StartX + 40 + XXX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 82 + YYY, 200, 1, "máº­t kháº©u");

		gInterface.DrawText(eWhite, StartX + 50 + XXX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 82 + YYY, 200, 3, gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue);

		pDrawGUI(0x7B5E, StartX + 30 + XXX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 95 + YYY, 82.0, 2.0); //   1
		pDrawGUI(0x7B5E, StartX + 30 + 82 + XXX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 95 + YYY, 82.0, 2.0); //   2
	}
///////////////////////////////////////////PASSWORD END////////////////////////////////////////////


	gInterface.DrawFormat(eWhite, StartX + 40, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 87, 200, 1, "Only Guild");
	if (gPartySearchSettings.m_SystemActive){
		if (gPartySearchSettings.m_OnlyGuild == false){
			gInterface.DrawButton(ePARTYSETTINGS_ONLY_GUILD, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 83, 0, 0);
		}else{
			gInterface.DrawButton(ePARTYSETTINGS_ONLY_GUILD, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 83, 0, 15);
		}
	}else{
		gInterface.DrawButton(ePARTYSETTINGS_ONLY_GUILD, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 83, 0, 30);
	}
	pDrawGUI(0x7B5E, StartX + 30, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 100, 82.0, 2.0);
	pDrawGUI(0x7B5E, StartX + 30 + 82, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 100, 82.0, 2.0);
	gInterface.DrawFormat(eWhite, StartX + 40, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 109, 200, 1, "Only One Class");
	if (gPartySearchSettings.m_SystemActive){
		if (gPartySearchSettings.m_OneClass == false){
			gInterface.DrawButton(ePARTYSETTINGS_ONE_CLASS, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 105, 0, 0);
		}else{
			gInterface.DrawButton(ePARTYSETTINGS_ONE_CLASS, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 105, 0, 15);
		}
	}else{
		gInterface.DrawButton(ePARTYSETTINGS_ONE_CLASS, ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 105, 0, 30);
	}
	gInterface.DrawGUI(ePARTYSETTINGS_DIV, StartX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 115);
	char szCharNames[7][32] ={"Dark Wizard","Dard Knight","Elf","Magic Gladiator","Dark Lord","Summoner","Rage Fighter"};
	int ObjectIDs[7] ={
		ePARTYSETTINGS_DARK_WIZARD,
		ePARTYSETTINGS_DARK_KNIGHT,
		ePARTYSETTINGS_ELF,
		ePARTYSETTINGS_MAGIC_GLADIATOR,
		ePARTYSETTINGS_DARK_LORD,
		ePARTYSETTINGS_SUMMONER,
		ePARTYSETTINGS_RAGE_FIGHTER
	};
	for (int i = 0; i<7; i++){
		gInterface.DrawFormat(eWhite, StartX + 40, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 135 + (i * 22), 200, 1, szCharNames[i]);
		bool ClassValue = 0;
		switch (i){
		case 0:
			ClassValue = gPartySearchSettings.m_DarkWizard;
			break;
		case 1:
			ClassValue = gPartySearchSettings.m_DarkKnight;
			break;
		case 2:
			ClassValue = gPartySearchSettings.m_Elf;
			break;
		case 3:
			ClassValue = gPartySearchSettings.m_MagicGladiator;
			break;
		case 4:
			ClassValue = gPartySearchSettings.m_DarkLord;
			break;
		case 5:
			ClassValue = gPartySearchSettings.m_Summoner;
			break;
		case 6:
			ClassValue = gPartySearchSettings.m_RageFighter;
			break;
		}
		if (gPartySearchSettings.m_SystemActive){
			if (ClassValue == false){
				gInterface.DrawButton(ObjectIDs[i], ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 131 + (i * 22), 0, 0);
			}else{
				gInterface.DrawButton(ObjectIDs[i], ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 131 + (i * 22), 0, 15);
			}
		}else{
			gInterface.DrawButton(ObjectIDs[i], ButtonX + 110, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 131 + (i * 22), 0, 30);
		}
		pDrawGUI(0x7B5E, StartX + 30, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 148 + (i * 22), 82.0, 2.0);
		pDrawGUI(0x7B5E, StartX + 30 + 82, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 148 + (i * 22), 82.0, 2.0);
	}
	gInterface.DrawGUI(ePARTYSETTINGS_DIV, StartX, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 290);
	gInterface.DrawButton(ePARTYSETTINGS_OK, StartX + 75, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 310, 0, 0);
	if (gInterface.IsWorkZone(ePARTYSETTINGS_OK)){
		int ScaleY = 30;
		if (gInterface.Data[ePARTYSETTINGS_OK].OnClick){
			ScaleY = 60;
		}
		gInterface.DrawButton(ePARTYSETTINGS_OK, StartX + +75, gInterface.Data[ePARTYSETTINGS_MAIN].Y + 310, 0, ScaleY);
	}
}

bool cPartySearch::EventPartySettingsWindow_Main(DWORD Event){
	this->EventPartySettingsWindow_Close(Event);
	this->EventPartySettingsWindow_All(Event);
	return true;
}

bool cPartySearch::EventPartySettingsWindow_All(DWORD Event){
	const DWORD CurrentTick = GetTickCount(); //DWORD CurrentTick = GetTickCount();
	if (!gInterface.Data[ePARTYSETTINGS_MAIN].OnShow){
		return false;
	}

	

	if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_PASSWORD))
	{
		gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].Attribute = 1;
	}
	else
	{
		gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].Attribute = 0;
	}

	if (gInterface.IsWorkZone(ePARTYSETTINGS_SYSTEM_ACTIVE)){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_SYSTEM_ACTIVE].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSETTINGS_SYSTEM_ACTIVE].OnClick = true;
			return true;
		}
		gInterface.Data[ePARTYSETTINGS_SYSTEM_ACTIVE].OnClick = false;
		if (Delay < 500){
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_SYSTEM_ACTIVE].EventTick = GetTickCount();
		gPartySearchSettings.m_SystemActive ^= 1;
		for (int i = 0; i<7; i++){
			gPartySearchSettings.m_SystemActive == true ? gPartySearchSettings.SetClassValue(i, true) : gPartySearchSettings.SetClassValue(i, false);
		}
	}
	if (gInterface.IsWorkZone(ePARTYSETTINGS_LEVEL_MINUS)){
		if (gPartySearchSettings.m_SystemActive == 0){
			return false;
		}
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_LEVEL_MINUS].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick = true;
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick = false;
		if (Delay < 200){
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_LEVEL_MINUS].EventTick = GetTickCount();
		gPartySearchSettings.m_Level -= 10;
		if (gPartySearchSettings.m_Level <= 0){
			gPartySearchSettings.m_Level = 0;
		}
	}
	if (gInterface.IsWorkZone(ePARTYSETTINGS_LEVEL_PLUS)){
		if (gPartySearchSettings.m_SystemActive == 0){
			return false;
		}
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_LEVEL_PLUS].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick = true;
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick = false;
		if (Delay < 200){
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_LEVEL_PLUS].EventTick = GetTickCount();
		gPartySearchSettings.m_Level += 10;
		if (gPartySearchSettings.m_Level >= 400){
			gPartySearchSettings.m_Level = 400;
		}
	}
	if (gInterface.IsWorkZone(ePARTYSETTINGS_ONLY_GUILD)){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_ONLY_GUILD].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSETTINGS_ONLY_GUILD].OnClick = true;
			return true;
		}
		gInterface.Data[ePARTYSETTINGS_ONLY_GUILD].OnClick = false;
		if (Delay < 500){
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_ONLY_GUILD].EventTick = GetTickCount();
		gPartySearchSettings.m_OnlyGuild ^= 1;
	}
	if (gInterface.IsWorkZone(ePARTYSETTINGS_ONE_CLASS)){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_ONE_CLASS].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSETTINGS_ONE_CLASS].OnClick = true;
			return true;
		}
		gInterface.Data[ePARTYSETTINGS_ONE_CLASS].OnClick = false;
		if (Delay < 500){
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_ONE_CLASS].EventTick = GetTickCount();
		gPartySearchSettings.m_OneClass ^= 1;
		for (int i = 0; i<7; i++){
			gPartySearchSettings.m_OneClass == false ? gPartySearchSettings.SetClassValue(i, true) : gPartySearchSettings.SetClassValue(i, false);
		}
	}
	if (gInterface.IsWorkZone(ePARTYSETTINGS_OK)){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_OK].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSETTINGS_OK].OnClick = true;
			pSetCursorFocus = false; //loai bo cursor
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_OK].OnClick = false;
		if (Delay < 500){
			pSetCursorFocus = false; //loai bo cursor
			return false;
		}
		gInterface.Data[ePARTYSETTINGS_OK].EventTick = GetTickCount();
		gPartySearchSettings.CGSendPartySearchAdd();
		this->SwitchPartySettingsWindowState();
		//----addnew
		this->SwitchPartySearchWindowState();
		UP_PARTYSEARCH_REQ pMsg;
		pMsg.h.set(0xF3, 0x25, sizeof(pMsg));
		DataSend((BYTE*)&pMsg, pMsg.h.size);
		//----addnew
		pSetCursorFocus = false; //loai bo cursor
	}
	int ObjectIDs[7] ={
		ePARTYSETTINGS_DARK_WIZARD,
		ePARTYSETTINGS_DARK_KNIGHT,
		ePARTYSETTINGS_ELF,
		ePARTYSETTINGS_MAGIC_GLADIATOR,
		ePARTYSETTINGS_DARK_LORD,
		ePARTYSETTINGS_SUMMONER,
		ePARTYSETTINGS_RAGE_FIGHTER
	};
	for (int i = 0; i<7; i++){
		if (gInterface.IsWorkZone(ObjectIDs[i])){
			DWORD Delay = (CurrentTick - gInterface.Data[ObjectIDs[i]].EventTick);
			if (Event == WM_LBUTTONDOWN){
				gInterface.Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			gInterface.Data[ObjectIDs[i]].OnClick = false;
			if (Delay < 500){
				return false;
			}
			gInterface.Data[ObjectIDs[i]].EventTick = GetTickCount();
			gPartySearchSettings.ChangeClassValue(i);
			if (gPartySearchSettings.m_OneClass == true){
				gPartySearchSettings.m_OneClass = false;
			}
		}
	}
	return false;
}

bool cPartySearch::EventPartySettingsWindow_Close(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSETTINGS_CLOSE].EventTick);
	if (!gInterface.Data[ePARTYSETTINGS_MAIN].OnShow || !gInterface.IsWorkZone(ePARTYSETTINGS_CLOSE)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		gInterface.Data[ePARTYSETTINGS_CLOSE].OnClick = true;
		return true;
	}
	gInterface.Data[ePARTYSETTINGS_CLOSE].OnClick = false;
	if (Delay < 500){
		return false;
	}
	gInterface.Data[ePARTYSETTINGS_CLOSE].EventTick = GetTickCount();
	gInterface.Data[ePARTYSETTINGS_MAIN].Close();
	return false;
}

void cPartySearch::DrawPartySearchWindow(){

	if (!gInterface.Data[ePARTYSEARCH_MAIN].OnShow){
		return;
	}

	if (gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Character) //-- 13 & 16
		|| gInterface.CheckWindow(Warehouse) //-- 8
		|| gInterface.CheckWindow(Shop) //-- 12
		|| gInterface.CheckWindow(ChaosBox) //-- 9
		|| gInterface.CheckWindow(Trade) //-- 7
		|| gInterface.CheckWindow(Store) //-- 14
		|| gInterface.CheckWindow(OtherStore) //-- 15
		|| gInterface.CheckWindow(LuckyCoin1) //-- 60
		|| gInterface.CheckWindow(NPC_ChaosMix)
		|| gInterface.CheckWindow(MoveList)
		) //-- 76
	{
		gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;
		return;
	}
// ----
	float MainWidth			= 230.0;
	float MainHeight		= 320.0;
	float StartBody			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY			= 23.0;
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);
	// ----

	if (gInterface.IsWorkZone(ePARTYSEARCH_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;


      //gCItemSetOption.ItemTooltipS15(StartX, StartY, MainWidth, MainHeight, 0, 0);

	  RenderBitmap(500001,StartX-7, StartY-5, MainWidth+50, MainHeight+185, 0, 0, 1, 1, 1, 1, 0.0);


	if (gInterface.IsWorkZone(ePARTYSEARCH_CLOSE))
	{
		if (gInterface.Data[ePARTYSEARCH_CLOSE].OnClick)
		{
			PlayBuffer(25, 0, 0);
			gInterface.DrawButtonRender(ePARTYSEARCH_CLOSE, (int)StartX + 205, (int)StartY - 10, 0 , 28);
			
		}
		else
		{
			gInterface.DrawButtonRender(ePARTYSEARCH_CLOSE, (int)StartX + 205, (int)StartY - 10, 0 , 0);
			
		}
	}
	else
	{
		gInterface.DrawButtonRender(ePARTYSEARCH_CLOSE, (int)StartX + 205, (int)StartY - 10, 0 , 0);
		
	}
	gInterface.DrawFormat(eWhite, (int)StartX + 205, (int)StartY - 10, 59, 3, "");


	

	gInterface.DrawGUI(OBJECT_PARTYPASSWORD_REFRESH,(int)StartX + 130, (int)StartY + 10);

	if (gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_REFRESH))
	{
		DWORD Color = eExcellentS15;
		// ----
		if (gInterface.Data[OBJECT_PARTYPASSWORD_REFRESH].OnClick)
		{
			Color = eExcellentS15;
		}
		// ----
		gInterface.DrawColoredGUI(OBJECT_PARTYPASSWORD_REFRESH, gInterface.Data[OBJECT_PARTYPASSWORD_REFRESH].X, gInterface.Data[OBJECT_PARTYPASSWORD_REFRESH].Y, Color);

	}

	gInterface.DrawGUI(OBJECT_PARTYPASSWORD_RESETTING,(int)StartX + 170, (int)StartY + 10);

	if (gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_RESETTING))
	{
		DWORD Color = eExcellentS15;
		// ----
		if (gInterface.Data[OBJECT_PARTYPASSWORD_RESETTING].OnClick)
		{
			Color = eExcellentS15;
		}
		// ----
		gInterface.DrawColoredGUI(OBJECT_PARTYPASSWORD_RESETTING, gInterface.Data[OBJECT_PARTYPASSWORD_RESETTING].X, gInterface.Data[OBJECT_PARTYPASSWORD_RESETTING].Y, Color);
		//gInterface.DrawToolTip((int)gInterface.Data[eMenu_NEXT].X + 5, (int)gInterface.Data[eMenu_NEXT].Y + 25, "Next");
	}

	int x = 200;
	int y = 50;

	gInterface.DrawFormat(eWhite, StartX + 20, gInterface.Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "Status:");
	if (gPartySearchSettings.m_SystemActive == false){
		gInterface.DrawFormat(eRed, StartX + 42, gInterface.Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "OFF");
	}else{
		gInterface.DrawFormat(eShinyGreen, StartX + 42, gInterface.Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "ON");
	}
	gInterface.DrawGUI(ePARTYSETTINGS_DIV, StartX, gInterface.Data[ePARTYSEARCH_MAIN].Y + 40);
	gInterface.DrawFormat(eWhite, StartX + 5, gInterface.Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Player");
	gInterface.DrawFormat(eWhite, StartX + 45, gInterface.Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Map");
	gInterface.DrawFormat(eWhite, StartX + 95, gInterface.Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "X");
	gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Y");
	gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Count");
	gInterface.DrawFormat(eWhite, StartX + 170, gInterface.Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Join");
	gInterface.DrawGUI(ePARTYSETTINGS_DIV, StartX, gInterface.Data[ePARTYSEARCH_MAIN].Y + 60);
	if (gPartySearch.CountPages>1){
		gInterface.DrawFormat(eGold, StartX + 104, 379, 20, 3, "%d/%d", gPartySearch.Page + 1, gPartySearch.CountPages);
	}
	if (gPartySearch.Page + 1 > 1){
		gInterface.DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 0);
	}
	if (gPartySearch.Page + 1 < gPartySearch.CountPages){
		gInterface.DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 0);
	}
	int DrawnItems = 0;
	for (int i = 0; i<gPartySearch.ListsCount; i++){
		if (DrawnItems >= 10){
			break;
		}
		PARTYLIST* info = gPartySearch.GetPartyList(i + (10 * gPartySearch.Page));
		if (info == 0){
			continue;
		}
		pDrawGUI(0x7E98, StartX + 10, gInterface.Data[ePARTYSEARCH_MAIN].Y + 80 + (20 * i), 170, 21);
		gInterface.DrawFormat(eYellow, StartX + 15, gInterface.Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 1, info->Name);
		gInterface.DrawFormat(eWhite, StartX + 45, gInterface.Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, pGetMapName(info->Map));
		gInterface.DrawFormat(eWhite, StartX + 95, gInterface.Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d", info->X);
		gInterface.DrawFormat(eWhite, StartX + 115, gInterface.Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d", info->Y);
		gInterface.DrawFormat(eWhite, StartX + 140, gInterface.Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d / 10", info->Count); //hien thi so luong max party
		pDrawGUI(0x7E99, StartX + 178, gInterface.Data[ePARTYSEARCH_MAIN].Y + 80 + (i * 20), 22, 19);
		if (info->ButtonActive == true){
			pDrawButton(0x7AA4, StartX + 203, gInterface.Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20), 16, 15, 0, 0);
		}
		int X = StartX + 203;
		int Y = gInterface.Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20);
		int MaxX = X + 16;
		int MaxY = Y + 15;
		if (info->ButtonActive == true){
			if (this->IsWorkZone(X, Y, MaxX, MaxY)){
				pDrawColorButton(0x7AA4, X, Y, 16, 15, 0, 16, eGray100);
			}
		}
		DrawnItems++;
	}
	DrawnItems = 0;
	for (int i = 0; i<gPartySearch.ListsCount; i++){
		if (DrawnItems >= 10){
			break;
		}
		PARTYLIST* info = gPartySearch.GetPartyList(i + (10 * gPartySearch.Page));
		if (info == 0){
			continue;
		}
		int X = StartX + 178;
		int Y = gInterface.Data[ePARTYSEARCH_MAIN].Y + 80 + (i * 20);
		int MaxX = X + 22;
		int MaxY = Y + 19;
		if (this->IsWorkZone(X, Y, MaxX, MaxY)){
			char szText[2048];
			sprintf(szText, "Äiá»u kiá»‡n nhÃ³m\n Level:%d", info->Level);

			if (info->RequirePassword)
			{
				strcat(szText, "\nCÃ³ máº­t kháº©u");
			}

			if (info->DarkWizard == true){
				strcat(szText, "\nDark Wizard");
			}
			if (info->DarkKnight == true){
				strcat(szText, "\nDark Knight");
			}
			if (info->Elf == true){
				strcat(szText, "\nElf");
			}
			if (info->MagicGladiator == true){
				strcat(szText, "\nMagic Gladiator");
			}
			if (info->DarkLord == true){
				strcat(szText, "\nDark Lord");
			}
			if (info->Summoner == true){
				strcat(szText, "\nSummoner");
			}
			if (info->RageFighter == true){
				strcat(szText, "\nRage Fighter");
			}
			if (info->OnlyGuild == true){
				strcat(szText, "\nOnly Guild");
			}
			strcat(szText, "\n");
			this->DrawToolTipEx(eWhite, StartX + 230, gInterface.Data[ePARTYSEARCH_MAIN].Y + 62 + (i * 20), 100, 30, 3, szText);
		}
		DrawnItems++;
	}
	if (gPartySearch.Page + 1 > 1){
		if (gInterface.IsWorkZone(ePARTYSEARCH_LEFT)){
			if (gInterface.Data[ePARTYSEARCH_LEFT].OnClick){
				gInterface.DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 46);
				return;
			}
			gInterface.DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 23);
		}
	}
	if (gPartySearch.Page + 1 < gPartySearch.CountPages){
		if (gInterface.IsWorkZone(ePARTYSEARCH_RIGHT)){
			if (gInterface.Data[ePARTYSEARCH_RIGHT].OnClick){
				gInterface.DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 46);
				return;
			}
			gInterface.DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 23);
		}
	}
}

void cPartySearch::EventPartySearchWindow_All(DWORD Event){
	float StartX = (MAX_WIN_WIDTH / 2) - (230.0 / 2);
	DWORD CurrentTick = GetTickCount();
	if (!gInterface.Data[ePARTYSEARCH_MAIN].OnShow){
		return;
	}
	if (gInterface.IsWorkZone(ePARTYSEARCH_CLOSE)){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSEARCH_CLOSE].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSEARCH_CLOSE].OnClick = true;
			return;
		}
		gInterface.Data[ePARTYSEARCH_CLOSE].OnClick = false;
		if (Delay < 500){
			return;
		}
		gInterface.Data[ePARTYSEARCH_CLOSE].EventTick = GetTickCount();
		this->SwitchPartySearchWindowState();
	}
	if (gInterface.IsWorkZone(ePARTYSEARCH_LEFT) && gPartySearch.Page + 1 > 1){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSEARCH_LEFT].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSEARCH_LEFT].OnClick = true;
			return;
		}
		gInterface.Data[ePARTYSEARCH_LEFT].OnClick = false;
		if (Delay < 100){
			return;
		}
		gInterface.Data[ePARTYSEARCH_LEFT].EventTick = GetTickCount();
		gPartySearch.Page--;
	}
	if (gInterface.IsWorkZone(ePARTYSEARCH_RIGHT) && gPartySearch.Page + 1 < gPartySearch.CountPages){
		DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSEARCH_RIGHT].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[ePARTYSEARCH_RIGHT].OnClick = true;
			return;
		}
		gInterface.Data[ePARTYSEARCH_RIGHT].OnClick = false;
		if (Delay < 100){
			return;
		}
		gInterface.Data[ePARTYSEARCH_RIGHT].EventTick = GetTickCount();
		gPartySearch.Page++;
	}
	int DrawnItems = 0;
	for (int i = 0; i<gPartySearch.ListsCount; i++){
		if (DrawnItems >= 10){
			break;
		}
		if (this->IsWorkZone(StartX + 203, gInterface.Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20), StartX + 203 + 16, gInterface.Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20) + 15)){
			DWORD Delay = (CurrentTick - gInterface.Data[ePARTYSEARCH_RIGHT].EventTick);
			if (Event == WM_LBUTTONDOWN){
				gInterface.Data[ePARTYSEARCH_RIGHT].OnClick = true;
				return;
			}
			gInterface.Data[ePARTYSEARCH_RIGHT].OnClick = false;
			if (Delay < 100){
				return;
			}
			if (gPartySearch.gPartyList[i + (10 * gPartySearch.Page)].ButtonActive == false){
				return;
			}
			gInterface.Data[ePARTYSEARCH_RIGHT].EventTick = GetTickCount();

			if (gPartySearch.gPartyList[i + (10 * gPartySearch.Page)].RequirePassword)
			{
				this->SwitchPartySearchWindowState();
				gPartySearch.currentIndex = i + (10 * gPartySearch.Page);
				//gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Open();
				this->party_search_password_switch_state();
			}
			else
			{
				gPartySearch.SendPartyRequest(i + (10 * gPartySearch.Page));
			}
		}
	}
}

int cPartySearch::DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...){
	char Buff[2048];
	char Buff2[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	int LineCount = 0;
	strcpy(Buff2, Buff);
	char * Line = strtok(Buff2, "\n");
	while (Line != NULL){
		LineCount++;
		Line = strtok(NULL, "\n");
	}
	pSetBlend(1);
	glColor4f(0.0, 0.0, 0.0, 0.8);
	pDrawBarForm(PosX - 10, PosY, Width, LineCount * 10, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	gInterface.DrawFormat(eYellow170, PosX, PosY, Width, Align, Buff);
	return 0;
}

bool cPartySearch::IsWorkZone(float X, float Y, float MaxX, float MaxY){
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY)){
		return false;
	}
	return true;
}

void cPartySearch::DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color){
	if (gInterface.Data[ObjectID].X == -1 || gInterface.Data[ObjectID].Y == -1){
		gInterface.Data[ObjectID].X = PosX;
		gInterface.Data[ObjectID].Y = PosY;
		gInterface.Data[ObjectID].MaxX = PosX + gInterface.Data[ObjectID].Width;
		gInterface.Data[ObjectID].MaxY = PosY + gInterface.Data[ObjectID].Height;
	}
	pDrawColorButton(gInterface.Data[ObjectID].ModelID, PosX, PosY,gInterface.Data[ObjectID].Width, gInterface.Data[ObjectID].Height, ScaleX, ScaleY, Color);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
void cPartySearch::draw_party_password()
{
	if (!gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].OnShow)
	{
		return;
	}
	// ----
	float MainWidth = 230.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);

	pSetCursorFocus = true;
	// ----
	gInterface.DrawGUI(OBJECT_PARTYPASSWORD_MAIN, StartX, StartY + 2);
	gInterface.DrawGUI(OBJECT_PARTYPASSWORD_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(OBJECT_PARTYPASSWORD_FRAME, StartX, StartY + 67.0, 1);
	gInterface.DrawGUI(OBJECT_PARTYPASSWORD_FOOTER, StartX, StartY);
	gInterface.DrawGUI(OBJECT_PARTYPASSWORD_CLOSE, StartX + MainWidth - gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].Width + 2, 99);
	// ----
	if (gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(OBJECT_PARTYPASSWORD_CLOSE, gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].X, gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].X + 5, gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].Y + 25, "ÄÃ³ng");
	}
	// ----
	gInterface.DrawText(eGold, StartX + 10, 110, 210, 3, "Nháº­p máº­t kháº©u");

	if (gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].FirstLoad == true)
	{
		gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].Attribute = 1;
		sprintf(gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue, "");
	}

	gInterface.DrawGUI(OBJECT_PARTYPASSWORD_TEXTBOX, StartX + 28, gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Y + 46);
	if (gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].Attribute == 1)
	{
		gInterface.DrawColoredGUI(OBJECT_PARTYPASSWORD_TEXTBOX, StartX + 28, gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Y + 46, eGray100);
	}

	gInterface.DrawText(eWhite, StartX + 40, gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Y + 52, 200, 1, "Máº­t kháº©u");

	gInterface.DrawText(eWhite, StartX + 50, gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Y + 52, 200, 3, gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue);


	gInterface.DrawButton(OBJECT_PARTYPASSWORD_OK, StartX + gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Width / 2 - gInterface.Data[OBJECT_PARTYPASSWORD_OK].Width / 2, gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Y + 86, 0, 0);

	if (gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_OK))
	{
		int ScaleY = 30;
		// ----
		if (gInterface.Data[OBJECT_PARTYPASSWORD_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		gInterface.DrawButton(OBJECT_PARTYPASSWORD_OK, StartX + gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Width / 2 - gInterface.Data[OBJECT_PARTYPASSWORD_OK].Width / 2, gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Y + 86, 0, ScaleY);
	}


	if (gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].FirstLoad == true)
	{
		gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].FirstLoad = false;
	}
}


void cPartySearch::event_party_search_password_window(DWORD Event)
{
	if (!gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].OnShow)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	if (gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_TEXTBOX))
	{
		gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].Attribute = 1;
	}
	else
	{
		gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].Attribute = 0;
	}

	if (gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_OK))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYPASSWORD_OK].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYPASSWORD_OK].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYPASSWORD_OK].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYPASSWORD_OK].EventTick = GetTickCount();
		gPartySearch.SendPartyRequest(gPartySearch.currentIndex, gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue);
		this->party_search_password_switch_state();
	}

	if (gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_CLOSE))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].EventTick = GetTickCount();
		this->party_search_password_switch_state();
	}
}


bool cPartySearch::ControlTextBoxPTSearch(DWORD Event)
{
	if (gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].OnShow && gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].Attribute == 1)
	{
		char value[20];
		int is_backspace = false;
		int is_enter = false;
		int IsDelete = false;

		if (Event == VK_BACK)
		{
			is_backspace = true;
		}
		else if (Event == VK_RETURN)
		{
			is_enter = true;
		}
		else if (Event == VK_DELETE)
		{
			IsDelete = true;
		}
		else if ((Event >= 0x30 && Event <= 0x39) || (Event >= 0x60 && Event <= 0x69))
		{
			const int symbol = GetSymbolFromVK(Event);
			if (symbol == 0)
			{
				return 1;
			}
			char buff[10];
			sprintf(buff, "%c", symbol);
			strcpy_s(value, buff);
		}
		else
		{
			return true;
		}

		if (is_backspace == true)
		{
			if (!strcmp(gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue, ""))
			{
				return true;
			}
			gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue[strlen(gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue) - 1] = '\0';
		}
		else if (is_enter == true)
		{
			gPartySearch.SendPartyRequest(gPartySearch.currentIndex, gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue);
			gPartySearch.party_search_password_switch_state();
			return 1;
		}
		else if (IsDelete == true)
		{
			strcpy_s(gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue, "");
		}
		else
		{
			if (strlen(gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue) < 16)
			{
				if (!strcmp(gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue, ""))
				{
					strcpy_s(gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue, value);
				}
				else
				{
					strcat_s(gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue, value);
				}
			}
		}
	}
	else if (gInterface.Data[ePARTYSETTINGS_MAIN].OnShow && gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].Attribute == 1)
	{
		char value[20];
		int is_backspace = false;

		if (Event == VK_BACK)
		{
			is_backspace = true;
		}
		else if ((Event >= 0x30 && Event <= 0x39) || (Event >= 0x60 && Event <= 0x69))
		{
			const int Symbol = GetSymbolFromVK(Event);
			if (Symbol == 0)
			{
				return true;
			}
			char buff[10];
			sprintf(buff, "%c", Symbol);
			strcpy_s(value, buff);
		}
		else
		{
			return true;
		}

		if (is_backspace == true)
		{
			if (!strcmp(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, ""))//NONE
			{
				return true;
			}
			gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue[strlen(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue) - 1] = '\0';

			if (strlen(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue) == 0)
			{
				strcpy_s(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, "");//NONE
			}
		}
		else
		{
			if (strlen(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue) < 16)
			{
				if (!strcmp(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, ""))//NONE
				{
					strcpy_s(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, value);
				}
				else
				{
					strcat_s(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, value);
				}
			}
		}
	}

	return false;
}
//OBJECT_PARTYPASSWORD_REFRESH,
//	OBJECT_PARTYPASSWORD_RESETTING,

bool cPartySearch::ClickRefresh(DWORD Event)
{
	DWORD CurrentTick = GetTickCount() + 5000;
	DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYPASSWORD_REFRESH].EventTick);
	// ----
	if (!gInterface.Data[ePARTYSEARCH_MAIN].OnShow || !gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_REFRESH))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[OBJECT_PARTYPASSWORD_REFRESH].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[OBJECT_PARTYPASSWORD_REFRESH].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[OBJECT_PARTYPASSWORD_REFRESH].EventTick = GetTickCount() + 5000;
	this->SwitchPartySearchWindowState2();
	
		UP_PARTYSEARCH_REQ pMsg;
		pMsg.h.set(0xF3, 0x25, sizeof(pMsg));
		DataSend((BYTE*)&pMsg, pMsg.h.size);
		
	
	//----
	return false;
}

bool cPartySearch::ClickReSetting(DWORD Event)
{
	DWORD CurrentTick = GetTickCount() + 5000;
	DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYPASSWORD_RESETTING].EventTick);
	// ----
	if (!gInterface.Data[ePARTYSEARCH_MAIN].OnShow || !gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_RESETTING))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[OBJECT_PARTYPASSWORD_RESETTING].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[OBJECT_PARTYPASSWORD_RESETTING].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[OBJECT_PARTYPASSWORD_RESETTING].EventTick = GetTickCount() + 5000;
	this->CheckSetting();
	//----
	return false;
}


void cPartySearch::OpenWindow()
{

	if (gInterface.CheckWindow(ObjWindow::CreateGuild) || gInterface.CheckWindow(ObjWindow::ChatWindow) || gInterface.CheckWindow(ObjWindow::FriendList) || gInterface.CheckWindow(ObjWindow::NPC_Dialog) || gInterface.CheckWindow(ObjWindow::MuHelper) || gInterface.CheckWindow(ObjWindow::Store) || gInterface.CheckWindow(ObjWindow::Warehouse) || gInterface.CheckWindow(ObjWindow::Trade) || gInterface.CheckWindow(ObjWindow::CashShop))
	{
		return;
	}

	if ((GetTickCount() - gInterface.Data[ePARTYSETTINGS_MAIN].EventTick) < 500)
	{
		return;
	}

	//gInterface.Data[ePARTYSETTINGS_MAIN].EventTick = GetTickCount();
	//
	//if (gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == true)
	//{
	//	gInterface.Data[ePARTYSETTINGS_MAIN].OnShow = false;

	//	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	//	{
	//		pSetCursorFocus = false;
	//	}
	//	return;
	//}

	gInterface.CloseCustomWindow();

	//this->ClearCustomEventTime();

	//PMSG_CUSTOM_EVENTTIME_SEND pMsg;

	//pMsg.header.set(0xF3, 0xE8, sizeof(pMsg));

	//DataSend((BYTE*)&pMsg, pMsg.header.size);

	gInterface.Data[ePARTYSETTINGS_MAIN].OnShow = true;

	if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}


#endif