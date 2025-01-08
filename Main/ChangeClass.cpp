#include "stdafx.h"
#include "ChangeClass.h"
#include "Interface.h"

cChangeClass gChangeClass;

cChangeClass::cChangeClass()
{
	//this->m_Price = 0;
	this->m_WCoinC = 0;
}

cChangeClass::~cChangeClass()
{
	
}

void cChangeClass::BinObeject()
{
	gInterface.BindObject(eCHANGINGCLASS_MAIN, 31461, 640, 419, -1, -1);  // 31461
	//gInterface.BindObject(eCHANGINGCLASS_TITLE, 0x7A63, 230, 67, -1, -1);
	//gInterface.BindObject(eCHANGINGCLASS_FRAME, 0x7A58, 230, 15, -1, -1);
	//gInterface.BindObject(eCHANGINGCLASS_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eCHANGINGCLASS_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eCHANGINGCLASS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(eCHANGINGCLASS_INFOBG, 0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eCHANGINGCLASS_MONEYBG, 0x7A89, 170, 26, -1, -1);
	gInterface.BindObject(eCHANGINGCLASS_DW, 0x7A5E, 106, 29, -1, -1);
	gInterface.BindObject(eCHANGINGCLASS_DK, 0x7A5E, 106, 29, -1, -1);
	gInterface.BindObject(eCHANGINGCLASS_ELF, 0x7A5E, 106, 29, -1, -1);
	gInterface.BindObject(eCHANGINGCLASS_MG, 0x7A5E, 106, 29, -1, -1);
	gInterface.BindObject(eCHANGINGCLASS_DL, 0x7A5E, 106, 29, -1, -1);
	gInterface.BindObject(eCHANGINGCLASS_SUM, 0x7A5E, 106, 29, -1, -1);
	gInterface.BindObject(eCHANGINGCLASS_RF, 0x7A5E, 106, 29, -1, -1);
}


void cChangeClass::RecvData(PMSG_CHANGECLASS_DATA* Data)
{
	//this->m_PriceType = Data->PriceType;
	//this->m_Price = Data->Price;
	this->m_WCoinC = Data->m_WCoinC;
}

void cChangeClass::SendChangeClass(int Type)
{
	gInterface.Data[eCHANGINGCLASS_MAIN].Close();
	CG_CHANGECLASS_SEND pRequest;
	pRequest.Head.set(0xFF,0x06,sizeof(pRequest));
	
	pRequest.Type = Type;

	DataSend((BYTE*)&pRequest,pRequest.Head.size);
}