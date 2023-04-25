// Author OmarMohammad
// Last update 24/7/2023

//#include "ArrayBasedList.h"
#include "SingleLinkedList.h"
//#include "StackLinkedList.h"
//#include "QueueLinkedList.h"
int main() {
	SingleLinkedList<int> ll;
	cout << "tc: 1" << endl;
	ll.insertAtTail(0);
	ll.insertAtTail(1);
	ll.insertAtTail(0);
	ll.insertAtTail(3);
	ll.insertAtTail(0);
	ll.insertAtTail(2);
	ll.insertAtTail(2);
	ll.insertAtTail(0);
	CombineNodes(ll.returnFirst());
	ll.clear();
	cout << "tc: 2" << endl;
	ll.insertAtTail(0);
	ll.insertAtTail(3);
	ll.insertAtTail(1);
	ll.insertAtTail(0);
	ll.insertAtTail(4);
	ll.insertAtTail(5);
	ll.insertAtTail(2);
	ll.insertAtTail(0);
	CombineNodes(ll.returnFirst());

}