#include "stdafx.h"
#include "InfoFile.h"


CInfoFile::CInfoFile()
{
}


CInfoFile::~CInfoFile()
{
}

void CInfoFile::ReadLogin(CString & name, CString & pwd)
{
	ifstream ifs;
	ifs.open(_F_LOGIN);//打开文件
	char buf[1024] = { 0 };
	ifs.getline(buf, sizeof(buf));//读取一行内容
	name = CString(buf);//char* 转换为CString
	ifs.getline(buf, sizeof(buf));
	pwd = CString(buf);
	ifs.close();//关闭文件
}

void CInfoFile::WritePwd(char * name, char * pwd)
{
	ofstream ofs;//创建文件输出对象
	ofs.open(_F_LOGIN);//打开文件
	ofs << name << endl;//写入文件
	ofs << pwd << endl;//pwd写入文件
	ofs.close();//关闭文件
}

void CInfoFile::ReadDocline()
{
	ifstream ifs(_F_STOCK);//输入方式打开文件
	char buf[1024] = { 0 };
	num = 0;//初始化商品输入为0
	ls.clear();//
	//取出表头
	ifs.getline(buf,sizeof(buf));
	while (!ifs.eof()) {//没到文件结尾
		msg tmp;
		ifs.getline(buf, sizeof(buf));//读取一行数据
		num++;//商品数目加一行
		//AfxMessageBox(CString(buf))
		char *sst = strtok(buf,"|");//以|切割
		if (sst != NULL) {
			tmp.id = atoi(sst);//商品id

		}
		else {
			break;
		}
		sst = strtok(NULL,"|");
		tmp.name = sst;//商品名称
		sst = strtok(NULL, "|");
		tmp.price = atoi(sst);//商品价格
		sst = strtok(NULL, "|");
		tmp.num = atoi(sst);//商品数目
		ls.push_back(tmp);//放在链表的后面



	}
	ifs.close();
}

void CInfoFile::WriteDocline()
{
	ofstream ofs(_F_STOCK);//输出方式打开文件
	if (ls.size() > 0) {
		ofs << "商品ID|商品名称|商品价格|库存" << endl;//写入表头
		//通过迭代器去除链表内容，写入文件 以"|"分隔 结尾加换行
		for (list<msg>::iterator it = ls.begin(); it != ls.end(); it++) {
			ofs << it->id << "|";
			ofs << it->name << "|";
			ofs << it->price << "|";
			ofs << it->num << endl;
		}


	}
	ofs.close();


}

void CInfoFile::Addline(CString name, int num, int price)
{
	msg tmp;
	if (ls.size() > 0) {
		//商品名称 库存 介个有效
		if (name.IsEmpty() && num > 0 && price > 0) {
			tmp.id = ls.size() + 1;
			CStringA str;
			str = name;//CString 转CStringA
			tmp.name = str.GetBuffer();//CStringA 转char*
			tmp.num = num;
			tmp.price = price;
			ls.push_back(tmp);
		}
	}
}
