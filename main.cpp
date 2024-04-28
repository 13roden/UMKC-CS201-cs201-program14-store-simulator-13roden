// BRODEN NESTLER
// PROGRAM 14 - Store Simulator
// bcntck@umkc.edu
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LinkedList.h"
#include "Queue.h"
#include "Checkout.h"

using namespace std;

// Constants for simulation
const int storeOpenMinutes = 720;
const int itemsPerMinuteMin = 1;
const int itemsPerMinuteMax = 3;
const double itemShoppingTimeMin = 0.5; // 30 seconds
const double itemShoppingTimeMax = 1.0; // 1 minute
const double itemCheckoutTimePerItem = 0.15; // 0.15 minutes per item

// Helper function to generate random number within a range
int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Simulate the grocery store       **USED CHATPGT to help format and fix simulation**
void simulateStore(int numCheckoutLines) {
    LinkedList shopperList;
    Queue checkoutLines[numCheckoutLines];
    CheckoutStats stats[numCheckoutLines];

    // Initialize random number generator
    srand((time(nullptr)));

    // Simulation loop
    for (int currentTime = 0; currentTime <= storeOpenMinutes; currentTime++) {
        // Randomly determine number of customers arriving
        int numCustomers = getRandom(itemsPerMinuteMin, itemsPerMinuteMax);
        for (int i = 0; i < numCustomers; i++) {
            // Generate random shopping time for each item
            int itemCount;
            double shoppingTime = 0.0;
            int randItem = rand() % 100 + 1; // Random percentage
            if (randItem <= 40) {
                itemCount = getRandom(1, 10); // 40% purchase <10
            } else if (randItem <= 70) {
                itemCount = getRandom(11, 20);// 30% purchase 11-20     // ***items for an individual***
            } else if (randItem <= 90) {
                itemCount = getRandom(21, 30);// 20% purhcase 21-30
            } else {
                itemCount = getRandom(31, 60);// 10% purhcase 31-60
            }
            shoppingTime = itemCount * getRandom(itemShoppingTimeMin * 10, itemShoppingTimeMax * 10) / 10.0;

            // Add customer to shopper list
            listType customer;
            customer.cartId = currentTime + shoppingTime; // Set enterQTime
            customer.itemCount = itemCount;
            customer.enterQTime = currentTime;
            shopperList.addElement(customer);
        }

        // Update checkout lines
        for (int j = 0; j < numCheckoutLines; j++) {
            int queueLength = checkoutLines[j].queueLength();
            if (!checkoutLines[j].queueEmpty()) {
                queueNodeData frontCustomer = checkoutLines[j].peek();
                if (frontCustomer.timeAvailable <= currentTime) {
                    checkoutLines[j].deQueue(); // Customer has finished checkout
                    stats[j].updateStats(frontCustomer.itemCount, currentTime, checkoutLines[j].queueEmpty(), queueLength);
                }
            }

            if (!shopperList.listIsEmpty()) {
                listType frontShopper = shopperList.peek();
                if (frontShopper.enterQTime <= currentTime) {
                    // Add shopper to shortest queue
                    int shortestLineIndex = 0;
                    int shortestLineLength = checkoutLines[0].queueEmpty() ? 0 : checkoutLines[0].peek().itemCount;
                    for (int k = 1; k < numCheckoutLines; k++) {
                        int currentLineLength = checkoutLines[k].queueEmpty() ? 0 : checkoutLines[k].peek().itemCount;
                        if (currentLineLength < shortestLineLength) {
                            shortestLineIndex = k;
                            shortestLineLength = currentLineLength;
                        }
                    }
                    queueNodeData shopper;
                    shopper.timeAvailable = currentTime + frontShopper.itemCount * itemCheckoutTimePerItem;
                    shopper.itemCount = frontShopper.itemCount;
                    checkoutLines[shortestLineIndex].enQueue(shopper);
                    shopperList.delElement();
                }
            }
        }
    }

    // Print checkout statistics
    for (int i = 0; i < numCheckoutLines; i++) {
        stats[i].printStats(i);
    }
}

int main() {
    int numCheckoutLines;
    cout << "Enter the number of checkout lines (1-10): ";
    cin >> numCheckoutLines;
    if (numCheckoutLines < 1 || numCheckoutLines > 10) {
        cout << "Invalid number of checkout lines. Please enter a number between 1 and 10." << endl;
        return 1;
    }

    simulateStore(numCheckoutLines);

    return 0;
}
