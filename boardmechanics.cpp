#define _CRT_SECURE_NO_WARNINGS
#include "boardmechanics.h"
#include "matrix.h"
#include "conio2.h"
#include <stdlib.h>

void kill(int boardW, int boardH, int** visited, bool* hasKilled, int** dead)
{
	*hasKilled = true;
	for (int i = 0; i < boardW; i++)
	{
		for (int j = 0; j < boardH; j++)
		{
			if (visited[i][j] == 1)
			{
				dead[i][j] = 1;
				visited[i][j] = 0;
			}
		}
	}
}

bool canplace(int x, int y, int boardW, int boardH, int** val, int tura, int** dead)
{
	if (val[x][y] != 0)
		return false;

	int** visited = allocateMatrix(boardH, boardW);
	matrixClear(visited, boardH, boardW);

	val[x][y] = tura;

	bool hasKilled = false;

	if (x < boardW - 1 && val[x + 1][y] == 1 + tura % 2 && !groupAlive(x + 1, y, boardW, boardH, val, visited, 1 + tura % 2))
		kill(boardW, boardH, visited, &hasKilled, dead);

	if (x > 0 && val[x - 1][y] == 1 + tura % 2 && !groupAlive(x - 1, y, boardW, boardH, val, visited, 1 + tura % 2))
		kill(boardW, boardH, visited, &hasKilled, dead);

	if (y < boardH - 1 && val[x][y + 1] == 1 + tura % 2 && !groupAlive(x, y + 1, boardW, boardH, val, visited, 1 + tura % 2))
		kill(boardW, boardH, visited, &hasKilled, dead);

	if (y > 0 && val[x][y - 1] == 1 + tura % 2 && !groupAlive(x, y - 1, boardW, boardH, val, visited, 1 + tura % 2))
		kill(boardW, boardH, visited, &hasKilled, dead);

	bool gA = groupAlive(x, y, boardW, boardH, val, visited, tura);

	deallocateMatrix(visited, boardW);

	val[x][y] = 0;

	if (hasKilled || gA)
		return true;

	return false;
}

bool groupAlive(int x, int y, int boardW, int boardH, int** val, int** visited, int tura)
{
	visited[x][y] = 1;

	if (x < boardW - 1 && val[x + 1][y] == 0)
	{
		matrixClear(visited, boardH, boardW);
		return true;
	}

	if (x > 0 && val[x - 1][y] == 0)
	{
		matrixClear(visited, boardH, boardW);
		return true;
	}

	if (y < boardH - 1 && val[x][y + 1] == 0)
	{
		matrixClear(visited, boardH, boardW);
		return true;
	}

	if (y > 0 && val[x][y - 1] == 0)
	{
		matrixClear(visited, boardH, boardW);
		return true;
	}

	bool r = false;

	if (x < boardW - 1 && val[x + 1][y] == tura && visited[x + 1][y] == 0)
	{
		r = groupAlive(x + 1, y, boardW, boardH, val, visited, tura);
		if (r)
			return r;
	}

	if (x > 0 && val[x - 1][y] == tura && visited[x - 1][y] == 0)
	{
		r = groupAlive(x - 1, y, boardW, boardH, val, visited, tura);
		if (r)
			return r;
	}

	if (y < boardH - 1 && val[x][y + 1] == tura && visited[x][y + 1] == 0)
	{
		r = groupAlive(x, y + 1, boardW, boardH, val, visited, tura);
		if (r)
			return r;
	}

	if (y > 0 && val[x][y - 1] == tura && visited[x][y - 1] == 0)
	{
		r = groupAlive(x, y - 1, boardW, boardH, val, visited, tura);
		if (r)
			return r;
	}

	return false;
}

void boardAction(int* znak, int* x, int* y, int boardX, int boardY, int boardW, int boardH, int** val , int* tura, int** toKill, int backColor, int txtColor, int* wyn1, int* wyn2, int** valBack1, int** valBack2)
{
	*znak = getch();
	if (*znak == 0)
	{
		*znak = getch();
		if (*znak == ArrowUp && *y > boardY) (*y)--;
		else if (*znak == ArrowDown && *y < boardY + boardH - 1) (*y)++;
		else if (*znak == ArrowLeft && *x > boardX) (*x)--;
		else if (*znak == ArrowRight && *x < boardX + boardW - 1) (*x)++;
	}
	else if (*znak == 'i' && canplace(*x - boardX, *y - boardY, boardW, boardH, val, *tura, toKill) && !ko(*x, *y, boardX, boardY, boardW, boardH, val, valBack2, *tura, toKill))
	{
		gotoxy(*x, *y);
		switch (*tura)
		{
		case 1:
			textbackground(0);
			break;
		case 2:
			textbackground(15);
			textcolor(0);
			break;
		}
		putch('?');
		textbackground(backColor);
		textcolor(txtColor);

		while (*znak != Enter && *znak != Esc && *znak != 'q' && *znak != 'n')
		{
			*znak = getch();
			if (*znak == 0)
				*znak = getch();
		}

		if (*znak == Enter)
		{
			val[*x - boardX][*y - boardY] = *tura;
			for (int i = 0; i < boardW; i++)
			{
				for (int j = 0; j < boardH; j++)
				{
					if (toKill[i][j] == 1)
					{
						val[i][j] = 0;
						toKill[i][j] = 0;
						if (*tura == 1)
							(*wyn1)++;
						else
							(*wyn2)++;

					}
				}
			}
			*tura = 1 + *tura % 2;
			passMatrixValues(valBack2, valBack1, boardH, boardW);
			passMatrixValues(valBack1, val , boardH, boardW);
		}
	}
}

bool ko(int x, int y, int boardX, int boardY, int boardW, int boardH, int** val, int** valBack2, int tura, int** toKill)
{
	int** boardWhatIf = allocateMatrix(boardH, boardW);
	passMatrixValues(boardWhatIf, val, boardH, boardW);

	if (canplace(x - boardX, y - boardY, boardW, boardH, boardWhatIf, tura, toKill))
	{
		boardWhatIf[x - boardX][y - boardY] = tura;
		for (int i = 0; i < boardW; i++)
		{
			for (int j = 0; j < boardH; j++)
			{
				if (toKill[i][j] == 1)
				{
					boardWhatIf[i][j] = 0;
				}
			}
		}
	}

	if (compareMatrix(boardWhatIf, valBack2, boardH, boardW))
		return true;
	return false;
}

void handicapAction(int* znak, int* x, int* y, int boardX, int boardY, int boardW, int boardH, int** boardVal, int backColor)
{
	*znak = getch();
	if (*znak == 0)
	{
		*znak = getch();
		if (*znak == ArrowUp && *y > boardY) (*y)--;
		else if (*znak == ArrowDown && *y < boardY + boardH - 1) (*y)++;
		else if (*znak == ArrowLeft && *x > boardX) (*x)--;
		else if (*znak == ArrowRight && *x < boardX + boardW - 1) (*x)++;
	}
	
	else if (*znak == 'i' && boardVal[*x - boardX][*y - boardY] == 0)
	{
		gotoxy(*x, *y);
		textbackground(0);
		putch('?');
		textbackground(backColor);

		while (*znak != Enter && *znak != Esc && *znak != 'q' && *znak != 'n')
		{
			*znak = getch();
			if (*znak == 0)
				*znak = getch();
		}

		if (*znak == Enter)
			boardVal[*x- boardX][*y - boardY] = 1;
	}
}