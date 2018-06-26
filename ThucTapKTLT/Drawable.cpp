#include "Drawable.h"

void Border_layout(short x, short y, int height, int width, WORD color){
	height -= 1;
	textcolor(color);
	gotoxy(x, y); cout << char(201);
	gotoxy(x+width, y); cout << char(187);
	gotoxy(x, y+height); cout << char(200);
	gotoxy(x+width, y+height); cout << char(188);
	for(int i=0; i<=height; i++){
		if(i>0 && i<height){
			gotoxy(x, y+i); cout << char(186);
			gotoxy(x+width, y+i); cout << char(186);
		}else{
			for(int j=1; j<width; j++){
				textcolor(color);
				gotoxy(x+j, y); cout << char(205);
				gotoxy(x+j, y+height); cout << char(205);
			}
		}
	}
}

void CreateBox()
{

	textcolor(3);
	//bien trai
	gotoxy(0, 2);
	printf("%c", 201);
	for (int i = 0; i < 26; i++) {
		gotoxy(0, i);
		printf("%c", 186);
		Sleep(2);
	}
	//bien duoi
	gotoxy(0, 25);
	printf("%c", 200);

	for (int i = 0; i < 80; i++) {
		gotoxy(i, 25);
		printf("%c", 205);
		Sleep(2);
	}

	//bien phai
	gotoxy(80, 25);
	printf("%c", 188);
	for (int i = 24; i > 0; i--) {
		gotoxy(80, i);
		printf("%c", 186);
		Sleep(2);
	}

	//bien tren
	gotoxy(80, 0);
	printf("%c", 187);
	for (int i = 79; i > 0; i--) {
		gotoxy(i, 0);
		printf("%c", 205);
		Sleep(2);
	}
}

void Loading(){
	textcolor(2);
	gotoxy(33,7); cout << " =>> WAITING... <<= ";
	/*Border_layout(14, 1, 3, 52, 10);

	for( int i = 0 ; i <= 50 ; i++ ){
		textcolor(3);
		gotoxy(15 + i,2);cout << char(219)<<" ";
		textcolor(15);
		gotoxy(45,4);cout << i*2 << "%";
		Sleep(20);
	}
	
	textcolor(10);
	gotoxy(14 + 52, 2); cout << char(186);
	*/	
	textcolor(14);
	gotoxy(35,4);cout << "HOAN TAT";
	textcolor(12);
	gotoxy(25, 6); cout << "Nhan phim bat ki de tiep tuc!!!";
	getch();
	system("cls");
	textcolor(15);
}

void Border_form(int x, int y, int height, int length, WORD color){
	ShowCur(false);
	gotoxy(x, y);
	Border_layout(x, y, 3, length, color);
	Border_layout(x, y+2, height-3, length, color);
	gotoxy(x, y+2); cout << char(204);
	gotoxy(x+length, y+2); cout << char(185); 
}

void Table(short x, short y, int row, WORD color){
	textcolor(color);
	row = row+2;
	int line = row*2;
	for (int i = 0; i <= line; i++)
	{
		gotoxy(x, i+y);
		for (int j = 0; j < 100; j++)
		{
			if(i%2==0){
				if(i==0 || i==2 || i==4 || i==line)
					cout << char(205);
				else
					cout << char(196);
				gotoxy(x+j, i+y);
				switch (i)
				{
				case 0:
					{
						if(j==0)
							cout << char(201);
						else if(j==99)
							cout << char(187);
						break;
					}
				case 2:
					{
						if(j==0)
							cout << char(204);
						else if(j==99)
							cout << char(185);
						else if(j==7 || j==19 || j==41 || j==68 || j==85)
							cout << char(209);
						break;
					}
				case 4:
					{
						if(j==0)
							cout << char(204);
						else if(j==99)
							cout << char(185);
						else if(j==7 || j==19 || j==41 || j==68 || j==85)
							cout << char(216);
						break;
					}
				default:
					{
						if(i!=line){
							if(j==0)
								cout << char(199);
							else if(j==99)
								cout << char(182);
							else if(j==7 || j==19 || j==41 || j==68 || j==85)
								cout << char(197);
						}
						break;
					}
				}
				if(i==line){
					gotoxy(x+j, i+y);
					if(j==0)
						cout << char(200);
					else if(j==99)
						cout << char(188);
					else if(j==7 || j==19 || j==41 || j==68 || j==85)
						cout << char(207);
				}
			}else if(i%2!=0){
				gotoxy(x+j, i+y);
				if(j==0 || j==99)
					cout << char(186);
				else if((j==7 || j==19 || j==41 || j==68 || j==85) && i!=1)
					cout << char(179);
			}
		}
	}
	gotoxy(x+1, y+3); printf("%5s", "STT");
	gotoxy(x+9, y+3); printf("%9s", "MA LOP");
	gotoxy(x+22, y+3); printf("%18s", "MA SINH VIEN");
	gotoxy(x+44, y+3); printf("%23s", "HO VA TEN");
	gotoxy(x+71, y+3); printf("%13s", "NGAY SINH");
	gotoxy(x+86, y+3); printf("%12s", "DIEM TB");
}

