#include "Link.h"



Link::Link() //���캯��
{
	_phead=new Node();
}

Link::~Link()//��������
{
	Node* pCur = _phead;
	Node* pNext = pCur;
	while (pCur != NULL)
	{
		pNext = pCur->_pnext;
		delete pCur;
		pCur = pNext;
	}
	_phead = NULL;
}

void Link::insertHead(int val) //ͷ�巨
{
	Node* pnewnode = new Node(val);
	pnewnode->_pnext = _phead->_pnext;
	_phead->_pnext = pnewnode;
}

void Link::insertTail(int val) //β�巨
{
	Node* pnewnode = new Node(val);
	Node* ptail = _phead;
	while (ptail->_pnext != NULL)
	{
		ptail = ptail->_pnext;
	}
	ptail->_pnext = pnewnode;
}

void Link::deleteNode(int val) //ɾ����������ֵΪval�Ľڵ�
{
	Node* pfront = _phead;
	Node* pCur = NULL;
	while (pfront->_pnext != NULL)
	{
		if (pfront->_pnext->_data == val)
		{
			pCur = pfront->_pnext;
			pfront->_pnext = pCur->_pnext;
			delete pCur;
		}
		else
		{
			pfront = pfront->_pnext;
		}
	}
}

void Link::show()//��ӡ����
{
	Node* pCur = _phead->_pnext;
	while (pCur != NULL)
	{
		std::cout << pCur->_data << " ";
		pCur = pCur->_pnext;
	}
	std::cout << std::endl;
}

int main()
{
	Link link;
	for (int i = 0; i < 5; i++)
	{
		link.insertHead(i + 1);
	}
	link.show();
	for (int i = 0; i < 5; i++)
	{
		link.insertTail(i + 1);
	}
	link.insertTail(1);
	link.show();
	link.deleteNode(1);
	link.show();
	return 0;
}
