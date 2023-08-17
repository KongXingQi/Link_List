#include"List.h"


LTNode* ListInit()
{
	//ÉÚ±øÎ»
	LTNode* head = (LTNode*)malloc(sizeof(LTNode) * 1);
	head->next = head;
	head->prev = head;

	return head;
}
