// GetWebFile.h : main header file for the GETWEBFILE application
//

#if !defined(AFX_GETWEBFILE_H__36EEA3C5_25F6_11D6_B00A_0080C6F1016A__INCLUDED_)
#define AFX_GETWEBFILE_H__36EEA3C5_25F6_11D6_B00A_0080C6F1016A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetWebFileApp:
// See GetWebFile.cpp for the implementation of this class
//

class CGetWebFileApp : public CWinApp
{
public:
	CGetWebFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetWebFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetWebFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETWEBFILE_H__36EEA3C5_25F6_11D6_B00A_0080C6F1016A__INCLUDED_)
