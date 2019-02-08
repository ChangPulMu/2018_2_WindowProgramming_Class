
// 20150269_Practice6_2View.h : CMy20150269_Practice6_2View 클래스의 인터페이스
//

#pragma once
#include "atltypes.h"


class CMy20150269_Practice6_2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy20150269_Practice6_2View();
	DECLARE_DYNCREATE(CMy20150269_Practice6_2View)

// 특성입니다.
public:
	CMy20150269_Practice6_2Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy20150269_Practice6_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	int m_nPenSize;					// 펜 크기를 저장하는 변수
	int m_nEraserSize;				// 지우개 크기를 저장하는 변수
	COLORREF m_colorPen;			// 펜 색상을 저장하는 변수
	CPoint m_ptPrev;				// 이전 점 저장 변수
	afx_msg void OnPenSize();
	afx_msg void OnEraserSize();
	afx_msg void OnPenColor();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 20150269_Practice6_2View.cpp의 디버그 버전
inline CMy20150269_Practice6_2Doc* CMy20150269_Practice6_2View::GetDocument() const
   { return reinterpret_cast<CMy20150269_Practice6_2Doc*>(m_pDocument); }
#endif

