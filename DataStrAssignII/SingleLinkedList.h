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
template<typename Type>
void SingleLinkedList<Type>::swap(int indx1, int indx2) {
	if (indx1 == indx2) return;
	NodeType<Type>* prevX = NULL, *prevY = NULL, *currX, *currY;
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
		currY = currY -> next;
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
bool SingleLinkedList<Type>::isItemAtEqual(Type element, int indx) {
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
void SingleLinkedList<Type>::replaceAt(Type element, int index) {
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
bool SingleLinkedList<Type>::isExist(Type element) {
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

template<typename Type>
void SingleLinkedList<Type>::retrieveAt(int indx) {
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
	trailCurrent->next = NULL;
	delete current;
	count--;
	
}

template<typename Type> 
void SingleLinkedList<Type>::removeAt(int index) {
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
		delete current;
	}
	last = NULL;
	count = 0;
}

void CombineNodes(NodeType<int>* first) {
	SingleLinkedList<int> new_sll;
	bool start, end; start = end = false;// start and end
	NodeType<int>* st, * nd; // two pointers to start and end
	NodeType<int>* newNode = new NodeType<int>; // to iterate
	newNode = first;
	while (newNode != NULL) {
		// if it is the first zero in the list
		if (newNode->info == 0 and start == false and end == false) {
			st = newNode;
		}
		// if it is the second zero
		else if (newNode->info == 0 and end == false and start == true) {
			nd = newNode;
		}
		// if we found the start and end of the list (we found a range)
		if (start and end) {
			int sum = 0;
			NodeType<int>* newNode1 = new NodeType<int>; // to iterate within the start and end
			newNode1 = st->next;
			// while the end is not reached
			while (newNode1 != nd) {
				sum += newNode1->info;
				newNode1 = newNode1->next;
			}
			new_sll.insertAtTail(sum);
			nd = st; // make the end of the range is the start of the next range
			start = true; // mark the start of the next range to be true
			end = false; // mark the end of the next range to be false
		}
		newNode = newNode->next; // iterate through the original ll
	}

}