
// MFCApplication1Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;


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


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, filepath);
	DDX_Text(pDX, IDC_EDIT4, filepath2);
	DDX_Text(pDX, IDC_EDIT3, notice);
	DDX_Text(pDX, IDC_EDIT5, filepath_open);
	DDX_Text(pDX, IDC_EDIT1, filepath_save);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
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

	ShowWindow(SW_MAXIMIZE);

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	/*
	** 动态分配256个结点，暂存字符频度，
	** 统计并拷贝到树结点后立即释放
	*/

	

	// 初始化暂存结点
	






	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//打开文件
void CMFCApplication1Dlg::OnBnClickedButton1()
{
	string f;
	BOOL isopen = TRUE;
	CString defaultDir = L"c:\\";
	CString filename = L"";
	CString filter = L"文件(*.txt;*.jpg;*.mp4)|*.txt;*.jpg;*.mp4||";
	CFileDialog openfileDLG(isopen, defaultDir, filename, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	openfileDLG.GetOFN().lpstrInitialDir = L"c:\\";
	filepath = defaultDir;
	INT_PTR result = openfileDLG.DoModal();
	if (result==IDOK)
	{
		//resolution
        //for test
		int a = 0;
		a++;
		a--;
		CString in1;
		UpdateData(TRUE);

		filepath = openfileDLG.GetPathName();

		USES_CONVERSION;
		f= W2A(filepath.LockBuffer());
		filepath.UnlockBuffer();
		const char *p = f.data();
		fpr = fopen(p,"rb");
		if (fpr == NULL)
		return ;

		tmp_nodes = (TmpNode *)malloc(256 * sizeof(TmpNode));

		for (i = 0; i < 256; ++i)
		{
			tmp_nodes[i].weight = 0;
			tmp_nodes[i].uch = (unsigned char)i;		// 数组的256个下标与256种字符对应
		}

		fread((char*)&char_temp, sizeof(unsigned char), 1, fpr);
		while (!feof(fpr))
		{
			filelength++;
			++tmp_nodes[char_temp].weight;
			fread((char*)&char_temp, sizeof(unsigned char), 1, fpr);
		}
		fclose(fpr);


		in1.Format(L"%d\n", filelength);
        notice = L"源文件长度（字节）：";
		notice += in1;
		UpdateData(FALSE);


		// 排序，将频度为零的放最后，剔除
		for (i = 0; i < 256 - 1; ++i) {
			for (j = i + 1; j < 256; ++j) {
				if (tmp_nodes[i].weight < tmp_nodes[j].weight)
				{
					node_temp = tmp_nodes[i];
					tmp_nodes[i] = tmp_nodes[j];
					tmp_nodes[j] = node_temp;
				}
			}
		}

		// 统计实际的字符种类（出现次数不为0）
		for (i = 0; i < 256; ++i) {
			if (tmp_nodes[i].weight == 0)
				break;
		}
		char_kinds = i;

	} 
	else
	{
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
}

//保存文件
void CMFCApplication1Dlg::OnBnClickedButton2()
{
	string f;
	string f1;
	BOOL isopen = FALSE;
	CString defaultDir = L"c:\\";
	CString filename = L"";
	CString filter = L"文件(*.huf;)|*.huf;||";
	CFileDialog openfileDLG(isopen, defaultDir, filename, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	openfileDLG.GetOFN().lpstrInitialDir = L"c:\\";
	INT_PTR result = openfileDLG.DoModal();

	char code_buf[256] = "\0";
	unsigned int code_len;


	if (result == IDOK)
	{
		int num1;
		CString in2;
		CString in3;
		float rate;
		UpdateData(TRUE);
		filepath2 = openfileDLG.GetPathName();
		UpdateData(FALSE);

		USES_CONVERSION;
		f = W2A(filepath2.LockBuffer());
		filepath2.UnlockBuffer();
		const char *p = f.data();


		if (char_kinds == 1)
		{ 
			fpw = fopen(p,"wb");			// 打开压缩后将生成的文件
			fwrite((char *)&char_kinds, sizeof(unsigned int), 1, fpw);		// 写入字符种类
			fwrite((char *)&tmp_nodes[0].uch, sizeof(unsigned char), 1, fpw);		// 写入唯一的字符
			fwrite((char *)&tmp_nodes[0].weight, sizeof(unsigned long), 1, fpw);		// 写入字符频度，也就是文件长度
			free(tmp_nodes);
			fclose(fpw);
		}
		else
		{
			node_num = 2 * char_kinds - 1;		// 根据字符种类数，计算建立哈夫曼树所需结点数 
			huf_tree = (HufNode *)malloc(node_num * sizeof(HufNode));
			// 初始化前char_kinds个结点
			for (i = 0; i < char_kinds; ++i)
			{
				// 将暂存结点的字符和频度拷贝到树结点
				huf_tree[i].uch = tmp_nodes[i].uch;
				huf_tree[i].weight = tmp_nodes[i].weight;
				huf_tree[i].parent = 0;
			}
			free(tmp_nodes);
			// 初始化后node_num-char_kins个结点
			for (; i < node_num; ++i)
				huf_tree[i].parent = 0;
			// 创建哈夫曼树
			CreateTree(huf_tree, char_kinds, node_num);
			// 生成哈夫曼编码
			HufCode(huf_tree, char_kinds);
			// 写入字符和相应权重，供解压时重建哈夫曼树
			fpw = fopen(p, "wb");
			fwrite((char *)&char_kinds, sizeof(unsigned int), 1, fpw);		// 写入字符种类
			for (i = 0; i < char_kinds; ++i)
			{
				fwrite((char *)&huf_tree[i].uch, sizeof(unsigned char), 1, fpw);			// 写入字符（已排序，读出后顺序不变）
				fwrite((char *)&huf_tree[i].weight, sizeof(unsigned long), 1, fpw);		// 写入字符对应权重
			}

			fwrite((char *)&filelength, sizeof(unsigned long), 1, fpw);		// 写入文件长度

			f1 = W2A(filepath.LockBuffer());
			filepath.UnlockBuffer();
			const char *p = f1.data();
			fpr = fopen(p, "rb");

			// 以二进制形式打开待压缩的文件
			fread((char *)&char_temp, sizeof(unsigned char), 1, fpr);     // 每次读取8bits

			while (!feof(fpr))
			{
				// 匹配字符对应编码
				for (i = 0; i < char_kinds; ++i)
					if (char_temp == huf_tree[i].uch)
						strcat(code_buf, huf_tree[i].code);

				// 以8位（一个字节长度）为处理单元
				while (strlen(code_buf) >= 8)
				{
					char_temp = '\0';		// 清空字符暂存空间，改为暂存字符对应编码
					for (i = 0; i < 8; ++i)
					{
						char_temp <<= 1;		// 左移一位，为下一个bit腾出位置
						if (code_buf[i] == '1')
							char_temp |= 1;		// 当编码为"1"，通过或操作符将其添加到字节的最低位
					}
					fwrite((char *)&char_temp, sizeof(unsigned char), 1, fpw);		// 将字节对应编码存入文件
					strcpy(code_buf, code_buf + 8);		// 编码缓存去除已处理的前八位
				}

				fread((char *)&char_temp, sizeof(unsigned char), 1, fpr);     // 每次读取8bits
			}


			// 处理最后不足8bits编码
			code_len = strlen(code_buf);

			if (code_len > 0)
			{
				char_temp = '\0';
				for (i = 0; i < code_len; ++i)
				{
					char_temp <<= 1;
					if (code_buf[i] == '1')
						char_temp |= 1;
				}
				char_temp <<= 8 - code_len;       // 将编码字段从尾部移到字节的高位
				fwrite((char *)&char_temp, sizeof(unsigned char), 1, fpw);       // 存入最后一个字节
			}





        UpdateData(TRUE);
		notice += L"\r\n压缩后文件长度（字节）：";
		ziplength= ftell(fpw);
		in2.Format(L"%d\n", ziplength);
		notice += in2;
		rate = ((float)ziplength) / (float)filelength ;
		notice += L"\r\n压缩率：";
		in3.Format(L"%.5f",rate);
		notice += in3;
		UpdateData(FALSE);
		fclose(fpw);
		fclose(fpr);
		filelength = 0;
		ziplength = 0;

		// 释放内存
		for (i = 0; i < char_kinds; ++i)
			free(huf_tree[i].code);
		free(huf_tree);


		}



		
		
		

		
		
	}
	else
	{
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
}

//打开压缩文件
void CMFCApplication1Dlg::OnBnClickedButton4()
{
	
	string f;
	BOOL isopen = TRUE;
	CString defaultDir = L"c:\\";
	CString filename = L"";
	CString filter = L"文件(*.huf)|*.huf||";
	CFileDialog openfileDLG(isopen, defaultDir, filename, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	openfileDLG.GetOFN().lpstrInitialDir = L"c:\\";
	INT_PTR result = openfileDLG.DoModal();
	if (result == IDOK)
	{
		CString in1;
		UpdateData(TRUE);
		filepath_open = openfileDLG.GetPathName();
		UpdateData(FALSE);
		USES_CONVERSION;
		f = W2A(filepath_open.LockBuffer());
		filepath_open.UnlockBuffer();
		const char *p = f.data();
		fpr1 = fopen(p, "rb");
		if (fpr1 == NULL)
			return;
		fread((char *)&char_kinds_1, sizeof(unsigned int), 1, fpr1);    // 读取字符种类数

	}
	else
	{
		return;
	}

	// TODO: 在此添加控件通知处理程序代码
}



//进行压缩文件的解压
void CMFCApplication1Dlg::OnBnClickedButton3()
{
	string f;
	string f1;
	BOOL isopen = FALSE;
	CString defaultDir = L"c:\\";
	CString filename = L"";
	CString filter = L"文件(*.jpg;*.txt;*.mp4)|*.jpg;*.txt;*.mp4||";
	CFileDialog openfileDLG(isopen, defaultDir, filename, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	openfileDLG.GetOFN().lpstrInitialDir = L"c:\\";
	INT_PTR result = openfileDLG.DoModal();


	if (result == IDOK)
	{
		int num1;
		CString in2;
		CString in3;
		float rate;
		UpdateData(TRUE);
		filepath_save = openfileDLG.GetPathName();
		UpdateData(FALSE);

		USES_CONVERSION;
		f = W2A(filepath_save.LockBuffer());
		filepath_save.UnlockBuffer();
		const char *p = f.data();
		// 读取压缩文件前端的字符及对应编码，用于重建哈夫曼树
		if (char_kinds_1 == 1)
		{
			fread((char *)&code_temp_1, sizeof(unsigned char), 1, fpr1);     // 读取唯一的字符
			fread((char *)&file_len_1, sizeof(unsigned long), 1, fpr1);     // 读取文件长度
			fpw1 = fopen(p, "wb");					// 打开压缩后将生成的文件
			while (file_len_1--)
				fwrite((char *)&code_temp_1, sizeof(unsigned char), 1, fpw1);

			fclose(fpr1);
			fclose(fpw1);
		}
		else
		{
			node_num_1 = 2 * char_kinds_1 - 1;		// 根据字符种类数，计算建立哈夫曼树所需结点数 
			huf_tree_1 = (HufNode *)malloc(node_num_1 * sizeof(HufNode));		// 动态分配哈夫曼树结点空间


			// 读取字符及对应权重，存入哈夫曼树节点

			for (i_1 = 0; i_1 < char_kinds_1; ++i_1)
			{
				fread((char *)&huf_tree_1[i_1].uch, sizeof(unsigned char), 1, fpr1);		// 读入字符
				fread((char *)&huf_tree_1[i_1].weight, sizeof(unsigned long), 1, fpr1);	// 读入字符对应权重
				huf_tree_1[i_1].parent = 0;

			}
			// 初始化后node_num-char_kins个结点的parent
			for (; i_1 < node_num_1; ++i_1)
				huf_tree_1[i_1].parent = 0;

			CreateTree(huf_tree_1, char_kinds_1, node_num_1);		// 重建哈夫曼树（与压缩时的一致）

			// 读完字符和权重信息，紧接着读取文件长度和编码，进行解码
			fread((char *)&file_len_1, sizeof(unsigned long), 1, fpr1);	// 读入文件长度
			fpw1 = fopen(p, "wb");
			root_1 = node_num_1 - 1;

			while (1)
			{
				fread((char *)&code_temp_1, sizeof(unsigned char), 1, fpr1);		// 读取一个字符长度的编码

																					// 处理读取的一个字符长度的编码（通常为8位）
				for (i_1 = 0; i_1 < 8; ++i_1)
				{
					// 由根向下直至叶节点正向匹配编码对应字符
					if (code_temp_1 & 128)
						root_1 = huf_tree_1[root_1].rchild;
					else
						root_1 = huf_tree_1[root_1].lchild;

					if (root_1 < char_kinds_1)
					{
						fwrite((char *)&huf_tree_1[root_1].uch, sizeof(unsigned char), 1, fpw1);
						++writen_len_1;
						if (writen_len_1 == file_len_1) break;		// 控制文件长度，跳出内层循环
						root_1 = node_num - 1;        // 复位为根索引，匹配下一个字符
					}
					code_temp_1 <<= 1;		// 将编码缓存的下一位移到最高位，供匹配

				}
				if (writen_len_1 == file_len_1) break;		// 控制文件长度，跳出外层循环
			}
			// 关闭文件
			fclose(fpr1);
			fclose(fpw1);
			// 释放内存
			free(huf_tree_1);

			file_len_1 = 0;
			writen_len_1 = 0;
			// TODO: 在此添加控件通知处理程序代码



			UpdateData(TRUE);
			notice += L"\r\n解压成功！";
			UpdateData(FALSE);



		}
	}
}