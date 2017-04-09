#include "SVDH.h"
#include <iostream>
#include <iomanip>

using namespace std;

SVDH::SVDH(void)
{
}

void SVDH::NhapDH()
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
	while (cout << "Tong so tin chi: " && !(cin >> TongTinChi) && TongTinChi < 1)
	{
		cout << "Du lieu khong hop le, vui long nhap lai! " << endl;
		cin.clear();
		cin.ignore(1024, '\n');
	}	
	//Diem trung binh
	while (cout << "Diem trung binh: " && !(cin >> DiemTB) && DiemTB < 0)
	{
		cout << "Du lieu khong hop le, vui long nhap lai! " << endl;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	//Ten luan van
	cin.ignore(1024, '\n');
	cout << "Ten luan van: ";
	cin.getline(TenLuanVan, 100);
	//Diem luan van
	while (cout << "Diem luan van: " && !(cin >> DiemLuanVan) && DiemLuanVan < 0)
	{
		cout << "Du lieu khong hop le, vui long nhap lai! " << endl;
		cin.clear();
		cin.ignore(1024, '\n');
	}
}

void SVDH::XuatDH()
{
	cout<< "Ma so sinh vien: " << "\t" << MSSV << endl
		<< "Ho ten: " << "\t\t" << HoTen << endl
		<< "Dia chi: " << "\t\t" << DiaChi << endl
		<< "Tong so tin chi: " << "\t" << TongTinChi << endl
		<< "Diem trung binh: " << "\t" << DiemTB << endl
		<< "Ten luan van: " << "\t\t" << TenLuanVan << endl
		<< "Diem luan van: " << "\t\t" << DiemLuanVan << endl;
}

SVDH::~SVDH(void)
{
}
