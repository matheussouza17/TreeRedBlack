#include "RedBlackTree.h"

int main()
{
	RedBlackTree* arvre = new RedBlackTree();
	int menu = -1;
	int v;

	do {
		system("cls");
		cout << "0: EXIT" << endl;
		cout << "1: Insert value" << endl;
		cout << "2: Delete value" << endl;
		cout << "3: Maximum and minimum value" << endl;
		cout << endl;
		arvre->printBeforeOrder();
		cout << endl << ">> ";
		cin >> menu;
		switch (menu)
		{
		case 0:
			cout << "Program finished." << endl;
			system("pause");
			break;
		case 1:
			cout << "Informe the value for insert: ";
			cin >> v;
			arvre->insert(v);
			break;
		case 2:
			cout << "Informe the value for delete: ";
			cin >> v;
			//arvre->delete(v);
			break;
		case 3:
			arvre->verifySmallAndBig();
			system("pause");
			break;
		default:
			break;
		}
	} while (menu);

	cout << endl;


	return 0;
}
