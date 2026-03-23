#include "QueueFactory.hpp"

#include <iostream>
#include <random>
#include <limits>

#include <string>

using namespace std;

int main() {
    // Setup Random Number Generation
    random_device rd;
    mt19937 gen(rd());
	// for first simulation, we want to use Queue array since we already know the line is limited (10 max)
    cout << "----------------First example simulation---------------------\n";
	Queue<double>* ticketLine = QueueFactory<double>::GetQueue(10);
    uniform_int_distribution<> dist1(-1, 1); // Range [-1, 1]
    double turnedAway = 0;
    double served = 0;

    for (int i = 0; i < 100; ++i) {
        int action = dist1(gen);
        if (action < 0) {
            if (!ticketLine->isEmpty()) {
                ticketLine->dequeue();
                served++;
            }
        }
        else {
            if (!ticketLine->isFull()) {
                ticketLine->enqueue(1);
            }
            else {
                turnedAway++;
            }
        }
    }
    cout << "Results: Served: " << served << ", Turned Away: " << turnedAway << "\n\n";
    delete ticketLine; // Clean up memory

    // for the second simulation, we want to use Queue LinkedList since there is no fixed maximum size for the waiting line.
    cout << "----------------Second example simulation---------------------\n";
    Queue <double>* bankLine = QueueFactory<double>::GetQueue();
    uniform_int_distribution<> dist2(-1, 2); // Range [-1, 2]
    double bankServed = 0;

    for (int i = 0; i < 100; ++i) {
        int action = dist2(gen);
        if (action < 0) {
            if (!bankLine->isEmpty()) {
                bankLine->dequeue();
                bankServed++;
            }
        }
        else {
            bankLine->enqueue(1);
        }
    }
    cout << "Results: Served: " << bankServed << ", Currently in line: " << bankLine->getLength() << "\n";
    delete bankLine;
	
	return 0;
}