#pragma once
using namespace std;
#include <iostream>

enum Color { RED, BLACK };

class Node
{
private:
	int value;
	Color color;
	Node* Left;
	Node* Right;
	Node* parent;
public:
	void setValue(int);
	void setColor(Color);
	void setLeft(Node*);
	void setRight(Node*);
	void setParent(Node*);
	
	Node* getParent();
	Color getColor();
	Node* getLeft();
	Node* getRight();	
	int getValue();

	Node(int value);
	~Node();

	void print(Node* tree);

	int factorBalancead();
	int height();
};


