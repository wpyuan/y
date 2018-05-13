
// yDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "y.h"
#include "yDlg.h"
#include "afxdialogex.h"
 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CyDlg 对话框




CyDlg::CyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CyDlg::IDD, pParent)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_L);
	DDX_Control(pDX, IDC_BUTTON1, m_kc);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_d1);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_d2);
}

BEGIN_MESSAGE_MAP(CyDlg, CDialogEx)
//	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CyDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CyDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &CyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CyDlg::OnBnClickedButton2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CyDlg::OnNMDblclkList1)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CyDlg::OnEnKillfocusEdit1)
	ON_BN_CLICKED(IDC_BUTTON3, &CyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON11, &CyDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &CyDlg::OnBnClickedButton13)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, &CyDlg::OnNMRClickList1)
	ON_COMMAND(ID_32771, &CyDlg::On32771)
	ON_BN_CLICKED(IDC_BUTTON12, &CyDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON9, &CyDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON14, &CyDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON10, &CyDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON8, &CyDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CyDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON15, &CyDlg::OnBnClickedButton15)
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CyDlg::OnHdnItemclickList1)
ON_BN_CLICKED(IDC_RADIO1, &CyDlg::OnBnClickedRadio1)

ON_BN_CLICKED(IDCANCEL, &CyDlg::OnBnClickedCancel)
ON_WM_PAINT()
ON_BN_CLICKED(IDC_CHECK1, &CyDlg::OnBnClickedCheck1)
ON_BN_CLICKED(IDC_BUTTON16, &CyDlg::OnBnClickedButton16)
ON_BN_CLICKED(IDC_BUTTON17, &CyDlg::OnBnClickedButton17)
ON_BN_CLICKED(IDC_BUTTON18, &CyDlg::OnBnClickedButton18)
END_MESSAGE_MAP()


// CyDlg 消息处理程序
static int skin=0;
BOOL CyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	if(password=="88785268")
		GetDlgItem(IDC_BUTTON10)->ShowWindow(0);
	m_Mytip.Create(this);
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON1), "库存:新增/编辑/历史功能。新增:添加新库存/更新库存。编辑:模糊查询/修改/右键删除/批量删除。历史:智能分组/模糊查询/修改/右键删除/批量删除" ); //IDC_BUTTON为你要添加提示信息的LISTBOX的ID
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON2), "订单:新增/编辑/统计功能。新增:添加新订单。编辑:智能分组/模糊查询/修改/右键删除/批量删除。统计:智能分组/按条件筛选统计" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON3), "客户:新增/编辑/统计功能。新增:添加新客户。编辑:模糊查询/修改/右键删除/批量删除" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON4), "新增:点击添加100行待增行,然后点击右下角保存,完成添加" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON5), "编辑:模糊查询在右上角.修改:双击需改位置,再在输入框填入修改信息,鼠标点击输入框别处,完成修改.批量删除:表格上方.右键删除:在需删除行右键,再点击删除,完成单条删除" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON6), "历史:模糊查询在右上角.修改:双击需改位置,再在输入框填入修改信息,鼠标点击输入框别处,完成修改.批量删除:表格上方.右键删除:在需删除行右键,再点击删除,完成单条删除.智能分组:表格上方" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON7), "新增:点击添加100行待增行,然后点击右下角保存,完成添加" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON8), "编辑:模糊查询在右上角.修改:双击需改位置,再在输入框填入修改信息,鼠标点击输入框别处,完成修改.批量删除:表格上方.右键删除:在需删除行右键,再点击删除,完成单条删除.智能分组:表格上方" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON9), "统计:按日期/型号/客户筛选统计.智能分组:按型号/客户分组" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON10), "补全利润:填完即完成,按此按钮刷新表格数据" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON11), "查询:根据输入信息全字段模糊查询,输入是空为全查询" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON12), "新增:点击添加100行待增行,然后点击右下角保存,完成添加" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON13), "编辑:模糊查询在右上角.修改:双击需改位置,再在输入框填入修改信息,鼠标点击输入框别处,完成修改.批量删除:表格上方.右键删除:在需删除行右键,再点击删除,完成单条删除" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON14), "统计:按日期/型号/客户筛选统计" );
	m_Mytip.AddTool( GetDlgItem(IDC_BUTTON15), "保存:保存新增信息" );
	m_Mytip.AddTool( GetDlgItem(IDCANCEL), "关闭" );
	m_Mytip.AddTool( GetDlgItem(IDC_RADIO1), "点击按条件分组" );
	m_Mytip.AddTool( GetDlgItem(IDC_CHECK1), "点击,再表格左边列选择,最后点击右下角删除,完成批量删除" );
	m_Mytip.AddTool( GetDlgItem(IDC_COMBO1), "点击下拉条选择分组方式" );
	m_Mytip.AddTool( GetDlgItem(IDC_EDIT2), "输入查询信息.若要模糊查询,例:要查询'张三',可输入'三'" );
	m_Mytip.SetDelayTime(200); //设置延迟
	m_Mytip.SetTipTextColor( RGB(0,0,0) ); //设置提示文本的颜色
	m_Mytip.SetTipBkColor( RGB(199,237,204)); //设置提示框的背景颜色
	m_Mytip.Activate(false); //设置是否启用提示
	menu=0;Menu=false;YDMenu=false;
	ADD_KH=false;ADD_DD=false;ADD_KC=false;
	CX_KH=false;CX_DD=false;CX_KC=false;CX_LS=false;CX_LR=false;
	TJ_DD=false;
	GX_KC=false;
	Delete_id="";
	datebases();
	m_Row=0,m_Col=0;
	KC_flagDJ=false,DD_flagDJ=false,KH_flagDJ=false;
	GetDlgItem(IDC_BUTTON1)->SetWindowPos( NULL,0,55,0,0,SWP_NOZORDER | SWP_NOSIZE );
	GetDlgItem(IDC_BUTTON2)->SetWindowPos( NULL,0,95,0,0,SWP_NOZORDER | SWP_NOSIZE );
	GetDlgItem(IDC_BUTTON3)->SetWindowPos( NULL,0,135,0,0,SWP_NOZORDER | SWP_NOSIZE );
	remind();//库存不足提醒
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
void CyDlg::remind()
{
	    CRect rect;
		m_L.GetClientRect(&rect);
		// 为列表视图控件添加全行选中和栅格风格
		m_L.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES| LVS_EX_TWOCLICKACTIVATE);
		// 为列表视图控件添加2列   
		m_L.InsertColumn(0,_T("库存不足"),LVCFMT_CENTER,rect.Width()/3,0); 
		m_L.InsertColumn(1,_T("型号"),LVCFMT_CENTER,rect.Width()/3,1); 
		m_L.InsertColumn(2,_T("库存"),LVCFMT_CENTER,rect.Width()/3,2); 
	    m_L.SetTextBkColor(RGB(199,237,204));
	//执行查询
	MYSQL_RES *m_result;
	CString sql;
	sql.Format("select I_type,I_kc from inventory.inventory where I_kc<2 order by I_kc ASC;");
	mysql_query(&m_sqlCons,sql);
	m_result=mysql_use_result(&m_sqlCons);
	int i=0;
	CString data[2];
	CString j;
	MYSQL_ROW row;
	while((row=mysql_fetch_row(m_result)))
	{
		//获取数据
		data[0]=row[0];
		data[1]=row[1];
		j.Format("%d",(i+1));
		// 在列表视图控件中插入列表项，并设置列表子项文本
		m_L.InsertItem(i, j);
		m_L.SetItemText(i, 1,data[0]);
	    m_L.SetItemText(i, 2,data[1] );
		i++;
	}	
	mysql_free_result(m_result); //关联的内存会释放
}
//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
BOOL CyDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_LBUTTONDOWN)
	{
		CRect rect(0,0,72,99);
		if(rect.PtInRect(pMsg->pt))
		{
			InvalidateRect(rect,0);
			if(menu%2)
			{
				Menu=false;
				menu++;
				m_Mytip.Activate(false); //设置是否启用提示
			}
			else
			{
				Menu=true;
				menu++;
				m_Mytip.Activate(TRUE); //设置是否启用提示
			}
		}
	}
	if(pMsg->message==WM_MOUSEMOVE)
	{
		CRect rect;
		m_Mytip.RelayEvent(pMsg);
		if(!KH_flagDJ&&!DD_flagDJ&&!KC_flagDJ)
		{
			GetDlgItem(IDC_BUTTON1)->GetWindowRect(rect);
			if(rect.PtInRect(pMsg->pt))				
			GetDlgItem(IDC_BUTTON1)->SetWindowPos( NULL,20,55,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
			else
				GetDlgItem(IDC_BUTTON1)->SetWindowPos( NULL,0,55,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
		}
		if(!KH_flagDJ&&!DD_flagDJ&&!KC_flagDJ)
		{
			GetDlgItem(IDC_BUTTON2)->GetWindowRect(rect);
			if(rect.PtInRect(pMsg->pt))
				GetDlgItem(IDC_BUTTON2)->SetWindowPos( NULL,20,97,0,0,SWP_NOZORDER | SWP_NOSIZE ); 		
			else
				GetDlgItem(IDC_BUTTON2)->SetWindowPos( NULL,0,97,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
		}
		if(!KH_flagDJ&&!DD_flagDJ&&!KC_flagDJ)
		{
			GetDlgItem(IDC_BUTTON3)->GetWindowRect(rect);
			if(rect.PtInRect(pMsg->pt))
				GetDlgItem(IDC_BUTTON3)->SetWindowPos( NULL,20,137,0,0,SWP_NOZORDER | SWP_NOSIZE ); 		
			else
				GetDlgItem(IDC_BUTTON3)->SetWindowPos( NULL,0,137,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
		}
		CRect r(0,0,79,97);
		if(r.PtInRect(pMsg->pt))
		{
			
			InvalidateRect(r,0);
			YDMenu=true;
		}
		else
		{
			InvalidateRect(r,0);
			YDMenu=false;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CyDlg::OnBnClickedButton4()
{
	ADD_KC=true;
	CX_KC=false;
	CX_LS=false;
	GetDlgItem(IDC_BUTTON17)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON15)->SetWindowTextA( "保存");
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_EDIT2)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON11)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_CHECK1)->ShowWindow(0);
	CButton *p=(CButton *)GetDlgItem(IDC_CHECK1);
	p->SetCheck(0);
	GetDlgItem(IDC_RADIO1)->ShowWindow(0);
	CButton *p1=(CButton *)GetDlgItem(IDC_RADIO1);
	p1->SetCheck(0);
	m_L.DeleteAllItems();
	
	CHeaderCtrl* pHeaderCtrl = m_L.GetHeaderCtrl();
		if (pHeaderCtrl != NULL)
		{
			int  nColumnCount = pHeaderCtrl->GetItemCount();
			for (int i=0; i<nColumnCount; i++)
			{
				m_L.DeleteColumn(0);
			}
		}
		m_L.DeleteAllItems();
		CRect rect;
		m_L.GetClientRect(&rect);
		// 为列表视图控件添加全行选中和栅格风格
		m_L.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES| LVS_EX_TWOCLICKACTIVATE);
		// 为列表视图控件添加7列   
		m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()/6,0); 
		m_L.InsertColumn(1,_T("日期"),LVCFMT_CENTER,rect.Width()/6,1); 
		m_L.InsertColumn(2,_T("型号"),LVCFMT_CENTER,rect.Width()/6,2); 
		m_L.InsertColumn(3,_T("入库"),LVCFMT_CENTER,rect.Width()/12,3); 
	    m_L.InsertColumn(4,_T("出库"),LVCFMT_CENTER,rect.Width()/12,4); 
		m_L.InsertColumn(5,_T("库存"),LVCFMT_CENTER,rect.Width()/12,5); 
		m_L.InsertColumn(6,_T("备注"),LVCFMT_CENTER,rect.Width()*3/12,6); 
	m_L.SetTextBkColor(RGB(199,237,204));

	CString x;
	SYSTEMTIME st;
	CString strDate;
	GetLocalTime(&st);
	strDate.Format("%4d-%d-%d",st.wYear,st.wMonth,st.wDay);

	for(int i=0;i<20;i++)
	{
		x.Format("%d",i+1);
	    m_L.InsertItem(i, x);
		m_L.SetItemText(i,1,strDate);
	}
	m_L.SetTextBkColor(RGB(199,237,204));
	GetDlgItem(IDC_BUTTON4)->SetWindowTextA("■    新增");
	GetDlgItem(IDC_BUTTON5)->SetWindowTextA("□    编辑");
	GetDlgItem(IDC_BUTTON6)->SetWindowTextA("□    历史");
}


