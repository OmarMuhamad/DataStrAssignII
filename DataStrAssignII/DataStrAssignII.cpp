// Author OmarMohammad
// Last update 4/7/2023

#include "ArrayBasedList.h"
#include "SingleLinkedList.h"
int main() {
	SingleLinkedList<int> sll;
	sll.insertAtTail(5);
	sll.insertAtTail(5);
	sll.insertAtTail(5);
	sll.insertAtTail(5);
	sll.insertAtTail(5);
	
	cout << sll.isEmpty();
}