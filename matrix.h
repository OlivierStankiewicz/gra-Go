int** allocateMatrix(int H, int W); //allocates a matrix with the given dimentions

void matrixClear(int** m, int H, int W); //sets all values in the matrix to 0

void deallocateMatrix(int** m, int W); //deallocates the matrix

void passMatrixValues(int** c, int** m, int H, int W); //sets all values in the first matrix, to those of the second one

bool compareMatrix(int** c, int** m, int H, int W); //compares two matrices of the same size