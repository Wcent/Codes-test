// HuffmanCoding.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct CNode
{
	int value;
	int weight;
	bool flag;
	CNode *left;
	CNode *right;
};

CNode * huffmanCoding(CNode *p, int len);
void showHuffmanCode(CNode *p, int *code, int len);
void showCode(int value, int *code, int len);

int _tmain(int argc, _TCHAR* argv[])
{
	char str[100];
	cout<<"please input a sequence of number :";
	cin>>str;
	
	int count[10] = {0};
	for(int i=0; str[i]!='\0'; i++)
	{
		if(str[i] < '0' || str[i] > '9')
			continue;
		count[str[i]-'0']++;
	}
	
	int n = 0;
	for(int i=0; i<10; i++)
	{
		if(count[i] == 0)
			continue;
		n++;
		cout<<i<<" : "<<count[i]<<" "<<endl;
	}
	
	CNode *p = new CNode[2*n];
	for(int i=0, j=0; i<10; i++)
	{
		if(count[i] == 0)
			continue;
		p[j].value = i;
		p[j].weight = count[i];
		p[j].flag = false;
		p[j].left = NULL;
		p[j].right = NULL;
		j++;
	}
	for(int j=n; j<2*n; j++)
	{
		p[j].value = -1;
		p[j].weight = -1;
		p[j].flag = false;
		p[j].left = NULL;
		p[j].right = NULL;
	}
	
	cout<<endl;
	CNode *root = huffmanCoding(p, n);
	int code[15], k=0;
	showHuffmanCode(root, code, k);

	return 0;
}

// ~huffman coding
// ~

CNode * huffmanCoding(CNode *p, int len)
{
	int min, secMin;
	int m, sm;
	
	while(1)
	{
		m = -1;
		min = -1;
		for(int i=0; i<len; i++)
		{
			if(p[i].flag == true)
				continue;
			if(m == -1 || min > p[i].weight)
			{
				sm = m;
				secMin = min;
				m = i;
				min = p[i].weight;
			}
			else if(secMin == -1 || secMin > p[i].weight)
			{
				sm = i;
				secMin = p[i].weight;
			}
		}
		
		if(m != -1 && sm == -1)
			return &p[m];
			
		p[m].flag = true;
		p[sm].flag = true;
		p[len].weight = p[m].weight + p[sm].weight;
		p[len].left = &p[m];
		p[len].right = &p[sm];
		len++;
	}
}

void showHuffmanCode(CNode *p, int *code, int len)
{
	if(p->left == NULL && p->right == NULL)
	{
		showCode(p->value, code, len);
		return ;
	}
	if(p->left != NULL)
	{
		code[len++] = 0;
		showHuffmanCode(p->left, code, len);
		len--;
	}
	if(p->right != NULL)
	{
		code[len++] = 1;
		showHuffmanCode(p->right, code, len);
		len--;
	}
}

void showCode(int value, int *code, int len)
{
	if(len == 0)
		return ;
		
	cout<<value<<" : ";
	for(int i=0; i<len; i++)
		cout<<code[i];
	cout<<endl;
}
