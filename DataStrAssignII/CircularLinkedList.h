#include <iostream>
using namespace std;
template<typename Type>
struct NodeType {
	Type info;
	NodeType<Type>* next;
};
// same implementation of single but the remove(head, tail) will be updated and any update function
template<typename Type>
class CircularLinkedList {
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
	int CircularlinkedListSize();
	void clear();
	void print();

};
template<typename Type>
void CircularLinkedList<Type>::swap(int indx1, int indx2) {
	if (indx1 == indx2) return;
	NodeType<Type>* prevX = NULL, * prevY = NULL, * currX, * currY;
	currX = new NodeType<Type>;
	currY = new NodeType<Type>;
	currX = first;
	while (currX and currX->info != indx1) {
		prevX = currX;
		currX = currX->next;
	}
	currY = first;
	while (currY and currY->info != indx2) {
		prevY = currY;
		currY = currY->next;
	}
	// if indx1 or indx2 are not in list
	if (currX == NULL or currY == NULL) {
		return;
	}

	if (prevX != NULL) {
		prevX->next = currY;
	}
	else first = currY;
	if (prevY != NULL) {
		prevY->next = currX;
	}
	else {
		first = currX;
	}
	// swap next pointers
	NodeType<Type>* temp = new NodeType<Type>;
	temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

template<typename Type>
bool CircularLinkedList<Type>::isItemAtEqual(Type element, int indx) {
	int counter = 1;
	NodeType<Type>* current = new NodeType<Type>;
	if (indx > count or indx < 0) {
		cout << "Out Of Range\n";
		return 0;
	}
	bool found = false;
	current = first;
	while (current != NULL) {
		if (indx == counter) {
			if (current->info == element) {
				found = true;
			}
		}
		current = current->next;
		counter++;
	}
	return found;
}

template<typename Type>
void CircularLinkedList<Type>::replaceAt(Type element, int index) {
	int counter = 1;
	NodeType<Type>* current = new NodeType<Type>;
	if (index > count or index < 0) {
		cout << "Out Of Range\n";
		return;
	}
	current = first;
	while (current != NULL) {
		if (index == counter) {
			current->info = element;
		}
		current = current->next;
		counter++;
	}
}

template<typename Type>
void CircularLinkedList<Type>::retrieveAt(int indx) {
	NodeType<Type>* newNode = new NodeType<Type>;
	newNode = first;
	int counter = 0;
	while (newNode != NULL) {
		if (counter == indx) {
			cout << newNode->info << endl;
			break;
		}
		newNode = newNode->next;
		counter++;

	}
	//cout << endl;
}

template<typename Type>
void CircularLinkedList<Type>::insertAtHead(Type element) {
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
void CircularLinkedList<Type>::insertAtTail(const Type element) {
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
		last->next = newNode;
		last = newNode;
		count++;
	}
}

template<typename Type>
void CircularLinkedList<Type>::insertAt(Type element, int index) {
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
void CircularLinkedList<Type>::removeAtHead() {
	NodeType<Type>* current = new NodeType<Type>;
	current = first;
	first = first->next;
	last->next = first;
	delete current;
}

template<typename Type>
void CircularLinkedList<Type>::removeAtTail() {
	if (first == NULL) {
		cout << "Cannot Delete from an Empty List\n";
		return;
	}
	NodeType<Type>* current = new NodeType<Type>;
	NodeType<Type>* trailCurrent = new NodeType<Type>;
	current = first;
	while (current->next != NULL) {
		trailCurrent = current;
		current = current->next;
	}
	last = trailCurrent;
	trailCurrent->next = first;
	delete current;
	count--;
}

template<typename Type>
void CircularLinkedList<Type>::removeAt(int index) {
	int counter = 1;
	if (index == 1) {
		count--;
		removeAtHead();
		return;
	}
	else if (index == count) {
		count--;
		removeAtTail();
		return;
	}
	cout << counter << endl;
	NodeType<Type>* current = new NodeType<Type>;
	NodeType<Type>* trailCurrent = new NodeType<Type>;
	current = first;
	while (current != NULL) {
		if (counter == index) {
			count--;
			cout << trailCurrent->info << endl;
			trailCurrent->next = current->next;
			delete current;
			break;
		}
		counter++;
		trailCurrent = current;
		current = current->next;
	}
}

template<typename Type>
bool CircularLinkedList<Type>::isEmpty() {
	return (count == 0);
}

template<typename Type>
void CircularLinkedList<Type>::print() {
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
int CircularLinkedList<Type>::CircularlinkedListSize() {
	return count;
}

template<typename Type>
void CircularLinkedList<Type>::clear() {
	NodeType<Type>* current = new NodeType<Type>;
	while (first != NULL) {
		current = first;
		first = first->next;
		delete current;
	}
	last = NULL;
	count = 0;
}

template<typename Type>
bool CircularLinkedList<Type>::isExist(Type element) {
	NodeType<Type>* newNode = new NodeType<Type>;
	newNode = first;
	bool found = false;
	while (newNode != NULL and !found) {
		if (newNode->info == element) {
			found = true;
		}
		else {
			newNode = newNode->next;
		}
	}
	return found;
}