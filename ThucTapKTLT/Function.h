#include "Standardized.h"
#include "Drawable.h"

struct SinhVien{
	char MaLop[10];
	char MaSV[10];
	char HoTen[50];
	char NgaySinh[10];
	float DiemTB;
};

void ThemMoi(vector<SinhVien> &sv);
void InDanhSach(vector<SinhVien> &sv, int x, int y, WORD color, bool type);
void ReadFile(vector<SinhVien> &sv);
void WriteFile(SinhVien sv);
void swap(SinhVien &sv1, SinhVien &sv2);
char *DaoNgaySinh(char ngay[20]);
char *DaoTen(char name[50]);
void Selection_sort(vector<SinhVien> sv, int Opt);
void Insertion_sort(vector<SinhVien> sv, int Opt);
void Bubble_sort(vector<SinhVien> sv, int Opt);
void Quick_sort(vector<SinhVien> &sv, int L, int R, int Opt);
void Linear_search(vector<SinhVien> sv, int Opt);
int Binary_search(vector<SinhVien> sv, int L, int R, int Opt, char cKey[50]);
int numClass(vector<SinhVien> sv);
void Xoa(vector<SinhVien> &sv,int index);
void BaoCao_SinhVien(vector<SinhVien> sv);
int Xep_Loai(float diem);
void BaoCao_PhanLoai(vector<SinhVien> sv);
void Chinh_Sua(vector<SinhVien> &sv, int index);

void ThemMoi(vector<SinhVien> &sv){
	textcolor(11);
	//ShowCur(false);
	SinhVien svt;
	svt.MaLop[0] = '\0';
	svt.MaSV[0] = '\0';
	svt.HoTen[0] = '\0';
	svt.NgaySinh[0] = '\0';
	int x, y, chose, count = 0;
	char key;
	bool confirm = true;
	x = 3;
	y = 9;
note:
	do 
	{
		Border_form(x-2, y-7, 24, 85, 13);
		gotoxy(x, y-6); cout << "THEM SINH VIEN VAO DANH SACH!!!";
		gotoxy(x, y-4); printf("Da them %02d vao danh sach!", count);
		textcolor(11);
		chose = y;
		gotoxy(x, y-3); cout << "ESC: Thoat    Enter: Nhap    Dau Cach: Xac nhan";
		gotoxy(x, y   ); cout << "Nhap vao ma lop: ";
		gotoxy(x, y+3 ); cout << "Nhap vao ma sinh vien: ";
		gotoxy(x, y+6 ); cout << "Nhap vao ten sinh vien: ";
		gotoxy(x, y+9 ); cout << "Nhap vao ngay thang nam sinh: ";
		gotoxy(x, y+12); cout << "Nhap diem: ";
		if(!confirm){
			gotoxy(x+33, y); cout << svt.MaLop;
			gotoxy(x+33, y+3); cout << svt.MaSV;
			gotoxy(x+33, y+6); cout << svt.HoTen;
			gotoxy(x+33, y+9); cout << svt.NgaySinh;
			gotoxy(x+33, y+12); cout << svt.DiemTB;
		}

	
		do 
		{
			chose = Input_form(x+31, y, chose-1);
			textcolor(11);
			ShowCur(true);
			//gotoxy(x+31, chose);
			switch (chose)
			{
			case 9:
				{
				nhapMaLop(svt.MaLop, x + 31, chose);
				/*do {
					nhapMaLop(svt.MaLop, x + 31, chose);
					if (strlen(svt.MaLop) > 6) {
						gotoxy(x + 60, chose);
						cout << "ma lop sai ,nhap lai!! ";  // cout << strlen(svt.MaLop);
						getch();
						gotoxy(x + 60, chose);
						cout << "                       ";
						}
				} while (strlen(svt.MaLop) > 6);
				*/
				}
				break;
			case 12:
				{

				nhapMaSV(svt.MaSV, x + 31, chose);

				do {
					nhapMaSV(svt.MaSV, x + 31, chose);
					if (strlen(svt.MaSV) > 8) {
						gotoxy(x + 60, chose);
						cout << "ma sv sai ,nhap lai!! ";
						getch();
						gotoxy(x + 60, chose);
						cout << "                       ";
					}
				} while (strlen(svt.MaSV) > 8);
					
				}
				break;
			case 15:
			{
				do {
					
					ChuanHoaTen(svt.HoTen, x + 31, chose);
					if (strlen(svt.HoTen) > 25) {
						gotoxy(x + 60, chose);
						cout << "ten sai ,nhap lai!! ";
						getch();
						gotoxy(x + 60, chose);
						cout << "                       ";
					}

				} while (strlen(svt.HoTen) > 25);
			}
				break;
			case 18:
				{
					bool checkDate;
					do 
					{
						ChuanHoaNgay(svt.NgaySinh, x+31, chose);
						checkDate = CheckDate(svt.NgaySinh);
						if(!checkDate){
							gotoxy(x+60, chose);	
							cout << "Ngay thang sai!";
							getch();
							gotoxy(x+60, chose);
							cout << "                       ";
						}
					} while (!checkDate);
				}
				break;
			case 21:
				{
					ChuanHoaDiem(svt.DiemTB, x+31, chose);
				}
				break;
			}
		} while (chose!=0 && chose!=1);
		if(chose==1){

			if ((strlen(svt.MaLop) == 0) || (strlen(svt.MaSV) == 0) || (strlen(svt.HoTen) == 0) || (strlen(svt.NgaySinh) == 0))
			{
				//gotoxy(40, 40);
				//cout << " KHONG DUOC DE TRONG !! ";
				goto note;

			}

			confirm = YesOrNo_dialog(x+60, y+2, "Them sinh vien!", "Xac nhan them moi", 11, 12);
			if(confirm){
				
					sv.push_back(svt);
					WriteFile(svt);
					svt.MaLop[0] = '\0';
					svt.MaSV[0] = '\0';
					svt.HoTen[0] = '\0';
					svt.NgaySinh[0] = '\0';
					count++;
					
			}
		}
		system("cls");
	} while (chose!=0);

}

