// http_downloadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "http_download.h"
#include "http_downloadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//my include files
#include <afxinet.h>
#include "MyInternetSession.h"
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
// CHttp_downloadDlg dialog

CHttp_downloadDlg::CHttp_downloadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHttp_downloadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHttp_downloadDlg)
	m_strDirectory = _T("");
	m_strFileName = _T("");
	m_count = 0;
	m_strMessage = _T("");
	m_start = 0;
	m_Status = _T("");
	m_strExt = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_strDirectory = "nasledie.enip.ras.ru/books/10076729";
	m_strFileName = "10076729_";
	m_start = 1;
	m_count = 483;
	m_strExt = ".tif";
}

void CHttp_downloadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHttp_downloadDlg)
	DDX_Text(pDX, IDC_DIRECTORY, m_strDirectory);
	DDX_Text(pDX, IDC_FILENAME, m_strFileName);
	DDX_Text(pDX, IDC_COUNT, m_count);
	DDX_Text(pDX, IDC_START, m_start);
	DDX_Text(pDX, IDC_STATUS, m_Status);
	DDX_Text(pDX, IDC_EXT, m_strExt);
	//}}AFX_DATA_MAP
}

#define WM_UPDATEFIELDS WM_APP + 1

BEGIN_MESSAGE_MAP(CHttp_downloadDlg, CDialog)
	//{{AFX_MSG_MAP(CHttp_downloadDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DOWNLOAD, OnDownload)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_UPDATEFIELDS, UpdateDisplay)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHttp_downloadDlg message handlers

BOOL CHttp_downloadDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHttp_downloadDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHttp_downloadDlg::OnPaint() 
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
HCURSOR CHttp_downloadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//tread global variables
unsigned int Start, Count;
CString strFileName, strDirectory, strExt;
CMyInternetSession * pMySession = NULL;
CHttp_downloadDlg * pMainDlg = NULL;

UINT DownloadTread(LPVOID pParam ) {
	
	CString Statustext;
	unsigned long Status;
	CString pszAppName = "GetApp";

	for(unsigned i = Start; i < Count; i++) {
		//compose filename
		
		CString strFileIndex;
		CString strServerName;
		CString strPathName;

		strFileIndex.Format("%04d", i);
		char ch[5];
		itoa(i,ch, 10);
		CString strName = strFileName + strFileIndex + strExt;
		CString str = strDirectory + '/' + strName;

		//get server name
		int sym = str.Find('.');
		sym = str.Find('/',sym);

		if(sym != 0) {
			strServerName = str.Left(sym);
		}

		//get file path name
		int len = str.GetLength();
		strPathName = str.Right(len-sym);

		//update main dialog status
		pMainDlg->m_Status.Format("Downloading file: %s", strName);
		pMainDlg->SendMessage(WM_UPDATEFIELDS, false);

		Status = pMySession->GetWebFile(pszAppName, strServerName, 80, strPathName);
	}

	return 0;
}

void CHttp_downloadDlg::OnDownload() 
{
	// TODO: Add your control notification handler code here

	UpdateData();

	pMySession = new CMyInternetSession();//(CMyInternetSession *)AfxGetMainWnd();

	//create download directory
	pMySession->SetDownloadDirectory("Download");

	//update global variables
	Start = m_start;
	Count = m_count;
	strFileName = m_strFileName;
	strDirectory = m_strDirectory;
	strExt = m_strExt;

	//save main dialog painter
	pMainDlg = this;

	HWND hWnd = GetSafeHwnd();
	AfxBeginThread(DownloadTread, hWnd, THREAD_PRIORITY_NORMAL);
}

void CHttp_downloadDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CHttp_downloadDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

LRESULT CHttp_downloadDlg::UpdateDisplay(WPARAM wParam, LPARAM lParam)
{
	UpdateData((BOOL)wParam);
	return 0;
}
