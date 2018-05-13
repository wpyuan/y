// LOGIN.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "y.h"
#include "LOGIN.h"
#include "afxdialogex.h"


// LOGIN �Ի���

IMPLEMENT_DYNAMIC(LOGIN, CDialogEx)

LOGIN::LOGIN(CWnd* pParent /*=NULL*/)
	: CDialogEx(LOGIN::IDD, pParent)
{

}

LOGIN::~LOGIN()
{
}

void LOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_COMBO1, m_acc);
}


BEGIN_MESSAGE_MAP(LOGIN, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &LOGIN::OnBnClickedOk)
//	ON_WM_CTLCOLOR()
ON_WM_LBUTTONDOWN()
ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// LOGIN ��Ϣ�������


void LOGIN::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//����һ��λͼ���� 
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP4);
	
	//����һ���ڴ��豸��������󣨼��󱸻�������  
	CDC mdc;
	//��������Ļ�豸������ǰ�˻����������ݵ��ڴ��豸�����������󱸻�������  
    mdc.CreateCompatibleDC(&dc); 
	//��ͼ
	mdc.SelectObject(&m_Back);
	//���󱸻������е�ͼ�ο�����ǰ�˻�����  
	dc.BitBlt(0,0,500,324,&mdc,0,0,SRCCOPY);	
	//��ͼ��ɺ������  
	m_Back.DeleteObject();  
	mdc.DeleteDC();
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}


void LOGIN::OnBnClickedOk()
{
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(password);
	CString x;
	GetDlgItem(IDC_COMBO1)->GetWindowTextA(x);
	if(password=="6335598"&&x=="����Ա")
	{
		MessageBox("����Ա��¼�ɹ���","��ʾ",MB_ICONEXCLAMATION);
		CDialogEx::OnOK();
		CyDlg dlg;
		dlg.DoModal();
		
	}
	else if(password=="88785268"&&x=="Ա��")
	{
		MessageBox("Ա����¼�ɹ���","��ʾ",MB_ICONEXCLAMATION);
		CDialogEx::OnOK();
		CyDlg dlg;
		dlg.DoModal();
	}
	else
	{
		MessageBox("�������","��ʾ",MB_ICONHAND );
	}
	
}


//HBRUSH LOGIN::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
//
//	// TODO:  �ڴ˸��� DC ���κ�����
//
//	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
//	//û�취����һ�����ܵġ�����֣��ڱ�����ͼƬ������£�nCtlColor��������CTLCOLOR_BTN�ˣ��������ϵ���Կ϶���
//    //ÿ���ؼ�������������Ϣ
//    UINT id = pWnd->GetDlgCtrlID();
//    if(id == IDOK )
//    {
//        pDC->SetBkMode(TRANSPARENT);
//
//        CRect rc;
//        pWnd->GetWindowRect(&rc);
//        ScreenToClient(&rc);
//
//        CDC* dc = GetDC();
//
//        pDC->BitBlt(0,0,rc.Width(),rc.Height(),dc,rc.left,rc.top,SRCCOPY);  //�Ѹ����ڱ���ͼƬ�Ȼ�����ť��
//
//        ReleaseDC(dc);
//
//        hbr = (HBRUSH) ::GetStockObject(NULL_BRUSH);
//    }
//	return hbr;
//}


BOOL LOGIN::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void LOGIN::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CString x;
	//x.Format("%d %d",point.x,point.y);//176 131  385 160    ..... 175 167 386 197
	//MessageBox(x);
	CRect account(176,131,385,160);
	CRect pass(175,167,386,197);
	if(account.PtInRect(point))
	{
		//m_acc.MoveWindow(account);//�ƶ�Edit��RECT���ڵ�λ��;
		//m_acc.SetWindowText("");//���������е�ֵ����Edit�ؼ��У�
		m_acc.ShowWindow(SW_SHOW);//��ʾEdit�ؼ���
		m_acc.SetFocus();//����Edit����
		//m_acc.ShowCaret();//��ʾ���
		//m_acc.SetSel(-1);//������ƶ������
	}
	if(pass.PtInRect(point))
	{
		m_edit.MoveWindow(pass);//�ƶ�Edit��RECT���ڵ�λ��;
		m_edit.SetWindowText("");//���������е�ֵ����Edit�ؼ��У�
		m_edit.ShowWindow(SW_SHOW);//��ʾEdit�ؼ���
		m_edit.SetFocus();//����Edit����
		m_edit.ShowCaret();//��ʾ���
		m_edit.SetSel(-1);//������ƶ������
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


LRESULT LOGIN::OnNcHitTest(CPoint point)
{
	CRect rect(0,0,500,100);
	ClientToScreen(rect);
	if(rect.PtInRect(point))
		return HTCAPTION;
	return CDialogEx::OnNcHitTest(point);
}
