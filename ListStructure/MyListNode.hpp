#pragma once
#include <iostream>

class LinkedList;

class SingleNode {
	int data;
	SingleNode *next;

	SingleNode();
	friend class LinkedList; // Definiendo el nivel de acceso...
};


