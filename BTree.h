
#pragma once

#include <ostream>
#include "BinNode.h"
#include "Queue.h"
using namespace std;

enum class TraverseType { BREADTHORDER, PREORDER, INORDER, POSTORDER, Default = BREADTHORDER};

template <class P>
class BTree
{

private:

	// Attributes
	BinNode<P> *head;
	TraverseType traverseOrder;

	//output helper methods
	void postOrderOutputHelper(ostream& outStream, BinNode<P> *current) const
	{
		if (current != nullptr)
		{
			postOrderOutputHelper(outStream, current->getLeft());
			postOrderOutputHelper(outStream, current->getRight());
			outStream << *current;
			
		}
	}

	void inOrderOutputHelper(ostream& outStream, BinNode<P> *current) const
	{

		if (current != nullptr)
		{
			inOrderOutputHelper(outStream, current->getLeft());
			outStream << current->getPayload();
			inOrderOutputHelper(outStream, current->getRight());
		}
	}

	void preOrderOutputHelper(ostream& outStream, BinNode<P> *current) const
	{
		if (current != nullptr)
		{
			outStream << current->getPayload();
			preOrderOutputHelper(outStream, current->getLeft());
			preOrderOutputHelper(outStream, current->getRight());

		}
	}

	void breadthOrderOutputHelper(ostream& outStream, BinNode<P> *current) const
	{
		Queue<BinNode<P>*> BinQueue;
		
		if (current != nullptr)
		{
			BinQueue.enqueue(current);

			while (BinQueue.isEmpty() == false)
			{
				current = BinQueue.dequeue();
				outStream << current->getPayload();
				
				
				if (current->getLeft() != nullptr)
				{
					BinQueue.enqueue(current->getLeft());
				}

				if (current->getRight() != nullptr)
				{
					BinQueue.enqueue(current->getRight());
				}

				
			}

			
		}

		
	}

	// copy helper method
	BinNode<P> copyHelper(BinNode<P> current)
	{
		BinNode<P> *temp = nullptr;
		if (current != nullptr)
		{
			temp = new BinNode<P>(current.getPayload(), copyHelper(current->getLeft()), copyHelper(current->getRight()));
			
		}
			
		return temp;
	}

	
public:


	//Default constructor
	BTree()
	{
		BinNode<P> *head = nullptr;
		traverseOrder = TraverseType::BREADTHORDER;
	}

	
	/*BTree(const &BTree)
	{
		head = BTree.head;
		traverseOrder = BTree.traverseOrder();

		copyhelper(BTree.head);
	}
*/
	// //Deconstructor
	//~BTree()
	//{
	//	clearTree(head);
	//}


	// Set traverse order
	void setTraverseOrder(TraverseType newTraverseOrder)
	{
		traverseOrder = newTraverseOrder;
	}

	// Accessor 
	BinNode<P>* getRoot() const
	{
		return head;
	}

	
	// Mutators
	void setHead(BinNode<P> *node)
	{
		head = node;
	}


	// clear Tree Method
	void clearTree(BinNode<P> * current)
	{
		if (current != nullptr)
		{
			clearTree(current->getLeft());
			clearTree(current->getRight());
			delete current;
		}
	}



	// << overload
	friend ostream& operator <<(ostream& outStream, BTree tree)
	{
		switch (tree.traverseOrder)
		{
			case TraverseType::INORDER:
			{
				tree.inOrderOutputHelper(outStream, tree.head);
				break;
			}

			case TraverseType::PREORDER:
			{
				tree.preOrderOutputHelper(outStream, tree.head);
				break;
			}

			case TraverseType::POSTORDER:
			{
				tree.postOrderOutputHelper(outStream, tree.head);
				break;
			}


			case TraverseType::BREADTHORDER:
			{
				tree.breadthOrderOutputHelper(outStream, tree.head);
			}

			

		}

		return outStream;
	}


	// = overload
	 BTree& operator =(const BTree& fromTree)
	{
		
		 if (this->head == fromTree.head)
		 {

		 }
		 else
		 {
			 //clearTree();
			 this->head = copyHelper(fromTree.getRoot());
		 }


		return *this;
	}
};
