
// lab5Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "lab5.h"
#include "lab5Dlg.h"
#include "afxdialogex.h"
#include "CScoreDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Clab5Dlg 对话框



Clab5Dlg::Clab5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB5_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clab5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_STUDENTS, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(Clab5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &Clab5Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_SCORE, &Clab5Dlg::OnBnClickedButtonScore)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_STUDENTS, &Clab5Dlg::OnLvnItemchangedListStudents)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &Clab5Dlg::OnBnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &Clab5Dlg::OnBnClickedButtonDelete)
END_MESSAGE_MAP()


// Clab5Dlg 消息处理程序

BOOL Clab5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ListCtrl.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(1, _T("课程"), LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(2, _T("成绩"), LVCFMT_LEFT, 80);
	m_ListCtrl.InsertColumn(1, _T("学分"), LVCFMT_LEFT, 80);
	//添加数据项
	//m_ListCtrl.InsertItem(0, _T("001"));
	//m_ListCtrl.SetItemText(0, 1, _T("数学"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Clab5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Clab5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Clab5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clab5Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void Clab5Dlg::OnBnClickedButtonScore()
{
	CScoreDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		// 添加学生成绩到列表控件
		int nIndex = m_ListCtrl.InsertItem(0, dlg.m_strName);
		m_ListCtrl.SetItemText(nIndex, 1, dlg.m_strCourseID);
		m_ListCtrl.SetItemText(nIndex, 2, dlg.m_strScore);
		m_ListCtrl.SetItemText(nIndex, 3, dlg.m_nScore);
	}
}


void Clab5Dlg::OnLvnItemchangedListStudents(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if (pNMLV->iItem >= 0)
	{
		GetDlgItem(IDC_BUTTON_MODIFY)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_DELETE)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_BUTTON_MODIFY)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_DELETE)->EnableWindow(FALSE);
	}
	*pResult = 0;
}


void Clab5Dlg::OnBnClickedButtonModify()
{
	int nIndex = m_ListCtrl.GetNextItem(-1, LVNI_SELECTED);
	if (nIndex >= 0)
	{
		CScoreDlg dlg;
		dlg.m_strName = m_ListCtrl.GetItemText(nIndex, 0);
		dlg.m_strCourseID = m_ListCtrl.GetItemText(nIndex, 1);
		dlg.m_strScore = m_ListCtrl.GetItemText(nIndex, 2);
		dlg.m_nScore = m_ListCtrl.GetItemText(nIndex, 3);

		if (dlg.DoModal() == IDOK)
		{
			m_ListCtrl.SetItemText(nIndex, 0, dlg.m_strName);
			m_ListCtrl.SetItemText(nIndex, 1, dlg.m_strCourseID);
			m_ListCtrl.SetItemText(nIndex, 2, dlg.m_strScore);
			m_ListCtrl.SetItemText(nIndex, 3, dlg.m_nScore);
		}
	}
}


void Clab5Dlg::OnBnClickedButtonDelete()
{
	int nIndex = m_ListCtrl.GetNextItem(-1, LVNI_SELECTED);
	if (nIndex >= 0)
	{
		m_ListCtrl.DeleteItem(nIndex);
	}
}
