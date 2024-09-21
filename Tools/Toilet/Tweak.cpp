// Tweak.cpp : implementation file
//

#include "stdafx.h"
#include "toilet.h"
#include "Tweak.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define HEADER_SIZE 0x1D7
enum {TYPE_RIDE = 0, TYPE_PATH = 5};

const T0_GET_WET  = 0x00000100; // guests get wet when they go on this ride (?)
const T0_COVERED  = 0x00000400; // indicates a "covered" ride - preferred when raining
const T0_NO_REMAP = 0x00080000; // prevent the user from being able to remap map 1 colors.


/////////////////////////////////////////////////////////////////////////////
// CTweak dialog


CTweak::CTweak(CWnd* pParent /*=NULL*/)
	: CDialog(CTweak::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTweak)
	//}}AFX_DATA_INIT
	mBytes = NULL;
}


void CTweak::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTweak)
	DDX_Control(pDX, IDC_PAIRS, m_Pairs);
	DDX_Control(pDX, IDC_SPECIAL, m_Special);
	DDX_Control(pDX, IDC_RIDERS, m_Riders);
	DDX_Control(pDX, IDC_REMAP3, m_Remap3);
	DDX_Control(pDX, IDC_REMAP2, m_Remap2);
	DDX_Control(pDX, IDC_REMAP, m_Remap);
	DDX_Control(pDX, IDC_GETWET, m_GetWet);
	DDX_Control(pDX, IDC_COVERED, m_Covered);
	DDX_Control(pDX, IDC_NAUSEA, m_Nausea);
	DDX_Control(pDX, IDC_INTENSITY, m_Intensity);
	DDX_Control(pDX, IDC_EXCITEMENT, m_Excitement);
	DDX_Control(pDX, IDC_COMBO2, m_rideType2);
	DDX_Control(pDX, IDC_COMBO1, m_rideType1);
	//}}AFX_DATA_MAP

	m_rideType1.SetCurSel(mBytes[0x01D3]);
	m_rideType2.SetCurSel(mBytes[0x01D4]);

	CString str;
	str.Format("%d",mBytes[0x01C7]);
	m_Excitement.SetWindowText(str);
	str.Format("%d",mBytes[0x01C8]);
	m_Intensity.SetWindowText(str);
	str.Format("%d",mBytes[0x01C8]);
	m_Nausea.SetWindowText(str);

	m_Covered.SetCheck(GetFlag(T0_COVERED));
	m_GetWet.SetCheck(GetFlag(T0_GET_WET));
	m_Remap.SetCheck(!(GetFlag(T0_NO_REMAP)));
	m_Remap2.SetCheck(mBytes[0x043] & 0x01);
	m_Remap3.SetCheck(mBytes[0x042] & 0x02);

	unsigned char rid = mBytes[0x03A];

	m_Pairs.SetCheck(rid & 0x80);

	rid &= 0x7F;
	str.Format("%d",rid);
	m_Riders.SetWindowText(str);

	str.Format("%d",mBytes[0x029]);
	m_Special.SetWindowText(str);

}


BEGIN_MESSAGE_MAP(CTweak, CDialog)
	//{{AFX_MSG_MAP(CTweak)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTweak message handlers
bool CTweak::LoadBinFileHeader()
{
	CString str,dir;
	CFile inFile;

	if (inFile.Open(m_binFileName,CFile::modeRead | CFile::typeBinary))
	{  

		//the first 21 bytes are not encoded.
		//but we must account for the checksum
		// and the file length
		mBytes = new char[HEADER_SIZE];
		inFile.Read(mBytes,HEADER_SIZE);
		inFile.Close();
  }
	else 
	{
		return false;
	}


	return true;
}

void CTweak::cleanup()
{
	delete [] mBytes;
	mBytes = NULL;
}


void CTweak::SetRideType(const char * str, char num)
{
	long pos = 0x01D3;

	if (strcmp(str,"Transportation") == 0)
		mBytes[pos + num] = 0;
	if (strcmp(str,"Gentle") == 0)
		mBytes[pos + num] = 1;
	if (strcmp(str,"Rollercoaster") == 0)
		mBytes[pos + num] = 2;
	if (strcmp(str,"Thrill") == 0)
		mBytes[pos + num] = 3;
	if (strcmp(str,"Water") == 0)
		mBytes[pos + num] = 4;
	if (strcmp(str,"Shop") == 0)
		mBytes[pos + num] = 5;
}

void CTweak::OnOK() 
{
	// TODO: Add extra validation here
	CString str,dir;
	CFile outFile;
	char num;

  m_rideType1.GetWindowText(str);
	SetRideType(str,0);
	m_rideType2.GetWindowText(str);
	SetRideType(str,1);

	m_Excitement.GetWindowText(str);
	num = atoi(str);
	mBytes[0x01C7] = num;

	m_Intensity.GetWindowText(str);
	num = atoi(str);
	mBytes[0x01C8] = num;

	m_Nausea.GetWindowText(str);
	num = atoi(str);
	mBytes[0x01C9] = num;

	m_Riders.GetWindowText(str);
	num = atoi(str);
	mBytes[0x03A] = num;

	m_Special.GetWindowText(str);
	num = atoi(str);
	mBytes[0x029] = num;

	if (m_Covered.GetCheck())
		SetFlag(T0_COVERED);
	else
		ClearFlag(T0_COVERED);

	if (m_GetWet.GetCheck())
		SetFlag(T0_GET_WET);
	else
		ClearFlag(T0_GET_WET);

	if (m_Remap.GetCheck())  //remap is special
		ClearFlag(T0_NO_REMAP);
	else
		SetFlag(T0_NO_REMAP);

	if (m_Remap2.GetCheck())  
		mBytes[0x043] |= 0x01;
	else
		mBytes[0x043] &= ~(0x01);

	if (m_Remap3.GetCheck())  
		mBytes[0x042] |= 0x02;
	else
		mBytes[0x042] &= ~(0x02);

	if (m_Pairs.GetCheck())  
		mBytes[0x03A] |= 0x80;

	if (outFile.Open(m_binFileName,CFile::modeWrite | CFile::typeBinary))
	{  

		outFile.Write(mBytes,HEADER_SIZE);
		outFile.Close();
  }
	
	CDialog::OnOK();
}

long CTweak::GetFlag(long flag)
{
	long flags = 0;
	memcpy(&flags,mBytes + 0x1D,4);
	return flags & flag;
}

void CTweak::SetFlag(long flag)
{
	long flags = 0;
	memcpy(&flags,mBytes + 0x1D,4);
	flags = flags | flag;
	memcpy(mBytes + 0x1D,&flags,4);
}

void CTweak::ClearFlag(long flag)
{
	long flags = 0;
	memcpy(&flags,mBytes + 0x1D,4);
	long revFlag = flag;
	revFlag = ~revFlag;
	flags = flags & revFlag;
	memcpy(mBytes + 0x1D,&flags,4);
}
