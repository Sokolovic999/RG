
// RG_LabVezba1View.h : interface of the CRGLabVezba1View class
//

#pragma once


class CRGLabVezba1View : public CView
{
protected: // create from serialization only
	CRGLabVezba1View() noexcept;
	DECLARE_DYNCREATE(CRGLabVezba1View)
	bool keyPress;

// Attributes
public:
	CRGLabVezba1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CRGLabVezba1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in RG_LabVezba1View.cpp
inline CRGLabVezba1Doc* CRGLabVezba1View::GetDocument() const
   { return reinterpret_cast<CRGLabVezba1Doc*>(m_pDocument); }
#endif

