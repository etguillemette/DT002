#include "menus.h"



//Function that handles string inputs that need to be of a certain size
std::string getStringInput()
{
	std::string userInput;

	std::cin >> userInput;

	while (userInput.size() > con::nameMaxCharSize)
	{
		std::cout << "That is too long. Please stay under " << con::nameMaxCharSize << " characters... Try again:\n";
		std::cin >> userInput;
	}
	return userInput;
}

//Function that handles receiving user input, and verrifies that it's an int before proceeding
int getIntInput(int minVal, int maxVal)
{
	//The int input value that the user will insert into with a cin
	int iInput;
	std::cin >> iInput;

	//Checks to see if max value is disabled. If so, we will only check to see if it meets the minimum value
	if (maxVal == -1)
	{
		//Check to see if the input is valid as an int, and if the minimum value is met
		while (!std::cin.good() || iInput < minVal)
		{
			//If invalid, ignores the stream and tries again
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number greater than " << maxVal << "\n";
			std::cin >> iInput;
		}
	}
	else
	{
		//Maximum value is active. Checks to see if the input is valid, and that it is between the minimum and maximum values allowed
		while (!std::cin.good() || iInput < minVal || iInput > maxVal)
		{
			//If invalid, ignores the stream and tries again
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number between " << minVal << " and " << maxVal << "\n";
			std::cin >> iInput;
		}
	}
	return iInput;
}


//Checks to see if the user wants to proceed or quit
void proceedCheck(gameState GSgame)
{
	char userInput;

	std::cout << "\nProceed? Y/N\n";
	std::cin >> userInput;

	std::system("clear");

	while (userInput != 'y' && userInput != 'Y')
	{
		if (userInput == 'n' || userInput == 'N')
		{
			std::cout << "\nWould you like to quit the game?\nY/N?\n";
			std::cin >> userInput;
			std::system("clear");

			if (userInput == 'y' || userInput == 'Y')
			{
				std::cout << "\nThank you for playing Dachshund Trail! Enter any key to quit\n";
				std::cin >> userInput;
				exit(EXIT_SUCCESS);
			}
			else {
				std::cout << "\nYou have opted to continue playing.\n";
			}
		}

		std::cout << "\nProceed? Y/N\n";
		std::cin >> userInput;

		std::system("clear");

	}
}




//Game over screen. Forces places to exit the game
void gameOver(gameState GSgame)
{
	std::system("clear");
	std::cout << "Oh no! You're out of pack members! GAME OVER!\n";
	std::cout << "Thank you for playing DACHSHUND TRAIL. You will now quit the game...\n";
	proceedCheck(GSgame);
	exit(EXIT_SUCCESS);

}

