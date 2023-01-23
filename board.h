#define boardtopleft 218
#define boardbottomleft 192
#define boardleft 195
#define boardtopright 191
#define boardbottomright 217
#define boardright 180
#define boardtopmid 194
#define boardbottommid 193
#define boardmid 197

void cursorpr(int X, int Y, int boardX, int boardY, int** val, int backColor, int boardColor, int txtColor); //print the cursor

void boardpr(int boardX, int boardY, int W, int H, int** val, int backColor, int boardColor); //print the board

void boardpr2(int boardX, int boardY, int W, int H, int backColor, int boardColor); //print a preview of the board