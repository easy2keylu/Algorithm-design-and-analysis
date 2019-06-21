#include "Huffman.h"
#include<iostream>
#include<malloc.h>

#define OK 1
#define ERROR 0

using namespace std;

//����Huffman��
int CreateHuffmanTree(HuffmanTree pHT,int weight[],int n){
	int s1, s2,i;
	int m = 2 * n - 1;

	for (i = 1; i <= n; i++) {
		pHT[i].weight = weight[i - 1];
		pHT[i].lchild = 0;
		pHT[i].rchild = 0;
		pHT[i].parent = 0;
	}
	for (i=n+1; i <= m; i++) {
		pHT[i].parent = 0;
		pHT[i].lchild = 0;
		pHT[i].rchild = 0;
		pHT[i].weight = 0;
	}

//	cout << "���Գ�ʼ��Huffman������б�" << endl;
//	if (TestHufTree(pHT))
//		cout << "������ϣ�" << endl;

	for (i = n + 1; i <= m; i++)
	{
		//��pHT[1...i-1]��ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2
		Select(pHT, i - 1, s1, s2);
		pHT[s1].parent = i;
		pHT[s2].parent = i; //�޸�s1��s2���ĸ�ָ��parent

		pHT[i].lchild = s1;
		pHT[i].rchild = s2; //�޸�i�������Һ���ָ��

		pHT[i].weight = pHT[s1].weight + pHT[s2].weight; //�޸�Ȩֵ
//		cout << "257�Լ��Ժ� �޸�Ȩֵ���ֵ��" << i << "\t" << pHT[i].weight << endl;
	}

//	cout << "��������Huffman������б�" << endl;
//	if (TestHufTree(pHT))
//		cout << "������ϣ�" << endl;
	return OK;
}

//����
int CreateHuffmanTree2(HuffmanTree &pHT, int w[], int n)
{//w���n������Ȩֵ��������һ�ù�������pHT
	int i, m;
	int s1, s2;


//	HuffmanTree p;

	if (n <= 1) return ERROR;
	m = 2 * n - 1; //n��Ҷ�ӽ��Ĺ�����������2*n-1�����
	pHT = (HuffmanTree)malloc((m +1 ) * sizeof(HTNode)); //����2*n�����ռ�,0�ŵ�Ԫδ��

	for ( i = 1; i <= n; ++i) //���г�ʼ��
	{
		pHT[i].weight = w[i];
		pHT[i].parent = 0;
		pHT[i].lchild = 0;
		pHT[i].rchild = 0;
	}
	for (; i <= m; ++i)
	{
		pHT[i].weight = 0;
		pHT[i].parent = 0;
		pHT[i].lchild = 0;
		pHT[i].rchild = 0;
	}


	for (i = n + 1; i <= m; ++i) //����������
	{
		//��pHT[1...i-1]��ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2
		Select(pHT, i - 1, s1, s2);
		pHT[s1].parent = i;
		pHT[s2].parent = i; //�޸�s1��s2���ĸ�ָ��parent

		pHT[i].lchild = s1;
		pHT[i].rchild = s2; //�޸�i�������Һ���ָ��

		pHT[i].weight = pHT[s1].weight + pHT[s2].weight; //�޸�Ȩֵ
	}
	return OK;
}

//����Huffman���ڵ�������Ȩֵ��С�Ľڵ�
int Select(HuffmanTree pHT, int nSize) {
	int minValue = 0x7FFFFFFF;	//��Сֵ
	int min = 0;				//Ԫ�����

	//�ҵ���СȨֵ��Ԫ�����
	for (int i = 1; i <= nSize; i++)
	{
		if (pHT[i].parent == 0 && pHT[i].weight<minValue)
		{
			minValue = pHT[i].weight;
			min = i;
		}
	}
	return min;
}

void Select(HuffmanTree &pHT, int i, int &s1, int &s2) {
	int minValue = 0x7FFFFFFF;

	//�ҵ���С��һ��Ȩֵ
	for (int j = 1; j <= i; j++) {
		if (pHT[j].parent == 0 && pHT[j].weight<minValue) {
			minValue = pHT[j].weight;
			s1 = j;
		}
	}
//	cout << "��СȨֵ��" << s1;

	minValue = 0x7FFFFFFF;
	//�ҵ������ڶ�С��Ȩֵ
	for (int j = 1; j <= i; j++) {
		if (j != s1 && pHT[j].parent == 0 && pHT[j].weight < minValue) {
			minValue = pHT[j].weight;
			s2 = j;
		}
	}
//	cout << "\t��֮Ȩֵ��" << s2 << endl;
}

//����Huffman���� 
int HuffmanCoding(HuffmanCode &pHC, HuffmanTree &pHT)
{
	//��ջ�ǵݹ����Huffman������Huffman����
	char cd[256] = { '\0' };	//��¼����·��
	int cdlen = 0;				//��¼��ǰ·������

	for (int i = 1; i < 512; i++) {
		pHT[i].weight = 0;	//����Huffman��ʱ�����ڵ��״̬��־
	}

	int p = 511;			//���ڵ�
	while (p != 0) {
		//����
		if (pHT[p].weight == 0) {
			pHT[p].weight = 1;
			if (pHT[p].lchild != 0) {
				p = pHT[p].lchild;
				cd[cdlen++] = '0';
			}
			//�Ǽ�Ҷ�ӽڵ���ַ��ı���
			else if(pHT[p].rchild==0){
				pHC[p] = (char*)malloc((cdlen + 1) * sizeof(char));
				cd[cdlen] = '\0';
				strcpy(pHC[p], cd);//���Ʊ���
			}
		}
		//����
		else if (pHT[p].weight == 1) {
			pHT[p].weight = 2;
			//�Һ���ΪҶ�ӽڵ�
			if (pHT[p].rchild != 0) {
				p = pHT[p].rchild;
				cd[cdlen++] = '1';
			}
		}
		//�˻ظ��ڵ㣬���볤�ȼ�һ
		else {
			pHT[p].weight = 0;
			p = pHT[p].parent;
			cdlen--;
		}
	}
	return OK;
}

int TestHufTree(HuffmanTree pHT) {
	cout << "Byte\t\tWeight\tParent\tLchild\tRchild\n";
	for (int i = 1; i < 512; i++) {
		if (i <= 99) {
			cout << "pHT[" << i << "]\t\t" << pHT[i].weight << "\t" << pHT[i].parent << "\t" << pHT[i].lchild << "\t" << pHT[i].rchild << endl;
		}
		else {
			cout << "pHT[" << i << "]\t" << pHT[i].weight << "\t" << pHT[i].parent << "\t" << pHT[i].lchild << "\t" << pHT[i].rchild << endl;
		}

	}
	return OK;
}