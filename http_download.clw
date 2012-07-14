; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHttp_downloadDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "http_download.h"

ClassCount=3
Class1=CHttp_downloadApp
Class2=CHttp_downloadDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_HTTP_DOWNLOAD_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_HTTP_DOWNLOAD_DIALOG (English (U.S.))

[CLS:CHttp_downloadApp]
Type=0
HeaderFile=http_download.h
ImplementationFile=http_download.cpp
Filter=N

[CLS:CHttp_downloadDlg]
Type=0
HeaderFile=http_downloadDlg.h
ImplementationFile=http_downloadDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EXT

[CLS:CAboutDlg]
Type=0
HeaderFile=http_downloadDlg.h
ImplementationFile=http_downloadDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_HTTP_DOWNLOAD_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CHttp_downloadDlg

[DLG:IDD_HTTP_DOWNLOAD_DIALOG (English (U.S.))]
Type=1
Class=CHttp_downloadDlg
ControlCount=12
Control1=IDC_DIRECTORY,edit,1350631552
Control2=IDC_FILENAME,edit,1350631552
Control3=IDC_DOWNLOAD,button,1342242816
Control4=IDC_COUNT,edit,1350631552
Control5=IDC_START,edit,1350631552
Control6=IDC_STATIC,static,1342308354
Control7=IDC_STATIC,static,1342308354
Control8=IDC_STATIC,static,1342308354
Control9=IDC_STATIC,static,1342308354
Control10=IDC_STATUS,static,1342308352
Control11=IDC_EXT,edit,1350631552
Control12=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

