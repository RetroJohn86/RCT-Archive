#if !defined(AFX_TWEAK_H__0E25C8E6_DAF6_43C2_BF91_7493EA8EDC95__INCLUDED_)
#define AFX_TWEAK_H__0E25C8E6_DAF6_43C2_BF91_7493EA8EDC95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tweak.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTweak dialog

class CTweak : public CDialog
{
// Construction
public:
	CTweak(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTweak)
	enum { IDD = IDD_TWEAK };
	CButton	m_Pairs;
	CEdit	m_Special;
	CEdit	m_Riders;
	CButton	m_Remap3;
	CButton	m_Remap2;
	CButton	m_Remap;
	CButton	m_GetWet;
	CButton	m_Covered;
	CEdit	m_Nausea;
	CEdit	m_Intensity;
	CEdit	m_Excitement;
	CComboBox	m_rideType2;
	CComboBox	m_rideType1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTweak)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTweak)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	char *mBytes;
  void SetRideType(const char * str, char num);
	long GetFlag(long flag);
	void SetFlag(long flag);
	void ClearFlag(long flag);
public:
	
  CString m_binFileName;
  bool LoadBinFileHeader();
  void cleanup();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TWEAK_H__0E25C8E6_DAF6_43C2_BF91_7493EA8EDC95__INCLUDED_)
