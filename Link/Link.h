#pragma once
#pragma warning(disable:4996)
#include <iostream>

class Link
{
public:
	Link(); //���캯��
	~Link(); //��������
	void insertHead(int val); //ͷ�巨
	void insertTail(int val); //β�巨
	void deleteNode(int val); //ɾ����������ֵΪval�Ľڵ�
	void show(); //��ӡ����
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

