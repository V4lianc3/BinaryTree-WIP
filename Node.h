#pragma once

// includes
#include <ostream>
using namespace std;

// Code provided by Cliff Snyder
template <class P>
class Node
{
private:
	P payload;
	Node *next;

public:
	// constructor
	Node(P newPayload, Node* newNext)
	{
		// Constructor
		payload = newPayload;
		next = newNext;
	}

	// accessors 
	P getPayload() const
	{
		return payload;

	}

	Node* getNext() const
	{

		// get next pointer
		return next;

	}

	// mutators
	void setPayload(P newPayload)
	{
		// set the payload
		payload = newPayload;

	}

	void setNext(Node *newNext)
	{
		// set the new pointer

		next = newNext;

	}

	// Operator Overload
	friend ostream& operator <<(ostream& outStream, const Node& node)
	{
		outStream << node.getPayload();
		return outStream;
	}

	// Destructor
	~Node()
	{

	}
};