void InDanhSach(vector<SinhVien> &sv, int x, int y, WORD color, bool type){
	// type = true InDanhSachChon || type = false InDanhSachHienThi
	textcolor(color);
	Table(x, y, sv.size(), color);
	gotoxy(x+1, y+1);
	cout << "\t\t\t\t<<---------Danh sach co "<< sv.size() <<" sinh vien--------->>\t\t\t";
	//printf("%5s %10s %20s %25s %20s %15s", "Ma lop", "Ma sinh vien", "Ho va ten", "Ngay sinh", "Diem TB");
	int j, i;
	for (i = 0; i < sv.size(); i++)
	{
		j = i*2+5;
		gotoxy(x+1, y+j); printf("%5.03d", (i+1));
		gotoxy(x+9, y+j); printf("%9s", sv[i].MaLop);
		gotoxy(x+22, y+j); printf("%18s", sv[i].MaSV);
		gotoxy(x+44, y+j); printf("%23s", sv[i].HoTen);
		gotoxy(x+71, y+j); printf("%13s", sv[i].NgaySinh);
		gotoxy(x+86, y+j); printf("%12.2f", sv[i].DiemTB);
	}
	if(type){
		char key;
		i=0;
		do 
		{
			j = i*2+5;
			textcolor(9);
			gotoxy(x+1, y+j); printf("%5.03d", (i+1));
			gotoxy(x+9, y+j); printf("%9s", sv[i].MaLop);
			gotoxy(x+22, y+j); printf("%18s", sv[i].MaSV);
			gotoxy(x+44, y+j); printf("%23s", sv[i].HoTen);
			gotoxy(x+71, y+j); printf("%13s", sv[i].NgaySinh);
			gotoxy(x+86, y+j); printf("%12.2f", sv[i].DiemTB);
			textcolor(11);
			do 
			{
				key = getch();
				if(key==224) key=getch();
				if(key==72 || key==80){
					gotoxy(x+1, y+j); printf("%5.03d", (i+1));
					gotoxy(x+9, y+j); printf("%9s", sv[i].MaLop);
					gotoxy(x+22, y+j); printf("%18s", sv[i].MaSV);
					gotoxy(x+44, y+j); printf("%23s", sv[i].HoTen);
					gotoxy(x+71, y+j); printf("%13s", sv[i].NgaySinh);
					gotoxy(x+86, y+j); printf("%12.2f", sv[i].DiemTB);
				}
				if(key==72){
					if(i==0)
						i=sv.size()-1;
					else
						i--;
				}else if(key==80){
					if(i==sv.size()-1)
						i=0;
					else
						i++;
				}
			} while (key!=27 && key!=13 && key!=224 && key!=72 && key!=80);
		} while (key!=13 && key!=27);
		if(key==13){
			//system("cls");
			gotoxy(x+30, y+2*i);
			for(int p=0; p<10; p++){
				gotoxy(x+30, y+2*i+p);
				for(int q=0; q<35; q++)
					cout << " ";
			}
			char message[100];
			strcpy(message, sv[i].MaSV);
			strcat(message, " - ");
			strcat(message, sv[i].HoTen);
			int chose = Edit_dialog(x+30, y+2*i, message, "Thao tac voi sinh vien: ", 13, 12);

			// TODO
			if(chose == 0){
				// Chinh sua
				system("cls");
				Chinh_Sua(sv, i);
			}else if(chose==1){
				system("cls");
				bool yon = YesOrNo_dialog(x+30, 5, message, "Xac nhan xoa sinh vien:", 13, 12);
				if(yon) Xoa(sv, i);
			}else{
				//Thoat
			}
			system("cls");

			InDanhSach(sv, x, 2, color, type);

		}
	}
}

