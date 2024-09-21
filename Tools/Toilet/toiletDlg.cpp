// toiletDlg.cpp : implementation file
//

#include "stdafx.h"
#include "toilet.h"
#include "toiletDlg.h"
#include "tweak.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//#define DEBUG_MSG 1

#define HEADER_SIZE 21
enum {TYPE_RIDE = 0, TYPE_PATH = 5};

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToiletDlg dialog

CToiletDlg::CToiletDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CToiletDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CToiletDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CToiletDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToiletDlg)
	DDX_Control(pDX, IDC_TRANS, m_Trans);
	DDX_Control(pDX, IDC_DIRECTORY, m_Directory);
	DDX_Control(pDX, IDC_DESC, m_Desc);
	DDX_Control(pDX, IDC_NAME, m_Name);
	DDX_Control(pDX, IDC_BUILD_FILE, m_BuildFile);
	DDX_Control(pDX, IDC_FILENAME, m_FileName);
	DDX_Control(pDX, IDC_RADIO1, m_Radio1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CToiletDlg, CDialog)
	//{{AFX_MSG_MAP(CToiletDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOAD, OnLoad)
	ON_BN_CLICKED(IDC_PROCESS, OnProcess)
	ON_BN_CLICKED(IDC_DIS, OnDis)
	ON_BN_CLICKED(IDC_SET_DIR, OnSetDir)
	ON_BN_CLICKED(IDC_INVERT, OnInvert)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck5)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck6)
	ON_BN_CLICKED(IDC_CHECK7, OnCheck7)
	ON_BN_CLICKED(IDC_CHECK8, OnCheck8)
	ON_BN_CLICKED(IDC_CHECK9, OnCheck9)
	ON_BN_CLICKED(IDC_CHECK10, OnCheck10)
	ON_BN_CLICKED(IDC_CHECK11, OnCheck11)
	ON_BN_CLICKED(IDC_CHECK12, OnCheck12)
	ON_BN_CLICKED(IDC_CHECK13, OnCheck13)
	ON_BN_CLICKED(IDC_CHECK14, OnCheck14)
	ON_BN_CLICKED(IDC_CHECK15, OnCheck15)
	ON_BN_CLICKED(IDC_CHECK16, OnCheck16)
	ON_BN_CLICKED(IDC_CHECK17, OnCheck17)
	ON_BN_CLICKED(IDC_BMPS, OnBmps)
	ON_BN_CLICKED(IDC_CHECK18, OnCheck18)
	ON_BN_CLICKED(IDC_CHECK19, OnCheck19)
	ON_BN_CLICKED(IDC_CHECK21, OnCheck21)
	ON_BN_CLICKED(IDC_CHECK20, OnCheck20)
	ON_BN_CLICKED(IDC_CHECK22, OnCheck22)
	ON_BN_CLICKED(IDC_CHECK23, OnCheck23)
	ON_BN_CLICKED(IDC_CHECK24, OnCheck24)
	ON_BN_CLICKED(IDC_CHECK25, OnCheck25)
	ON_BN_CLICKED(IDC_CHECK26, OnCheck26)
	ON_BN_CLICKED(IDC_CHECK27, OnCheck27)
	ON_BN_CLICKED(IDC_CHECK28, OnCheck28)
	ON_BN_CLICKED(IDC_CHECK29, OnCheck29)
	ON_BN_CLICKED(IDC_CHECK30, OnCheck30)
	ON_BN_CLICKED(IDC_CHECK31, OnCheck31)
	ON_BN_CLICKED(IDC_CHECK32, OnCheck32)
	ON_BN_CLICKED(IDC_CHECK33, OnCheck33)
	ON_BN_CLICKED(IDC_CHECK34, OnCheck34)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_TWRIDE, OnTwride)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToiletDlg message handlers

BOOL CToiletDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//m_BuildFile.SetWindowText("SHOP#MKY");
	m_Invert = false;

	for (int i = 0; i < NUM_COLORS; i++)
		m_colorChange[i] = m_colorChange2[i] = false;

	m_objectType = TYPE_RIDE;

	m_Radio1.SetCheck(1);

	SetWindowText("RideMaker v2.1");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CToiletDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CToiletDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CToiletDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CToiletDlg::OnLoad() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fd(true);

	if (fd.DoModal())
	{
		CString str = fd.GetPathName();
		str = str.Left(str.Find(fd.GetFileName()));
		m_Directory.SetWindowText(str);
		m_FileName.SetWindowText(fd.GetFileName());
	}
	
}

