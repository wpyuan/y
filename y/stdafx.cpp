
// stdafx.cpp : 只包括标准包含文件的源文件
// y.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"
MYSQL m_sqlCons;
CString password="";
//检测是否连接数据库
void datebases()
{
	mysql_init(&m_sqlCons);
    if(!mysql_real_connect(&m_sqlCons,"localhost","root","123","inventory",3307,NULL,0))// localhost  IP地址  账号  密码  数据库名称  端口  
    {
		MessageBox(NULL,_T("访问数据库失败!"),"系统提示",NULL);
		CString e=mysql_error(&m_sqlCons);//需要将项目属性中字符集修改为“使用多字节字符集”或“未设置”
		MessageBox(NULL,e,"错误",NULL);
		return;
	}
	else{
		//MessageBox(NULL,"连接数据库成功","系统提示",NULL);
	}
	mysql_query(&m_sqlCons,"set names gbk;");//解决录入信息到数据库中后汉字乱码显示的问题
}