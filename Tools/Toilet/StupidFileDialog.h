#if !defined(AFX_STUPIDFILEDIALOG_H__A3C0D9DD_0A1D_4002_891A_AE64FA4B1AEF__INCLUDED_)
#define AFX_STUPIDFILEDIALOG_H__A3C0D9DD_0A1D_4002_891A_AE64FA4B1AEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StupidFileDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStupidFileDialog dialog

class CStupidFileDialog : public CFileDialog
{
	DECLARE_DYNAMIC(CStupidFileDialog)

public:
	CStupidFileDialog(BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL);

	  CString m_folderName;

protected:
	//{{AFX_MSG(CStupidFileDialog)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUPIDFILEDIALOG_H__A3C0D9DD_0A1D_4002_891A_AE64FA4B1AEF__INCLUDED_)
