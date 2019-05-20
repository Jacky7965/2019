#pragma warning(disable:4996)
#include <iostream>
using namespace std;

#define NoEdge 1000  //无连接权值表示

//无向图的邻接矩阵定义
typedef struct
{
	char* vertics;//存放图中结点
	int** edge;//存放邻接矩阵
	int num;//存放图中顶点数量
}Graph;

Graph graph;//求最小生成树的图
int* set;//用于记录不同的连通分量

//输入图的信息
void input(int num)
{
		set = new int[num + 1];
		graph.num = num;
		graph.vertics = new char[num + 1];
		graph.edge = new int* [num + 1];
		int i = 0;
		while (i <= num)
		{
			graph.edge[i] = new int[num + 1];
			++i;
		}

		cout << "输入图中顶点信息（char）:" << endl;
		i = 1;
		while (i <= graph.num)
		{
			cout << "第" << i << "个节点信息" << endl;
			cin >> graph.vertics[i++];
		}

		cout << "输入图的各边的权值（如果没有连接，输入1000）处理：" << endl;
		int j;
		for (i = 1; i <= graph.num; i++)
		{
			for (j = i + 1; j <= graph.num; j++)
			{
				cout << "输入" << graph.vertics[i] << "到" << graph.vertics[j] << "之间的权值" << endl;
				cin >> graph.edge[i][j];
			}
		}
}

//Kruskal求最小生成树
void kruskal()
{
		int min;
		int low;
		int high;
		int count = 1;
		
		for (int i = 1; i <= graph.num; i++)
		{
			set[i] = i;
		}
		
		cout << "\n最小生成树信息：" << endl;
		while (count <= graph.num - 1)
		{
			min = NoEdge;
			for (int i = 1; i <= graph.num; i++)
			{
				for (int j = i + 1; j <= graph.num; j++)
				{
					if (graph.edge[i][j] < min)
					{
						min = graph.edge[i][j];
						low = i;
						high = j;
					}
				}
			}

			if (min == NoEdge)
			{
				cout << "无法生成最小生成树" << endl;
				return;
			}
			
			if (set[low] != set[high])
			{
				cout << "第" << count << "条边"  << graph.vertics[low] << "与" << graph.vertics[high] << "连接"<< endl;
				for (int m = 1; m <= graph.num; m++)
				{
					if (set[m] == set[high])
					{
						set[m] = set[low];
					}
				}
				++count;
			}
			graph.edge[low][high] = NoEdge;
		}
	
}

int main()
{
	input(5);
	kruskal();
}

//测试用图的邻接矩阵如下：
//      a   b     c      d     e
 //  a      30   60     1000  1000
 //  b           1000   55    40
 //  c                  22    1000
 //  d                        50
 //  e                    