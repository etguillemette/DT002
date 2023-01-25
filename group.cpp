#include "group.h"


//Function that goes through the dialogue for picking a character class
charClass pickClass(std::string charName)
{
	std::system("clear");

	//Name (in string form) of the class
	std::string strClass;
	//Base strength of the class
	int strength = 0;
	//Base agility of the class
	int agility = 0;
	//Base wits of the class
	int wits = 0;


	std::cout << "What is " << charName << "'s class? Choose from the following: \n";
	std::cout << strBold("Strength-based classes:\t\t(1) Crusher\t(2) Bruiser\t(3) Brawler\n", fred);
	std::cout << strBold("Agility-based classes:\t\t(4) Dodger\t(5) Acrobat\t(6) Rogue\n", fgreen);
	std::cout << strBold("Wits-based classes:\t\t(7) Mastermind\t(8) Trickster\t(9) Duelist\n", fblue);
	std::cout << strBold("Even classes:\t\t\t(10) Fighter\n", fgray);

	std::cout << "Which is your choice?\n";

	//Sanitized int input
	int ninput = getIntInput(1, 10);

	switch (ninput) {
	case 1: strClass = "Crusher"; strength = 4; agility = 1; wits = 1; break;
	case 2: strClass = "Bruiser"; strength = 3; agility = 2; wits = 1; break;
	case 3: strClass = "Brawler"; strength = 3; agility = 1; wits = 2; break;
	case 4: strClass = "Dodger"; strength = 1; agility = 4; wits = 1; break;
	case 5: strClass = "Acrobat"; strength = 2; agility = 3; wits = 1; break;
	case 6: strClass = "Rogue"; strength = 1; agility = 3; wits = 2; break;
	case 7: strClass = "Mastermind"; strength = 1; agility = 1; wits = 4; break;
	case 8: strClass = "Trickster"; strength = 1; agility = 2; wits = 3; break;
	case 9: strClass = "Duelist"; strength = 2; agility = 1; wits = 3; break;
	case 10: strClass = "Fighter"; strength = 2; agility = 2; wits = 2; break;
	}

	//Export object for the class picked
	charClass classPicked(strClass, strength, agility, wits);

	return classPicked;
}

//Sorting function to test whether or not a pack member has higher agility
void sortAgility(std::vector<packMember>& pack)
{
	bool swapp = true;
	while (swapp) {
		swapp = false;
		for (int i = 0; i < pack.size() - 1; i++)
		{
			packMember a = pack[i];
			packMember b = pack[i + 1];
			if (pack[i].agility < pack[i + 1].agility) {
				pack[i] = b;
				pack[i + 1] = a;
				swapp = true;
			}
		}
	}
}

void sortByProperty(std::vector<packMember>& pack, int packMember::*member, bool reverse)
{
	bool swapp = true;
	while (swapp) {
		swapp = false;
		
		if (!reverse)
		{
			for (int i = 0; i < pack.size() - 1; i++)
			{
				packMember a = pack[i];
				packMember b = pack[i + 1];
				if (pack[i].*member < pack[i + 1].*member) {
					pack[i] = b;
					pack[i + 1] = a;
					swapp = true;
				}
			}
		}
		else 
		{
			for (int i = 0; i < pack.size() - 1; i++)
			{
				packMember a = pack[i];
				packMember b = pack[i + 1];
				if (pack[i].*member > pack[i + 1].*member) {
					pack[i] = b;
					pack[i + 1] = a;
					swapp = true;
				}
			}
		}

	}
}


//Relays information about the pack and its current status to the terminal
void packStatus(gameState game)
{
	//Header
	std::cout << strBold("Name        Class       Fullness        Focus        Stamina\n", fgray);
	//Repeats the status (hunger, stamina, focus) of all the members of the pack
	for (size_t p = 0; p < game.playerPack.size(); p++)
	{
		std::cout << game.playerPack[p].strName << altTab(game.playerPack[p].strName.size()) << game.playerPack[p].strClass << altTab(game.playerPack[p].strClass.size()) << game.playerPack[p].hunger << "\t\t" << game.playerPack[p].focus << "\t\t" << game.playerPack[p].stamina << "\n";
	}

	//Prints to the terminal the current status of the pack's inventory
	std::cout << strBold("Trash: ", fyellow) << game.nTrash << strBold("\tBalls: ", fgreen) << game.nBalls << strBold("\tFood : ", fblue) << game.nFood << strBold("\tShivs: ", fred) << game.nShivs << "\n";
	std::cout << strBold("Distance From Home: \t", fmagenta) << &game.nDistance << "ft\n";
	//Prints the journey "map"
	printDistance(game);
	std::cout << "\n\n";
}


//Function that checks to see if any of the members of the pack has dropped off
void packCheck(gameState &game)
{
	//This is a placeholder that will 
	std::vector<packMember> packExport;

	//Runs through each member of the pack
	for (int p = 0; p < game.playerPack.size(); p++)
	{
		//Placeholder value. Really just to make sure that only one of these pack member leaving dialogues triggers, even if multiple events qualify
		int status = 0;

		//Checks if any of the main status stats has fallen below 0
		if (game.playerPack[p].hunger < 1 || game.playerPack[p].stamina < 1 || game.playerPack[p].focus < 1 || game.playerPack[p].hp < 1)
		{
			if (game.playerPack[p].hunger < 1 && status == 0)
			{
				std::cout << "Oh no! " << game.playerPack[p].strName << " is too hungry to continue the journey! They're wandering off to find some food...\n";
				status = 1;
				proceedCheck(game);
			}
			if (game.playerPack[p].stamina < 1 && status == 0)
			{
				std::cout << "Oh no! " << game.playerPack[p].strName << " is too tired continue the journey! They're just going to take a nap here...\n";
				status = 1;
				proceedCheck(game);
			}
			if (game.playerPack[p].focus < 1 && status == 0)
			{
				std::cout << "Oh no! " << game.playerPack[p].strName << " is too bored continue the journey! They're wandering off to find some shit to get into...\n";
				status = 1;
				proceedCheck(game);
			}
			if (game.playerPack[p].hp < 1 && status == 0)
			{
				std::cout << "Oh no! " << game.playerPack[p].strName << " was too disgraced by the fight to continue the journey! They're slinking away with a wounded pride...\n";
				status = 1;
				proceedCheck(game);
			}
		}
		else {
			packExport.push_back(game.playerPack[p]);
		}
	}

	game.playerPack = packExport;
}