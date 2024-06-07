// CScoreDlg.cpp: 实现文件
//

#include "pch.h"
#include "lab5.h"
#include "afxdialogex.h"
#include "CScoreDlg.h"


// CScoreDlg 对话框

IMPLEMENT_DYNAMIC(CScoreDlg, CDialogEx)

CScoreDlg::CScoreDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCORE_DIALOG, pParent)
	, m_strName(_T(""))
	, m_strCourseID(_T(""))
	, m_strScore(_T(""))
	, m_nScore(_T(""))
{

}

CScoreDlg::~CScoreDlg()
{
}

void CScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_COURSEID, m_strCourseID);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_strScore);
	DDX_Text(pDX, IDC_EDIT_HOURS, m_nScore);
}


BEGIN_MESSAGE_MAP(CScoreDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CScoreDlg::OnBnClickedButtonAdd)
END_MESSAGE_MAP()


	



// CScoreDlg 消息处理程序


void CScoreDlg::OnBnClickedButtonAdd()
{
	GetDlgItemText(IDC_EDIT_NAME, m_strName);
	GetDlgItemText(IDC_EDIT_COURSEID, m_strCourseID);
	GetDlgItemText(IDC_EDIT_SCORE, m_strScore);
	GetDlgItemText(IDC_EDIT_HOURS, m_nScore);
	CDialogEx::OnOK();
}
