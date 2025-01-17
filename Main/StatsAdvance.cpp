#include "stdafx.h"
#include "protocol.h"
#include "Interface.h"
#include "StatsAdvance.h"
#include "Defines.h"


CStatsAdvance g_StatsAdvance;

CStatsAdvance::CStatsAdvance()
{
	this->m_Enable = false;
	this->m_Loaded = false;

	memset(&this->m_Data, 0, sizeof(this->m_Data));
}

CStatsAdvance::~CStatsAdvance()
{
}

void CStatsAdvance::Load()
{
	this->m_Enable = true;
}

void CStatsAdvance::DrawInfo()
{
	if (!this->m_Enable && !this->m_Loaded)
	{
		return;
	}

	if (!gInterface.CheckWindow(ObjWindow::Character))
	{
		return;
	}

	////--Advance Status Icon
	//if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 2)
	//{
	//	if(gProtect.m_MainInfo.DisableAdvance == 0)
	//	{
	//	gInterface.BindObject(eADVANCE_STAT_INFO, ex_INFO_2, 22, 19, -1, -1);
	//	}
	//	//--
	//	LoadBitmapA("Custom\\Interface\\info_block.tga", ex_INFO_2, 0x2601, 0x2900, 1, 0);
	//}

	DWORD dwColor = eWhite;
	float flDrawX = this->m_CharX + 593;	//450;
	float flDrawY = this->m_CharY + 101;	//18;

	gInterface.DrawGUI(eADVANCE_STAT_INFO, flDrawX, flDrawY-10);

	if (!gInterface.IsWorkZone(eADVANCE_STAT_INFO))
	{
		return;
	}

	flDrawX = this->m_CharX + 450;	// - 15;
	flDrawY = 0;//this->m_CharY - 52;	//18;

	float flWidth = 190;
	float flHight = 430;

	gInterface.DrawBarForm(flDrawX, flDrawY, flWidth, flHight, 0, 0, 0, 1.0);
	flDrawY += 15;

	this->DrawLine(flDrawX, flDrawY, flWidth, "Phản Sát Thương:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.TotalDamageReflect);
		
	this->DrawLine(flDrawX, flDrawY, flWidth, "Sát Thương Chí Mạng:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.CriticalDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Sát Thương Chí Mạng (Quái Vật):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eBlue, "%d", this->m_Data.CriticalDamagePVM);

	this->DrawLine(flDrawX, flDrawY, flWidth, "Sát Thương Chí Mạng (Người Chơi)");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eBlue, "%d", this->m_Data.CriticalDamagePVP);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Sát Thương Hoàn Hảo:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ExellentDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Sát Thương Hoàn Hảo (Quái Vật):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eAncient, "%d", this->m_Data.ExellentDamagePVM);

	this->DrawLine(flDrawX, flDrawY, flWidth, "Sát Thương Hoàn Hảo (Người Chơi):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eAncient, "%d", this->m_Data.ExellentDamagePVP);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Sát Thương X2:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.DoubleDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Sát Thương X3:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.TripleDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Giảm Sát Thương:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.DamageReductionRate);

	this->DrawLine(flDrawX, flDrawY, flWidth, "Giảm Sát Thương (Gia Cường Dòng Vàng):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.SDDamageReductionRate);
			
	this->DrawLine(flDrawX, flDrawY, flWidth, "SD Giảm Tỷ Lệ Sát Thương:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.SDDecreaseDamageRate);
		
	this->DrawLine(flDrawX, flDrawY, flWidth, "Bỏ Qua Phòng Thủ Của Đối Phương:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.IgnoreDefenceRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Bỏ Qua Phòng Thủ SD Của Đối Phương:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.IgnoreSDRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Tăng Sát Thương PvP:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d", this->m_Data.IncreaseDamagePvP);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Tăng Phòng Thủ PvP:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d", this->m_Data.IncreaseDefencePvP);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Chống Lại Dame X2 Của Đối Phương:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ResistDoubleDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Chống Lại Bỏ Qua Phòng Thủ Của Đối Phương:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ResistIgnoreDefenceRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Chống Lại Bỏ Qua Tỷ Lệ SD Của Đối Phương:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ResistIgnoreSDRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Chống Lại Sát Thương Chí Mạng Của Đối Phương:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ResistCriticalDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Chống Lại Sát Thương Hoàn Hảo Của Đối Phương:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ResistExellentDamageRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Chống Lại Đóng Băng Của Đối Phương:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%%", this->m_Data.ResistStumRate);
		
	this->DrawLine(flDrawX, flDrawY, flWidth, "Tỷ Lệ Hồi Phục Tất Cả HP:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%% - %d%%", this->m_Data.FullHPRestoreRateDef, this->m_Data.FullHPRestoreRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Tỷ Lệ Hồi Phục Tất Cả Mana:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%% - %d%%", this->m_Data.FullMPRestoreRateDef, this->m_Data.FullMPRestoreRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Tỷ Lệ Hồi Phục Tất Cả SD:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%% - %d%%", this->m_Data.FullSDRestoreRateDef, this->m_Data.FullSDRestoreRate);

	gInterface.DrawFormat(eColorAdvance, flDrawX, 5, flWidth, 3, "Thông Tin Nhân Vật");

}

void CStatsAdvance::DrawLine(float PosX, float PosY, int Width, LPCSTR Text, ...)
{
	float flResult = 0.0;

	char szBuff[256];
	int iBuffLen = sizeof(szBuff) - 1;
	ZeroMemory(szBuff, iBuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(szBuff, iBuffLen, Text, args);
	va_end(args);

	pDrawColorText(szBuff, PosX + 10, PosY, 150, 0, eWhite, 0, 1);
}

float CStatsAdvance::DrawLineR(float PosX, float PosY, int Width, DWORD dwColor, LPCSTR Text, ...)
{
	float flResult = 0.0;

	char szBuff[256];
	int iBuffLen = sizeof(szBuff) - 1;
	ZeroMemory(szBuff, iBuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(szBuff, iBuffLen, Text, args);
	va_end(args);

	pDrawColorText(szBuff, PosX + 140, PosY, 50, 0, dwColor, 0, 1);

	pDrawColorButton(31460, PosX + 10, PosY + 10, Width - 20, 0.85, NULL, NULL, eOrange);

	flResult = PosY + 12;

	return flResult;
}

void CStatsAdvance::Recv(PMSG_STATS_ADVANCE* lpMsg)
{
	if (!lpMsg->Result)
	{
		return;
	}

	memcpy(&this->m_Data, &lpMsg->StatInfo, sizeof(this->m_Data));

	this->m_Loaded = true;
}