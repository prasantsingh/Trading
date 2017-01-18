#pragma once
#include <atldbcli.h>
#include "afxwin.h"
#include "Client_Table.h"
// ClientCreate dialog

class ClientCreate : public CDialogEx
{
	DECLARE_DYNAMIC(ClientCreate)

public:
	ClientCreate(CWnd* pParent = NULL);   // standard constructor
	virtual ~ClientCreate();
	CDataSource connection;
    CSession session;
    HRESULT hr;
// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSave();
	afx_msg void OnClose();
	CEdit m_login;
	CEdit m_name;
	CEdit m_group1;
	CEdit m_group2;
	CEdit m_group3;
	CButton m_commnentYN;
	CButton m_ignoreYN;
	float m_creditclientf;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedDeletebtn();
};