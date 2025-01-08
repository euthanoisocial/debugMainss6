#include "stdafx.h"

#include "RegisterMain.h"
#include "Offset.h"
#include "Util.h"
#include "Defines.h"
#include "Import.h"
 
 
RegisterMain gRegisterMain;


 short  GetSymbolFromVK2(WPARAM wParam)
 {
 	BYTE btKeyState[256];
 	HKL hklLayout = GetKeyboardLayout(0);
 	WORD Symbol;
 	GetKeyboardState(btKeyState);
 	if ((ToAsciiEx(wParam, MapVirtualKey(wParam, 0), btKeyState, &Symbol, 0, hklLayout) == 1))
 	{
 		return Symbol;
 	}
 	return 0;
 }
bool RegisterMain::TexBoxC(KBDLLHOOKSTRUCT Hook)
{ 
	return false;
}



bool CheckName2(char* szID)
{
	if (FindText2(szID, " ", 0) || FindText2(szID, "¡¡", 0) ||
		FindText2(szID, ".", 0) || FindText2(szID, "¡¤", 0) ||
		FindText2(szID, "¡­", 0) || FindText2(szID, "Webzen", 0) ||
		FindText2(szID, "WebZen", 0) || FindText2(szID, "webzen", 0) ||
		FindText2(szID, "WEBZEN", 0) || FindText2(szID, GlobalText(GlobalLine, 457), 0) ||
		FindText2(szID, GlobalText(GlobalLine, 458), 0))
	{
		return true;
	}
	return false;
}
       char iUser1[32],iPassword1[32];
       char iUser2[32],iPassword2[32];
       char iUser3[32],iPassword3[32];
       char iUser4[32],iPassword4[32];
       char iUser5[32],iPassword5[32];
       char iUser6[32],iPassword6[32];



void InitRegistro()
{
	//SetDword(0x0040C989 + 3, 1);

	//SetCompleteHook(0xE8, 0x004D7EB1, &RenderInformacion);

	///SetCompleteHook(0xE8, 0x0040B5A9, &RegisterMain::ButtonsController);
	
}

void RegisterMain::SendRegisterRequest(char* account, char* password,char* name, char* phone ,char* numcode , char* email)
{
	PMSG_REGISTER_MAIN_SEND pMsg;

	//pMsg.header.set(0xF3, 0xEF, sizeof(pMsg));
	//memcpy(pMsg.account, account, sizeof(pMsg.account));
	//memcpy(pMsg.password, password, sizeof(pMsg.password));
	//memcpy(pMsg.name, name, sizeof(pMsg.name));
	//memcpy(pMsg.phone, phone, sizeof(pMsg.phone));
	//memcpy(pMsg.numcode, numcode, sizeof(pMsg.numcode));
 //   memcpy(pMsg.email, email, sizeof(pMsg.email));
	//DataSend((BYTE*)&pMsg, pMsg.header.size);
}
