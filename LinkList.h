#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int ElemType;


typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;

//---------------------------------------------------------------------------------------------------------------------------


void SListprint(Node* phead);

void SListPushBack(Node** pphead, ElemType x);
void SListPushFront(Node** pphead,ElemType x);

void SListPopBack(Node** pphead);//尾删
void SListPopFront(Node** pphead);//头删

Node* SListFind(Node* phead, ElemType x);//找数据
void SListInsert(Node** pphead,Node* pos,ElemType x);//插入一数据
void SListDel(Node** pphead,Node* pos);//删除链表中一个元素

void SListDestory(Node** pphead);



//---------------------------------------------------------------------------------------------------------------------------
