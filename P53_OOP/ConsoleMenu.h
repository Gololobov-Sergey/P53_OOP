#pragma once
#include <windows.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "Settings.h"


using std::cout;
using std::endl;


namespace ConsoleMenu
{
	enum HorizontalAlignment
	{
		Center, Left, Right
	};

	enum class KEY
	{
		RIGHT = 77, LEFT = 75, UP = 72, DOWN = 80, ESC = 27, ENTER = 13
	};

	enum ConsoleColor
	{
		Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
		LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
	};

	void setColor(int text, int background);

	void setCursorPosition(int x, int y);

	void frame(int width, int height, int xPos, int yPos);

	class Menu
	{
		static int textColor;
		static int backColor;
		static int widthConsole;
		static int heightConsole;
		static HANDLE hStdOut;
		static CONSOLE_CURSOR_INFO structCursorInfo;

		static void init();

		static int formatItems(std::vector<std::string>& menuItems)
		{
			size_t maxLengthItem = 0;
			for (size_t i = 0; i < menuItems.size(); i++)
			{
				menuItems[i] = " " + menuItems[i] + " ";
				if (menuItems[i].length() > maxLengthItem)
					maxLengthItem = menuItems[i].length();
			}
			return maxLengthItem;
		}


	public:

		static void consoleSettings()
		{
			init();

			std::vector<std::string> menuItems = { "Розмір екрану", "Колір тексту", "Колір фону" };

			int maxLengthItem = formatItems(menuItems);

			KEY key;
			int x = (widthConsole - maxLengthItem) / 2;
			int y = (heightConsole - menuItems.size()) / 2;
			int selectedItem = 0;

			int posArrowTextColor = textColor;
			int posArrowBackColor = backColor;

			do
			{
				system("cls");

				frame(maxLengthItem + 10, menuItems.size() + 4, x - 5, y - 2);
				for (int i = 0; i < menuItems.size(); i++)
				{
					if (i == selectedItem)
					{
						setColor(backColor, textColor);
						setCursorPosition(x, y + i);
						cout << std::setw(maxLengthItem) << std::left;
						setCursorPosition(x, y + i);
						cout << menuItems[i] << endl;
						setColor(textColor, backColor);
					}
					else
					{
						setColor(textColor, backColor);
						setCursorPosition(x, y + i);
						cout << std::setw(maxLengthItem) << std::left;
						setCursorPosition(x, y + i);
						cout << menuItems[i] << endl;
						setColor(backColor, textColor);
					}
				}
				switch (selectedItem)
				{
				case 0:
					setColor(backColor, backColor);
					frame(52, 4, widthConsole / 2 - 26, y + 5);
					break;
				case 1:
					textColor = posArrowTextColor;
					setColor(textColor, backColor);
					frame(52, 4, widthConsole / 2 - 26, y + 5);
					setCursorPosition(widthConsole / 2 - 26 + 2, y + 5 + 1);
					for (size_t i = 0; i < 16; i++)
					{
						setColor(textColor, i);
						cout << "   ";
					}
					break;
				case 2:
					backColor = posArrowBackColor;
					setColor(textColor, backColor);
					frame(52, 4, widthConsole / 2 - 26, y + 5);
					setCursorPosition(widthConsole / 2 - 26 + 2, y + 5 + 1);
					for (size_t i = 0; i < 16; i++)
					{
						setColor(textColor, i);
						cout << "   ";
					}
					break;
				}
				setColor(textColor, backColor);
				int color = (selectedItem == 1) ? posArrowTextColor : posArrowBackColor;
				setCursorPosition(widthConsole / 2 - 26 + 2 + color * 3, y + 5 + 2);
				if (selectedItem != 0)
					cout << " ^ ";
				key = (KEY)_getch();
				switch (key)
				{
				case KEY::UP:   if (selectedItem > 0)                   selectedItem--; break;
				case KEY::DOWN: if (selectedItem < menuItems.size() - 1) selectedItem++; break;
				case KEY::RIGHT:
					if (posArrowTextColor < 15 && selectedItem == 1)
						posArrowTextColor++;
					if (posArrowBackColor < 15 && selectedItem == 2)
						posArrowBackColor++;
					break;
				case KEY::LEFT:
					if (posArrowTextColor > 0 && selectedItem == 1)
						posArrowTextColor--;
					if (posArrowBackColor > 0 && selectedItem == 2)
						posArrowBackColor--;
					break;
				case KEY::ENTER: break;
				}
				textColor = posArrowTextColor;
				backColor = posArrowBackColor;
				setColor(textColor, backColor);
			} while (key != KEY::ENTER);

			//Settings::widthConsole = 110;
			//Settings::heightConsole = 30;
			Settings::textColorConsole = textColor;
			Settings::backColorConsole = backColor;

			setColor(textColor, backColor);
			system("cls");
		}

		static int verticalMenu(std::string menuName, std::vector<std::string> menuItems, HorizontalAlignment ha, int y = 12)
		{
			init();

			int selectedItem = (menuItems.size() > 0)? 0 : -1;
			KEY key;
			int maxLengthItem = formatItems(menuItems);
		
			int x = 0;
			switch (ha)
			{
			case Center: x = (widthConsole - maxLengthItem) / 2; break;
			case Left:   x = 0;	              break;
			case Right:  x = widthConsole - maxLengthItem;     break;
			}

			//frame(maxLengthItem + 10, menuItems.size() + 4, x - 5, y - 2);

			do
			{
				setColor(backColor, textColor);
				setCursorPosition((widthConsole - menuName.length()) / 2, y - 2);
				std::cout << menuName;
				setColor(textColor, backColor);

				for (int i = 0; i < menuItems.size(); i++)
				{
					if (i == selectedItem)
					{
						setColor(backColor, textColor);
						setCursorPosition(x, y + i);
						cout << std::setw(maxLengthItem) << std::left;
						setCursorPosition(x, y + i);
						cout << menuItems[i] << endl;
						setColor(textColor, backColor);
					}
					else
					{
						setColor(textColor, backColor);
						setCursorPosition(x, y + i);
						cout << std::setw(maxLengthItem) << std::left;
						setCursorPosition(x, y + i);
						cout << menuItems[i] << endl;
						setColor(backColor, textColor);
					}
				}
				key = (KEY)_getch();
				switch (key)
				{
				case KEY::UP: if (selectedItem > 0)                      selectedItem--; break;
				case KEY::DOWN: if (selectedItem < menuItems.size() - 1) selectedItem++; break;
				case KEY::ESC: selectedItem = -1; break;
				case KEY::ENTER: break;
				}
			} while (key != KEY::ENTER && key != KEY::ESC);

			if (selectedItem != -1)
			{
				for (size_t i = 0; i < 2; i++)
				{
					setColor(textColor, backColor);
					setCursorPosition(x, y + selectedItem);
					cout << std::setw(maxLengthItem) << std::left;
					setCursorPosition(x, y + selectedItem);
					cout << menuItems[selectedItem] << endl;
					Sleep(200);
					setColor(backColor, textColor);
					setCursorPosition(x, y + selectedItem);
					cout << std::setw(maxLengthItem) << std::left;
					setCursorPosition(x, y + selectedItem);
					cout << menuItems[selectedItem] << endl;
					setColor(textColor, backColor);
					Sleep(200);
				}
			}
			setColor(textColor, backColor);
			structCursorInfo.bVisible = TRUE;
			SetConsoleCursorInfo(hStdOut, &structCursorInfo);
			system("cls");
			
			return selectedItem;
		}
	};
}