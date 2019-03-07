
		// Destructor
		~BinNode()
		{
	
		}
	};

#pragma once

// includes
#include <ostream>
using namespace std;

template <class P>
class BinNode
{
private:

	P payload;
	BinNode *left;
	BinNode *right;

public:

	//constructor
	BinNode(P newPayload)
	{
		// Constructor
		payload = newPayload;
		left = nullptr;
		right = nullptr;
	}

	//constructor with parameters
	BinNode(P newPayload, BinNode<P>* newLeft, BinNode<P>* newRight)
	{
		payload = newPayload;
		left = newLeft;
		right = newRight;
	}

	// accessors 
	P getPayload() const
	{
		return payload;

	}

	BinNode* getLeft() const
	{
		
			// get left pointer
			return left;
		
	}

	BinNode* getRight() const
	{
		
			//get the right pointer
			return right;
		
	}

	// mutators
	void setPayload(P newPayload)
	{
		// set the payload
		payload = newPayload;

	}

	void setLeft(BinNode *newLeft)
	{
		// set the new pointer

		left = newLeft;

	}

	void setRight(BinNode *newRight)
	{
		// set the new right pointer
		right = newRight;
	}

	// Operator Overload
	friend ostream& operator <<(ostream& outStream, const BinNode& node)
	{
		outStream << node.getPayload();
		return outStream;
	}

	// Destructor
	~BinNode()
	{

	}
};
