#include "main.h"



int main()
{
	std::system("clear");

	//introGraphic();

	gameState game;

	std::cout << "\n"
		<< strBold("Welcome to DACHSHUND TRAIL", fgreen) << "\n";

	proceedCheck(game);



	int gameState = 1;

	while (gameState > 0)
	{
		std::system("clear");
		std::cout << "\n"
			<< strBold("You are a group of Dachshunds hoping to brave the Dachshund Trail. The goal is to make it across town for dinner before dark. You will lose members of your party due to hunger, boredom and squirrels.", white) << "\n";

		proceedCheck(game);

		gameState++;

		while (gameState > 1)
		{
			std::string nameInput;

			std::system("clear");

			packStatus(game);

			std::cout << "\nWhat is the name of the leader of your pack? (no spaces allowed)\n";

			std::string leaderName = getStringInput();
			packMember newPack1(leaderName, pickClass(leaderName),0);

			game.playerPack.push_back(newPack1);

			for (int i = 0; i < con::nFollowers; i++)
			{
				std::system("clear");
				packStatus(game);
				std::cout << "\nWhat is the name of the next member of your pack? (no spaces allowed)\n";

				std::string followerName = getStringInput();
				packMember newFollower(followerName, pickClass(followerName),i+1);

				game.playerPack.push_back(newFollower);
			}

			std::system("clear");

			packStatus(game);

			std::cout << "\nYour dachshunds must prepare for their journey. " << game.playerPack[0].strName << " must barter with a racoon selling fresh garbage from a nearby dumpster.\n";

			//racoonGraphic();

			proceedCheck(game);

			packStatus(game);

			std::cout << "\nThis is the price of goods:\nTennis Balls - " << game.nBallPrice << "u\nMunchies - " << game.nFoodPrice << "u\nChew Toy Shivs - " << game.nShivsPrice << "u\n";

			proceedCheck(game);

			barter(game,"Tennis Balls", &game.nBallPrice, &game.nBalls);

			barter(game,"Food ", &game.nFoodPrice, &game.nFood);

			barter(game,"Chew Toy Shivs", &game.nShivsPrice, &game.nShivs);

			std::system("clear");

			std::cout << "\nYou set off on your journey home...\n";

			proceedCheck(game);

			while (game.playerPack.size() > 0 && game.nDistance > 0)
			{

				idleMenu(game);



			}

		}


	}

	return 0;
}