
// Practice2_1View.h : CPractice2_1View Ŭ������ �������̽�
//

#pragma once


class CPractice2_1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CPractice2_1View();
	DECLARE_DYNCREATE(CPractice2_1View)

// Ư���Դϴ�.
public:
	CPractice2_1Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CPractice2_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Practice2_1View.cpp�� ����� ����
inline CPractice2_1Doc* CPractice2_1View::GetDocument() const
   { return reinterpret_cast<CPractice2_1Doc*>(m_pDocument); }
#endif

