#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include "GenerateGraphics.h"
void userInput();
void gameLogic();
#define Black 0
#define Blue 1
#define Green 2
#define Cyan 3
#define Red 4
#define Magenta 5
#define Yellow 6
#define White 7
#define Gray 8
#define LightBlue 9
#define LightGreen 10
#define LightCyan 11
#define LightRed 12
#define LightMagenta 13
#define LightYellow 14
#define BrightWhite 15
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
int x = 8;
int y = 1;
bool control_array[6];
char gameMap[20][106] = {
	"#########################################################################################################",
	"#      |-                                                                                               #",
	"#      |                                                                                                #",
	"#      |                                                                                                #",
	"#      |                                                                                                #",
	"#      |                                                                                                #",
	"#                                                                                                       #",
	"#                                                                                                       #",
	"#                                                                                                       #",
	"#                                                                                                       #",
	"#                                                                                                       #",
	"#                                                                                                       #",
	"#                                                                                                       #",
	"#                                                                                                       #",
	"#                                                                                                       #",
	"#                                                                                                       #",
	"#                                                                                                       #",
	"#                                                                                                       #",
	"#                                                                                                       #",
	"#########################################################################################################",
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

	std::string sayAtGameStart = "Good luck!";
	//GenerateGraphics TextObj;
	//TextObj.printText(sayAtGameStart, RED, 90, 10000);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //changing colour back
	SetConsoleTextAttribute(hConsole, 11);
	while (inGame) {
		system("cls");																
		

		userInput();																//check for controls - will change array value accordingly
		gameLogic();																//check for array value for key input - will draw character accordingly
		for (int printGameMap = 0; printGameMap < 20; printGameMap++) {				//prints mapp array each frame.
			std::cout << gameMap[printGameMap] << std::endl;
		}
		system("pause>nul");														//pause and wait for everything - you're moma accordingly 
	}
}

void gameLogic() {
	if (control_array[2] == true) {                     //if user presses up
		int y2 = y - 1;
		if (gameMap[y2][x] == ' ') {			//if the square above is blank,
			gameMap[y][x] = ' ';				//make the current square blank,
			y--;								//change original y value to the value up one
			gameMap[y][x] = '^';				//and make the new value occupied by -

			std::cout << "up" << std::endl;
		}
		else {
			std::cout << "border" << std::endl;
		}
	}
	if (control_array[3] == true) {						//if user presses down
		int y2 = y + 1;
		if (gameMap[y2][x] == ' ') {
			gameMap[y][x] = ' ';
			y++;
			gameMap[y][x] = 'v';

			std::cout << "down" << std::endl;
		}
		else {
			std::cout << "border" << std::endl;
		}
	}
	if (control_array[0]) {
		int x2 = x + 1;
		if (gameMap[y][x2] == ' ') {
			gameMap[y][x] = ' ';
			x++;
			gameMap[y][x] = '>';

			std::cout << "right" << std::endl;	
		}
		else {
			std::cout << "border" << std::endl;
		}

	}
	if (control_array[1]) {
		int x2 = x - 1;
		if (gameMap[y][x2] == ' ') {
			gameMap[y][x] = ' ';
			x--;
			gameMap[y][x2] = '<';

			std::cout << "left" << std::endl;
		}
		else {
			std::cout << "border" << std::endl;
		}

	}
	if (control_array[5]) {
		int y1 = y - 1;
		int y2 = y - 2;
		if (gameMap[y1][x] && gameMap[y2][x] == ' ') {

		}
		std::cout << "jump" << std::endl;
	}
}
void userInput() {
	for (int makeKeyStateFalse = 0; makeKeyStateFalse < 6; makeKeyStateFalse++) {
		control_array[makeKeyStateFalse] = false;
	}

	if (GetAsyncKeyState('W') != 0) {			//w UP

		control_array[2] = true;
	
	}
	if (GetAsyncKeyState('S') != 0) {			//s DOWN
	
		control_array[3] = true;
	
	}
	if (GetAsyncKeyState('D') != 0) {			//d RIGHT

		control_array[0] = true;

	}
	if (GetAsyncKeyState('A') != 0) {			//a LEFT

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
	if (GetAsyncKeyState(VK_SPACE) != 0) {
		
		control_array[5] = true;
	
	}
	//system("pause>nul");
}



int main()
{	//set window name
	SetConsoleTitle(TEXT("daerware (the game)"));

	//1. call intro function through GenerateGraphics class
	//GenerateGraphics startObj;
	//startObj.printText(daerwareText, CYAN, 5, 500);
	//2. when passed condition of intro function, call render game
	renderGame();
	//while (inMenu) { //reminder: inMenu is false right now
	//
	//}

	
}
