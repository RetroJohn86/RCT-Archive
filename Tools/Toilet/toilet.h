// toilet.h : main header file for the TOILET application
//

#if !defined(AFX_TOILET_H__8990540C_CC2D_48B3_A279_4FA790D5643E__INCLUDED_)
#define AFX_TOILET_H__8990540C_CC2D_48B3_A279_4FA790D5643E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CToiletApp:
// See toilet.cpp for the implementation of this class
//

class CToiletApp : public CWinApp
{
public:
	CToiletApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToiletApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CToiletApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOILET_H__8990540C_CC2D_48B3_A279_4FA790D5643E__INCLUDED_)
