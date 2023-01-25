#ifndef MENUS_H
#define MENUS_H

#include <string>
#include <iostream>
#include "constants.h"
#include "group.h"
#include "math_functions.h"

#pragma once

//Function that handles string inputs that need to be of a certain size
std::string getStringInput();

//Function that handles receiving user input, and verrifies that it's an int before proceeding
int getIntInput(int minVal, int maxVal);

//Checks to see if the user wants to proceed or quit
void proceedCheck(gameState GSgame);

//Game over screen. Forces places to exit the game
void gameOver(gameState GSgame);

//The main loop of the game
void idleMenu(gameState GSgame);

//Barters for a particular item based on price and quantity available
void barter(gameState &GSgame, std::string strItem, int* nPrice, int* nQty);

//Combat encounter
void combatEncounter(std::string strEnemy, int nPosseSize, int nStrength);

#endif
