#include "Function.h"
//#include "Drawable.h"

int Select_menu(int x, int y, int index, int rowCount, vector<string> lisMenu, WORD currentColor, WORD newColor){
	char key;
	char keyNo = '1';
	int line = index + (y+1);
	do{
		gotoxy(x+2, line); textcolor(newColor); cout << "=>>";
		gotoxy(x+6, line); cout << lisMenu[line-(y+1)];
		textcolor(currentColor);
		do{
			key = getch();
			if(key==224) key=getch();// Ký tự đặc biệt tổ hợp phím mũi tên
			if(key!=13){
				gotoxy(x+2, line); cout << "    " << lisMenu[line-(y+1)];
			}
			if(key==72){ // Mui ten len
				if(line == index+(y+1))
					line = line+rowCount-1;
				else
					line -= 1;

			}else if(key == 80){ // Mui ten xuong
				if(line == index+rowCount+y)
					line -= (rowCount-1);
				else
					line += 1;
			}
			else if(key>=keyNo && key<(keyNo+rowCount))
				line = key-48+index+y;
			else if(key==27)
				line = rowCount+y+index;

		}while(key!=13 && key!=224 && key!=27 && key!=72 && key!=80 && !(key>=keyNo && key<(key+rowCount)));

	}while(key!=13 && key!=27);

	return line-index-y;
}

int LengthMaxOfElement(vector<string> lisMenu){
	int max = 0;
	for(int i=0; i<lisMenu.size(); i++){
		if(lisMenu[i].size() > max) max = lisMenu[i].size();
	}
	return max;
}

int Menu(){
	//CreateBox();
	ShowCur(false);
	int x=45;
	int y=1;
	vector<string> lisMenu;
	lisMenu.push_back("1. Them moi ho so");
	lisMenu.push_back("2. In danh sach");
	lisMenu.push_back("3. Sap xep");
	lisMenu.push_back("4. Tim kiem");
	lisMenu.push_back("5. Thong ke");
	lisMenu.push_back("6. Thoat");
	int width = LengthMaxOfElement(lisMenu);
	Border_layout(x, y, 3, width+9, 12);
	gotoxy(x+2, y+1); cout << "MENU CHUONG TRINH CHINH";
	Border_layout(x, y+2, lisMenu.size()+2, width+9, 12);
	for(int i=0; i<lisMenu.size(); i++){
		gotoxy(x+2, (y+3)+i);
		cout << "    "<<lisMenu[i]<< endl;
	}
	gotoxy(x, y+2); cout << char(204);
	gotoxy(x+width+9, y+2); cout << char(185);
	int opt = Select_menu(x, y+2, 0, 6, lisMenu, 12, 10);
	return opt;
}

int Menu_M3(){
	int x=45;
	int y=1;
	vector<string> lisMenu;
	lisMenu.push_back("Ban chon thuat toan sap xep: ");
	lisMenu.push_back("1> Selection Sort");
	lisMenu.push_back("2> Insert Sort");
	lisMenu.push_back("3> Bubble Sort");
	lisMenu.push_back("4> Quick Sort");
	lisMenu.push_back("5> quay lai !");

	int width = LengthMaxOfElement(lisMenu);
	Border_layout(x, y, 3, width+6, 12);
	gotoxy(x+5, y+1); cout << "CAC THUAT TOAN SAP XEP";
	Border_layout(x, y+2, lisMenu.size()+2, width+6, 12);
	for(int i=0; i<lisMenu.size(); i++){
		gotoxy(x+2, (y+3)+i);
		cout << "    "<<lisMenu[i]<< endl;
	}
	gotoxy(x, y+2); cout << char(204);
	gotoxy(x+width+6, y+2); cout << char(185);
	int opt = Select_menu(x, y+2, 1, 5, lisMenu, 12, 14);

	return opt;
}

int Menu_item_M3(){
	int x=45;
	int y=1;
	vector<string> lisMenu;
	lisMenu.push_back("Moi ban chon khoa sap xep: ");
	lisMenu.push_back("1. Ma sinh vien");
	lisMenu.push_back("2. Ho va ten");
	lisMenu.push_back("3. Ngay sinh");
	lisMenu.push_back("4. Diem TB");
	lisMenu.push_back("5. Tro ve menu truoc");

	int width = LengthMaxOfElement(lisMenu);
	Border_layout(x, y, 3, width+6, 11);
	gotoxy(x+5, y+1); cout << "DANH MUC TU KHOA SAP XEP";
	Border_layout(x, y+2, lisMenu.size()+2, width+6, 11);
	for(int i=0; i<lisMenu.size(); i++){
		gotoxy(x+2, (y+3)+i);
		cout << "    "<<lisMenu[i]<< endl;
	}
	gotoxy(x, y+2); cout << char(204);
	gotoxy(x+width+6, y+2); cout << char(185);
	int opt = Select_menu(x, y+2, 1, 5, lisMenu, 11, 9);
	return opt;
}