void ReadFile(vector<SinhVien> &sv){
	SinhVien sve;

	ifstream read("Sinhvien.dat", ios::in | ios::binary);

	while(read.read(reinterpret_cast<char *>(&sve), sizeof(SinhVien))){
		sv.push_back(sve);
	}
	read.close();
}

void WriteFile(SinhVien sv){
	fstream write("Sinhvien.dat", ios::app | ios::binary);

	write.write(reinterpret_cast<char *>(&sv), sizeof(SinhVien));
	write.close();
}

void swap(SinhVien &sv1, SinhVien &sv2){
	SinhVien temp;
	temp=sv1;
	sv1=sv2;
	sv2=temp;
}

char *DaoNgaySinh(char ngay[20]){
	char temp[20], date[20], *m[20];
	strcpy(date, ngay);
	char *p;
	int i=0;
	p=strtok(date, "/");
	while(p!=NULL){
		m[i]=p;
		i++;
		p=strtok(NULL, "/");
	}
	strcpy(temp, m[i-1]);
	for(int j=i-2; j>=0; j--){
		strcat(temp, "/");
		strcat(temp, m[j]);
	}
	return temp;
}

char *DaoTen(char name[50]){
	char temp[50], namet[50], *str[10];
	strcpy(namet, name);
	char *p;
	int i=0;
	p=strtok(namet, " ");
	while(p!=NULL){
		str[i]=p;
		i++;
		p=strtok(NULL, " ");
	}
	strcpy(temp, str[i-1]);
	for(int j=i-2; j>=0; j--){
		strcat(temp, " ");
		strcat(temp, str[j]);
	}
	return temp;
}

void Selection_sort(vector<SinhVien> sv, int Opt){
	int min;
	char temp1[50], temp2[50];
	for(int i=0; i<sv.size()-1; i++){
		min=i;
		for(int j=i+1; j<sv.size(); j++){

			switch (Opt)
			{
			case 1:
				{
					if(strcmp(sv[min].MaSV, sv[j].MaSV)>0)
						min=j;
				}
				break;
			case 2:
				{
					strcpy(temp1, DaoTen(sv[min].HoTen));
					strcpy(temp2, DaoTen(sv[j].HoTen));
					if(strcmp(temp1, temp2)>0)
						min=j;
				}
				break;
			case 3:
				{
					strcpy(temp1, DaoNgaySinh(sv[min].NgaySinh));
					strcpy(temp2, DaoNgaySinh(sv[j].NgaySinh));
					if(strcmp(temp1, temp2)>0)
						min=j;
				}
				break;
			case 4:
				{
					if(sv[min].DiemTB<sv[j].DiemTB)
						min=j;
				}
				break;
			}
		}
		swap(sv[i], sv[min]);
	}

	InDanhSach(sv, 6, 14, 11, true);
}

