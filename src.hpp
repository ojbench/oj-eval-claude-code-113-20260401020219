#ifndef SRC_HPP
#define SRC_HPP

#include <iostream>
using namespace std;

// Node structure for LinkedList
template<typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(const T& val) : data(val), next(nullptr), prev(nullptr) {}
};

// LinkedList template class
template<typename T>
class LinkedList {
protected:
    Node<T>* head;
    Node<T>* tail;
    int count;

public:
    // Default constructor
    LinkedList() : head(nullptr), tail(nullptr), count(0) {}

    // Destructor
    virtual ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Copy constructor
    LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr), count(0) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            pushBack(current->data);
            current = current->next;
        }
    }

    // Push element to front
    void pushFront(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    // Push element to back
    void pushBack(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    // Pop element from front
    T popFront() {
        if (head == nullptr) {
            return T();
        }
        T val = head->data;
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        count--;
        return val;
    }

    // Pop element from back
    T popBack() {
        if (tail == nullptr) {
            return T();
        }
        T val = tail->data;
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        count--;
        return val;
    }

    // Get size
    int size() const {
        return count;
    }

    // Print the list
    void print() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Virtual functions
    virtual const char* name() { return "LinkedList"; }
    virtual T peak() { return T(); }
    virtual T pop() { return T(); }
    virtual void push(T val) {}
};

// Stack class
template<typename T>
class Stack : public LinkedList<T> {
public:
    Stack() : LinkedList<T>() {}

    const char* name() override {
        return "Stack";
    }

    T peak() override {
        return this->tail->data;  // Stack top is at tail
    }

    T pop() override {
        return this->popBack();  // Pop from tail
    }

    void push(T val) override {
        this->pushBack(val);  // Push to tail
    }
};

// Queue class
template<typename T>
class Queue : public LinkedList<T> {
public:
    Queue() : LinkedList<T>() {}

    const char* name() override {
        return "Queue";
    }

    T peak() override {
        return this->head->data;  // Queue front is at head
    }

    T pop() override {
        return this->popFront();  // Pop from head
    }

    void push(T val) override {
        this->pushBack(val);  // Push to tail
    }
};

#endif
