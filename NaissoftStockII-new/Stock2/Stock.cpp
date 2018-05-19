#include "global.h"


namespace GameSystem
{
	
void cNode::SetPrice(int _price)
{
	mPrice						= _price;
}

void cNode::SetCompanyNumber(int _compNum)
{
	mCompNum					= _compNum;
}

void cNode::SetAmount(int _amount)
{
	mAmount						= _amount;
}

void cNode::SetIfChecked(bool _ifChecked)
{
	mIfChecked					= _ifChecked;
}

void cNode::SetNextNode(cNode *_nextNode)
{
	mpNextNode					= _nextNode;
}


void cNode::SetPrevNode(cNode *_prevNode)
{
	mpPrevNode					= _prevNode;
}

int	cNode::GetPrice()
{
	return mPrice;
}

int	cNode::GetCompanyNumber()
{
	return mCompNum;
}

int cNode::GetAmount()
{
	return mAmount;
}

bool cNode::GetIfChecked()
{
	return mIfChecked;
}

cNode* cNode::GetNextNode()
{
	return mpNextNode;
}

cNode* cNode::GetPrevNode()
{
	return mpPrevNode;
}

cNode* cStock::InsertNode(cNode *pTarget, cNode *insertStock)
{
	cNode *pNewNode = new cNode;
	cNode *pRight = pTarget->GetNextNode();

	*pNewNode = *insertStock;

	
	pNewNode->SetNextNode(pRight);
	pNewNode->SetPrevNode(pTarget);

	pTarget->SetNextNode(pNewNode);

	if (pRight)
		pRight->SetNextNode(pNewNode);

	return pNewNode;
}

bool cStock::DeleteNode(cNode *deleteStock)
{
	cNode *pLeft;
	cNode *pRight;

	if (deleteStock == NULL || deleteStock == mHead)
		return false;

	pLeft						= deleteStock->GetPrevNode();
	pRight						= deleteStock->GetNextNode();

	pLeft->SetNextNode(pRight);

	if (pRight)
		pRight->SetPrevNode(pLeft);

	delete deleteStock;

	return true;
}
cNode* cStock::SearchNode(int index)
{
	int ind = 0;

	cNode *pNow;
	
	for (pNow = mHead->GetNextNode(); pNow; pNow = pNow->GetNextNode())
	{
		if (ind == index)
			return pNow;
		ind++;
	}

	return NULL;
}

cNode* cStock::GetHead()
{
	return mHead;
}
}
