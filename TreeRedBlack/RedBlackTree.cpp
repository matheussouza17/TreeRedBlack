#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
	raiz = NULL;
}


void RedBlackTree::insert(int value)
{
	if (raiz == nullptr) {
		raiz = new Node(value);
	}
	else
		insert(value, raiz);
}

void RedBlackTree::insert(int valor, Node* no)
{
	if (no == NULL) {
		no = new Node(valor);
		return;
	}


	if (valor < no->getValue()) {
		if (no->getLeft() == nullptr) {
			Node* aux = new Node(valor);
			no->setLeft(aux);
			VerifyBalenced(raiz);
		}
		else {
			insert(valor, no->getLeft());
			return;
		}
	}
	else if (valor > no->getValue()) {
		if (no->getRight() == nullptr) {
			Node* aux = new Node(valor);
			no->setRight(aux);
			VerifyBalenced(raiz);
		}
		else {
			insert(valor, no->getRight());
			return;
		}
	}
	else {
		cout << "Valor repetido!" << endl;
		return;
	}
}

bool RedBlackTree::exist(int value)
{
	return exist(raiz, value); //Utilizando sobrecarga para não precisar passando a raiz toda vez
}

bool RedBlackTree::exist(Node* no, int value)
{
	if (no == nullptr) /*verificando se o nó é nulo, pois se sim, chegou ao final da àrvore em questão...
		PS: Não da àrvore completa, e sim da "arvore do nó", pois outro lado pode-se encontrar o valor, já que ela tem esquerda e direita*/
	{
		return false; //retornando falso, mais como é utilizado recursivamente, não necessáriamente quer dizer que não fo encontrado o valor, AINDA
	}

	if (no->getValue() == value) //Caso dê verdadeiro, seu valor foi encontrado e será retornado true	
		return true;


	else if (value < no->getValue()) //se o valor em questão a ser proucurado for menor que o atual, ele vai fazer recursivamente a esquerda, caso contrario, será maior, então analiza a direita
		return exist(no->getLeft(), value);

	else
		return exist(no->getRight(), value);

}

//print menor e maior
void RedBlackTree::verifySmallAndBig()
{
	Node* minNode = ValueMin(raiz);
	Node* maxNode = ValueMax(raiz);

	cout << "Big value = " << maxNode->getValue()
		<< "\nSmall value = " << minNode->getValue() << endl;
}

//verificar o menor e maior
Node* RedBlackTree::ValueMin(Node* no)
{
	while (no->getLeft() != NULL) {
		no = no->getLeft();
	}
	return no;
}

Node* RedBlackTree::ValueMax(Node* no)
{
	while (no->getRight() != NULL) {
		no = no->getRight();
	}
	return no;
}


void RedBlackTree::VerifyBalenced(Node* no)
{
	int Vb = no->factorBalancead();
	if (Vb > 1) {
		if (no->getRight()->factorBalancead() < 0)
			DoubleLeftRightRotation(no);
		else
			SimpleLeftRotation(no);

	}
	else if (Vb < -1) {
		if (no->getLeft()->factorBalancead() > 0)
			DoubleRightLeftRotation(no);
		else
			SimpleRightRotation(no);

	}

	if (no->getLeft())
		VerifyBalenced(no->getLeft());
	if (no->getRight())
		VerifyBalenced(no->getRight());

}

void RedBlackTree::DoubleLeftRightRotation(Node* no)
{
	cout << "Double Right Rotation..." << endl;
	SimpleLeftRotation(no->getRight());
	SimpleRightRotation(no);
}

void RedBlackTree::DoubleRightLeftRotation(Node* no)
{
	cout << "Double Right Rotation..." << endl;
	SimpleRightRotation(no->getLeft());
	SimpleLeftRotation(no);
}

void RedBlackTree::SimpleRightRotation(Node* no)
{
	cout << "Simple Right Rotation..." << endl;
	Node* temp = no->getLeft();
	no->setLeft(temp->getRight());
	if (temp->getRight() != nullptr)
		temp->getRight()->setParent(no);

	temp->setRight(no);
	if (no->getParent() == nullptr)
		raiz = temp;
	else if (no == no->getParent()->getLeft())
		no->getParent()->setLeft(temp);
	else
		no->getParent()->setRight(temp);

	temp->setParent(no->getParent());
	no->setParent(temp);
}

void RedBlackTree::SimpleLeftRotation(Node* no)
{
	cout << "Simple Left Rotation..." << endl;
	Node* temp = no->getRight();
	no->setRight(temp->getLeft());
	temp->setLeft(no);
	if (no == raiz) raiz = temp;
}

void RedBlackTree::printBeforeOrder(Node* no)
{
	if (no != NULL) {
		cout << no->getValue();
		cout << "(";
		printBeforeOrder(no->getLeft());
		printBeforeOrder(no->getRight());
		cout << ")";
	}
}



void RedBlackTree::update(Node* no)
{
	if (no) {
		no->factorBalancead();
	}
}
bool RedBlackTree::IsEmpty(Node* no)
{
	return (no == NULL ? true : false);
}


Node* RedBlackTree::deleteValue(Node* no, int v)
{
	if (IsEmpty(no)) {
		cout << "Value not found!" << endl;
		return no;
	}

	if (v < no->getValue())
		no->setLeft(deleteValue(no->getLeft(), v));
	else if (v > no->getValue())
		no->setRight(deleteValue(no->getRight(), v));
	else {
		if (no->getLeft() == NULL) {
			Node* aux = no->getRight();
			delete (no);
			return aux;
		}
		else if (no->getRight() == NULL)
		{
			Node* aux = no->getLeft();
			delete (no);
			return aux;
		}
		else
		{
			Node* successor = getSuccessor(no->getRight());
			no->setValue(successor->getValue());
			no->setRight(deleteValue(no->getRight(), successor->getValue()));

		}

	}
}

Node* RedBlackTree::getSuccessor(Node* no)
{
	Node* current = no;
	while (current and current->getLeft() != NULL)
		current = current->getLeft();
	return current;
}











