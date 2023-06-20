#pragma once
#include "Node.h"
class RedBlackTree
{
private:
	Node* raiz;

public:
	RedBlackTree();

	void insert(int value);
	void insert(int, Node*);

	bool exist(int value);
	bool exist(Node* no, int value);

	void verifySmallAndBig();

	Node* ValueMax(Node*);
	Node* ValueMin(Node*);

	bool IsEmpty(Node*);

	void VerifyBalenced(Node*);

	void DoubleLeftRightRotation(Node*);
	void DoubleRightLeftRotation(Node*);

	void SimpleRightRotation(Node*);
	void SimpleLeftRotation(Node*);

	void printBeforeOrder(Node*);
	void printBeforeOrder() { printBeforeOrder(raiz); }

	void update() { update(raiz); }
	void update(Node*);

	Node* deleteValue(int value) { deleteValue(raiz, value); }
	Node* deleteValue(Node* no, int v);

	Node* getSuccessor(Node* no);

};

