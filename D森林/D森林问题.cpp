#include "iostream"
#include "fstream"
#include "queue"
using namespace std;

const int MAX = 50;
int parent[MAX]; //存储父结点
int leaf[MAX];  //存储叶子结点
int deg[MAX];   //存储顶点的出度
int parlen[MAX]; //parlen[i]表示i结点到父节点的距离
int cut[MAX];  //存储分离后子树的根结点
int dist[MAX];  //dist[i]表示结点i到叶结点的距离

//从叶结点到根结点移动
double greedy(int n, int d)
{
	int total = 0;
	int i;
	memset(cut, 0, sizeof(cut));
	memset(dist, 0, sizeof(dist));
	for (i = 1; i <= leaf[0]; i++)
	{
		if (leaf[i] != 1) //如果不是根结点
		{
			int par = parent[leaf[i]];
			int len = parlen[leaf[i]];
			if (cut[par]<1 && dist[leaf[i]] + len>d) //如果路长超过d，且未分离
			{
				cut[par] = 1;
				par = parent[par];
				total++;
			}
			else if (cut[par] < 1 && dist[par] < dist[leaf[i]] + len) //如果未超过d，且未分离
				dist[par] = len + dist[leaf[i]];  //更新父结点路长
			if (--deg[par] == 0)   //如果出度边为0
				leaf[++leaf[0]] = par;
		}
	}
	return total;
}
/*
int main()
{
	ifstream fin("input.txt");
	int n, d;
	cout << "输入树的顶点数：";
	fin >> n; cout << n;
	cout << "\n输入各边的情况：\n";
	int a, len;
	int i, j;
	leaf[0] = 0;
	for (i = 1; i <= n; i++)
	{
		fin >> deg[i]; cout << deg[i] << " ";
		if (deg[i] == 0)   //如果出度为0，则为叶子，leaf[0]为叶子数
			leaf[++leaf[0]] = i;
		else
			for (j = 0; j < deg[i]; j++)
			{
				fin >> a >> len; cout << a << " " << len << " ";
				parent[a] = i;  //a结点的父结点为i
				parlen[a] = len;  //a结点到父结点的距离为len
			}
		cout << endl;
	}
	cout << "输入d:";
	fin >> d; cout << d;

	cout << "\n最小分离集s顶点数为：" << greedy(n, d);
	cout << endl;
	fin.close();
	return 0;
}*/