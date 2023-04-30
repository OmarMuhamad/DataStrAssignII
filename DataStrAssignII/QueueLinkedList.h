// Queue Linked List Header With Functions
// Author Omar Mohammad
#include <iostream>
#include <string>
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
    void sortQueue(Queue<Type> qu);
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
Type Queue<Type>::dequeuee() {
    if (count == 0) {
        cout << "Cannot delete from an empty queue!" << endl;
        return 0;
    }
    else {
        NodeType<Type>* newNode;
        newNode = first;
        if (count == 1) {
            Type data = newNode->info;
            first = NULL;
            last = NULL;
            delete newNode;
            count = 0;
            return data;
        }
        else {
            Type data = newNode->info;
            first = first->link;
            delete newNode;
            count--;
            return data;
        }
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
Type Queue<Type>::First() {
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

void generateBinaryNum1(int limit) {
    Queue<string> qu;
    qu.enqueue("1");
    for (int i = 1; i <= limit; i++) {
        string binRep = qu.dequeuee();
        cout << binRep << " ";
        qu.enqueue((binRep + "0"));
        qu.enqueue((binRep + "1"));
    }
}
void genrateBinaryNum2(int limit) {
    Queue<string> qu;
    int remainder;
    int product = 1;
    int binary = 0;
    for (int i = 1; i <= limit; i++) {
        while (i != 0) {
            remainder = i % 2;
            binary = binary + (remainder * product);
            i = i / 2;
            product *= 10;
        }
        qu.enqueue(to_string(binary));
    }
}
template<typename Type>
void Queue<Type>::sortQueue(Queue<Type> qu) {
    // Implementation of queue sorting algorithm
}
template<typename Type>
class StackBasedQueue {
private:
    Queue<Type> stackOne, stackTwo;
public:
    /* 
    the idea is that you will create a queue and each enqueue operation you will add the element to the first, 
    if a dequeue operation will add a to a new queue but with a reversed order 
    (it's like you are rebuilding a tower but from top so the bottom will be top and top will be bottom which we want
    */
    void push(Type element){
        stackOne.enqueue(element);
    }
    void dequeue() {
        if (stackTwo.isEmpty()) {
            while (!stackOne.isEmpty()) {
                stackTwo.enqueue(stackOne.dequeuee());
                stackOne.pop();
            }
        }
        stackTwo.dequeuee();
    }
};