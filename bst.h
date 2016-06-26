#ifndef __bst_h__
#define __bst_h__

#include <fstream>
using namespace std;

#include "node.h"
#include "exception.h"

template<typename T> class BSTree {
public:
	BSTree();
	BSTree(T);
	~BSTree();

	int size();
	bool isEmpty();

	bool add(T);
	bool remove(T);

	bool contains(T);
	T getMin();
	T getMax();

	// debugging method
	void printTree(ostream&);

protected:
	void auxPrintTree(ostream&, Node<T>*, int);

private:
	Node<T>* root;
	int sz;
};

#include "bst.tpp"

#endif