void CToiletDlg::RLEDecode() 
{
	CString dir,str;
	CFile fp;
	CFile outFile;

	m_FileName.GetWindowText(str);
	m_Directory.GetWindowText(dir);

	if (fp.Open(dir + str,CFile::modeRead | CFile::typeBinary))
	if (outFile.Open(dir + "outfile.bin", CFile::modeCreate | CFile::modeWrite | CFile::typeBinary))
	{  
		char num;

		//the first 21 bytes are not encoded.
		char by[HEADER_SIZE];
		fp.Read(by,HEADER_SIZE);
		outFile.Write(by,HEADER_SIZE);

		char isCompressed = by[0x10];

		if (isCompressed)
		{
			while (fp.Read(&num,1) > 0 )
			{

  			if (num >= 0) // copy this many bytes + 1
				{
					int sz = num;
					sz++;
					char bytes[256];
							
					fp.Read(&bytes,sz);
					outFile.Write(&bytes,sz);

				}
				else //repeat this byte (1- this byte times)
				{
					num = 1 - num;
					char b;

					fp.Read(&b,1);
					for (; num > 0; num--)
						outFile.Write(&b,1);

				}
			} // end while
		}
		else
		{
			while (fp.Read(&num,1) > 0 )
				outFile.Write(&num,1);
		}

		fp.Close();
		outFile.Close();
	}

	MessageBox("Finished","Ridemaker");

}

char CToiletDlg::CountContinuous(char *bytes, long size) 
{
	char total = 0;

	for (total = 1; total < size && bytes[total] == bytes[0] && total < 127; total++);
	
	return total;
}

char CToiletDlg::CountDiscontinuous(char *bytes, long size) 
{
	char total = 0;

	for (total = 1; total < size && bytes[total] != bytes[total - 1] && total < 127; total++);
	
	return max(1,total - 1);
}

long CToiletDlg::RotateLeft(long num, long amt)
{
	for (;amt > 0; amt--)
	{
		if (0x80000000 & num)
		{
			num = num << 1;
			num = num | 0x00000001;
		}
		else
		{
			num = num << 1;
			num = num & 0xFFFFFFFE;
		}
	}

	return num;

}

void CToiletDlg::RLEEncode() 
{
	CString str,dir;
	CFile inFile;
	CFile outFile;

	long checksum = 0xF369A75B;

	m_Trans.GetWindowText(str);
	m_TransColor = atoi(str.GetBuffer(0));
	str.ReleaseBuffer();
	
	m_BuildFile.GetWindowText(str);
	m_Directory.GetWindowText(dir);

	if (str.GetLength() > 8)
		str = str.Left(8);
	if (str.GetLength() > 0) 
	if (inFile.Open(dir + "outfile.bin",CFile::modeRead | CFile::typeBinary))
	if (outFile.Open(dir + str+".DAT", CFile::modeCreate | CFile::modeWrite | CFile::typeBinary))
	{  
		char num;
		long i;

#ifdef DEBUG_MSG
	MessageBox("File Opened");
#endif

		//the first 21 bytes are not encoded.
		//but we must account for the checksum
		// and the file length
		char by[HEADER_SIZE];
		inFile.Read(by,HEADER_SIZE);

#ifdef DEBUG_MSG
	MessageBox("Read Header");
#endif

		by[0] = m_objectType;
		by[0x10] = 1;
		memset(&(by[4]),' ',8);
		memcpy(&(by[4]),str.GetBuffer(0),str.GetLength());
		str.ReleaseBuffer();

#ifdef DEBUG_MSG
	MessageBox("Copied Header");
#endif

		//rle the rest of the file.
		mSize = inFile.GetLength() - HEADER_SIZE;
		mBytes = new char[mSize];
		inFile.Read(mBytes,mSize);

	  //set the animation width and height to 255
	  mBytes[0x28] = 255;
	  mBytes[0x29] = 255;
	  mBytes[0x2A] = 255;

		m_Name.GetWindowText(str);
		if (str.GetLength() > 0)
		for (i= 0; i <= 13; i++)
			InsertString(0,i,str);

#ifdef DEBUG_MSG
	MessageBox("Built First String Table");
#endif

		if (m_objectType == TYPE_RIDE)
		{
			m_Desc.GetWindowText(str);
			if (str.GetLength() > 0)
			for (i= 0; i < 13; i++)
				InsertString(1,i,str);

#ifdef DEBUG_MSG
	MessageBox("Built Second String Table");
#endif

		  unsigned char rid = mBytes[0x025];
			rid &= 0x7F;
		  str.Format("%d Riders",rid);
			for (i= 0; i < 13; i++)
				InsertString(2,i,str);

		}

	

		ProcessGraphics();

#ifdef DEBUG_MSG
	MessageBox("Beginning Checksum");
#endif

		long checksum = 0xF369A75B;
		char *myby = (char *)(&checksum);

		*myby ^= by[0];
		checksum = RotateLeft(checksum, 11);

		for (num = 4; num < 12; num++)
		{
			*myby ^= by[num];
			checksum = RotateLeft(checksum, 11);
		}

		for (i = 0; i < mSize; i++)
		{
			*myby ^= mBytes[i];
			checksum = RotateLeft(checksum, 11);
		}

		memcpy(&(by[12]),&checksum,4);

#ifdef DEBUG_MSG
	MessageBox("Finished Checksum");
#endif

		outFile.Write(by,HEADER_SIZE);

#ifdef DEBUG_MSG
	MessageBox("Written Header -- Writing File ");
#endif

		for (i = 0; i < mSize; )
		{
			num = CountContinuous(&(mBytes[i]), mSize - i);
			if (num > 1) // repeat the bytes
			{
				char n2 = 1 - num;
				outFile.Write(&n2,1);
				outFile.Write(&(mBytes[i]),1);
				i += num;
			}
			else  //write x bytes
			{
				num = CountDiscontinuous(&(mBytes[i]), mSize - i);
				char n2 = num - 1;
				outFile.Write(&n2,1);
				outFile.Write(&(mBytes[i]),num);
				i += num;
			}
			str.Format("Written %d out of %d",i, mSize);

		}

#ifdef DEBUG_MSG
	MessageBox("Written File");
#endif

		inFile.Close();
		outFile.Close();

		//File Size
		m_BuildFile.GetWindowText(str);
		m_Directory.GetWindowText(dir);
		if (outFile.Open(dir + str + ".DAT", CFile::modeWrite | CFile::typeBinary))
		{  
			mSize = outFile.GetLength() - HEADER_SIZE;
			outFile.Seek(17,CFile::begin);
			outFile.Write(&mSize,4);
			outFile.Close();
#ifdef DEBUG_MSG
	MessageBox("Written File Size ");
#endif

		}

	}
}