void Button(short x, short y, char text[100], WORD color){
	Border_layout(x, y, 3, strlen(text)+3, color);
	gotoxy(x+2, y+1);
	cout << text;
}

bool YesOrNo_dialog(short x, short y, char message[100], char title[100], WORD currentColor, WORD newColor){
	ShowCur(false);
	gotoxy(x, y);
	int strLength = strlen(message)>strlen(title) ? strlen(message):strlen(title);
	int length = strLength > 20 ? strLength+3:20;
	Border_layout(x, y, 3, length, currentColor);
	gotoxy(x+2, y+1);
	cout << title;
	Border_layout(x, y+2, 8, length, currentColor);
	gotoxy(x+2, y+4);
	cout << message;
	int bX = (length-15)/2;
	Button(x+bX, y+6, "Co", currentColor);
	Button(x+bX+8, y+6, "Khong", currentColor);
	gotoxy(x, y+2); cout << char(204);
	gotoxy(x+length, y+2); cout << char(185); 
	char key;
	bool temp = true;
	do {
		if(temp)
			Button(x+bX, y+6, "Co", newColor);
		else
			Button(x+bX+8, y+6, "Khong", newColor);
		do {
			key = getch();
			if(key==224) key=getch();
			if(key==75 || key==77){//mui ten phai
				if(temp){
					Button(x+bX, y+6, "Co", currentColor);
					temp = false;
				}else{
					Button(x+bX+8, y+6, "Khong", currentColor);
					temp = true;
				}
			}
		} while (key != 13 && key!=224 && key!=75 && key!=77);
	} while (key != 13);
	return temp;
}

void Title(){
	SYSTEMTIME time;
	GetLocalTime(&time);
	char thu[][10]={"Chu nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau", "Thu Bay"};
	Border_layout(1, 1, 11, 40, 8);
	textcolor(12); gotoxy(4, 3); cout << "+++ QUAN LY SINH VIEN +++";
	textcolor(11); gotoxy(3, 5); cout << ">> Hoc vien ki thuat quan su (MTA) <<";
	textcolor(9);
	gotoxy(4, 6); cout << "Ho va ten: Nguyen Duc Anh";
	gotoxy(4, 7); cout << "Lop      : MMT15";
	gotoxy(4, 8); cout << "Ma SV    : 16150074";
	gotoxy(4, 9); printf("%s, Ngay %02d thang %02d nam %04d", thu[time.wDayOfWeek], time.wDay, time.wMonth, time.wYear);
}

