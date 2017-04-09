#pragma once
#include "SinhVien.h"

class SVCD : public SinhVien
{
public:
	SVCD(void);
	float DiemTotNghiep;
	void NhapCD();
	void XuatCD();
	~SVCD(void);
};
