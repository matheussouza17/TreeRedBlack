#include "Node.h"

void Node::setValue(int vall)
{
	value = vall;
}

void Node::setColor(Color cor)
{
	color = cor;
}

void Node::setLeft(Node* l)
{
	Left = l;
}

void Node::setRight(Node* r)
{
	Right = r;
}

void Node::setParent(Node*)
{
}


Node* Node::getParent()
{
	return nullptr;
}

Color Node::getColor()
{
	return color;
}

Node* Node::getLeft()
{
	return Left;
}

Node* Node::getRight()
{
	return Right;
}

int Node::getValue()
{
	return value;
}

Node::Node(int value)
{
	this->value = value;
	color = RED;
	Left = NULL;
	Right = NULL;
}

Node::~Node()
{
	delete Left;
	delete Right;
}

void Node::print(Node* arvoreemingles)
{
	if (arvoreemingles == NULL) {
		cout << "()";
		return;
	}
	cout << "("
		<< arvoreemingles->value;
	print(arvoreemingles->Left);
	print(arvoreemingles->Right);
	cout << ")";

}


int Node::factorBalancead()
{
	int height_r = this->Right ? this->Right->height() : -1;
	int height_l = this->Left ? this->Left->height() : -1;
	return height_r - height_l;
}

int Node::height()
{
	int height_r = this->Right ? this->Right->height() : -1;
	int height_l = this->Left ? this->Left->height() : -1;
	return 1 + max(height_r, height_l);
}