void CyDlg::OnBnClickedButton5()
{
	ADD_KC=false;
	CX_KC=true;
	CX_LS=false;
	GetDlgItem(IDC_RADIO1)->ShowWindow(0);
	CButton *p=(CButton *)GetDlgItem(IDC_RADIO1);
	p->SetCheck(0);
	GetDlgItem(IDC_CHECK1)->ShowWindow(1);
	CButton *p1=(CButton *)GetDlgItem(IDC_CHECK1);
	p1->SetCheck(0);
	GetDlgItem(IDC_EDIT2)->ShowWindow(1);
	GetDlgItem(IDC_BUTTON11)->ShowWindow(1);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON15)->SetWindowTextA( "保存");
	GetDlgItem(IDC_BUTTON4)->SetWindowTextA("□    新增");
	GetDlgItem(IDC_BUTTON5)->SetWindowTextA("■    编辑");
	GetDlgItem(IDC_BUTTON6)->SetWindowTextA("□    历史");
	GetDlgItem(IDC_BUTTON17)->EnableWindow(1);

	 CHeaderCtrl* pHeaderCtrl = m_L.GetHeaderCtrl();
		if (pHeaderCtrl != NULL)
		{
			int  nColumnCount = pHeaderCtrl->GetItemCount();
			for (int i=0; i<nColumnCount; i++)
			{
				m_L.DeleteColumn(0);
			}
		}
		m_L.DeleteAllItems();
		CRect rect;
		m_L.GetClientRect(&rect);
		// 为列表视图控件添加全行选中和栅格风格
		m_L.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES| LVS_EX_TWOCLICKACTIVATE);
		// 为列表视图控件添加7列   
		m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()/6,0); 
		m_L.InsertColumn(1,_T("日期"),LVCFMT_CENTER,rect.Width()/6,1); 
		m_L.InsertColumn(2,_T("型号"),LVCFMT_CENTER,rect.Width()/6,2); 
	//	m_L.InsertColumn(3,_T("入库"),LVCFMT_CENTER,rect.Width()/12,3); 
	 //   m_L.InsertColumn(4,_T("出库"),LVCFMT_CENTER,rect.Width()/12,4); 
		m_L.InsertColumn(5,_T("库存"),LVCFMT_CENTER,rect.Width()/6,5); 
		m_L.InsertColumn(6,_T("备注"),LVCFMT_CENTER,rect.Width()/3,6); 
	CString sql;
	sql.Format("SELECT I_id,I_time,I_type,I_kc,I_remark FROM inventory.inventory order by I_time DESC;");
	m_L.SetRedraw(FALSE);
	KC(sql);
	m_L.SetRedraw(TRUE);
	m_L.Invalidate();
}


void CyDlg::OnBnClickedButton6()
{
	ADD_KC=false;
	CX_KC=false;
	CX_LS=true;
	GetDlgItem(IDC_BUTTON17)->EnableWindow(1);
	GetDlgItem(IDC_RADIO1)->ShowWindow(1);
	CButton *p=(CButton *)GetDlgItem(IDC_RADIO1);
	p->SetCheck(0);
	GetDlgItem(IDC_CHECK1)->ShowWindow(1);
	CButton *p1=(CButton *)GetDlgItem(IDC_CHECK1);
	p1->SetCheck(0);
	GetDlgItem(IDC_EDIT2)->ShowWindow(1);
	GetDlgItem(IDC_BUTTON11)->ShowWindow(1);
	GetDlgItem(IDC_BUTTON15)->SetWindowTextA( "保存");
		GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
		GetDlgItem(IDC_BUTTON4)->SetWindowTextA("□    新增");
		GetDlgItem(IDC_BUTTON5)->SetWindowTextA("□    编辑");
		GetDlgItem(IDC_BUTTON6)->SetWindowTextA("■    历史"); 
		CHeaderCtrl* pHeaderCtrl = m_L.GetHeaderCtrl();
		if (pHeaderCtrl != NULL)
		{
			int  nColumnCount = pHeaderCtrl->GetItemCount();
			for (int i=0; i<nColumnCount; i++)
			{
				m_L.DeleteColumn(0);
			}
		}
		m_L.DeleteAllItems();
		CRect rect;
		m_L.GetClientRect(&rect);
		// 为列表视图控件添加全行选中和栅格风格
		m_L.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES| LVS_EX_TWOCLICKACTIVATE);
		// 为列表视图控件添加7列   
		m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()/6,0); 
		m_L.InsertColumn(1,_T("日期"),LVCFMT_CENTER,rect.Width()/6,1); 
		m_L.InsertColumn(2,_T("型号"),LVCFMT_CENTER,rect.Width()/6,2); 
		m_L.InsertColumn(3,_T("入库"),LVCFMT_CENTER,rect.Width()/12,3); 
	    m_L.InsertColumn(4,_T("出库"),LVCFMT_CENTER,rect.Width()/12,4); 
		m_L.InsertColumn(5,_T("库存"),LVCFMT_CENTER,rect.Width()/12,5); 
		m_L.InsertColumn(6,_T("备注"),LVCFMT_CENTER,rect.Width()*3/12,6); 
		CString sql;
		sql.Format("SELECT * FROM inventory.history;");
		m_L.SetRedraw(FALSE);
		KC(sql);
		m_L.SetRedraw(TRUE);
		m_L.Invalidate();
}


void CyDlg::OnBnClickedButton1()
{
	CX_LR=false;
	ADD_DD=false;
	ADD_KH=false;
	CX_DD=false;
	TJ_DD=false;
	GetDlgItem(IDC_BUTTON17)->EnableWindow(0);
	GetDlgItem(IDC_COMBO1)->ShowWindow(0);
	GetDlgItem(IDC_COMBO1)->SetWindowTextA("按型号");
	    CHeaderCtrl* pHeaderCtrl = m_L.GetHeaderCtrl();
		if (pHeaderCtrl != NULL)
		{
			int  nColumnCount = pHeaderCtrl->GetItemCount();
			for (int i=0; i<nColumnCount; i++)
			{
				m_L.DeleteColumn(0);
			}
		}
		m_L.DeleteAllItems();
		CRect rect;
		m_L.GetClientRect(&rect);
		// 为列表视图控件添加全行选中和栅格风格
		m_L.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);
		// 为列表视图控件添加7列   
		m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()/6,0); 
		m_L.InsertColumn(1,_T("日期"),LVCFMT_CENTER,rect.Width()/6,1); 
		m_L.InsertColumn(2,_T("型号"),LVCFMT_CENTER,rect.Width()/6,2); 
		m_L.InsertColumn(3,_T("入库"),LVCFMT_CENTER,rect.Width()/12,3); 
	    m_L.InsertColumn(4,_T("出库"),LVCFMT_CENTER,rect.Width()/12,4); 
		m_L.InsertColumn(5,_T("库存"),LVCFMT_CENTER,rect.Width()/12,5); 
		m_L.InsertColumn(6,_T("备注"),LVCFMT_CENTER,rect.Width()*3/12,6); 
	

	KC_flagDJ=true;
	    GetDlgItem(IDC_BUTTON4)->ShowWindow(1);
		GetDlgItem(IDC_BUTTON5)->ShowWindow(1);
		GetDlgItem(IDC_BUTTON6)->ShowWindow(1);
	    GetDlgItem(IDC_BUTTON2)->SetWindowPos( NULL,0,210,0,0,SWP_NOZORDER | SWP_NOSIZE );
		GetDlgItem(IDC_BUTTON3)->SetWindowPos( NULL,0,250,0,0,SWP_NOZORDER | SWP_NOSIZE );
		CButton *p=(CButton *)GetDlgItem(IDC_CHECK1);
		p->SetCheck(0);
		GetDlgItem(IDC_CHECK1)->ShowWindow(0);
		CButton *p1=(CButton *)GetDlgItem(IDC_RADIO1);
		p1->SetCheck(0);
		GetDlgItem(IDC_RADIO1)->ShowWindow(0);

	    GetDlgItem(IDC_BUTTON7)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON8)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON9)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON10)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON12)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON13)->ShowWindow(0);
		GetDlgItem(IDC_STATIC1)->ShowWindow(0);
	GetDlgItem(IDC_STATIC2)->ShowWindow(0);
	GetDlgItem(IDC_STATIC3)->ShowWindow(0);
	GetDlgItem(IDC_STATIC4)->ShowWindow(0);
	GetDlgItem(IDC_DATETIMEPICKER1)->ShowWindow(0);
	GetDlgItem(IDC_DATETIMEPICKER2)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON14)->ShowWindow(0);
	GetDlgItem(IDC_EDIT3)->ShowWindow(0);
	GetDlgItem(IDC_EDIT4)->ShowWindow(0);
	m_kc.SetWindowTextA("◢   库存");
	GetDlgItem(IDC_BUTTON1)->SetWindowPos( NULL,0,55,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
	GetDlgItem(IDC_BUTTON2)->SetWindowTextA("◤  订单");
	GetDlgItem(IDC_BUTTON3)->SetWindowTextA("◤  客户");
	GetDlgItem(IDC_BUTTON12)->SetWindowTextA("□    新增");
	GetDlgItem(IDC_BUTTON13)->SetWindowTextA("□    编辑");
	GetDlgItem(IDC_BUTTON7)->SetWindowTextA("□    新增");
	GetDlgItem(IDC_BUTTON8)->SetWindowTextA("□    编辑");
	GetDlgItem(IDC_BUTTON9)->SetWindowTextA("□    统计");
	GetDlgItem(IDC_BUTTON10)->SetWindowTextA("□    补全");
	GetDlgItem(IDC_BUTTON15)->SetWindowTextA( "保存");
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
}