void CToiletDlg::InsertString(char string_table, char num, CString str)
{
	long pos = 0x000001C2;
	char i;

	if (m_objectType == TYPE_RIDE)
	{
		pos = 0x000001C2;
	}

	if (m_objectType == TYPE_PATH)
	{
		pos = 0x0000000E;
	}

	//start of string table
	for (i = 0; i < string_table; i++,pos+=2)
	for (pos++; !(mBytes[pos] == 0 && mBytes[pos+1] == -1) && pos < mSize; pos++);

	//start of string num
	bool found_it = false;
	for (i = 0; mBytes[pos+1] != -1 && !found_it; i++,pos++)
	{
		if (mBytes[pos] == num)
			found_it = true;
		else
			for (pos++; mBytes[pos] != 0 && pos < mSize; pos++);
	}

	if (!found_it)
		return;

	//get old string pos
	long string_end;
	for (string_end = pos + 1; mBytes[string_end] != 0 && string_end < mSize; string_end++);

	long newsize = pos + str.GetLength() + (mSize - string_end);

	char * b1 = new char[newsize];
	memcpy(b1,mBytes,pos);
	strcpy(&(b1[pos]),str.GetBuffer(0));
	memcpy(&(b1[pos + str.GetLength()]),&(mBytes[string_end]),(mSize - string_end));

	delete mBytes;
	mBytes = new char[newsize];
	memcpy(mBytes,b1,newsize);
	mSize = newsize;
	delete b1;
}

unsigned char CToiletDlg::CountZeros(unsigned char *bytes, unsigned char size) 
{
	unsigned char total = 0;

	for (total = 0; total < size && bytes[total] == m_TransColor  && total < 127; total++);
	
	return total;
}

unsigned char CToiletDlg::CountNonZeros(unsigned char *bytes, unsigned char size) 
{
	unsigned char total = 0;

	for (total = 0; total < size && bytes[total] != m_TransColor && total < 127; total++);
	
	return total;
}

bool CToiletDlg::IsFinal(unsigned char *bytes, long size) 
{
	unsigned char total = 0;

	for (total = 0; total < size && bytes[total] == m_TransColor; total++);
	
	return total == size;
}

unsigned char CToiletDlg::FindNearestColor(RGBQUAD color)
{
	#include "pal.h"

	int big_diff = 9999;
	unsigned char index = 0;
	for (unsigned char i = 0; i < PAL_SIZE && big_diff > 0; i++)
	{
		int diff = abs(pal[i].rgbRed - color.rgbRed) +  abs(pal[i].rgbGreen - color.rgbGreen) +  abs(pal[i].rgbBlue - color.rgbBlue);
		if (diff < big_diff)
		{
			big_diff = diff;
			index = i;
		}
	}

	return index;
}

