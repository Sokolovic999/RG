
// RG_LabVezba2.h : main header file for the RG_LabVezba2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CRGLabVezba2App:
// See RG_LabVezba2.cpp for the implementation of this class
//

class CRGLabVezba2App : public CWinApp
{
public:
	CRGLabVezba2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRGLabVezba2App theApp;
