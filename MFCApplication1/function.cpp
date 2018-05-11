#include "stdafx.h"
#include "function.h"


void CreateTree(HufNode *huf_tree, unsigned int char_kinds, unsigned int node_num)
{
	unsigned int i;
	int s1, s2;
	for (i = char_kinds; i < node_num; ++i)
	{
		select(huf_tree, i, &s1, &s2);		// 选择最小的两个结点
		huf_tree[s1].parent = huf_tree[s2].parent = i;
		huf_tree[i].lchild = s1;
		huf_tree[i].rchild = s2;
		huf_tree[i].weight = huf_tree[s1].weight + huf_tree[s2].weight;
	}
}

//冒泡排序法，从大到小进行排序
void select(HufNode *huf_tree, unsigned int n, int *s1, int *s2)
{
	// 找最小
	unsigned int i;
	unsigned long min = ULONG_MAX;
	for (i = 0; i < n; ++i)
		if (huf_tree[i].parent == 0 && huf_tree[i].weight < min)
		{
			min = huf_tree[i].weight;
			*s1 = i;
		}
	huf_tree[*s1].parent = 1;   // 标记此结点已被选中

								// 找次小
	min = ULONG_MAX;
	for (i = 0; i < n; ++i)
		if (huf_tree[i].parent == 0 && huf_tree[i].weight < min)
		{
			min = huf_tree[i].weight;
			*s2 = i;
		}
}


void HufCode(HufNode *huf_tree, unsigned char_kinds)
{
	unsigned int i;
	int cur, next, index;
	char *code_tmp = (char *)malloc(256 * sizeof(char));		// 暂存编码，最多256个叶子，编码长度不超多255
	code_tmp[256 - 1] = '\0';

	for (i = 0; i < char_kinds; ++i)
	{
		index = 256 - 1;	// 编码临时空间索引初始化

							// 从叶子向根反向遍历求编码
		for (cur = i, next = huf_tree[i].parent; next != 0;
			cur = next, next = huf_tree[next].parent)
			if (huf_tree[next].lchild == cur)
				code_tmp[--index] = '0';	// 左‘0’
			else
				code_tmp[--index] = '1';	// 右‘1’
		huf_tree[i].code = (char *)malloc((256 - index) * sizeof(char));			// 为第i个字符编码动态分配存储空间 
		strcpy(huf_tree[i].code, &code_tmp[index]);     // 正向保存编码到树结点相应域中
	}
	free(code_tmp);		// 释放编码临时空间
}



