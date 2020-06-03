#pragma once
#define _F_LOGIN "./login.ini"
#define _F_STOCK "stock.txt"
#include<string>
#include<iostream>
#include<list>
#include<fstream>
using namespace std;
struct msg {

	int id;//商品id
	string name;//商品名
	int price;//商品价格
	int num;//商品个数
};
class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();
	//读取登录信息
	void ReadLogin(CString &name, CString &pwd);

	//修改密码
	void WritePwd(char*name, char*pwd);
	//读取商品信息
	void ReadDocline();
	//商品写入文件
	void WriteDocline();
	void Addline(CString name, int num, int price);
	//添加新商品

	//存储商品容器
	list<msg> ls;

	//记录商品个数
	int num;
};

