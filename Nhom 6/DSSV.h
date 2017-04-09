#pragma once
#include "SVCD.h"
#include "SVDH.h"

class DSSV
{
public:
	DSSV(void);
	void NhapDS();
	void XuatDS();
	int dh_dk_tn();
	int cd_dk_tn();
	SVDH max_tb_dh();
	SVCD max_tb_cd();
	void max_lv();
	SVDH min_lv();
	int getso_svcd();
	int getso_svdh();
	void TB_sort();
	~DSSV(void);
};