void CyDlg::OnBnClickedButton2()
{
	ADD_KC=false;
	CX_KH=false;
	ADD_KH=false;
	CX_KC=false;
	CX_LS=false;

	GetDlgItem(IDC_RADIO1)->ShowWindow(0);
	CButton *p=(CButton *)GetDlgItem(IDC_RADIO1);
	p->SetCheck(0);
		CHeaderCtrl* pHeaderCtrl = m_L.GetHeaderCtrl();
		if (pHeaderCtrl != NULL)
		{
			int  nColumnCount = pHeaderCtrl->GetItemCount();
			for (int i=0; i<nColumnCount; i++)
			{
				m_L.DeleteColumn(0);
			}
		}
		m_L.DeleteAllItems();
		CRect rect;
		m_L.GetClientRect(&rect);
		// 为列表视图控件添加全行选中和栅格风格
		m_L.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES);
		if(password=="6335598")
		{
		// 为列表视图控件添加8列   
			m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()*3/24,0); //  1/12
			m_L.InsertColumn(1,_T("日期"),LVCFMT_CENTER,rect.Width()*3/24,1); 
			m_L.InsertColumn(2,_T("型号"),LVCFMT_CENTER,rect.Width()*3/24,2); //  3/12
			m_L.InsertColumn(3,_T("客户"),LVCFMT_CENTER,rect.Width()/12,3); 
			m_L.InsertColumn(4,_T("数量"),LVCFMT_CENTER,rect.Width()/12,4); 
			m_L.InsertColumn(5,_T("单价"),LVCFMT_CENTER,rect.Width()/12,5); 
			m_L.InsertColumn(6,_T("金额"),LVCFMT_CENTER,rect.Width()/12,6); 
			m_L.InsertColumn(7,_T("备注"),LVCFMT_CENTER,rect.Width()*5/24,7); 
			m_L.InsertColumn(8,_T("利润"),LVCFMT_CENTER,rect.Width()/12,8); 
		}
		else
		{
			m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()*3/24,0); //  1/12
			m_L.InsertColumn(1,_T("日期"),LVCFMT_CENTER,rect.Width()/12,1); 
			m_L.InsertColumn(2,_T("型号"),LVCFMT_CENTER,rect.Width()*5/24,2); //  3/12
			m_L.InsertColumn(3,_T("客户"),LVCFMT_CENTER,rect.Width()/12,3); 
			m_L.InsertColumn(4,_T("数量"),LVCFMT_CENTER,rect.Width()/12,4); 
			m_L.InsertColumn(5,_T("单价"),LVCFMT_CENTER,rect.Width()/12,5); 
			m_L.InsertColumn(6,_T("金额"),LVCFMT_CENTER,rect.Width()/12,6); 
			m_L.InsertColumn(7,_T("备注"),LVCFMT_CENTER,rect.Width()*3/12,7); 
		}
	DD_flagDJ=true;
	    GetDlgItem(IDC_BUTTON1)->SetWindowPos( NULL,0,55,0,0,SWP_NOZORDER | SWP_NOSIZE );
		GetDlgItem(IDC_BUTTON3)->SetWindowPos( NULL,0,297,0,0,SWP_NOZORDER | SWP_NOSIZE );
		GetDlgItem(IDC_BUTTON7)->SetWindowPos( NULL,20,137,0,0,SWP_NOZORDER | SWP_NOSIZE );
		GetDlgItem(IDC_BUTTON8)->SetWindowPos( NULL,20,177,0,0,SWP_NOZORDER | SWP_NOSIZE );
		GetDlgItem(IDC_BUTTON9)->SetWindowPos( NULL,20,217,0,0,SWP_NOZORDER | SWP_NOSIZE );
		GetDlgItem(IDC_BUTTON10)->SetWindowPos( NULL,20,257,0,0,SWP_NOZORDER | SWP_NOSIZE );
		
		GetDlgItem(IDC_BUTTON7)->ShowWindow(1);
		GetDlgItem(IDC_BUTTON8)->ShowWindow(1);
		GetDlgItem(IDC_BUTTON9)->ShowWindow(1);
		GetDlgItem(IDC_BUTTON10)->ShowWindow(1);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON5)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON6)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON12)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON13)->ShowWindow(0);
		
		CButton *p1=(CButton *)GetDlgItem(IDC_CHECK1);
		p1->SetCheck(0);
		GetDlgItem(IDC_CHECK1)->ShowWindow(0);
		
	m_kc.SetWindowTextA("◤  库存");
	GetDlgItem(IDC_BUTTON3)->SetWindowTextA("◤  客户");
	GetDlgItem(IDC_BUTTON2)->SetWindowTextA("◢  订单");
	GetDlgItem(IDC_BUTTON4)->SetWindowTextA("□    新增");
	GetDlgItem(IDC_BUTTON5)->SetWindowTextA("□    编辑");
	GetDlgItem(IDC_BUTTON6)->SetWindowTextA("□    历史");
	GetDlgItem(IDC_BUTTON12)->SetWindowTextA("□    新增");
	GetDlgItem(IDC_BUTTON13)->SetWindowTextA("□    编辑");
	GetDlgItem(IDC_BUTTON15)->SetWindowTextA( "保存");
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON2)->SetWindowPos( NULL,0,97,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
	if(password=="88785268")
		GetDlgItem(IDC_BUTTON10)->ShowWindow(0);
	else
		GetDlgItem(IDC_BUTTON10)->ShowWindow(1);
}

void CyDlg::OnBnClickedButton3()
{
	ADD_KC=false;
	ADD_DD=false;//封锁订单新增
	CX_DD=false;
	TJ_DD=false;
	CX_KC=false;
	CX_LS=false;
	CX_LR=false;
	GetDlgItem(IDC_BUTTON17)->EnableWindow(0);
	GetDlgItem(IDC_RADIO1)->ShowWindow(0);
	CButton *p=(CButton *)GetDlgItem(IDC_RADIO1);
	p->SetCheck(0);

	GetDlgItem(IDC_CHECK1)->ShowWindow(0);
	CButton *p1=(CButton *)GetDlgItem(IDC_CHECK1);
	p1->SetCheck(0);

	GetDlgItem(IDC_COMBO1)->ShowWindow(0);
	GetDlgItem(IDC_COMBO1)->SetWindowTextA("按型号");
	    GetDlgItem(IDC_BUTTON1)->SetWindowPos( NULL,0,55,0,0,SWP_NOZORDER | SWP_NOSIZE );
		GetDlgItem(IDC_BUTTON2)->SetWindowPos( NULL,0,97,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
		GetDlgItem(IDC_BUTTON3)->SetWindowPos( NULL,0,137,0,0,SWP_NOZORDER | SWP_NOSIZE );		
		GetDlgItem(IDC_BUTTON12)->SetWindowPos( NULL,20,178,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
		GetDlgItem(IDC_BUTTON13)->SetWindowPos( NULL,20,217,0,0,SWP_NOZORDER | SWP_NOSIZE );		
		GetDlgItem(IDC_BUTTON12)->ShowWindow(1);
		GetDlgItem(IDC_BUTTON13)->ShowWindow(1);
		GetDlgItem(IDC_BUTTON7)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON8)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON9)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON10)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON5)->ShowWindow(0);
		GetDlgItem(IDC_BUTTON6)->ShowWindow(0);

		GetDlgItem(IDC_STATIC1)->ShowWindow(0);
	GetDlgItem(IDC_STATIC2)->ShowWindow(0);
	GetDlgItem(IDC_STATIC3)->ShowWindow(0);
	GetDlgItem(IDC_STATIC4)->ShowWindow(0);
	GetDlgItem(IDC_DATETIMEPICKER1)->ShowWindow(0);
	GetDlgItem(IDC_DATETIMEPICKER2)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON14)->ShowWindow(0);
	GetDlgItem(IDC_EDIT3)->ShowWindow(0);
	GetDlgItem(IDC_EDIT4)->ShowWindow(0);

	m_kc.SetWindowTextA("◤  库存");
	GetDlgItem(IDC_BUTTON2)->SetWindowTextA("◤  订单");
	GetDlgItem(IDC_BUTTON3)->SetWindowTextA("◢  客户");
	GetDlgItem(IDC_BUTTON4)->SetWindowTextA("□    新增");
	GetDlgItem(IDC_BUTTON5)->SetWindowTextA("□    编辑");
	GetDlgItem(IDC_BUTTON6)->SetWindowTextA("□    历史");
	GetDlgItem(IDC_BUTTON7)->SetWindowTextA("□    新增");
	GetDlgItem(IDC_BUTTON8)->SetWindowTextA("□    编辑");
	GetDlgItem(IDC_BUTTON9)->SetWindowTextA("□    统计");
	GetDlgItem(IDC_BUTTON10)->SetWindowTextA("□    补全");

	GetDlgItem(IDC_BUTTON3)->SetWindowPos( NULL,0,137,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
	

		CHeaderCtrl* pHeaderCtrl = m_L.GetHeaderCtrl();
		if (pHeaderCtrl != NULL)
		{
			int  nColumnCount = pHeaderCtrl->GetItemCount();
			for (int i=0; i<nColumnCount; i++)
			{
				m_L.DeleteColumn(0);
			}
		}
		m_L.DeleteAllItems();
		CRect rect;
		m_L.GetClientRect(&rect);
		// 为列表视图控件添加全行选中和栅格风格
		m_L.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES| LVS_EX_TWOCLICKACTIVATE);
		// 为列表视图控件添加5列   
		m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()*3/18,0); //1 
		m_L.InsertColumn(1,_T("姓名"),LVCFMT_CENTER,rect.Width()/9,1); //1 
		m_L.InsertColumn(2,_T("联系方式"),LVCFMT_CENTER,rect.Width()*3/9,2); //3
		m_L.InsertColumn(3,_T("联系地址"),LVCFMT_CENTER,rect.Width()*3/9,3); //3
	    m_L.InsertColumn(4,_T("发货物流"),LVCFMT_CENTER,rect.Width()/18,4); //3
	KH_flagDJ=true;
}
void CyDlg::Customer(CString SQL)
{
	m_L.DeleteAllItems();
	m_L.SetTextBkColor(RGB(199,237,204));
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCons,SQL);
	m_result=mysql_use_result(&m_sqlCons);
	int i=0;
	CString data[5];
	MYSQL_ROW row;
	while((row=mysql_fetch_row(m_result)))
	{
		//获取数据
		data[0]=row[0];
		data[1]=row[1];
		data[2]=row[2];
		data[3]=row[3];
		data[4]=row[4];
		// 在列表视图控件中插入列表项，并设置列表子项文本
		m_L.InsertItem(i, data[0]);
		m_L.SetItemText(i, 1,data[1]);
	    m_L.SetItemText(i, 2,data[2] );
		m_L.SetItemText(i, 3,data[3] );
		m_L.SetItemText(i, 4,data[4] );
		i++;
	}	
	mysql_free_result(m_result); //关联的内存会释放
}
void CyDlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	m_Row = pNMListView->iItem;//获得选中的行
	m_Col = pNMListView->iSubItem;//获得选中列


	if   (pNMListView->iSubItem != 0&&!TJ_DD&&!CX_KC) //如果选择的是子项;
	{
		m_L.GetSubItemRect(m_Row,m_Col,LVIR_LABEL,rc);//获得子项的RECT；
		m_edit.SetParent(&m_L);//转换坐标为列表框中的坐标
		m_edit.MoveWindow(rc);//移动Edit到RECT坐在的位置;
		m_edit.SetWindowText(m_L.GetItemText(m_Row,m_Col));//将该子项中的值放在Edit控件中；
		m_edit.ShowWindow(SW_SHOW);//显示Edit控件；
		m_edit.SetFocus();//设置Edit焦点
		m_edit.ShowCaret();//显示光标
		m_edit.SetSel(-1);//将光标移动到最后
		start_date=m_L.GetItemText(m_Row,m_Col);//还原初始数据
	}


	*pResult = 0;

}


