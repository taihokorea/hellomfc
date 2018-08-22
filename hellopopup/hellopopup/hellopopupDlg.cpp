
// hellopopupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hellopopup.h"
#include "hellopopupDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// ChellopopupDlg dialog

const CString newguyname = L"New Guy";
const CString oldmanname = L"Old Man";

ChellopopupDlg::ChellopopupDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HELLOPOPUP_DIALOG, pParent)
	, m_Name(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ChellopopupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_NAME, m_Name);

}

BEGIN_MESSAGE_MAP(ChellopopupDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_HELLO, &ChellopopupDlg::OnBnClickedBtnHello)
	ON_EN_SETFOCUS(IDC_EDT_NAME, &ChellopopupDlg::OnEnSetfocusEdtName)
	ON_EN_KILLFOCUS(IDC_EDT_NAME, &ChellopopupDlg::OnEnKillfocusEdtName)
END_MESSAGE_MAP()


// ChellopopupDlg message handlers

BOOL ChellopopupDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_Name = newguyname;
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void ChellopopupDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void ChellopopupDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR ChellopopupDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ChellopopupDlg::OnBnClickedBtnHello()
{
	UpdateData(TRUE);

	CString msg;
	msg.Format(L"Hello, %s~", m_Name);

	AfxMessageBox(msg);
}

void ChellopopupDlg::OnEnSetfocusEdtName()
{
	UpdateData(TRUE);

	if (newguyname == m_Name)
	{
		m_Name = "";
		UpdateData(FALSE);
	}
}


void ChellopopupDlg::OnEnKillfocusEdtName()
{
	UpdateData(TRUE);

	if ("" == m_Name)
	{
		m_Name = newguyname;
		UpdateData(FALSE);
	}
}
