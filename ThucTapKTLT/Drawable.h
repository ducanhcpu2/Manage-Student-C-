#include "Support.h"

void Border_layout(short x, short y, int height, int width, WORD color);
void Loading();
void CreateBox();
void Table(short x, short y, int row, WORD color);
bool YesOrNo_dialog(short x, short y, char message[100], char title[100], WORD currentColor, WORD newColor);
void Button(short x, short y, char text[100], WORD color);
void Title();
void Report_table(short x, short y, int row, WORD color);
int Edit_dialog(short x, short y, char message[100], char title[100], WORD currentColor, WORD newColor);
int Input_form(int x, int y, int chose);
void Border_form(int x, int y, int height, int length, WORD color);

