// Doubly Linked List Header With Functions
// Author Omar Mohammad
#include <iostream>
using namespace std;
template<typename Type>
struct NodeType {
	Type info;
	NodeType<Type>* next;
	NodeType<Type>* previous;
};
template<typename Type>
class SingleLinkedList {
private:
	NodeType<Type>* first;
	NodeType<Type>* last;
	int count = 0;
public:
	void insertAtHead(Type info);
	void insertAtTail(Type info);
	void insertAt(Type info, int indx);
	//void insertAfter()
	void removeAtHead();
	void removeAtTail();
	void removeAt(int indx);
	
};