
#include <iostream>
#include <thread>
#include <vector>
#include <semaphore>
#include <mutex>
#include <atomic>
#include <memory>  // Required for unique_ptr

using namespace std;

#define MAX_EATS 5  // Each philosopher eats 5 times before stopping

//  this class Implements the classic Dining Philosophers problem using threads, semaphores, and mutexes
class DiningPhilosophers {
private:
    int numPhilosophers;
    vector<unique_ptr<binary_semaphore>> chopsticks;  // Use unique_ptr for binary_semaphore
    mutex coutMutex;  // Mutex to synchronize console output
    mutex pickUpMutex;  // Mutex to ensure fair chopstick picking

public:
    //this Constructor to initialize semaphores for chopsticks
    DiningPhilosophers(int n) : numPhilosophers(n) {
        for (int i = 0; i < n; i++) {
            chopsticks.push_back(make_unique<binary_semaphore>(1));
            // Each chopstick starts as available (1)
        }
    }
   //Each philosopher will think, eat, and repeat this process MAX_EATS times
   // id = unique id for the philosopher
    void philosopher(int id) {
        for (int i = 0; i < MAX_EATS; i++) { // Limits the eating cycles
            think(id);
            eat(id);
        }

        lock_guard<mutex> lock(coutMutex);
        cout << "Philosopher " << id << " has finished eating " << MAX_EATS << " times and is leaving.\n";
    }

    // this function simulates the thinking phase of a philosopher
    void think(int id) {
        {
            lock_guard<mutex> lock(coutMutex);
            cout << "Philosopher " << id << " is thinking...\n";
        }
        this_thread::sleep_for(chrono::milliseconds(1000));  // Simulate thinking
    }

    //this function will simulate the eating phase, handling chopstick acquisition and release.
    void eat(int id) {
        int left = id;
        int right = (id + 1) % numPhilosophers;

        {
            lock_guard<mutex> lock(coutMutex);
            cout << "Philosopher " << id << " is hungry...\n";
        }

        // Prevent circular wait using odd-even ordering strategy
        pickUpMutex.lock();
        if (id % 2 == 0) {
            chopsticks[right]->acquire(); // Even philosophers pick right first
            chopsticks[left]->acquire();
        } else {
            chopsticks[left]->acquire(); // Odd philosophers pick left first
            chopsticks[right]->acquire();
        }
        pickUpMutex.unlock();

        {
            lock_guard<mutex> lock(coutMutex);
            cout << "Philosopher " << id << " is eating...\n";
        }

        this_thread::sleep_for(chrono::milliseconds(2000)); // Simulate eating

        // Release both chopsticks after eating
        chopsticks[left]->release();
        chopsticks[right]->release();

        {
            lock_guard<mutex> lock(coutMutex);
            cout << "Philosopher " << id << " put down chopsticks " << left << " & " << right << ".\n";
        }
    }
};

int main() {
    int numPhilosophers;
    cout << "Enter number of philosophers: ";
    cin >> numPhilosophers;     // take input from user

    DiningPhilosophers dp(numPhilosophers);
    vector<thread> philosophers;

    for (int i = 0; i < numPhilosophers; i++) {
        philosophers.emplace_back(&DiningPhilosophers::philosopher, &dp, i);
    }

    // Join all philosopher threads to ensure completion
    for (auto &t : philosophers) {
        t.join();
    }

    cout << "All philosophers have finished eating. Simulation complete.\n";
    return 0;
}
