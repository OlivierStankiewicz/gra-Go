#define Enter 0x0d
#define ArrowUp 0x48
#define ArrowDown 0x50
#define ArrowLeft 0x4b
#define ArrowRight 0x4d
#define Esc 0x1b

void kill(int boardW, int boardH, int** visited, bool* hasKilled, int** dead); //mark stones that will be captured

bool canplace(int x, int y, int boardW, int boardH, int** val, int tura, int** dead); //check if the stone can be placed in the position of the cursor

bool groupAlive(int x, int y, int boardW, int boardH, int** val, int** visited, int tura); //check if the chain has liberties

void boardAction(int* znak, int* x, int* y, int boardX, int boardY, int boardW, int boardH, int** val, int* tura, int** toKill, int backColor, int txtColor, int* wyn1, int* wyn2, int** valBack1, int** valBack2); //handle the game

bool ko(int x, int y, int boardX, int boardY, int boardW, int boardH, int** val, int** valBack2, int tura, int** toKill); //check if the Ko rule applies

void handicapAction(int* znak, int* x, int* y, int boardX, int boardY, int boardW, int boardH, int** boardVal, int backColor); //handle handicap