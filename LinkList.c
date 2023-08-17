#include"LinkList.h"

//---------------------------------------------------------------------------------------------------------------------------

Node* BuySlistNode(ElemType x)//����һ���ڵ�
{
	Node* newnode = (Node*)malloc(sizeof(Node) * 1);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListprint(Node* phead)//��ӡ����
{
	if (phead == NULL)
	{
		printf("������Ϊ�գ�\n");
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

void SListPushBack(Node** pphead, ElemType x)//β������
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


void SListPushFront(Node** pphead, ElemType x)//ͷ��
{
	Node* newnode = BuySlistNode(x);

	newnode->next = *pphead;
	*pphead = newnode;

}

void SListPopBack(Node** pphead)//βɾ
{

	assert(*pphead != NULL);//������Ϊ��

	if ((*pphead)->next == NULL)//ֻ��һ���ڵ�ʱ��
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

		//��˵�� ��������
		/*Node* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;*/

	}
	
}

void SListPopFront(Node** pphead)//ͷɾ
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
	printf("�Ҳ��� %d �������е�λ��!\n",x);
	exit(-1);

}

void SListInsert(Node** pphead, Node* pos, ElemType x)//������λ�ò���һ������
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


void SListDel(Node** pphead, Node* pos)//����λ��ɾ��һ��Ԫ��
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


void SListDestory(Node** pphead)//��������
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