int Menu_M4(){
	int x=45;
	int y=1;
	vector<string> lisMenu;
	lisMenu.push_back("Ban chon thuat toan tim kiem: ");
	lisMenu.push_back("1. Tim kiem tuan tu");
	lisMenu.push_back("2. Tim kiem nhi phan");
	lisMenu.push_back("3. Tro ve menu chinh");

	int width = LengthMaxOfElement(lisMenu);
	Border_layout(x, y, 3, width+6, 13);
	gotoxy(x+5, y+1); cout << "MENU TIM KIEM";
	Border_layout(x, y+2, lisMenu.size()+2, width+6, 13);
	for(int i=0; i<lisMenu.size(); i++){
		gotoxy(x+2, (y+3)+i);
		cout << "    "<<lisMenu[i]<< endl;
	}
	gotoxy(x, y+2); cout << char(204);
	gotoxy(x+width+6, y+2); cout << char(185);
	int opt = Select_menu(x, y+2, 1, 3, lisMenu, 13, 12);
	return opt;
}

int Menu_item_M4(){
	int x=45;
	int y=1;
	vector<string> lisMenu;
	lisMenu.push_back("Ban chon khoa can tim kiem: ");
	lisMenu.push_back("1. Ma sinh vien");
	lisMenu.push_back("2. Ho va ten");
	lisMenu.push_back("3. Ngay sinh");
	lisMenu.push_back("4. Diem TB");
	lisMenu.push_back("5. Ma lop");
	lisMenu.push_back("6. Tro ve menu truoc");

	int width = LengthMaxOfElement(lisMenu);
	Border_layout(x, y, 3, width+6, 10);
	gotoxy(x+5, y+1); cout << "DANH MUC TU KHOA TIM KIEM";
	Border_layout(x, y+2, lisMenu.size()+2, width+6, 10);
	for(int i=0; i<lisMenu.size(); i++){
		gotoxy(x+2, (y+3)+i);
		cout << "    "<<lisMenu[i]<< endl;
	}
	gotoxy(x, y+2); cout << char(204);
	gotoxy(x+width+6, y+2); cout << char(185);
	int opt = Select_menu(x, y+2, 1, 6, lisMenu, 10, 13);
	return opt;
}

int Menu_M5(){
	int x=45;
	int y=1;
	vector<string> lisMenu;
	lisMenu.push_back("Ban chon bao cao: ");
	lisMenu.push_back("1. So luong sinh vien theo lop");
	lisMenu.push_back("2. Ty le phan loai ket qua hoc tap");
	lisMenu.push_back("3. Tro ve menu chinh");

	int width = LengthMaxOfElement(lisMenu);
	Border_layout(x, y, 3, width+7, 11);
	gotoxy(x+5, y+1); cout << "MENU BAO CAO";
	Border_layout(x, y+2, lisMenu.size()+2, width+7, 11);
	for(int i=0; i<lisMenu.size(); i++){
		gotoxy(x+2, (y+3)+i);
		cout << "    "<<lisMenu[i]<< endl;
	}
	gotoxy(x, y+2); cout << char(204);
	gotoxy(x+width+7, y+2); cout << char(185);
	int opt = Select_menu(x, y+2, 1, 3, lisMenu, 11, 14);
	return opt;
}

void M3(vector<SinhVien> sv){

	int chon;
	int iOpt=0;
	do
	{
		system("cls");
		Title();
		chon = Menu_M3();
		if(chon < 5){
			do{
				system("cls");
				Title();
				iOpt = Menu_item_M3();
				gotoxy(6, 10);
				if(iOpt < 5){
					switch (chon)
					{
					case 1:
						Selection_sort(sv, iOpt);
						break;
					case 2:
						Insertion_sort(sv, iOpt);
						break;
					case 3:
						Bubble_sort(sv, iOpt);
						break;
					case 4:
						{
							vector<SinhVien> svp(sv);
							Quick_sort(svp, 0, svp.size()-1, iOpt);
							InDanhSach(svp, 6, 12, 11, true);
						}
						break;
					}
				}
			}while(iOpt < 5);
		}
	} while (chon<5);
}

void M4(vector<SinhVien> sv){
	int chon, Opt;
	do{
		system("cls");
		Title();
		chon = Menu_M4();
		if(chon<3){
			do{
				system("cls");
				Title();
				Opt = Menu_item_M4();
				Border_layout(24, 13, 3, 25, 11);
				gotoxy(6, 13);
				if(Opt<6){
					switch (chon)
					{
					case 1:
						{
							Linear_search(sv, Opt);
						}
						break;
					case 2:
						{
							Quick_sort(sv, 0, sv.size()-1, Opt);
							vector<SinhVien> result, svp(sv);
							char cKey[50];
							cout << "\n Nhap noi dung can tim: ";
							gotoxy(26, 14);
							fflush(stdin);
							gets_s(cKey);
							int i;
							while(Binary_search(svp, 0, svp.size()-1, Opt, cKey)>=0){
								i=Binary_search(svp, 0, svp.size()-1, Opt, cKey);
								result.push_back(svp[i]);
								svp.erase(svp.begin()+i);
							}
							if(result.empty()){
								cout << "\n\t\t\t------Khong tim thay ket qua!!!------\n";
								getch();
							}else{
								InDanhSach(result, 6, 16, 11, false);
								getch();
							}
						}
						break;
					}
				}
			}while(Opt < 6);
		}
	}while(chon<3);
	
}

void M5(vector<SinhVien> sv){

	int chon;
	do{
		system("cls");
		Title();
		chon = Menu_M5();
		gotoxy(3, 10);
		switch(chon){
		case 1:
			{
				BaoCao_SinhVien(sv);
				break;
			}
		case 2:
			{
				BaoCao_PhanLoai(sv);
				break;
			}
		}
	}while(chon<3);
}

