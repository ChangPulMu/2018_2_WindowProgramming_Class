
// 20150269_Practice10_1View.h : CMy20150269_Practice10_1View 클래스의 인터페이스
//

#pragma once
#include "afxcmn.h"


class CMy20150269_Practice10_1View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMy20150269_Practice10_1View();
	DECLARE_DYNCREATE(CMy20150269_Practice10_1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY20150269_PRACTICE10_1_FORM };
#endif

// 특성입니다.
public:
	CMy20150269_Practice10_1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CMy20150269_Practice10_1View();
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
	CString m_strText;
	int m_nRed;
	int m_nGreen;
	int m_nBlue;
	int m_nX;
	int m_nY;
	CSliderCtrl m_sliderY;
	COLORREF m_colorText;
	afx_msg void OnClickedButtonOutput();
	afx_msg void OnClickedButtonColor();
	afx_msg void OnClickedButtonReset();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnChangeEditRed();
	afx_msg void OnChangeEditGreen();
	afx_msg void OnChangeEditBlue();
	afx_msg void OnChangeEditText();
	virtual void OnDraw(CDC* /*pDC*/);
	CSliderCtrl m_sliderX;
};

#ifndef _DEBUG  // 20150269_Practice10_1View.cpp의 디버그 버전
inline CMy20150269_Practice10_1Doc* CMy20150269_Practice10_1View::GetDocument() const
   { return reinterpret_cast<CMy20150269_Practice10_1Doc*>(m_pDocument); }
#endif

