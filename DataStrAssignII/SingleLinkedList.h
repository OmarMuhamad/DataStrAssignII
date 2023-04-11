// Single Linked List Header With Functions
// Author Omar Mohammad
#include <iostream>
using namespace std;
template<typename Type>
struct NodeType {
	Type info;
	NodeType<Type>* next;
};
template<typename Type>
class SingleLinkedList{
private:
	NodeType<Type>* first;
	NodeType<Type>* last;
	int count = 0;
public:
	SingleLinkedList() { first = NULL, last = NULL; }
	void insertAtHead(Type element);
	void insertAtTail(const Type element);
	void insertAt(Type element, int index);
	void removeAtHead();
	void removeAtTail();
	void removeAt(int index);
	void retrieveAt(int index);
	void replaceAt(Type newElement, int index);
	bool isExist(Type element);
	bool isItemAtEqual(Type element, int index);
	void swap(int index1, int index2);
	bool isEmpty();
	int linkedListSize();
	void clear();
	void print();

};
template<typename Type>
void SingleLinkedList<Type>::insertAtHead(Type element) {
	NodeType<Type>* newNode; 
	newNode = new NodeType<Type>;
	newNode->info = element;
	newNode->next = NULL;
	if (first == NULL and last == NULL) {
		first = newNode;
		last = newNode;
		count++;
	}
	else {
		newNode->next = first;
		first = newNode;
		count++;
	}
}
template<typename Type>
void SingleLinkedList<Type>::insertAtTail(const Type element) {
	NodeType<Type>* newNode = new NodeType<Type>;
	newNode->info = element;
	newNode->next = NULL;
	if (first == NULL and last == NULL) {
		first = newNode;
		last = newNode;
		count++;
	}
	else {
		last->next = newNode;
		last = newNode;
		count++;
	}
}
template<typename Type>
void SingleLinkedList<Type>::insertAt(Type element, int index) {
	int counter = 1;
	NodeType<Type>* newNode = new NodeType<Type>;

	newNode->info = element;
	newNode->next = NULL;
	NodeType<Type>* current = new NodeType<Type>;
	NodeType<Type>* trailCurrent = new NodeType<Type>;
	if (index == 1) {
		insertAtHead(element);
		count++;
		return;
	}
	else if (count == index) {
		insertAtTail(element);
		count++;
		return;
	}
	current = first;
	bool t = false;
	while (current != NULL and !t) {
		if (counter == index) {
			t = true;
		}
		else {
			current = current->next;
			trailCurrent = current;
		}
		counter++;
	}
	if (t) {
		trailCurrent->next = newNode;
		newNode->next = current;
		count++;
	}
	
}
template<typename Type>
void SingleLinkedList<Type>::removeAtHead() {
	NodeType<Type>* current = new NodeType<Type>;
	current = first;
	first = first->next;
	delete current;
}
template<typename Type>
void SingleLinkedList<Type>::removeAtTail() {
	NodeType<Type>* current = new NodeType<Type>;
	NodeType<Type>* trailCurrent = new NodeType<Type>;
	current = first;
	while (current->next != NULL) {
		trailCurrent = current;
		current = current->next;
	}
	last = trailCurrent;
	delete current;
	
}
template<typename Type> 
void SingleLinkedList<Type>::removeAt(int index) {
	int counter = 1;
	NodeType<Type>* newNode = new NodeType<Type>;

	
	NodeType<Type>* current = new NodeType<Type>;
	NodeType<Type>* trailCurrent = new NodeType<Type>;
	while (current != NULL) {
		if (counter == index) {
			if (counter == 1) {
				//insertAtHead(element);
			}
			else if (counter == count) {
				//insertAtTail(element);
			}
			else {
				newNode->next = current;
				trailCurrent->next = newNode;
			}
		}
		else {
			counter++;
			trailCurrent = current;
			current = current->next;
		}
	}
	count++;
}
template<typename Type>
bool SingleLinkedList<Type>::isEmpty() {
	return (count == 0);
}
template<typename Type>
void SingleLinkedList<Type>::print() {
	NodeType<Type>* newNode;
	newNode = new NodeType<Type>;
	newNode = first;
	while (newNode != NULL) {
		cout << newNode->info << " ";
		newNode = newNode->next;
	}
	cout << endl;
}
template<typename Type>
int SingleLinkedList<Type>::linkedListSize() {
	return count;
}
template<typename Type>
void SingleLinkedList<Type>::clear(){
	NodeType<Type>* current = new NodeType<Type>;
	while (first != NULL) {
		current = first;
		first = first->next;
		delete current
	}
	last = NULL;
	count = 0;
}