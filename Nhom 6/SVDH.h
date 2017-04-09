#pragma once
#include "SinhVien.h"

class SVDH : public SinhVien 
{
public:
	SVDH(void);
	char TenLuanVan[40];
	float DiemLuanVan;
	void NhapDH();
	void XuatDH();
	~SVDH(void);
};

