#include "MyListNode.hpp"

class LinkedList {
	SingleNode* first;

public:
	LinkedList();

	void showList();

	void addFirts(int data);

	void addLast(int data);

	int addTo(int data, int ref);

	int addAfter(int data, int ref);

	int removeFirts();

	int removeLast();

	int removeElement(int ref);

	int get(int index);
};
