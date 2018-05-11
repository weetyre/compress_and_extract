
// MFCApplication1Dlg.h: 头文件
//
#include "function.h"
#pragma once


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
	// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
public:

	CString filepath;
	CString filepath2;
	CString filepath_open;
	CString filepath_save;
	CString notice;




	unsigned int i, j;
	unsigned int char_kinds;		// 字符种类
	unsigned char char_temp;		// 暂存8bits字符
	unsigned long filelength = 0;
	int ziplength = 0;

	TmpNode node_temp;
	unsigned int node_num;
    HufTree huf_tree;
	



	
	FILE *fpr;
	FILE *fpw;
	FILE *fpr1;
	FILE *fpw1;

	TmpNode *tmp_nodes = (TmpNode *)malloc(256 * sizeof(TmpNode));
	//解压需要用到的一些东西
	

	//解压所需变量
	unsigned int i_1;
	unsigned long file_len_1;
	unsigned long writen_len_1 = 0;		// 控制文件写入长度
	unsigned int char_kinds_1;		// 存储字符种类
	unsigned int node_num_1;
	HufTree huf_tree_1;
	unsigned char code_temp_1;		// 暂存8bits编码
	unsigned int root_1;		// 保存根节点索引，供匹配编码使用

	

	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
};
