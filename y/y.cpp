
// y.cpp : ����Ӧ�ó��������Ϊ��
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


// CyApp ����

CyApp::CyApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CyApp ����

CyApp theApp;


// CyApp ��ʼ��

BOOL CyApp::InitInstance()
{
	handle=::CreateMutex(NULL,FALSE,one);//handleΪ������HANDLE���͵�ȫ�ֱ���
    if(GetLastError()==ERROR_ALREADY_EXISTS)    
    {   
        AfxMessageBox("Ӧ�ó����Ѿ�������");
        return FALSE;   
    }

	skinppLoadSkin(_T("Noire.ssk"),0);//·����ǰ
	//MessageBox();
	AfxEnableControlContainer();
#ifdef _AFXDLL
 Enable3dControls();   // Call this when using MFC in a shared DLL
#else
 Enable3dControlsStatic(); // Call this when linking to MFC statically
#endif
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	LOGIN dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}


int CyApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	skinppExitSkin(); 
	CloseHandle(handle);    
	return CWinApp::ExitInstance();
}
