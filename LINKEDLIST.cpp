#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::addElement(Customer data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

Customer LinkedList::peek() {
    if (head != nullptr) {
        return head->data;
    }
    // Handle empty list
}

void LinkedList::delElement() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    // Handle empty list
}

void LinkedList::printList() {
    Node* current = head;
    while (current != nullptr) {
        // Print current->data
        current = current->next;
    }
}

bool LinkedList::listIsEmpty() {
    return head == nullptr;
}