void CyDlg::OnEnKillfocusEdit1()
{
	CString tem;
	m_edit.GetWindowText(tem);    //得到用户输入的新的内容
	m_L.SetItemText(m_Row,m_Col,tem);   //设置编辑框的新内容
	m_edit.ShowWindow(SW_HIDE); //应藏编辑框
	if(ADD_DD)
	{
		//自动添加单价
		if(!tem.IsEmpty()&&m_Col==2)
		{
			CString sql;
			sql.Format("SELECT G_price FROM inventory.goods where G_type='%s';",tem);
			//执行查询
			MYSQL_RES *m_result;
			mysql_query(&m_sqlCons,sql);
			m_result=mysql_use_result(&m_sqlCons);
			CString data[1]={};
			int i=0;
			MYSQL_ROW row;
			m_L.SetItemText(m_Row, 5,"" );
			while((row=mysql_fetch_row(m_result)))
			{
				//获取数据
				data[0]=row[0];
				i++;
				m_L.SetItemText(m_Row, 5,data[0] );
			}	
			mysql_free_result(m_result); //关联的内存会释放
		}
	}
	if(ADD_KC)
	{
		//判断型号是否为新型号  GX_KC=true ---不是;
		if(m_Col==2)
		 {
			CString SQL;
			SQL.Format("SELECT I_type,I_kc,I_remark FROM inventory.inventory where I_type='%s';",tem);
			//执行查询
			MYSQL_RES *m_result;
			mysql_query(&m_sqlCons,SQL);
			m_result=mysql_use_result(&m_sqlCons);
			CString data[3];
			MYSQL_ROW row;
			if((row=mysql_fetch_row(m_result)))
			{
				GX_KC=true;
				//获取数据
				data[0]=row[0];
				data[1]=row[1];
				data[2]=row[2];
				// 在列表视图控件中插入列表项，并设置列表子项文本
				m_L.SetItemText(m_Row, 5,data[1]);
				m_L.SetItemText(m_Row, 6,data[2]);
				
			}	
			else
			{
				GX_KC=false;
				m_L.SetItemText(m_Row, 5,"");	
			}
			mysql_free_result(m_result); //关联的内存会释放		
		}
		if(m_Col==3 || m_Col==4)
		{
			CString next;
			if(m_Col==3)
				next=m_L.GetItemText(m_Row,4);
			if(m_Col==4)
				next=m_L.GetItemText(m_Row,3);
			//自动计算库存
			if(!tem.IsEmpty()&&!next.IsEmpty())
			{
				CString kc;
				double kcnum;
				CString start_kc;
				double skc;
				start_kc=m_L.GetItemText(m_Row,5);
				if(!GX_KC)//是新型号
					skc=0;
				else if(start_kc.IsEmpty())
					skc=0;			
				else
					skc=atof(start_kc);
				if(m_Col==3)
					kcnum=skc+atof(tem)-atof(next);
				else
					kcnum=skc+atof(next)-atof(tem);
				kc.Format("%.1f",kcnum);
				if(kcnum<0)
					kc="×产生负库存(出入库数据输入出错)";
				m_L.SetItemText(m_Row, 5, kc);
			}
		}
	}
	//if(CX_KC || CX_LS)
	if(CX_LS)
	{
		CString id,s;
		s=m_L.GetItemText(m_Row,m_Col);
		id=m_L.GetItemText(m_Row,0);
		CString sql;
		/*if(CX_KC)
		{
			if(m_Col==1)
				sql.Format("update inventory.inventory set I_time='%s' where I_id=%s", s,id);
			if(m_Col==2)
				sql.Format("update inventory.inventory set I_type='%s' where I_id=%s", s,id);
			if(m_Col==3)
				sql.Format("update inventory.inventory set I_kc=%s where I_id=%s", s,id);
			if(m_Col==4)
				sql.Format("update inventory.inventory set I_remark='%s' where I_id=%s", s,id);
		}*/
	
			if(m_Col==1)
				sql.Format("update inventory.history set H_time='%s' where H_Id=%s", s,id);
			if(m_Col==2)
				sql.Format("update inventory.history set H_type='%s' where H_Id=%s", s,id);
			if(m_Col==3)
				sql.Format("update inventory.history set H_rk=%s where H_Id=%s", s,id);
			if(m_Col==4)
				sql.Format("update inventory.history set H_ck=%s where H_Id=%s", s,id);
			if(m_Col==5)
			{
				sql.Format("update inventory.history set H_kc=%s where H_Id=%s", s,id);
				if(  mysql_query(&m_sqlCons, sql)==0 )
				{
					id=m_L.GetItemText(m_Row,2);
					sql.Format("update inventory.inventory set I_kc=%s where I_type='%s'", s,id);
					mysql_query(&m_sqlCons, sql);
				}
				else{
					MessageBox("保存失败","提示");
					m_L.SetItemText(m_Row,m_Col,start_date);
				}
			}
			if(m_Col==6)
			{
				sql.Format("update inventory.history set H_remark='%s' where H_Id=%s", s,id);
				if(  mysql_query(&m_sqlCons, sql)==0 )
				{
					id=m_L.GetItemText(m_Row,2);
					sql.Format("update inventory.inventory set I_remark='%s' where I_type='%s'", s,id);
					mysql_query(&m_sqlCons, sql);
				}
				else{
					MessageBox("保存失败","提示");
					m_L.SetItemText(m_Row,m_Col,start_date);
				}
			}
		if(  mysql_query(&m_sqlCons, sql)==0 )
		{
			//MessageBox("保存成功","提示");
		}
		else{
			MessageBox("保存失败","提示");
			m_L.SetItemText(m_Row,m_Col,start_date);
		}
	}
	if(CX_KH)
	{
		CString id,s;
		s=m_L.GetItemText(m_Row,m_Col);
		id=m_L.GetItemText(m_Row,0);
		CString sql;
		if(m_Col==1)
			sql.Format("update inventory.customer set C_name='%s' where C_Id=%s", s,id);
		if(m_Col==2)
			sql.Format("update inventory.customer set C_phone='%s' where C_Id=%s", s,id);
		if(m_Col==3)
			sql.Format("update inventory.customer set C_address='%s' where C_Id=%s", s,id);
		if(m_Col==4)
			sql.Format("update inventory.customer set C_wuliu='%s' where C_Id=%s", s,id);

		if(  mysql_query(&m_sqlCons, sql)==0 )
		{
			//MessageBox("保存成功","提示");
		}
		else{
			MessageBox("保存失败","提示");
			m_L.SetItemText(m_Row,m_Col,start_date);
		}
	}
	if(CX_DD)
	{
		CString id,s;
		s=m_L.GetItemText(m_Row,m_Col);
		id=m_L.GetItemText(m_Row,0);
		CString sql;
		if(m_Col==1)
			sql.Format("update inventory.goods set G_time='%s' where G_id=%s", s,id);
		if(m_Col==2)
			sql.Format("update inventory.goods set G_type='%s' where G_id=%s", s,id);
		if(m_Col==3)
			sql.Format("update inventory.goods set G_customer='%s' where G_id=%s", s,id);
		if(m_Col==4)
			sql.Format("update inventory.goods set G_number=%s where G_id=%s", s,id);
		if(m_Col==5)
			sql.Format("update inventory.goods set G_price=%s where G_id=%s", s,id);
		if(m_Col==6)
			sql.Format("update inventory.goods set G_money=%s where G_id=%s", s,id);
		if(m_Col==7)
			sql.Format("update inventory.goods set G_remark='%s' where G_id=%s", s,id);
		if(m_Col==8&&password=="6335598")
		{
			if(!s.IsEmpty())
				sql.Format("update inventory.goods set G_profit=%s where G_id='%s'", s,id);
			else
				sql.Format("update inventory.goods set G_profit=null where G_id='%s'",id);
		}
			if(  mysql_query(&m_sqlCons, sql)==0 )
			{
				//MessageBox("保存成功","提示");
			}
			else{
				MessageBox("保存失败","提示");
				m_L.SetItemText(m_Row,m_Col,start_date);
			}
	}
}
void CyDlg::OnBnClickedButton11()
{
	if(CX_KC || CX_LS)
	{
		CString sql;
		CString text="";
		GetDlgItem(IDC_EDIT2)->GetWindowTextA(text);
		if(CX_KC)
		{
			/**************判断是否输入汉字***是（true）*************/
			char str[100];
			sprintf(str,"%s",text);
			int flag=false;
			for(int i = 0;i < 100;i++)
			{
				if((BYTE)str[i] >= 0x80)
				{
					flag=true;
				}
			}   
			/******************************/		
			if(text.IsEmpty())
				sql.Format("SELECT I_id,I_time,I_type,I_kc,I_remark FROM inventory.inventory;");
			else
			{
				if(!flag)
					sql.Format("SELECT I_id,I_time,I_type,I_kc,I_remark FROM inventory.inventory where  I_time like '%s%s%s' or I_type like '%s%s%s' or I_remark like '%s%s%s';","%",text,"%","%",text,"%","%",text,"%");
				else
					sql.Format("SELECT I_id,I_time,I_type,I_kc,I_remark FROM inventory.inventory where  I_type like '%s%s%s' or I_remark like '%s%s%s';","%",text,"%","%",text,"%");
			}
		}
		if(CX_LS)
		{
			/**************判断是否输入汉字***是（true）*************/
			char str[100];
			sprintf(str,"%s",text);
			int flag=false;
			for(int i = 0;i < 100;i++)
			{
				if((BYTE)str[i] >= 0x80)
				{
					flag=true;
				}
			}   
			/******************************/
			if(text.IsEmpty())
			{
				CButton *p=(CButton *)GetDlgItem(IDC_RADIO1);
				if(!p->GetCheck())
					sql.Format("SELECT * FROM inventory.history;");
				else
					sql.Format("select * from inventory.history order by H_type, H_Id ASC;  ");
			}
			else
			{
				if(!flag)
					sql.Format("SELECT * FROM inventory.history where  H_time like '%s%s%s' or H_type like '%s%s%s' or H_remark like '%s%s%s';","%",text,"%","%",text,"%","%",text,"%");
				else
					sql.Format("SELECT * FROM inventory.history where  H_type like '%s%s%s' or H_remark like '%s%s%s';","%",text,"%","%",text,"%");
			}
		}
		m_L.SetRedraw(FALSE);
		KC(sql);
		m_L.SetRedraw(TRUE);
		m_L.Invalidate();
	}
	if(CX_KH)
	{
		CString sql;
		CString text="";
		GetDlgItem(IDC_EDIT2)->GetWindowTextA(text);
		if(text.IsEmpty())
			sql.Format("SELECT * FROM inventory.customer;");
		else
			sql.Format("SELECT * FROM inventory.customer where C_name like '%s%s%s' or C_phone like '%s%s%s'  or C_address like '%s%s%s' or C_wuliu like '%s%s%s';","%",text,"%","%",text,"%","%",text,"%","%",text,"%");
		Customer(sql);
	}
	if(CX_DD)
	{
		CString sql;
		CString text="";
		GetDlgItem(IDC_EDIT2)->GetWindowTextA(text);
		if(text.IsEmpty())
			sql.Format("SELECT * FROM inventory.goods;");
		else
		{
			/**************判断是否输入汉字***是（true）*************/
	/*		char str[100];
			sprintf(str,"%s",text);
			int flag=false;
			for(int i = 0;i < 100;i++)
			{
				if((BYTE)str[i] >= 0x80)
					flag=true;
			}   */
			/******************************/
			sql.Format("SELECT * FROM inventory.goods where  G_customer like '%s%s%s' or G_type like '%s%s%s' or G_remark like '%s%s%s';","%",text,"%","%",text,"%","%",text,"%");
		}	
		m_L.SetRedraw(FALSE);
		DD(sql);
		m_L.SetRedraw(TRUE);
		m_L.Invalidate();
	}
}