unsigned char * CToiletDlg::LoadBitmap(CString bit_file, BITMAPFILEHEADER &bmfh, BITMAPINFOHEADER &bmih)
{
	//start with loading the bitmap.
	CFile bmp;
	CString str;
	unsigned char *aBitmapBits;
	unsigned char *bb;
	long realWidth;
	int numColors = 0;
	RGBQUAD entries[256];
	unsigned long tpos;

	if (!bmp.Open(bit_file,CFile::modeRead | CFile::typeBinary))
		return 0;

	bmp.Read(&bmfh,sizeof(BITMAPFILEHEADER));
	bmp.Read(&bmih,sizeof(BITMAPINFOHEADER));

	realWidth = (bmih.biWidth + 3) / 4;
	realWidth *= 4;

	if (bmih.biBitCount <= 8)
	{
			numColors = bmih.biClrUsed ? bmih.biClrUsed : 256;
			bmp.Read(entries,numColors * sizeof(RGBQUAD));
	}

	bmp.Seek(bmfh.bfOffBits,CFile::begin);
	unsigned long len = bmp.GetLength() - bmfh.bfOffBits;
	aBitmapBits = new unsigned char[len];
	bmp.Read(aBitmapBits,len);

	bmp.Close();

	if (bmih.biBitCount == 8)
	{
		  for (long i = 0; i < len; i++)
			{
				aBitmapBits[i] = FindNearestColor(entries[aBitmapBits[i]]);
			}
	}

	if (bmih.biBitCount == 24)
	{
		len = bmih.biHeight * bmih.biWidth;
		bb = new unsigned char[len];
		//memset(bb,0,len);
		for (long bit_y = 0; bit_y < bmih.biHeight; bit_y++)
		for (long bit_x = 0; bit_x < realWidth; bit_x++)
    {
			RGBQUAD rgb;
			tpos = (bit_y * realWidth) + (bit_x);
			unsigned long tpos2 = tpos * 3;
			rgb.rgbBlue = aBitmapBits[tpos2];
			rgb.rgbGreen = aBitmapBits[tpos2+1];
			rgb.rgbRed = aBitmapBits[tpos2+2];
			rgb.rgbReserved = 0; //bmp.aBitmapBits[tpos+3];
			bb[tpos] = FindNearestColor(rgb);
		}
		delete [] aBitmapBits;
		aBitmapBits = bb;
	}

	return aBitmapBits;
}

