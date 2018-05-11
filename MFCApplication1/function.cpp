#include "stdafx.h"
#include "function.h"


void CreateTree(HufNode *huf_tree, unsigned int char_kinds, unsigned int node_num)
{
	unsigned int i;
	int s1, s2;
	for (i = char_kinds; i < node_num; ++i)
	{
		select(huf_tree, i, &s1, &s2);		// ѡ����С���������
		huf_tree[s1].parent = huf_tree[s2].parent = i;
		huf_tree[i].lchild = s1;
		huf_tree[i].rchild = s2;
		huf_tree[i].weight = huf_tree[s1].weight + huf_tree[s2].weight;
	}
}

//ð�����򷨣��Ӵ�С��������
void select(HufNode *huf_tree, unsigned int n, int *s1, int *s2)
{
	// ����С
	unsigned int i;
	unsigned long min = ULONG_MAX;
	for (i = 0; i < n; ++i)
		if (huf_tree[i].parent == 0 && huf_tree[i].weight < min)
		{
			min = huf_tree[i].weight;
			*s1 = i;
		}
	huf_tree[*s1].parent = 1;   // ��Ǵ˽���ѱ�ѡ��

								// �Ҵ�С
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
	char *code_tmp = (char *)malloc(256 * sizeof(char));		// �ݴ���룬���256��Ҷ�ӣ����볤�Ȳ�����255
	code_tmp[256 - 1] = '\0';

	for (i = 0; i < char_kinds; ++i)
	{
		index = 256 - 1;	// ������ʱ�ռ�������ʼ��

							// ��Ҷ�����������������
		for (cur = i, next = huf_tree[i].parent; next != 0;
			cur = next, next = huf_tree[next].parent)
			if (huf_tree[next].lchild == cur)
				code_tmp[--index] = '0';	// ��0��
			else
				code_tmp[--index] = '1';	// �ҡ�1��
		huf_tree[i].code = (char *)malloc((256 - index) * sizeof(char));			// Ϊ��i���ַ����붯̬����洢�ռ� 
		strcpy(huf_tree[i].code, &code_tmp[index]);     // ���򱣴���뵽�������Ӧ����
	}
	free(code_tmp);		// �ͷű�����ʱ�ռ�
}



