// NCardListBox.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "20150269_Practice9_1.h"
#include "NCardListBox.h"
#include "20150269_Practice9_1Dlg.h"


// CNCardListBox

IMPLEMENT_DYNAMIC(CNCardListBox, CVSListBox)

CNCardListBox::CNCardListBox()
{

}

CNCardListBox::~CNCardListBox()
{
}


BEGIN_MESSAGE_MAP(CNCardListBox, CVSListBox)
END_MESSAGE_MAP()



// CNCardListBox 메시지 처리기입니다.




void CNCardListBox::OnAfterAddItem(int nIndex)
{
	// 명함 데이터 추가하기
	CMy20150269_Practice9_1Dlg* pParent = (CMy20150269_Practice9_1Dlg*)GetParent();
	pParent->AddNameCard(GetItemText(nIndex));
}


void CNCardListBox::OnSelectionChanged()
{
	int nItem;
	if ((nItem = GetSelItem()) < 0)
		return;

	// 명함 데이터 선택하기
	CMy20150269_Practice9_1Dlg* pParent = (CMy20150269_Practice9_1Dlg*)GetParent();
	pParent->SelectNameCard(nItem);
}


BOOL CNCardListBox::OnBeforeRemoveItem(int nIndex)
{
	// 명함 데이터 삭제하기
	CMy20150269_Practice9_1Dlg* pParent = (CMy20150269_Practice9_1Dlg*)GetParent();
	pParent->DeleteNameCard(GetSelItem());
	return TRUE;
}
