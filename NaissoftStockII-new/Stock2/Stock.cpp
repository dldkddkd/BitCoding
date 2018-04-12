#include <stdio.h>
#include <stdlib.h>

#include "Stock.h"

Stock *gHead, *gNow, gTmp;

void InitStock()
{
	gHead = (Stock *)malloc(sizeof(Stock));
	gHead->next = NULL;
	gHead->prev = NULL;
}

Stock *InsertStock(Stock *Target, Stock *aStock)
{
	Stock *New;
	Stock *Right;

	New = (Stock *)malloc(sizeof(Stock));
	*New = *aStock;

	Right = Target->next;
	New->next = Right;
	New->prev = Target;

	Target->next = New;
	if (Right) Right->prev = New;
	return New;
}

bool DeleteStock(Stock *Target)
{
	Stock *left, *right;

	if (Target == NULL || Target == gHead) return false;

	left = Target->prev;
	right = Target->next;

	left->next = right;
	if (right) right->prev = left;

	free(Target);
	return true;
}

void AppendStock(Stock *aStock)
{
	Stock *tail;

	for (tail = gHead; tail->next; tail = tail->next){}
	InsertStock(tail, aStock);
}

Stock *FindStock(int idx)
{
	Stock *now;
	int index = 0;

	for (now = gHead->next; now; now = now->next)
	{
		if (index == idx) return now;
		index++;
	}
	return NULL;
}

void UnInitStock()
{
	while (DeleteStock(gHead)) { ; }

	free(gHead);
	gHead = NULL;
}