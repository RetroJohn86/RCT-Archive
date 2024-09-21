// toiletDlg.h : header file
//

#if !defined(AFX_TOILETDLG_H__CAB23497_0329_4588_99C6_F9A357509B54__INCLUDED_)
#define AFX_TOILETDLG_H__CAB23497_0329_4588_99C6_F9A357509B54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const int NUM_COLORS = 17;
const int COLOR_START = 22;
const int COLOR_LEN = 12;

struct TGraphicRecord
{
	long StartAddress;
	short Width, Height, Xoffset, Yoffset; // signed two byte variables
	short Flags; 
	short unused; // to pad the structure to 16 bytes
};



/////////////////////////////////////////////////////////////////////////////
// CToiletDlg dialog

class CToiletDlg : public CDialog
{
// Construction
public:
	CToiletDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CToiletDlg)
	enum { IDD = IDD_TOILET_DIALOG };
	CEdit	m_Trans;
	CEdit	m_Directory;
	CEdit	m_Desc;
	CEdit	m_Name;
	CEdit	m_BuildFile;
	CEdit	m_FileName;
	CButton m_Radio1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToiletDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CToiletDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLoad();
	afx_msg void OnProcess();
	afx_msg void OnDis();
	afx_msg void OnSetDir();
	afx_msg void OnInvert();
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	afx_msg void OnCheck5();
	afx_msg void OnCheck6();
	afx_msg void OnCheck7();
	afx_msg void OnCheck8();
	afx_msg void OnCheck9();
	afx_msg void OnCheck10();
	afx_msg void OnCheck11();
	afx_msg void OnCheck12();
	afx_msg void OnCheck13();
	afx_msg void OnCheck14();
	afx_msg void OnCheck15();
	afx_msg void OnCheck16();
	afx_msg void OnCheck17();
	afx_msg void OnBmps();
	afx_msg void OnCheck18();
	afx_msg void OnCheck19();
	afx_msg void OnCheck21();
	afx_msg void OnCheck20();
	afx_msg void OnCheck22();
	afx_msg void OnCheck23();
	afx_msg void OnCheck24();
	afx_msg void OnCheck25();
	afx_msg void OnCheck26();
	afx_msg void OnCheck27();
	afx_msg void OnCheck28();
	afx_msg void OnCheck29();
	afx_msg void OnCheck30();
	afx_msg void OnCheck31();
	afx_msg void OnCheck32();
	afx_msg void OnCheck33();
	afx_msg void OnCheck34();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnTwride();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	void RLEEncode();
	void RLEDecode();
	void RLEExtractBMPs();
	char CountContinuous(char *bytes, long size);
	char CountDiscontinuous(char *bytes, long size);
	long RotateLeft(long num, long amt);
	void ProcessGraphics();
	void InsertBitmap(int bit_num, CString bit_file);
	unsigned char CountZeros(unsigned char *bytes, unsigned char size); 
	unsigned char CountNonZeros(unsigned char *bytes, unsigned char size); 
	bool IsFinal(unsigned char *bytes, long size);
	void InsertString(char string_table, char num, CString str);
	void SetBitPos();
	void ExtractBMP(int bit_num, CString bit_file);

	char *mBytes;
	long mSize;
	long m_bitPos;
	bool m_Invert;
	bool m_colorChange[NUM_COLORS];
	bool m_colorChange2[NUM_COLORS];
	unsigned char m_objectType;
	char m_TransColor;

	unsigned char * LoadBitmap(CString bit_file, BITMAPFILEHEADER &bmfh, BITMAPINFOHEADER &bmih);
	unsigned char CToiletDlg::FindNearestColor(RGBQUAD color);


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOILETDLG_H__CAB23497_0329_4588_99C6_F9A357509B54__INCLUDED_)
