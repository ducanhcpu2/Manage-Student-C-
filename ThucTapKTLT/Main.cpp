#include "Menu.h"

void main(){
	ShowCur(false);
	CreateBox();
	Loading();
	int chon;
	vector<SinhVien> sv;
	ReadFile(sv);
	do{
		system("cls");
		Title();
		chon = Menu();
		switch (chon)
		{
		case 1:
			{
				system("cls");
				ThemMoi(sv);				
			}
			break;
		case 2:
			system("cls");
			InDanhSach(sv, 6, 2, 11, true);
			break;
		case 3:
			M3(sv);
			break;
		case 4:
			M4(sv);
			break;
		case 5:
			M5(sv);
			break;
		case 6:
			{
				bool exit = YesOrNo_dialog(75, 1, "Ban co muon thoat khong ?", "Thong bao!!!", 9, 15);
				if(!exit)
					chon = 0;
			}
			break;
		}
		//getch();
	}while(chon<6);
}