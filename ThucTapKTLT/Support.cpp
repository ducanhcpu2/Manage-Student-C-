#include "Support.h"

void gotoxy(short x, short y) 
{ 
	HANDLE hConsoleOutput; 
	COORD Cursor_an_Pos = {x , y}; 
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos); 
}

void textcolor(WORD color) 
{ 
	HANDLE hConsoleOutput; 
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info; 
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info); 

	WORD wAttributes = screen_buffer_info.wAttributes; 
	color &= 0x000f; 
	wAttributes &= 0xfff0; 
	wAttributes |= color; 

	SetConsoleTextAttribute(hConsoleOutput, wAttributes); 
}

void SetBGColor(WORD color) 
{ 
	HANDLE hConsoleOutput; 
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info; 
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info); 

	WORD wAttributes = screen_buffer_info.wAttributes; 
	color &= 0x000f; 
	color <<= 4; 
	wAttributes &= 0xff0f; 
	wAttributes |= color; 

	SetConsoleTextAttribute(hConsoleOutput, wAttributes); 
}

void setColor(int maunen, int mauchu)
{
	SetBGColor(maunen);
	textcolor(mauchu);
}

int wherex()
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

				// Vị trí y của con trỏ chuột
int wherey()
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}

void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}