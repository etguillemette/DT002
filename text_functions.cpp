#include "text_functions.h"



//Function that adds color coding to terminal text
std::string strBold(std::string strInput, strColor color)
{
	//Switches the string code based on the input enum option
	std::string strColor;
	switch (color)
	{
	case black:
		strColor = "30";
		break;

	case red:
		strColor = "31";
		break;

	case green:
		strColor = "32";
		break;

	case yellow:
		strColor = "33";
		break;

	case blue:
		strColor = "34";
		break;

	case magenta:
		strColor = "35";
		break;

	case cyan:
		strColor = "36";
		break;

	case white:
		strColor = "37";
		break;

	case gray:
		strColor = "90";
		break;

	case fblack:
		strColor = "40";
		break;

	case fred:
		strColor = "41";
		break;

	case fgreen:
		strColor = "42";
		break;

	case fyellow:
		strColor = "43";
		break;

	case fblue:
		strColor = "44";
		break;

	case fmagenta:
		strColor = "45";
		break;

	case fcyan:
		strColor = "46";
		break;

	case fwhite:
		strColor = "47";
		break;
	case fgray:
		strColor = "100";
		break;
	}
	//Exports a string with the extra bits at the front and back to color it
	return "\033[1;" + strColor + "m" + strInput + "\033[0m";
}



//Adds a number of spaces to a string. This is mostly used for formatting text
std::string spaces(int numberOfSpaces)
{
	std::string strExport = "";
	for (int i = 0; i < numberOfSpaces; i++)
	{
		strExport = strExport + " ";
	}
	return strExport;
}

//Similar to the spaces function, this function adds a number of spaces based on the size of the input
std::string altTab(size_t tabStr)
{
	size_t toTab = con::nameMaxCharSize - tabStr;
	std::string strExport = "";
	for (size_t i = 0; i < toTab; i++)
	{
		strExport = strExport + " ";
	}
	return strExport;
}