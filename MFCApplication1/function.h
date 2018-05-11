#include<iostream>
#include<string.h>
#include<time.h>



#define  TRUE                 1
#define  FALSE                0
#define  OK                   1
#define  ERROR                0
#define  INFEASIBLE           -1

typedef  int Status;
extern char code[256][50];

typedef struct {
	unsigned char uch;			// ��8bitsΪ��Ԫ���޷����ַ�
	unsigned long weight;		// ÿ�ࣨ�Զ����Ʊ������֣��ַ�����Ƶ��
} TmpNode;


typedef struct {
	unsigned char uch;				// ��8bitsΪ��Ԫ���޷����ַ�
	unsigned long weight;			// ÿ�ࣨ�Զ����Ʊ������֣��ַ�����Ƶ��
	char *code;						// �ַ���Ӧ�Ĺ��������루��̬����洢�ռ䣩
	int parent, lchild, rchild;		// ����˫�׺����Һ���
} HufNode, *HufTree;


void CreateTree(HufNode *huf_tree, unsigned int char_kinds, unsigned int node_num);
void select(HufNode *huf_tree, unsigned int n, int *s1, int *s2);
void HufCode(HufNode *huf_tree, unsigned char_kinds);