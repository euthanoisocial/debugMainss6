#pragma once


#if (SELECTCHARACTER==1)
#include "Protocol.h"

class MultiCharacter
{
public:
	MultiCharacter();
	~MultiCharacter();
	// ----
	static void SelectChar();
	void	EventSelectChar(DWORD Event);
	// ----
public:
	int m_CharacterPage;
	// ----
}; extern MultiCharacter gMultiCharacter;
#endif