#define _CRT_SECURE_NO_WARNINGS
#include "menus.h"
#include "conio2.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void menupr(int x, int y, int cursorX, int cursorY, int boardX, int boardY, int w1, int w2)
{
	char t[32];

	clrscr();

	gotoxy(x, y);
	cputs("Olivier Stankiewicz");

	gotoxy(x, y + 2);
	cputs("(Normal mode)");

	gotoxy(x, y + 4);
	cputs("arrows  =  move");

	gotoxy(x, y + 5);
	cputs("i       =  place a stone");

	gotoxy(x, y + 6);
	cputs("enter   =  confirm selection");

	gotoxy(x, y + 7);
	cputs("esc     =  cancel selection");

	gotoxy(x, y + 8);
	cputs("n       =  new game");

	gotoxy(x, y + 9);
	cputs("q       =  exit game");

	gotoxy(x, y + 11);
	sprintf(t, "cursor pos : %i, %i", cursorX - boardX, cursorY - boardY);
	cputs(t);

	gotoxy(x, y + 13);
	sprintf(t, "player 1 score: %i", w1);
	cputs(t);

	gotoxy(x, y + 14);
	sprintf(t, "player 2 score: %i", w2);
	cputs(t);
}

void sizemenupr(int x, int y, int cursorY, int boardX, int boardY, int backColor, int boardColor, int txtColor)
{
	clrscr();

	gotoxy(x, y);
	cputs("Olivier Stankiewicz");

	gotoxy(x, y + 2);
	cputs("Choose the board size");

	gotoxy(x, y + 3);
	if (cursorY == y + 3)
	{
		textbackground(15);
		textcolor(0);
		cputs("9x9");
		textcolor(txtColor);
		textbackground(backColor);
		boardpr2(boardX, boardY, 9, 9, backColor, boardColor);
	}
	else
		cputs("9x9");

	gotoxy(x, y + 4);
	if (cursorY == y + 4)
	{
		textbackground(15);
		textcolor(0);
		cputs("13x13");
		textcolor(txtColor);
		textbackground(backColor);
		boardpr2(boardX, boardY, 13, 13, backColor, boardColor);
	}
	else
		cputs("13x13");

	gotoxy(x, y + 5);
	if (cursorY == y + 5)
	{
		textbackground(15);
		textcolor(0);
		cputs("19x19");
		textcolor(txtColor);
		textbackground(backColor);
		boardpr2(boardX, boardY, 19, 19, backColor, boardColor);
	}
	else
		cputs("19x19");

	gotoxy(x, y + 6);
	if (cursorY == y + 6)
	{
		textbackground(15);
		textcolor(0);
		cputs("custom");
		textcolor(txtColor);
		textbackground(backColor);
	}
	else
		cputs("custom");

	gotoxy(x, y + 9);
	cputs("arrows  =  move");

	gotoxy(x, y + 10);
	cputs("enter   =  confirm selection");

	gotoxy(x, y + 11);
	cputs("q       =  exit game");
}

void handicapmenupr(int x, int y, int cursorX, int cursorY, int boardX, int boardY)
{
	char t[32];

	clrscr();

	gotoxy(x, y);
	cputs("Olivier Stankiewicz");

	gotoxy(x, y + 2);
	cputs("(Handicap mode)");

	gotoxy(x, y + 4);
	cputs("arrows  =  move");

	gotoxy(x, y + 5);
	cputs("i       =  place a stone");

	gotoxy(x, y + 6);
	cputs("enter   =  confirm selection");

	gotoxy(x, y + 7);
	cputs("esc     =  cancel selection");

	gotoxy(x, y + 8);
	cputs("e       =  exit handicap mode");

	gotoxy(x, y + 9);
	cputs("n       =  new game");

	gotoxy(x, y + 10);
	cputs("q       =  exit game");

	gotoxy(x, y + 12);
	sprintf(t, "cursor pos : %i, %i", cursorX - boardX, cursorY - boardY);
	cputs(t);
}