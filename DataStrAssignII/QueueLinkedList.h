#include <iostream>
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

void generateBinaryNum(int limit) {
    Queue<string> qu;
    qu.enqueue("1");
    for (int i = 1; i <= limit; i++) {
        string binRep = qu.dequeuee();
        cout << binRep << " ";
        qu.enqueue((binRep + "0"));
        qu.enqueue((binRep + "1"));
    }
}

template<typename Type>
void Queue<Type>::sortQueue(Queue<Type> qu) {
    // Implementation of queue sorting algorithm
}
