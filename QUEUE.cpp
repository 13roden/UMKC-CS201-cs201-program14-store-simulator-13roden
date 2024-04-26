#include "Queue.h"

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    totalItemsProcessedVar = 0;
    maxQueueLengthVar = 0;
    totalIdleTimeVar = 0;
    totalOverTimeVar = 0;
}

void Queue::enQueue(Customer data) {
    QueueNode* newNode = new QueueNode;
    newNode->data = data;
    newNode->next = nullptr;
    if (front == nullptr) {
        front = newNode;
    } else {
        rear->next = newNode;
    }
    rear = newNode;
}

Customer Queue::deQueue() {
    if (front == nullptr) {
        // Handle empty queue
    }
    QueueNode* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    Customer data = temp->data;
    delete temp;
    return data;
}

Customer Queue::peek() {
    if (front != nullptr) {
        return front->data;
    }
    // Handle empty queue
}

bool Queue::queueEmpty() {
    return front == nullptr;
}

void Queue::printQueue() {
    QueueNode* current = front;
    while (current != nullptr) {
        // Print current->data
        current = current->next;
    }
}

int Queue::totalCustomersProcessed() {
    int count = 0;
    QueueNode* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

int Queue::totalItemsProcessed() {
    return totalItemsProcessedVar;
}

int Queue::maxQueueLength() {
    return maxQueueLengthVar;
}

int Queue::totalIdleTime() {
    return totalIdleTimeVar;
}

int Queue::totalOverTime() {
    return totalOverTimeVar;
}
