
// 20150269_Exercise3_1View.h : CMy20150269_Exercise3_1View 클래스의 인터페이스
//

#pragma once


class CMy20150269_Exercise3_1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy20150269_Exercise3_1View();
	DECLARE_DYNCREATE(CMy20150269_Exercise3_1View)

// 특성입니다.
public:
	CMy20150269_Exercise3_1Doc* GetDocument() const;

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
	virtual ~CMy20150269_Exercise3_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_strStopWatch;
	CString m_strRecord[40];
	int m_nCount;
	int m_nMinute;
	int m_nSecond;
	int m_nMSec;
	bool m_strStopWatchRun;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 20150269_Exercise3_1View.cpp의 디버그 버전
inline CMy20150269_Exercise3_1Doc* CMy20150269_Exercise3_1View::GetDocument() const
   { return reinterpret_cast<CMy20150269_Exercise3_1Doc*>(m_pDocument); }
#endif

