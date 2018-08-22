
// hellopopupDlg.h : header file
//

#pragma once


// ChellopopupDlg dialog
class ChellopopupDlg : public CDialogEx
{
// Construction
public:
	ChellopopupDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HELLOPOPUP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnHello();
	CString m_Name;
	afx_msg void OnEnSetfocusEdtName();
	afx_msg void OnEnKillfocusEdtName();
};
