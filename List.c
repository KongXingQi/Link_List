#include"List.h"


LTNode* ListInit()
{
	//�ڱ�λ
	LTNode* head = (LTNode*)malloc(sizeof(LTNode) * 1);
	head->next = head;
	head->prev = head;

	return head;
}
