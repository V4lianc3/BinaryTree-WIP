


#include <iostream>
#include <string>
#include "BTree.h"
#include"Queue.h"
using namespace std;

int main()
{

	


		BTree<char> tree1, tree2;
		BinNode<char> *node1, *node2;
		tree1.setHead(new BinNode<char>('A'));
		//Level 1
		node1 = tree1.getRoot();
		node1->setLeft(new BinNode<char>('B'));
		node1->setRight(new BinNode<char>('C'));
		// Level 2
		node2 = node1->getRight(); // C
		node1 = node1->getLeft(); // B
		node1->setRight(new BinNode<char>('D'));
		node2->setLeft(new BinNode<char>('E'));
		node2->setRight(new BinNode<char>('F'));
		// Level 3
		node1 = node2->getLeft(); // E
		node2 = node2->getRight(); // F
		node1->setLeft(new BinNode<char>('G'));
		node2->setLeft(new BinNode<char>('H'));
		node2->setRight(new BinNode<char>('I'));
		tree1.setTraverseOrder(TraverseType::PREORDER);
		cout << "Tree 1 (preorder)    : " << tree1 << endl;
		tree1.setTraverseOrder(TraverseType::INORDER);
		cout << "Tree 1 (inorder)     : " << tree1 << endl;
		tree1.setTraverseOrder(TraverseType::POSTORDER);
		cout << "Tree 1 (postorder)   : " << tree1 << endl;
		tree1.setTraverseOrder(TraverseType::BREADTHORDER);
		cout << "Tree 1 (breadthorder): " << tree1 << endl;
		//Test the copy constructor and = method.
		tree2 = tree1;
		cout << "Tree 2               : " << tree2 << endl;
		/*BTree<char> tree3(tree1);
		cout << "Tree 3               : " << tree3 << endl;*/
	system("PAUSE");
	return 0;
}
