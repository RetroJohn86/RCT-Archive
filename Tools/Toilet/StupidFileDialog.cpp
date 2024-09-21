// StupidFileDialog.cpp : implementation file
//

#include "stdafx.h"
#include "toilet.h"
#include "StupidFileDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStupidFileDialog

IMPLEMENT_DYNAMIC(CStupidFileDialog, CFileDialog)

CStupidFileDialog::CStupidFileDialog(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd) :
		CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
}


BEGIN_MESSAGE_MAP(CStupidFileDialog, CFileDialog)
	//{{AFX_MSG_MAP(CStupidFileDialog)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

