#pragma once



#define _BYTE	BYTE
#define _WORD	WORD
#define _DWORD	DWORD
#define _FLOAT	FLOAT
// ----------------------------------------------------------------------------------------------
#define MODEL_BODY_NUM			24
#define MODEL_BODY_HELM			9389 //-- 9389
#define MODEL_BODY_ARMOR		9413 //-- 9413
#define MODEL_BODY_PANTS		9437 //-- 9437
#define MODEL_BODY_GLOVES		9461//-- 9461
#define MODEL_BODY_BOOTS		9485 //-- 9485
#define MODEL_PLAYER			1163
#define MODEL_HELPER			7827
#define EQUIP_BODY_HELM			268 //-- 9389
#define EQUIP_BODY_ARMOR		304 //-- 9389
#define EQUIP_BODY_PANTS		340 //-- 9389
#define EQUIP_BODY_GLOVES		376 //-- 9389
#define EQUIP_BODY_BOOTS		412 //-- 9389
#define MAX_ITEM_INFO			12
#define MAX_BONES				200
#define MAX_MESH				50
#define MAX_VERTICES			15000
#define SERVER_LIST_SCENE		0
#define	NON_SCENE				0
#define WEBZEN_SCENE			1
#define LOG_IN_SCENE			2
#define LOADING_SCENE			3
#define CHARACTER_SCENE			4
#define MAIN_SCENE				5
#define RENDER_COLOR			0x00000001
#define RENDER_TEXTURE			0x00000002
#define RENDER_CHROME			0x00000004
#define RENDER_METAL			0x00000008
#define RENDER_LIGHTMAP			0x00000010
#define RENDER_SHADOWMAP		0x00000020

#define RENDER_BRIGHT			0x00000040
#define RENDER_DARK				0x00000080

#define RENDER_EXTRA			0x00000100
#define RENDER_CHROME2			0x00000200
#define RENDER_WAVE				0x00000400
#define RENDER_CHROME3			0x00000800
#define RENDER_CHROME4			0x00001000
#define RENDER_NODEPTH			0x00002000
#define RENDER_CHROME5			0x00004000
#define RENDER_OIL				0x00008000
#define RENDER_CHROME6			0x00010000
#define RENDER_CHROME7			0x00020000
#ifdef YDG_ADD_DOPPELGANGER_MONSTER
#define RENDER_DOPPELGANGER        0x00040000
#endif	// YDG_ADD_DOPPELGANGER_MONSTER

#define RENDER_CHROME8			0x00080000


#define MODEL_PLAYER			1163
#define MODEL_HELPER			7827
#define EQUIP_BODY_HELM			268 //-- 9389
#define EQUIP_BODY_ARMOR		304 //-- 9389
#define EQUIP_BODY_PANTS		340 //-- 9389
#define EQUIP_BODY_GLOVES		376 //-- 9389
#define EQUIP_BODY_BOOTS		412 //-- 9389

