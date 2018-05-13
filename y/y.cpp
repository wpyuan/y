
// y.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "y.h"
#include "yDlg.h"

#define one "0xbe8e2ce1, 0xdab6, 0x11d6, 0xad, 0xd0, 0x0, 0xe0, 0x4c, 0x53, 0xf6, 0xe6"
#define SKINSPACE _T("/SPATH:")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
HANDLE handle;

// CyApp

BEGIN_MESSAGE_MAP(CyApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CyApp 构造

CyApp::CyApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CyApp 对象

CyApp theApp;


// CyApp 初始化

BOOL CyApp::InitInstance()
{
	handle=::CreateMutex(NULL,FALSE,one);//handle为声明的HANDLE类型的全局变量
    if(GetLastError()==ERROR_ALREADY_EXISTS)    
    {   
        AfxMessageBox("应用程序已经在运行");
        return FALSE;   
    }

	skinppLoadSkin(_T("Noire.ssk"),0);//路径当前
	//MessageBox();
	AfxEnableControlContainer();
#ifdef _AFXDLL
 Enable3dControls();   // Call this when using MFC in a shared DLL
#else
 Enable3dControlsStatic(); // Call this when linking to MFC statically
#endif
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	LOGIN dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}


int CyApp::ExitInstance()
{
	// TODO: 在此添加专用代码和/或调用基类
	skinppExitSkin(); 
	CloseHandle(handle);    
	return CWinApp::ExitInstance();
}
