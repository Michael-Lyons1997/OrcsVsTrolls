#include "troll.h"
troll::troll()
{
}


troll::~troll()
{
}

void troll::setAttack(melee newAttack)
{
	meleeAttack = newAttack;
}

void troll::setMagic(spells newSpells)
{
	spellUse = newSpells;
}

void troll::setDefense(defend newDefense)
{
	defense = newDefense;
}

void troll::setStamina(int newStamina)
{
	mana = newStamina;
}

Character::melee troll::getAttack()
{
	return melee();
}

Character::spells troll::getSpell()
{
	return spells();
}

Character::defend troll::getDefense()
{
	return defend();
}

int troll::getStamina()
{
	return mana;
}






