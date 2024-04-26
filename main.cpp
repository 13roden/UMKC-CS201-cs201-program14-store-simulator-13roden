// BRODEN NESTLER
// PROGRAM 14 - Store Simulator
// bcntck@umkc.edu

#include <iostream>
#include <cstdlib> // For rand() function
#include <ctime>   // For time() function
#include "LINKEDLIST.h"
#include "QUEUE.h"
#include "CUSTOMER.h"

using namespace std;

int main() {
    srand(time(0));

    const int storeOpenTime = 720;
    int numCheckouts;

    cout << "Enter the number of checkout lines: ";
    cin >> numCheckouts;

    // Create an array of checkout queues
    Queue* checkouts = new Queue[numCheckouts];

    LinkedList shoppers; // Linked list to store shoppers in the store

    // Simulate customer arrivals and shopping
    for (int currentTime = 0; currentTime <= storeOpenTime; ++currentTime) {
        // Randomly decide how many customers arrived
        int numArrivals = rand() % 3 + 1; // 1 to 3 customers

        for (int i = 0; i < numArrivals; ++i) {
            Customer customer;
            customer.items = rand() % 60 + 1; // 1 to 60 items
            customer.shoppingTime = customer.items * (30 + rand() % 31); // 30 to 60 seconds per item
            customer.enterQueueTime = currentTime + customer.shoppingTime;

            // Add customer to the shoppers list
            shoppers.addElement(customer);
        }

        // Update checkout lines
        for (int i = 0; i < numCheckouts; ++i) {
            if (!shoppers.listIsEmpty()) {
                Customer customer = shoppers.peek();
                if (customer.enterQueueTime <= currentTime) {
                    checkouts[i].enQueue(customer);
                    shoppers.delElement();
                }
            }
        }
    }

    // Process remaining customers in the store
    while (!shoppers.listIsEmpty()) {
        for (int i = 0; i < numCheckouts; ++i) {
            if (!shoppers.listIsEmpty()) {
                Customer customer = shoppers.peek();
                if (customer.enterQueueTime <= storeOpenTime) {
                    checkouts[i].enQueue(customer);
                    shoppers.delElement();
                }
            }
        }
    }

    // Print checkout statistics
    for (int i = 0; i < numCheckouts; ++i) {
        cout << "Checkout Line " << i+1 << " Statistics:" << endl;
        cout << "Total Customers Helped: " << checkouts[i].totalCustomersProcessed() << endl;
        cout << "Total Number of Items: " << checkouts[i].totalItemsProcessed() << endl;
        cout << "Maximum Line Length: " << checkouts[i].maxQueueLength() << endl;
        cout << "Total Minutes of Idle Time: " << checkouts[i].totalIdleTime() << endl;
        cout << "Total Minutes of Overtime: " << checkouts[i].totalOverTime() << endl;
        cout << endl;
    }

    // Clean up
    delete[] checkouts;

    return 0;
}