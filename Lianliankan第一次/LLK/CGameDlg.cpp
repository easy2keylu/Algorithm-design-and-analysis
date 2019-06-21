// CGameDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "LLK.h"
#include "CGameDlg.h"
#include "afxdialogex.h"


// CGameDlg 对话框

IMPLEMENT_DYNAMIC(CGameDlg, CDialogEx)

CGameDlg::CGameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GAME_DIALOG, pParent)
{

}

CGameDlg::~CGameDlg()
{
}

void CGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGameDlg, CDialogEx)
	ON_WM_PAINT()
	//ON_BN_CLICKED(IDC_BUTTON1, &CGameDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BTN_START, &CGameDlg::OnClickedBtnStart)
END_MESSAGE_MAP()


// CGameDlg 消息处理程序

void CGameDlg::InitBackground(void)
{
	//获得当前对话框的视频内存
	CClientDC dc(this);

	//加载BMP图片资源
	HANDLE bmp = ::LoadImage(NULL, _T("theme\\picture\\fruit_bg.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	
	//创建与视频内存兼容的内存DC
	m_dcMem.CreateCompatibleDC(&dc);
	
	//将位图资源选入DC
	m_dcMem.SelectObject(bmp);
}

BOOL CGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	InitBackground();
	InitElement();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CGameDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	dc.BitBlt(0, 0, 800, 600, &m_dcMem, 0, 0, SRCCOPY);
}

void CGameDlg::InitElement()
{
	//获得当前对话框的视频内存
	CClientDC dc(this);

	//加载BMP图片资源（水果单元）
	HANDLE bmp1 = ::LoadImage(NULL, _T("theme\\picture\\fruit_element.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	//创建与视频内存兼容的内存DC
	m_dcElement.CreateCompatibleDC(&dc);

	//将位图资源选入DC
	m_dcElement.SelectObject(bmp1);
	
	//加载BMP图片资源（水果单元掩码——消除背景）
	HANDLE bmp2 = ::LoadImage(NULL, _T("theme\\picture\\fruit_mask.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	//创建与视频内存兼容的内存DC
	m_dcMask.CreateCompatibleDC(&dc);

	//将位图资源选入DC
	m_dcMask.SelectObject(bmp2);
}


void CGameDlg::OnClickedBtnStart()
{
	// TODO: 在此添加控件通知处理程序代码
	int anMap[4][4] = { 2, 0, 1, 3, 2, 2, 1, 3, 2, 1, 0, 0, 1, 3, 0, 3 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_anMap[i][j] = anMap[i][j];
		}
	}

	int nLeft = 50;
	int nTop = 50;
	int nElemW = 40;
	int nElemH = 40;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nElemH, nElemW, nElemH, &m_dcElement, 0, m_anMap[i][j] * nElemH, SRCCOPY);
			m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nElemH, nElemW, nElemH, &m_dcMask, 0, m_anMap[i][j] * nElemH, SRCPAINT);
			m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nElemH, nElemW, nElemH, &m_dcElement, 0, m_anMap[i][j] * nElemH, SRCAND);
		}
	}

	Invalidate(FALSE);
}

//将绘制游戏界面的语句进行封装（头函数也要改）
/*void CGameDlg::UpdateMap(void)
{
	int nLeft = 50;
	int nTop = 50;
	int nElemW = 40;
	int nElemH = 40;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nElemH, nElemW, nElemH, &m_dcElement, 0, m_anMap[i][j] * nElemH, SRCCOPY);
			m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nElemH, nElemW, nElemH, &m_dcMask, 0, m_anMap[i][j] * nElemH, SRCPAINT);
			m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nElemH, nElemW, nElemH, &m_dcElement, 0, m_anMap[i][j] * nElemH, SRCAND);
		}
	}

	Invalidate(FALSE);
}*/