#ifndef __node_h__
#define __node_h__

template<typename T> class Node {
public:
	Node(T);
	~Node();

	void setData(T);
	void setLeft(Node<T>*);
	void setRight(Node<T>*);

	T getData();
	Node<T>* getLeft();
	Node<T>* getRight();

private:
	T data;
	Node<T>* left, *right;
};

#include "node.tpp"

#endif
