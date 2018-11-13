#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

enum keyboardControls {
	LEFT,
	RIGHT,
	DOWN,
	UP,
	ENTER
};
bool inMenu = false; //false until i make menu
bool inGame = true;
bool playerAlive = true;
char dotDotDot[3][4] = {
	".  ",
	".. ",
	"..."
};
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

void renderGame() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);							//remember to change it back
	for (int printDots = 3; printDots < 3; printDots++) {
		std::cout << "Press any key to begin" << dotDotDot << std::endl;

	}
    system("cls");
	for (int printGameMap = 0; printGameMap < 20; printGameMap++) {
		std::cout << gameMap[printGameMap] << std::endl;
	}
	system("pause>nul");
	
}

void userInput() {
	bool control_array[5]{
		RIGHT,
		LEFT,
		UP,
		DOWN,
		ENTER
	};

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
	while (inMenu) { //note: inMenu is false right now

	}
	while (inGame) {
		renderGame();
	}
}
