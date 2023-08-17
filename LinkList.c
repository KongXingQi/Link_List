#include"LinkList.h"

//---------------------------------------------------------------------------------------------------------------------------

Node* BuySlistNode(ElemType x)//开辟一个节点
{
	Node* newnode = (Node*)malloc(sizeof(Node) * 1);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListprint(Node* phead)//打印链表
{
	if (phead == NULL)
	{
		printf("此链表为空！\n");
	}
	else
	{
		Node* sur = phead;
		while (sur != NULL)
		{
			printf("%d ", sur->data);
			sur = sur->next;
		}
		printf("\n");
	}

}

void SListPushBack(Node** pphead, ElemType x)//尾插链表
{

	Node* newnode = BuySlistNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		Node* tail = *pphead;
		while (tail->next  != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}


}


void SListPushFront(Node** pphead, ElemType x)//头插
{
	Node* newnode = BuySlistNode(x);

	newnode->next = *pphead;
	*pphead = newnode;

}

void SListPopBack(Node** pphead)//尾删
{

	assert(*pphead != NULL);//链表不能为空

	if ((*pphead)->next == NULL)//只有一个节点时候
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		Node* prev = *pphead;
		Node* tail = *pphead;

		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;

		//有说法 啊哈哈哈
		/*Node* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;*/

	}
	
}

void SListPopFront(Node** pphead)//头删
{
	assert(*pphead != NULL);

	Node* next = (*pphead)->next;
	free(*pphead);
	(*pphead)->next = NULL;
	*pphead = next;

}


Node* SListFind(Node* phead, ElemType x)
{
	while (phead != NULL)
	{
		if (phead->data == x)
		{
			return phead;
		}
		else
		{
			phead = phead->next;
		}
	}
	printf("找不到 %d 在链表中的位置!\n",x);
	exit(-1);

}

void SListInsert(Node** pphead, Node* pos, ElemType x)//在任意位置插入一个数据
{
	
	Node* newnode = BuySlistNode(x);
	if (*pphead != pos)
	{
		Node* posprev = *pphead;
		newnode->next = pos;

		while (posprev->next != pos)
		{
			posprev = posprev->next;
		}

		posprev->next = newnode;
	}
	else
	{
		newnode->next = *pphead;
		*pphead= newnode;

	}
	
}


void SListDel(Node** pphead, Node* pos)//任意位置删除一个元素
{

	assert(*pphead != NULL);

	Node* cur = *pphead, *prve = NULL;

	if (cur == pos)
	{
		*pphead = (*pphead)->next;
		free(cur);
	}
	else
	{
		while (cur != pos)
		{
			prve = cur;
			cur = cur->next;
		}
		prve->next = cur->next;
		free(cur);
	}

	
}


void SListDestory(Node** pphead)//销毁链表
{
	Node* cur = *pphead;
	while (*pphead != NULL)
	{
		*pphead = (*pphead)->next;
		free(cur);
		cur = *pphead;
	}


}


//---------------------------------------------------------------------------------------------------------------------------

