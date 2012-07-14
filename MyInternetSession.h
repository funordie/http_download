// MyInternetSession.h: interface for the CMyInternetSession class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYINTERNETSESSION_H__67F1B46F_249C_11D6_B00A_0080C6F1016A__INCLUDED_)
#define AFX_MYINTERNETSESSION_H__67F1B46F_249C_11D6_B00A_0080C6F1016A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include <afxwin.h>
#include <afxinet.h>
#include <iostream.h>
#include <stdlib.h>

class CMyInternetSession : public CInternetSession  
{
public:
	
	int SetDownloadDirectory(CString strDirectory);
	CString GetDownloadDirectory();
	CMyInternetSession(LPCTSTR pszAppName = "GetHttpApp", int nMethod = 1, LPCTSTR pstrProxyName = "",	LPCTSTR pstrProxyBypass = "", DWORD dwFlags = NULL);

	virtual void OnStatusCallback(DWORD dwContext, 
								  DWORD dwInternetStatus,
								  LPVOID lpvStatusInformation, 
								  DWORD dwStatusInformationLength);

	DWORD GetWebFile(LPCTSTR pszAppName, 
					 LPCTSTR lpstrServer,
					 int nPort,
					 CString lpstrFileName);
private:
	CString m_strDownloadDirectory;
};

#endif // !defined(AFX_MYINTERNETSESSION_H__67F1B46F_249C_11D6_B00A_0080C6F1016A__INCLUDED_)