void CToiletDlg::InsertBitmap(int bit_num, CString bit_file)
{
	BITMAPFILEHEADER    bmfh;
	BITMAPINFOHEADER    bmih;
	unsigned char       *aBitmapBits;

	//start with loading the bitmap.
	CString dir,str;

	//get to start of the bitmaps.
	long pos = m_bitPos;
	long i;

	m_Directory.GetWindowText(dir);
	
  aBitmapBits = LoadBitmap(dir+bit_file,bmfh,bmih);
	if (!aBitmapBits)
	{
		return;
	}

	short xoff,yoff; 

	CStdioFile coords;
	if (!coords.Open(dir + "pos.txt",CFile::modeRead))
		return;

	for (i = 0; i <= bit_num; i++)
		coords.ReadString(str);

	coords.Close();

	sscanf(str.GetBuffer(0),"%d,%d",&xoff,&yoff);
	str.ReleaseBuffer();

	unsigned long num_images;
	memcpy(&num_images,&(mBytes[pos]),4);
  pos += 4;

	//these need to be read in
	//length of scan lines
	unsigned long scan_len = pos;
	pos += 4;

	//16 byte records
	TGraphicRecord *pix;
	unsigned short *pixsize;
	unsigned long pixpos;

	pix = new TGraphicRecord[num_images];
	pixsize = new unsigned short[num_images];

	// get second offset
	pixpos = pos;
	memcpy(pix,&(mBytes[pos]),16*num_images);
	for (i = 0; i < num_images; i++, pos+=16)
		pixsize[i] = (i < num_images - 1) ? pix[i+1].StartAddress - pix[i].StartAddress : mSize - pix[i].StartAddress;

	if (pix[bit_num].Flags == 1)  // uncompressed
	{
		//flip the image
		char *bBitmapBits;
		bBitmapBits = new char[bmih.biHeight * bmih.biWidth];
		unsigned short newWidth = (bmih.biWidth % 4 > 0) ? ((bmih.biWidth / 4) + 1) * 4 : bmih.biWidth;
		for (i = 0; i < bmih.biHeight; i++)
		{
			long bitpos = (bmih.biHeight - i - 1) * newWidth;
			memcpy(&bBitmapBits[bmih.biWidth * i],&aBitmapBits[bitpos],bmih.biWidth);
		}
		
		long end_offset = (bit_num < num_images - 1) ? pos + pix[bit_num+1].StartAddress : mSize;
		char *b1;
		long newsize = pos + pix[bit_num].StartAddress + (bmih.biHeight * bmih.biWidth) + (mSize - end_offset);

		b1 = new char[newsize];
		memcpy(b1,mBytes,pos + pix[bit_num].StartAddress);
		memcpy(&(b1[pos + pix[bit_num].StartAddress]),bBitmapBits,(bmih.biHeight * bmih.biWidth));

		pix[bit_num].Height = bmih.biHeight;
		pix[bit_num].Width = bmih.biWidth;
		pix[bit_num].Xoffset = xoff;
		pix[bit_num].Yoffset = yoff;

		if (bit_num < num_images - 1)
		{
			memcpy(&b1[pos + pix[bit_num].StartAddress + (bmih.biHeight * bmih.biWidth)],&mBytes[pos + pix[bit_num+1].StartAddress],mSize - end_offset);
			pix[bit_num+1].StartAddress = pix[bit_num].StartAddress + (bmih.biHeight * bmih.biWidth);
			for (int k = bit_num + 2; k < num_images; k++)
				pix[k].StartAddress = pix[k-1].StartAddress + pixsize[k-1];
		}
		delete mBytes;
		mBytes = new char[newsize];
		memcpy(mBytes,b1,newsize);
		memcpy(&mBytes[pixpos],pix,16*num_images);
		mSize = newsize;

		//size of all pictures
		newsize = newsize - (pos + pix[0].StartAddress);
		memcpy(&mBytes[scan_len],&newsize,4);

		delete b1;
		delete bBitmapBits;
	} // uncompressed

  if (pix[bit_num].Flags == 5)  // compressed
	{
		unsigned short newWidth = (bmih.biWidth % 4 > 0) ? ((bmih.biWidth / 4) + 1) * 4 : bmih.biWidth;

		unsigned short newpos = 0;
		unsigned short bitpos = 0;
		char *bBitmapBits;
		bBitmapBits = new char[bmfh.bfSize * 10];
		unsigned short *offsets;
		offsets = new unsigned short[bmih.biHeight];
		for (i = 0; i < bmih.biHeight; i++)
		{
			 offsets[i] = newpos + (bmih.biHeight * 2);
			 unsigned char lineoff = 0;
			 bitpos = (bmih.biHeight - i - 1) * newWidth;
			 bool isFinalinRow = false;
			 while (!isFinalinRow)
			 {
				 lineoff += CountZeros(&(aBitmapBits[bitpos+lineoff]), bmih.biWidth);
				 unsigned char mylen = CountNonZeros(&(aBitmapBits[bitpos+lineoff]), bmih.biWidth-lineoff);
				 isFinalinRow = IsFinal(&(aBitmapBits[bitpos+lineoff+mylen]), bmih.biWidth-(lineoff+mylen));

				 bBitmapBits[newpos]= (isFinalinRow) ? mylen | 0x80 : mylen;
				 bBitmapBits[newpos+1]=lineoff;
				 memcpy(&(bBitmapBits[newpos+2]),&(aBitmapBits[bitpos + lineoff]),mylen);
				 newpos += mylen + 2;

				 lineoff = lineoff + mylen;
			 }

			 bitpos -= newWidth;
		}
/*		{
			 offsets[i] = newpos + (bmih.biHeight * 2);
			 char mylen = min(i+1,bmih.biWidth);
			 bBitmapBits[newpos]= mylen | 0x80;
			 bBitmapBits[newpos+1]=0;
			 memset(&(bBitmapBits[newpos+2]),mylen,mylen);
			 newpos += mylen + 2;	 
		}*/

		//now, remove the old and insert the new.
		unsigned long end_offset = (bit_num < num_images - 1) ? pos + pix[bit_num+1].StartAddress : mSize;
		char *b1;
		unsigned long newsize = pos + pix[bit_num].StartAddress + (bmih.biHeight * 2) + newpos + (mSize - end_offset);

		b1 = new char[newsize];
		memcpy(b1,mBytes,pos + pix[bit_num].StartAddress);
		memcpy(&(b1[pos + pix[bit_num].StartAddress]),offsets,(bmih.biHeight * 2));
		memcpy(&b1[pos + pix[bit_num].StartAddress + (bmih.biHeight * 2)],bBitmapBits,newpos);

		pix[bit_num].Height = bmih.biHeight;
		pix[bit_num].Width = bmih.biWidth;
		pix[bit_num].Xoffset = xoff;
		pix[bit_num].Yoffset = yoff;

		if (bit_num < num_images - 1)
		{
			memcpy(&b1[pos + pix[bit_num].StartAddress + (bmih.biHeight * 2) + newpos],&mBytes[pos + pix[bit_num+1].StartAddress],mSize - end_offset);
			pix[bit_num+1].StartAddress = pix[bit_num].StartAddress + (bmih.biHeight * 2) + newpos;
			for (int k = bit_num + 2; k < num_images; k++)
				pix[k].StartAddress = pix[k-1].StartAddress + pixsize[k-1];
		}

		delete mBytes;
		mBytes = new char[newsize];
		memcpy(mBytes,b1,newsize);
		memcpy(&mBytes[pixpos],pix,16*num_images);
		mSize = newsize;

		//size of all pictures
		newsize = newsize - (pos + pix[0].StartAddress);
		memcpy(&mBytes[scan_len],&newsize,4);

		delete b1;

		delete bBitmapBits;
		delete offsets;
	}

	delete pix;
	delete pixsize;
	delete aBitmapBits;

}
	
void CToiletDlg::SetBitPos()
{

	//get to end of each string table.
	long pos = 0x000001C2;
	long i, numstr;

	if (m_objectType == TYPE_RIDE)
	{
		pos = 0x000001C2;
		numstr = 3;
	}

	if (m_objectType == TYPE_PATH)
	{
		pos = 0x0000000E;
		numstr = 1;
	}

	//end of third string table
	for (i = 0; i < numstr; i++)
	for (pos++; !(mBytes[pos] == 0 && mBytes[pos+1] == -1) && pos < mSize; pos++);
	
	pos += 2;

	if (m_objectType == TYPE_RIDE)
	{
		//3 byte structures;
		for (i = (mBytes[pos] == - 1)?32:mBytes[pos] ; i > 0; i--, pos+=3);
		pos += 1; 

		// four (variable length) structures
		for (i = 0 ; i < 4; i++)
		{
			unsigned char len = mBytes[pos];
			if (len == 0xFF)
			{
				unsigned short len2;
				memcpy (&len2,&(mBytes[pos+ 1]),2);
				pos = pos + len2 + 3;
			}
			else
			{
				pos = pos + len + 1;
			}
		}
	} // end if

	m_bitPos = pos;
}

