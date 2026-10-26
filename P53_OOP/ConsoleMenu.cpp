#include "ConsoleMenu.h"

int ConsoleMenu::Menu::textColor = 7;
int ConsoleMenu::Menu::backColor = 0;
int ConsoleMenu::Menu::widthConsole = 80;
int ConsoleMenu::Menu::heightConsole = 25;
HANDLE ConsoleMenu::Menu::hStdOut = nullptr;
CONSOLE_CURSOR_INFO ConsoleMenu::Menu::structCursorInfo = CONSOLE_CURSOR_INFO();


void ConsoleMenu::setColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

void ConsoleMenu::setCursorPosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleMenu::frame(int width, int height, int xPos, int yPos)
{
	setCursorPosition(xPos, yPos);
	SetConsoleOutputCP(866);
	cout << (char)201;
	for (int i = 0; i < width - 2; i++)
		cout << (char)205;
	cout << (char)187;

	for (int j = 0; j < height - 2; j++)
	{
		setCursorPosition(xPos, yPos + 1 + j);
		cout << (char)186;
		for (int i = 0; i < width - 2; i++)
			cout << " ";
		cout << (char)186;
	}
	setCursorPosition(xPos, yPos + height - 1);
	cout << (char)200;
	for (int i = 0; i < width - 2; i++)
		cout << (char)205;
	cout << (char)188;
	SetConsoleOutputCP(1251);
}

void ConsoleMenu::Menu::init()
{

	SetConsoleOutputCP(1251);
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hStdOut, &consoleInfo);

	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);

	textColor = consoleInfo.wAttributes & 15;
	backColor = (consoleInfo.wAttributes >>= 4) & 15;

	widthConsole = consoleInfo.dwSize.X;
	heightConsole = consoleInfo.dwSize.Y;
}
