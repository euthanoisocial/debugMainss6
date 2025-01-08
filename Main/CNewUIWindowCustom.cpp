#include "stdafx.h"

#include "CNewUIWindowsClient.h"
#include "CNewUIWindowCustom.h"
#include "CustomFont.h"
#include "Interface.h"

#include "Defines.h"
#include "CNewUIMacro.h"
#include "CustomEventTime.h"
#include "CustomBuyVip.h"
#include "CustomRanking.h"
#include "Common.h"
#include "CustomFog.h"
#include "ChatExpanded.h"
#include "CustomMessage.h"
#include "Protect.h"
#include "User.h"

CNewUIWindowCustom CustomWindow;

CNewUIWindowCustom::CNewUIWindowCustom()
{
	char i;
	//Reset System
	this->ResetWindow	= new GUIObj(200, 20, 150, 350, true);
	this->ResetOK		= new GUIButton(220, 300, 60, 30, 150);
	this->ResetCANCEL	= new GUIButton(310, 300, 60, 30, 150);

	for (i = 0; i < 5; i++) {
		this->AddPoint[i] = new GUICheckbox(0, 0, 10, 12, 150);
		this->ResetAddPoint[i] = new uintInput(0, 1999999999, 0);
	}
	this->bufferUint	= new uintInput(0, 4000000000, 50);
	
	this->ResetTypeNOR	= new GUICheckbox(0, 0, 10, 12, 150);
	this->ResetTypeVIP	= new GUICheckbox(0, 0, 10, 12, 150);
	//END Reset System
	gCMacroUIEx.XulieFlowResource = new GUItga(0xF2000, 256, 128, 768, 384);
	gCMacroUIEx.shandianCosredResource = new GUItga(0xF2001, 64, 64, 256, 256);
	gCMacroUIEx.XulieFlow = new GUIAnimation(gCMacroUIEx.XulieFlowResource, 200, 100, 256, 128, 9, 3, 3, 125);
	gCMacroUIEx.shandianCosred = new GUIAnimation(gCMacroUIEx.shandianCosredResource, 200, 100, 64, 64, 9, 3, 3, 125);



	gCMacroUIEx.macroSwitchServer = new GUIbutton;
	gCMacroUIEx.macroSwitchServer->data = new GUIButton(-100, 1, 35, 10, 150);
	gCMacroUIEx.macroSwitchServer->normalFrame = new GUIresource(0xF3001, 59, 20, 779, 42, 1024, 256, 1.5, 1.75);
	gCMacroUIEx.macroSwitchServer->hoverFrame = new GUIresource(0xF3001, 59, 20, 720, 42, 1024, 256, 1.5, 1.75);
	gCMacroUIEx.macroSwitchServer->clickedFrame = new GUIresource(0xF3001, 59, 20, 779, 42, 1024, 256, 1.5, 1.75);
	gCMacroUIEx.macroSwitchServer->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);


	gCMacroUIEx.macroSwitchServerHover = new GUIbutton;
	gCMacroUIEx.macroSwitchServerHover->data = new GUIButton(12.5, 3, 166 / 1.5, 24 / scale_ratio, 0);
	gCMacroUIEx.macroSwitchServerHover->normalFrame = new GUIresource(0xF3001, 0, 0, 385, 44, 1024, 256, 2, 2);
	gCMacroUIEx.macroSwitchServerHover->hoverFrame = new GUIresource(0xF3001, 166, 20, 385, 45, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerHover->clickedFrame = new GUIresource(0xF3001, 0, 0, 385, 44, 1024, 256, 2, 2);
	gCMacroUIEx.macroSwitchServerHover->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);


	gCMacroUIEx.macroSwitchServerSliderUp = new GUIbutton;
	gCMacroUIEx.macroSwitchServerSliderUp->data = new GUIButton(121, 21.5, 24 / 1.5, 16 / 1.5, 150);
	gCMacroUIEx.macroSwitchServerSliderUp->normalFrame = new GUIresource(0xF3001, 24, 16, 547 - 24, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderUp->hoverFrame = new GUIresource(0xF3001, 24, 16, 523 - 24, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderUp->clickedFrame = new GUIresource(0xF3001, 24, 16, 403, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderUp->disabledFrame = new GUIresource(0xF3001, 24, 16, 499 - 24, 73, 1024, 256, 1.5, 1.5);

	gCMacroUIEx.macroSwitchServerSliderDown = new GUIbutton;
	gCMacroUIEx.macroSwitchServerSliderDown->data = new GUIButton(121, 158.5, 24 / 1.5, 16 / 1.5, 150);
	gCMacroUIEx.macroSwitchServerSliderDown->normalFrame = new GUIresource(0xF3001, 24, 16, 451, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderDown->hoverFrame = new GUIresource(0xF3001, 24, 16, 427, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderDown->clickedFrame = new GUIresource(0xF3001, 24, 16, 571, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderDown->disabledFrame = new GUIresource(0xF3001, 24, 16, 547, 73, 1024, 256, 1.5, 1.5);

	gCMacroUIEx.macroLog = new GUIbutton;
	gCMacroUIEx.macroLog->data = new GUIButton(67, 8, 18, 18, 150);
	gCMacroUIEx.macroLog->normalFrame = new GUIresource(0xF3001, 28, 28, 752, 1, 1024, 256, 2.2, 2.2);
	gCMacroUIEx.macroLog->hoverFrame = new GUIresource(0xF3001, 28, 28, 783, 1, 1024, 256, 2.2, 2.2);
	gCMacroUIEx.macroLog->clickedFrame = new GUIresource(0xF3001, 28, 28, 814, 1, 1024, 256, 2.2, 2.2);
	gCMacroUIEx.macroLog->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gCMacroUIEx.macroConfig = new GUIbutton;
	gCMacroUIEx.macroConfig->data = new GUIButton(67+ 18, 8 , 18, 18, 150);
	gCMacroUIEx.macroConfig->normalFrame = new GUIresource(0xF3001, 28, 28, 877, 1, 1024, 256, 2.2, 2.2);
	gCMacroUIEx.macroConfig->hoverFrame = new GUIresource(0xF3001, 28, 28, 970, 1, 1024, 256, 2.2, 2.2);
	gCMacroUIEx.macroConfig->clickedFrame = new GUIresource(0xF3001, 28, 28, 355, 44, 1024, 256, 2.2, 2.2);
	gCMacroUIEx.macroConfig->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gCMacroUIEx.macroAuto = new GUIbutton;
	gCMacroUIEx.macroAuto->data = new GUIButton(67+  18 * 2, 8 , 18, 18, 150);
	gCMacroUIEx.macroAuto->normalFrame = new GUIresource(0xF3001, 28, 28, 231, 44, 1024, 256, 2.2, 2.2);
	gCMacroUIEx.macroAuto->hoverFrame = new GUIresource(0xF3001, 28, 28, 262, 44, 1024, 256, 2.2, 2.2);
	gCMacroUIEx.macroAuto->clickedFrame = new GUIresource(0xF3001, 28, 28, 293, 44, 1024, 256, 2.2, 2.2);
	gCMacroUIEx.macroAuto->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gCMacroUIEx.macroPauseAuto = new GUIbutton;
	gCMacroUIEx.macroPauseAuto->data = new GUIButton(67 +  18 * 2, 8, 18, 18, 150);
	gCMacroUIEx.macroPauseAuto->normalFrame = new GUIresource(0xF3001, 28, 28, 691, 1, 1024, 256, 2.2, 2.2);
	gCMacroUIEx.macroPauseAuto->hoverFrame = new GUIresource(0xF3001, 28, 28, 722, 1, 1024, 256, 2.2, 2.2);
	gCMacroUIEx.macroPauseAuto->clickedFrame = new GUIresource(0xF3001, 28, 28, 908, 1, 1024, 256, 2.2, 2.2);
	gCMacroUIEx.macroPauseAuto->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);


	//custom window

	this->CustomList = new GUIObj(200, 20, 190, 340, true);

	for (i = 0; i < 9; i++){
		this->CustomButton[i] = new GUIbutton;
		this->CustomButton[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomButton[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButton[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButton[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButton[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}


	this->CustomClose = new GUIbutton;
	this->CustomClose->data = new GUIButton(190 + 190 / 1.5, 30, 20 / 1.5, 20 / 1.5, 150);
	this->CustomClose->normalFrame = new GUIresource(0xF1009, 20, 19, 1002, 20, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CustomClose->hoverFrame = new GUIresource(0xF1009, 20, 19, 981, 20, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CustomClose->clickedFrame = new GUIresource(0xF1009, 20, 19, 1002, 0, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CustomClose->disabledFrame = new GUIresource(0xF1009, 20, 19, 981, 0, 1024, 512, pWinWidthReal, pWinHeightReal);

	//new menu op
    this->CustomMenuOP = new GUIObj(200, 20, 190, 340, true);
	for (i = 0; i < 15; i++) {
		this->MenuOPKG[i] = new GUICheckbox(0, 0, 10, 12, 150);
	}

	//chaosbox
	this->CustomChaosBox = new GUIObj(200, 20, 190, 440, true);
	this->CustomInvExt = new GUIObj(200, 20, 190, 440, true);

	//Multi Ware
	this->CustomWareOP = new GUIObj(200, 20, 190, 260, true);
	for (i = 0; i < 11; i++) {
		this->WareOPKG[i] = new GUIbutton;
		this->WareOPKG[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->WareOPKG[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->WareOPKG[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->WareOPKG[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->WareOPKG[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}

	/*Buy VIP*/
	this->CustomBuyVIP = new GUIObj(200, 20, 190, 340, true);
	for (i = 0; i < 3; i++){
		this->CustomButtonVIP[i] = new GUIbutton;
		this->CustomButtonVIP[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomButtonVIP[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButtonVIP[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButtonVIP[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButtonVIP[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}

	/*Event Time*/
	this->CustomEventTime = new GUIObj(200, 20, 190, 340, true);
	for (i = 0; i < 2; i++){
		this->CustomButtonEvent[i] = new GUIbutton;
		this->CustomButtonEvent[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomButtonEvent[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButtonEvent[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButtonEvent[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButtonEvent[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}

	/*Ranking*/
	this->CustomRanking = new GUIObj(200, 20, 190, 340, true);
	for (i = 0; i < 2; i++){
		this->CustomRankingBTN[i] = new GUIbutton;
		this->CustomRankingBTN[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomRankingBTN[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomRankingBTN[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomRankingBTN[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomRankingBTN[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}

	/*Command Info*/
	this->CustomCommandInfo = new GUIObj(200, 20, 190, 340, true);
	for (i = 0; i < 2; i++){
		this->CustomCommandInfoBTN[i] = new GUIbutton;
		this->CustomCommandInfoBTN[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomCommandInfoBTN[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomCommandInfoBTN[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomCommandInfoBTN[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomCommandInfoBTN[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}

	/*LuckyWheel*/
	this->CustomLuckyWheel = new GUIObj(200, 20, 340, 340, true);
	for (i = 0; i < 2; i++){
		this->CustomLuckyWheelBTN[i] = new GUIbutton;
		this->CustomLuckyWheelBTN[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomLuckyWheelBTN[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomLuckyWheelBTN[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomLuckyWheelBTN[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomLuckyWheelBTN[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}

	/*Smith Item*/
	this->CustomSmithItem = new GUIObj(200, 20, 190, 420, true);
	for (i = 0; i < 5; i++) {
	    this->nextButton[i] = new GUIbutton;
	    this->nextButton[i]->data = new GUIButton(0, 0, 17, 17, 150);
	    this->nextButton[i]->normalFrame = new GUIresource(0xF1003, 17, 17, 372, 328, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	    this->nextButton[i]->hoverFrame = new GUIresource(0xF1003, 17, 17, 351, 328, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	    this->nextButton[i]->clickedFrame = new GUIresource(0xF1003, 17, 17, 330, 328, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	    this->nextButton[i]->disabledFrame = new GUIresource(0xF1003, 17, 17, 727, 298, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}
	for (i = 0; i < 5; i++) {
	    this->prevButton[i] = new GUIbutton;
	    this->prevButton[i]->data = new GUIButton(0, 0, 17, 17, 150);
	    this->prevButton[i]->normalFrame = new GUIresource(0xF1003, 17, 17, 434, 328, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	    this->prevButton[i]->hoverFrame = new GUIresource(0xF1003, 17, 17, 413, 328, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	    this->prevButton[i]->clickedFrame = new GUIresource(0xF1003, 17, 17, 392, 328, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	    this->prevButton[i]->disabledFrame = new GUIresource(0xF1003, 17, 17, 685, 298, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}
	for (i = 0; i < 14; i++) {
        this->CustomCheckBox[i] = new GUICheckbox(0, 0, 10, 12, 150);
	}
	for (i = 0; i < 2; i++){
		this->CustomSmithBTN[i] = new GUIbutton;
		this->CustomSmithBTN[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomSmithBTN[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomSmithBTN[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomSmithBTN[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomSmithBTN[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}
#if(CHANGE_CLASS_SYSTEM==1)
	/*Change Class System*/
	this->CustomChangeClass = new GUIObj(200, 20, 190, 340, true);
	for (i = 0; i < 7; i++){
		this->CustomChangeClassBTN[i] = new GUIbutton;
		this->CustomChangeClassBTN[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomChangeClassBTN[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal, pWinHeightReal);
		this->CustomChangeClassBTN[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal, pWinHeightReal);
		this->CustomChangeClassBTN[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal, pWinHeightReal);
		this->CustomChangeClassBTN[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal, pWinHeightReal);
	}
#endif
	/*Windows Struct x803*/
	this->CloseWindowsUP= new GUIbutton;
	this->CloseWindowsUP->data = new GUIButton(190 + 190 / 1.5, 30, 20 / 1.5, 20 / 1.5, 150);
	this->CloseWindowsUP->normalFrame = new GUIresource(0xF1009, 20, 19, 1002, 20, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CloseWindowsUP->hoverFrame = new GUIresource(0xF1009, 20, 19, 981, 20, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CloseWindowsUP->clickedFrame = new GUIresource(0xF1009, 20, 19, 1002, 0, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CloseWindowsUP->disabledFrame = new GUIresource(0xF1009, 20, 19, 981, 0, 1024, 512, pWinWidthReal, pWinHeightReal);
}

CNewUIWindowCustom::~CNewUIWindowCustom()
{
}

DWORD	SetInvisibleEffect_PointerYY;
DWORD	SetInvisibleEffect_BuffYY;
DWORD	SetInvisibleEffect_PointerY;
DWORD	SetInvisibleEffect_BuffY;
DWORD	ObjectPointer;

__declspec(naked) void ItemInvisible1(){
	static DWORD m_aaaaab = 0x0060B37A;
		_asm{
		    mov SetInvisibleEffect_BuffYY, esi
		    mov ecx, dword ptr ss : [ebp + 8]
		    mov esi, dword ptr ds : [ecx + 0x30]
		    mov SetInvisibleEffect_PointerYY, esi
		    mov esi, SetInvisibleEffect_BuffYY
		}
		if(SetInvisibleEffect_PointerYY != 0x1EA5
		|| SetInvisibleEffect_PointerYY != ITEM2(12, 15) 
		|| SetInvisibleEffect_PointerYY != ITEM2(12, 30)
		|| SetInvisibleEffect_PointerYY != ITEM2(12, 31)
		|| SetInvisibleEffect_PointerYY != ITEM2(12, 136)
		|| SetInvisibleEffect_PointerYY != ITEM2(12, 137)
		|| SetInvisibleEffect_PointerYY != ITEM2(12, 138)
		|| SetInvisibleEffect_PointerYY != ITEM2(12, 139)
		|| SetInvisibleEffect_PointerYY != ITEM2(12, 140)
		|| SetInvisibleEffect_PointerYY != ITEM2(12, 141)
		|| SetInvisibleEffect_PointerYY != ITEM2(12, 142)
		|| SetInvisibleEffect_PointerYY != ITEM2(12, 143)
		|| SetInvisibleEffect_PointerYY != ITEM2(14, 13)
		|| SetInvisibleEffect_PointerYY != ITEM2(14, 14)
		|| SetInvisibleEffect_PointerYY != ITEM2(14, 16)
		|| SetInvisibleEffect_PointerYY != ITEM2(14, 31)
		|| SetInvisibleEffect_PointerYY != ITEM2(14, 42)
		|| SetInvisibleEffect_PointerYY != ITEM2(14, 13)
		|| SetInvisibleEffect_PointerYY != ITEM2(14, 41)
		|| SetInvisibleEffect_PointerYY != ITEM2(14, 43)
		|| SetInvisibleEffect_PointerYY != ITEM2(14, 44))
		{
		_asm{
			jmp [m_aaaaab]
		}
	}
}
__declspec(naked) void ItemInvisible2(){
	static DWORD m_aaaaaa = 0x0060B41D;
	_asm{
		mov SetInvisibleEffect_BuffY, esi
		mov ecx, dword ptr ss : [ebp + 8]
		mov esi, dword ptr ds : [ecx + 0x30]
		jmp [m_aaaaaa]
	}
}
DWORD	SetInvisibleEffect_PointerX;
DWORD	SetInvisibleEffect_BuffX;

Naked(InvisibleEffectX){
	_asm{
		mov SetInvisibleEffect_BuffX, esi
		mov ecx, dword ptr ss : [ebp + 8]
		mov esi, dword ptr ds : [ecx + 0x30]
		mov SetInvisibleEffect_PointerX, esi
		mov esi, SetInvisibleEffect_BuffX
	}
	if (SetInvisibleEffect_PointerX == 0x1EA5 || SetInvisibleEffect_PointerX == ITEM2(13, 18)){
	    _asm{
			mov SetInvisibleEffect_BuffX, 0x0060B37A
			jmp SetInvisibleEffect_BuffX
		}
	}else{
		_asm{
			mov SetInvisibleEffect_BuffX, 0x0060B41D
			jmp SetInvisibleEffect_BuffX
		}
	}
}
#include "Util.h"
#include "TMemory.h"
void InvisibleItem1(){
	SetCompleteHook(0xE9, 0x0060B36A, &ItemInvisible1);
}
void InvisibleItem2(){
	SetCompleteHook(0xE9, 0x0060B36A, &ItemInvisible2);
}
void InvisibleItemX(){
	SetRange((LPVOID)0x0060B36A, 10, ASM::NOP); //12
	SetCompleteHook(0xE9, 0x0060B36A, &InvisibleEffectX);
}

void InivisibleObjects1(){
	SetByte((PVOID)(0x005DE2B2), 1);
}
void InivisibleObjects2(){
	SetByte((PVOID)(0x005DE2B2), 0);
}

void Effect151(){
	MemorySet(0x0057655B,0x90,0x5);
}
void Effect152(){
	SetOp((LPVOID)0x0057655B,(LPVOID)0x006097B0,ASM::CALL);
}

void InvisibleWeapon1(){
	MemorySet(0x576DDB,0x90,0x5);
	MemorySet(0x5883F4,0x90,0x5);
}
void InvisibleWeapon2(){
	SetOp((LPVOID)0x00576DDB,(LPVOID)0x005655C0,ASM::CALL);
	SetOp((LPVOID)0x005883F4,(LPVOID)0x005655C0,ASM::CALL);
}

void InvisibleWings1(){
	MemorySet(0x588661,0x90,0x5);
}
void InvisibleWings2(){
	SetOp((LPVOID)0x00588661,(LPVOID)0x005655C0,ASM::CALL);
}


__declspec(naked) void DelectEffectDynamicOn()
{
	static DWORD Buff_EffectDynamic = 0x0074CD57;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0
		JMP [Buff_EffectDynamic]
	}
}

__declspec(naked) void DelectEffectDynamicOff()
{
	static DWORD Buff_EffectDynamic = 0x0074CD57;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0x0BB8
		JMP [Buff_EffectDynamic]
	}
}
void DelectEffectDynamicOff_Hook(){
	SetCompleteHook(0xE9, 0x0074CD50, &DelectEffectDynamicOff);
}

void DelectEffectDynamicOn_Hook(){
	SetCompleteHook(0xE9, 0x0074CD50, &DelectEffectDynamicOn);
}

__declspec(naked) void DelectEffectStaticOn()
{
	static DWORD Buff_EffectStatic = 0x0077132F;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0
		JMP [Buff_EffectStatic]
	}

}

__declspec(naked) void DelectEffectStaticOff()
{
	static DWORD Buff_EffectStatic = 0x0077132F;

		_asm
		{
			CMP DWORD PTR SS:[EBP-0x4],0x3E8
			JMP [Buff_EffectStatic]
		}
}

void DelectEffectStaticOn_Hook()
{
	SetCompleteHook(0xE9, 0x00771328, &DelectEffectStaticOn);
}

void DelectEffectStaticOff_Hook()
{
	SetCompleteHook(0xE9, 0x00771328, &DelectEffectStaticOn);
}


__declspec(naked) void DelectlpViewPlayerOn()
{
	static DWORD Buff_lpViewPlayer = 0x0057D27F;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0
		JMP [Buff_lpViewPlayer]
	}
}

__declspec(naked) void DelectlpViewPlayerOff()
{
	static DWORD Buff_lpViewPlayer = 0x0057D27F;

		_asm
		{
			CMP DWORD PTR SS:[EBP-0x4],400
			JMP [Buff_lpViewPlayer]
		}
}

void DelectlpViewPlayerOff_Hook()
{
	SetCompleteHook(0xE9, 0x0057D278, &DelectlpViewPlayerOff);
}

void DelectlpViewPlayerOn_Hook()
{
	SetCompleteHook(0xE9, 0x0057D278, &DelectlpViewPlayerOn);
}

void ActiveShades1(){
	SetByte(0x0054A270, 0xC3);
}
void ActiveShades2(){
	SetByte(0x0054A270, 0x55);
}






void CNewUIWindowCustom::keyPressed(DWORD a1){
	if (!this->bufferUint->selected)
	{
		return;
	}
	char lastValue = this->bufferUint->value % 10;
	unsigned int calVal = this->bufferUint->value;
	switch (a1)
	{
	case VK_BACK:
	{
		if (calVal && this->bufferUint->lastActionTime < GetTickCount()) {
			calVal = (calVal - lastValue) / 10;
			this->bufferUint->lastActionTime = GetTickCount() + this->bufferUint->delay;
		}
	} break;
	case 0x30:
	case 0x31:
	case 0x32:
	case 0x33:
	case 0x34:
	case 0x35:
	case 0x36:
	case 0x37:
	case 0x38:
	case 0x39:
	{
		if (calVal || (a1 - 0x30))
		{
			if (this->bufferUint->lastActionTime < GetTickCount()) {
				calVal = calVal * 10 + (a1 - 0x30);
				this->bufferUint->lastActionTime = GetTickCount() + this->bufferUint->delay;
			}
		}
	} break;
	case 0x60:
	case 0x61:
	case 0x62:
	case 0x63:
	case 0x64:
	case 0x65:
	case 0x66:
	case 0x67:
	case 0x68:
	case 0x69:
	{
		if (calVal || (a1 - 0x60))
		{
			if (this->bufferUint->lastActionTime < GetTickCount()) {
				calVal = calVal * 10 + (a1 - 0x60);
				this->bufferUint->lastActionTime = GetTickCount() + this->bufferUint->delay;
			}
		}
	} break;
	default:
		break;
	}
	if (calVal > this->bufferUint->max)
	{
		this->bufferUint->value = this->bufferUint->max;
	}
	else
		this->bufferUint->value = calVal;
}
