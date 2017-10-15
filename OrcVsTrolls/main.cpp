#include "main.h"
#include "character.h"
#include "orc.h"
#include "troll.h"
#include<string.h>
#include<time.h>


int main()
{
	troll newTroll;
	orc newOrc;
	Character *npc = nullptr;
	Character *player = nullptr;
	srand((int)time(0));
	int side = 0;
	int playerAttackDefendMagic = 0;
	int cpuAttackDefendMagic = 0;
	int playerAttack = 0;
	int playerDef = 0;
	int playerSpell = 0;
	int randomAttack = 0;
	int randomDef = 0;
	int randomSpell = 0;
	bool wrongValue = false;
	bool orcWin = false;
	bool trollWin = false;
	bool draw = false;
	char goAgain = ' ';
	while (!orcWin && !trollWin)
	{
		wrongValue = false;
		orcWin = false;
		trollWin = false;
		draw = false;
		system("cls");
		std::cout << "Welcome to ORCS VS TROLLS 2017! \nPlease, pick your side: (1) Orcs, \t(2) Trolls" << std::endl;
		std::cin >> side;
		if (side == 1)
		{
			system("cls");
			npc = &newTroll;
			player = &newOrc;
			std::cout << "You have picked the orcs. \nDo you want to attack, use a spell, or defend. \nEach spell uses 10 mana.\n(1) attack \t(2) spell \t(3) defend" << std::endl;
			std::cin >> playerAttackDefendMagic;
			//Sets orc attack
			if (playerAttackDefendMagic == 1)
			{
				system("cls");
				std::cout << "Enter your attack: \n(1) Rock Bash, (2) Screech, (3) Claw, (4) Bite, (5) Stab, (6) Gouge, (7) Punch" << std::endl;			std::cin >> playerAttack;
				switch (playerAttack)
				{
				case 1:
					newOrc.setAttack(Character::melee::bash);
					break;
				case 2:
					newOrc.setAttack(Character::melee::screech);
					break;
				case 3:
					newOrc.setAttack(Character::melee::claw);
					break;
				case 4:
					newOrc.setAttack(Character::melee::bite);
					break;
				case 5:
					newOrc.setAttack(Character::melee::stab);
					break;
				case 6:
					newOrc.setAttack(Character::melee::gouge);
					break;
				case 7:
					newOrc.setAttack(Character::melee::punch);
					break;
				default:
					system("cls");
					std::cout << "Error, you did not pick a valid value. \nTry again \n(but you will start from the main screen)" << std::endl;
					system("pause");
					wrongValue = true;
					break;
				}
			}
			//sets orc spell
			else if (playerAttackDefendMagic == 2 && newOrc.getStamina() > 0)
			{

				system("cls");
				std::cout << "Enter your spell: \n(1) Wind, (2) Water, (3) Fire, (4) Earth, (5) Lightning" << std::endl;
				std::cin >> playerSpell;
				switch (playerSpell)
				{
				case 1:
					newOrc.setMagic(Character::spells::wind);
					break;
				case 2:
					newOrc.setMagic(Character::spells::water);
					break;
				case 3:
					newOrc.setMagic(Character::spells::fire);
					break;
				case 4:
					newOrc.setMagic(Character::spells::earth);
					break;
				case 5:
					newOrc.setMagic(Character::spells::lightning);
					break;
				default:
					system("cls");
					std::cout << "Error, you did not pick a valid value. \nTry again \n(but you will start from the main screen)" << std::endl;
					system("pause");
					wrongValue = true;
					break;
				}
				newOrc.setStamina(newOrc.getStamina() - 10);
			}
			//sets orc defense
			else if (playerAttackDefendMagic == 3)
			{
				system("cls");
				std::cout << "Enter your defense: \n(1) Prone, (2) Shield, (3) Ripost" << std::endl;
				std::cin >> playerDef;
				switch (playerDef)
				{
				case 1:
					newOrc.setDefense(Character::defend::prone);
					break;
				case 2:
					newOrc.setDefense(Character::defend::shield);
					break;
				case 3:
					newOrc.setDefense(Character::defend::ripost);
					break;
				default:
					system("cls");
					std::cout << "Error, you did not pick a valid value. \nTry again \n(but you will start from the main screen)" << std::endl;
					system("pause");
					wrongValue = true;
					break;
				}
			}
			else
			{
				system("cls");
				std::cout << "Error, you did not pick a valid value. \nTry again \n(but you will start from the main screen)" << std::endl;
				system("pause");
				wrongValue = true;
			}
			//lets the computer choose what it wants to do
			cpuAttackDefendMagic = rand() % 4;
			if (cpuAttackDefendMagic == 1)
			{
				randomAttack = rand() % 8;
				switch (randomAttack)
				{
				case 1:
					newTroll.setAttack(Character::melee::bash);
					break;
				case 2:
					newTroll.setAttack(Character::melee::screech);
					break;
				case 3:
					newTroll.setAttack(Character::melee::claw);
					break;
				case 4:
					newTroll.setAttack(Character::melee::bite);
					break;
				case 5:
					newTroll.setAttack(Character::melee::stab);
					break;
				case 6:
					newTroll.setAttack(Character::melee::gouge);
					break;
				case 7:
					newTroll.setAttack(Character::melee::punch);
					break;
				default:
					break;
				}
			}
			else if (cpuAttackDefendMagic == 2 && newTroll.getStamina() > 0)
			{
				randomDef = rand() % 6;
				switch (randomDef)
				{
				case 1:
					newTroll.setMagic(Character::spells::wind);
					break;
				case 2:
					newTroll.setMagic(Character::spells::water);
					break;
				case 3:
					newTroll.setMagic(Character::spells::fire);
					break;
				case 4:
					newTroll.setMagic(Character::spells::earth);
					break;
				case 5:
					newTroll.setMagic(Character::spells::lightning);
					break;
				default:
					break;
				}
				newTroll.setStamina(newTroll.getStamina() - 10);
			}
			else if (cpuAttackDefendMagic == 3)
			{
				randomSpell = rand() % 4;
				switch (randomSpell)
				{
				case 1:
					newTroll.setDefense(Character::defend::prone);
					break;
				case 2:
					newTroll.setDefense(Character::defend::shield);
					break;
				case 3:
					newTroll.setDefense(Character::defend::ripost);
					break;
				default:
					break;
				}
			}
			system("cls");
			//battle system
			if (!wrongValue)
			{
				switch (playerAttackDefendMagic)
				{
				case 1:
					switch (cpuAttackDefendMagic)
					{
					case 1:
						std::cout << "you both attacked." << std::endl;
						draw = true;
						orcWin = false;
						break;
					case 2:
						std::cout << "You attacked while the trolls were using a spell" << std::endl;
						orcWin = true;
						draw = false;
						trollWin = false;
						break;
					case 3:
						std::cout << "you attacked while the trolls were defending" << std::endl;
						draw = false;
						orcWin = false;
						trollWin = true;
					}
					break;
				case 2:
					switch (cpuAttackDefendMagic)
					{
					case 1:
						std::cout << "The trolls attacked while you were using magic." << std::endl;
						draw = false;
						orcWin = false;
						trollWin = true;
						break;
					case 2:
						std::cout << "You both used a spell" << std::endl;
						draw = true;
						orcWin = false;
						trollWin = false;
						break;
					case 3:
						std::cout << "you used a spell while the trolls were defending" << std::endl;
						orcWin = true;
						draw = false;
						trollWin = false;
					}
					break;
				case 3:
					switch (cpuAttackDefendMagic)
					{
					case 1:
						std::cout << "You blocked the attack." << std::endl;
						orcWin = true;
						draw = false;
						trollWin = false;
						break;
					case 2:
						std::cout << "You defended a spell. it's not very effective." << std::endl;
						trollWin = true;
						draw = false;
						orcWin = false;
						break;
					case 3:
						std::cout << "you both defended." << std::endl;
						draw = true;
						orcWin = false;
						trollWin = false;
					}
					break;
				default:
					break;
				}
				system("pause");
				system("cls");
				if (draw)
				{
					std::cout << "you drew. Do you want to try again? (Y/N)" << std::endl;
					std::cin >> goAgain;
					goAgain = toupper(goAgain);
					if (goAgain == 'N')
					{
						orcWin = true;
					}
				}
			}

		}
		//troll's side
		else if (side == 2)
		{
			npc = &newOrc;
			player = &newTroll;
			system("cls");
			std::cout << "You have picked the trolls. \nDo you want to attack, use a spell, or defend. \nEach spell uses 10 mana.\n(1) attack \t(2) spell \t(3) defend" << std::endl;
			std::cin >> playerAttackDefendMagic;
			if (playerAttackDefendMagic == 1)
			{
				system("cls");
				std::cout << "Enter your attack: \n(1) atk1, (2) atk2, (3) atk3, (4) atk4, (5) atk5, (6) atk6, (7) atk7" << std::endl;
				std::cin >> playerAttack;
				switch (playerAttack)
				{
				case 1:
					newTroll.setAttack(Character::melee::bash);
					break;
				case 2:
					newTroll.setAttack(Character::melee::screech);
					break;
				case 3:
					newTroll.setAttack(Character::melee::claw);
					break;
				case 4:
					newTroll.setAttack(Character::melee::bite);
					break;
				case 5:
					newTroll.setAttack(Character::melee::stab);
					break;
				case 6:
					newTroll.setAttack(Character::melee::gouge);
					break;
				case 7:
					newTroll.setAttack(Character::melee::punch);
					break;
				default:
					system("cls");
					std::cout << "Error, you did not pick a valid value. \nTry again \n(but you will start from the main screen)" << std::endl;
					system("pause");
					wrongValue = true;
					break;
				}
			}
			else if (playerAttackDefendMagic == 2 && newOrc.getStamina() > 0)
			{
				system("cls");
				std::cout << "Enter your spell: \n(1) spell1, (2) spell2, (3) spell3, (4) spell4, (5) spell5" << std::endl;
				std::cin >> playerSpell;
				switch (playerSpell)
				{
				case 1:
					newTroll.setMagic(Character::spells::wind);
					break;
				case 2:
					newTroll.setMagic(Character::spells::water);
					break;
				case 3:
					newTroll.setMagic(Character::spells::fire);
					break;
				case 4:
					newTroll.setMagic(Character::spells::earth);
					break;
				case 5:
					newTroll.setMagic(Character::spells::lightning);
					break;
				default:
					system("cls");
					std::cout << "Error, you did not pick a valid value. \nTry again \n(but you will start from the main screen)" << std::endl;
					system("pause");
					wrongValue = true;
					break;
				}
				newTroll.setStamina(newOrc.getStamina() - 10);
			}
			else if (playerAttackDefendMagic == 3)
			{
				system("cls");
				std::cout << "Enter your defense: \n(1) def1, (2) def2, (3) def3" << std::endl;
				std::cin >> playerDef;
				switch (playerDef)
				{
				case 1:
					newTroll.setDefense(Character::defend::prone);
					break;
				case 2:
					newTroll.setDefense(Character::defend::shield);
					break;
				case 3:
					newTroll.setDefense(Character::defend::ripost);
					break;
				default:
					system("cls");
					std::cout << "Error, you did not pick a valid value. \nTry again \n(but you will start from the main screen)" << std::endl;
					system("pause");
					wrongValue = true;
					break;
				}
			}
			else
			{
				system("cls");
				std::cout << "Error, you did not pick a valid value. \nTry again \n(but you will start from the main screen)" << std::endl;
				system("pause");
				wrongValue = true;
			}
			cpuAttackDefendMagic = rand() % 4;
			if (cpuAttackDefendMagic == 1)
			{
				randomAttack = rand() % 8;
				switch (randomAttack)
				{
				case 1:
					newOrc.setAttack(Character::melee::bash);
					break;
				case 2:
					newOrc.setAttack(Character::melee::screech);
					break;
				case 3:
					newOrc.setAttack(Character::melee::claw);
					break;
				case 4:
					newOrc.setAttack(Character::melee::bite);
					break;
				case 5:
					newOrc.setAttack(Character::melee::stab);
					break;
				case 6:
					newOrc.setAttack(Character::melee::gouge);
					break;
				case 7:
					newOrc.setAttack(Character::melee::punch);
					break;
				default:
					break;
				}
			}
			else if (cpuAttackDefendMagic == 2 && newTroll.getStamina() > 0)
			{
				randomDef = rand() % 6;
				switch (randomDef)
				{
				case 1:
					newOrc.setMagic(Character::spells::wind);
					break;
				case 2:
					newOrc.setMagic(Character::spells::water);
					break;
				case 3:
					newOrc.setMagic(Character::spells::fire);
					break;
				case 4:
					newOrc.setMagic(Character::spells::earth);
					break;
				case 5:
					newOrc.setMagic(Character::spells::lightning);
					break;
				default:
					break;
				}
				newTroll.setStamina(newTroll.getStamina() - 10);
			}
			else if (cpuAttackDefendMagic == 3)
			{
				randomSpell = rand() % 4;
				switch (randomSpell)
				{
				case 1:
					newOrc.setDefense(Character::defend::prone);
					break;
				case 2:
					newOrc.setDefense(Character::defend::shield);
					break;
				case 3:
					newOrc.setDefense(Character::defend::ripost);
					break;
				default:
					break;
				}
			}
			system("cls");
			if (!wrongValue)
			{
				switch (playerAttackDefendMagic)
				{
				case 1:
					switch (cpuAttackDefendMagic)
					{
					case 1:
						std::cout << "you both attacked." << std::endl;
						draw = true;
						trollWin = false;
						orcWin = false;
						break;
					case 2:
						std::cout << "You attacked while the orcs were using a spell" << std::endl;
						trollWin = true;
						draw = false;
						orcWin = false;
						break;
					case 3:
						std::cout << "you attacked while the orcs were defending" << std::endl;
						orcWin = true;
						draw = false;
						trollWin = false;
						break;
					}
				case 2:
					switch (cpuAttackDefendMagic)
					{
					case 1:
						std::cout << "The orcs attacked while you were using magic." << std::endl;
						orcWin = true;
						draw = false;
						trollWin = false;
						break;
					case 2:
						std::cout << "You both used a spell" << std::endl;
						draw = true;
						trollWin = false;
						orcWin = false;
						break;
					case 3:
						std::cout << "you used a spell while the orcs were defending" << std::endl;
						trollWin = true;
						draw = false;
						orcWin = false;
					}
					break;
				case 3:
					switch (cpuAttackDefendMagic)
					{
					case 1:
						std::cout << "You blocked the attack." << std::endl;
						trollWin = true;
						draw = false;
						orcWin = false;
						break;
					case 2:
						std::cout << "You defended a spell. it's not very effective." << std::endl;
						orcWin = true;
						draw = false;
						trollWin = false;
						break;
					case 3:
						std::cout << "you both defended." << std::endl;
						draw = true;
						trollWin = false;
						orcWin = false;
					}
					break;
				default:
					break;
				}
				system("pause");
				system("cls");
				if (draw)
				{
					std::cout << "you drew. Do you want to try again? (Y/N)" << std::endl;
					std::cin >> goAgain;
					goAgain = toupper(goAgain);
					if (goAgain == 'N')
					{
						orcWin = true;
					}
				}
			}
		}
		else
		{
			system("cls");
			std::cout << "Error, you did not pick a valid value. \nTry again \n(but you will start from the main screen)" << std::endl;
			system("pause");
			wrongValue = true;
		}

	}
	if (side == 1)
	{
		system("cls");
		if (orcWin)
		{
			std::cout << "You did it, you beat the trolls. (There wasn't that many)." << std::endl;
		}
		if (draw)
		{
			std::cout << "It's a stalemate. How will you solve it?" << std::endl;
		}
		if (trollWin)
		{
			std::cout << "The trolls now control the kingdom. RIP" << std::endl;
		}
	}
	if (side == 2)
	{
		if (trollWin)
		{
			std::cout << "You did it, you beat the orcs. (There wasn't that many)." << std::endl;
		}
		if (draw)
		{
			std::cout << "It's a stalemate. How will you solve it?" << std::endl;
		}
		if (orcWin)
		{
			std::cout << "The orcs now control the kingdom. RIP" << std::endl;
		}
	}

	system("pause");
	return 0;
}