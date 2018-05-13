// LOGIN.cpp : 实现文件
//

#include "stdafx.h"
#include "y.h"
#include "LOGIN.h"
#include "afxdialogex.h"


// LOGIN 对话框

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


// LOGIN 消息处理程序


void LOGIN::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//定义一个位图对象 
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP4);
	
	//定义一个内存设备描述表对象（即后备缓冲区）  
	CDC mdc;
	//建立与屏幕设备描述表（前端缓冲区）兼容的内存设备描述表句柄（后备缓冲区）  
    mdc.CreateCompatibleDC(&dc); 
	//绘图
	mdc.SelectObject(&m_Back);
	//将后备缓冲区中的图形拷贝到前端缓冲区  
	dc.BitBlt(0,0,500,324,&mdc,0,0,SRCCOPY);	
	//绘图完成后的清理  
	m_Back.DeleteObject();  
	mdc.DeleteDC();
	// 不为绘图消息调用 CDialogEx::OnPaint()
}


void LOGIN::OnBnClickedOk()
{
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(password);
	CString x;
	GetDlgItem(IDC_COMBO1)->GetWindowTextA(x);
	if(password=="6335598"&&x=="管理员")
	{
		MessageBox("管理员登录成功！","提示",MB_ICONEXCLAMATION);
		CDialogEx::OnOK();
		CyDlg dlg;
		dlg.DoModal();
		
	}
	else if(password=="88785268"&&x=="员工")
	{
		MessageBox("员工登录成功！","提示",MB_ICONEXCLAMATION);
		CDialogEx::OnOK();
		CyDlg dlg;
		dlg.DoModal();
	}
	else
	{
		MessageBox("密码错误！","提示",MB_ICONHAND );
	}
	
}


//HBRUSH LOGIN::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
//
//	// TODO:  在此更改 DC 的任何特性
//
//	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
//	//没办法，搞一个万能的。很奇怪，在背景是图片的情况下，nCtlColor都不等于CTLCOLOR_BTN了，但经过断点可以肯定，
//    //每个控件都会进入这个消息
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
//        pDC->BitBlt(0,0,rc.Width(),rc.Height(),dc,rc.left,rc.top,SRCCOPY);  //把父窗口背景图片先画到按钮上
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

	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void LOGIN::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CString x;
	//x.Format("%d %d",point.x,point.y);//176 131  385 160    ..... 175 167 386 197
	//MessageBox(x);
	CRect account(176,131,385,160);
	CRect pass(175,167,386,197);
	if(account.PtInRect(point))
	{
		//m_acc.MoveWindow(account);//移动Edit到RECT坐在的位置;
		//m_acc.SetWindowText("");//将该子项中的值放在Edit控件中；
		m_acc.ShowWindow(SW_SHOW);//显示Edit控件；
		m_acc.SetFocus();//设置Edit焦点
		//m_acc.ShowCaret();//显示光标
		//m_acc.SetSel(-1);//将光标移动到最后
	}
	if(pass.PtInRect(point))
	{
		m_edit.MoveWindow(pass);//移动Edit到RECT坐在的位置;
		m_edit.SetWindowText("");//将该子项中的值放在Edit控件中；
		m_edit.ShowWindow(SW_SHOW);//显示Edit控件；
		m_edit.SetFocus();//设置Edit焦点
		m_edit.ShowCaret();//显示光标
		m_edit.SetSel(-1);//将光标移动到最后
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
