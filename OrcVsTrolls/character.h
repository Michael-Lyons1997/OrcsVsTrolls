#pragma once
#include <iostream>


class Character
{
public:
	int mana = 100;
	enum class melee
	{
		bash, screech, claw, bite, stab, gouge, punch
	};
	enum class spells
	{
		wind, water, fire, earth, lightning
	};
	enum class defend
	{
		prone, shield, ripost
	};
	melee meleeAttack = melee::bash;
	spells spellUse = spells::wind;
	defend defense = defend::prone;
};