void CToiletDlg::ProcessGraphics()
{
	SetBitPos();

	long pos = m_bitPos;
	long i;

	long num_images;
	memcpy(&num_images,&(mBytes[pos]),4);
  pos += 4;

	CString str;
	for (i = 0; i < num_images; i++)
	{
			str.Format("pic%d.bmp",i);
			InsertBitmap(i,str);
			str.Format("pic0%d.bmp",i);
			InsertBitmap(i,str);
			str.Format("pic00%d.bmp",i);
			InsertBitmap(i,str);
			str.Format("pic000%d.bmp",i);
			InsertBitmap(i,str);
#ifdef DEBUG_MSG
	MessageBox("Inserted Bitmap:" + str);
#endif

	}
	//return;
	
	//length of scan lines
	pos += 4;

	//16 byte records
	TGraphicRecord *pix;

	pix = new TGraphicRecord[num_images];

	// get second offset
	for (i = 0; i < num_images; i++, pos+=16)
		memcpy(&(pix[i]),&(mBytes[pos]),16);

	for (int j = 0; j < num_images; j++)
	{
		if (pix[j].Flags == 1 && m_Invert) // simple bitmap.
		{
#ifdef DEBUG_MSG
	MessageBox("Inverting Image");
#endif

			long end_offset = (j < num_images - 1) ? pos + pix[j+1].StartAddress : mSize;

			for (i = pos + pix[j].StartAddress; i < end_offset; i++)
			{
				unsigned char num = mBytes[i];
				mBytes[i] = 255 - num;
			}
#ifdef DEBUG_MSG
	MessageBox("Done Inverting");
#endif

		}

		//start of images
		bool colorChange = false;

		for (i = 0; i < NUM_COLORS && !colorChange; i++)
			colorChange = colorChange | m_colorChange[i] | m_colorChange2[i];

		if (pix[j].Flags == 5 && colorChange) // compacted bitmap.
		{
			long cur_offset = pos + pix[j].StartAddress;
			for (i = 0; i < pix[j].Height; i++, cur_offset+=2)
			{
				unsigned short row_offset;
				memcpy(&row_offset,&mBytes[cur_offset],2);

				unsigned long mypos = pos + pix[j].StartAddress + row_offset;

				unsigned char len = 0;
				unsigned char off = 0;
				int tot = 0;

				bool last_one;

				do 
				{
					mypos += len;
					len = mBytes[mypos];
					off = mBytes[mypos+1];
					mypos += 2;

					last_one = len & 0x80;
					len = len & 0x7F;

					for (int k = 0; k < len; k++)
					{
						unsigned char mb = mBytes[mypos+k];
						for (int num = 0; num < NUM_COLORS; num++)
						{
							if (m_colorChange[num])
							if (mb >= COLOR_START + (num * COLOR_LEN) && mb < COLOR_START + ((num+1) * COLOR_LEN))
								mBytes[mypos+k] = 244 + mb - (COLOR_START + (num * COLOR_LEN));
							if (m_colorChange2[num])
							if (mb >= COLOR_START + (num * COLOR_LEN) && mb < COLOR_START + ((num+1) * COLOR_LEN))
								mBytes[mypos+k] = 202 + mb - (COLOR_START + (num * COLOR_LEN));
						}
					}


				} while (!last_one);

			} // for
		
		} // if 5

	} //something
	delete pix;
}

