// ServerSock.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "20150269_Practice14_1.h"
#include "ServerSock.h"
#include "20150269_Practice14_1.h"


// CServerSock

CServerSock::CServerSock()
{
}

CServerSock::~CServerSock()
{
}


// CServerSock ��� �Լ�


void CServerSock::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	((CMy20150269_Practice14_1App*)AfxGetApp())->Accept();

	CAsyncSocket::OnAccept(nErrorCode);
}