//The main loop of the game
void idleMenu(gameState GSgame)
{
	packStatus(GSgame);
	//Menu level
	int menu = 1;

	//Checks to make sure the pack is still alive
	while (menu > 0 && GSgame.playerPack.size() > 0)
	{
		//Menu choice value
		int menuInput;
		std::system("clear");

		packCheck(GSgame);

		packStatus(GSgame);
		std::cout << "What would you like to do next?\n";
		std::cout << "(1) Check party\n(2) Eat\n(3) Rest \n(4) Play\n(5) Continue on journey\n";

		std::cin >> menuInput;

		//Check party
		if (menuInput == 1)
		{
			menu = 2;
			while (menu == 2)
			{
				//Choice of party member to inspect

				std::system("clear");
				std::cout << "Which party member would you like to inspect?\n";
				for (size_t i = 0; i < GSgame.playerPack.size(); i++)
				{
					std::cout << "(" << i << ") " << GSgame.playerPack[i].strName << "\n";
				}
				std::cout << "(" << GSgame.playerPack.size() << ") Exit\n\n";

				int inspectMember = getIntInput(0, GSgame.playerPack.size());

				//The player has selected a valid party member
				if (inspectMember < GSgame.playerPack.size())
				{
					//Spits out party information
					std::system("clear");
					std::cout << "Name:\t\t" << GSgame.playerPack[inspectMember].strName << "\n";
					std::cout << "Strength:\t" << GSgame.playerPack[inspectMember].strength << "\n";
					std::cout << "Agility:\t" << GSgame.playerPack[inspectMember].agility << "\n";
					std::cout << "Wits:\t\t" << GSgame.playerPack[inspectMember].wits << "\n";
					std::cout << "Pride:\t\t" << GSgame.playerPack[inspectMember].hp << "\t(Strength + Agility)\n";
					std::cout << "Attack:\t\t" << GSgame.playerPack[inspectMember].attack << "\t(Strength + Wits)\n";
					std::cout << "Defense:\t" << GSgame.playerPack[inspectMember].defense << "\t(Agility + Wits)\n";
					std::cout << "Fullness:\t" << GSgame.playerPack[inspectMember].hunger << "/" << GSgame.playerPack[inspectMember].maxHunger << "\t(Max = 10 + Strength)\n";
					std::cout << "Stamina:\t" << GSgame.playerPack[inspectMember].stamina << "/" << GSgame.playerPack[inspectMember].maxStamina << "\t(Max = 10 + Agility)\n";
					std::cout << "Focus:\t\t" << GSgame.playerPack[inspectMember].focus << "/" << GSgame.playerPack[inspectMember].maxFocus << "\t(Max = 10 + Wits)\n";
					proceedCheck(GSgame);
				}

				//The player has selected the last option of the menu, to exit
				if (inspectMember == GSgame.playerPack.size())
				{
					//Sets the menu back to level 1
					menu = 1;
				}

			}
		}
		//Eat
		if (menuInput == 2)
		{

			std::system("clear");
			//Runs through each of the pack members in order
			for (int p = 0; p < GSgame.playerPack.size(); p++)
			{
				//Checks if they're hungry
				if (GSgame.playerPack[p].hunger < GSgame.playerPack[p].maxHunger)
				{
					//Checks if there is enough food available
					if (GSgame.nFood > 0)
					{
						GSgame.nFood--;
						GSgame.playerPack[p].focus--;
						GSgame.playerPack[p].hunger = GSgame.playerPack[p].maxHunger;
						std::cout << GSgame.playerPack[p].strName << " has eaten one unit of food.\n";
					}
					//Out of food
					else {
						std::cout << "There is not enough food left, so " << GSgame.playerPack[p].strName << " has gone hungry.\n";
					}
				}
				//They're not hungry
				else {
					std::cout << GSgame.playerPack[p].strName << " is unbelievably not hungry.\n";
				}
			}
			proceedCheck(GSgame);
			//Sets the menu back to the main menu
			menu = 1;
		}
		//Rest
		if (menuInput == 3)
		{
			std::system("clear");
			//Runs through the pack members, replenishing stamina, but also making them hungrier and less focused
			for (int p = 0; p < GSgame.playerPack.size(); p++)
			{
				std::cout << GSgame.playerPack[p].strName << " has rested for a while. They are getting hungrier, and slightly more bored...\n";
				GSgame.playerPack[p].stamina = GSgame.playerPack[p].maxStamina;
				GSgame.playerPack[p].hunger--;
				GSgame.playerPack[p].focus--;
			}
			proceedCheck(GSgame);
			//Sets the menu back to the main menu
			menu = 1;

		}
		//Play
		if (menuInput == 4)
		{
			std::system("clear");
			//Checks if there are any tennis balls left
			if (GSgame.nBalls > 0)
			{
				//Runs through the pack, restoring focus, but expending stamina and hunger
				for (int p = 0; p < GSgame.playerPack.size(); p++)
				{
					std::cout << GSgame.playerPack[p].strName << " has played with a Tennis Ball. They are getting hungrier, and more tired...\n";
					GSgame.playerPack[p].focus = GSgame.playerPack[p].maxFocus;
					GSgame.playerPack[p].hunger--;
					GSgame.playerPack[p].stamina--;
				}
				std::cout << "\nThe tennis ball has been lost to the toy gods...\n";
				GSgame.nBalls--;
				proceedCheck(GSgame);
			}
			//No balls left
			else {
				std::cout << "The party has no Tennis Balls to play with.\n";
				proceedCheck(GSgame);
			}
			//Sets the menu back to the main menu
			menu = 1;
		}
		//Combat (Test version)
		if (menuInput == 5)
		{
			std::system("clear");

			std::vector<packMember> vEnemyPack;

			int nEncounterSize = 2;
			for (int e = 0; e < nEncounterSize; e++)
			{
				//Pulls out a random dog name from the dog names vector
				std::string enemyName = con::vDogNames[nRandom(0, con::vDogNames.size() - 1)];
				charClass enemyClass("Chonk", 4, 1, 1);
				packMember enemyMember(enemyName, enemyClass, e);

				vEnemyPack.push_back(enemyMember);
			}
			for (size_t p = 0; p < vEnemyPack.size(); p++)
			{
				std::cout << "Name: " << vEnemyPack[p].strName << "\n";
			}

			//Find combat order

			std::vector<packMember> vPackOrdered = GSgame.playerPack;

			//sortAgility(GSgame.playerPack);

			sortByProperty(GSgame.playerPack, &packMember::agility,false);

			packStatus(GSgame);

			sortByProperty(GSgame.playerPack, &packMember::orderRank, true);

			//Create new packs for combat

			//Let players choose creatures to attack until they're all dead


			proceedCheck(GSgame);

		}


	}
	gameOver(GSgame);
}



void barter(gameState &GSgame, std::string strItem, int* nPrice, int* nQty)
{

	packStatus(GSgame);

	int nBarterSkill = GSgame.playerPack[0].wits;
	std::string leaderName = GSgame.playerPack[0].strName;
	int nNewPrice = *nPrice - nBarterSkill;

	if (nNewPrice < 1)
	{
		nNewPrice = 1;
	}

	std::cout << "\n" << strItem << " cost " << *nPrice << " units each, but " << leaderName << " has bartered it down to " << nNewPrice << "\n";

	std::cout << "You have " << GSgame.nTrash << " units of trash to barter with.\n";
	std::cout << "How many do you want to purchase?\n";


	int nInput = getIntInput(0, (GSgame.nTrash / nNewPrice));

	std::system("clear");

	int nCost = nInput * nNewPrice;

	while (nCost <= GSgame.nTrash)
	{

		if (nCost <= GSgame.nTrash)
		{
			packStatus(GSgame);
			GSgame.nTrash -= nCost;
			std::cout << "\nYou have purchased " << nInput << " " << strItem << " for " << nCost << " units of trash.\nYou now have " << GSgame.nTrash << " trash left.\n";
			*nQty += nInput;
			break;
		}
		else {
			std::cout << "\nYou cannot afford that quantity";
			std::cin >> nInput;
			std::system("clear");
			int nCost = nInput * nNewPrice;
		}
	}

	proceedCheck(GSgame);
}


void combatEncounter(std::string strEnemy, int nPosseSize, int nStrength)
{

}