void CyDlg::OnBnClickedButton13()
{
	GetDlgItem(IDC_BUTTON17)->EnableWindow(1);
	GetDlgItem(IDC_RADIO1)->ShowWindow(0);
	CButton *p=(CButton *)GetDlgItem(IDC_RADIO1);
	p->SetCheck(0);
	GetDlgItem(IDC_EDIT2)->ShowWindow(1);
	GetDlgItem(IDC_BUTTON11)->ShowWindow(1);
	GetDlgItem(IDC_CHECK1)->ShowWindow(1);
	CString sql;
	sql.Format("SELECT * FROM inventory.customer;");
	m_L.SetRedraw(FALSE);
	Customer(sql);
	m_L.SetRedraw(TRUE);
	m_L.Invalidate();
	CX_KH=true;//查询激活
	ADD_KH=false;//新增封锁
	GetDlgItem(IDC_BUTTON13)->SetWindowTextA( "■    编辑");
	GetDlgItem(IDC_BUTTON12)->SetWindowTextA( "□    新增");
	GetDlgItem(IDC_BUTTON15)->SetWindowTextA( "□    删除");
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
}


void CyDlg::OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	 NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
           if(pNMListView->iItem != -1&&!TJ_DD)
           {
                DWORD dwPos = GetMessagePos();
                CPoint point( LOWORD(dwPos), HIWORD(dwPos) );
                CMenu menu;
                VERIFY( menu.LoadMenu( IDR_MENU1 ) );
                CMenu* popup = menu.GetSubMenu(0);
                ASSERT( popup != NULL );
                popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );

				int i=m_L.GetSelectionMark();//获得选 中行的行标
				
				Delete_id=m_L.GetItemText(i,0);//i是行，j是列。m_list是个list control 对象
				Delete_type=m_L.GetItemText(i,2);
		   } 
	*pResult = 0;
}


void CyDlg::On32771()
{
	int j=atoi(Delete_id);
	if(ADD_KC)
	{
		m_L.SetItemText(j-1,2,"");
		m_L.SetItemText(j-1,3,"");
		m_L.SetItemText(j-1,4,"");
		m_L.SetItemText(j-1,5,"");
		m_L.SetItemText(j-1,6,"");
	}
	else if(m_L.DeleteAllItems()!=0)
	{	   
			CString sql;
			if(CX_KH)
			{
				sql.Format("DELETE FROM inventory.customer where C_Id=%s",Delete_id);
				mysql_query(&m_sqlCons,sql);
				sql.Format("SELECT * FROM inventory.customer;");
				Customer(sql);
			}
			if(CX_DD)
			{
				sql.Format("DELETE FROM inventory.goods where G_id=%s",Delete_id);
				mysql_query(&m_sqlCons,sql);
				sql.Format("SELECT * FROM inventory.goods;");
				m_L.SetRedraw(FALSE);
				DD(sql);
				m_L.SetRedraw(TRUE);
				m_L.Invalidate();
			}
			if(CX_KC)
			{
				sql.Format("DELETE FROM inventory.inventory where I_id=%s",Delete_id);
				mysql_query(&m_sqlCons,sql);
				sql.Format("SELECT * FROM inventory.inventory;");
				m_L.SetRedraw(FALSE);
				KC(sql);
				m_L.SetRedraw(TRUE);
				m_L.Invalidate();
				if(MessageBox("是否删除该型号相应的历史记录？","提示",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
				{
					sql.Format("DELETE FROM inventory.history where H_type=%s",Delete_type);
					mysql_query(&m_sqlCons,sql);
				}
			}
			if(CX_LS)
			{
				sql.Format("DELETE FROM inventory.history where H_Id=%s",Delete_id);
				mysql_query(&m_sqlCons,sql);
				sql.Format("SELECT * FROM inventory.history;");
				m_L.SetRedraw(FALSE);
				KC(sql);
				m_L.SetRedraw(TRUE);
				m_L.Invalidate();
			}
	}
}


void CyDlg::OnBnClickedButton12()
{
	CX_KH=false;
	GetDlgItem(IDC_BUTTON17)->EnableWindow(0);
	GetDlgItem(IDC_RADIO1)->ShowWindow(0);
	CButton *p=(CButton *)GetDlgItem(IDC_RADIO1);
	p->SetCheck(0);
	m_L.DeleteAllItems();
	m_L.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES| LVS_EX_TWOCLICKACTIVATE);
	m_L.SetTextBkColor(RGB(199,237,204));
	CString x;
	for(int i=0;i<20;i++)
	{
		x.Format("%d",i+1);
	    m_L.InsertItem(i, x);
		ADD_KH=true;
	}
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_EDIT2)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON11)->ShowWindow(0);
	GetDlgItem(IDC_CHECK1)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON12)->SetWindowTextA("■    新增");
	GetDlgItem(IDC_BUTTON13)->SetWindowTextA("□    编辑");
	GetDlgItem(IDC_BUTTON15)->SetWindowTextA("保存");
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	CButton *p1=(CButton *)GetDlgItem(IDC_CHECK1);
	p1->SetCheck(0);
}




void CyDlg::DD(CString sql)
{
	m_L.DeleteAllItems();
	m_L.SetTextBkColor(RGB(199,237,204));
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCons,sql);
	m_result=mysql_use_result(&m_sqlCons);
	CString data[9],sl,je,lr;
	double SL=0,SLSUM=0,JE=0,JESUM=0,LR=0,LRSUM=0;
	int i=0;
	MYSQL_ROW row;
	bool q=false;
	while((row=mysql_fetch_row(m_result)))
	{
		q=true;
		//获取数据
		data[0]=row[0];
		data[1]=row[1];
		data[2]=row[2];
		data[3]=row[3];
		data[4]=row[4];
		data[5]=row[5];
		data[6]=row[6];
		data[7]=row[7];
		SL=atof(data[4]);
		JE=atof(data[6]);

		SLSUM=SLSUM+SL;
		JESUM=JESUM+JE;
		// 在列表视图控件中插入列表项，并设置列表子项文本
		m_L.InsertItem(i, data[0]);
		m_L.SetItemText(i, 1,data[1]);
	    m_L.SetItemText(i, 2,data[2] );
		m_L.SetItemText(i, 3,data[3] );
		m_L.SetItemText(i, 4,data[4] );
		m_L.SetItemText(i, 5,data[5] );
		m_L.SetItemText(i, 6,data[6] );
		m_L.SetItemText(i, 7,data[7] );
		if(password=="6335598")
		{
			data[8]=row[8];
			LR=atof(data[8]);
			LRSUM=LRSUM+LR;
			m_L.SetItemText(i, 8,data[8] );
		}
		i++;
	}
	if(!q)
		MessageBox("经查询，无此条件订单记录。","提示",MB_ICONEXCLAMATION|MB_OK);
	else if(TJ_DD)
	{
		sl.Format("%.1lf",SLSUM);
		je.Format("%.1lf",JESUM);
		lr.Format("%.1lf",LRSUM);
		m_L.InsertItem(i, "■■■■■");
	    m_L.SetItemText(i, 1,"■■■■■" );
		m_L.SetItemText(i, 2,"总和" );
		m_L.SetItemText(i, 3,"数量:" );
		m_L.SetItemText(i, 4,sl );
		m_L.SetItemText(i, 5,"金额:" );
		m_L.SetItemText(i, 6,je );		
		if(password=="6335598")
		{
			m_L.SetItemText(i, 7,"利润:" );
			m_L.SetItemText(i, 8, lr);
		}
		else m_L.SetItemText(i, 7, "■■■■■■■■■■■■■■■■■");
	}
	mysql_free_result(m_result); //关联的内存会释放

}
void CyDlg::OnBnClickedButton9()
{
	GetDlgItem(IDC_BUTTON17)->EnableWindow(1);
	CX_LR=false;
	TJ_DD=true;
	CX_DD=false;
	ADD_DD=false;
	m_L.DeleteAllItems();
	GetDlgItem(IDC_COMBO1)->ShowWindow(1);
	GetDlgItem(IDC_COMBO1)->SetWindowTextA("按型号");
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_STATIC1)->ShowWindow(1);
	GetDlgItem(IDC_STATIC2)->ShowWindow(1);
	GetDlgItem(IDC_STATIC3)->ShowWindow(1);
	GetDlgItem(IDC_STATIC4)->ShowWindow(1);
	GetDlgItem(IDC_DATETIMEPICKER1)->ShowWindow(1);
	GetDlgItem(IDC_DATETIMEPICKER2)->ShowWindow(1);
	GetDlgItem(IDC_BUTTON14)->ShowWindow(1);
	GetDlgItem(IDC_EDIT3)->ShowWindow(1);
	GetDlgItem(IDC_EDIT4)->ShowWindow(1);
	GetDlgItem(IDC_EDIT2)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON11)->ShowWindow(0);
	GetDlgItem(IDC_CHECK1)->ShowWindow(0);
	CButton *p=(CButton *)GetDlgItem(IDC_CHECK1);
	p->SetCheck(0);
	GetDlgItem(IDC_RADIO1)->ShowWindow(1);
	CButton *p1=(CButton *)GetDlgItem(IDC_RADIO1);
	p1->SetCheck(0);

	GetDlgItem(IDC_BUTTON9)->SetWindowTextA("■    统计");
	GetDlgItem(IDC_BUTTON7)->SetWindowTextA("□    新增");
	GetDlgItem(IDC_BUTTON8)->SetWindowTextA("□    编辑");
	GetDlgItem(IDC_BUTTON10)->SetWindowTextA("□    补全");
}