#define RENDER_WAVE_EXT			0x10000000
#define RENDER_BYSCRIPT			0x80000000
#define SOCKET_EMPTY			0xFF
#define RNDEXT_WAVE				1
#define RNDEXT_OIL				2
#define RNDEXT_RISE				4
#define MAX_MONSTER_SOUND		10//5
#define MODEL_ITEM				1171
#define MAX_ITEM_INDEX			512
#define ITEM_SWORD(x)			(0 + x)   //pal,etc
#define ITEM_AXE(x)				(1 * MAX_ITEM_INDEX + x)  //ran,dru
#define ITEM_MACE(x)			(2 * MAX_ITEM_INDEX + x)  //ran,nec
#define ITEM_SPEAR(x)			(3 * MAX_ITEM_INDEX + x)  //ama
#define ITEM_BOW(x)				(4 * MAX_ITEM_INDEX + x)  //ama
#define ITEM_STAFF(x)			(5 * MAX_ITEM_INDEX + x)  //soc
#define ITEM_SHIELD(x)			(6 * MAX_ITEM_INDEX + x) 
#define ITEM_HELM(x)			(7 * MAX_ITEM_INDEX + x)
#define ITEM_ARMOR(x)			(8 * MAX_ITEM_INDEX + x)
#define ITEM_PANTS(x)			(9 * MAX_ITEM_INDEX + x)
#define ITEM_GLOVES(x)			(10 * MAX_ITEM_INDEX + x)
#define ITEM_BOOTS(x)			(11 * MAX_ITEM_INDEX + x)
#define ITEM_WING(x)			(12 * MAX_ITEM_INDEX + x)
#define ITEM_HELPER(x)			(13 * MAX_ITEM_INDEX + x)
#define ITEM_POTION(x)			(14 * MAX_ITEM_INDEX + x)
#define ITEM_ETC(x)				(15 * MAX_ITEM_INDEX + x)
#define MAX_SOCKETS				5
#define MAX_ITEM_SPECIAL		8
#define MAX_CLASS				11
#define MAX_OLD_CLASS			7
#define MAX_RESISTANCE			7
#define SYSTEM_CLASS					9
// ----------------------------------------------------------------------------------------------
#define ITEM_INTER					1171
#define ITEM(x, y)					((x * 512) + y)
#define ITEM2(x, y)					((x * 512) + y + ITEM_INTER)
#define Color4f(r, b, g, o)			((o << 24) + (g << 16) + (b << 8) + r)
#define Naked(Function)				void __declspec(naked) Function()
#define _FC							__fastcall
#define _CD							__cdecl
#define IS_NEWWINGS(x)				((x < ITEM(12, 180)) ? FALSE : (x > ITEM(12, 215)) ? FALSE : TRUE)
#define CS_GET_WEAPON(x, y)			( y | (16 * (x & 0xF0)) )
#define CS_GET_HELM(x, y, z)		( (32 * (z & 0xF)) + 16 * ((x >> 7) & 1) + (y >> 4) )
#define CS_GET_ARMOR(x, y, z)		( (32 * ((z >> 4) & 0xF)) + 16 * ((x >> 6) & 1) + (y & 0xF) )
#define CS_GET_PANTS(x, y, z)		( (32 * (z & 0xF)) + 16 * ((x >> 5) & 1) + (y >> 4) )
#define CS_GET_GLOVES(x, y, z)		( (32 * ((z >> 4) & 0xF)) + 16 * ((x >> 4) & 1) + (y & 0xF) )
#define CS_GET_BOOTS(x, y, z)		( (32 * (z & 0xF)) + 16 * ((x >> 3) & 1) + (y >> 4) )
#define MAX_ITEMOPT_BIT				0x3F
#define GET_ITEMOPT_LEVEL(x)		((x >> 3) & 0xF)
#define SET_ITEMOPT_LEVEL(x)		(x << 3)
#define GET_ITEMOPT0(x)				(x & 3)
#define GET_ITEMOPT16(x)			(x & 0x40)
#define GET_ITEMOPT_SKILL(x)		(x >> 7)
#define GET_ITEMOPT_LUCK(x)			((x >> 2) & 1)
#define GET_ITEMOPT_0(x)			(x & 1)
#define GET_ITEMOPT_1(x)			(((x & MAX_ITEMOPT_BIT) >> 1) & 1)
#define GET_ITEMOPT_2(x)			(((x & MAX_ITEMOPT_BIT) >> 2) & 1)
#define GET_ITEMOPT_3(x)			(((x & MAX_ITEMOPT_BIT) >> 3) & 1)
#define GET_ITEMOPT_4(x)			(((x & MAX_ITEMOPT_BIT) >> 4) & 1)
#define GET_ITEMOPT_5(x)			(((x & MAX_ITEMOPT_BIT) >> 5) & 1)

#define HDK_SET_ITEM_EFFECT 0x0057AD82 //0x0052B0DB
#define HDK_SET_COLOR_EFFECT 0x0057AEFA //0x0052B122
#define HDK_ITEM_EFFECT_ALLOW 0x0057AD8D //0x0052B0E7
#define HDK_ITEM_EFFECT_NOT_ALLOW 0x0057B73B //0x0052B9E0
#define HDK_NEXT_ITEM_COLOR 0x0057AF2E //0x0052B150
#define MAIN_LANGUAGE 0x00E8C5C4
#define VK_N 0x4E
#define VK_R 0x52
#define VK_O 0x4F
#define VK_W 0x57
#define VK_J 0x4A
#define VK_K 0x4B
#define MAX_ACCOUNT_LEVEL 4
#define GetCharacterItem(x) ((*(DWORD*)MAIN_CHARACTER_STRUCT)+0x1240 + x * 0x6B)
// ----------------------------------------------------------------------------------------------