void Insertion_sort(vector<SinhVien> sv, int Opt){
	int j;
	SinhVien temp;
	char temp1[50], temp2[50];
	for(int i=1; i<sv.size(); i++){
		temp=sv[i];
		j=i-1;
		switch (Opt)
		{
		case 1:
			{
				while((j>=0)&&(strcmp(temp.MaSV, sv[j].MaSV)<0)){
					sv[j+1]=sv[j];
					j=j-1;
				}
			}
			break;
		case 2:
			{
				strcpy(temp1, DaoTen(temp.HoTen));

				while(j>=0){
					strcpy(temp2, DaoTen(sv[j].HoTen));
					if(strcmp(temp1, temp2)<0){
						sv[j+1]=sv[j];
						j=j-1;
					}else{
						break;
					}
				}
			}
			break;
		case 3:
			{
				strcpy(temp1, DaoNgaySinh(temp.NgaySinh));
				while(j>=0){
					strcpy(temp2, DaoNgaySinh(sv[j].NgaySinh));
					if(strcmp(temp1, temp2)<0){
						sv[j+1]=sv[j];
						j=j-1;
					}else{
						break;
					}
				}
			}
			break;
		case 4:
			{
				while((j>=0)&&(temp.DiemTB>sv[j].DiemTB)){
					sv[j+1]=sv[j];
					j=j-1;
				}
			}
			break;
		}
		sv[j+1]=temp;
	}
	InDanhSach(sv, 6, 14, 11, true);
}

void Bubble_sort(vector<SinhVien> sv, int Opt){
	char temp1[50], temp2[50];
	for(int i=0; i<sv.size()-1; i++){
		for(int j=sv.size()-1; j>i; j--){
			switch (Opt)
			{
			case 1:
				{
					if(strcmp(sv[j].MaSV, sv[j-1].MaSV)<0)
						swap(sv[j], sv[j-1]);
				}
				break;
			case 2:
				{
					strcpy(temp1, DaoTen(sv[j].HoTen));
					strcpy(temp2, DaoTen(sv[j-1].HoTen));
					if(strcmp(temp1, temp2)<0)
						swap(sv[j], sv[j-1]);
				}
				break;
			case 3:
				{
					strcpy(temp1, DaoNgaySinh(sv[j].NgaySinh));
					strcpy(temp2, DaoNgaySinh(sv[j-1].NgaySinh));
					if(strcmp(temp1, temp2)<0)
						swap(sv[j], sv[j-1]);
				}
				break;
			case 4:
				{
					if(sv[j].DiemTB>sv[j-1].DiemTB)
						swap(sv[j], sv[j-1]);
				}
				break;
			}
		}
	}
	InDanhSach(sv, 6, 14, 11, true);
}

