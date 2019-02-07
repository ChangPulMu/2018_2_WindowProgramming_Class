// HobbyCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "20150269_Exercise5_1.h"
#include "HobbyCtrl.h"
#include "afxdialogex.h"


// CHobbyCtrl ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CHobbyCtrl, CDialogEx)

CHobbyCtrl::CHobbyCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_strName(_T(""))
	, m_bMaleCheck(false)
{

}

CHobbyCtrl::~CHobbyCtrl()
{
}

void CHobbyCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_HOBBY, m_listHobby);
	DDX_Control(pDX, IDC_COMBO_SEX, m_cbSex);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
}


BEGIN_MESSAGE_MAP(CHobbyCtrl, CDialogEx)
END_MESSAGE_MAP()


// CHobbyCtrl �޽��� ó�����Դϴ�.


BOOL CHobbyCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_listHobby.AddString(_T("����"));
	m_listHobby.AddString(_T("����"));
	m_listHobby.AddString(_T("�"));

	//GetDlgItem(IDC_RADIO_MALE)->SetCheck(TRUE);

	m_cbSex.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}