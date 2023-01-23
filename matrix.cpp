#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"
#include <stdlib.h>

int** allocateMatrix(int H, int W)
{
	int** m = (int**)malloc(W * sizeof(int*));
	for (int i = 0; i < W; i++)
		m[i] = (int*)malloc(H * sizeof(int));

	return m;
}

void matrixClear(int** m, int H, int W)
{
	for (int i = 0; i < W; i++)
		for (int j = 0; j < H; j++)
			m[i][j] = 0;
}

void deallocateMatrix(int** m, int W)
{
	for (int i = 0; i < W; i++)
		free(m[i]);
	free(m);
}

void passMatrixValues(int** c, int** m, int H, int W)
{
	for (int i = 0; i < W; i++)
		for (int j = 0; j < H; j++)
			c[i][j] = m[i][j];
}

bool compareMatrix(int** c, int** m, int H, int W)
{
	for (int i = 0; i < W; i++)
		for (int j = 0; j < H; j++)
			if (m[i][j] != c[i][j])
				return false;
	return true;
}