void Quick_sort(vector<SinhVien> &sv, int L, int R, int Opt){
	int i=L;
	int j=R;
	SinhVien key=sv[(L+R)/2];
	char cKey[50], temp[50];

	while (i<=j){
		switch (Opt)
		{
		case 1:
			{
				while(strcmp(sv[i].MaSV, key.MaSV)<0)
					i++;
				while(strcmp(sv[j].MaSV, key.MaSV)>0)
					j--;
			}
			break;
		case 2:
			{
				strcpy(cKey, DaoTen(key.HoTen));
				while(1){
					strcpy(temp, DaoTen(sv[i].HoTen));
					if(strcmp(temp, cKey)<0)
						i++;
					else
						break;
				}
				while(1){
					strcpy(temp, DaoTen(sv[j].HoTen));
					if(strcmp(temp, cKey)>0)
						j--;
					else
						break;
				}
			}
			break;
		case 3:
			{
				strcpy(cKey, DaoNgaySinh(key.NgaySinh));
				while(1){
					strcpy(temp, DaoNgaySinh(sv[i].NgaySinh));
					if(strcmp(temp, cKey)<0)
						i++;
					else
						break;
				}
				while(1){
					strcpy(temp, DaoNgaySinh(sv[j].NgaySinh));
					if(strcmp(temp, cKey)>0)
						j--;
					else
						break;
				}
			}
			break;
		case 4:
			{
				while(sv[i].DiemTB>key.DiemTB)
					i++;
				while(sv[j].DiemTB<key.DiemTB)
					j--;
			}
			break;
		case 5:
			{
				while(strcmp(sv[i].MaLop, key.MaLop)<0)
					i++;
				while(strcmp(sv[j].MaLop, key.MaLop)>0)
					j--;
			}
			break;
		}
		if(i<=j){
			swap(sv[i], sv[j]);
			i++;
			j--;
		}
	}
	if(L<j)
		Quick_sort(sv, L, j, Opt);
	if(i<R)
		Quick_sort(sv, i, R, Opt);
}

bool SearchName(char *Name, char *Key){
	int lengthKey = strlen(Key);
	char *cutName = new char[lengthKey];
	int lengthName = strlen(Name);
	bool result = false;
	for(int i = 0; i<lengthName-lengthKey+1; i++){
		int j = i;
		for (int k = 0; k<lengthKey; k++)
		{
			cutName[k] = Name[j];
			j++;
		}
		cutName[j] = '\0';
		if(strcmp(cutName, Key)==0)
			result = true;
	}
	return result;
}

void Linear_search(vector<SinhVien> sv, int Opt){
	vector<SinhVien> result;
	char cKey[50], cName[50];
	//cKey[0] = '\0';
	float mKey;
	cout << "\n Nhap noi dung can tim: ";
	fflush(stdin);
	gotoxy(26, 14);
	gets_s(cKey);
	for(int i=0; i<sv.size(); i++){
		switch (Opt)
		{

		case 1:
			{
				if(strcmp(cKey, sv[i].MaSV)==0){
					result.push_back(sv[i]);
				}
			}
			break;
		case 2:
			{
				strlwr(cKey);
				strcpy(cName, sv[i].HoTen);
				strlwr(cName);
				if(SearchName(cName, cKey)){
					result.push_back(sv[i]);
				}
			}
			break;
		case 3:
			{
				if(strcmp(cKey, sv[i].NgaySinh)==0){
					result.push_back(sv[i]);
				}
			}
			break;
		case 4:
			{
				mKey = atof(cKey);
				if(mKey==sv[i].DiemTB){
					result.push_back(sv[i]);
				}
			}
			break;
		case 5:
			{
				if(strcmp(cKey, sv[i].MaLop)==0){
					result.push_back(sv[i]);
				}
			}
			break;
		}
	}
	if(result.empty()){
		cout << "\n\n\t\t\t------Khong tim thay ket qua!!!------\n";
		getch();
	}else{
		InDanhSach(result, 6, 16, 11, true);
	}

}

