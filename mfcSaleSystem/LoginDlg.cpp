// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mfcSaleSystem.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "InfoFile.h"


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DIALOG_LOGIN, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLoginDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_user = TEXT("admin");
	m_pwd = TEXT("admin");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CLoginDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);//���¿ռ�����ݵ���Ӧ�ı���
	CInfoFile file;//�����ļ������
	CString user, pwd;
	//��ȡ�����ļ�����ȡ�û������� ����Ϊ���ô���
	file.ReadLogin(user, pwd);
	if (m_user == user) {
		if (m_pwd != pwd) {
			MessageBox(_T("�������"));
			m_user.Empty();
			m_pwd.Empty();
		}
		else {

			MessageBox(_T("��¼�ɹ�"));
			CDialogEx::OnOK();
		}
	}
	else {
		MessageBox(_T("�û���������"));
		m_user.Empty();
		m_pwd.Empty();
	}

	CDialogEx::OnOK();
}


void CLoginDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	exit(0);
}
