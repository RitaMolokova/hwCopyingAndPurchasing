#pragma once

class Node {
public:
    int value;
    Node* next;
    Node() : value(0), next(nullptr) {}
    Node(int value) : value(value), next(nullptr) {}
};

class ForwardList {
private:
    Node* head;
    Node* tail;
public:
    ForwardList() : head(nullptr), tail(nullptr) {}
    ForwardList(const ForwardList& other);
    ForwardList& operator=(const ForwardList& other);
    ~ForwardList() {
        clear();
    }
    void push_back(int value);
    void push_front(int value);
    void insert_after(Node* prev, int value);
    void print();
    void clear();
};

