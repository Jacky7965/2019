// 从尾到头打印链表.cpp :
//
#pragma warning(disable:4996)
#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int data;
	ListNode* pnext;
};

ListNode* pHead;
void insertTail(int val) //尾插法
{
	ListNode* pnewnode = new ListNode();
	pnewnode->data = val;
	ListNode* ptail = pHead;
	while (ptail->pnext != NULL)
	{
		ptail = ptail->pnext;
	}
	ptail->pnext = pnewnode;
}

void Show()
{
	ListNode* pCur = pHead->pnext;
	while (pCur != NULL)
	{
		std::cout << pCur->data << " ";
		pCur = pCur->pnext;
	}
	std::cout << std::endl;
}

void PrintListReverse(ListNode* pHead)
{
	stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->pnext;
	}
	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->data);
		nodes.pop();
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		insertTail(i + 1);
	}
	Show();
	PrintListReverse(pHead);

}