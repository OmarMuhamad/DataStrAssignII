// Queue Linked List Header With Functions
// Author Omar Mohammad
/*
enqueue (elementType element) : void
dequeue () : elementType element //return the first element and remove it.
first () : elementType element //return the first element without removing it.
isEmpty () : bool
queueSize () : int
clear (): void
print () : void
*/
#include <iostream>
using namespace std;

template<typename Type>
struct NodeType {
	Type info;
	NodeType<Type>* link;
}; 
template<typename Type>
class Queue {
	NodeType<Type>* first = NULL;
	NodeType<Type>* last = NULL;
	int count = 0;
public:
	void enqueue(Type);
	Type dequeuee(); //return the first element and remove it.
	Type First();
	int queueSize();
	bool isEmpty();
	void clear();
	void print();
};

template<typename Type>
void Queue<Type>::enqueue(Type info) {
	NodeType<Type>* newNode;
	newNode = new NodeType<Type>;
	newNode->info = info;
	newNode->link = NULL;
	if (first == NULL and last == NULL) {
		first = newNode;
		last = newNode;
		count++;
	}
	else {
		last->link = newNode;
		last = newNode;
		count++;
	}
}

template<typename Type>
Type Queue<Type>::dequeuee(){
	if (count == 0) {
		cout << "Cannot delete from an empty queue!" << endl;
		return 0;
	}
	else {
		NodeType<Type>* newNode;
		newNode = new NodeType<Type>;
		newNode = first;
		Type data = newNode->info;
		first = first->link;
		delete newNode;
		count--;
		return data;
	}
	
}

template<typename Type>
void Queue<Type>::print() {
	NodeType<Type>* newNode;
	newNode = new NodeType<Type>;
	newNode = first;
	while (newNode != NULL) {
		cout << newNode->info << " ";
		newNode = newNode->link;
	}
	cout << endl;
}

template<typename Type>
Type Queue<Type>::First(){
	if (count == 0) {
		cout << "Empty Queue!" << endl;
		return 0;
	}
	else return first->info;
}

template<typename Type>
bool Queue<Type>::isEmpty() {
	return count == 0;
}

template<typename Type>
void Queue<Type>::clear() {
	NodeType<Type>* current = new NodeType<Type>;
	while (first != NULL) {
		current = first;
		first = first->link;
		delete current;
	}
	last = NULL;
	count = 0;
}

template<typename Type>
int Queue<Type>::queueSize() {
	return count;
}