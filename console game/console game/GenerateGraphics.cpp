#include "pch.h"
#include "GenerateGraphics.h"

#include <iostream>
#include <string>
#include <Windows.h>
char daerwareIntro[7][55] = {
	"      _                                               ",
	"     | |                                              ",
	"   __| |  __ _   ___  _ __ __      __ __ _  _ __  ___ ",
	"  / _` | / _` | / _ \\| '__|\\ \\ /\\ / // _` || '__|/ _ \\",
	" | (_| || (_| ||  __/| |    \\ V  V /| (_| || |  |  __/",
	"  \\__,_| \\__,_| \\___||_|     \\_/\\_/  \\__,_||_|   \\___|",
	"                                                      "
};

//cant be bothered to find a better way to type that ¯\_(-_-)_/¯
GenerateGraphics::GenerateGraphics()
{
	
}

void GenerateGraphics::printText(std::string the_text, int& whatColour, int sleepTime, bool pauseAfter){
	int x = 0; 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, whatColour);
	while (the_text[x] != '\0')
	{
		std::cout << the_text[x];
		Sleep(sleepTime);
		x++;
	};
	while (pauseAfter) {
		//userInput();
		system("pause>nul");
	}
	std::cout << "\n" << std::endl;
}



GenerateGraphics::~GenerateGraphics()
{
}
