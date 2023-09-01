// ListStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "MyList.hpp"
#include "Expect.hpp"

int main()
{
	LinkedList list;
	Expect<int>(list.get(0)).toEqual(-1, "Al tratar de obtener el indice de una lista vacia NO devuelve -1");

	list.addFirts(10);
	Expect<int>(list.get(0)).toEqual(10, "Al agregar un elemento este NO se encuentra");

	list.removeFirts();
	Expect<int>(list.get(0)).toEqual(-1, "Al remover un elemento al principio, NO se remueve correctamente");

	list.addLast(10);
	Expect<int>(list.get(0)).toEqual(10, "Al agregar un elemento al final este NO se encuentra");

	list.removeLast();
	Expect<int>(list.get(0)).toEqual(-1, "Al remover un elemento al final, NO se remueve correctamente");

	list.showList();
	return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
