// ClientSock.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "20150269_Practice14_1.h"
#include "ClientSock.h"
#include "20150269_Practice14_1.h"


// CClientSock

CClientSock::CClientSock()
{
}

CClientSock::~CClientSock()
{
}


// CClientSock ��� �Լ�


void CClientSock::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	((CMy20150269_Practice14_1App*)AfxGetApp())->ReceiveData();

	CAsyncSocket::OnReceive(nErrorCode);
}


void CClientSock::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	((CMy20150269_Practice14_1App*)AfxGetApp())->CloseChild();

	CAsyncSocket::OnClose(nErrorCode);
}
