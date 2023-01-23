#define _CRT_SECURE_NO_WARNINGS
#include "menumechanics.h"
#include "boardmechanics.h"
#include "conio2.h"

void sizechoice(int* znak, int* choiceX, int* choiceY, int menuX, int menuY, int* boardW, int* boardH, int txtColor, int backColor)
{
	*znak = getch();
	if (*znak == 0) {
		*znak = getch();
		if (*znak == ArrowUp && *choiceY > menuY + 3)
			(*choiceY)--;
		else if (*znak == ArrowDown && *choiceY < menuY + 6)
			(*choiceY)++;
	}

	else if (*znak == Enter)
	{
		
		if (*choiceY == menuY + 3)
		{
			*boardW = 9;
			*boardH = 9;
		}
		else if (*choiceY == menuY + 4)
		{
			*boardW = 13;
			*boardH = 13;
		}
		else if (*choiceY == menuY + 5)
		{
			*boardW = 19;
			*boardH = 19;
		}
		else if (*choiceY == menuY + 6)
		{
			gotoxy(menuX, menuY + 7);
			cputs("height: ");
			gotoxy(menuX, menuY + 8);
			cputs("width: ");
			gotoxy(menuX, menuY + 6);
			clreol();
			cputs("custom");

			sizeinput(znak, choiceX, choiceY, menuX, boardH, txtColor, backColor);
			if (*znak != 'q')
				sizeinput(znak, choiceX, choiceY, menuX, boardW, txtColor, backColor);
		}
	}
}

void sizeinput(int* znak, int* choiceX, int* choiceY, int menuX, int* dimention, int txtColor, int backColor)
{
	(*choiceY)++;
	*choiceX = menuX + 7;
	gotoxy(*choiceX, *choiceY);
	textbackground(15);
	textcolor(0);
	cputs(" ");
	gotoxy(*choiceX, *choiceY);

	int rozmiar = 0;
	*znak = '_';
	bool done = false;
	while (*znak != 'q' && !done)
	{
		*znak = getch();
		if (*znak > '0' && *znak <= '9')
		{
			rozmiar = *znak - '0';
			putch(*znak);
			break;
		}
	}
	while (*znak != 'q' && *znak != Enter && !done)
	{
		*znak = getch();
		if (*znak >= '0' && *znak <= '9')
		{
			rozmiar *= 10;
			rozmiar += *znak - '0';
			putch(*znak);
			done = true;
			break;
		}
	}

	*dimention = rozmiar;

	while (*znak != 'q' && *znak != Enter)
	{
		*znak = getch();
	}
	textcolor(txtColor);
	textbackground(backColor);
}