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
int operatorPrec(char op) {
	if (op == '^')
		return 3;
	else if (op == '/' or op == '*')
		return 2;
	else if (op == '+' or op == '-')
		return 1;
	else
		return 0;
}
string infixToPostfix(string infix) {
	Stack<char> st;
	string postfix = "";
	for (int i = 0; i < infix.size(); i++) {
		if (isalpha(infix[i]) or (infix[i] >= '0' and infix[i] <= '9')) {
			postfix += infix[i];
		}
		else if (infix[i] == '(') {
			st.Push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (st.top() != '(') {
				postfix += st.top();
				st.Pop();
			}
			st.Pop();
		}
		// operator
		else {
			while (!st.isEmpty() and (operatorPrec(infix[i]) <= operatorPrec(st.top()))) {
				postfix += st.top();
				st.Pop();
			}
			st.Push(infix[i]);
		}
	}
	while (!st.isEmpty()) {
		postfix += st.top();
		st.Pop();
	}
	return postfix;
}