
// 20150269_Practice3_3View.h : CMy20150269_Practice3_3View 클래스의 인터페이스
//

#pragma once
#include "atltypes.h"


class CMy20150269_Practice3_3View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy20150269_Practice3_3View();
	DECLARE_DYNCREATE(CMy20150269_Practice3_3View)

// 특성입니다.
public:
	CMy20150269_Practice3_3Doc* GetDocument() const;

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
	virtual ~CMy20150269_Practice3_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_strOutput;
	CPoint m_ptLocation;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CPoint m_ptClientSize;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	bool m_bDrag;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 20150269_Practice3_3View.cpp의 디버그 버전
inline CMy20150269_Practice3_3Doc* CMy20150269_Practice3_3View::GetDocument() const
   { return reinterpret_cast<CMy20150269_Practice3_3Doc*>(m_pDocument); }
#endif

