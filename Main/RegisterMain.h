#include "Protocol.h"

#define RenderInfomationR					((int(*)()) 0x4D5EC0)
#define RenderBitmap				((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, float Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, float ScaleAlpha)) 0x00637C60)
#define MAX_WIN_WIDTH 640
#define MAX_WIN_HEIGHT 480
#define pSetCursorFocus				*(DWORD*)0x00E8CB3C
#define pDrawGUI				((void(*)(DWORD, float, float, float, float))0x790B50)
#define pCursorX				*(int*)0x879340C
#define pCursorY				*(int*)0x8793410
#define pDrawButton					((void(__cdecl*)(DWORD ModelID, float X, float Y, float W, float H, float CurrentX, float CurrentY)) 0x00790E40)
#define pGameWindow					*(HWND*)0x00E8C578
#define BtnSysMenuClick					((bool(__thiscall*)(BYTE* thisa)) 0x00404AD0)
#define CSysMenuWin_Render				((void(__thiscall*)(int thisa)) 0x004AC520)
#define CharMakeWin						((int(*)()) 0x00482B70)
#define GlobalLine									(LPVOID)0x008128ADC
#define FindText2						((bool(__cdecl*)(char *Text,char *Token,bool First)) 0x00512DC0)
#define PopUpMsgWin						((void(__thiscall*)(int thisa, int nMsgCode, char* pszMsg)) 0x00484A10)
#define GlobalText									((char*(__thiscall*)(LPVOID thisa, int LineNumber)) 0x00402320)
#define MAX_ID_SIZE								10
#define MAX_PERSONAL_SIZE						14
#define MAX_PASSWORD_SIZE						20
#define SIZE_PROTOCOLVERSION					( 5)
#define SIZE_PROTOCOLSERIAL						( 16)
#define CurrentProtocolState			*(int*)0x87935A4

#define InputBox_SetText					((void(__thiscall*)(int thisa, const char* pszText)) 0x00421830)
#define RequestLogin						((int(__thiscall*)(int This)) 0x0040B7B0)
#define Sprite_SetPosition					((void(__thiscall*)(BYTE * CButton, int cx, int cy, int eChangedPram)) 0x00416640)
#define CUIRenderText_SetFont				((int(__thiscall*)(int This, int a2)) 0x00420120)
#define pTextThis							((LPVOID(*)()) 0x0041FE10)
#define cInstance							((int(*)()) 0x00482B70)
#define SEASON3B_CheckMouseIn				((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)
#define g_fScreenRate_x						*(float*)0xE7C3D4
#define g_fScreenRate_y						*(float*)0xE7C3D8
#define IsPress								((int(__cdecl*)(int VKBUTTON)) 0x00791070)
#define RenderBitmap						((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)
#define PlayBuffer							((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
 
struct OBJECT_INFO_REGISTRO
{
	short	ObjectID;
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	char	FileName[100];
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;

	bool	FirstLoad;
	bool	ByClose;
	BYTE	Speed;
	long	OpenedValue;
	void Open()
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->ByClose = false;
	};

	void Open(int Value, int Speed)
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
		this->FirstLoad = true;
	};

	void Close()
	{
		this->OnShow = false;
		pSetCursorFocus = false;
		this->ByClose = false;
	};

	void Close(int Value, int Speed)
	{
		this->OnShow = false; pSetCursorFocus = false;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
	}

	void CloseAnimated(int Speed)
	{
		pSetCursorFocus = false;
		//this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = true;
	}
};
struct REGISTER_MAIN
{
	char RegisterUser[10];
	char RegisterPassword[10];
	char name[50];
	char phone[30];
	char numcode[18];
	char email[50];
};


struct PMSG_REGISTER_MAIN_SEND
{ 
	PSBMSG_HEAD header; // C1:D2:02
	char account[10];
	char password[10];
	char name[50];
	char phone[30];
	char numcode[18];
	char email[50];
};


class RegisterMain
{
	protected:
		RegisterMain*	m_pIDInputBox, * m_pPassInputBox;
public:
	//RegisterMain();
	void LoadIMG();

	void MainRegistro();
	REGISTER_MAIN  DatosRegister;
	int CountUser;
	int CountPassword;
	int DrawToolTip1(int X, int Y, LPCSTR Text, ...);
	void SendRegisterRequest(char* account, char* password,char*name ,char*phone,char* numcode,char* email);
	//----
	void  ButtonsController(DWORD Event);
	bool Usado;
	// void RenderInformacion();
	OBJECT_INFO_REGISTRO Data[350];
	//void IMG(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y);
	 
	bool TexBoxC(KBDLLHOOKSTRUCT Hook);

	RegisterMain* GetIDInputBox() const { return m_pIDInputBox; }
	RegisterMain* GetPassInputBox() const { return m_pPassInputBox; }

	//void		OPEN_WINDOW_DANGKY() { this->Data[OBJECT_PARTYPASSWORD_MAIN1].OnShow ^= true; pSetCursorFocus ^= true; this->Data[OBJECT_PARTYPASSWORD_MAIN1].FirstLoad = true; *(BYTE*)0xE8C5AC ^= 1;};
	//void		CLOSE_WINDOW_DANGKY() { this->Data[OBJECT_PARTYPASSWORD_MAIN1].OnShow = false; pSetCursorFocus = false;};
private:
	std::map<int, OBJECT_INFO_REGISTRO> m_RegisterInfo;
};
extern RegisterMain gRegisterMain;

void InitRegistro();