void CyDlg::OnBnClickedButton14()
{

	CTime tm;
	CString rq1,rq2,kh,xh;
	m_d1.GetTime(tm);
	rq1=tm.Format("%Y%m%d");
	m_d2.GetTime(tm);
	rq2=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(kh);
	GetDlgItem(IDC_EDIT3)->GetWindowTextA(xh);
	CString sql;
	m_L.DeleteAllItems();
	if(kh.IsEmpty()&&xh.IsEmpty())
		sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s';",rq1,rq2);
	else//1 0  ； 0 1 ； 1 1
	{
		if(!kh.IsEmpty())//1 0 ；1 1
		{
			sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' and G_customer='%s';",rq1,rq2,kh);
			if(!xh.IsEmpty())
				sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' and G_customer='%s' and G_type='%s';",rq1,rq2,kh,xh);
		}
		else //0 1
			sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' and G_type='%s';",rq1,rq2,xh);
	}
	        m_L.SetRedraw(FALSE);
			DD(sql);
			m_L.SetRedraw(TRUE);
			m_L.Invalidate();
	
}


void CyDlg::OnBnClickedButton10()
{
	CX_DD=true;
	CX_LR=true;
	ADD_DD=false;
	TJ_DD=false;
	GetDlgItem(IDC_BUTTON17)->EnableWindow(0);
	GetDlgItem(IDC_RADIO1)->ShowWindow(1);
	CButton *p=(CButton *)GetDlgItem(IDC_RADIO1);
	p->SetCheck(0);
	GetDlgItem(IDC_COMBO1)->ShowWindow(1);
	GetDlgItem(IDC_COMBO1)->SetWindowTextA("按型号");
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_EDIT2)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON11)->ShowWindow(0);
	GetDlgItem(IDC_STATIC1)->ShowWindow(0);
	GetDlgItem(IDC_STATIC2)->ShowWindow(0);
	GetDlgItem(IDC_STATIC3)->ShowWindow(0);
	GetDlgItem(IDC_STATIC4)->ShowWindow(0);
	GetDlgItem(IDC_DATETIMEPICKER1)->ShowWindow(0);
	GetDlgItem(IDC_DATETIMEPICKER2)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON14)->ShowWindow(0);
	GetDlgItem(IDC_EDIT3)->ShowWindow(0);
	GetDlgItem(IDC_EDIT4)->ShowWindow(0);
	GetDlgItem(IDC_CHECK1)->ShowWindow(0);
	CButton *p1=(CButton *)GetDlgItem(IDC_CHECK1);
	p1->SetCheck(0);
	GetDlgItem(IDC_BUTTON9)->SetWindowTextA("□    统计");
	GetDlgItem(IDC_BUTTON7)->SetWindowTextA("□    新增");
	GetDlgItem(IDC_BUTTON8)->SetWindowTextA("□    编辑");
	GetDlgItem(IDC_BUTTON10)->SetWindowTextA("■    补全");

	CString sql;
	sql.Format("SELECT * FROM inventory.goods where G_profit is null;");
	m_L.SetRedraw(FALSE);
	DD(sql);
	m_L.SetRedraw(TRUE);
	m_L.Invalidate();
}


void CyDlg::OnBnClickedButton8()
{
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON17)->EnableWindow(1);
	CX_DD=true;
	ADD_DD=false;
	TJ_DD=false;
	CX_LR=false;
	GetDlgItem(IDC_COMBO1)->ShowWindow(1);
	GetDlgItem(IDC_COMBO1)->SetWindowTextA("按型号");
	GetDlgItem(IDC_EDIT2)->ShowWindow(1);
	GetDlgItem(IDC_BUTTON11)->ShowWindow(1);

	GetDlgItem(IDC_CHECK1)->ShowWindow(1);
	CButton *p=(CButton *)GetDlgItem(IDC_CHECK1);
	p->SetCheck(0);
	
	GetDlgItem(IDC_RADIO1)->ShowWindow(1);
	CButton *p1=(CButton *)GetDlgItem(IDC_RADIO1);
	p1->SetCheck(0);

	GetDlgItem(IDC_STATIC1)->ShowWindow(0);
	GetDlgItem(IDC_STATIC2)->ShowWindow(0);
	GetDlgItem(IDC_STATIC3)->ShowWindow(0);
	GetDlgItem(IDC_STATIC4)->ShowWindow(0);
	GetDlgItem(IDC_DATETIMEPICKER1)->ShowWindow(0);
	GetDlgItem(IDC_DATETIMEPICKER2)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON14)->ShowWindow(0);
	GetDlgItem(IDC_EDIT3)->ShowWindow(0);
	GetDlgItem(IDC_EDIT4)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON8)->SetWindowTextA("■    编辑");
	GetDlgItem(IDC_BUTTON7)->SetWindowTextA("□    新增");
	GetDlgItem(IDC_BUTTON9)->SetWindowTextA("□    统计");
	GetDlgItem(IDC_BUTTON10)->SetWindowTextA("□    补全");
	
	CString sql;
	sql.Format("SELECT * FROM inventory.goods;");
	m_L.SetRedraw(FALSE);
	DD(sql);
	m_L.SetRedraw(TRUE);
	m_L.Invalidate();
}


void CyDlg::OnBnClickedButton7()
{
	CX_DD=false;
	TJ_DD=false;
	CX_LR=false;
	GetDlgItem(IDC_BUTTON17)->EnableWindow(0);
	GetDlgItem(IDC_COMBO1)->ShowWindow(0);
	GetDlgItem(IDC_RADIO1)->ShowWindow(0);
	CButton *p=(CButton *)GetDlgItem(IDC_RADIO1);
	p->SetCheck(0);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_EDIT2)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON11)->ShowWindow(0);
	GetDlgItem(IDC_STATIC1)->ShowWindow(0);
	GetDlgItem(IDC_STATIC2)->ShowWindow(0);
	GetDlgItem(IDC_STATIC3)->ShowWindow(0);
	GetDlgItem(IDC_STATIC4)->ShowWindow(0);
	GetDlgItem(IDC_DATETIMEPICKER1)->ShowWindow(0);
	GetDlgItem(IDC_DATETIMEPICKER2)->ShowWindow(0);
	GetDlgItem(IDC_BUTTON14)->ShowWindow(0);
	GetDlgItem(IDC_EDIT3)->ShowWindow(0);
	GetDlgItem(IDC_EDIT4)->ShowWindow(0);
	GetDlgItem(IDC_CHECK1)->ShowWindow(0);
	CButton *p1=(CButton *)GetDlgItem(IDC_CHECK1);
	p1->SetCheck(0);

	m_L.DeleteAllItems();
	m_L.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES| LVS_EX_TWOCLICKACTIVATE);
	m_L.SetTextBkColor(RGB(199,237,204));
	CString x;

	SYSTEMTIME st;
	CString strDate;
	GetLocalTime(&st);
	strDate.Format("%4d-%d-%d",st.wYear,st.wMonth,st.wDay);

	for(int i=0;i<20;i++)
	{
		x.Format("%d",i+1);
	    m_L.InsertItem(i, x);
		m_L.SetItemText(i,1,strDate);
		ADD_DD=true;
	}
	GetDlgItem(IDC_BUTTON7)->SetWindowTextA("■    新增");
	GetDlgItem(IDC_BUTTON8)->SetWindowTextA("□    编辑");
	GetDlgItem(IDC_BUTTON9)->SetWindowTextA("□    统计");
	GetDlgItem(IDC_BUTTON10)->SetWindowTextA("□    补全");
	GetDlgItem(IDC_BUTTON15)->SetWindowTextA("保存");
}

