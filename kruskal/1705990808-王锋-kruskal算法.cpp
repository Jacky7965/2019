#pragma warning(disable:4996)
#include <iostream>
using namespace std;

#define NoEdge 1000  //������Ȩֵ��ʾ

//����ͼ���ڽӾ�����
typedef struct
{
	char* vertics;//���ͼ�н��
	int** edge;//����ڽӾ���
	int num;//���ͼ�ж�������
}Graph;

Graph graph;//����С��������ͼ
int* set;//���ڼ�¼��ͬ����ͨ����

//����ͼ����Ϣ
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

		cout << "����ͼ�ж�����Ϣ��char��:" << endl;
		i = 1;
		while (i <= graph.num)
		{
			cout << "��" << i << "���ڵ���Ϣ" << endl;
			cin >> graph.vertics[i++];
		}

		cout << "����ͼ�ĸ��ߵ�Ȩֵ�����û�����ӣ�����1000������" << endl;
		int j;
		for (i = 1; i <= graph.num; i++)
		{
			for (j = i + 1; j <= graph.num; j++)
			{
				cout << "����" << graph.vertics[i] << "��" << graph.vertics[j] << "֮���Ȩֵ" << endl;
				cin >> graph.edge[i][j];
			}
		}
}

//Kruskal����С������
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
		
		cout << "\n��С��������Ϣ��" << endl;
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
				cout << "�޷�������С������" << endl;
				return;
			}
			
			if (set[low] != set[high])
			{
				cout << "��" << count << "����"  << graph.vertics[low] << "��" << graph.vertics[high] << "����"<< endl;
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

//������ͼ���ڽӾ������£�
//      a   b     c      d     e
 //  a      30   60     1000  1000
 //  b           1000   55    40
 //  c                  22    1000
 //  d                        50
 //  e                    