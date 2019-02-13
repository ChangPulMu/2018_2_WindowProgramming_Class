
// 20150269_Practice9_1Dlg.h : 헤더 파일
//

#pragma once
#include "afxcolorbutton.h"
#include "afxfontcombobox.h"
#include "afxpropertygridctrl.h"
#include "NCardListBox.h"

typedef struct NameCard
{
	CString strCompany;
	CString strTitle;
	CString strName;
	CString strTelephone;
	CString strMobile;
	CString strEMail;

} NameCard;


// CMy20150269_Practice9_1Dlg 대화 상자
class CMy20150269_Practice9_1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMy20150269_Practice9_1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20150269_PRACTICE9_1_DIALOG };
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
	NameCard m_pNameCards[20];
	int m_nCount;
	int m_nSelectedCard;
	void AddNameCard(CString strName);
	void SelectNameCard(int nIndex);
	void DeleteNameCard(int nIndex);
	CMFCColorButton m_cbtnBackgnd;
	CMFCColorButton m_cbtnText;
	CMFCFontComboBox m_fcbText;
	CMFCPropertyGridCtrl m_pgCardInfo;
	void InitializePropGrid(NameCard card);
	void DrawNameCard(NameCard card);

	afx_msg LRESULT OnPropertyChanged(WPARAM wParam, LPARAM lParam);
	CNCardListBox m_listNameCard;
	afx_msg void OnClickedMfccolorbuttonBackgnd();
	afx_msg void OnClickedMfccolorbuttonText();
	afx_msg void OnSelchangeMfcfontcomboText();
};