int Binary_search(vector<SinhVien> sv, int L, int R, int Opt, char cKey[50]){
	if(L>R)
		return -1;
	else
	{
		char tKey[50];
		int key = (L+R)/2;
		switch (Opt)
		{
		case 1:
			{
				if(strcmp(cKey, sv[key].MaSV)==0) return key;
				else if(strcmp(cKey, sv[key].MaSV)>0) return Binary_search(sv, key+1, R, Opt, cKey);
				else if(strcmp(cKey, sv[key].MaSV)<0) return Binary_search(sv, L, key-1, Opt, cKey);
			}
			break;
		case 2:
			{
				char cKey1[50];
				strcpy(tKey, DaoTen(sv[key].HoTen));
				strcpy(cKey1, DaoTen(cKey));
				string tencat="";
				for(int i=0; i<strlen(cKey1); i++){
					tencat += tKey[i];
				}

				if(strcmp(cKey1, tencat.c_str())==0) return key;
				else if(strcmp(cKey1, tencat.c_str())>0) return Binary_search(sv, key+1, R, Opt, cKey);
				else if(strcmp(cKey1, tencat.c_str())<0) return Binary_search(sv, L, key-1, Opt, cKey);
			}
			break;
		case 3:
			{
				char cKey1[50];
				strcpy(tKey, DaoNgaySinh(sv[key].NgaySinh));
				strcpy(cKey1, DaoNgaySinh(cKey));
				if(strcmp(cKey1, tKey)==0) return key;
				else if(strcmp(cKey1, tKey)>0) return Binary_search(sv, key+1, R, Opt, cKey);
				else if(strcmp(cKey1, tKey)<0) return Binary_search(sv, L, key-1, Opt, cKey);
			}
			break;
		case 4:
			{
				float mKey = atof(cKey);
				if(mKey==sv[key].DiemTB) return key;
				else if(mKey<sv[key].DiemTB) return Binary_search(sv, key+1, R, Opt, cKey);
				else if(mKey>sv[key].DiemTB) return Binary_search(sv, L, key-1, Opt, cKey);
			}
			break;
		case 5:
			{
				if(strcmp(cKey, sv[key].MaLop)==0) return key;
				else if(strcmp(cKey, sv[key].MaLop)>0) return Binary_search(sv, key+1, R, Opt, cKey);
				else if(strcmp(cKey, sv[key].MaLop)<0) return Binary_search(sv, L, key-1, Opt, cKey);
			}
		}
	}
}

int numClass(vector<SinhVien> sv){
	int count = 0;
	char maLop[10];
	int i = 0;
	while(!sv.empty()){
		strcpy(maLop, sv[0].MaLop);
		count++;
		i = 0;
		while(!sv.empty() && i<sv.size()){
			if(strcmp(maLop, sv[0].MaLop)==0){
				sv.erase(sv.begin()+i);
			}else{
				i++;
			}
		}
	}
	return count;
}

void BaoCao_SinhVien(vector<SinhVien> sv){
	Quick_sort(sv, 0, sv.size()-1, 5);
	char malop[10];
	int count, i;
	vector<SinhVien> temp;
	int line=0;
	int	y=16;

	while(!sv.empty()){
		temp.clear(); 
		strcpy(malop, sv[0].MaLop); 
		i=0; 
		count = 0; 
		while(!sv.empty()){
			if(i==sv.size()){
				break;
			}else{
				if(strcmp(malop, sv[i].MaLop)==0){
					count++;
					temp.push_back(sv[i]);  
					sv.erase(sv.begin()+i); 
				}else
					i++; 
			}
		}
		InDanhSach(temp, 6, y, 11, false);
		gotoxy(8, y+1);
		cout << "Lop "<<malop;//<< " co "<< count << " sinh vien\n";
		y = y+count*2+7;
	}
	getch();
}

int Xep_Loai(float diem){
	int result;
	if(diem >= 0 && diem <4){
		result = 0;
	}else if(diem >= 4 && diem < 6.5){
		result = 1;
	}else if(diem >=6.5 && diem <8){
		result = 2;
	}else if(diem >= 8 && diem < 9.5)
		result = 3;
	else
		result = 4;
	return result;
}

