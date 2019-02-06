
// 20150269_Practice5_4View.h : CMy20150269_Practice5_4View 클래스의 인터페이스
//

#pragma once
#include "atltypes.h"


class CMy20150269_Practice5_4View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy20150269_Practice5_4View();
	DECLARE_DYNCREATE(CMy20150269_Practice5_4View)

// 특성입니다.
public:
	CMy20150269_Practice5_4Doc* GetDocument() const;

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
	virtual ~CMy20150269_Practice5_4View();
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
	CString m_strOutput;
	int m_nTextWidth;
	int m_nTextHeight;
	CPoint m_ptPosition;
	COLORREF m_colorText;
	bool m_bFont;
	LOGFONT m_logFont;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // 20150269_Practice5_4View.cpp의 디버그 버전
inline CMy20150269_Practice5_4Doc* CMy20150269_Practice5_4View::GetDocument() const
   { return reinterpret_cast<CMy20150269_Practice5_4Doc*>(m_pDocument); }
#endif

