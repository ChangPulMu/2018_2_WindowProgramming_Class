
// 20150269_Exercise3_1View.cpp : CMy20150269_Exercise3_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20150269_Exercise3_1.h"
#endif

#include "20150269_Exercise3_1Doc.h"
#include "20150269_Exercise3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20150269_Exercise3_1View

IMPLEMENT_DYNCREATE(CMy20150269_Exercise3_1View, CView)

BEGIN_MESSAGE_MAP(CMy20150269_Exercise3_1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy20150269_Exercise3_1View ����/�Ҹ�

CMy20150269_Exercise3_1View::CMy20150269_Exercise3_1View()
	: m_strStopWatch(_T("00: 00. 00"))
	, m_nCount(0)
	, m_nMinute(0)
	, m_nSecond(0)
	, m_nMSec(0)
	, m_strStopWatchRun(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20150269_Exercise3_1View::~CMy20150269_Exercise3_1View()
{
}

BOOL CMy20150269_Exercise3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20150269_Exercise3_1View �׸���

void CMy20150269_Exercise3_1View::OnDraw(CDC* pDC)
{
	CMy20150269_Exercise3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CFont big_font;											// ��Ʈ �� ����
	big_font.CreateFont(100, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("����ü"));

	CRect rect;												
	GetClientRect(&rect);									// ȭ�� ũ�� ������

	CClientDC dc(this);										// ���ο� ����̽� ���ؽ�Ʈ�� ����
	dc.SelectObject(big_font);								// �� ����̽� ���ؽ�Ʈ�� ��Ʈ ���
	dc.DrawText(m_strStopWatch, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);		// �����ġ�� ȭ��� ���

	for (int i = 0, y_adder = 0; i <= m_nCount; i++)		// ��� ���� 10,10 ��ġ���� y���� 20�� �÷����� ���ʴ�� ���
	{
		pDC->TextOut(10, 10 + y_adder, m_strRecord[i]);
		y_adder += 20;
	}
}


// CMy20150269_Exercise3_1View �μ�

BOOL CMy20150269_Exercise3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20150269_Exercise3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20150269_Exercise3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy20150269_Exercise3_1View ����

#ifdef _DEBUG
void CMy20150269_Exercise3_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20150269_Exercise3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20150269_Exercise3_1Doc* CMy20150269_Exercise3_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20150269_Exercise3_1Doc)));
	return (CMy20150269_Exercise3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20150269_Exercise3_1View �޽��� ó����


void CMy20150269_Exercise3_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_strStopWatchRun == false)				// Ÿ�̸Ӱ� �������� ��
	{
		SetTimer(0, 10, NULL);
		m_strStopWatchRun = true;				// Ÿ�̸Ӹ� ���۽�Ų��.
	}
	else										// Ÿ�̸Ӱ� �������� ��
	{
		KillTimer(0);
		m_strStopWatchRun = false;				// Ÿ�̸Ӹ� �����.
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMy20150269_Exercise3_1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_nMSec++;							// SetTimer�� ���� 1/100�� ȣ�⸶�� �и������� ���� 1�� �ø���.
	if (m_nMSec == 100)					// �и������尡 100�� �Ѿ�� ������ ������ ġȯ
	{
		m_nSecond++;
		m_nMSec = 0;
		if (m_nSecond == 60)			// �����尡 60�� �Ѿ�� �̴� ������ ġȯ
		{
			m_nMinute++;
			m_nSecond = 0;
		}
	}
	m_strStopWatch.Format(_T("%02d: %02d. %02d"), m_nMinute, m_nSecond, m_nMSec);			// Ÿ�̸� ����
	
	Invalidate();						// Ondraw() ȣ��

	CView::OnTimer(nIDEvent);
}


void CMy20150269_Exercise3_1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nChar == VK_SPACE)										// �����̽� �ٰ� ������ ��
	{
		if (m_strStopWatchRun == true)							// �����ġ�� �۵����̸�
		{
			m_nCount++;											// m_strRecord�� �ε��� ���� �ϳ� �ø���
			if (m_nCount >= 40)									// m_strRecord�� ���ڵ��� 40���� ������ �ʱ�ȭ
			{
				m_nCount = 0;
				for (int i = 0; i < 40; i++)
				{
					m_strRecord[i] = "";
				}
			}
			m_strRecord[m_nCount] = m_strStopWatch;				// �����ġ ���� ��Ͽ� �ϳ� ����
		}

		Invalidate();											// Ondraw() ȣ��
	}


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy20150269_Exercise3_1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_strStopWatchRun == false)				// �����ġ�� �������� ��
	{
		if (AfxMessageBox(_T("�ʱ�ȭ �Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES)			// �ʱ�ȭ
		{
			m_nCount = 0;
			m_nMinute = 0;
			m_nSecond = 0;
			m_nMSec = 0;
		}
	}
	else										// �����ġ�� �۵����� ��
	{
		AfxMessageBox(_T("�۵� �߿��� �����ġ�� �ʱ�ȭ��ų�� �����ϴ�."), MB_ICONWARNING);			// �ʱ�ȭ �Ұ�
	}

	CView::OnRButtonDown(nFlags, point);
}
