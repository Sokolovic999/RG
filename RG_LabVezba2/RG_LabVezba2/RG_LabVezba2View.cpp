
// RG_LabVezba2View.cpp : implementation of the CRGLabVezba2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "RG_LabVezba2.h"
#endif

#include "RG_LabVezba2Doc.h"
#include "RG_LabVezba2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
# define M_PI           3.14159265358979323846
#endif

// CRGLabVezba2View

IMPLEMENT_DYNCREATE(CRGLabVezba2View, CView)

BEGIN_MESSAGE_MAP(CRGLabVezba2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CRGLabVezba2View construction/destruction


CRGLabVezba2View::CRGLabVezba2View() noexcept
{
	// TODO: add construction code here
	grid = false;
	ugao1 = ugao2 =0;
	light_cactus = GetEnhMetaFile(CString("cactus_part_light.emf"));
	dark_cactus = GetEnhMetaFile(CString("cactus_part.emf"));

}

CRGLabVezba2View::~CRGLabVezba2View()
{
	DeleteEnhMetaFile(light_cactus);
	DeleteEnhMetaFile(dark_cactus);
}

BOOL CRGLabVezba2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CRGLabVezba2View drawing

void CRGLabVezba2View::CrtajGrid(CDC* pDC)
{
	CPen* newPen = new CPen(PS_SOLID, 1, RGB(255, 255, 255));
	CPen* oldPen = pDC->SelectObject(newPen);
	CObject* oldBrush = pDC->SelectStockObject(NULL_BRUSH);

	pDC->Rectangle(0, 0, 500, 500);

	for (int i = 25; i < 500; i += 25)
	{
		pDC->MoveTo(0, i);
		pDC->LineTo(500, i);
		pDC->MoveTo(i, 0);
		pDC->LineTo(i, 500);
	}


	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	newPen->DeleteObject();
}
void CRGLabVezba2View::CrtajPozadinu(CDC* pDC)
{
	CBrush* brush = new CBrush(RGB(135, 206, 235));
	CBrush* oldBrush = pDC->SelectObject(brush);
	pDC->Rectangle(0,0,500,500);
	pDC->SelectObject(oldBrush);
	brush->DeleteObject();
	
}
void CRGLabVezba2View::CrtajSaksiju(CDC* pDC)
{
	CBrush* brush = new CBrush(RGB(222, 148, 0));
	CBrush* oldBrush = pDC->SelectObject(brush);
	CPoint* tacke{ new CPoint[8] {CPoint(200,450),CPoint(190,450),CPoint(190,430),CPoint(310,430),CPoint(310,450),CPoint(300,450),CPoint(290,500),CPoint(210,500)} };
	pDC->Polygon(tacke, 8);
	pDC->SelectObject(oldBrush);
	brush->DeleteObject();
}
void CRGLabVezba2View::CrtajLeviKaktus(CDC* pDC)
{
	XFORM stara, nova, sacuvana;
	pDC->GetWorldTransform(&stara);

	nova = {
		cosf(-M_PI / 4),
		sinf(-M_PI / 4),
		-sinf(-M_PI / 4),
		cosf(-M_PI / 4),
		250,
		350
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	nova = {
		1,
		0,
		0,
		1,
		-250,
		-350
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	PlayEnhMetaFile(pDC->m_hDC, dark_cactus, CRect(250 - 10, 275, 250 + 10, 350));

	pDC->GetWorldTransform(&sacuvana);
	nova = {
		cosf(M_PI / 4),
		sinf(M_PI / 4),
		-sinf(M_PI / 4),
		cosf(M_PI / 4),
		250,
		275
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	nova = {
		1,
		0,
		0,
		1,
		-250,
		-275,
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	PlayEnhMetaFile(pDC->m_hDC, dark_cactus, CRect(250 - 20, 200, 250 + 20, 275));
	pDC->SetWorldTransform(&sacuvana);
	nova = {
		cosf(-M_PI / 4),
		sinf(-M_PI / 4),
		-sinf(-M_PI / 4),
		cosf(-M_PI / 4),
		250,
		275
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	nova = {
		1,
		0,
		0,
		1,
		-250,
		-275,
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	PlayEnhMetaFile(pDC->m_hDC, dark_cactus, CRect(250 - 20, 200, 250 + 20, 275));
	pDC->Ellipse(240, 265, 260, 285);
	pDC->SetWorldTransform(&stara);
}
void CRGLabVezba2View::CrtajSrednjiKaktus(CDC* pDC)
{
	PlayEnhMetaFile(pDC->m_hDC, dark_cactus, CRect(250 - 10, 275, 250 + 10, 350));
	pDC->Ellipse(240, 265, 260, 285);
	PlayEnhMetaFile(pDC->m_hDC, dark_cactus, CRect(250 - 30, 200, 250 + 30, 275));
}
void CRGLabVezba2View::CrtajDesniKaktus(CDC* pDC)
{
	XFORM stara, nova, sacuvana;
	pDC->GetWorldTransform(&stara);
	nova = {
		cosf(M_PI / 4 + ugao2),
		sinf(M_PI / 4 + ugao2),
		-sinf(M_PI / 4 + ugao2),
		cosf(M_PI / 4 + ugao2),
		250,
		350
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	nova = {
		1,
		0,
		0,
		1,
		-250,
		-350
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	PlayEnhMetaFile(pDC->m_hDC, light_cactus, CRect(250 - 10, 275, 250 + 10, 350));
	pDC->GetWorldTransform(&sacuvana);
	nova = {
		cosf(-M_PI / 4),
		sinf(-M_PI / 4),
		-sinf(-M_PI / 4),
		cosf(-M_PI / 4),
		250,
		275
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	nova = {
		1,
		0,
		0,
		1,
		-250,
		-275,
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	PlayEnhMetaFile(pDC->m_hDC, dark_cactus, CRect(250 - 20, 200, 250 + 20, 275));
	pDC->SetWorldTransform(&sacuvana);
	nova = {
		cosf(M_PI / 4),
		sinf(M_PI / 4),
		-sinf(M_PI / 4),
		cosf(M_PI / 4),
		250,
		275
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	nova = {
		1,
		0,
		0,
		1,
		-250,
		-275,
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	PlayEnhMetaFile(pDC->m_hDC, dark_cactus, CRect(250 - 20, 200, 250 + 20, 275));
	pDC->Ellipse(240, 265, 260, 285);
	pDC->GetWorldTransform(&sacuvana);

	nova = {
	cosf(-M_PI / 4),
	sinf(-M_PI / 4),
	-sinf(-M_PI / 4),
	cosf(-M_PI / 4),
	250,
	200
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	nova = {
		1,
		0,
		0,
		1,
		-250,
		-200,
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	PlayEnhMetaFile(pDC->m_hDC, dark_cactus, CRect(250 - 20, 125, 250 + 20, 200));
	pDC->SetWorldTransform(&sacuvana);
	nova = {
		cosf(M_PI / 4),
		sinf(M_PI / 4),
		-sinf(M_PI / 4),
		cosf(M_PI / 4),
		250,
		200
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	nova = {
		1,
		0,
		0,
		1,
		-250,
		-200
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);
	PlayEnhMetaFile(pDC->m_hDC, dark_cactus, CRect(250 - 20, 125, 250 + 20, 200));
	pDC->Ellipse(240, 190, 260, 210);

	pDC->SetWorldTransform(&stara);

}
void CRGLabVezba2View::CrtajKaktus(CDC* pDC)
{
	CBrush* brush = new CBrush(RGB(0, 204, 0));
	CBrush* oldBrush = pDC->SelectObject(brush);
	XFORM stara;

	int oldMode = pDC->SetGraphicsMode(GM_ADVANCED);
	pDC->GetWorldTransform(&stara);

	XFORM nova;
	nova = {
		cosf(ugao1),
		sinf(ugao1),
		-sinf(ugao1),
		cosf(ugao1),
		250,
		425
	};
	pDC->SetWorldTransform(&nova);
	nova = {
		1,
		0,
		0,
		1,
		-250,
		-425
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);

	PlayEnhMetaFile(pDC->m_hDC, light_cactus, CRect(250 - 30, 350, 250 + 30, 425));


	CrtajLeviKaktus(pDC);
	CrtajSrednjiKaktus(pDC);
	CrtajDesniKaktus(pDC);
	
	pDC->Ellipse(240, 415, 260, 435);
	pDC->Ellipse(240, 415 - 75, 260, 435 - 75);

	pDC->SetWorldTransform(&stara);
	pDC->SelectObject(oldBrush);
	brush->DeleteObject();
	pDC->SetGraphicsMode(oldMode);
}
void CRGLabVezba2View::IspisiIme(CDC* pDC)
{
	XFORM stara, nova;
	int oldMode = pDC->SetGraphicsMode(GM_ADVANCED);
	pDC->GetWorldTransform(&stara);
	nova = {
		cosf(M_PI / 2),
		sinf(M_PI / 2),
		-sinf(M_PI / 2),
		cosf(M_PI / 2),
		475,
		25
	};
	pDC->SetWorldTransform(&nova);
	nova = {
		1,
		0,
		0,
		1,
		-475,
		-25
	};
	pDC->ModifyWorldTransform(&nova, MWT_LEFTMULTIPLY);

	CString* ime = new CString("16866 Stefan Sokolovic");
	CFont* font = new CFont();
	font->CreateFontW(30, 0, 0, 0, 600, 0, 0, 0, 0, 0, 0, 0, 0, CString("Arial"));
	CFont* oldFont = pDC->SelectObject(font);
	CPoint textPosition(475, 25);
	pDC->SetBkMode(TRANSPARENT);

	COLORREF oldColor = pDC->SetTextColor(RGB(0, 0, 0));
	pDC->TextOutW(textPosition.x + 2, textPosition.y + 2, *ime);
	pDC->SetTextColor(RGB(255, 255, 0));
	pDC->TextOutW(textPosition.x, textPosition.y, *ime);

	pDC->SelectObject(oldFont);
	pDC->SetBkMode(OPAQUE);
	pDC->SetTextColor(oldColor);
	font->DeleteObject();
	delete ime;
	pDC->SetWorldTransform(&stara);
	pDC->SetGraphicsMode(oldMode);
}

void CRGLabVezba2View::OnDraw(CDC* pDC)
{
	CRGLabVezba2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRgn region;
	region.CreateRectRgn(0, 0, 500, 500);
	pDC->SelectClipRgn(&region);

	CrtajPozadinu(pDC);
	CrtajKaktus(pDC);
	CrtajSaksiju(pDC);
	IspisiIme(pDC);
	//if(grid)
		CrtajGrid(pDC);

	// TODO: add draw code for native data here
}


// CRGLabVezba2View printing

BOOL CRGLabVezba2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRGLabVezba2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRGLabVezba2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CRGLabVezba2View diagnostics

#ifdef _DEBUG
void CRGLabVezba2View::AssertValid() const
{
	CView::AssertValid();
}

void CRGLabVezba2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRGLabVezba2Doc* CRGLabVezba2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRGLabVezba2Doc)));
	return (CRGLabVezba2Doc*)m_pDocument;
}
#endif //_DEBUG


// CRGLabVezba2View message handlers


void CRGLabVezba2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_LEFT:
		ugao1 -= 5*(M_PI*2/360);
		Invalidate();
		break;

	case VK_RIGHT:
		ugao1 += 5 * (M_PI * 2 / 360);
		Invalidate();
		break;
	case VK_SPACE:
		grid = !grid;
		Invalidate();
		break;
	case VK_DOWN:
		ugao2 += 5 * (M_PI * 2 / 360);
		Invalidate();
		break;
	case VK_UP:
		ugao2 -= 5 * (M_PI * 2 / 360);
		Invalidate();
		break;
	}


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
