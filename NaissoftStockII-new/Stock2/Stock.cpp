#include <stdio.h>
#include <stdlib.h>

#include "Stock.h"

Stock *gHead, *gNow, gTmp;

Stock comStock[10];

/** Initialize stock node
*
* @return void
*/
void InitStock()
{
	gHead = (Stock *)malloc(sizeof(Stock));
	gHead->next = NULL;
	gHead->prev = NULL;
}
/** Initialize Computer stock node
*
* @return void
*/
void InitComputerStock() {
	int i;
	
	for (i = 0; i < 10; i++) {
		comStock[i].company = 0;
		comStock[i].price = 0;
	}

}
/** Insert stock next target node
*
* @param *pTarget
* Where to insert
*
* @param *aStock
* The node to insert
*
* @return Stock pointer
* New node inserted
*/
Stock *InsertStock(Stock *pTarget, Stock *aStock)
{
	Stock *pNew;
	Stock *pRight;

	pNew = (Stock *)malloc(sizeof(Stock));
	*pNew = *aStock;

	pRight = pTarget->next;
	pNew->next = pRight;
	pNew->prev = pTarget;

	pTarget->next = pNew;

	if (pRight) 
		pRight->prev = pNew;

	return pNew;
}

/** Delete a target node
*
* @param *pTarget
* Node to delete
*
* @return bool
* If the target node exists, return true
* Not exists, return false
*/
bool DeleteStock(Stock *pTarget)
{
	Stock *pLeft, *pRight;

	if (pTarget == NULL || pTarget == gHead) 
		return false;

	pLeft = pTarget->prev;
	pRight = pTarget->next;

	pLeft->next = pRight;
	if (pRight) pRight->prev = pLeft;

	free(pTarget);
	return true;
}

/** Add the node after the end
* 사용되지 않습니다
* @param *aStock
* Node to add
*
* @return void
*/
void AppendStock(Stock *aStock)
{
	Stock *pTail;

	for (pTail = gHead; pTail->next; pTail = pTail->next){}
	InsertStock(pTail, aStock);
}

/** Find the node of the index
*
* @param idx
* Location of the node user want to find
*
* @return Stock pointer
* Found the Node or NULL
*/
Stock *FindStock(int idx)
{
	Stock *now;
	int index = 0;

	for (now = gHead->next; now; now = now->next)
	{
		if (index == idx) 
			return now;
		index++;
	}
	return NULL;
}

/** Deallocate all stock nodes
*
* @return void
*/
void DeallocateStock()
{
	while (DeleteStock(gHead)) { ; }

	free(gHead);
	gHead = NULL;
}