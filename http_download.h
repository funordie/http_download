// http_download.h : main header file for the HTTP_DOWNLOAD application
//

#if !defined(AFX_HTTP_DOWNLOAD_H__0B6C14BF_A9BF_4759_9301_4A26B85B8377__INCLUDED_)
#define AFX_HTTP_DOWNLOAD_H__0B6C14BF_A9BF_4759_9301_4A26B85B8377__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHttp_downloadApp:
// See http_download.cpp for the implementation of this class
//

class CHttp_downloadApp : public CWinApp
{
public:
	CHttp_downloadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHttp_downloadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHttp_downloadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTTP_DOWNLOAD_H__0B6C14BF_A9BF_4759_9301_4A26B85B8377__INCLUDED_)