void CToiletDlg::ExtractBMP(int bit_num, CString bit_file)
{
	BITMAPFILEHEADER    bmfh;
	BITMAPINFOHEADER    bmih;

	#include "pal.h"
	
	long pos = m_bitPos;
	long i;

	long num_images;
	memcpy(&num_images,&(mBytes[pos]),4);
  pos += 4;

	//length of scan lines
	pos += 4;

	//16 byte records
	TGraphicRecord *pix;

	pix = new TGraphicRecord[num_images];

	// get second offset
	for (i = 0; i < num_images; i++, pos+=16)
		memcpy(&(pix[i]),&(mBytes[pos]),16);

	int tmp_width = pix[bit_num].Width;
	if (tmp_width % 4 > 0)
		tmp_width = ((tmp_width / 4) + 1) * 4;

	bmfh.bfType = 19778;
	bmfh.bfReserved1 = 0;
	bmfh.bfReserved2 = 0;
	bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (sizeof(RGBQUAD) * PAL_SIZE); 
	bmfh.bfSize = bmfh.bfOffBits + (tmp_width * pix[bit_num].Height);

	bmih.biSize = sizeof(BITMAPINFOHEADER);
	bmih.biWidth = pix[bit_num].Width;
	bmih.biHeight = pix[bit_num].Height;
	bmih.biPlanes = 1;
	bmih.biBitCount = 8;
	bmih.biCompression = 0;
	bmih.biSizeImage = 0;
	bmih.biXPelsPerMeter = 2834;
	bmih.biYPelsPerMeter = 2834;
	bmih.biClrUsed = PAL_SIZE; 
	bmih.biClrImportant = PAL_SIZE;

	CFile outFile;
	CString dir;

	m_Directory.GetWindowText(dir);
	outFile.Open(dir + bit_file, CFile::modeCreate | CFile::modeWrite | CFile::typeBinary);

	outFile.Write(&bmfh,sizeof(BITMAPFILEHEADER));
	outFile.Write(&bmih,sizeof(BITMAPINFOHEADER));
	outFile.Write(&pal,sizeof(RGBQUAD) * PAL_SIZE);

		if (pix[bit_num].Flags == 1) // simple bitmap.
		{
		  unsigned short newWidth = (pix[bit_num].Width % 4 > 0) ? ((pix[bit_num].Width / 4) + 1) * 4 : pix[bit_num].Width;
			unsigned char zero = 0;
			for (long j = pix[bit_num].Height - 1; j >= 0; j--)
			{
				long myoff = pos + pix[bit_num].StartAddress + (pix[bit_num].Width * j);
				outFile.Write(&(mBytes[myoff]), pix[bit_num].Width);
				for (int q = pix[bit_num].Width; q < newWidth; q++)
					outFile.Write(&zero,1);
			}

		}

		if (pix[bit_num].Flags == 5) // compacted bitmap.
		{
			long cur_offset = pos + pix[bit_num].StartAddress + (2 * (pix[bit_num].Height - 1));
			for (i = 0; i < pix[bit_num].Height; i++, cur_offset-=2)
			{
				short row_offset;
				memcpy(&row_offset,&mBytes[cur_offset],2);

				long mypos = pos + pix[bit_num].StartAddress + row_offset;

				unsigned char len = 0;
				unsigned char off = 0;
				int tot = 0;

				bool last_one;

				do 
				{
					mypos += len;
					len = mBytes[mypos];
					off = mBytes[mypos+1];
					mypos += 2;

					last_one = len & 0x80;
					len = len & 0x7F;

					for (unsigned char fn = tot; fn < off; fn++)
					{
						char tmp = 0;
						outFile.Write(&tmp,1);
					}
					outFile.Write(&mBytes[mypos],len);

					tot = off + len;

					if (last_one)
					{
							int final_num = pix[bit_num].Width;
							if (final_num % 4 > 0)
								final_num = ((final_num / 4) + 1) * 4;
							final_num = final_num - (tot);
							for (fn = 0; fn < final_num; fn++)
							{
								char tmp = 0;
								outFile.Write(&tmp,1);
							}

					} // if last one

			
				} while (!last_one);

			}
		}

		outFile.Close();

	delete pix;
} // extract bitmap

void CToiletDlg::RLEExtractBMPs() 
{
	CString str,dir;
	CFile inFile;

	m_BuildFile.GetWindowText(str);
	m_Directory.GetWindowText(dir);

	if (inFile.Open(dir + "outfile.bin",CFile::modeRead | CFile::typeBinary))
	{  
		long i;
		CStdioFile posFile;

		//the first 21 bytes are not encoded.
		//but we must account for the checksum
		// and the file length
		char by[HEADER_SIZE];
		inFile.Read(by,HEADER_SIZE);

		by[0] = 0;
		memset(&(by[4]),' ',8);
		memcpy(&(by[4]),str.GetBuffer(0),str.GetLength());

		//rle the rest of the file.
		mSize = inFile.GetLength() - HEADER_SIZE;
		mBytes = new char[mSize];
		inFile.Read(mBytes,mSize);
		inFile.Close();

		posFile.Open(dir + "pos.txt",CFile::modeWrite | CFile::modeCreate);

		SetBitPos();

		long pos = m_bitPos;

		long num_images;
		memcpy(&num_images,&(mBytes[pos]),4);

		pos+=8;

		for (i = 0; i < num_images; i++)
		{
			CString str, fstr;
			str.Format("%d",num_images);
			fstr.Format("%d",str.GetLength());
			fstr = "pic%." + fstr + "d.bmp";
			str.Format(fstr,i);
			ExtractBMP(i,str);
			short xoff, yoff;
			memcpy(&xoff, &mBytes[pos + 8],2);
			memcpy(&yoff, &mBytes[pos + 10],2);
			str.Format("%d,%d\n",xoff, yoff);
			posFile.WriteString(str);
			pos += 16;
		}

		delete mBytes;

		posFile.Close();

	}  // end if

	MessageBox("Finished","Ridemaker");

} //extract bmps


void CToiletDlg::OnProcess() 
{
	RLEEncode();

	MessageBox("Finished","Ridemaker");

}

void CToiletDlg::OnDis() 
{

	RLEDecode();
}

void CToiletDlg::OnBmps() 
{
	RLEExtractBMPs();
}


