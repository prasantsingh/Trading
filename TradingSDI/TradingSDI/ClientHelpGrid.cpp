#include "stdafx.h"
#include "ClientHelpGrid.h"


ClientHelpGrid::ClientHelpGrid(void)
{
}


ClientHelpGrid::~ClientHelpGrid(void)
{
}

void ClientHelpGrid::OnSetup()
{
	SetNumberCols(9);
	//SetNumberRows(10);
		//soritng
	m_iArrowIndex = AddCellType( &m_sortArrow );

	SetCurrentCellMode( 2 );

	UseHints( TRUE );

	SetSH_Width( 0 );

	QuickSetCellType( 0, -1, m_iArrowIndex );
	SortBy( 0, UG_SORT_ASCENDING );

	m_iSortCol = 0;
	m_bSortedAscending = TRUE;


	EnableMenu(TRUE);

	//CoInitialize(NULL);		
	//hr=connection.OpenFromInitializationString(L"Provider=SQLOLEDB.1;Password=ok@12345;Persist Security Info=True;User ID=sa;Initial Catalog=MT4;Data Source=68.168.101.187;Use Procedure for Prepare=1;Auto Translate=True;Packet Size=4096;Workstation ID=ABHISHEK-P;Use Encryption for Data=False;Tag with column collation when possible=False");			
	//if(SUCCEEDED(hr))
	//{
	//	hr=session.Open(connection);							
	//}


}


void ClientHelpGrid::OnDClicked(int col,long row,RECT *rect,POINT *point,BOOL processed)
{
	StartEdit();
}	