void CyDlg::OnBnClickedButton15()
{
	if(ADD_KH)
	{
		CString name,phone,address,wl;
		CString sql;
		int i=0;
		while(!m_L.GetItemText(i,1).IsEmpty())
		{
			name=m_L.GetItemText(i,1);
			phone=m_L.GetItemText(i,2);
			address=m_L.GetItemText(i,3);
			wl=m_L.GetItemText(i,4);
			sql.Format("INSERT INTO inventory.customer value(null, '%s', '%s', '%s', '%s')", name,phone,address,wl );	
			if(  mysql_query(&m_sqlCons, sql)==0 )
			{
				m_L.DeleteItem(i);
				i--;
			}
			else
				m_L.SetItemText(i,0,"该行保存出错(姓名重复)×");
			i++;
		}
	}
	if(ADD_DD)
	{
		CString time,type,name,num,price,money,remark,profit;
		CString sql;
		int i=0;
		while(!m_L.GetItemText(i,2).IsEmpty())
		{
			time=m_L.GetItemText(i,1);
			type=m_L.GetItemText(i,2);
			name=m_L.GetItemText(i,3);
			num=m_L.GetItemText(i,4);
			price=m_L.GetItemText(i,5);
			money=m_L.GetItemText(i,6);
			remark=m_L.GetItemText(i,7);
			profit=m_L.GetItemText(i,8);
			if(profit.IsEmpty())
				profit="null";
			sql.Format("INSERT INTO inventory.goods value(null, '%s', '%s', '%s', %s, %s, %s, '%s', %s)",time,type, name,num,price,money,remark,profit );
			if(  mysql_query(&m_sqlCons, sql)==0 )
			{
				m_L.DeleteItem(i);
				i--;
			}
			else
				m_L.SetItemText(i,0,"该行保存出错  ×");
			i++;
		}
	}
	if(ADD_KC)
	{
		CString time,type,rk,ck,kc,remark;
		CString sql;
		int i=0;
		while(!m_L.GetItemText(i,2).IsEmpty())
		{
			time=m_L.GetItemText(i,1);
			type=m_L.GetItemText(i,2);
			rk=m_L.GetItemText(i,3);
			ck=m_L.GetItemText(i,4);
			kc=m_L.GetItemText(i,5);
			remark=m_L.GetItemText(i,6);
			if(!GX_KC)//是新型号
			{
				sql.Format("INSERT INTO inventory.inventory value(null, '%s', '%s', %s, %s, %s, '%s')",time,type, rk,ck,kc,remark);
				if(  mysql_query(&m_sqlCons, sql)==0 )
				{
						sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,type, rk,ck,kc,remark );
						mysql_query(&m_sqlCons, sql);
					m_L.DeleteItem(i);
					i--;
				}
				else
					m_L.SetItemText(i,0,"该行保存出错  ×");
				i++;
			}
			else
			{						
				sql.Format("update inventory.inventory set I_time='%s',I_kc=%s,I_rk=%s,I_ck=%s,I_remark='%s' where I_type='%s'",time,kc,rk,ck,remark,type);
				if(  mysql_query(&m_sqlCons, sql)==0 )
				{
						sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,type, rk,ck,kc,remark );
						mysql_query(&m_sqlCons, sql);
						m_L.DeleteItem(i);
						i--;
				}
				else
					m_L.SetItemText(i,0,"该行保存出错  ×");
				i++;
			}
		}
	}

	if(CX_KH)//客户删除
	{	
		CString id;
		CString sql;
		for(int i=0; i <m_L.GetItemCount(); i++) 
		{ 
			if(m_L.GetCheck(i))
			{
				id=m_L.GetItemText(i,0);
					
					sql.Format("DELETE FROM inventory.customer where C_Id=%s",id);
					mysql_query(&m_sqlCons,sql);
			}
		} 
		sql.Format("SELECT * FROM inventory.customer;");
		Customer(sql);
	}
	if(CX_DD)//订单删除
	{
		CString id;
		CString sql;
		for(int i=0; i <m_L.GetItemCount(); i++) 
		{ 
			if(m_L.GetCheck(i))
			{
				id=m_L.GetItemText(i,0);	
				sql.Format("DELETE FROM inventory.goods where G_id=%s",id);
				mysql_query(&m_sqlCons,sql);
			}
		} 
		sql.Format("SELECT * FROM inventory.goods;");
		DD(sql);
	}
	if(CX_KC)
	{
		CString id;
		CString sql;
		for(int i=0; i <m_L.GetItemCount(); i++) 
		{ 
			if(m_L.GetCheck(i))
			{
				id=m_L.GetItemText(i,0);	
				sql.Format("DELETE FROM inventory.inventory where I_id=%s",id);
				mysql_query(&m_sqlCons,sql);
			}
		} 
		sql.Format("SELECT * FROM inventory.inventory;");
		KC(sql);
	}
	if(CX_LS)
	{
		CString id;
		CString sql;
		for(int i=0; i <m_L.GetItemCount(); i++) 
		{ 
			if(m_L.GetCheck(i))
			{
				id=m_L.GetItemText(i,0);	
				sql.Format("DELETE FROM inventory.history where H_Id=%s",id);
				mysql_query(&m_sqlCons,sql);
			}
		} 
		sql.Format("SELECT * FROM inventory.history;");
		KC(sql);
	}
}





void CyDlg::OnHdnItemclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	if(phdr->iItem==6&&ADD_DD)
	{
		int i=0;
		CString JE;
		double sl,dj,je;
		while(!m_L.GetItemText(i,4).IsEmpty()&&!m_L.GetItemText(i,5).IsEmpty())
		{
			sl=atof(m_L.GetItemText(i,4));
			dj=atof(m_L.GetItemText(i,5));
			je=sl*dj;
			JE.Format("%.1f",je);
			m_L.SetItemText(i,6,JE);
			i++;
		}
	}
	*pResult = 0;
}

void CyDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}
void CyDlg::KC(CString SQL)
{
	m_L.DeleteAllItems();
	m_L.SetTextBkColor(RGB(199,237,204));
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCons,SQL);
	m_result=mysql_use_result(&m_sqlCons);
	int i=0;
	CString data[7];
	MYSQL_ROW row;
	while((row=mysql_fetch_row(m_result)))
	{
		//获取数据
		data[0]=row[0];
		data[1]=row[1];
		data[2]=row[2];
		data[3]=row[3];
		data[4]=row[4];
		if(!CX_KC)
		{
			data[5]=row[5];
			data[6]=row[6];
		}
		// 在列表视图控件中插入列表项，并设置列表子项文本
		m_L.InsertItem(i, data[0]);
		m_L.SetItemText(i, 1,data[1]);
	    m_L.SetItemText(i, 2,data[2] );
		m_L.SetItemText(i, 3,data[3] );
		m_L.SetItemText(i, 4,data[4] );
		if(!CX_KC)
		{
			m_L.SetItemText(i, 5,data[5] );
			m_L.SetItemText(i, 6,data[6] );
		}
		i++;
	}	
	mysql_free_result(m_result); //关联的内存会释放
}

void CyDlg::OnBnClickedRadio1()
{
	CButton *p=(CButton *)GetDlgItem(IDC_RADIO1);
	if(CX_LS)
	{
			CString sql;
			sql.Format("select * from inventory.history order by H_type, H_Id ASC;  ");
			m_L.SetRedraw(FALSE);
			KC(sql);
			m_L.SetRedraw(TRUE);
			m_L.Invalidate();
	}
	
	if(CX_DD)
	{		
		CString x;
		GetDlgItem(IDC_COMBO1)->GetWindowTextA(x);
			CString sql;
		if(!CX_LR)
		{
			if(x=="按型号")
				sql.Format("select * from inventory.goods order by G_type, G_id ASC;  ");
			else
				sql.Format("select * from inventory.goods order by G_customer, G_id ASC;  ");		
		}
		else
		{
			if(x=="按型号")
				sql.Format("select * from inventory.goods where G_profit is null order by G_type, G_id ASC;  ");
			else
				sql.Format("select * from inventory.goods where G_profit is null order by G_customer, G_id ASC;  ");		
		}
		    m_L.SetRedraw(FALSE);
			DD(sql);
			m_L.SetRedraw(TRUE);
			m_L.Invalidate();
	}
	if(TJ_DD)
	{
		CString x;
		GetDlgItem(IDC_COMBO1)->GetWindowTextA(x);
			CString sql;
			CTime tm;
			CString rq1,rq2,kh,xh;
			m_d1.GetTime(tm);
			rq1=tm.Format("%Y%m%d");
			m_d2.GetTime(tm);
			rq2=tm.Format("%Y%m%d");
			GetDlgItem(IDC_EDIT4)->GetWindowTextA(kh);
			GetDlgItem(IDC_EDIT3)->GetWindowTextA(xh);
			if(x=="按型号")
			{
				if(kh.IsEmpty()&&xh.IsEmpty())
					sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' order by G_type, G_id ASC;",rq1,rq2);
				else//1 0  ； 0 1 ； 1 1
				{
					if(!kh.IsEmpty())//1 0 ；1 1
					{
						sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' and G_customer='%s' order by G_type, G_id ASC;",rq1,rq2,kh);
						if(!xh.IsEmpty())
							sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' and G_customer='%s' and G_type='%s' order by G_type, G_id ASC;",rq1,rq2,kh,xh);
					}
					else //0 1
						sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' and G_type='%s' order by G_type, G_id ASC;",rq1,rq2,xh);
				}
			}
			else
			{
				if(kh.IsEmpty()&&xh.IsEmpty())
					sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' order by G_customer, G_id ASC;",rq1,rq2);
				else//1 0  ； 0 1 ； 1 1
				{
					if(!kh.IsEmpty())//1 0 ；1 1
					{
						sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' and G_customer='%s' order by G_customer, G_id ASC;",rq1,rq2,kh);
						if(!xh.IsEmpty())
							sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' and G_customer='%s' and G_type='%s' order by G_customer, G_id ASC;",rq1,rq2,kh,xh);
					}
					else //0 1
						sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' and G_type='%s' order by G_customer, G_id ASC;",rq1,rq2,xh);
				}
			}	
		    m_L.SetRedraw(FALSE);
			DD(sql);
			m_L.SetRedraw(TRUE);
			m_L.Invalidate();
	}
}


