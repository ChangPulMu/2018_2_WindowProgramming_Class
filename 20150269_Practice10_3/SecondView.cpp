// SecondView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "20150269_Practice10_3.h"
#include "SecondView.h"
#include "20150269_Practice10_3Doc.h"


// CSecondView

IMPLEMENT_DYNCREATE(CSecondView, CView)

CSecondView::CSecondView()
{

}

CSecondView::~CSecondView()
{
}

BEGIN_MESSAGE_MAP(CSecondView, CView)
END_MESSAGE_MAP()


// CSecondView 그리기입니다.

void CSecondView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
	CMy20150269_Practice10_3Doc* pDoc2 = (CMy20150269_Practice10_3Doc*)GetDocument();

	pDC->TextOut(1, 1, pDoc2->m_strSaveInput);
}


// CSecondView 진단입니다.

#ifdef _DEBUG
void CSecondView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CSecondView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSecondView 메시지 처리기입니다.
