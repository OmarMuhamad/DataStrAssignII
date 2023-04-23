#include <iostream>
using namespace std;

struct NodeType {
	Type info;
	NodeType<Type>* next;
};
template<typename Type>
class SingleLinkedList {
private:
	NodeType<Type>* first;
	NodeType<Type>* last;
	int count = 0;
public:
	
	void insertAtHead(Type element);
	void insertAtTail(Type element);
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