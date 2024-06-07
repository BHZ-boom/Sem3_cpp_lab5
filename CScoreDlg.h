#pragma once
#include "afxdialogex.h"


// CScoreDlg 对话框

class CScoreDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CScoreDlg)

public:
	CScoreDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CScoreDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCORE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	
public:
	CString m_strName;
	CString m_strCourseID;
	CString m_strScore;
	CString m_nScore;
	afx_msg void OnBnClickedButtonAdd();
	
};
