#include "DSSV.h"
#include "SVCD.h"
#include "SVDH.h"
#include <iostream>
#include <iomanip>

using namespace std;
int n_svcd, n_svdh;
SVCD *svcd;
SVDH *svdh;

DSSV::DSSV(void)
{
}

void DSSV::NhapDS()
{
	//Nhap so sinh vien cao dang
	int i;
	while (cout << "Nhap so luong sinh vien cao dang: " && !(cin >> n_svcd) && n_svcd < 1)
	{
		cout << "Du lieu ban nhap khong hop le, vui long nhap lai!" << endl;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	svcd = new SVCD [n_svcd];
	cout << "\n-------------------------------------------------\n";
	for (i = 0; i < n_svcd; ++i)
	{
		cout << endl << "Nhap thong tin cua sinh vien thu " << i+1 << ": " << endl;
		svcd[i].NhapCD();
	}
	cout << endl;
	
	//Nhap so sinh vien dai hoc
	while (cout << "Nhap so luong sinh vien dai hoc: " && !(cin >> n_svdh) && n_svdh < 1)
	{
		cout << "Du lieu ban nhap khong hop le, vui long nhap lai!" << endl;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	svdh = new SVDH [n_svdh];
	cout << "\n-------------------------------------------------\n";
	for (i = 0; i < n_svdh; ++i)
	{
		cout << endl << "Nhap thong tin cua sinh vien thu " << i+1 << ": " << endl;
		svdh[i].NhapDH();
	}
	cout << endl;
}

//In ra man hinh thong tin vua nhap
void DSSV::XuatDS()
{
	int i;
	cout << "\n---Danh sach sinh vien CAO DANG:";
	for(i = 0; i < n_svcd; ++i)
	{
		cout<< "\n-------------------------------------------------\n"
			<<"[ "<< i+1<<" ]\n";
		//<< "Thong tin cua sinh vien thu " << i+1 << ": " << endl;
		svcd[i].XuatCD();
	}
	cout << "\n\n---Danh sach sinh vien DAI HOC:";
	for(i = 0; i < n_svdh; ++i)
	{
		cout<< "\n-------------------------------------------------\n"
			<<"[ "<< i+1<<" ]\n";
		//<< "Thong tin cua sinh vien thu " << i+1 << ": " << endl;
		svdh[i].XuatDH();
	}
}

//So luong SV tot nghiep
int DSSV::dh_dk_tn()
{
	int dk_dh=0;
	for (int i = 0; i < n_svdh; ++i)
	{
		
		if (svdh[i].TongTinChi >= 170 && svdh[i].DiemTB >= 5 && svdh[i].DiemLuanVan >= 5)
			++dk_dh;
	}
	return dk_dh;
}
int DSSV::cd_dk_tn()
{
	int dk_cd=0;
	for (int i = 0; i < n_svcd; ++i)
	{
		if (svcd[i].TongTinChi >= 120 && svcd[i].DiemTB >= 5 && svcd[i].DiemTotNghiep >= 5)
			++dk_cd;
	}
	return dk_cd;
}

//DAI HOC - Diem TB cao nhat
SVDH DSSV::max_tb_dh()
{
	SVDH max = svdh[0];
	for (int i = 0; i < n_svdh; ++i)
	{
		if (svdh[i].DiemTB > max.DiemTB)
			max = svdh[i];
	}
	return max;
}

//CAO DANG - Diem TB cao nhat
SVCD DSSV::max_tb_cd()
{
	SVCD max = svcd[0];
	for (int i = 0; i < n_svcd; ++i)
	{
		if (svcd[i].DiemTB > max.DiemTB)
			max = svcd[i];
	}
	return max;
}

//DAI HOC - Diem LV cao nhat, thap nhat
void DSSV::max_lv()
{
	SVDH max = svdh[0];
	for (int i = 0; i < n_svdh; ++i)
	{
		if (svdh[i].DiemLuanVan > max.DiemLuanVan)
			max = svdh[i];
	}
	for (int i =0;i<n_svdh;i++)
	{
		if(svdh[i].DiemLuanVan==max.DiemLuanVan)
			cout<<"\n";
			svdh[i].XuatDH();
	}
	//return max;
}
SVDH DSSV::min_lv()
{
	SVDH min = svdh[0];
	for (int i = 0; i < n_svdh; ++i)
	{
		if (svdh[i].DiemLuanVan < min.DiemLuanVan)
			min = svdh[i];
	}
	return min;
}

//Get so luong SV
int DSSV::getso_svcd()
{
	return n_svcd;
}
int DSSV::getso_svdh()
{
	return n_svdh;
}

//Sap xep theo diem TB giam
void DSSV::TB_sort()
{
	int i,j;
	SVDH tam;
	SVCD tam2;
	cout<<"Danh Sach Sau Khi Sap Xep:\n";
	cout<<"---DAI HOC:";
	for (i=0;i<n_svdh-1;i++)
	{	for(j=i+1;j<n_svdh;j++)
		if(svdh[i].DiemTB < svdh[j].DiemTB)
		{
			tam=svdh[i];
			svdh[i]=svdh[j];
			svdh[j]=tam;
		}
	}
	for (i=0;i<n_svdh;i++)
	{
		cout<<"\n-------------------------------------------------\n"
			<<"[ "<< i+1<<" ]\n";
		svdh[i].XuatDH();
	}
	cout<<"\n---CAO DANG:";
	for (i=0;i<n_svcd-1;i++)
	{	for(j=i+1;j<n_svdh;j++)
		if(svcd[i].DiemTB < svcd[j].DiemTB)
		{
			tam2=svcd[i];
			svcd[i]=svcd[j];
			svcd[j]=tam2;
		}
	}
	for (i=0;i<n_svcd;i++)
	{
		cout<<"\n-------------------------------------------------\n"
			<<"[ "<< i+1<<" ]\n";
		svcd[i].XuatCD();
	}
}

DSSV::~DSSV(void)
{
}
