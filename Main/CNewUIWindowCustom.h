#pragma once

class CNewUIWindowCustom
{
public:
	CNewUIWindowCustom();
	~CNewUIWindowCustom();
	void		keyPressed(DWORD);
	uintInput	*bufferUint;

	uintInput	*ResetAddStr;
	uintInput	*ResetAddAgi;
	uintInput	*ResetAddVit;
	uintInput	*ResetAddEne;
	uintInput	*ResetAddCmd;

	GUIObj		*ResetWindow;
	GUIButton	*ResetOK;
	GUIButton	*ResetCANCEL;

	GUICheckbox *ResetTypeNOR;
	GUICheckbox *ResetTypeVIP;


	uintInput	*ResetAddPoint[5];
	GUICheckbox *AddPoint[5];

	GUICheckbox *AddStr;
	GUICheckbox *AddAgi;
	GUICheckbox *AddVit;
	GUICheckbox *AddEne;
	GUICheckbox *AddCmd;

	//GUItga		*XulieFlowResource;
	GUItga		*shandianCosredResource;
	//GUIAnimation *XulieFlow;
	GUIAnimation *shandianCosred;
	//windows original
	GUIObj		*CustomChaosBox;
	GUIObj      *CustomInvExt;
	//ware
	GUIObj		*CustomWareOP;
	GUIbutton   *WareOPKG[11];
	//custom list
	GUIObj		*CustomList;
	GUIbutton	*CustomButton[8];
	GUIbutton	*CustomClose;
	//new menu op
	GUIObj		*CustomMenuOP;
	GUICheckbox *MenuOPKG[15];
	/*Buy Vip*/
    GUIObj      *CustomBuyVIP;
	GUIbutton	*CustomButtonVIP[3];
	/*Event Time*/
	GUIObj      *CustomEventTime;
	GUIbutton   *CustomButtonEvent[2];
	/*Ranking*/
	GUIObj      *CustomRanking;
	GUIbutton   *CustomRankingBTN[2];
	/*CommandInfo*/
	GUIObj      *CustomCommandInfo;
	GUIbutton   *CustomCommandInfoBTN[2];
	/*LuckyWheel*/
	GUIObj      *CustomLuckyWheel;
	GUIbutton   *CustomLuckyWheelBTN[2];
	/*SmithItem*/
	GUIObj      *CustomSmithItem;
	GUICheckbox *CustomCheckBox[14];
	GUIbutton   *CustomSmithBTN[2];
	GUIbutton   *prevButton[5];
	GUIbutton   *nextButton[5];
	/*Windows X803*/
	GUIbutton   *CloseWindowsUP;
private:

};extern CNewUIWindowCustom CustomWindow;
