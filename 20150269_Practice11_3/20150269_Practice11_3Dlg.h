
// 20150269_Practice11_3Dlg.h : 헤더 파일
//

#pragma once
#include "C:\풀무 2018-2\윈도우 프로그래밍 및 실습\20150269_Practice11_3\RootDll\CalculateRoot.h"


// CMy20150269_Practice11_3Dlg 대화 상자
class CMy20150269_Practice11_3Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMy20150269_Practice11_3Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20150269_PRACTICE11_3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CCalculateRoot m_calcRoot;
	afx_msg void OnClickedButtonCalcRoot();
	afx_msg void OnClickedButtonClear();
};
