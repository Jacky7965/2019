#include "iostream"
#include "fstream"
#include "queue"
using namespace std;

const int MAX = 50;
int parent[MAX]; //�洢�����
int leaf[MAX];  //�洢Ҷ�ӽ��
int deg[MAX];   //�洢����ĳ���
int parlen[MAX]; //parlen[i]��ʾi��㵽���ڵ�ľ���
int cut[MAX];  //�洢����������ĸ����
int dist[MAX];  //dist[i]��ʾ���i��Ҷ���ľ���

//��Ҷ��㵽������ƶ�
double greedy(int n, int d)
{
	int total = 0;
	int i;
	memset(cut, 0, sizeof(cut));
	memset(dist, 0, sizeof(dist));
	for (i = 1; i <= leaf[0]; i++)
	{
		if (leaf[i] != 1) //������Ǹ����
		{
			int par = parent[leaf[i]];
			int len = parlen[leaf[i]];
			if (cut[par]<1 && dist[leaf[i]] + len>d) //���·������d����δ����
			{
				cut[par] = 1;
				par = parent[par];
				total++;
			}
			else if (cut[par] < 1 && dist[par] < dist[leaf[i]] + len) //���δ����d����δ����
				dist[par] = len + dist[leaf[i]];  //���¸����·��
			if (--deg[par] == 0)   //������ȱ�Ϊ0
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
	cout << "�������Ķ�������";
	fin >> n; cout << n;
	cout << "\n������ߵ������\n";
	int a, len;
	int i, j;
	leaf[0] = 0;
	for (i = 1; i <= n; i++)
	{
		fin >> deg[i]; cout << deg[i] << " ";
		if (deg[i] == 0)   //�������Ϊ0����ΪҶ�ӣ�leaf[0]ΪҶ����
			leaf[++leaf[0]] = i;
		else
			for (j = 0; j < deg[i]; j++)
			{
				fin >> a >> len; cout << a << " " << len << " ";
				parent[a] = i;  //a���ĸ����Ϊi
				parlen[a] = len;  //a��㵽�����ľ���Ϊlen
			}
		cout << endl;
	}
	cout << "����d:";
	fin >> d; cout << d;

	cout << "\n��С���뼯s������Ϊ��" << greedy(n, d);
	cout << endl;
	fin.close();
	return 0;
}*/