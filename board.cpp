#define _CRT_SECURE_NO_WARNINGS
#include "board.h"
#include "conio2.h"

void cursorpr(int X, int Y, int boardX, int boardY, int** val, int backColor, int boardColor, int txtColor)
{
	textbackground(boardColor);
	gotoxy(X, Y);
	switch (val[X - boardX][Y - boardY])
	{
	case 1:
		textbackground(0);
		break;
	case 2:
		textbackground(15);
		textcolor(0);
		break;
	}
	putch('*');
	textbackground(backColor);
	textcolor(txtColor);
}

void boardpr(int boardX, int boardY, int W, int H, int** val, int backcolor, int boardcolor)
{
	textbackground(boardcolor);
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			gotoxy(boardX + i, boardY + j);
			switch (val[i][j])
			{
			case 0:
				if (i == 0)
				{
					if (j == 0)
						putch(boardtopleft);
					else if (j == H - 1)
						putch(boardbottomleft);
					else
						putch(boardleft);
				}
				else if (i == W - 1)
				{
					if (j == 0)
						putch(boardtopright);
					else if (j == H - 1)
						putch(boardbottomright);
					else
						putch(boardright);
				}
				else
				{
					if (j == 0)
						putch(boardtopmid);
					else if (j == H - 1)
						putch(boardbottommid);
					else
						putch(boardmid);
				}
				break;

			case 1:
				textbackground(0);
				putch(' ');
				textbackground(boardcolor);
				break;

			case 2:
				textbackground(15);
				putch(' ');
				textbackground(boardcolor);
			}

		}
	}

	for (int i = -1; i <= W; i++)
	{
		for (int j = -1; j <= H; j++)
		{
			if (i == W || i == -1 || j == H || j == -1)
			{
				gotoxy(boardX + i, boardY + j);
				putch(' ');
			}
		}
	}

	textbackground(backcolor);
}

void boardpr2(int boardX, int boardY, int W, int H, int backcolor, int boardcolor)
{
	textbackground(boardcolor);
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			gotoxy(boardX + i, boardY + j);
			if (i == 0)
			{
				if (j == 0)
					putch(boardtopleft);
				else if (j == H - 1)
					putch(boardbottomleft);
				else
					putch(boardleft);
			}
			else if (i == W - 1)
			{
				if (j == 0)
					putch(boardtopright);
				else if (j == H - 1)
					putch(boardbottomright);
				else
					putch(boardright);
			}
			else
			{
				if (j == 0)
					putch(boardtopmid);
				else if (j == H - 1)
					putch(boardbottommid);
				else
					putch(boardmid);
			}
		}
	}

	for (int i = -1; i <= W; i++)
	{
		for (int j = -1; j <= H; j++)
		{
			if (i == W || i == -1 || j == H || j == -1)
			{
				gotoxy(boardX + i, boardY + j);
				putch(' ');
			}
		}
	}
	textbackground(backcolor);
}