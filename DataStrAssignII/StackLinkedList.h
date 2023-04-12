// Stack Using Linked List Header With Functions
// Author Omar Mohammad
#include <iostream>
using namespace std;

template<typename Type>
struct NodeType {
	Type info;
	NodeType<Type>* next;
};

template <typename Type>
class Stack {
private:
	NodeType<Type>* Top;
	int count = 0;
public:
	Stack() { Top = NULL; }
	Type top() {
		return Top->info;
	}
	void Push(Type data) {
		NodeType<Type>* newNode = new NodeType<Type>;
		newNode->info = data;
		if (Top == NULL) {
			Top = newNode;
			Top->next = NULL;
		}
		else {
			newNode->next = Top;
			Top = newNode;
		}
		count++;
	}
	void Pop() {
		NodeType<Type>* temp = new NodeType<Type>;
		if (Top == NULL) {
			cout << "Stack is Empty!" << endl;
			return;
		}
		else {
			temp = Top;
			Top = Top->next;
			delete temp;
		}
		count--;
	}
	bool isEmpty() { return Top == NULL; }
	int stckSize() { return count; }
	void clear() {
		NodeType<Type>* curr = new NodeType<Type>;
		while(Top != NULL){
			curr = Top;
			Top = Top->next;
			delete curr;
		}
	}
	void print() {
		NodeType<Type>* current = new NodeType<Type>;
		current = Top;
		while (current != NULL) {
			cout << current->info << " ";
			current = current->next;
		}
		cout << endl;
	}
};