void CyDlg::OnBnClickedCancel()
{
	//1.获取当前时间做EXCEL的文件名：
	WORD  sYear,sMonth,sDay,sHour,sMinute,sSecond; 
    SYSTEMTIME  CurTime;/////定义SYSTEMTIME类的对象 
    GetLocalTime(&CurTime);////获取本地时间 
    sYear=CurTime.wYear;////获得年 
    sMonth=CurTime.wMonth;//获得月 
    sDay=CurTime.wDay; 
    sHour=CurTime.wHour; 
    sMinute=CurTime.wMinute; 
	sSecond=CurTime.wSecond; 
	CString time;
	time.Format("%d年%d月%d日%d点%d分%d秒",sYear,sMonth,sDay,sHour,sMinute,sSecond);

	if(MessageBox("退出系统？","提示",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
	{
		MessageBox("正在备份......","提示");
		CString SQL;
		SQL.Format("select * from inventory.inventory into outfile 'D://inventory_backup//inventory_inventory%s.sql';",time);
		if(mysql_query(&m_sqlCons,SQL)==0)
		{
			SQL.Format("select * from inventory.history into outfile 'D://inventory_backup//inventory_history%s.sql';",time);
			if(mysql_query(&m_sqlCons,SQL)==0)
			{
				SQL.Format("select * from inventory.goods into outfile 'D://inventory_backup//inventory_goods%s.sql';",time);
				if(mysql_query(&m_sqlCons,SQL)==0)
				{
					SQL.Format("select * from inventory.customer into outfile 'D://inventory_backup//inventory_customer%s.sql';",time);
					if(mysql_query(&m_sqlCons,SQL)==0)
					{
				        MessageBox("备份结束。","提示");		
					}
				}
			}
		}
		CDialogEx::OnOK();
	}
}


void CyDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//定义一个位图对象 
	CBitmap m_Back;
	if(YDMenu)
	{
		m_Back.LoadBitmap(IDB_BITMAP3);
	}
	else 
	{
		if(Menu)
			m_Back.LoadBitmap(IDB_BITMAP1);
		else
			m_Back.LoadBitmap(IDB_BITMAP2);
	}
	//定义一个内存设备描述表对象（即后备缓冲区）  
	CDC mdc;
	//建立与屏幕设备描述表（前端缓冲区）兼容的内存设备描述表句柄（后备缓冲区）  
    mdc.CreateCompatibleDC(&dc); 
	//绘图
	mdc.SelectObject(&m_Back);
	//将后备缓冲区中的图形拷贝到前端缓冲区  
	dc.BitBlt(0,0,127,95,&mdc,0,0,SRCCOPY);	
	//绘图完成后的清理  
	m_Back.DeleteObject();  
	mdc.DeleteDC();
	// 不为绘图消息调用 CDialogEx::OnPaint()
}


void CyDlg::OnBnClickedCheck1()
{
	//MessageBox("1");
	CButton *p= (CButton*)GetDlgItem(IDC_CHECK1);
	if(p->GetCheck())
	{
		GetDlgItem(IDC_BUTTON15)->SetWindowTextA( "■    删除");
		GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	    CHeaderCtrl* pHeaderCtrl = m_L.GetHeaderCtrl();
		if (pHeaderCtrl != NULL)
		{
			int  nColumnCount = pHeaderCtrl->GetItemCount();
			for (int i=0; i<nColumnCount; i++)
			{
				m_L.DeleteColumn(0);
			}
		}
	    m_L.DeleteAllItems();
		CRect rect;
		m_L.GetClientRect(&rect);
		// 为列表视图控件添加全行选中和栅格风格
		m_L.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES| LVS_EX_TWOCLICKACTIVATE | LVS_EX_CHECKBOXES);
		if(CX_KH)
		{
			// 为列表视图控件添加5列   
			m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()/9,0); //1 
			m_L.InsertColumn(1,_T("姓名"),LVCFMT_CENTER,rect.Width()/9,1); //1 
			m_L.InsertColumn(2,_T("联系方式"),LVCFMT_CENTER,rect.Width()*3/9,2); //3
			m_L.InsertColumn(3,_T("联系地址"),LVCFMT_CENTER,rect.Width()*3/9,3); //3
			m_L.InsertColumn(4,_T("发货物流"),LVCFMT_CENTER,rect.Width()/9,4); //3
			CString sql;
			sql.Format("SELECT * FROM inventory.customer;");
			Customer(sql);
		}
		if(CX_DD)
		{		
			// 为列表视图控件添加8列   
			m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()*3/24,0); //  1/12
			m_L.InsertColumn(1,_T("日期"),LVCFMT_CENTER,rect.Width()/12,1); 
			m_L.InsertColumn(2,_T("型号"),LVCFMT_CENTER,rect.Width()*5/24,2); //  3/12
			m_L.InsertColumn(3,_T("客户"),LVCFMT_CENTER,rect.Width()/12,3); 
			m_L.InsertColumn(4,_T("数量"),LVCFMT_CENTER,rect.Width()/12,4); 
			m_L.InsertColumn(5,_T("单价"),LVCFMT_CENTER,rect.Width()/12,4); 
			m_L.InsertColumn(6,_T("金额"),LVCFMT_CENTER,rect.Width()/12,4); 
			m_L.InsertColumn(7,_T("备注"),LVCFMT_CENTER,rect.Width()*3/12,4); 
			CString sql;
			sql.Format("SELECT * FROM inventory.goods;");
			m_L.SetRedraw(FALSE);
			DD(sql);
			m_L.SetRedraw(TRUE);
			m_L.Invalidate();
		}
		if(CX_KC)
		{
			// 为列表视图控件添加7列   
			m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()/6,0); 
			m_L.InsertColumn(1,_T("日期"),LVCFMT_CENTER,rect.Width()/6,1); 
			m_L.InsertColumn(2,_T("型号"),LVCFMT_CENTER,rect.Width()/6,2); 
			m_L.InsertColumn(3,_T("入库"),LVCFMT_CENTER,rect.Width()/12,3); 
			m_L.InsertColumn(4,_T("出库"),LVCFMT_CENTER,rect.Width()/12,4); 
			m_L.InsertColumn(5,_T("库存"),LVCFMT_CENTER,rect.Width()/12,5); 
			m_L.InsertColumn(6,_T("备注"),LVCFMT_CENTER,rect.Width()*3/12,6); 
			CString sql;
			sql.Format("SELECT * FROM inventory.inventory;");
			m_L.SetRedraw(FALSE);
			KC(sql);
			m_L.SetRedraw(TRUE);
			m_L.Invalidate();
		}
		if(CX_LS)
		{
			// 为列表视图控件添加7列   
			m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()/6,0); 
			m_L.InsertColumn(1,_T("日期"),LVCFMT_CENTER,rect.Width()/6,1); 
			m_L.InsertColumn(2,_T("型号"),LVCFMT_CENTER,rect.Width()/6,2); 
			m_L.InsertColumn(3,_T("入库"),LVCFMT_CENTER,rect.Width()/12,3); 
			m_L.InsertColumn(4,_T("出库"),LVCFMT_CENTER,rect.Width()/12,4); 
			m_L.InsertColumn(5,_T("库存"),LVCFMT_CENTER,rect.Width()/12,5); 
			m_L.InsertColumn(6,_T("备注"),LVCFMT_CENTER,rect.Width()*3/12,6); 
			CString sql;
			sql.Format("SELECT * FROM inventory.history;");
			m_L.SetRedraw(FALSE);
			KC(sql);
			m_L.SetRedraw(TRUE);
			m_L.Invalidate();
		}
	}
	else
	{
		GetDlgItem(IDC_BUTTON15)->SetWindowTextA( "□    删除");
		GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
		m_L.SetExtendedStyle(LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES| LVS_EX_TWOCLICKACTIVATE);
	}
}


void CyDlg::OnBnClickedButton16()
{
	CDialog::OnOK();
	LOGIN dlg;
	dlg.DoModal();
	
}


void CyDlg::OnBnClickedButton17()
{
	m_L.SendMessage (LVM_SETEXTENDEDLISTVIEWSTYLE, 0,LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//1.获取当前时间做EXCEL的文件名：
	WORD  sYear,sMonth,sDay,sHour,sMinute,sSecond; 
    SYSTEMTIME  CurTime;/////定义SYSTEMTIME类的对象 
    GetLocalTime(&CurTime);////获取本地时间 
    sYear=CurTime.wYear;////获得年 
    sMonth=CurTime.wMonth;//获得月 
    sDay=CurTime.wDay; 
    sHour=CurTime.wHour; 
    sMinute=CurTime.wMinute; 
	sSecond=CurTime.wSecond; 
	CString sFileName;
	sFileName.Format("%d年%d月%d日%d点%d分%d秒.xls",sYear,sMonth,sDay,sHour,sMinute,sSecond);
	//2.添加保存对话框：
	CFileDialog dlg(false, ".xls", sFileName,OFN_OVERWRITEPROMPT|OFN_HIDEREADONLY,"(*.xls)|*.xls||", this);

	dlg.m_ofn.lpstrTitle = _T("保存文件");
	//3.单击确定执行：
    if (dlg.DoModal() == IDOK)
    {
		// 实现存盘
		CString buff1,buff2,buff3,buff4,buff5,buff6,buff7,buff8;
        CString fileName = dlg.GetPathName();     
		//判断文件是否存在，存在则删除重建
		DWORD dwRe=GetFileAttributes(fileName);
		if(dwRe!=(DWORD)-1)
		{
			DeleteFile(fileName);
		}

		CFile file(fileName, CFile::modeCreate|CFile::modeReadWrite|CFile::shareExclusive);
		CString title;
		if(CX_KC)
			title="日期\t型号\t库存\t备注\n";
		if(CX_LS)
			title="日期\t型号\t入库\t出库\t库存\t备注\n";
		if( (CX_DD||TJ_DD)&&password=="88785268")
			title="日期\t型号\t客户\t数量\t单价\t金额\t备注\n";
		if( (CX_DD||TJ_DD)&&password=="6335598")
			title="日期\t型号\t客户\t数量\t单价\t金额\t备注\t利润\n";
		if(CX_KH)
			title="姓名\t联系方式\t联系地址\t发货物流\n";
		file.Write(title,title.GetLength());
     
        int i = 0;
        int j=0;
        j = m_L.GetItemCount();
        if( j > 0 )
        {
            for(i=0;i<j;i++)
			{
				CString msg=NULL;
				if(CX_KC)
				{
					buff1 = m_L.GetItemText( i, 1 );
					buff2 = m_L.GetItemText( i, 2 );
					buff3 = m_L.GetItemText( i, 3 );
					buff4 = m_L.GetItemText( i, 4 );	
					msg.Format("%s\t%s\t%s\t%s\n",buff1,buff2,buff3,buff4);
				}
				if(CX_LS)
				{
					buff1 = m_L.GetItemText( i, 1 );
					buff2 = m_L.GetItemText( i, 2 );
					buff3 = m_L.GetItemText( i, 3 );
					buff4 = m_L.GetItemText( i, 4 );	
					buff5 = m_L.GetItemText( i, 5 );
					buff6 = m_L.GetItemText( i, 6 );	
					msg.Format("%s\t%s\t%s\t%s\t%s\t%s\n",buff1,buff2,buff3,buff4,buff5,buff6);
				}
				if((CX_DD||TJ_DD)&&password=="88785268")
				{
					buff1 = m_L.GetItemText( i, 1 );
					buff2 = m_L.GetItemText( i, 2 );
					buff3 = m_L.GetItemText( i, 3 );
					buff4 = m_L.GetItemText( i, 4 );	
					buff5 = m_L.GetItemText( i, 5 );
					buff6 = m_L.GetItemText( i, 6 );	
					buff7 = m_L.GetItemText( i, 7 );	
					msg.Format("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",buff1,buff2,buff3,buff4,buff5,buff6,buff7);
				}
				if((CX_DD||TJ_DD)&&password=="6335598")
				{
					buff1 = m_L.GetItemText( i, 1 );
					buff2 = m_L.GetItemText( i, 2 );
					buff3 = m_L.GetItemText( i, 3 );
					buff4 = m_L.GetItemText( i, 4 );	
					buff5 = m_L.GetItemText( i, 5 );
					buff6 = m_L.GetItemText( i, 6 );	
					buff7 = m_L.GetItemText( i, 7 );	
					buff8 = m_L.GetItemText( i, 8 );	
					msg.Format("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",buff1,buff2,buff3,buff4,buff5,buff6,buff7,buff8);
				}
				if(CX_KH)
				{
					buff1 = m_L.GetItemText( i, 1 );
					buff2 = m_L.GetItemText( i, 2 );
					buff3 = m_L.GetItemText( i, 3 );
					buff4 = m_L.GetItemText( i, 4 );	
					msg.Format("%s\t%s\t%s\t%s\n",buff1,buff2,buff3,buff4);
				}
				file.Write(msg,msg.GetLength());
			}		  
		}
		file.Close();
	}
     return;
}


void CyDlg::OnBnClickedButton18()
{
	Invalidate(0);
	skin++;
	if(skin==1)
		skinppLoadSkin(_T("AlphaOS.ssk"),0);
	else if(skin==2)
		skinppLoadSkin(_T("AquaOS.ssk"),0);
	else
		skinppLoadSkin(_T("Noire.ssk"),0);
}
