#include "MyList.hpp";

LinkedList::LinkedList() {
	this->first = NULL;
}

void LinkedList::showList()
{
	SingleNode* node = first;
	while (node != NULL)
	{
		std::cout << "| " << node->data << " |";
		node = node->next;
	}
	std::cout << std::endl;
}

int LinkedList::addAfter(int data, int ref) {
	int index = 0;

	if (first != NULL) {
		std::cout << "| Agregando posterior a | " << ref << std::endl;
		SingleNode* node = new SingleNode();
		node->data = data;

		SingleNode* actual = first;
		while (actual != NULL && actual->data != ref)
		{
			actual = actual->next;
			index++;
		}

		if (actual == NULL) return 0;

		std::cout << "| El valor | " << node->data << std::endl;
		actual->next = node;
	}
	else {
		// La lista esta vacia..
		index = -1;
	}
	return index;
}

void LinkedList::addFirts(int data) {
	SingleNode* node = new SingleNode();
	node->data = data;
	// Agregar al inicio de la lista...
	node->next = first;
	first = node;
}

void LinkedList::addLast(int data) {
	SingleNode* node = new SingleNode();
	node->data = data;

	// Si existe al menos un elemento en la lista...
	if (first != NULL) {
		SingleNode* actual = first;
		while (actual->next != NULL)
		{
			actual = actual->next;
		}
		// En este punto "actual" es el último nodo de la lista...
		actual->next = node;
	}
	else {
		first = node;
	}
}

int LinkedList::addTo(int data, int ref) {
	int index = 0;

	if (first != NULL) {
		SingleNode* node = new SingleNode();
		SingleNode* actual = first;
		SingleNode* before = NULL;
		node->data = data;

		while (actual != NULL && actual->data != ref)
		{
			before = actual;
			actual = actual->next;
			index++;
		}
		// before es una referencia al elemento anterior...

		if (actual != NULL) { // no llegamos al final de la lista...

			if (actual == first) { // Es el primero de la lista...
				node->next = first;
				first = node;
			}
			else {
				before->next = node;
				node->next = actual;
			}
		}
		else // Llegamos al final de la lista
		{
			index = 0;
		}
	}
	else {
		// La lista esta vacia..
		index = -1;
	}
	return index;
}

int LinkedList::removeFirts() {
	if (first != NULL) {
		SingleNode* toRemove = first;
		first = first->next; // En caso de que existan más.
		delete (toRemove);
		return 1;
	}
	return 0; // lista vacia.
}

int LinkedList::removeLast() {
	if (first == NULL) return 0;

	SingleNode* node = first;
	SingleNode* before = NULL;

	while (node->next != NULL)
	{
		before = node;
		node = node->next;
	}

	if (node == first) {
		delete first;
		first = NULL;
		return 1;
	}

	node->next = NULL;
	before->next = NULL;
	delete node;
	return 1;
}

int LinkedList::removeElement(int ref) {

	if (first == NULL) return -1;

	if (first->data == ref) {
		std::cout << "| Se remueve el primer elemento |" << std::endl;
		removeFirts();
		return 1;
	}

	SingleNode* node = first;
	SingleNode* before = NULL;

	std::cout << "| Buscando el elemento a remover |" << std::endl;

	while (node != NULL && node->data != ref)
	{
		before = node;
		node = node->next;
	}

	std::cout << "El elemento encontrado es : " << node->data << std::endl;

	if (node->data != ref) {// No se encontro...
		return 0;
	}
	else { // No es el primero...
		before->next = node->next;
		delete node;
	}

}

int LinkedList::get(int index)
{
	SingleNode* node = first;
	int counter = 0;
	while (node != NULL && counter != index)
		node = node->next;
	if (node == NULL) return -1;
	return node->data;
}
