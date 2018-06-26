#include "Support.h"

void nhapMaLop(char *maLop, int x, int y){
	int dem = strlen(maLop);
	gotoxy(x+dem+2, y);
	char ch;
Nhap:
	while((ch=getch())!=13){
		if( (ch == 8)  ){
			if(dem>0){
				cout << "\b \b";
				dem--;
			}else
				cout << "\a";
		}else if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>= '0' && ch<= '9')){
			if(ch >='a' && ch <= 'z')
				ch -= 32;
			cout << ch;
			maLop[dem] = ch;
			dem++;
		}
	}
	if(dem == 0 || dem >6 )
		goto Nhap;
	maLop[dem]='\0';
}

void nhapMaSV(char *maSV, int x, int y){
	//cout << strlen(maSV);
	int dem = strlen(maSV);
	gotoxy(x+dem+2, y);
	char ch;
Nhap:
	while((ch=getch())!=13){
		if(ch == 8){
			if(dem>0){
				cout << "\b \b";
				dem--;
			}else
				cout << "\a";
		}else if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>= '0' && ch<= '9')){
			if(ch >='a' && ch <= 'z')
				ch -= 32;
			cout << ch;
			maSV[dem] = ch;
			dem++;
		}
	}
	if(dem == 0  )
		goto Nhap;
	maSV[dem]='\0';
}

void ChuanHoaTen(char *HoTen, int x, int y){
	char ch;
	int dem=strlen(HoTen);
	gotoxy(x+dem+2, y);
/*
Nhap:
	while((ch=getch())!=13){
		if((dem == 0 || HoTen[dem-1]==' ' ) && ch >='a' && ch <= 'z'){
			ch = ch - 32;
			cout << ch;
			HoTen[dem]=ch;
			dem++;
		}else if(HoTen[dem-1]!=' ' && ch>='A' && ch<='Z' && dem!=0){
			ch = ch + 32;
			cout << ch;
			HoTen[dem]=ch;
			dem++;
		}else if((dem == 0 || HoTen[dem-1]==' ') && ch==' '){
			cout << ch;
			cout <<"\a";
			cout << "\b \b";
		}else if(ch == 8){
			if(dem>0){
				cout << "\b \b";
				dem--;
			}else{
				cout <<"\a";
			}
		}else{
			cout << ch;
			HoTen[dem] = ch;
			dem++;
		}

	}
	HoTen[dem]='\0';
	if(strlen(HoTen)==0)
		goto Nhap;
	*/
Nhap:
	while ( (ch = getch()) != 13) {
		if (ch == 8 && dem > 0) {
			cout << "\b \b";
			dem--;
		}
		if ( (dem == 0 || HoTen[dem-1] == ' ' ) && ch == ' ') {
			cout << "\a";
			//cout << "\b \b";
		}
		else 
		{
			if (ch >= 'a' && ch <= 'z') {
				ch -= 32;
				HoTen[dem] = ch;
				cout << ch;
				dem++;
			}
			if (ch == ' ' && HoTen[dem - 1] != ' ') {
				cout << ' ';
				HoTen[dem] = ' ';
				dem++;
			}

		}
	}
	//if (HoTen[dem] == ' ') cout << "\b \b";
	HoTen[dem] = '\0';
	if (strlen(HoTen) == 0 )
		goto Nhap;

}

void ChuanHoaNgay(char *date, int x, int y){
	char temp;
	int dem=strlen(date);
	gotoxy(x+dem+2, y);
Nhap:
	while(((temp=getch())!=13)){
		if(dem > 9 && temp!=8){
			cout << "\a";
			continue;
		}
		if((temp >='0' && temp<='9') || temp ==' ' || temp =='-' || temp == '/' || temp == 8){
			if(temp ==' ' || temp =='-' || temp == '/'){
				if((date[dem-2]==' ' || date[dem-2]=='-' || date[dem-2] == '/') || dem==1){
					if(dem < 6){
						cout << "\b \b";
						cout << "0"<<date[dem-1]<<"/";
						date[dem]=date[dem-1];
						date[dem-1]='0';
						date[dem+1]='/';
						dem += 2;
					}else{
						cout << "\a";
					}
				}else if((dem==0 || date[dem-1] == '/')){
					cout << "\a";
				}
			}else if(temp >='0' && temp<='9'){
				if((dem==1 || date[dem-2]=='/') && dem<6){
					cout << temp<<"/";
					date[dem] = temp;
					date[dem+1]='/';
					dem += 2;
				}else{
					cout << temp;
					date[dem] = temp;
					dem++;
				}
			}else if(temp == 8){
				if(dem>0){
					cout << "\b \b";
					dem--;
				}else
					cout << "\a";
			}
		}else{
			cout << "\a";
		}
	}
	if(dem!=10)
		goto Nhap;
	date[dem]='\0';
}

void ChuanHoaDiem(float &diem, int x, int y){
	char mark[6];
	char temp;
	int dem = 0;
	gotoxy(x+dem+2, y);
Nhap:
	while((temp=getch()) != 13){
		if(dem > 4 && temp!=8){
			cout << "\a";
			continue;
		}
		if((temp>='0' && temp<='9') || temp == '.' || temp == 8){
			if(temp>='0' && temp<='9'){
				if(dem!=2){
					if(dem==1 && mark[dem-1]=='1'){
						cout << "0";
						mark[dem] = '0';
						dem++;
					}else if((mark[0]=='1' && dem>2 && temp!='0') || (dem = 1 && mark[dem-1]>='2')){
						cout << "\a";
					}else{
						cout << temp;
						mark[dem]=temp;
						dem++;
					}
				}else
					cout << "\a";
			}else if(temp == '.'){
				if(dem==1){
					if(mark[dem-1]=='0'){
						cout << "\b \b";
						cout << " 0.";
					}else{
						cout << "\b \b";
						cout << "0"<<mark[dem-1]<<".";
					}
					mark[dem] = mark[dem-1];
					mark[dem-1] = '0';
					mark[dem+1] = '.';
					dem += 2;
				}else if(dem == 2){
					cout << temp;
					mark[dem] = temp;
					dem ++;
				}else if(dem==0){
					cout << " 0.";
					mark[0] = '0';
					mark[1] = '0';
					mark[2] = temp;
					dem = 3;
				}else
					cout << "\a";
			}else{
				if(dem>0){
					cout << "\b \b";
					dem--;
				}else
					cout << "\a";
			}
		}else
			cout << "\a";
	}
	if(strlen(mark)==0)
		goto Nhap;
	mark[dem] = '\0';
	diem = atof(mark);
}

bool CheckDate(char date[11]){
	char dTemp[11];
	char *p, *pt[5];
	int birth[3], i=0;
	strcpy(dTemp, date);
	p = strtok(dTemp, "/");
	while(p!=NULL){
		pt[i] = p;
		birth[i] = atoi(pt[i]);
		p = strtok(NULL, "/");
		i++;
	}
	bool check = false;
	if(birth[1] == 1 ||  birth[1] == 3 || birth[1] == 5 || birth[1] == 7 || birth[1] == 8 || birth[1] == 10 || birth[1] == 12){
		if(birth[0] < 32)
			check = true;
	}else if(birth[1] == 2){
		if(birth[2] % 400 == 0 || (birth[2] % 4 == 0 && birth[2] % 100 !=0)){
			if(birth[0]<30)
				check = true;
		}else
			if(birth[0] < 29)
				check = true;
	}else if(birth[1] == 4 || birth[1] == 6 || birth[1] == 9 || birth[1] == 11){
		if(birth[0]<31)
			check = true;
	}
	return check;
}
