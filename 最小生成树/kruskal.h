#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

const int size = 128;
int n;
int father[size];
int rank[size];

//把每条边成为一个结构体，包括起点、终点和权值 
typedef struct node
{
	int val;
	int start;
	int end;
}edge[SIZE * SIZE / 2];

//把每个元素初始化为一个集合 
void make_set()
{
	for (int i = 0; i < n; i++) {
		father[i] = i;
		rank[i] = 1;
	}
	return;
}

//查找一个元素所在的集合,即找到祖先 
int find_set(int x)
{
	if (x != father[x]) {
		father[x] = find_set(father[x]);
	}
	return father[x];
}

//合并x,y所在的两个集合：利用Find_Set找到其中两个
//集合的祖先，将一个集合的祖先指向另一个集合的祖先。
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

int kruskal(int n) //n为边的数量 
{
	int sum = 0;
	make_set();
	for (int i = 0; i < n; i++) {   //从权最小的边开始加进图中 
		if (find_set(edge[i].start) != find_set(edge[i].end)) {
			Union(edge[i].start, edge[i].end);
			sum += edge[i].val;
		}
	}
	return sum;
}
