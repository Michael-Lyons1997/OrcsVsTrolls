#pragma once
#include "character.h"
class troll : public Character
{
public:
	troll();
	~troll();
	void setAttack(melee newAttack);
	void setMagic(spells newSpells);
	void setDefense(defend newDefense);
	void setStamina(int newStamina);
	melee getAttack();
	spells getSpell();
	defend getDefense();
	int getStamina();
};


