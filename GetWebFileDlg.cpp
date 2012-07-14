// GetWebFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GetWebFile.h"
#include "GetWebFileDlg.h"
#include "MyInternetSession.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CGetWebFileDlg dialog

CGetWebFileDlg::CGetWebFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetWebFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetWebFileDlg)
	m_strAddress = _T("");
	m_nPort = 80;
	m_strFileName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetWebFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetWebFileDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrlProgress);
	DDX_Control(pDX, IDC_EDIT3, m_strFileNameCtrl);
	DDX_Control(pDX, IDC_EDIT2, m_nPortCtrl);
	DDX_Control(pDX, IDC_EDIT1, m_strAddressCtrl);
	DDX_Text(pDX, IDC_EDIT1, m_strAddress);
	DDV_MaxChars(pDX, m_strAddress, 256);
	DDX_Text(pDX, IDC_EDIT2, m_nPort);
	DDV_MinMaxInt(pDX, m_nPort, 1, 65000);
	DDX_Text(pDX, IDC_EDIT3, m_strFileName);
	DDV_MaxChars(pDX, m_strFileName, 256);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGetWebFileDlg, CDialog)
	//{{AFX_MSG_MAP(CGetWebFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetWebFileDlg message handlers

BOOL CGetWebFileDlg::OnInitDialog()
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

void CGetWebFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGetWebFileDlg::OnDestroy()
{
	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGetWebFileDlg::OnPaint() 
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
HCURSOR CGetWebFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGetWebFileDlg::OnOK() 
{
	// TODO: Add extra validation here
	CMyInternetSession * pMySession = (CMyInternetSession *)AfxGetMainWnd();
	CString strServerName;
	CString strPort;
	CString strFileName;
	m_strAddressCtrl.GetWindowText(strServerName);
	m_nPortCtrl.GetWindowText(strPort);
	m_strFileNameCtrl.GetWindowText(strFileName);
	int nPort =  _ttoi(strPort);
	LPCTSTR pszAppName = "GetWebFile";
	CString Statustext;
	DWORD Status;
	Status = pMySession->GetWebFile(pszAppName, strServerName, nPort, strFileName);
	Statustext.Format("Status Code %d was returned.", Status);
	ShowStatus(Statustext);
}

void CGetWebFileDlg::ShowStatus(const CString &status)
{
	CEdit * pEdit = (CEdit*) GetDlgItem(IDC_EDIT4);
	CString strTemp = status;

	strTemp += "\r\n";
	
	int length = pEdit->GetWindowTextLength();
	
	pEdit->SetSel(length,length);
	
	pEdit->ReplaceSel(strTemp);
}

BOOL PeekAndPump()
{
	static MSG msg;

	while (::PeekMessage(&msg,NULL,0,0,PM_NOREMOVE)) {
		if (!AfxGetApp()->PumpMessage()) {
			::PostQuitMessage(0);
			return FALSE;
		}	
	}

	return TRUE;
}
