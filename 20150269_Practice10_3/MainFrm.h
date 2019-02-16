
// MainFrm.h : CMainFrame 클래스의 인터페이스
//

#pragma once

#include "20150269_Practice10_3Doc.h"				// 도큐먼트 클래스의 헤더파일 추가
#include "20150269_Practice10_3View.h"				// 폼 뷰 클래스의 헤더파일 추가
#include "SecondView.h"								// 일반 뷰 클래스의 헤더파일 추가
#define FIRST_VIEW		1							// 폼 뷰에 대한 상수 값 설정
#define SECOND_VIEW		2							// 일반 뷰에 대한 상수 값 설정

class CMainFrame : public CFrameWndEx
{
	
protected: // serialization에서만 만들어집니다.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 특성입니다.
public:

// 작업입니다.
public:
	CMy20150269_Practice10_3View *m_pFirstView;			// 두 개의 뷰 클래스에 대한
	CSecondView *m_pSecondView;							// 객체를 등록한다

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// 구현입니다.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 컨트롤 모음이 포함된 멤버입니다.
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;

// 생성된 메시지 맵 함수
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnViewChange();
	int m_nViewFlag;
	void FirstView();
	void SecondView();
};


