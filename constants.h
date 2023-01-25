#ifndef CONSTANTS_H
#define CONSTANTS_H
#pragma once

#include <vector>
#include <string>

namespace con {
	//Magic number that sets the maximum character size for names
	static int nameMaxCharSize = 12;

	//The number of additional members of the pack, beyond the leader
	static int nFollowers = 3;

	//Length of the journey. This is a static variable
	static int nJourney = 1000;


	//List of random dog names
	static std::vector<std::string> vDogNames = {
		"Spot",
		"Fido",
		"Cheesemonger",
		"Monster",
		"Tiny",
		"Bulky",
		"Blacky",
		"Midnight",
		"Shadow",
		"Gonzo",
		"Odin",
		"Loki",
		"Sherlock",
		"Luigi",
		"Winnie",
		"Cooper",
		"Milo",
		"Daisy",
		"Sadie",
		"Lola",
		"Duke",
		"Rocky",
		"Lily"
	};
}


//Enum class for the different color codes needed for colorful terminal text
enum strColor
{
	//Background black
	black = 30,
	//Background red
	red = 31,
	//Background green
	green = 32,
	//Background yellow
	yellow = 33,
	//Background blue
	blue = 34,
	//Background magenta
	magenta = 35,
	//Background cyan
	cyan = 36,
	//Background white
	white = 37,
	//Background gray
	gray = 90,
	//Foreground black
	fblack = 40,
	//Foreground red
	fred = 41,
	//Foreground green
	fgreen = 42,
	//Foreground yellow
	fyellow = 43,
	//Foreground blue
	fblue = 44,
	//Foreground magenta
	fmagenta = 45,
	//Foreground cyan
	fcyan = 46,
	//Foreground white
	fwhite = 47,
	//Foreground gray
	fgray = 100
};





//Class for handling a pack member's base stats
class charClass
{
public:
	std::string strClass;
	int strength;
	int agility;
	int wits;

	//Constructor for a new class
	charClass(std::string className, int str, int agi, int wit)
	{
		strClass = className;
		strength = str;
		agility = agi;
		wits = wit;
	}

};


charClass pickClass(std::string charName);


//Class for pack members
class packMember {
public:
	//Name of the character
	std::string strName;
	//Name of the class
	std::string strClass;
	//Main stat: For strength checks, and contributes to attack and HP
	int strength;
	//Main stat: For dexterity checks, and contributes to defense and HP
	int agility;
	//Main stat: For intelligence checks, and contributes to attack and defense
	int wits;
	//Derived stat: When health falls below zero, they faint. Derived from strength + agility
	int hp;
	//Derived stat: Adds to percentage that an attack will be successful. Derived from strength + wits
	int attack;
	//Derived stat: Adds to percentage that an opponent's attack will miss. Derived from agility + wits
	int defense;
	//Stat max: Maximum possible level of hunger (fullness)
	int maxHunger;
	//Stat max: Maximum possible level of focus
	int maxFocus;
	//Stat max: Maximum possible level of Stamina
	int maxStamina;
	//Status stat: Current level of hunger. If it drops below zero, they give up
	int hunger;
	//Status stat: Current level of focus. If it drops below zero, they lose interest in the mission
	int focus;
	//Status stat: Current level of stamina. If it drops below zero, they get too tired
	int stamina;
	//Current rank in the pack
	int orderRank;

	//Function that creates a new pack member
	packMember(std::string name, charClass classPicked,int rank) {
		std::system("clear");

		//Grabs the stats from the charClass picked

		strClass = classPicked.strClass;
		strength = classPicked.strength;
		agility = classPicked.agility;
		wits = classPicked.wits;

		orderRank = rank;

		strName = name;
		hp = strength + agility;
		attack = strength + wits;
		defense = wits + agility;
		hunger = 10 + strength;
		focus = 10 + wits;
		stamina = 10 + agility;
		maxHunger = 10 + strength;
		maxFocus = 10 + wits;
		maxStamina = 10 + agility;
	}
};


class gameState {
public:
	//The price for tennis balls. This is a global variable because I'm being lazy.
	int nBallPrice = 10;
	//The price for food. This is a global variable because I'm being lazy.
	int nFoodPrice = 6;
	//The price for chew toy shivs. This is a global variable because I'm being lazy.
	int nShivsPrice = 5;

	//Number of tennis balls the party has at the moment
	int nBalls = 0;
	//Number of food the party has at the moment
	int nFood = 0;
	//Number of weapons (chew toy shivs) the party has at the moment
	int nShivs = 0;
	//Amount of trash (currency) the party has at the moment
	int nTrash = 100;

	//The current distance the party has until reaching its destination home
	int nDistance = con::nJourney;

	//Player Pack
	std::vector<packMember> playerPack;
};

#endif



