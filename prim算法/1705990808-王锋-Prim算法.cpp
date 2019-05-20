#pragma warning(disable:4996)
#include <iostream>
using namespace std;

#define MAX 1000 //非相邻节点的权值

//无向图的邻接矩阵定义   
typedef struct
{
	char* vertics;	//存放图中结点   
	int** edge;		//存放邻接矩阵   
	int num;		//存放图中顶点数量   
}Graph;

//最小生成树的n个结点的信息
typedef struct
{
	char vertics;	//顶点信息
	int weight;		//权值
}MinSpanTree;

Graph graph;//定义图
MinSpanTree* tree;//记录最小生成树的信息

//输入图的信息
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
	cout << "下面输入顶点的信息" << endl;
	for (int i = 1; i <= graph.num; i++)
	{
		cout << "输入第" << i << "个顶点:";
		cin >> graph.vertics[i];
	}
	for (int i = 1; i <= graph.num; i++)
	{
		for (int j = i + 1; j <= graph.num; j++)
		{
			cout << "输入" << graph.vertics[i] << "到" << graph.vertics[j] << "的距离" << endl;
			cin >> temp;
			graph.edge[i][j] = temp;
			graph.edge[j][i] = temp;
		}
	}
}

//普林姆算法
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
			cout << "无法生成最小生成树" << endl;
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

//输出最小生成树的信息
void display()
{
	cout<<"最小生成树信息为：" << endl;
	int sum = 0;
	for (int i = 1; i <= graph.num; i++)
	{
		cout << "第" << i << "个加入的顶点为:" << tree[i].vertics << "\t权值:" << tree[i].weight << endl;
		sum += tree[i].weight;
	}
	//cout <<"最小"<< sum << endl;
}

int main()
{
	input(5);
	prim();
	display();
}

//测试用图的邻接矩阵如下：   
//      a   b   c   d   e   
 //  a      50  60 1000 1000   
 //  b          1000 65  40   
 //  c              52  1000   
  // d                   50   
  // e         