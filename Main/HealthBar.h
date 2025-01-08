#pragma once

#define MAX_MAIN_VIEWPORT 400
#define RGBTOGLFLOAT(x) ((float)x/255.0f)
#define FLOATTORGB(x)	((float)x*255)
#define ABS(x) (((x) < 0) ? (-(x)) : (x))
#include "Protocol.h"

struct NEW_HEALTH_BAR
{
	WORD index;
	BYTE type;
	BYTE rate;
	WORD monsterid;
	float Life;
	float MaxLife;
	short Level;
	int Reset;
	int Shield;
	int MaxShield;
	BYTE SDrate;
	bool isSameGuild;
	bool HaveGuild;
	char GuildName[11];
	BYTE Mark[64];
	//BYTE Rank;
	BYTE bHasManyFlag;
	int ItemID;
};

void ClearNewHealthBar();
void InsertNewHealthBar(PMSG_NEW_HEALTH_RECV* lpInfo);
NEW_HEALTH_BAR* GetNewHealthBar(WORD index,BYTE type);
//void DrawNewHealthBar();
void DrawHealthBar(void * item_data);
bool IsPartyMember(int ViewportID);
bool PlayerHasManyFlag(WORD index);