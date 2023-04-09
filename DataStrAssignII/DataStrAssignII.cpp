// Author OmarMohammad
// Last update 4/7/2023

#include "ArrayBasedList.h"
#include "SingleLinkedList.h"
int main() {
	/*SingleLinkedList<int> sll;
	sll.insertAtTail(1);
	sll.insertAtTail(2);
	sll.insertAtTail(3);
	sll.insertAtTail(4);
	sll.insertAtTail(5);
	sll.print();
	sll.insertAt(6, 2);
	sll.print();*/
	ArrayBasedList<int> arr(5);
	arr.insertFirst(5);
	arr.insertFirst(4);
	arr.insertFirst(3);
	arr.insertFirst(2);
	arr.insertFirst(1);
	arr.removeAt(2);
	arr.print();
	cout << arr.maxListSize();
	//cout << sll.isEmpty();
}