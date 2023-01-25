#ifndef TEXT_FUNCTIONS_H
#define TEXT_FUNCTIONS_H

#pragma once

#include "constants.h"
#include <string>


//Function that 
std::string strBold(std::string strInput, strColor color);


//Adds a number of spaces to a string. This is mostly used for formatting text
std::string spaces(int numberOfSpaces);

//Similar to the spaces function, this function adds a number of spaces based on the size of the input
std::string altTab(size_t tabStr);

#endif