enum eTextAlign
{
	eLeftToRight = 6,
	eRightToLeft = 7,
	eCenter = 8,
};

enum eObjectType	//-> Complete
{
	emPlayer	= 1,
	emMonster	= 2,
	emNPC		= 4,
	emNone		= 8,
};
// ----------------------------------------------------------------------------------------------

enum eClassNumber 
{
	CLASS_WIZARD	= 0,
	CLASS_KNIGHT	= 1,
	CLASS_ELF		= 2,
	CLASS_MAGUMSA	= 3,
	CLASS_DARKLORD	= 4,
	CLASS_SUMMONER	= 5,
	CLASS_MONK		= 6,
};
// ----------------------------------------------------------------------------------------------

enum eClassCode // -> Complete -> Season 5.2 JPN
{
	DarkWizard 		= 0,
	SoulMaster 		= 8,
	GrandMaster		= 24,
	// ----
	DarkKnight		= 1,
	BladeKnight		= 9,
	BladeMaster		= 25,
	// ----
	Elf				= 2,
	MuseElf			= 10,
	HightElf		= 26,
	// ----
	MagicGladiator	= 3,
	DuelMaster		= 19,
	// ----
	DarkLord		= 4,
	LordEmperor		= 28,
	// ----
	//Summoner		= 5,
	BloodySummoner	= 13,
	DimensionMaster	= 29,
	// ----
	Monk			= 6,
	FirstMaster		= 16
};
// ----------------------------------------------------------------------------------------------

enum ObjState // -> Complete
{
	SelectServer	= 2,
	SwitchCharacter = 4,
	GameProcess		= 5,
};
// ----------------------------------------------------------------------------------------------

enum ObjWindow // -> Season 6.3
{
	FriendList		= 1,
	MoveList		= 2,
	Party			= 3,
	Quest			= 4,
	NPC_Devin		= 5,
	Guild			= 6,
	Trade			= 7,
	Warehouse		= 8,
	ChaosBox		= 9,
	CommandWindow	= 10,
	PetInfo			= 11,
	Shop			= 12,
	Inventory		= 13,
	Store			= 14,
	OtherStore		= 15,
	Character		= 16,
	DevilSquare		= 19,
	BloodCastle		= 20,
	CreateGuild		= 21,
	GuardNPC		= 22,
	SeniorNPC		= 23,
	GuardNPC2		= 24,
	CastleGateSwitch= 25,
	CatapultNPC		= 26,
	CrywolfGate		= 29,
	IllusionTemple	= 30,
	HeroList		= 32,
	ChatWindow		= 33,
	FastMenu		= 34,
	Options			= 35,
	Help			= 36,
	FastDial		= 39,
	SkillTree		= 57,
	GoldenArcher1	= 58,
	GoldenArcher2	= 59,
	LuckyCoin1		= 60,
	LuckyCoin2		= 61,
	NPC_Duel		= 62,
	NPC_Titus		= 63,
	CashShop		= 65,
	Lugard			= 66,
	QuestList1		= 68,
	QuestList2		= 69,
	Jerint			= 70,
	FullMap			= 72,
	NPC_Dialog		= 73,
	GensInfo		= 74,
	NPC_Julia		= 75,
	NPC_ChaosMix	= 76,
	ExpandInventory	= 77,
	ExpandWarehouse	= 78,
	MuHelper = 79,
};

namespace ASM
{
	enum T
	{
		JMP			= 0xE9,
		JE			= 0x74,
		JNE			= 0x75,
		JGE			= 0x7D,
		NOP			= 0x90,
		CALL		= 0xE8,
		CALLD		= 0xFF,
		PUSH		= 0x68,
	};
};
// ----------------------------------------------------------------------------------------------

