
// RG_LabVezba1.h : main header file for the RG_LabVezba1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CRGLabVezba1App:
// See RG_LabVezba1.cpp for the implementation of this class
//

class CRGLabVezba1App : public CWinApp
{
public:
	CRGLabVezba1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRGLabVezba1App theApp;
