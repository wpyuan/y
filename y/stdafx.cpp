
// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// y.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"
MYSQL m_sqlCons;
CString password="";
//����Ƿ��������ݿ�
void datebases()
{
	mysql_init(&m_sqlCons);
    if(!mysql_real_connect(&m_sqlCons,"localhost","root","123","inventory",3307,NULL,0))// localhost  IP��ַ  �˺�  ����  ���ݿ�����  �˿�  
    {
		MessageBox(NULL,_T("�������ݿ�ʧ��!"),"ϵͳ��ʾ",NULL);
		CString e=mysql_error(&m_sqlCons);//��Ҫ����Ŀ�������ַ����޸�Ϊ��ʹ�ö��ֽ��ַ�������δ���á�
		MessageBox(NULL,e,"����",NULL);
		return;
	}
	else{
		//MessageBox(NULL,"�������ݿ�ɹ�","ϵͳ��ʾ",NULL);
	}
	mysql_query(&m_sqlCons,"set names gbk;");//���¼����Ϣ�����ݿ��к���������ʾ������
}