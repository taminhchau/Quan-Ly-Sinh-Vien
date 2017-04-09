#include "SVCD.h"
#include <iostream>
#include <iomanip>

using namespace std;

SVCD::SVCD(void)
{
}

void SVCD::NhapCD()
{
	//MSSV
	cin.ignore(1024, '\n');
	cout << "Ma so sinh vien: ";
	cin.getline(MSSV, 10);
	//Ho ten
	cout << "Ho ten: ";
	cin.getline(HoTen, 30);
	//Dia chi
	cout << "Dia chi: ";
	cin.getline(DiaChi, 50);
	//Tong so tin chi
	while (cout << "Tong so tin chi: " && !(cin >> TongTinChi) && TongTinChi < 1 && TongTinChi > 200)
	{
		cout << "Du lieu khong hop le, vui long nhap lai! " << endl;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	//Diem trung binh
	while (cout << "Diem trung binh: " && !(cin >> DiemTB) && DiemTB < 0 && DiemTB > 10)
	{
		cout << "Du lieu khong hop le, vui long nhap lai! " << endl;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	//Diem tot nghiep
	while (cout << "Diem tot nghiep: " && !(cin >> DiemTotNghiep) && DiemTotNghiep < 0 && DiemTotNghiep > 200)
	{
		cout << "Du lieu khong hop le, vui long nhap lai! " << endl;
		cin.clear();
		cin.ignore(1024, '\n');
	}
}

void SVCD::XuatCD()
{
	
	cout<< "Ma so sinh vien: " << "\t" << MSSV << endl
		<< "Ho ten: " << "\t\t"<< HoTen << endl
		<< "Dia chi: " << "\t\t"<< DiaChi << endl
		<< "Tong so tin chi: " << "\t" << TongTinChi << endl
		<< "Diem trung binh: " << "\t" << DiemTB << endl
		<< "Diem tot nghiep: " << "\t" << DiemTotNghiep << endl;
}

SVCD::~SVCD(void)
{
}
