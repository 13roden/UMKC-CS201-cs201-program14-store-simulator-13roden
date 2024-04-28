#ifndef UMKC_CS201_CS201_PROGRAM14_STORE_SIMULATOR_13RODEN_LINKEDLIST_H
#define UMKC_CS201_CS201_PROGRAM14_STORE_SIMULATOR_13RODEN_LINKEDLIST_H

struct listType {
    int cartId;
    int itemCount;
    int enterQTime;
};

struct Node {
    listType data;
    Node* nextPtr;
};

class LinkedList {
private:
    Node* headPtr;
public:
    LinkedList();
    void addElement(listType data);
    listType peek();
    void delElement();
    bool listIsEmpty();
    static int listCount;
};


#endif //UMKC_CS201_CS201_PROGRAM14_STORE_SIMULATOR_13RODEN_LINKEDLIST_H