void CToiletDlg::OnSetDir() 
{
	CFileDialog fd(true);

	if (fd.DoModal())
	{
		CString str = fd.GetPathName();
		str = str.Left(str.Find(fd.GetFileName()));
		m_Directory.SetWindowText(str);
	}
}

void CToiletDlg::OnInvert() 
{
	m_Invert = !m_Invert;	
}

void CToiletDlg::OnCheck1() 
{
		m_colorChange[0] = !(m_colorChange[0]);
}

void CToiletDlg::OnCheck2() 
{
		m_colorChange[1] = !(m_colorChange[1]);
}

void CToiletDlg::OnCheck3() 
{
		m_colorChange[2] = !(m_colorChange[2]);
}

void CToiletDlg::OnCheck4() 
{
		m_colorChange[3] = !(m_colorChange[3]);
}

void CToiletDlg::OnCheck5() 
{
		m_colorChange[4] = !(m_colorChange[4]);
}

void CToiletDlg::OnCheck6() 
{
		m_colorChange[5] = !(m_colorChange[5]);
}

void CToiletDlg::OnCheck7() 
{
		m_colorChange[6] = !(m_colorChange[6]);
}

void CToiletDlg::OnCheck8() 
{
		m_colorChange[7] = !(m_colorChange[7]);
}

void CToiletDlg::OnCheck9() 
{
		m_colorChange[8] = !(m_colorChange[8]);
}

void CToiletDlg::OnCheck10() 
{
		m_colorChange[9] = !(m_colorChange[9]);
}

void CToiletDlg::OnCheck11() 
{
		m_colorChange[10] = !(m_colorChange[10]);
}

void CToiletDlg::OnCheck12() 
{
		m_colorChange[11] = !(m_colorChange[11]);
}

void CToiletDlg::OnCheck13() 
{
		m_colorChange[12] = !(m_colorChange[12]);
}

void CToiletDlg::OnCheck14() 
{
		m_colorChange[13] = !(m_colorChange[13]);
}

void CToiletDlg::OnCheck15() 
{
		m_colorChange[14] = !(m_colorChange[14]);
}

void CToiletDlg::OnCheck16() 
{
		m_colorChange[15] = !(m_colorChange[15]);
}

void CToiletDlg::OnCheck17() 
{
		m_colorChange[16] = !(m_colorChange[16]);
}

void CToiletDlg::OnCheck18() 
{
		m_colorChange2[0] = !(m_colorChange2[0]);
}

void CToiletDlg::OnCheck19() 
{
		m_colorChange2[1] = !(m_colorChange2[1]);
}

void CToiletDlg::OnCheck20() 
{
		m_colorChange2[2] = !(m_colorChange2[2]);
}

void CToiletDlg::OnCheck21() 
{
		m_colorChange2[3] = !(m_colorChange2[3]);
}

void CToiletDlg::OnCheck22() 
{
		m_colorChange2[4] = !(m_colorChange2[4]);
}

void CToiletDlg::OnCheck23() 
{
		m_colorChange2[5] = !(m_colorChange2[5]);
}

void CToiletDlg::OnCheck24() 
{
		m_colorChange2[6] = !(m_colorChange2[6]);
}

void CToiletDlg::OnCheck25() 
{
		m_colorChange2[7] = !(m_colorChange2[7]);
}

void CToiletDlg::OnCheck26() 
{
		m_colorChange2[8] = !(m_colorChange2[8]);
}

void CToiletDlg::OnCheck27() 
{
		m_colorChange2[9] = !(m_colorChange2[9]);
}

void CToiletDlg::OnCheck28() 
{
		m_colorChange2[10] = !(m_colorChange2[10]);
}

void CToiletDlg::OnCheck29() 
{
		m_colorChange2[11] = !(m_colorChange2[11]);
}

void CToiletDlg::OnCheck30() 
{
		m_colorChange2[12] = !(m_colorChange2[12]);
}

void CToiletDlg::OnCheck31() 
{
		m_colorChange2[13] = !(m_colorChange2[13]);
}

void CToiletDlg::OnCheck32() 
{
		m_colorChange2[14] = !(m_colorChange2[14]);
}

void CToiletDlg::OnCheck33() 
{
		m_colorChange2[15] = !(m_colorChange2[15]);
}

void CToiletDlg::OnCheck34() 
{
		m_colorChange2[16] = !(m_colorChange2[16]);
}

void CToiletDlg::OnRadio1() 
{
	 m_objectType = TYPE_RIDE;
}

void CToiletDlg::OnRadio2() 
{
	m_objectType = TYPE_PATH;
}

void CToiletDlg::OnTwride() 
{
	CTweak dlgTweak;
	CString str,dir;

	if (m_objectType != TYPE_RIDE)
  {
		MessageBox("Can only tweak rides");
		return;
	}

	m_Directory.GetWindowText(dir);

	dlgTweak.m_binFileName = dir + "outfile.bin";
  if (!dlgTweak.LoadBinFileHeader())
  {
		MessageBox("Could not open outfile bin.  Did you set the working directory and dissasemble the ride?");
		return;
	}
	
	dlgTweak.DoModal();

	dlgTweak.cleanup();

}
