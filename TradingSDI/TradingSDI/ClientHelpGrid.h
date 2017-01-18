#pragma once
#include "ugctrl.h"
#include "OrderGrid.h"

class ClientHelpGrid :public CUGCtrl
{
public:
	ClientHelpGrid(void);
	~ClientHelpGrid(void);


	BOOL m_bSortedAscending;
	int m_iArrowIndex;
	CUGSortArrowType m_sortArrow;
	int m_iSortCol;

public:
	virtual void OnSetup();
	virtual void OnDClicked(int col,long row,RECT *rect,POINT *point,BOOL processed);
};

