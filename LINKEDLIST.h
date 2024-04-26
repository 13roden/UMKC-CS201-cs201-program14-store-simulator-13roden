#pragma once

#include "CUSTOMER.h"

struct Node {
    Customer data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList();
    void addElement(Customer data);
    Customer peek();
    void delElement();
    void printList();
    bool listIsEmpty();
};

