#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

const int size = 128;
int n;
int father[size];
int rank[size];

//��ÿ���߳�Ϊһ���ṹ�壬������㡢�յ��Ȩֵ 
typedef struct node
{
	int val;
	int start;
	int end;
}edge[SIZE * SIZE / 2];

//��ÿ��Ԫ�س�ʼ��Ϊһ������ 
void make_set()
{
	for (int i = 0; i < n; i++) {
		father[i] = i;
		rank[i] = 1;
	}
	return;
}

//����һ��Ԫ�����ڵļ���,���ҵ����� 
int find_set(int x)
{
	if (x != father[x]) {
		father[x] = find_set(father[x]);
	}
	return father[x];
}

//�ϲ�x,y���ڵ��������ϣ�����Find_Set�ҵ���������
//���ϵ����ȣ���һ�����ϵ�����ָ����һ�����ϵ����ȡ�
void Union(int x, int y)
{
	x = find_set(x);
	y = find_set(y);
	if (x == y) {
		return;
	}
	if (rank[x] < rank[y]) {
		father[x] = find_set(y);
	}
	else {
		if (rank[x] == rank[y]) {
			rank[x] ++;
		}
		father[y] = find_set(x);
	}
	return;
}

bool cmp(pnode a, pnode b)
{
	return a.val < b.val;
}

int kruskal(int n) //nΪ�ߵ����� 
{
	int sum = 0;
	make_set();
	for (int i = 0; i < n; i++) {   //��Ȩ��С�ı߿�ʼ�ӽ�ͼ�� 
		if (find_set(edge[i].start) != find_set(edge[i].end)) {
			Union(edge[i].start, edge[i].end);
			sum += edge[i].val;
		}
	}
	return sum;
}
