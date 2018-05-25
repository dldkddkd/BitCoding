/*
 * Stock.h
 *
 * Stock 자료구조 이중 연결 리스트
 *
 * Created on : 2018-05-01
 *     Author : Naissoft
 *	   Remark : 2018.04.29 조경제.
 */
#pragma once

namespace GameSystem
{
class cNode
{
public:
	cNode() {}
	virtual ~cNode() {}
private:
	int							mPrice;
	int							mCompNum;
	int							mAmount;

	bool						mIfChecked;

	cNode*						mpNextNode;
	cNode*						mpPrevNode;
public:
	void						SetPrice(int _price);
	void						SetCompanyNumber(int _compNum);
	void						SetAmount(int _amount);
	void						SetIfChecked(bool _ifChecked);
	void						SetNextNode(cNode *_nextNode);
	void						SetPrevNode(cNode *_prevNode);

	int							GetPrice();
	int		 					GetCompanyNumber();
	int							GetAmount();
	bool						GetIfChecked();
	cNode*						GetNextNode();
	cNode*						GetPrevNode();
};
class cStock
{
public:
	cStock() 
	{
		mHead = new cNode;
		mHead->SetNextNode(NULL);
		mHead->SetPrevNode(NULL);
	}
	virtual ~cStock() {}

private:
	cNode*						mHead;

public:
	cNode*						InsertNode(cNode* pTarget, cNode *insertStock);
	bool						DeleteNode(cNode *deleteStock);
	cNode*						SearchNode(int index);
	
	cNode*						GetHead();
};

}
