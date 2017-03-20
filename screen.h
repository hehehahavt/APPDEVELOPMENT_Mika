//include function prototype for screen manipulation
enum COLOR{BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTO, CYAN, WHITE};
#define UNICODE
#define BAR "\u2590" 	//unicode for a bar 

//function prototype 
void setFGcoloR(int fq);
void resetColors(void);
void gotoXY(int row, int col);
void clearscreen(void);
void displayBar(double rms, int col);
