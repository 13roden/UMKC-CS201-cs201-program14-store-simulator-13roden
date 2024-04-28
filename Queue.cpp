#include "Queue.h"

#include <iostream>

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

void Queue::enQueue(queueNodeData data) {
    queueNode* newNode = new queueNode;
    newNode->data = data;
    newNode->nextPtr = nullptr;

    if (front == nullptr) {
        front = newNode;
    } else {
        rear->nextPtr = newNode;
    }
    rear = newNode;
}

queueNodeData Queue::deQueue() {
    if (front == nullptr) {
        throw "Queue is empty";
    }

    queueNode* temp = front;
    queueNodeData tempData = temp->data;
    front = front->nextPtr;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;

    return tempData;
}

queueNodeData Queue::peek() {
    if (front == nullptr) {
        throw "Queue is empty";
    }
    return front->data;
}

bool Queue::queueEmpty() {
    return front == nullptr;
}


int Queue::queueLength() {
    int length = 0;
    queueNode* current = front;
    while (current != nullptr) {
        length++;
        current = current->nextPtr;
    }
    return length;
}
