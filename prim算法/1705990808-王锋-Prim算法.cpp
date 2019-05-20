#pragma warning(disable:4996)
#include <iostream>
using namespace std;

#define MAX 1000 //�����ڽڵ��Ȩֵ

//����ͼ���ڽӾ�����   
typedef struct
{
	char* vertics;	//���ͼ�н��   
	int** edge;		//����ڽӾ���   
	int num;		//���ͼ�ж�������   
}Graph;

//��С��������n��������Ϣ
typedef struct
{
	char vertics;	//������Ϣ
	int weight;		//Ȩֵ
}MinSpanTree;

Graph graph;//����ͼ
MinSpanTree* tree;//��¼��С����������Ϣ

//����ͼ����Ϣ
void input(int num)
{
	tree = new MinSpanTree[num + 1];
	graph.vertics = new char[num + 1];
	graph.edge = new int* [num + 1];
	for (int i = 0; i <= num; i++)
	{
		graph.edge[i] = new int[num + 1];
	}
	graph.num = num;

	int temp;
	cout << "�������붥�����Ϣ" << endl;
	for (int i = 1; i <= graph.num; i++)
	{
		cout << "�����" << i << "������:";
		cin >> graph.vertics[i];
	}
	for (int i = 1; i <= graph.num; i++)
	{
		for (int j = i + 1; j <= graph.num; j++)
		{
			cout << "����" << graph.vertics[i] << "��" << graph.vertics[j] << "�ľ���" << endl;
			cin >> temp;
			graph.edge[i][j] = temp;
			graph.edge[j][i] = temp;
		}
	}
}

//����ķ�㷨
void prim()
{

	int min;
	int minPoint;
	int* lowCost = new int[graph.num + 1];

	lowCost[1] = -1;
	tree[1].vertics = graph.vertics[1];
	tree[1].weight = 0;

	for (int i = 2; i <= graph.num; i++)
	{
		lowCost[i] = graph.edge[1][i];
	}
	
	int count = 2;
	while (count <= graph.num)
	{
		min = MAX;
		for (int i = 2; i <= graph.num; i++)
		{
			if (lowCost[i] != -1 && lowCost[i] < min)
			{
				min = lowCost[i];
				minPoint = i;
			}
		}

		if (min == MAX)
		{
			cout << "�޷�������С������" << endl;
			return;
		}

		tree[count].vertics = graph.vertics[minPoint];
		tree[count].weight = lowCost[minPoint];
		
		lowCost[minPoint] = -1;
		for (int i = 2; i <= graph.num; i++)
		{
			if (lowCost[i] != -1 && graph.edge[minPoint][i] < lowCost[i])
			{
				lowCost[i] = graph.edge[minPoint][i];
			}
		}
		++count;
	}
}

//�����С����������Ϣ
void display()
{
	cout<<"��С��������ϢΪ��" << endl;
	int sum = 0;
	for (int i = 1; i <= graph.num; i++)
	{
		cout << "��" << i << "������Ķ���Ϊ:" << tree[i].vertics << "\tȨֵ:" << tree[i].weight << endl;
		sum += tree[i].weight;
	}
	//cout <<"��С"<< sum << endl;
}

int main()
{
	input(5);
	prim();
	display();
}

//������ͼ���ڽӾ������£�   
//      a   b   c   d   e   
 //  a      50  60 1000 1000   
 //  b          1000 65  40   
 //  c              52  1000   
  // d                   50   
  // e         