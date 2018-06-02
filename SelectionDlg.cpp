// SelectionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test1.h"
#include "SelectionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectionDlg dialog


CSelectionDlg::CSelectionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectionDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSelectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectionDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectionDlg, CDialog)
	//{{AFX_MSG_MAP(CSelectionDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectionDlg message handlers
