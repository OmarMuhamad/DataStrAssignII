// Single Linked List Header With Functions
#include <iostream>
using namespace std;
template<typename Type>
struct NodeType {
	Type* info;
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
	void insertAtHead(Type element);//
	void insertAtTail(Type element);//
	void insertAt(Type element, int index);//
	void removeAtHead();//
	void removeAtTail();//
	void removeAt(int index);
	void retrieveAt(int index);
	void replaceAt(Type newElement, int index);
	bool isExist(Type element);
	bool isItemAtEqual(Type element, int index);
	void swap(int index1, int index2);
	bool isEmpty();//
	int linkedListSize();
	bool clear();
	void print();

};
template<typename Type>
void SingleLinkedList<Type>::insertAtHead(Type element) {
	NodeType<Type>* newNode = new NodeType<Type>;
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
void SingleLinkedList<Type>::insertAtTail(Type element) {
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
	while (current != NULL) {
		if (counter == index) {
			if (counter == 1) {
				insertAtHead(element);
			}
			else if (counter == count) {
				insertAtTail(element);
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
void SingleLinkedList<Type>::removeAtHead() {
	NodeType<Type>* current = new NodeType<Type>;
	current = first;
	first = first->next;
	delete current;
}
template<typename Type>
void SingleLinkedList<Type>::removeAtTail() {
	NodeType<Type>* current = new NodeType<Type>;
	NodeType<Type>* trialCurrent = new NodeType<Type>;
	current = first;
	while (current->next != Null) {
		trailCurrent = current;
		current = current->next
	}
	last = trailCurrent;
	delete current;
	
}
template<typename Type> 
void SingleLinkedList<Type>::removeAt(Type element, int index) {
	int counter = 1;
	NodeType<Type>* newNode = new NodeType<Type>;

	newNode->info = element;
	newNode->next = NULL;
	NodeType<Type>* current = new NodeType<Type>;
	NodeType<Type>* trailCurrent = new NodeType<Type>;
	while (current != NULL) {
		if (counter == index) {
			if (counter == 1) {
				insertAtHead(element);
			}
			else if (counter == count) {
				insertAtTail(element);
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
	return count == 0;
}
