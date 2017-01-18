#pragma once
#include "overview.h"
#include "tab2.h"
#include "tab3.h"
#include "tab4.h"
 
// tabControl
 
class tabControl : public CTabCtrl
{
    DECLARE_DYNAMIC(tabControl)
 
public:
    tabControl();
    virtual ~tabControl();
 
protected:
    DECLARE_MESSAGE_MAP()
private:
    //Array to hold the list of dialog boxes/tab pages for CTabCtrl
    int m_DialogID[4];
    //CDialog Array Variable to hold the dialogs
    CDialog *m_Dialog[4];
    int m_tabCurrent;
    int m_nPageCount;
 
    //CArray<CString,CString> TabCaptions;
    //CArray<CDialog *,CDialog *> TabPanes;
    //int m_iCurSel;
public:
    //Function to Create the dialog boxes during startup
    void InitDialogs();
 
    //Function to activate the tab dialog boxes
    void ActivateTabDialogs();
 
    afx_msg void OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult);
 
  //  afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
    //void AddTabPane(CString strCaption,CDialog * pDlg);
    //afx_msg void OnMove(int x, int y);
    //void SetDefaultPane(int iPaneIndex);
     
    virtual BOOL PreTranslateMessage(MSG* pMsg);
 
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnClose();
    afx_msg void OnDestroy();
};