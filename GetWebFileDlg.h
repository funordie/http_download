// GetWebFileDlg.h : header file
//

#if !defined(AFX_GETWEBFILEDLG_H__36EEA3C7_25F6_11D6_B00A_0080C6F1016A__INCLUDED_)
#define AFX_GETWEBFILEDLG_H__36EEA3C7_25F6_11D6_B00A_0080C6F1016A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetWebFileDlg dialog
BOOL PeekAndPump();

class CGetWebFileDlg : public CDialog
{
// Construction
public:
	CGetWebFileDlg(CWnd* pParent = NULL);	// standard constructor
	void ShowStatus(const CString &status);
// Dialog Data
	//{{AFX_DATA(CGetWebFileDlg)
	enum { IDD = IDD_GETWEBFILE_DIALOG };
	CProgressCtrl	m_ctrlProgress;
	CEdit	m_strFileNameCtrl;
	CEdit	m_nPortCtrl;
	CEdit	m_strAddressCtrl;
	CString	m_strAddress;
	int		m_nPort;
	CString	m_strFileName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetWebFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetWebFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETWEBFILEDLG_H__36EEA3C7_25F6_11D6_B00A_0080C6F1016A__INCLUDED_)
