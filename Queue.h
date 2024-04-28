#ifndef UMKC_CS201_CS201_PROGRAM14_STORE_SIMULATOR_13RODEN_QUEUE_H
#define UMKC_CS201_CS201_PROGRAM14_STORE_SIMULATOR_13RODEN_QUEUE_H

struct queueNodeData {
    int timeAvailable;
    int itemCount;
};

struct queueNode {
    queueNodeData data;
    queueNode* nextPtr;
};

class Queue {
private:
    queueNode* front;
    queueNode* rear;
public:
    Queue();
    void enQueue(queueNodeData data);
    queueNodeData deQueue();
    queueNodeData peek();
    bool queueEmpty();
    int queueLength();

};

#endif //UMKC_CS201_CS201_PROGRAM14_STORE_SIMULATOR_13RODEN_QUEUE_H
