#include "Checkout.h"
#include <iostream>

CheckoutStats::CheckoutStats() {
    totalCustomersHelped = 0;
    totalItemsProcessed = 0;
    maxQueueLength = 0;
    totalIdleTime = 0;
    totalOverTime = 0;
    cartsServed = std::vector<int>();
}

void CheckoutStats::updateStats(int itemCount, int currentTime, bool queueEmpty, int queueLength) {
    if (!queueEmpty) {
        totalOverTime += (currentTime > 720) ? (currentTime - 720) : 0;
        totalItemsProcessed += itemCount;
        totalCustomersHelped++;
        cartsServed.push_back(itemCount);

        if (queueLength > maxQueueLength) {
            maxQueueLength = queueLength;
        }
    } else {
        totalIdleTime++;
    }
}

void CheckoutStats::printStats(int checkoutLine) {
    cout << "Checkout Line " << checkoutLine + 1 << " Statistics:" << std::endl;
    cout << "Total Customers Helped: " << totalCustomersHelped << std::endl;
    cout << "Total Items Processed: " << totalItemsProcessed << std::endl;
    cout << "Maximum Line Length: " << maxQueueLength << std::endl;
    cout << "Total Minutes of Idle Time: " << totalIdleTime << std::endl;
    cout << "Total Minutes of Overtime: " << totalOverTime << std::endl;
    cout << endl;
}
