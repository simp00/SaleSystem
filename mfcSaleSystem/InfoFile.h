#pragma once
#define _F_LOGIN "./login.ini"
#define _F_STOCK "stock.txt"
#include<string>
#include<iostream>
#include<list>
#include<fstream>
using namespace std;
struct msg {

	int id;//��Ʒid
	string name;//��Ʒ��
	int price;//��Ʒ�۸�
	int num;//��Ʒ����
};
class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();
	//��ȡ��¼��Ϣ
	void ReadLogin(CString &name, CString &pwd);

	//�޸�����
	void WritePwd(char*name, char*pwd);
	//��ȡ��Ʒ��Ϣ
	void ReadDocline();
	//��Ʒд���ļ�
	void WriteDocline();
	void Addline(CString name, int num, int price);
	//�������Ʒ

	//�洢��Ʒ����
	list<msg> ls;

	//��¼��Ʒ����
	int num;
};

