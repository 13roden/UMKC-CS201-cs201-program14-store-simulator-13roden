#include "CUSTOMER.h"
#pragma once

struct QueueNode {
    Customer data;
    QueueNode* next;
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;
    int totalItemsProcessedVar; // Keep track of total items processed
    int maxQueueLengthVar; // Keep track of maximum queue length
    int totalIdleTimeVar; // Keep track of total idle time
    int totalOverTimeVar; // Keep track of total overtime
public:
    Queue();
    void enQueue(Customer data);
    Customer deQueue();
    Customer peek();
    bool queueEmpty();
    void printQueue();

    int totalCustomersProcessed(); // Return the total number of customers processed
    int totalItemsProcessed(); // Return the total number of items processed
    int maxQueueLength(); // Return the maximum queue length
    int totalIdleTime(); // Return the total idle time
    int totalOverTime(); // Return the total overtime
};

