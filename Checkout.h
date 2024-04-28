
#ifndef UMKC_CS201_CS201_PROGRAM14_STORE_SIMULATOR_13RODEN_CHECKOUT_H
#define UMKC_CS201_CS201_PROGRAM14_STORE_SIMULATOR_13RODEN_CHECKOUT_H

#include <vector>
using namespace std;

struct CheckoutStats {
    int totalCustomersHelped;
    int totalItemsProcessed;
    int maxQueueLength;
    int totalIdleTime;
    int totalOverTime;
    vector<int> cartsServed;

    CheckoutStats();
    void updateStats(int itemCount, int currentTime, bool queueEmpty, int queueLength);
    void printStats(int checkoutLine);
};

#endif //UMKC_CS201_CS201_PROGRAM14_STORE_SIMULATOR_13RODEN_CHECKOUT_H
