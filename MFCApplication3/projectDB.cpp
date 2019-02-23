// projectDB.h : CprojectDB Ŭ������ �����Դϴ�.



// CprojectDB �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 12�� 11�� ȭ����, ���� 9:36

#include "stdafx.h"
#include "projectDB.h"
IMPLEMENT_DYNAMIC(CprojectDB, CRecordset)

CprojectDB::CprojectDB(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_TITLE = L"";
	m_UPLOAD_TIME = L"";
	m_VIEW = L"";
	m_TAG = L"";
	m_URL = L"";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString CprojectDB::GetDefaultConnect()
{
	return _T("DBQ=..\\real\\projectDB.mdb;DefaultDir=C:..\\real;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=C:..real\\projectDB.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CprojectDB::GetDefaultSQL()
{
	return _T("[projectDB]");
}

void CprojectDB::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Int(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[TITLE]"), m_TITLE);
	RFX_Text(pFX, _T("[UPLOAD_TIME]"), m_UPLOAD_TIME);
	RFX_Text(pFX, _T("[VIEW]"), m_VIEW);
	RFX_Text(pFX, _T("[TAG]"), m_TAG);
	RFX_Text(pFX, _T("[URL]"), m_URL);

}
/////////////////////////////////////////////////////////////////////////////
// CprojectDB ����

#ifdef _DEBUG
void CprojectDB::AssertValid() const
{
	CRecordset::AssertValid();
}

void CprojectDB::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


