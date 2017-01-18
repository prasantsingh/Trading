// tabControl.cpp : implementation file
//
 
#include "stdafx.h"
#include "TradingSDI.h"
#include "tabControl.h"
 
// tabControl
 
 
 
IMPLEMENT_DYNAMIC(tabControl, CTabCtrl)
 
tabControl::tabControl()
{
 //  m_iCurSel = -1;
    m_DialogID[0] =IDD_TAB1;
    m_DialogID[1] =IDD_TAB2;
    m_DialogID[2] =IDD_TAB3;
    m_DialogID[3] =IDD_TAB4;
 
    m_Dialog[0] = new overview();
    m_Dialog[1] = new Tab2();
    m_Dialog[2] = new tab3();
    m_Dialog[3] = new tab4();
 
    m_nPageCount = 4;
    
}
 
tabControl::~tabControl()
{
 
    for(int nCount=2; nCount <m_nPageCount ; nCount++){
     delete m_Dialog[nCount];
    }
 
}
 
void tabControl::InitDialogs()
{
    /*m_Dialog[0]->Create(m_DialogID[0],GetParent());
    m_Dialog[1]->Create(m_DialogID[1],GetParent());
    m_Dialog[2]->Create(m_DialogID[2],GetParent());
    m_Dialog[3]->Create(m_DialogID[3],GetParent());*/
 
    m_tabCurrent=0;
 
    m_Dialog[0]->Create(m_DialogID[0], this);
    m_Dialog[1]->Create(m_DialogID[1], this);
    m_Dialog[2]->Create(m_DialogID[2], this);
    m_Dialog[3]->Create(m_DialogID[3], this);
 
 
    m_Dialog[0]->ShowWindow(SW_SHOW);
    m_Dialog[1]->ShowWindow(SW_HIDE);
    m_Dialog[2]->ShowWindow(SW_HIDE);    
    m_Dialog[3]->ShowWindow(SW_HIDE);
    ActivateTabDialogs();
 
 
}
 
BEGIN_MESSAGE_MAP(tabControl, CTabCtrl)
//  ON_NOTIFY_REFLECT(NM_CLICK, OnNMClick)
//  ON_WM_MOVE()
    ON_NOTIFY_REFLECT(TCN_SELCHANGE, &tabControl::OnTcnSelchange)
     
    ON_WM_LBUTTONDOWN()
    ON_WM_CLOSE()
    ON_WM_DESTROY()
END_MESSAGE_MAP()
 
//void tabControl::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
//{
//  // TODO: Add your control notification handler code here
//  int iTab;
//  int iPaneCount=0;
//  CRect r;
//  iTab=GetCurSel();
//  CDialog *p;
//  m_iCurSel=iTab;
//  while(iPaneCount<TabPanes.GetCount())
//  {
//      p = TabPanes.GetAt(iPaneCount); 
//      p->ShowWindow(SW_HIDE);
//      iPaneCount++;
//  }
//  p = TabPanes.GetAt(m_iCurSel);
//  GetWindowRect(r);
//  p->SetWindowPos(&CWnd::wndBottom,r.left+3,r.top+25,r.Width()-7,r.Height()-30,SWP_SHOWWINDOW);  
//  p->ShowWindow(SW_SHOW); 
//  *pResult = 0;
//}
 
 
//void tabControl::AddTabPane(CString strCaption,CDialog * pDlg)
//{
//  TabCaptions.Add(strCaption);
//  TabPanes.Add(pDlg);
//  TC_ITEM tci;
//  tci.mask = TCIF_TEXT;
//  tci.pszText = (LPWSTR)(LPCTSTR)strCaption;
//  tci.cchTextMax = strCaption.GetLength();
//  InsertItem((TabCaptions.GetCount()-1),&tci);
//
////    SetDefaultPane(0);
//}
 
//void tabControl::OnMove(int x, int y)
//{
//  CTabCtrl::OnMove(x, y);
//  CDialog *p;
//  CRect r;
//  if(m_iCurSel>-1)
//  {
//      p = TabPanes.GetAt(m_iCurSel);
//      GetWindowRect(r);
//      p->SetWindowPos(&CWnd::wndBottom,r.left+3,r.top+25,r.Width()-7,r.Height()-30,SWP_SHOWWINDOW);  
//      p->ShowWindow(SW_SHOW); 
//  }
//}
 
 
//void tabControl::SetDefaultPane(int iPaneIndex)
//{
//  CDialog *p;
//  CRect r;
//  m_iCurSel = iPaneIndex;
//  if(iPaneIndex<TabPanes.GetCount())
//  {
//      SetCurSel(iPaneIndex);
//      p = TabPanes.GetAt(iPaneIndex);
//      GetWindowRect(r);
//      p->SetWindowPos(&CWnd::wndBottom,r.left+3,r.top+25,r.Width()-7,r.Height()-30,SWP_SHOWWINDOW);  
//      p->ShowWindow(SW_SHOW); 
//  }
//}
 
 
// tabControl message handlers
 
 
 
 
void tabControl::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
    // TODO: Add your control notification handler code here
      // the compiler is happy in warning level 4
    if(m_tabCurrent != GetCurSel()){
        m_Dialog[m_tabCurrent]->ShowWindow(SW_HIDE);
        m_tabCurrent=GetCurSel();
        m_Dialog[m_tabCurrent]->ShowWindow(SW_SHOW);
        m_Dialog[m_tabCurrent]->SetFocus();
    }
 
 
    *pResult = 0;
}
 
 
void tabControl::ActivateTabDialogs()
{
    CRect tabRect, itemRect;
    int nX, nY, nXc, nYc;
 
    GetClientRect(&tabRect);
    GetItemRect(0, &itemRect);
 
    nX=itemRect.left;
    nY=itemRect.bottom+1;
    nXc=tabRect.right-itemRect.left-1;
    nYc=tabRect.bottom-nY-1;
 
    m_Dialog[0]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_SHOWWINDOW);
    for(int nCount=1; nCount < m_nPageCount; nCount++){
        m_Dialog[nCount]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_HIDEWINDOW);
    }
 
}
 
 
 
 
 
 
 
BOOL tabControl::PreTranslateMessage(MSG* pMsg)
{
    // TODO: Add your specialized code here and/or call the base class
 
   
    return CTabCtrl::PreTranslateMessage(pMsg);
}
 
 
 
 
 
void tabControl::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    if(m_tabCurrent != GetCurFocus()){
    m_Dialog[m_tabCurrent]->ShowWindow(SW_HIDE);
    m_tabCurrent=GetCurFocus();
    m_Dialog[m_tabCurrent]->ShowWindow(SW_SHOW);
    m_Dialog[m_tabCurrent]->SetFocus();
    }
 
 
 
    CTabCtrl::OnLButtonDown(nFlags, point);
}
 
 
void tabControl::OnClose()
{
    // TODO: Add your message handler code here and/or call default
    //m_Dialog[0]->ShowWindow(SW_HIDE);
    //m_Dialog[1]->ShowWindow(SW_HIDE);
    //m_Dialog[2]->ShowWindow(SW_HIDE);
    //m_Dialog[3]->ShowWindow(SW_HIDE);
    CTabCtrl::OnClose();
}
 
 
void tabControl::OnDestroy()
{
    CTabCtrl::OnDestroy();
     
    // TODO: Add your message handler code here
}