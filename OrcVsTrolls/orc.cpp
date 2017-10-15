#include "orc.h"

orc::orc()
{
}


orc::~orc()
{
}

void orc::setAttack(melee newAttack)
{
	meleeAttack = newAttack;
}

void orc::setMagic(spells newSpells)
{
	spellUse = newSpells;
}

void orc::setDefense(defend newDefense)
{
	defense = newDefense;
}

void orc::setStamina(int newStamina)
{
	mana = newStamina;
}

Character::melee orc::getAttack()
{
	return meleeAttack;
}

Character::spells orc::getSpell()
{
	return spellUse;
}

Character::defend orc::getDefense()
{
	return defense;
}

int orc::getStamina()
{
	return mana;
}


