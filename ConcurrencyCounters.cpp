/*
 * ConcurrencyCounters.cpp
 *
 *  Created on: Oct 9, 2026
 *      Author: arifakhri
 */


#include <iostream>
#include <thread>

// Thread 1 counts upward from 0 to 20
void countUp() {
    for (int number = 0; number <= 20; ++number) {
        std::cout << "Thread 1 counting up: "
                  << number << '\n';
    }
}

// Thread 2 counts downward from 20 to 0
void countDown() {
    for (int number = 20; number >= 0; --number) {
        std::cout << "Thread 2 counting down: "
                  << number << '\n';
    }
}

int main() {
    // Create and start the first thread
    std::thread firstThread(countUp);

    // Wait for the first thread to finish
    firstThread.join();

    // Create and start the second thread
    std::thread secondThread(countDown);

    // Wait for the second thread to finish
    secondThread.join();

    std::cout << "Both threads have finished."
              << std::endl;

    return 0;
}



