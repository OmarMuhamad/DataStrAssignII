#include <iostream>
using namespace std;

template<typename Type>
class ArrayBasedList {
	Type* list ;
	int length;
	int maxSize;
public:
	ArrayBasedList(int);
	void insertFirst(Type);
	void insertLast(Type);
	void insertAt(Type, int);
	Type retrieveAt(int);
	void removeAt(int);
	void replaceAt(Type, int);
	bool isItemEqual(Type, int);
	bool isEmpty();
	bool isFull();
	int maxListSize();
	void clear();
	void print();
};
template<typename Type>
ArrayBasedList<Type>::ArrayBasedList(int sz) {
	list = new Type[sz];
	length = 0;
	maxSize = sz;
}

template<typename Type>
void ArrayBasedList<Type>::insertFirst(Type element) {
	if (length == maxSize) {
		cout << "List is FUll!" << endl;
	}
	else {
		// looping from back until loc is reached and shifting elements
		for (int i = length; i > 0; i--) {
			list[i] = list[i - 1];
		}
		length++;
		list[0] = element;
	}
}

template<typename Type>
void ArrayBasedList<Type>::insertLast(Type element) {
	if (length == maxSize) {
		cout << "List is Full!" << endl;
	}
	else {
		list[length] = element;
		length++;
	}
}

template<typename Type>
void ArrayBasedList<Type>::insertAt(Type element, int index) {
	if (index >= length or index < 0) {
		cout << "Out of Range!" << endl;
	}
	else if (length == maxSize) {
		cout << "List is FUll!" << endl;
	}
	else {
		// looping from back until loc is reached and shifting elements
		for (int i = length; i > index; i--) {
			list[i] = list[i - 1];
		}
		length++;
		list[index] = element;
	}
}

template<typename Type>
void ArrayBasedList<Type>::removeAt(int index) {
	if (index >= length or index < 0) {
		cout << "Out of Range!" << endl;
	}
	else {
		for (int i = index; i < length - 1; i++) {
			list[i] = list[i + 1];
		}
	}
	length--;
}

template<typename Type>
void ArrayBasedList<Type>::replaceAt(Type element, int index) {
	if (index >= length or index < 0) {
		cout << "Out of Range!" << endl;
	}
	else {
		list[index] = element;
	}
}

template<typename Type>
Type ArrayBasedList<Type>::retrieveAt(int index) {
	if (index >= length or index < 0) {
		cout << "Out of Range!" << endl;
	}
	else return list[index];
}

template<typename Type>
bool ArrayBasedList<Type>::isEmpty() {
	return (length == 0);
}

template<typename Type>
bool ArrayBasedList<Type>::isFull() {
	return (length == maxSize);
}

template<typename Type>
bool ArrayBasedList<Type>::isItemEqual(Type element, int index) {
	return (list[index] == element);
}

template<typename Type>
void ArrayBasedList<Type>::clear() {
	length = 0;
}

template<typename Type>
void ArrayBasedList<Type>::print() {
	cout << "[ ";
	for (int i = 0; i < length - 1; i++) {
		cout << list[i] << ", ";
	}
	cout << list[length - 1] << " ]\n";
}

template<typename Type>
int ArrayBasedList<Type>::maxListSize() {
	return maxSize;
}