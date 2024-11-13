#include "ForwardList.h"
#include <iostream>
using namespace std;

void ForwardList::push_back(int value) {
    Node* new_node = new Node(value);
    if (!head) {
        head = new_node;
    }
    if (tail) {
        tail->next = new_node;
    }
    tail = new_node;
}

void ForwardList::print() {
    Node* current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void ForwardList::push_front(int value) {
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;

    if (!tail) {
        tail = head;
    }
}

void ForwardList::insert_after(Node* prev, int value) {
    if (prev == nullptr) return;

    Node* new_node = new Node(value);
    new_node->next = prev->next;
    prev->next = new_node;

    if (prev == tail) {
        tail = new_node;
    }
}

void ForwardList::clear() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

ForwardList::ForwardList(const ForwardList& other) : head(nullptr), tail(nullptr) {
    Node* current = other.head;
    while (current) {
        this->push_back(current->value);
        current = current->next;
    }
}

ForwardList& ForwardList::operator=(const ForwardList& other) {
    if (this == &other) return *this;

    clear();

    Node* current = other.head;
    while (current) {
        this->push_back(current->value);
        current = current->next;
    }

    return *this;
}
