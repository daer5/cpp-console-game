#pragma once
#include <iostream>
#include <string>
class GenerateGraphics
{
public:
	GenerateGraphics();
	void printText(std::string the_text, int& whatColour, int sleepTime, bool pauseAfter);
	~GenerateGraphics();
};

