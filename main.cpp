#include <iostream>
#include <cassert>
#include "bst.h"

int main(void) {
	BSTree<int> bst = BSTree<int>();
	
	assert(bst.isEmpty());
	
	bst.add(42);
	bst.add(15);
	bst.add(16);
	bst.add(11);
	bst.add(45);
	bst.add(44);
	bst.add(77);
	
	assert(bst.size() == 7);
	assert(bst.getMin() == 11);
	assert(bst.getMax() == 77);

	assert(bst.contains(42));
	assert(bst.contains(15));
	assert(bst.contains(16));
	assert(bst.contains(11));
	assert(bst.contains(45));
	assert(bst.contains(44));
	assert(bst.contains(77));

	for(int i=46; i<55; i++)
		assert(!bst.contains(i));

	bst.printTree(cout);
	cout << endl;
	assert(bst.remove(42));
	bst.printTree(cout);
	cout << endl;
	assert(bst.remove(15));
	bst.printTree(cout);
	cout << endl;
	assert(bst.remove(16));
	bst.printTree(cout);
	cout << endl;
	assert(bst.remove(11));
	bst.printTree(cout);
	cout << endl;
	assert(bst.remove(77));
	bst.printTree(cout);
	cout << endl;
	assert(bst.remove(44));
	bst.printTree(cout);
	cout << endl;
	assert(bst.remove(45));
	bst.printTree(cout);

	assert(bst.isEmpty());

	try {
		bst.getMin();
	} catch(NoSuchElement) {
		// cerr << "NoSuchElement Exception Thrown!" << endl;
	}

	return 0;
}
