// http_downloadDlg.h : header file
//

#if !defined(AFX_HTTP_DOWNLOADDLG_H__CE1A4A54_4196_4728_8AAC_A5A20A2DA86B__INCLUDED_)
#define AFX_HTTP_DOWNLOADDLG_H__CE1A4A54_4196_4728_8AAC_A5A20A2DA86B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHttp_downloadDlg dialog

class CHttp_downloadDlg : public CDialog
{
// Construction
public:
	LRESULT UpdateDisplay(WPARAM wParam, LPARAM lParam);
	CHttp_downloadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHttp_downloadDlg)
	enum { IDD = IDD_HTTP_DOWNLOAD_DIALOG };
	CString	m_strDirectory;
	CString	m_strFileName;
	UINT	m_count;
	CString	m_strMessage;
	UINT	m_start;
	CString	m_Status;
	CString	m_strExt;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHttp_downloadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHttp_downloadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDownload();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTTP_DOWNLOADDLG_H__CE1A4A54_4196_4728_8AAC_A5A20A2DA86B__INCLUDED_)
