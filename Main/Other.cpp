#include "stdafx.h"
#include "Other.h"
#include "TMemory.h"
#include "Import.h"
#include "User.h"
#include "Defines.h"
#include "Interface.h"
#include "Util.h"
#include "Protect.h"
#include "WindowsStruct.h"
#include "CNewUIWindowsClient.h"
#include "CNewUIMacro.h"
// ----------------------------------------------------------------------------------------------

Other	gOther;
DWORD	GuildAssistEx_Buff;
DWORD dwAllowTabSwitchLoginJMP = 0x0040B16F;
int ImgTag = 0;
int ImgTagEx41 = 632117; //Rank Dynamic
// ----------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------
static int NewCredit(void *This, int a2)
{
	return pCharacterBuf(This, a2);
}

int valor = 0;

DWORD		Test_Buff;
char		Test_LevelBuff[40];


//--------------------


void Other::Load()
{
	this->Crack();
#if(THANMA)
	char GetFotText[55] = { 0 };
	for (int st = 0; st < 50; st++)
	{
		wsprintf(GetFotText, "Text%d", st);
		GetPrivateProfileStringA("TextVN_EventThanMa", GetFotText, "Null", TextVN_ThanMaChien[st], sizeof(TextVN_ThanMaChien[st]), TEXTVN_FILE);
	}
#endif
	//============================================================================================================
	GetPrivateProfileStringA("TextVN", "TextVN0", "Null", TextVN[0], sizeof(TextVN[0]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN1", "Null", TextVN[1], sizeof(TextVN[1]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN2", "Null", TextVN[2], sizeof(TextVN[2]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN3", "Null", TextVN[3], sizeof(TextVN[3]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN4", "Null", TextVN[4], sizeof(TextVN[4]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN5", "Null", TextVN[5], sizeof(TextVN[5]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN6", "Null", TextVN[6], sizeof(TextVN[6]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN7", "Null", TextVN[7], sizeof(TextVN[7]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN8", "Null", TextVN[8], sizeof(TextVN[8]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN9", "Null", TextVN[9], sizeof(TextVN[9]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN10", "Null", TextVN[10], sizeof(TextVN[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN11", "Null", TextVN[11], sizeof(TextVN[11]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN12", "Null", TextVN[12], sizeof(TextVN[12]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN13", "Null", TextVN[13], sizeof(TextVN[13]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN14", "Null", TextVN[14], sizeof(TextVN[14]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN15", "Null", TextVN[15], sizeof(TextVN[15]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN16", "Null", TextVN[16], sizeof(TextVN[16]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN17", "Null", TextVN[17], sizeof(TextVN[17]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN18", "Null", TextVN[18], sizeof(TextVN[18]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN19", "Null", TextVN[19], sizeof(TextVN[19]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN20", "Null", TextVN[20], sizeof(TextVN[20]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN21", "Null", TextVN[21], sizeof(TextVN[21]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN22", "Null", TextVN[22], sizeof(TextVN[22]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN23", "Null", TextVN[23], sizeof(TextVN[23]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN24", "Null", TextVN[24], sizeof(TextVN[24]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN25", "Null", TextVN[25], sizeof(TextVN[25]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN26", "Null", TextVN[26], sizeof(TextVN[26]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN27", "Null", TextVN[27], sizeof(TextVN[27]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN28", "Null", TextVN[28], sizeof(TextVN[28]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN29", "Null", TextVN[29], sizeof(TextVN[29]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN30", "Null", TextVN[30], sizeof(TextVN[30]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN31", "Null", TextVN[31], sizeof(TextVN[31]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN32", "Null", TextVN[32], sizeof(TextVN[32]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN33", "Null", TextVN[33], sizeof(TextVN[33]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN34", "Null", TextVN[34], sizeof(TextVN[34]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN35", "Null", TextVN[35], sizeof(TextVN[35]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN36", "Null", TextVN[36], sizeof(TextVN[36]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN37", "Null", TextVN[37], sizeof(TextVN[37]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN38", "Null", TextVN[38], sizeof(TextVN[38]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN39", "Null", TextVN[39], sizeof(TextVN[39]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN40", "Null", TextVN[40], sizeof(TextVN[40]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN41", "Null", TextVN[41], sizeof(TextVN[41]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN42", "Null", TextVN[42], sizeof(TextVN[42]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN43", "Null", TextVN[43], sizeof(TextVN[43]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN44", "Null", TextVN[44], sizeof(TextVN[44]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN45", "Null", TextVN[45], sizeof(TextVN[45]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN46", "Null", TextVN[46], sizeof(TextVN[46]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN47", "Null", TextVN[47], sizeof(TextVN[47]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN48", "Null", TextVN[48], sizeof(TextVN[48]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN49", "Null", TextVN[49], sizeof(TextVN[49]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN50", "Null", TextVN[50], sizeof(TextVN[50]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN51", "Null", TextVN[51], sizeof(TextVN[51]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN52", "Null", TextVN[52], sizeof(TextVN[52]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN53", "Null", TextVN[53], sizeof(TextVN[53]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN54", "Null", TextVN[54], sizeof(TextVN[54]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN55", "Null", TextVN[55], sizeof(TextVN[55]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN56", "Null", TextVN[56], sizeof(TextVN[56]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN57", "Null", TextVN[57], sizeof(TextVN[57]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN58", "Null", TextVN[58], sizeof(TextVN[58]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN59", "Null", TextVN[59], sizeof(TextVN[59]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN60", "Null", TextVN[60], sizeof(TextVN[60]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN61", "Null", TextVN[61], sizeof(TextVN[61]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN62", "Null", TextVN[62], sizeof(TextVN[62]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN63", "Null", TextVN[63], sizeof(TextVN[63]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN64", "Null", TextVN[64], sizeof(TextVN[64]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN65", "Null", TextVN[65], sizeof(TextVN[65]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN66", "Null", TextVN[66], sizeof(TextVN[66]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN67", "Null", TextVN[67], sizeof(TextVN[67]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN68", "Null", TextVN[68], sizeof(TextVN[68]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN69", "Null", TextVN[69], sizeof(TextVN[69]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN70", "Null", TextVN[70], sizeof(TextVN[70]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN71", "Null", TextVN[71], sizeof(TextVN[71]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN72", "Null", TextVN[72], sizeof(TextVN[72]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN73", "Null", TextVN[73], sizeof(TextVN[73]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN74", "Null", TextVN[74], sizeof(TextVN[74]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN75", "Null", TextVN[75], sizeof(TextVN[75]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN76", "Null", TextVN[76], sizeof(TextVN[76]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN77", "Null", TextVN[77], sizeof(TextVN[77]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN78", "Null", TextVN[78], sizeof(TextVN[78]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN79", "Null", TextVN[79], sizeof(TextVN[79]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN80", "Null", TextVN[80], sizeof(TextVN[80]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN81", "Null", TextVN[81], sizeof(TextVN[81]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN82", "Null", TextVN[82], sizeof(TextVN[82]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN83", "Null", TextVN[83], sizeof(TextVN[83]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN84", "Null", TextVN[84], sizeof(TextVN[84]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN85", "Null", TextVN[85], sizeof(TextVN[85]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN86", "Null", TextVN[86], sizeof(TextVN[86]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN87", "Null", TextVN[87], sizeof(TextVN[87]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN88", "Null", TextVN[88], sizeof(TextVN[88]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN89", "Null", TextVN[89], sizeof(TextVN[89]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN90", "Null", TextVN[90], sizeof(TextVN[90]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN91", "Null", TextVN[91], sizeof(TextVN[91]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN92", "Null", TextVN[92], sizeof(TextVN[92]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN93", "Null", TextVN[93], sizeof(TextVN[93]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN94", "Null", TextVN[94], sizeof(TextVN[94]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN95", "Null", TextVN[95], sizeof(TextVN[95]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN96", "Null", TextVN[96], sizeof(TextVN[96]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN97", "Null", TextVN[97], sizeof(TextVN[97]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN98", "Null", TextVN[98], sizeof(TextVN[98]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN99", "Null", TextVN[99], sizeof(TextVN[99]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN100", "Null", TextVN[100], sizeof(TextVN[100]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN101", "Null", TextVN[101], sizeof(TextVN[101]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN102", "Null", TextVN[102], sizeof(TextVN[102]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN103", "Null", TextVN[103], sizeof(TextVN[103]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN104", "Null", TextVN[104], sizeof(TextVN[104]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN105", "Null", TextVN[105], sizeof(TextVN[105]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN106", "Null", TextVN[106], sizeof(TextVN[106]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN107", "Null", TextVN[107], sizeof(TextVN[107]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN108", "Null", TextVN[108], sizeof(TextVN[108]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN109", "Null", TextVN[109], sizeof(TextVN[109]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN110", "Null", TextVN[110], sizeof(TextVN[110]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN111", "Null", TextVN[111], sizeof(TextVN[111]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN112", "Null", TextVN[112], sizeof(TextVN[112]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN113", "Null", TextVN[113], sizeof(TextVN[113]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN114", "Null", TextVN[114], sizeof(TextVN[114]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN115", "Null", TextVN[115], sizeof(TextVN[115]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN116", "Null", TextVN[116], sizeof(TextVN[116]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN117", "Null", TextVN[117], sizeof(TextVN[117]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN118", "Null", TextVN[118], sizeof(TextVN[118]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN119", "Null", TextVN[119], sizeof(TextVN[119]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN120", "Null", TextVN[120], sizeof(TextVN[120]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN121", "Null", TextVN[121], sizeof(TextVN[121]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN122", "Null", TextVN[122], sizeof(TextVN[122]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN123", "Null", TextVN[123], sizeof(TextVN[123]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN124", "Null", TextVN[124], sizeof(TextVN[124]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN125", "Null", TextVN[125], sizeof(TextVN[125]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN126", "Null", TextVN[126], sizeof(TextVN[126]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN127", "Null", TextVN[127], sizeof(TextVN[127]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN128", "Null", TextVN[128], sizeof(TextVN[128]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN129", "Null", TextVN[129], sizeof(TextVN[129]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN130", "Null", TextVN[130], sizeof(TextVN[130]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN131", "Null", TextVN[131], sizeof(TextVN[131]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN132", "Null", TextVN[132], sizeof(TextVN[132]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN133", "Null", TextVN[133], sizeof(TextVN[133]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN134", "Null", TextVN[134], sizeof(TextVN[134]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN135", "Null", TextVN[135], sizeof(TextVN[135]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN136", "Null", TextVN[136], sizeof(TextVN[136]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN137", "Null", TextVN[137], sizeof(TextVN[137]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN138", "Null", TextVN[138], sizeof(TextVN[138]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN139", "Null", TextVN[139], sizeof(TextVN[139]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN140", "Null", TextVN[140], sizeof(TextVN[140]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN141", "Null", TextVN[141], sizeof(TextVN[141]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN142", "Null", TextVN[142], sizeof(TextVN[142]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN143", "Null", TextVN[143], sizeof(TextVN[143]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN144", "Null", TextVN[144], sizeof(TextVN[144]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN145", "Null", TextVN[145], sizeof(TextVN[145]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN146", "Null", TextVN[146], sizeof(TextVN[146]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN147", "Null", TextVN[147], sizeof(TextVN[147]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN148", "Null", TextVN[148], sizeof(TextVN[148]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN149", "Null", TextVN[149], sizeof(TextVN[149]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN150", "Null", TextVN[150], sizeof(TextVN[150]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN151", "Null", TextVN[151], sizeof(TextVN[151]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN152", "Null", TextVN[152], sizeof(TextVN[152]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN153", "Null", TextVN[153], sizeof(TextVN[153]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN154", "Null", TextVN[154], sizeof(TextVN[154]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN155", "Null", TextVN[155], sizeof(TextVN[155]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN156", "Null", TextVN[156], sizeof(TextVN[156]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN157", "Null", TextVN[157], sizeof(TextVN[157]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN158", "Null", TextVN[158], sizeof(TextVN[158]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN159", "Null", TextVN[159], sizeof(TextVN[159]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN160", "Null", TextVN[160], sizeof(TextVN[160]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN161", "Null", TextVN[161], sizeof(TextVN[161]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN162", "Null", TextVN[162], sizeof(TextVN[162]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN163", "Null", TextVN[163], sizeof(TextVN[163]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN164", "Null", TextVN[164], sizeof(TextVN[164]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN165", "Null", TextVN[165], sizeof(TextVN[165]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN166", "Null", TextVN[166], sizeof(TextVN[166]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN167", "Null", TextVN[167], sizeof(TextVN[167]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN168", "Null", TextVN[168], sizeof(TextVN[168]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN169", "Null", TextVN[169], sizeof(TextVN[169]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN170", "Null", TextVN[170], sizeof(TextVN[170]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN171", "Null", TextVN[171], sizeof(TextVN[171]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN172", "Null", TextVN[172], sizeof(TextVN[172]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN173", "Null", TextVN[173], sizeof(TextVN[173]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN174", "Null", TextVN[174], sizeof(TextVN[174]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN175", "Null", TextVN[175], sizeof(TextVN[175]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN176", "Null", TextVN[176], sizeof(TextVN[176]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN177", "Null", TextVN[177], sizeof(TextVN[177]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN178", "Null", TextVN[178], sizeof(TextVN[178]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN179", "Null", TextVN[179], sizeof(TextVN[179]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN180", "Null", TextVN[180], sizeof(TextVN[180]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN181", "Null", TextVN[181], sizeof(TextVN[181]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN182", "Null", TextVN[182], sizeof(TextVN[182]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN183", "Null", TextVN[183], sizeof(TextVN[183]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN184", "Null", TextVN[184], sizeof(TextVN[184]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN185", "Null", TextVN[185], sizeof(TextVN[185]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN186", "Null", TextVN[186], sizeof(TextVN[186]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN187", "Null", TextVN[187], sizeof(TextVN[187]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN188", "Null", TextVN[188], sizeof(TextVN[188]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN189", "Null", TextVN[189], sizeof(TextVN[189]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN190", "Null", TextVN[190], sizeof(TextVN[190]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN191", "Null", TextVN[191], sizeof(TextVN[191]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN192", "Null", TextVN[192], sizeof(TextVN[192]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN193", "Null", TextVN[193], sizeof(TextVN[193]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN194", "Null", TextVN[194], sizeof(TextVN[194]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN195", "Null", TextVN[195], sizeof(TextVN[195]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN196", "Null", TextVN[196], sizeof(TextVN[196]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN197", "Null", TextVN[197], sizeof(TextVN[197]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN198", "Null", TextVN[198], sizeof(TextVN[198]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN199", "Null", TextVN[199], sizeof(TextVN[199]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN200", "Null", TextVN[200], sizeof(TextVN[200]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN201", "Null", TextVN[201], sizeof(TextVN[201]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN202", "Null", TextVN[202], sizeof(TextVN[202]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN203", "Null", TextVN[203], sizeof(TextVN[203]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN204", "Null", TextVN[204], sizeof(TextVN[204]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN205", "Null", TextVN[205], sizeof(TextVN[205]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN206", "Null", TextVN[206], sizeof(TextVN[206]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN207", "Null", TextVN[207], sizeof(TextVN[207]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN208", "Null", TextVN[208], sizeof(TextVN[208]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN209", "Null", TextVN[209], sizeof(TextVN[209]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN210", "Null", TextVN[210], sizeof(TextVN[210]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN211", "Null", TextVN[211], sizeof(TextVN[211]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN212", "Null", TextVN[212], sizeof(TextVN[212]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN213", "Null", TextVN[213], sizeof(TextVN[213]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN214", "Null", TextVN[214], sizeof(TextVN[214]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN215", "Null", TextVN[215], sizeof(TextVN[215]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN216", "Null", TextVN[216], sizeof(TextVN[216]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN217", "Null", TextVN[217], sizeof(TextVN[217]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN218", "Null", TextVN[218], sizeof(TextVN[218]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN219", "Null", TextVN[219], sizeof(TextVN[219]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN220", "Null", TextVN[220], sizeof(TextVN[220]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN221", "Null", TextVN[221], sizeof(TextVN[221]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN222", "Null", TextVN[222], sizeof(TextVN[222]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN223", "Null", TextVN[223], sizeof(TextVN[224]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN224", "Null", TextVN[224], sizeof(TextVN[224]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN225", "Null", TextVN[225], sizeof(TextVN[225]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN226", "Null", TextVN[226], sizeof(TextVN[226]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN227", "Null", TextVN[227], sizeof(TextVN[227]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN", "TextVN228", "Null", TextVN[228], sizeof(TextVN[228]), TEXTVN_FILE);
	//===>>>
	GetPrivateProfileStringA("TextVN_KepChuot", "TextVN_KepChuot0", "Null", TextVN_KepChuot[0], sizeof(TextVN_KepChuot[0]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_KepChuot", "TextVN_KepChuot1", "Null", TextVN_KepChuot[1], sizeof(TextVN_KepChuot[1]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_KepChuot", "TextVN_KepChuot2", "Null", TextVN_KepChuot[2], sizeof(TextVN_KepChuot[2]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_KepChuot", "TextVN_KepChuot3", "Null", TextVN_KepChuot[3], sizeof(TextVN_KepChuot[3]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_KepChuot", "TextVN_KepChuot4", "Null", TextVN_KepChuot[4], sizeof(TextVN_KepChuot[4]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_KepChuot", "TextVN_KepChuot5", "Null", TextVN_KepChuot[5], sizeof(TextVN_KepChuot[5]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_KepChuot", "TextVN_KepChuot6", "Null", TextVN_KepChuot[6], sizeof(TextVN_KepChuot[6]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_KepChuot", "TextVN_KepChuot7", "Null", TextVN_KepChuot[7], sizeof(TextVN_KepChuot[7]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_KepChuot", "TextVN_KepChuot8", "Null", TextVN_KepChuot[8], sizeof(TextVN_KepChuot[8]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_KepChuot", "TextVN_KepChuot9", "Null", TextVN_KepChuot[9], sizeof(TextVN_KepChuot[9]), TEXTVN_FILE);
	//===>>>
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh0", "Null", TextVN_SachThuocTinh[0], sizeof(TextVN_SachThuocTinh[0]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh1", "Null", TextVN_SachThuocTinh[1], sizeof(TextVN_SachThuocTinh[1]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh2", "Null", TextVN_SachThuocTinh[2], sizeof(TextVN_SachThuocTinh[2]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh3", "Null", TextVN_SachThuocTinh[3], sizeof(TextVN_SachThuocTinh[3]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh4", "Null", TextVN_SachThuocTinh[4], sizeof(TextVN_SachThuocTinh[4]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh5", "Null", TextVN_SachThuocTinh[5], sizeof(TextVN_SachThuocTinh[5]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh6", "Null", TextVN_SachThuocTinh[6], sizeof(TextVN_SachThuocTinh[6]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh7", "Null", TextVN_SachThuocTinh[7], sizeof(TextVN_SachThuocTinh[7]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh8", "Null", TextVN_SachThuocTinh[8], sizeof(TextVN_SachThuocTinh[8]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh9", "Null", TextVN_SachThuocTinh[9], sizeof(TextVN_SachThuocTinh[9]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh10", "Null", TextVN_SachThuocTinh[10], sizeof(TextVN_SachThuocTinh[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh11", "Null", TextVN_SachThuocTinh[11], sizeof(TextVN_SachThuocTinh[11]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh12", "Null", TextVN_SachThuocTinh[12], sizeof(TextVN_SachThuocTinh[12]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh13", "Null", TextVN_SachThuocTinh[13], sizeof(TextVN_SachThuocTinh[13]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh14", "Null", TextVN_SachThuocTinh[14], sizeof(TextVN_SachThuocTinh[14]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh15", "Null", TextVN_SachThuocTinh[15], sizeof(TextVN_SachThuocTinh[15]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh16", "Null", TextVN_SachThuocTinh[16], sizeof(TextVN_SachThuocTinh[16]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh17", "Null", TextVN_SachThuocTinh[17], sizeof(TextVN_SachThuocTinh[17]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh18", "Null", TextVN_SachThuocTinh[18], sizeof(TextVN_SachThuocTinh[18]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh19", "Null", TextVN_SachThuocTinh[19], sizeof(TextVN_SachThuocTinh[19]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh20", "Null", TextVN_SachThuocTinh[20], sizeof(TextVN_SachThuocTinh[20]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh21", "Null", TextVN_SachThuocTinh[21], sizeof(TextVN_SachThuocTinh[21]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh22", "Null", TextVN_SachThuocTinh[22], sizeof(TextVN_SachThuocTinh[22]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh23", "Null", TextVN_SachThuocTinh[23], sizeof(TextVN_SachThuocTinh[23]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh24", "Null", TextVN_SachThuocTinh[24], sizeof(TextVN_SachThuocTinh[24]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh25", "Null", TextVN_SachThuocTinh[25], sizeof(TextVN_SachThuocTinh[25]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh26", "Null", TextVN_SachThuocTinh[26], sizeof(TextVN_SachThuocTinh[26]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh27", "Null", TextVN_SachThuocTinh[27], sizeof(TextVN_SachThuocTinh[27]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh28", "Null", TextVN_SachThuocTinh[28], sizeof(TextVN_SachThuocTinh[28]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh29", "Null", TextVN_SachThuocTinh[29], sizeof(TextVN_SachThuocTinh[29]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_SachThuocTinh", "TextVN_SachThuocTinh30", "Null", TextVN_SachThuocTinh[30], sizeof(TextVN_SachThuocTinh[30]), TEXTVN_FILE);
	//===>>>
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan0", "Null", TextVN_RingPedan[0], sizeof(TextVN_RingPedan[0]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan1", "Null", TextVN_RingPedan[1], sizeof(TextVN_RingPedan[1]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan2", "Null", TextVN_RingPedan[2], sizeof(TextVN_RingPedan[2]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan3", "Null", TextVN_RingPedan[3], sizeof(TextVN_RingPedan[3]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan4", "Null", TextVN_RingPedan[4], sizeof(TextVN_RingPedan[4]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan5", "Null", TextVN_RingPedan[5], sizeof(TextVN_RingPedan[5]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan6", "Null", TextVN_RingPedan[6], sizeof(TextVN_RingPedan[6]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan7", "Null", TextVN_RingPedan[7], sizeof(TextVN_RingPedan[7]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan8", "Null", TextVN_RingPedan[8], sizeof(TextVN_RingPedan[8]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan9", "Null", TextVN_RingPedan[9], sizeof(TextVN_RingPedan[9]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan10", "Null", TextVN_RingPedan[10], sizeof(TextVN_RingPedan[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan11", "Null", TextVN_RingPedan[11], sizeof(TextVN_RingPedan[11]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan12", "Null", TextVN_RingPedan[12], sizeof(TextVN_RingPedan[12]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan13", "Null", TextVN_RingPedan[13], sizeof(TextVN_RingPedan[13]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan14", "Null", TextVN_RingPedan[14], sizeof(TextVN_RingPedan[14]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan15", "Null", TextVN_RingPedan[15], sizeof(TextVN_RingPedan[15]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan16", "Null", TextVN_RingPedan[16], sizeof(TextVN_RingPedan[16]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan17", "Null", TextVN_RingPedan[17], sizeof(TextVN_RingPedan[17]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan18", "Null", TextVN_RingPedan[18], sizeof(TextVN_RingPedan[18]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan19", "Null", TextVN_RingPedan[19], sizeof(TextVN_RingPedan[19]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan20", "Null", TextVN_RingPedan[20], sizeof(TextVN_RingPedan[20]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan21", "Null", TextVN_RingPedan[21], sizeof(TextVN_RingPedan[21]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan22", "Null", TextVN_RingPedan[22], sizeof(TextVN_RingPedan[22]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan23", "Null", TextVN_RingPedan[23], sizeof(TextVN_RingPedan[23]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan24", "Null", TextVN_RingPedan[24], sizeof(TextVN_RingPedan[24]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan25", "Null", TextVN_RingPedan[25], sizeof(TextVN_RingPedan[25]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan26", "Null", TextVN_RingPedan[26], sizeof(TextVN_RingPedan[26]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan27", "Null", TextVN_RingPedan[27], sizeof(TextVN_RingPedan[27]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan28", "Null", TextVN_RingPedan[28], sizeof(TextVN_RingPedan[28]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan29", "Null", TextVN_RingPedan[29], sizeof(TextVN_RingPedan[29]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan30", "Null", TextVN_RingPedan[30], sizeof(TextVN_RingPedan[30]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan31", "Null", TextVN_RingPedan[31], sizeof(TextVN_RingPedan[31]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan32", "Null", TextVN_RingPedan[32], sizeof(TextVN_RingPedan[32]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan33", "Null", TextVN_RingPedan[33], sizeof(TextVN_RingPedan[33]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan34", "Null", TextVN_RingPedan[34], sizeof(TextVN_RingPedan[34]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan35", "Null", TextVN_RingPedan[35], sizeof(TextVN_RingPedan[35]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan36", "Null", TextVN_RingPedan[36], sizeof(TextVN_RingPedan[36]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan37", "Null", TextVN_RingPedan[37], sizeof(TextVN_RingPedan[37]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan38", "Null", TextVN_RingPedan[38], sizeof(TextVN_RingPedan[38]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan39", "Null", TextVN_RingPedan[39], sizeof(TextVN_RingPedan[39]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan40", "Null", TextVN_RingPedan[40], sizeof(TextVN_RingPedan[40]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan41", "Null", TextVN_RingPedan[41], sizeof(TextVN_RingPedan[41]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan42", "Null", TextVN_RingPedan[42], sizeof(TextVN_RingPedan[42]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan43", "Null", TextVN_RingPedan[43], sizeof(TextVN_RingPedan[43]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan44", "Null", TextVN_RingPedan[44], sizeof(TextVN_RingPedan[44]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan45", "Null", TextVN_RingPedan[45], sizeof(TextVN_RingPedan[45]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan46", "Null", TextVN_RingPedan[46], sizeof(TextVN_RingPedan[46]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan47", "Null", TextVN_RingPedan[47], sizeof(TextVN_RingPedan[47]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan48", "Null", TextVN_RingPedan[48], sizeof(TextVN_RingPedan[48]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan49", "Null", TextVN_RingPedan[49], sizeof(TextVN_RingPedan[49]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_RingPedan", "TextVN_RingPedan50", "Null", TextVN_RingPedan[50], sizeof(TextVN_RingPedan[50]), TEXTVN_FILE);

	//===>>>
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu1", "Null", TextVN_NhiemVu[1], sizeof(TextVN_NhiemVu[1]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu2", "Null", TextVN_NhiemVu[2], sizeof(TextVN_NhiemVu[2]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu3", "Null", TextVN_NhiemVu[3], sizeof(TextVN_NhiemVu[3]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu4", "Null", TextVN_NhiemVu[4], sizeof(TextVN_NhiemVu[4]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu5", "Null", TextVN_NhiemVu[5], sizeof(TextVN_NhiemVu[5]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu6", "Null", TextVN_NhiemVu[6], sizeof(TextVN_NhiemVu[6]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu7", "Null", TextVN_NhiemVu[7], sizeof(TextVN_NhiemVu[7]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu8", "Null", TextVN_NhiemVu[8], sizeof(TextVN_NhiemVu[8]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu9", "Null", TextVN_NhiemVu[9], sizeof(TextVN_NhiemVu[9]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu10", "Null", TextVN_NhiemVu[10], sizeof(TextVN_NhiemVu[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu11", "Null", TextVN_NhiemVu[11], sizeof(TextVN_NhiemVu[11]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu12", "Null", TextVN_NhiemVu[12], sizeof(TextVN_NhiemVu[12]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu13", "Null", TextVN_NhiemVu[13], sizeof(TextVN_NhiemVu[13]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu14", "Null", TextVN_NhiemVu[14], sizeof(TextVN_NhiemVu[14]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu15", "Null", TextVN_NhiemVu[15], sizeof(TextVN_NhiemVu[15]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu16", "Null", TextVN_NhiemVu[16], sizeof(TextVN_NhiemVu[16]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu17", "Null", TextVN_NhiemVu[17], sizeof(TextVN_NhiemVu[17]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu18", "Null", TextVN_NhiemVu[18], sizeof(TextVN_NhiemVu[18]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu19", "Null", TextVN_NhiemVu[19], sizeof(TextVN_NhiemVu[19]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu20", "Null", TextVN_NhiemVu[20], sizeof(TextVN_NhiemVu[20]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu21", "Null", TextVN_NhiemVu[21], sizeof(TextVN_NhiemVu[21]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu22", "Null", TextVN_NhiemVu[22], sizeof(TextVN_NhiemVu[22]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu23", "Null", TextVN_NhiemVu[23], sizeof(TextVN_NhiemVu[23]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu24", "Null", TextVN_NhiemVu[24], sizeof(TextVN_NhiemVu[24]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu25", "Null", TextVN_NhiemVu[25], sizeof(TextVN_NhiemVu[25]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu26", "Null", TextVN_NhiemVu[26], sizeof(TextVN_NhiemVu[26]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu27", "Null", TextVN_NhiemVu[27], sizeof(TextVN_NhiemVu[27]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu28", "Null", TextVN_NhiemVu[28], sizeof(TextVN_NhiemVu[28]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_NhiemVu", "TextVN_NhiemVu29", "Null", TextVN_NhiemVu[29], sizeof(TextVN_NhiemVu[29]), TEXTVN_FILE);
	//===>>>
	//===>>>
	//===>>>
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu0", "Null", TextVN_DanhHieu[0], sizeof(TextVN_DanhHieu[0]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu1", "Null", TextVN_DanhHieu[1], sizeof(TextVN_DanhHieu[1]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu2", "Null", TextVN_DanhHieu[2], sizeof(TextVN_DanhHieu[2]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu3", "Null", TextVN_DanhHieu[3], sizeof(TextVN_DanhHieu[3]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu4", "Null", TextVN_DanhHieu[4], sizeof(TextVN_DanhHieu[4]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu5", "Null", TextVN_DanhHieu[5], sizeof(TextVN_DanhHieu[5]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu6", "Null", TextVN_DanhHieu[6], sizeof(TextVN_DanhHieu[6]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu7", "Null", TextVN_DanhHieu[7], sizeof(TextVN_DanhHieu[7]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu8", "Null", TextVN_DanhHieu[8], sizeof(TextVN_DanhHieu[8]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu9", "Null", TextVN_DanhHieu[9], sizeof(TextVN_DanhHieu[9]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu10", "Null", TextVN_DanhHieu[10], sizeof(TextVN_DanhHieu[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu10", "Null", TextVN_DanhHieu[10], sizeof(TextVN_DanhHieu[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu11", "Null", TextVN_DanhHieu[11], sizeof(TextVN_DanhHieu[11]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu12", "Null", TextVN_DanhHieu[12], sizeof(TextVN_DanhHieu[12]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu13", "Null", TextVN_DanhHieu[13], sizeof(TextVN_DanhHieu[13]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu14", "Null", TextVN_DanhHieu[14], sizeof(TextVN_DanhHieu[14]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu15", "Null", TextVN_DanhHieu[15], sizeof(TextVN_DanhHieu[15]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu16", "Null", TextVN_DanhHieu[16], sizeof(TextVN_DanhHieu[16]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu17", "Null", TextVN_DanhHieu[17], sizeof(TextVN_DanhHieu[17]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu18", "Null", TextVN_DanhHieu[18], sizeof(TextVN_DanhHieu[18]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu19", "Null", TextVN_DanhHieu[19], sizeof(TextVN_DanhHieu[19]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu20", "Null", TextVN_DanhHieu[20], sizeof(TextVN_DanhHieu[20]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu21", "Null", TextVN_DanhHieu[21], sizeof(TextVN_DanhHieu[21]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu22", "Null", TextVN_DanhHieu[22], sizeof(TextVN_DanhHieu[22]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu23", "Null", TextVN_DanhHieu[23], sizeof(TextVN_DanhHieu[23]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu24", "Null", TextVN_DanhHieu[24], sizeof(TextVN_DanhHieu[24]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu25", "Null", TextVN_DanhHieu[25], sizeof(TextVN_DanhHieu[25]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu26", "Null", TextVN_DanhHieu[26], sizeof(TextVN_DanhHieu[26]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu27", "Null", TextVN_DanhHieu[27], sizeof(TextVN_DanhHieu[27]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu28", "Null", TextVN_DanhHieu[28], sizeof(TextVN_DanhHieu[28]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu29", "Null", TextVN_DanhHieu[29], sizeof(TextVN_DanhHieu[29]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu30", "Null", TextVN_DanhHieu[30], sizeof(TextVN_DanhHieu[30]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu31", "Null", TextVN_DanhHieu[31], sizeof(TextVN_DanhHieu[31]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu32", "Null", TextVN_DanhHieu[32], sizeof(TextVN_DanhHieu[32]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu33", "Null", TextVN_DanhHieu[33], sizeof(TextVN_DanhHieu[33]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu34", "Null", TextVN_DanhHieu[34], sizeof(TextVN_DanhHieu[34]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu35", "Null", TextVN_DanhHieu[35], sizeof(TextVN_DanhHieu[35]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu36", "Null", TextVN_DanhHieu[36], sizeof(TextVN_DanhHieu[36]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu37", "Null", TextVN_DanhHieu[37], sizeof(TextVN_DanhHieu[37]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu38", "Null", TextVN_DanhHieu[38], sizeof(TextVN_DanhHieu[38]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu39", "Null", TextVN_DanhHieu[39], sizeof(TextVN_DanhHieu[39]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu40", "Null", TextVN_DanhHieu[40], sizeof(TextVN_DanhHieu[40]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu41", "Null", TextVN_DanhHieu[41], sizeof(TextVN_DanhHieu[41]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu42", "Null", TextVN_DanhHieu[42], sizeof(TextVN_DanhHieu[42]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu43", "Null", TextVN_DanhHieu[43], sizeof(TextVN_DanhHieu[43]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu44", "Null", TextVN_DanhHieu[44], sizeof(TextVN_DanhHieu[44]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu45", "Null", TextVN_DanhHieu[45], sizeof(TextVN_DanhHieu[45]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu46", "Null", TextVN_DanhHieu[46], sizeof(TextVN_DanhHieu[46]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu47", "Null", TextVN_DanhHieu[47], sizeof(TextVN_DanhHieu[47]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu48", "Null", TextVN_DanhHieu[48], sizeof(TextVN_DanhHieu[48]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu49", "Null", TextVN_DanhHieu[49], sizeof(TextVN_DanhHieu[49]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu50", "Null", TextVN_DanhHieu[50], sizeof(TextVN_DanhHieu[50]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu51", "Null", TextVN_DanhHieu[51], sizeof(TextVN_DanhHieu[51]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu52", "Null", TextVN_DanhHieu[52], sizeof(TextVN_DanhHieu[52]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu53", "Null", TextVN_DanhHieu[53], sizeof(TextVN_DanhHieu[53]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu54", "Null", TextVN_DanhHieu[54], sizeof(TextVN_DanhHieu[54]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu55", "Null", TextVN_DanhHieu[55], sizeof(TextVN_DanhHieu[55]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu56", "Null", TextVN_DanhHieu[56], sizeof(TextVN_DanhHieu[56]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu57", "Null", TextVN_DanhHieu[57], sizeof(TextVN_DanhHieu[57]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu58", "Null", TextVN_DanhHieu[58], sizeof(TextVN_DanhHieu[58]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu59", "Null", TextVN_DanhHieu[59], sizeof(TextVN_DanhHieu[59]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu60", "Null", TextVN_DanhHieu[60], sizeof(TextVN_DanhHieu[60]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu61", "Null", TextVN_DanhHieu[61], sizeof(TextVN_DanhHieu[61]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu62", "Null", TextVN_DanhHieu[62], sizeof(TextVN_DanhHieu[62]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu63", "Null", TextVN_DanhHieu[63], sizeof(TextVN_DanhHieu[63]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu64", "Null", TextVN_DanhHieu[64], sizeof(TextVN_DanhHieu[64]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu65", "Null", TextVN_DanhHieu[65], sizeof(TextVN_DanhHieu[65]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu66", "Null", TextVN_DanhHieu[66], sizeof(TextVN_DanhHieu[66]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu67", "Null", TextVN_DanhHieu[67], sizeof(TextVN_DanhHieu[67]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu68", "Null", TextVN_DanhHieu[68], sizeof(TextVN_DanhHieu[68]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu69", "Null", TextVN_DanhHieu[69], sizeof(TextVN_DanhHieu[69]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu70", "Null", TextVN_DanhHieu[70], sizeof(TextVN_DanhHieu[70]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu71", "Null", TextVN_DanhHieu[71], sizeof(TextVN_DanhHieu[71]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu72", "Null", TextVN_DanhHieu[72], sizeof(TextVN_DanhHieu[72]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu73", "Null", TextVN_DanhHieu[73], sizeof(TextVN_DanhHieu[73]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu74", "Null", TextVN_DanhHieu[74], sizeof(TextVN_DanhHieu[74]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu75", "Null", TextVN_DanhHieu[75], sizeof(TextVN_DanhHieu[75]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu76", "Null", TextVN_DanhHieu[76], sizeof(TextVN_DanhHieu[76]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu77", "Null", TextVN_DanhHieu[77], sizeof(TextVN_DanhHieu[77]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu78", "Null", TextVN_DanhHieu[78], sizeof(TextVN_DanhHieu[78]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu79", "Null", TextVN_DanhHieu[79], sizeof(TextVN_DanhHieu[79]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu80", "Null", TextVN_DanhHieu[80], sizeof(TextVN_DanhHieu[80]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu81", "Null", TextVN_DanhHieu[81], sizeof(TextVN_DanhHieu[81]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu82", "Null", TextVN_DanhHieu[82], sizeof(TextVN_DanhHieu[82]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu83", "Null", TextVN_DanhHieu[83], sizeof(TextVN_DanhHieu[83]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu84", "Null", TextVN_DanhHieu[84], sizeof(TextVN_DanhHieu[84]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu85", "Null", TextVN_DanhHieu[85], sizeof(TextVN_DanhHieu[85]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu86", "Null", TextVN_DanhHieu[86], sizeof(TextVN_DanhHieu[86]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu87", "Null", TextVN_DanhHieu[87], sizeof(TextVN_DanhHieu[87]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu88", "Null", TextVN_DanhHieu[88], sizeof(TextVN_DanhHieu[88]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu89", "Null", TextVN_DanhHieu[89], sizeof(TextVN_DanhHieu[89]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu90", "Null", TextVN_DanhHieu[90], sizeof(TextVN_DanhHieu[90]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu91", "Null", TextVN_DanhHieu[91], sizeof(TextVN_DanhHieu[91]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu92", "Null", TextVN_DanhHieu[92], sizeof(TextVN_DanhHieu[92]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu93", "Null", TextVN_DanhHieu[93], sizeof(TextVN_DanhHieu[93]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu94", "Null", TextVN_DanhHieu[94], sizeof(TextVN_DanhHieu[94]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu95", "Null", TextVN_DanhHieu[95], sizeof(TextVN_DanhHieu[95]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu96", "Null", TextVN_DanhHieu[96], sizeof(TextVN_DanhHieu[96]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu97", "Null", TextVN_DanhHieu[97], sizeof(TextVN_DanhHieu[97]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu98", "Null", TextVN_DanhHieu[98], sizeof(TextVN_DanhHieu[98]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu99", "Null", TextVN_DanhHieu[99], sizeof(TextVN_DanhHieu[99]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu100", "Null", TextVN_DanhHieu[100], sizeof(TextVN_DanhHieu[100]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu101", "Null", TextVN_DanhHieu[101], sizeof(TextVN_DanhHieu[101]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu102", "Null", TextVN_DanhHieu[102], sizeof(TextVN_DanhHieu[102]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu103", "Null", TextVN_DanhHieu[103], sizeof(TextVN_DanhHieu[103]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu104", "Null", TextVN_DanhHieu[104], sizeof(TextVN_DanhHieu[104]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu105", "Null", TextVN_DanhHieu[105], sizeof(TextVN_DanhHieu[105]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu106", "Null", TextVN_DanhHieu[106], sizeof(TextVN_DanhHieu[106]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_DanhHieu", "TextVN_DanhHieu107", "Null", TextVN_DanhHieu[107], sizeof(TextVN_DanhHieu[107]), TEXTVN_FILE);
	//===>>>
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam0", "Null", TextVN_QuanHam[0], sizeof(TextVN_QuanHam[0]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam1", "Null", TextVN_QuanHam[1], sizeof(TextVN_QuanHam[1]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam2", "Null", TextVN_QuanHam[2], sizeof(TextVN_QuanHam[2]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam3", "Null", TextVN_QuanHam[3], sizeof(TextVN_QuanHam[3]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam4", "Null", TextVN_QuanHam[4], sizeof(TextVN_QuanHam[4]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam5", "Null", TextVN_QuanHam[5], sizeof(TextVN_QuanHam[5]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam6", "Null", TextVN_QuanHam[6], sizeof(TextVN_QuanHam[6]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam7", "Null", TextVN_QuanHam[7], sizeof(TextVN_QuanHam[7]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam8", "Null", TextVN_QuanHam[8], sizeof(TextVN_QuanHam[8]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam9", "Null", TextVN_QuanHam[9], sizeof(TextVN_QuanHam[9]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam10", "Null", TextVN_QuanHam[10], sizeof(TextVN_QuanHam[10]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam11", "Null", TextVN_QuanHam[11], sizeof(TextVN_QuanHam[11]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam12", "Null", TextVN_QuanHam[12], sizeof(TextVN_QuanHam[12]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam13", "Null", TextVN_QuanHam[13], sizeof(TextVN_QuanHam[13]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam14", "Null", TextVN_QuanHam[14], sizeof(TextVN_QuanHam[14]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam15", "Null", TextVN_QuanHam[15], sizeof(TextVN_QuanHam[15]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam16", "Null", TextVN_QuanHam[16], sizeof(TextVN_QuanHam[16]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam17", "Null", TextVN_QuanHam[17], sizeof(TextVN_QuanHam[17]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam18", "Null", TextVN_QuanHam[18], sizeof(TextVN_QuanHam[18]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam19", "Null", TextVN_QuanHam[19], sizeof(TextVN_QuanHam[19]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam20", "Null", TextVN_QuanHam[20], sizeof(TextVN_QuanHam[20]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam21", "Null", TextVN_QuanHam[21], sizeof(TextVN_QuanHam[21]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam22", "Null", TextVN_QuanHam[22], sizeof(TextVN_QuanHam[22]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam23", "Null", TextVN_QuanHam[23], sizeof(TextVN_QuanHam[23]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam24", "Null", TextVN_QuanHam[24], sizeof(TextVN_QuanHam[24]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam25", "Null", TextVN_QuanHam[25], sizeof(TextVN_QuanHam[25]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam26", "Null", TextVN_QuanHam[26], sizeof(TextVN_QuanHam[26]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam27", "Null", TextVN_QuanHam[27], sizeof(TextVN_QuanHam[27]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam28", "Null", TextVN_QuanHam[28], sizeof(TextVN_QuanHam[28]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam29", "Null", TextVN_QuanHam[29], sizeof(TextVN_QuanHam[29]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam30", "Null", TextVN_QuanHam[30], sizeof(TextVN_QuanHam[30]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam31", "Null", TextVN_QuanHam[31], sizeof(TextVN_QuanHam[31]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam32", "Null", TextVN_QuanHam[32], sizeof(TextVN_QuanHam[32]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam33", "Null", TextVN_QuanHam[33], sizeof(TextVN_QuanHam[33]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam34", "Null", TextVN_QuanHam[34], sizeof(TextVN_QuanHam[34]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam35", "Null", TextVN_QuanHam[35], sizeof(TextVN_QuanHam[35]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam36", "Null", TextVN_QuanHam[36], sizeof(TextVN_QuanHam[36]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam37", "Null", TextVN_QuanHam[37], sizeof(TextVN_QuanHam[37]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam38", "Null", TextVN_QuanHam[38], sizeof(TextVN_QuanHam[38]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam39", "Null", TextVN_QuanHam[39], sizeof(TextVN_QuanHam[39]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam40", "Null", TextVN_QuanHam[40], sizeof(TextVN_QuanHam[40]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam41", "Null", TextVN_QuanHam[41], sizeof(TextVN_QuanHam[41]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam42", "Null", TextVN_QuanHam[42], sizeof(TextVN_QuanHam[42]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam43", "Null", TextVN_QuanHam[43], sizeof(TextVN_QuanHam[43]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam44", "Null", TextVN_QuanHam[44], sizeof(TextVN_QuanHam[44]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam45", "Null", TextVN_QuanHam[45], sizeof(TextVN_QuanHam[45]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam46", "Null", TextVN_QuanHam[46], sizeof(TextVN_QuanHam[46]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam47", "Null", TextVN_QuanHam[47], sizeof(TextVN_QuanHam[47]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam48", "Null", TextVN_QuanHam[48], sizeof(TextVN_QuanHam[48]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam49", "Null", TextVN_QuanHam[49], sizeof(TextVN_QuanHam[49]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam50", "Null", TextVN_QuanHam[50], sizeof(TextVN_QuanHam[50]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam51", "Null", TextVN_QuanHam[51], sizeof(TextVN_QuanHam[51]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam52", "Null", TextVN_QuanHam[52], sizeof(TextVN_QuanHam[52]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam53", "Null", TextVN_QuanHam[53], sizeof(TextVN_QuanHam[53]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam54", "Null", TextVN_QuanHam[54], sizeof(TextVN_QuanHam[54]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam55", "Null", TextVN_QuanHam[55], sizeof(TextVN_QuanHam[55]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam56", "Null", TextVN_QuanHam[56], sizeof(TextVN_QuanHam[56]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam57", "Null", TextVN_QuanHam[57], sizeof(TextVN_QuanHam[57]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam58", "Null", TextVN_QuanHam[58], sizeof(TextVN_QuanHam[58]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam59", "Null", TextVN_QuanHam[59], sizeof(TextVN_QuanHam[59]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam60", "Null", TextVN_QuanHam[60], sizeof(TextVN_QuanHam[60]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam61", "Null", TextVN_QuanHam[61], sizeof(TextVN_QuanHam[61]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam62", "Null", TextVN_QuanHam[62], sizeof(TextVN_QuanHam[62]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam63", "Null", TextVN_QuanHam[63], sizeof(TextVN_QuanHam[63]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam64", "Null", TextVN_QuanHam[64], sizeof(TextVN_QuanHam[64]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam65", "Null", TextVN_QuanHam[65], sizeof(TextVN_QuanHam[65]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam66", "Null", TextVN_QuanHam[66], sizeof(TextVN_QuanHam[66]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam67", "Null", TextVN_QuanHam[67], sizeof(TextVN_QuanHam[67]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam68", "Null", TextVN_QuanHam[68], sizeof(TextVN_QuanHam[68]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam69", "Null", TextVN_QuanHam[69], sizeof(TextVN_QuanHam[69]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam70", "Null", TextVN_QuanHam[70], sizeof(TextVN_QuanHam[70]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam71", "Null", TextVN_QuanHam[71], sizeof(TextVN_QuanHam[71]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam72", "Null", TextVN_QuanHam[72], sizeof(TextVN_QuanHam[72]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam73", "Null", TextVN_QuanHam[73], sizeof(TextVN_QuanHam[73]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam74", "Null", TextVN_QuanHam[74], sizeof(TextVN_QuanHam[74]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam75", "Null", TextVN_QuanHam[75], sizeof(TextVN_QuanHam[75]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam76", "Null", TextVN_QuanHam[76], sizeof(TextVN_QuanHam[76]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam77", "Null", TextVN_QuanHam[77], sizeof(TextVN_QuanHam[77]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam78", "Null", TextVN_QuanHam[78], sizeof(TextVN_QuanHam[78]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam79", "Null", TextVN_QuanHam[79], sizeof(TextVN_QuanHam[79]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam80", "Null", TextVN_QuanHam[80], sizeof(TextVN_QuanHam[80]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam81", "Null", TextVN_QuanHam[81], sizeof(TextVN_QuanHam[81]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam82", "Null", TextVN_QuanHam[82], sizeof(TextVN_QuanHam[82]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam83", "Null", TextVN_QuanHam[83], sizeof(TextVN_QuanHam[83]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam84", "Null", TextVN_QuanHam[84], sizeof(TextVN_QuanHam[84]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam85", "Null", TextVN_QuanHam[85], sizeof(TextVN_QuanHam[85]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam86", "Null", TextVN_QuanHam[86], sizeof(TextVN_QuanHam[86]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam87", "Null", TextVN_QuanHam[87], sizeof(TextVN_QuanHam[87]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam88", "Null", TextVN_QuanHam[88], sizeof(TextVN_QuanHam[88]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam89", "Null", TextVN_QuanHam[89], sizeof(TextVN_QuanHam[89]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam90", "Null", TextVN_QuanHam[90], sizeof(TextVN_QuanHam[90]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam91", "Null", TextVN_QuanHam[91], sizeof(TextVN_QuanHam[91]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam92", "Null", TextVN_QuanHam[92], sizeof(TextVN_QuanHam[92]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam93", "Null", TextVN_QuanHam[93], sizeof(TextVN_QuanHam[93]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam94", "Null", TextVN_QuanHam[94], sizeof(TextVN_QuanHam[94]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam95", "Null", TextVN_QuanHam[95], sizeof(TextVN_QuanHam[95]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam96", "Null", TextVN_QuanHam[96], sizeof(TextVN_QuanHam[96]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam97", "Null", TextVN_QuanHam[97], sizeof(TextVN_QuanHam[97]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam98", "Null", TextVN_QuanHam[98], sizeof(TextVN_QuanHam[98]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam99", "Null", TextVN_QuanHam[99], sizeof(TextVN_QuanHam[99]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam100", "Null", TextVN_QuanHam[100], sizeof(TextVN_QuanHam[100]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam101", "Null", TextVN_QuanHam[101], sizeof(TextVN_QuanHam[101]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam102", "Null", TextVN_QuanHam[102], sizeof(TextVN_QuanHam[102]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam103", "Null", TextVN_QuanHam[103], sizeof(TextVN_QuanHam[103]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam104", "Null", TextVN_QuanHam[104], sizeof(TextVN_QuanHam[104]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam105", "Null", TextVN_QuanHam[105], sizeof(TextVN_QuanHam[105]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam106", "Null", TextVN_QuanHam[106], sizeof(TextVN_QuanHam[106]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam107", "Null", TextVN_QuanHam[107], sizeof(TextVN_QuanHam[107]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam108", "Null", TextVN_QuanHam[108], sizeof(TextVN_QuanHam[108]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam109", "Null", TextVN_QuanHam[109], sizeof(TextVN_QuanHam[109]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam110", "Null", TextVN_QuanHam[110], sizeof(TextVN_QuanHam[110]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam111", "Null", TextVN_QuanHam[111], sizeof(TextVN_QuanHam[111]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam112", "Null", TextVN_QuanHam[112], sizeof(TextVN_QuanHam[112]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam113", "Null", TextVN_QuanHam[113], sizeof(TextVN_QuanHam[113]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam114", "Null", TextVN_QuanHam[114], sizeof(TextVN_QuanHam[114]), TEXTVN_FILE);
	GetPrivateProfileStringA("TextVN_QuanHam", "TextVN_QuanHam115", "Null", TextVN_QuanHam[115], sizeof(TextVN_QuanHam[115]), TEXTVN_FILE);
}																	  



void GensLogoPlayer(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)
{
	gObjUser.Refresh();
	RenderBitmap(a1, a2 - valor, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}

void CRenderBoolean(int a1, int a2, char *a3)
{
	int result = *(DWORD *)(a3 + 668);

	if (*(BYTE *)(result + 800) == 1)
	{
		CreateGuildMark(*(WORD *)(result + 124), 1);
		RenderBitmap(31740, a1 - 11, a2, 15.0, 15.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
	}

	RenderBoolean(a1, a2, a3);
}

void PlayerGuildLogo(int a1, int a2, char *a3) // ok
{
	gObjUser.Refresh();

	int result = *(DWORD *)(a3 + 668);

	if ((*(WORD *)(result + 124) == 0)) // ok
	{
		valor = 15;
		CreateGuildMark(*(WORD *)(result + 124), 1);
		RenderBitmap(31740, a1 - 14, a2, 15.0, 15.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);

		if (ImgTag > 100) ImgTag = 0;
			pDrawButton(0xF2001, a1 -14, a2, 15, 15, (ImgTag % 4) * 15, (ImgTag / 60) * 15);
		ImgTag++;

	}

	if (!(*(WORD *)(result + 124) == 0)) // ok
	{
		valor = 15;
		CreateGuildMark(*(WORD *)(result + 124), 1);
		RenderBitmap(31740, a1 - 14, a2, 15.0, 15.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
	}


	RenderBoolean(a1, a2, a3);
}

// ----------------------------------------------------------------------------------------------
void Other::Crack()
{
	//MiniBuff Icon
	SetFloat((PVOID)(0x00D43220), 10);
	SetFloat((PVOID)(0x00D43224), 12);
	SetByte((PVOID)(0x00777E70), 0x16);
	//----------------------------------------------------------------------
	//-> level xoa nhan vat
	SetDword((PVOID)(0x00405B7A + 2), 401); // Delete rule
	SetDword((PVOID)(0x0040CC3F + 1), 401); // Error message
	//----------------------------------------------------------------------
//	SetCompleteHook(0xFF, 0x00830BA6, &MoveListInit);
//	SetCompleteHook(0xFF, 0x00832ED8, &MoveListInit);
	//----------------------------------------------------------------------
	//SetOp((LPVOID)0x004D2180, (LPVOID)GameLoad, ASM::CALL);
	//----------------------------------------------------------------------
	SetOp2((LPVOID)0x004060D0, this->LoadNewFontA, ASM::CALL, 6);
	SetOp2((LPVOID)0x004D2882, this->LoadNewFontA, ASM::CALL, 6);
	SetOp2((LPVOID)0x004D28EB, this->LoadNewFontA, ASM::CALL, 6);
	SetOp2((LPVOID)0x004D2957, this->LoadNewFontA, ASM::CALL, 6);
	SetOp2((LPVOID)0x004D29C1, this->LoadNewFontA, ASM::CALL, 6);
	//----------------------------------------------------------------------
	//Fix CTRL Freeze
	SetByte((LPVOID)0x0052101B, 0x02);

	//SetByte(0x0059AF53 + 2, 0);
	//SetByte(0x0059B248 + 2, 0);


	//SetCompleteHook(0xE8, 0x005BAFAB, &PlayerGuildLogo);

	//SetCompleteHook(0xE8, 0x007C5DB0, &GensLogoPlayer);
	
}
// ----------------------------------------------------------------------------------------------

HFONT Other::LoadNewFontA(int nHeight,
	int nWidth,
	int nEscapement,
	int nOrientation,
	int fnWeight,
	DWORD fdwItalic,
	DWORD fdwUnderline,
	DWORD fdwStrikeOut,
	DWORD fdwCharSet,
	DWORD fdwOutputPrecision,
	DWORD fdwClipPrecision,
	DWORD fdwQuality,
	DWORD fdwPitchAndFamily,
	LPCTSTR lpszFace) {
	int Height = 13; // 13
	int Width = 0;
	int Italic = 0;
	DWORD UnderLine = 0;
	DWORD StrikeOut = 0;
	return CreateFontA(Height, Width, 0, 0, fnWeight, Italic, UnderLine, StrikeOut, DEFAULT_CHARSET, 0, 0, fdwQuality, 0, "Tahoma");
}
//-------------------------------------------------------------------------------------------------------------------
//void Other::MoveListInit(LPVOID This, LPVOID EDX, int Arg1, int Arg2) {
//	GLsizei TempWidth = pWinWidth;
//	pWinWidth = 1280;
//	pMoveListInit(This, Arg1, Arg2);
//	pWinWidth = TempWidth;
//	GLsizei TempHeight = pWinHeight;
//	pWinHeight = 1920;
//	pMoveListInit(This, Arg1, Arg2);
//	pWinHeight = TempHeight;
//	return pMoveListInit(This, Arg1, Arg2);
//}
// ----------------------------------------------------------------------------------------------
//int Other::GameLoad()
//{
//	pGameLoad();
//	// ----
//	switch (pGameResolutionMode)
//	{
//	case 0:
//		pWinWidth = 640;
//		pWinHeight = 480;
//		break;
//		// --
//	case 1:
//		pWinWidth = 800;
//		pWinHeight = 500;
//
//		break;
//		// --
//	case 2:
//		pWinWidth = 1024;
//		pWinHeight = 640;
//		break;
//		// --
//	case 3:
//		pWinWidth = 1280;
//		pWinHeight = 720;
//		break;
//		// --
//	case 4:
//		pWinWidth = 1366;
//		pWinHeight = 850;
//		break;
//
//		// --
//	case 5:
//		pWinWidth = 1440;
//		pWinHeight = 810;
//		break;
//		// --
//	case 6:
//		pWinWidth = 1536;
//		pWinHeight = 864;
//		break;
//		// --
//	case 7:
//		pWinWidth = 1650;
//		pWinHeight = 1050;
//		break;
//		// --
//	case 8:
//		pWinWidth = 1920;
//		pWinHeight = 1080;
//		break;
//		// --
//	case 9:
//		pWinWidth = 500;
//		pWinHeight = 375;
//		break;
//	//case 0:
//	//	pWinWidth = 640;
//	//	pWinHeight = 480;
//	//	break;
//	//	 --
//	//case 1:
//	//	pWinWidth = 800;
//	//	pWinHeight = 600;
//	//	break;
//	//	 --
//	//case 2:
//	//	pWinWidth = 1024;
//	//	pWinHeight = 768;
//	//	break;
//	//	 --
//	//case 3:
//	//	pWinWidth = 1152;
//	//	pWinHeight = 864;
//	//	break;
//	//	 --
//	//case 4:
//	//	pWinWidth = 1280;
//	//	pWinHeight = 768;
//	//	break;
//	//	 --
//	//case 5:
//	//	pWinWidth = 1280;
//	//	pWinHeight = 800;
//	//	break;
//	//	 --
//	//case 6:
//	//	pWinWidth = 1280;
//	//	pWinHeight = 960;
//	//	break;
//	//	 --
//	//case 7:
//	//	pWinWidth = 1280;
//	//	pWinHeight = 1024;
//	//	break;
//	//	 --
//	//case 8:
//	//	pWinWidth = 1366;
//	//	pWinHeight = 768;
//	//	break;
//	//	 --
//	//case 9:
//	//	pWinWidth = 1440;
//	//	pWinHeight = 900;
//	//	break;
//	//	 --
//	//case 10:
//	//	pWinWidth = 1600;
//	//	pWinHeight = 900;
//	//	break;
//	//	 --
//	//case 11:
//	//	pWinWidth = 1600;
//	//	pWinHeight = 1200;
//	//	break;
//	//	 --
//	//case 12:
//	//	pWinWidth = 1680;
//	//	pWinHeight = 1050;
//	//	break;
//	//	 --
//	//case 13:
//	//	pWinWidth = 1920;
//	//	pWinHeight = 1080;
//	//	break;
//	//	 --
//	//case 14:
//	//	pWinWidth = 1920;
//	//	pWinHeight = 1200;
//	//	break;
//	//	 --
//	//case 15:
//	//	pWinWidth = 1024;
//	//	pWinHeight = 600;
//	//	break;
//	//	 --
//	//case 16:
//	//	pWinWidth = 1910;
//	//	pWinHeight = 970;
//	//	break;
//	//	 --
//	//case 17:
//	//	pWinWidth = 1350;
//	//	pWinHeight = 650;
//	//	break;
//	}
//	// ----
//	pWinFontHeight = 150;
//	pWinWidthReal = (float)pWinWidth / MAX_WIN_WIDTH;
//	pWinHeightReal = (float)pWinHeight / MAX_WIN_HEIGHT;
//	// ----
//	return 1;
//}
// ----------------------------------------------------------------------------------------------
