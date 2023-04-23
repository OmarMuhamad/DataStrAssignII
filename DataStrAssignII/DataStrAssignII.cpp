// Author OmarMohammad
// Last update 4/7/2023

#include "ArrayBasedList.h"
//#include "SingleLinkedList.h"
//#include "StackLinkedList.h"
#include "QueueLinkedList.h"
int main() {
	Queue<int> qu;
	qu.enqueue(1);
	qu.enqueue(2);
	qu.enqueue(3);
	qu.enqueue(4);
	qu.enqueue(5);
	cout << qu.dequeuee() << endl;
	qu.print();
	cout << qu.queueSize() << endl;
	cout << qu.First() << endl;

}