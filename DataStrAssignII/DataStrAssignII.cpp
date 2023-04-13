// Author OmarMohammad
// Last update 4/7/2023

//#include "ArrayBasedList.h"
#include "SingleLinkedList.h"
//#include "StackLinkedList.h"
int main() {
	SingleLinkedList<int> lst;
	lst.insertAtTail(1);
	lst.insertAtTail(2);
	lst.insertAtTail(3);
	lst.insertAtTail(4);
	lst.insertAtTail(5);
	//lst.replaceAt(8, 2);
	cout << lst.linkedListSize() << endl;
	lst.swap(1, 2);
	lst.print();
	//lst.clear();
	//cout << lst.linkedListSize() << endl;
	//lst.retrieveAt(1);
}