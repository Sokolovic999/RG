
// RG_LabVezba2View.h : interface of the CRGLabVezba2View class
//

#pragma once


class CRGLabVezba2View : public CView
{
protected: // create from serialization only
	CRGLabVezba2View() noexcept;
	DECLARE_DYNCREATE(CRGLabVezba2View)
	HENHMETAFILE light_cactus, dark_cactus;
	bool grid;
	float ugao1, ugao2;

// Attributes
public:
	CRGLabVezba2Doc* GetDocument() const;
	void CrtajGrid(CDC* pDC);
	void CrtajPozadinu(CDC* pDC);
	void CrtajSaksiju(CDC* pDC);
	void CrtajKaktus(CDC* pDC);
	void CrtajLeviKaktus(CDC* pDC);
	void CrtajSrednjiKaktus(CDC* pDC);
	void CrtajDesniKaktus(CDC* pDC);
	void IspisiIme(CDC* pDC);


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
	virtual ~CRGLabVezba2View();
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

#ifndef _DEBUG  // debug version in RG_LabVezba2View.cpp
inline CRGLabVezba2Doc* CRGLabVezba2View::GetDocument() const
   { return reinterpret_cast<CRGLabVezba2Doc*>(m_pDocument); }
#endif

