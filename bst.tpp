template<typename T> BSTree<T>::BSTree() {
	this->root = 0;
	this->sz = 0;
}

template<typename T> BSTree<T>::BSTree(T data) {
	this->root = new Node<T>(data);
	this->sz = 1;
}

template<typename T> BSTree<T>::~BSTree() {
	if(this->root)
		this->root->~Node();
	delete this->root;
}

/****************************************************/

template<typename T> int BSTree<T>::size() {
	return this->sz;
}

template<typename T> bool BSTree<T>::isEmpty() {
	return !this->sz;
}

template<typename T> bool BSTree<T>::contains(T data) {
	Node<T>* ptr = this->root;
	while(ptr)
		if(ptr->getData() == data)
			return true;
		else if(ptr->getData() > data)
			ptr = ptr->getLeft();
		else
			ptr = ptr->getRight();

	return false;
}

template<typename T> T BSTree<T>::getMin() {
	if(!this->root)
		throw NoSuchElement("[getMin]");

	Node<T>* ptr = this->root;
	while(ptr->getLeft())
		ptr = ptr->getLeft();
	return ptr->getData();
}

template<typename T> T BSTree<T>::getMax() {
	if(!this->root)
		throw NoSuchElement("[getMax]");

		Node<T>* ptr = this->root;
		while(ptr->getRight())
			ptr = ptr->getRight();
		return ptr->getData();
}

/******************************************************/

template<typename T> bool BSTree<T>::add(T data) {
	if(!this->root) {
		this->root = new Node<T>(data);
		this->sz = 1;
		return true;
	}

	Node<T>* ptr = this->root;
	for(;;)
		if(ptr->getData() == data)
			return false;
		else if(ptr->getData() > data)
			if(ptr->getLeft())
				ptr = ptr->getLeft();
			else {
				ptr->setLeft(new Node<T>(data));
				this->sz++;
				return true;
			}
		else
			if(ptr->getRight())
				ptr = ptr->getRight();
			else {
				ptr->setRight(new Node<T>(data));
				this->sz++;
				return true;
			}
}

template<typename T> bool BSTree<T>::remove(T data) {
	if(!this->root)
		throw NoSuchElement("[remove]");

	Node<T>* father = 0, *current = this->root;
	while(current->getData() != data) {
		father = current;
		if(current->getData() > data)
			if(current->getLeft())
				current = current->getLeft();
			else
				return false;
		else
			if(current->getRight())
				current = current->getRight();
			else
				return false;
	}

	if(!current->getLeft() || !current->getRight()) {
		Node<T>* aux = (current->getLeft())?current->getLeft():current->getRight();
		
		if(father)
			if(father->getData() > current->getData())
				father->setLeft(aux);
			else
				father->setRight(aux);
		else {
			if(!(this->sz-1)) {
				this->root->~Node();
				this->root = 0;
			} else {
				this->root->setLeft(0);
				this->root->setRight(0);
				this->root->~Node();
				this->root = aux;
			}
			this->sz--;
			return true;
		}

		current->setLeft(0);
		current->setRight(0);
		current->~Node();
		delete current;
	} else {
		Node<T>* aux = current->getRight();
		Node<T>* faux = current;
		
		while(aux->getLeft()) {
			faux = aux;
			aux = aux->getLeft();
		}

		if(faux != current)
			faux->setLeft(0);
		else
			faux->setRight(0);
		current->setData(aux->getData());
		aux->~Node();
		delete aux;
	}
	this->sz--;
	return true;
}

/******************************************************/

template<typename T> void BSTree<T>::printTree(ostream& ofs) {
	auxPrintTree(ofs, this->root, 0);
}

template<typename T> void BSTree<T>::auxPrintTree(ostream& ofs, Node<T>* current, int level) {
	if(!current)
		return;
	if(!ofs)
		throw BadStream();

	for(int i=0; i<level; i++)
		ofs << "-";
	ofs << " " << current->getData() << "\n";
	auxPrintTree(ofs, current->getLeft(), level+1);
	auxPrintTree(ofs, current->getRight(), level+1);
}

