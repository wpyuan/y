#pragma once
#include "afxwin.h"
#include "yDlg.h"

// LOGIN �Ի���

class LOGIN : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN)

public:
	LOGIN(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LOGIN();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CEdit m_edit;
	CComboBox m_acc;
	afx_msg LRESULT OnNcHitTest(CPoint point);
};
