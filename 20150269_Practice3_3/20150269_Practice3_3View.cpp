
// 20150269_Practice3_3View.cpp : CMy20150269_Practice3_3View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20150269_Practice3_3.h"
#endif

#include "20150269_Practice3_3Doc.h"
#include "20150269_Practice3_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20150269_Practice3_3View

IMPLEMENT_DYNCREATE(CMy20150269_Practice3_3View, CView)

BEGIN_MESSAGE_MAP(CMy20150269_Practice3_3View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy20150269_Practice3_3View ����/�Ҹ�

CMy20150269_Practice3_3View::CMy20150269_Practice3_3View()
	: m_strOutput(_T(""))
	, m_ptLocation(0)
	, m_ptClientSize(0)
	, m_bDrag(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20150269_Practice3_3View::~CMy20150269_Practice3_3View()
{
}

BOOL CMy20150269_Practice3_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20150269_Practice3_3View �׸���

void CMy20150269_Practice3_3View::OnDraw(CDC* pDC)
{
	CMy20150269_Practice3_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	// �����쿡 ���ڿ� ���
	pDC->TextOut(m_ptLocation.x, m_ptLocation.y, m_strOutput);
}


// CMy20150269_Practice3_3View �μ�

BOOL CMy20150269_Practice3_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20150269_Practice3_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20150269_Practice3_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy20150269_Practice3_3View ����

#ifdef _DEBUG
void CMy20150269_Practice3_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20150269_Practice3_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20150269_Practice3_3Doc* CMy20150269_Practice3_3View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20150269_Practice3_3Doc)));
	return (CMy20150269_Practice3_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20150269_Practice3_3View �޽��� ó����


void CMy20150269_Practice3_3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int nCharIndex;
	nCharIndex = m_strOutput.GetLength();			// �Էµ� �������� ���̸� ��´�.

	if (nChar == VK_BACK)							// �齺���̽��� ���� ���
		m_strOutput.Delete(nCharIndex - 1, 1);		// �� ���� �ϳ��� �����.
	else											// �齺���̽� �̿��� Ű�� ���� ���
		m_strOutput += (WCHAR)nChar;				// Ű����� �Էµ� ���ڸ� ���ڿ��� �߰�

	Invalidate();									// ȭ�� ����
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy20150269_Practice3_3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (nChar)						// ����Ű �ڵ� ���� ����
	{
	case VK_LEFT:						// ���� ȭ��ǥ Ű�� ���� ��
		m_ptLocation.x--;				// �������� 1 �̵�
		break;
	case VK_RIGHT:						// ������ ȭ��ǥ Ű�� ���� ��
		m_ptLocation.x++;				// ���������� 1 �̵�
		break;
	case VK_UP:							// ���� ȭ��ǥ Ű�� ���� ��
		m_ptLocation.y--;				// �������� 1 �̵�
		break;
	case VK_DOWN:						// �Ʒ��� ȭ��ǥ Ű�� ���� ��
		m_ptLocation.y++;				// �Ʒ������� 1 �̵�
		break;
	case VK_PRIOR:						// Pageup Ű�� ���� ��
		m_ptLocation.y -= 50;			// �������� 50 �̵�
		break;
	case VK_NEXT:						// Pagedown Ű�� ���� ��
		m_ptLocation.y += 50;			// �Ʒ������� 50 �̵�
		break;
	case VK_HOME:						// Home Ű�� ���� ��
		m_ptLocation = CPoint(0,0);		// ó����ġ�� �̵�
	break;
	}

	if (m_ptLocation.x < 0)							// X��ǥ�� 0���� ������
	{
		m_ptLocation.x = 0;							// m_ptLocation.x = 0���� �ʱ�ȭ
		AfxMessageBox(_T("�������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if (m_ptLocation.y < 0)							// Y��ǥ�� 0���� ������
	{
		m_ptLocation.y = 0;							// m_ptLocation.y = 0���� �ʱ�ȭ
		AfxMessageBox(_T("�������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if (m_ptLocation.x > m_ptClientSize.x)			// X��ǥ�� ������ ������ X ������ ũ��
	{
		m_ptLocation.x = m_ptClientSize.x;			// m_ptLocation.x = ������ Xũ��� �ʱ�ȭ
		AfxMessageBox(_T("���������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if (m_ptLocation.y > m_ptClientSize.y)			// Y��ǥ�� ������ ������ Y ������ ũ��
	{
		m_ptLocation.y = m_ptClientSize.y;			// m_ptLocation.y = ������ Yũ��� �ʱ�ȭ
		AfxMessageBox(_T("�Ʒ������� �� �̻� �̵��� �� �����ϴ�."));
	}
	Invalidate();						// ȭ�� ����

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy20150269_Practice3_3View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	m_ptClientSize.x = cx;		// ������ ������ ����(x) ���̸� ����
	m_ptClientSize.y = cy;		// ������ ������ ����(y) ���̸� ����

	Invalidate();				// ȭ�鰻��
}


void CMy20150269_Practice3_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_ptLocation.x > point.x - 30 && m_ptLocation.x < point.x + 30)
		if (m_ptLocation.y > point.y - 30 && m_ptLocation.y < point.y + 30)
			m_bDrag = true;

	m_ptLocation.x = point.x;
	m_ptLocation.y = point.y;
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CMy20150269_Practice3_3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_strOutput.IsEmpty() == false)
	{
		if (AfxMessageBox(_T("���ڸ� ��� ����ðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			m_strOutput.Empty();
		}
	}
	else
	{
		AfxMessageBox(_T("���ڿ��� �Է��Ͻÿ�."));
	}
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


void CMy20150269_Practice3_3View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bDrag == true)
	{
		m_ptLocation.x = point.x;
		m_ptLocation.y = point.y;
	}

	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


void CMy20150269_Practice3_3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bDrag == true)
	{
		m_bDrag = false;

		m_ptLocation.x = point.x;
		m_ptLocation.y = point.y;
	}

	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}