enum eTextColors	//-> Complete
{
	White			= 0x00,
	Blue			= 0x01,
	Red				= 0x02,
	Gold			= 0x03,
	Green			= 0x04,
	WhiteRed		= 0x05,
	Violet			= 0x06,
	WhiteBlue		= 0x07,
	WhiteBeige		= 0x08,
	GreenBlue		= 0x09,
	Gray			= 0x0A,
	DarkViolet		= 0x0B,
};
// ----------------------------------------------------------------------------------------------
	enum ColorLine2
	{
		TEXT_COLOR_WHITE = 0,
		TEXT_COLOR_BLUE,
		TEXT_COLOR_RED,
		TEXT_COLOR_YELLOW,
		TEXT_COLOR_GREEN,
		TEXT_COLOR_DARKRED,
		TEXT_COLOR_PURPLE,
		TEXT_COLOR_DARKBLUE,
		TEXT_COLOR_DARKYELLOW,
		TEXT_COLOR_GREEN_BLUE,
		TEXT_COLOR_GRAY,
		TEXT_COLOR_REDPURPLE,
		TEXT_COLOR_VIOLET,
		TEXT_COLOR_ORANGE = 13,
	};
enum eTextWeight	//-> Complete
{
	Bold			= 0x01,
	Normal			= 0x00,
};
// ----------------------------------------------------------------------------------------------

namespace eItemOption
{
	enum T
	{
		Damage			= 80,		//-> Additional Damage +<N>
		WizardryDamage	= 81,
		CurseSpell		= 82,
		Defense			= 84,		//-> Additional Defense +<N>
		Luck			= 85,		//-> Default: 0
		HPRecovery		= 86,
		// ----
		LifeIncrease	= 87,		//-> Increase Max HP +4%%
		ManaIncrease	= 88,		//-> Increase Max Mana +4%%
		DamageDecrease	= 89,		//-> Damage Decrease +4%%
		Reflect			= 90,		//-> Reflect Damage +5%%
		DefenseSuccess	= 91,		//-> Defense success rate +10%%
		IncreaseZen		= 92,		//-> Increases acquisition rate of Zen after hunting monsters +30%%
		// ----
		ExcellentDamage	= 93,		//-> Excellent Damage rate +10%%
		DamageByLevel	= 94,		//-> Increase Damage +level/20
		IncreaseDamage	= 95,		//-> Increase Damage +%d%%
		IncreaseWizardry= 96,		//-> Increase Wizardry Dmg +level/20
		IncreaseSpeed	= 98,		//-> Increase Attacking(Wizardry)speed +%d
		IgnorOpDefense	= 103,
		ReturnAttack	= 106,		//-> Return's the enemy's attack power in <N>%
		CompleteLife	= 107,		//-> Complete recovery of life in <N>% rate
		CompleteMana	= 108,		//-> Complete recovery of Mana in <N>% rate
		//================
		IncreaseWizardryDmg = 97,    //-> Increase Wizardry Dmg +2%
		LifePerMob        = 99,        //-> Increases acquisition rate of Life after hunting monsters +life/8
		ManaPerMob        = 100,        //-> Increases acquisition rate of Mana after hunting monsters +Mana/8
	};
};
// ----------------------------------------------------------------------------------------------

