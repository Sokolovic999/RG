
// RG_LabVezba1View.cpp : implementation of the CRGLabVezba1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "RG_LabVezba1.h"
#endif

#include "RG_LabVezba1Doc.h"
#include "RG_LabVezba1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;
# define M_PI           3.14159265358979323846
// CRGLabVezba1View

IMPLEMENT_DYNCREATE(CRGLabVezba1View, CView)

BEGIN_MESSAGE_MAP(CRGLabVezba1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CRGLabVezba1View construction/destruction

CRGLabVezba1View::CRGLabVezba1View() noexcept
{
	// TODO: add construction code here
	this->keyPress = true;
}

CRGLabVezba1View::~CRGLabVezba1View()
{
}

BOOL CRGLabVezba1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CRGLabVezba1View drawing

void CrtajGRid(CDC *pDC)
{
	CPen* newPen = new CPen(PS_SOLID, 0, RGB(192, 192, 192));
	CPen* oldPen = pDC->SelectObject(newPen);

	pDC->MoveTo(0, 0);
	pDC->LineTo(500, 0);
	pDC->LineTo(500, 500);
	pDC->LineTo(0, 500);
	pDC->LineTo(0, 0);

	for (int i = 25; i < 500; i += 25)
	{
		pDC->MoveTo(0, i);
		pDC->LineTo(500, i);
		pDC->MoveTo(i, 0);
		pDC->LineTo(i, 500);
	}

	pDC->SelectObject(oldPen);
	newPen->DeleteObject();
}



void CrtajOblik(CDC* pDC,CPoint* tacke,int count,COLORREF boja,int fill) {

	CPen* newPen = new CPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_SQUARE | PS_JOIN_ROUND, 5, RGB(0, 255, 255));
	CPen* oldPen = pDC->SelectObject(newPen);

	CBrush* brush;
	if (fill == 0)
		brush = new CBrush(boja);
	else
		brush = new CBrush(HS_BDIAGONAL, boja);
	CBrush* oldBrush = pDC->SelectObject(brush);
	
	pDC->Polygon(tacke,count);

	pDC->SelectObject(oldPen);
	newPen->DeleteObject();

	pDC->SelectObject(oldBrush);
	brush->DeleteObject();

}

void CrtajMnogougao(int brTemena, int x, int y,int r,CDC* pDC, int fill)
{
	double ugao = 2 * M_PI / brTemena;
	CPoint* temena = new CPoint[brTemena];
	for (int i = 0; i < brTemena; i++)
	{
		CPoint tacka( (int)(r*cos(i * ugao) + x), (int)(r*sin(i * ugao) + y));
		temena[i] = tacka;
	}

	CPen* newPen = new CPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_SQUARE | PS_JOIN_ROUND, 2, RGB(0, 255, 255));
	CPen* oldPen = pDC->SelectObject(newPen);

	CGdiObject* oldBrush = pDC->SelectStockObject(NULL_BRUSH);
	
	pDC->Polygon(temena, brTemena);

	pDC->SelectObject(oldPen);
	newPen->DeleteObject();

	pDC->SelectObject(oldBrush);

	delete[] temena;

}

void CRGLabVezba1View::OnDraw(CDC* pDC)
{
	CRGLabVezba1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	//Roze trougao
	CPoint* tacke{ new CPoint[3] {CPoint(25,220),CPoint(145,100),CPoint(145,340)} };
	CrtajOblik(pDC,tacke,3,RGB(255,153,255),0);
	delete[] tacke;
	//Ljubicasti trougao
	tacke = { new CPoint[3]{CPoint(145,100),CPoint(310,100),CPoint(145,263)} };
	CrtajOblik(pDC, tacke, 3,RGB(127, 0, 255), 0);
	delete[] tacke;
	//zeleni trougao
	tacke = { new CPoint[3]{CPoint(310,100),CPoint(310,220),CPoint(190,220)} };
	CrtajOblik(pDC, tacke, 3,RGB(0, 204, 0), 0);
	delete[] tacke;
	//Crveni cetvorougao
	tacke = { new CPoint[4]{CPoint(310,100),CPoint(390,100),CPoint(390,180),CPoint(310,180)} };
	CrtajOblik(pDC, tacke, 4,RGB(255, 0, 0), 0);
	delete[] tacke;
	//Srafiran trougao
	tacke = { new CPoint[3]{CPoint(390,100),CPoint(390,180),CPoint(470,180)} };
	CrtajOblik(pDC, tacke, 3, RGB(0, 102, 204), 1);
	delete[] tacke;
	//Narandzasti cetvorougao
	tacke = { new CPoint[4]{CPoint(310,220),CPoint(230,220),CPoint(310,300),CPoint(390,300)} };
	CrtajOblik(pDC, tacke, 4, RGB(255, 128, 0), 0);
	delete[] tacke;
	//Zuti trougao
	tacke = { new CPoint[3]{CPoint(125,400),CPoint(205,400),CPoint(125,320)} };
	CrtajOblik(pDC, tacke, 3, RGB(255, 255, 0), 0);
	delete[] tacke;
	
	//Mnogouglovi 
	CrtajMnogougao(4, 100, 220, 25, pDC, 0); //Cetvorougao unutar roze trougla
	CrtajMnogougao(5, 192, 150, 25, pDC, 0); // Petougao unutar ljubicastog trougla
	CrtajMnogougao(6, 148, 375, 13, pDC, 0); //Sestougao unutar zutog trougla
	CrtajMnogougao(8, 275, 183, 18, pDC, 0); //Osmougao unutar zelenog trougla
	CrtajMnogougao(7, 415, 155, 12, pDC, 1); // Sedmougao unutar srafiranog trougla


	//Grid se pali i gasi na space
	if(this->keyPress)
		CrtajGRid(pDC);
}


// CRGLabVezba1View printing

BOOL CRGLabVezba1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRGLabVezba1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRGLabVezba1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CRGLabVezba1View diagnostics

#ifdef _DEBUG
void CRGLabVezba1View::AssertValid() const
{
	CView::AssertValid();
}

void CRGLabVezba1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRGLabVezba1Doc* CRGLabVezba1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRGLabVezba1Doc)));
	return (CRGLabVezba1Doc*)m_pDocument;
}
#endif //_DEBUG


// CRGLabVezba1View message handlers


void CRGLabVezba1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	if (nChar == VK_SPACE)
	{
		this->keyPress = !this->keyPress;
		Invalidate();
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
