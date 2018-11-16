#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include "GenerateGraphics.h"
void userInput();
void gameLogic();
int BLACK = 0;
int BLUE = 1;
int GREEN = 2;
int CYAN = 3;
int RED = 4;
int MAGENTA = 5;
int BROWN = 6;
int LIGHTGRAY = 7;
int DARKGRAY = 8;
int YELLOW = 14;
int WHITE = 15;
enum keyboardControls {
	LEFT,
	RIGHT,
	DOWN,
	UP,
	ENTER
};
std::string daerwareText = "      _                                               \n     | |                                              \n   __| |  __ _   ___  _ __ __      __ __ _  _ __  ___ \n  / _` | / _` | / _ \\| '__|\\ \\ /\\ / // _` || '__|/ _ \\\n | (_| || (_| ||  __/| |    \\ V  V /| (_| || |  |  __/\n  \\__,_| \\__,_| \\___||_|     \\_/\\_/  \\__,_||_|   \\___|\n                                                      ";
bool inMenu = false; //false until i make menu
bool inGame = true;
bool playerAlive = true;
char dotDotDot[3][4] = {
	".  ",
	".. ",
	"..."
};
/*char daerwareIntro[7][55] = {
	"      _                                               ",
	"     | |                                              ",
	"   __| |  __ _   ___  _ __ __      __ __ _  _ __  ___ ",
	"  / _` | / _` | / _ \| '__|\ \ /\ / // _` || '__|/ _ \\",
	" | (_| || (_| ||  __/| |    \ V  V /| (_| || |  |  __/",
	"  \__,_| \__,_| \___||_|     \_/\_/  \__,_||_|   \___|",
	"                                                      "
};
*/
int x = 1;
int y = 1;
bool control_array[5];
char gameMap[20][41] = {
	"########################################",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"########################################",
};
/*
void waitForUserInput(std::string textStart, std::string textMiddle,std::string textEnd = "continue") {
	bool waiting = true;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);							//remember to change colour back
	while(waiting) {
		for (int printDot = 0; printDot < 3; printDot++) {
			std::cout << textStart << "ress " << textMiddle << " to " << textEnd << dotDotDot[printDot] << std::endl;
			Sleep(500);
			system("cls");
			userInput();
			if (control_array[4]) {
				waiting = false;

			}
		}

	}
}
*/

void renderGame() {
	//waitForUserInput("Good luck, p", "ENTER", "begin"); //might want to move this to the end of the future menu function
	std::string sayAtGameStart = "Good luck! Press ENTER to begin.";
	GenerateGraphics TextObj;
	TextObj.printText(sayAtGameStart, RED, 90, true);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //changing colour back
	SetConsoleTextAttribute(hConsole, 11);
	while (inGame) {
		system("cls");
		for (int printGameMap = 0; printGameMap < 20; printGameMap++) {
			std::cout << gameMap[printGameMap] << std::endl;
		}
		gameLogic();

		system("pause>nul");
	}
}

void gameLogic() {
	userInput();
	if (control_array[2]) {
		int y2 = y - 1;
		if (gameMap[y2][x] == ' ') {
			gameMap[y][x] = ' ';
			y--;
			gameMap[y][x] = '-';
			
			std::cout << "up" << std::endl;
		}
	if (control_array[3]) {
		int y2 = y + 1;
		if (gameMap[y2][x] == ' ') {
			gameMap[y][x] = ' ';
			y += 1;
			gameMap[y][x] = 'v';
			
			std::cout << "down" << std::endl;
		}
	}
	}
}

void userInput() {
	for (int makeKeyStateFalse = 0; makeKeyStateFalse < 5; makeKeyStateFalse++) {
		control_array[makeKeyStateFalse] = false;
	}

	if (GetAsyncKeyState(0x57) != 0) {			//w UP

		control_array[2] = true;
	}
	if (GetAsyncKeyState(0x53) != 0) {			//s DOWN

		control_array[3] = true;
	}
	if (GetAsyncKeyState(0x44) != 0) {			//d RIGHT

		control_array[0] = true;

	}
	if (GetAsyncKeyState(0x41) != 0) {			//a LEFT

		control_array[1] = true;

	}
	if (GetAsyncKeyState(VK_UP) != 0) {			//up

		control_array[2] = true;
	}
	if (GetAsyncKeyState(VK_DOWN) != 0) {		//down

		control_array[3] = true;
	}
	if (GetAsyncKeyState(VK_LEFT) != 0) {		//left

		control_array[1] = true;
	}
	if (GetAsyncKeyState(VK_RIGHT) != 0) {		//right

		control_array[0] = true;
	}
	if (GetAsyncKeyState(VK_RETURN) != 0) {		//enter

		control_array[4] = true;
	}
}



int main()
{
	SetConsoleTitle(TEXT("daerware (the game)"));
	GenerateGraphics startObj;
	startObj.printText(daerwareText, CYAN, 5, false);
	while (inMenu) { //reminder: inMenu is false right now

	}
	renderGame();
	
}
