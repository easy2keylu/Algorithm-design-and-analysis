#pragma once


// CGameDlg 对话框

class CGameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameDlg)

public:
	CGameDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGameDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAME_DIALOG };
#endif

protected:
	HICON m_hIcon;    //系统图标
	CDC m_dcMem;    //内存DC
	CDC m_dcElement;
	CDC m_dcMask;
	int m_anMap[4][4];

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void InitBackground(void);
	void InitElement();
	//将绘制游戏界面的语句进行封装（cpp文件也要改）
	//void UpdateMap(void);

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//afx_msg void OnBnClickedButton1();
	afx_msg void OnClickedBtnStart();
};
