
#include "LinkedList.h"

#include <iostream>

int LinkedList::listCount = 0;

LinkedList::LinkedList() {
    headPtr = nullptr;
}

void LinkedList::addElement(listType data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->nextPtr = nullptr;

    if (headPtr == nullptr || headPtr->data.enterQTime >= data.enterQTime) {
        newNode->nextPtr = headPtr;
        headPtr = newNode;
    } else {
        Node* current = headPtr;
        while (current->nextPtr != nullptr && current->nextPtr->data.enterQTime < data.enterQTime) {
            current = current->nextPtr;
        }
        newNode->nextPtr = current->nextPtr;
        current->nextPtr = newNode;
    }

    listCount++;
}

listType LinkedList::peek() {
    if (headPtr == nullptr) {
        throw "List is empty";
    }
    return headPtr->data;
}

void LinkedList::delElement() {
    if (headPtr == nullptr) {
        throw "List is empty";
    }

    Node* temp = headPtr;
    headPtr = headPtr->nextPtr;
    delete temp;

    listCount--;
}

bool LinkedList::listIsEmpty() {
    return headPtr == nullptr;
}
