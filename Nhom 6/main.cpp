#include "DSSV.h"
#include "SVCD.h"
#include "SVDH.h"
#include <iostream>

using namespace std;

void main()
{
	int chon=-1;
	DSSV ds;
	cout<<"*-*-*-*-*-*-*-*--CHUONG TRINH QUAN LI SINH VIEN--*-*-*-*-*-*-*-*\n";
	while (chon!=0)
	{
		cout<< "\n-----------------------MENU----------------------\n"
			<< "1. Nhap danh sach sinh vien tu ban phim\n"
			<< "2. Xuat danh sach sinh vien ra man hinh\n"
			<< "3. Xuat danh sach sinh vien ra file\n"
			<< "4. So luong sinh vien day du dieu kien tot nghiep\n"
			<< "5. Sinh vien CAO DANG co diem trung binh cao nhat\n"
			<< "6. Sinh vien DAI HOC co diem trung binh cao nhat\n"
			<< "7. Dem so sinh vien theo tung he\n"
			<< "8. Nhung sinh vien DAI HOC co diem luan van cao nhat, thap nhat\n"
			<< "9. Sap xep danh sach theo giam dan theo diem trung binh\n"
			<< "10. Sap xep danh sach thu tu bang chu cai\n"
			<< "11. Xoa man hinh\n"
			<< "0. Thoat\n"
			<< "----> Ban chon: ";
		cin>>chon;			
		cout<< "\n-------------------------------------------------\n";
		switch (chon)
		{
			case 1:
			{
				system("CLS");
				ds.NhapDS(); break;
			}
			case 2:
			{
				ds.XuatDS(); break;
			}
			case 4:
			{	
				cout<< "So luong sinh vien du dieu kien tot nghiep la:\n"
					<< "DAI HOC: "<< ds.dh_dk_tn() <<"\n"
					<< "CAO DANG: " << ds.cd_dk_tn() << "\n";
				break;
			}
			case 5:
			{
				cout<< "Thong tin sinh vien CAO DANG co diem trung binh cao nhat:\n";
				ds.max_tb_cd().XuatCD(); break;
			}			
			case 6:
			{
				cout<< "Thong tin sinh vien DAI HOC co diem trung binh cao nhat:\n";
				ds.max_tb_dh().XuatDH(); break;
			}
			case 7:
			{	
				cout<< "Tong so sinh vien tung he: \n"
					<< "DAI HOC: " << ds.getso_svdh() << "\n"
					<< "CAO DANG: " << ds.getso_svcd() << "\n";
				break;
			}
			case 8:
			{
				cout<< "Thong tin sinh vien DAI HOC co diem luan van cao nhat:\n";
				ds.max_lv();
				cout << "\nVa sinh vien co diem luan van thap nhat:\n";
				ds.min_lv().XuatDH();
				break;
			}
			case 9:
			{
				ds.TB_sort(); break;
			}
			case 11:
			{
				system("CLS"); break;
			}
		}
	};
	system("PAUSE");
}