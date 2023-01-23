#define _CRT_SECURE_NO_WARNINGS
#include "conio2.h"
#include <stdlib.h>
#include "menus.h"
#include "board.h"
#include "boardmechanics.h"
#include "menumechanics.h"
#include "matrix.h"
#define boardX 50
#define boardY 3
#define menuX 5
#define menuY 2
#define txtColor 15
#define backColor 3
#define boardColor 8

int main()
{
	int znak = 0;

	settitle("GO!");
	_setcursortype(_NOCURSOR);
	textbackground(backColor);
	textcolor(txtColor);

	while (znak != 'q') //game loop
	{
		int boardW, boardH, choiceY = menuY + 3, choiceX = menuX, tura = 1, wyn1 = 0, wyn2 = 0, X = boardX, Y = boardY;

		while (znak != Enter && znak != 'q') //size choice loop
		{
			sizemenupr(menuX, menuY, choiceY, boardX, boardY, backColor, boardColor, txtColor);
			sizechoice(&znak, &choiceX, &choiceY, menuX, menuY, &boardW, &boardH, txtColor, backColor);
		}

		//memory allocation
		int** boardVal = allocateMatrix(boardH, boardW);
		matrixClear(boardVal, boardH, boardW);
		int** boardValBack1 = allocateMatrix(boardH, boardW);
		matrixClear(boardValBack1, boardH, boardW);
		int** boardValBack2 = allocateMatrix(boardH, boardW);
		matrixClear(boardValBack2, boardH, boardW);

		while (znak != 'e' && znak != 'n' && znak != 'q') //handicap loop
		{
			handicapmenupr(menuX, menuY, X, Y, boardX, boardY);
			boardpr(boardX, boardY, boardW, boardH, boardVal, backColor, boardColor);
			cursorpr(X, Y, boardX, boardY, boardVal, backColor, boardColor, txtColor);
			handicapAction(&znak, &X, &Y, boardX, boardY, boardW, boardH, boardVal, backColor);
		}
		
		while (znak != 'n' &&  znak!= 'q') //normal mode loop
		{
			int** toKill = allocateMatrix(boardH, boardW);
			matrixClear(toKill, boardH, boardW);

			menupr(menuX, menuY, X, Y, boardX, boardY, wyn1, wyn2);
			boardpr(boardX, boardY, boardW, boardH, boardVal, backColor, boardColor);
			cursorpr(X, Y, boardX, boardY, boardVal, backColor, boardColor, txtColor);
			boardAction(&znak, &X, &Y, boardX, boardY, boardW, boardH, boardVal, &tura, toKill, backColor, txtColor, &wyn1, &wyn2, boardValBack1, boardValBack2);

			deallocateMatrix(toKill, boardW);
		}

		//memory deallocation
		deallocateMatrix(boardVal, boardW);
		deallocateMatrix(boardValBack1, boardW);
		deallocateMatrix(boardValBack2, boardW);
	}
	return 0;
}