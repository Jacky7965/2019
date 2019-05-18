#pragma once
#pragma warning(disable:4996)
#include <iostream>

class Link
{
public:
	Link(); //构造函数
	~Link(); //析构函数
	void insertHead(int val); //头插法
	void insertTail(int val); //尾插法
	void deleteNode(int val); //删除链表所有值为val的节点
	void show(); //打印链表
private:
	class Node
	{
	public:
		Node(int data = 0) :_data(data), _pnext(NULL) {}
		int _data;
		Node* _pnext;
	};
	Node* _phead;
};

