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
	unsigned char uch;			// 以8bits为单元的无符号字符
	unsigned long weight;		// 每类（以二进制编码区分）字符出现频度
} TmpNode;


typedef struct {
	unsigned char uch;				// 以8bits为单元的无符号字符
	unsigned long weight;			// 每类（以二进制编码区分）字符出现频度
	char *code;						// 字符对应的哈夫曼编码（动态分配存储空间）
	int parent, lchild, rchild;		// 定义双亲和左右孩子
} HufNode, *HufTree;


void CreateTree(HufNode *huf_tree, unsigned int char_kinds, unsigned int node_num);
void select(HufNode *huf_tree, unsigned int n, int *s1, int *s2);
void HufCode(HufNode *huf_tree, unsigned char_kinds);