void BaoCao_PhanLoai(vector<SinhVien> sv){
	int x=20;
	int y=16;
	Quick_sort(sv, 0, sv.size()-1, 5);

	Report_table(x, y, numClass(sv), 11);
	gotoxy(x+12, y-2); cout << "BANG PHAN BO TY LE XEP LOAI HOC TAP CUA TUNG LOP";
	char malop[10];
	int count, i, diem;
	while(!sv.empty()){
		strcpy(malop, sv[0].MaLop);
		i = 0;
		count = 0;
		float soluong[]={0, 0, 0, 0, 0};
		while(!sv.empty()){
			if(i==sv.size()){
				break;
			}else{
				if(strcmp(malop, sv[i].MaLop)==0){
					count++;
					diem = Xep_Loai(sv[i].DiemTB);
					soluong[diem]++;
					sv.erase(sv.begin()+i);
				}else
					i++;
			}
		}
		gotoxy(x+7, y+5); cout << malop;
		for (int i = 4; i >=0 ; i--)
		{
			gotoxy(x+22, y+5);
			printf("%5.2f %%", (soluong[i]/count)*100);
			x += 10;
		}
		x = 20;
		y += 2;
	}
	getch();
}

void Xoa(vector<SinhVien> &sv,int index){
	sv.erase(sv.begin()+index);
	fstream write("Sinhvien.dat", ios::out | ios::binary);
	for(int i=0; i<sv.size(); i++)
		write.write(reinterpret_cast<char *>(&sv[i]), sizeof(SinhVien));
	write.close();
}

void Chinh_Sua(vector<SinhVien> &sv, int index){
	SinhVien svt = sv[index];
	ShowCur(false);
	int x, y, chose;
	char key;
	bool confirm = false;
	x = 3;
	y = 9;
	do 
	{
		Border_form(x-2, y-7, 24, 95, 13);
		gotoxy(x, y-6); cout << "SUA THONG TIN SINH VIEN!!!";
		textcolor(11);
		chose = y;
		gotoxy(x, y-3); cout << "ESC: Thoat    Enter: Nhap    SpakeSpace: Xac nhan";
		gotoxy(x, y);
		gotoxy(x, y   ); cout << "Nhap vao ma lop: ";
		gotoxy(x, y+3 ); cout << "Nhap vao ma sinh vien: ";
		gotoxy(x, y+6 ); cout << "Nhap vao ten sinh vien: ";
		gotoxy(x, y+9 ); cout << "Nhap vao ngay thang nam sinh: ";
		gotoxy(x, y+12); cout << "Nhap diem: ";
		gotoxy(x+33, y); cout << svt.MaLop;
		gotoxy(x+33, y+3); cout << svt.MaSV;
		gotoxy(x+33, y+6); cout << svt.HoTen;
		gotoxy(x+33, y+9); cout << svt.NgaySinh;
		gotoxy(x+33, y+12); cout << svt.DiemTB;
		do 
		{
			chose = Input_form(x+31, y, chose-1);
			textcolor(11);
			ShowCur(true);
			//gotoxy(x+31, chose);
			switch (chose)
			{
			case 9:
				{
					nhapMaLop(svt.MaLop, x+31, chose);
				}
				break;
			case 12:
				{
					nhapMaSV(svt.MaSV, x+31, chose);
				}
				break;
			case 15:
				{
					ChuanHoaTen(svt.HoTen, x+31, chose);
				}
				break;
			case 18:
				{
					bool checkDate;
					do 
					{
						ChuanHoaNgay(svt.NgaySinh, x+31, chose);
						checkDate = CheckDate(svt.NgaySinh);
						if(!checkDate){
							gotoxy(x+60, chose);
							cout << "Ngay thang sai!";
							getch();
							gotoxy(x+60, chose);
							cout << "               ";
						}
					} while (!checkDate);
				}
				break;
			case 21:
				{
					ChuanHoaDiem(svt.DiemTB, x+31, chose);
				}
				break;
			}
		} while (chose!=0 && chose!=1);
		if(chose==1){
			confirm = YesOrNo_dialog(x+60, y+2, "Luu thong tin thay doi!", "Xac nhan thay doi", 11, 12);
			if(confirm){
				sv.erase(sv.begin()+index);
				sv.insert(sv.begin()+index, svt);

				fstream write("Sinhvien.dat", ios::out | ios::binary);
				for(int i=0; i<sv.size(); i++){
					write.write(reinterpret_cast<char *>(&sv[i]), sizeof(SinhVien));
				}
				write.close();
			}
		}
		system("cls");
	} while (!confirm && chose!=0);

	ShowCur(false);
}