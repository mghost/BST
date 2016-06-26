template<typename T> Node<T>::Node(T data) {
	this->data = data;
	this->left = this->right = 0;
}

template<typename T> Node<T>::~Node() {
	if(this->left)
		this->left->~Node();
	if(this->right)
		this->right->~Node();
	delete this->left;
	delete this->right;
}

/*******************************************************/

// warning: this could be dangerous!!
template<typename T> void Node<T>::setData(T data) {
	this->data = data;
}

template<typename T> void Node<T>::setLeft(Node<T>* left) {
	this->left = left;
}

template<typename T> void Node<T>::setRight(Node<T>* right) {
	this->right = right;
}

/*******************************************************/

template<typename T> T Node<T>::getData() {
	return this->data;
}

template<typename T> Node<T>* Node<T>::getLeft() {
	return this->left;
}

template<typename T> Node<T>* Node<T>::getRight() {
	return this->right;
}