enum ColorMacro
{
	eTextShop		= Color4f( 0xFFu, 0xDCu, 0x96u, 0xFFu),
	eExcellentS15   = Color4f(67, 204, 65, 255),
	eBlack			= Color4f(0, 0, 0, 255),
	eShinyGreen     = Color4f(172, 255, 56, 255),
	eShinyGreen100  = Color4f(172, 255, 56, 100),
	eGold           = Color4f(255, 189, 25, 255),
	eGold150        = Color4f(255, 189, 25, 150),
	eGold180        = Color4f(255, 189, 25, 180),
	eWhite          = Color4f(255, 255, 255, 255),
	eWhite150       = Color4f(255, 255, 255, 150),
	eWhite180       = Color4f(255, 255, 255, 180),
	eOrange         = Color4f(255, 105, 25, 255),
	eGray100        = Color4f(211, 211, 211, 100),
	eGray150        = Color4f(50, 50, 50, 150),
	eGray190        = Color4f(50, 50, 50, 190),
	eBlowPink       = Color4f(220, 20, 60, 255),
	eRed            = Color4f(225, 0, 0, 255),
	eRed2           = Color4f(225, 95, 45, 255),
	eExcellent      = Color4f(0, 225, 139, 255),
	eAncient        = Color4f(1, 223, 119, 255),
	eSocket         = Color4f(153, 102, 204, 255),
	eBlue           = Color4f(36, 242, 252, 255),
	eBlue250        = Color4f(36, 242, 252, 250),
	eYellow         = Color4f(255, 255, 0, 255),
	eYellow170      = Color4f(255, 255, 0, 170),
	eBrown          = Color4f(69, 39, 18, 255),
	eColorAdvance	= Color4f(109, 25, 192, 255),
};
// ----------------------------------------------------------------------------------------------

enum eMapNumber
{
    Lorencia        = 0,
    Dungeon        = 1,
    Devias        = 2,
    Noria            = 3,
    LostTower        = 4,
    Exile            = 5,
    Stadium        = 6,
    Atlans        = 7,
    Tarkan        = 8,
    DevilSquaree    = 9,
    Icarus        = 10,
    BloodCastle1    = 11,
    BloodCastle2    = 12,
    BloodCastle3    = 13,
    BloodCastle4    = 14,
    BloodCastle5    = 15,
    BloodCastle6    = 16,
    BloodCastle7    = 17,
    ChaosCastle1    = 18,
    ChaosCastle2    = 19,
    ChaosCastle3    = 20,
    ChaosCastle4    = 21,
    ChaosCastle5    = 22,
    ChaosCastle6    = 23,
    Kalima1        = 24,
    Kalima2        = 25,
    Kalima3        = 26,
    Kalima4        = 27,
    Kalima5        = 28,
    Kalima6        = 29,
    Kalima7        = 36,
    Loren            = 30,
    Trials            = 31,
	DevilSquare6    = 32,
    Aida            = 33,
    Crywolf        = 34,
    Kanturu1        = 37,
    Kanturu3        = 38,
    Kanturu_Event    = 39,
    Silent        = 40,
    Barracks        = 41,
    Refuge        = 42,
    Illusion1        = 45,
    Illusion2        = 46,
    Illusion3        = 47,
    Illusion4        = 48,
    Illusion5        = 49,
    Illusion6        = 50,
    Elbeland        = 51,
    BloodCastle8    = 52,
    ChaosCastle7    = 53,
    Calmness        = 56,
    Raklion        = 57,
    RaklionBoss    = 58,
    SantaTown        = 62,
    Vulcanus        = 63,
    Collosseum        = 64,
    Karutan1        = 80,
    Karutan2        = 81,
	CTCMINI         = 98,
	Chientruongco   = 103,
};
// ----------------------------------------------------------------------------------------------
enum CLASS_TYPE_4T
{
	//-- 1�� CLASS
	Dark_Wizard = 0,
	Dark_Knight,
	Fairy_Elf,
	Magic_Gladiator,
	Dark_Lord,
	Summoner,
	Rage_Fighter,
	Grow_Lancer,
	Runer_Wizzard,
	Slayer,
	Gun_Crusher,
	//-- 2DA CLASS
	Soul_Master,
	Blade_Knight,
	Muse_Elf,
	Bloody_Summoner,
	Rune_Spell,
	Royal_Slayer,
	Gun_Breaker,
	//-- 3RA CLASS
	Grand_Master,
	Blade_Master,
	High_Elf,
	Duel_Master,
	Lord_Emperor,
	Dimension_Master,
	Fist_Master,
	Mirage_Lancer,
	Rune_Grand,
	Master_Slayer,
	Master_Gun_Breaker,
	//-- 4TA CLASS
	Soul_Wizard,
	Dragon_Knight,
	Noble_Elves,
	Magic_Knight,
	Empire_Road,
	Dimension_Summoner,
	Fist_Blazer,
	Shining_Lancer,
	Majestic_Rune,
	Slaughterer,
	Heist_Gun_Crasher,
};