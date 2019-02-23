// projectDB.h : CprojectDB 클래스의 구현입니다.



// CprojectDB 구현입니다.

// 코드 생성 위치 2018년 12월 11일 화요일, 오후 9:36

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
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
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
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Int(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[TITLE]"), m_TITLE);
	RFX_Text(pFX, _T("[UPLOAD_TIME]"), m_UPLOAD_TIME);
	RFX_Text(pFX, _T("[VIEW]"), m_VIEW);
	RFX_Text(pFX, _T("[TAG]"), m_TAG);
	RFX_Text(pFX, _T("[URL]"), m_URL);

}
/////////////////////////////////////////////////////////////////////////////
// CprojectDB 진단

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


