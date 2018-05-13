
// yDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "explorer1.h"
#include "afxwin.h"
#include "afxdtctl.h"
#include "LOGIN.h"

// CyDlg 对话框
class CyDlg : public CDialogEx
{
// 构造
public:
	CyDlg(CWnd* pParent = NULL);	// 标准构造函数
	bool KC_flagDJ,DD_flagDJ,KH_flagDJ;
	int m_Row,m_Col;
	void Customer(CString SQL);
	void DD(CString SQL);
	void KC(CString SQL);
	void remind();
	CString Delete_id,Delete_type;
	bool ADD_KH,ADD_DD,ADD_KC;
	bool CX_KH,CX_DD,CX_KC,CX_LS,CX_LR;
	bool TJ_DD;
	bool GX_KC;
	int menu;
	bool Menu,YDMenu;
	CString start_date;
	
// 对话框数据
	enum { IDD = IDD_Y_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CToolTipCtrl m_Mytip;
	CListCtrl m_L;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CButton m_kc;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit m_edit;
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void On32771();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton9();
	CDateTimeCtrl m_d1;
	CDateTimeCtrl m_d2;
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnHdnItemclickList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnOK();
	afx_msg void OnBnClickedRadio1();

	afx_msg void OnBnClickedCancel();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
};