void Report_table(short x, short y, int row, WORD color){
	gotoxy(x, y);
	textcolor(color);
	char temp;
	for (int i= 0; i < 4; i++)
	{
		for (int j = 0; j <= 70; j++)
		{
			gotoxy(x+j, y+i);
			if(i==0){
				if(j==0)
					cout << char(201);
				else if(j==70)
					cout << char(187);
				else if(j==20)
					cout << char(203);
				else if(j==30 || j==40 || j==50 || j==60)
					cout << char(209);
				else
					cout << char(205);
			}else{
				if(j==0 || j==20 || j==70)
					cout << char(186);
				else if(j==30 || j==40 || j==50 || j==60)
					cout << char(179);
			}
		}
	}
	int line = row*2;
	for (int i = 0; i <= line; i++)
	{
		for (int j = 0; j <= 70; j++)
		{
			gotoxy(x+j, y+4+i);
			if(i%2==0 && i!=line && i!=0){
				if(j==0)
					cout << char(199);
				else if(j==70)
					cout << char(182);
				else if(j==20)
					cout << char(215);
				else if(j==30 || j==40 || j==50 || j==60)
					cout << char(197);
				else
					cout << char(196);
			}
			else if(i==line || i==0){
				if(j==0)
					temp = (i==0) ? char(204):char(200);
				else if(j==70)
					temp = (i==0) ? char(185):char(188);
				else if(j==20)
					temp = (i==0) ? char(206):char(202);
				else if(j==30 || j==40 || j==50 || j==60)
					temp = (i==0) ? char(216):char(207);
				else
					temp = char(205);
				cout << temp;
			}
			else{
				if(j==0 || j==20 || j==70)
					cout << char(186);
				else if(j==30 || j==40 || j==50 || j==60)
					cout << char(179);
			}
		}
	}
	gotoxy(x+8, y+1); cout << "\\";
	gotoxy(x+9, y+2); cout << "\\";
	gotoxy(x+10, y+3); cout << "\\";
	gotoxy(x+2, y+2); cout << "Lop";
	gotoxy(x+11, y+2); cout << "Xep loai";
	char xeploai[][15]={"  Yeu  ", "T. Binh", "  Kha  ", "  Gioi ", " X. Sac"};
	for (int i = 4; i >= 0; i--)
	{
		gotoxy(x+22, y+2);
		cout << xeploai[i];
		x += 10;
	}
}

int Edit_dialog(short x, short y, char message[100], char title[100], WORD currentColor, WORD newColor){
	ShowCur(false);
	gotoxy(x, y);
	int length = strlen(message) > 34 ? strlen(message)+3:34;
	Border_layout(x, y, 3, length, currentColor);
	gotoxy(x+2, y+1);
	cout << title;
	Border_layout(x, y+2, 8, length, currentColor);
	gotoxy(x+2, y+4);
	cout << message;
	int bX = (length-30)/2;
	Button(x+bX, y+6, "Chinh sua", currentColor);
	Button(x+bX+14, y+6, "Xoa", currentColor);
	Button(x+bX+22, y+6, "Thoat", currentColor);
	gotoxy(x, y+2); cout << char(204);
	gotoxy(x+length, y+2); cout << char(185); 
	char key;
	int temp = 0;
	do {
		if(temp==0)
			Button(x+bX, y+6, "Chinh sua", newColor);
		else if(temp==1)
			Button(x+bX+14, y+6, "Xoa", newColor);
		else
			Button(x+bX+22, y+6, "Thoat", newColor);
		do {
			key = getch();
			if(key==224) key=getch();
			if(key==77){
				if(temp==2){
					Button(x+bX+22, y+6, "Thoat", currentColor);
					temp=0;
				}else if(temp==1 || temp==0){
					if(temp==0) Button(x+bX, y+6, "Chinh sua", currentColor);
					else Button(x+bX+14, y+6, "Xoa", currentColor);
					temp++;
				}
			}else if(key==75){
				if(temp==0){
					Button(x+bX, y+6, "Chinh sua", currentColor);
					temp=2;
				}else if(temp==1 || temp==2){
					if(temp==2) Button(x+bX+22, y+6, "Thoat", currentColor);
					else Button(x+bX+14, y+6, "Xoa", currentColor);
					temp--;
				}
			}
		} while (key != 13 && key!=224 && key!=75 && key!=77);
	} while (key != 13);
	return temp;
}

int Input_form(int x, int y, int chose){
	for(int i=y-1; i<y+12; i=i+3){
		Border_layout(x, i, 3, 25, 12);
		textcolor(11);
		ShowCur(false);
	}
	char key;
	int j = chose;
	do 
	{
		Border_layout(x, j , 3, 25, 11);
		do 
		{
			key = getch();
			if(key==224) key=getch();
			if(key!=13) Border_layout(x, j, 3, 25, 12);
			if(key == 72){
				if(j==y-1)
					j = y+11;
				else
					j -= 3;
			}else if(key == 80){
				if(j==y+11)
					j = y-1;
				else
					j += 3;
			}else if(key==27){
				j = -1;
			}else if(key==13){
				Border_layout(x, j , 3, 25, 10);
			}else if(key==' '){
				j = 0;
			}
		} while (key!=13 && key!=224 && key!=27 && key!=72 && key!=80 && key!=' ');
	} while (key!=13 && key!=27 && key!=' ');
	return j+1;
}

