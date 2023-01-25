#ifndef CLASSES_H
#define CLASSES_H
#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "constants.h"
#include "text_functions.h"
#include "menus.h"
#include "graphics.h"



//Sorting function to test whether or not a pack member has higher agility
void sortAgility(std::vector<packMember>& pack);

//Relays information about the pack and its current status to the terminal
void packStatus(gameState game);


//Function that checks to see if any of the members of the pack has dropped off
void packCheck(gameState &game);

void sortByProperty(std::vector<packMember>& pack, int packMember::* member, bool reverse);

#endif
