/*
    to keep track:
    deposits always done immediately
    withdrawals must be processed in  fcfs 
    multiple threads can access the account safely 
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <cstdlib>

using namespace std;

int balance = 0; //bank account balance
mutex mtx; //mutex for balance
mutex cout_mutex; //mutex for printing 
condition_variable cv; //for withdrawa waiting

queue<pair<int, condition_variable*>> withdrawQueue; //queue for fsfc withdrawals

// deposit implementation
void deposit(int amount) {
{
    unique_lock<mutex> lock(mtx);// lock mutex to ensure no other thread modifies balance while runnign
    balance += amount;// add
}
{
        lock_guard<mutex> print_lock(cout_mutex);
    cout << "Deposited " << amount << ". Balance: " << balance << endl;
}
    cv.notify_all();// notify waiting withdrawals
}

// fcfs withdraw function
void withdraw(int amount) {
    condition_variable myCV;
    unique_lock<mutex> lock(mtx);

    //add withdraw request to queue
    withdrawQueue.push({amount, &myCV});

    // wiat til withdrawal is at the front of the queue and thees enough funds
    cv.wait(lock, [&] {
        return (withdrawQueue.front().second == &myCV) && (balance >= amount);
    });

    //process withdrawla 
    balance -= amount;
    withdrawQueue.pop(); // Remove processed withdrawal request

    { 
        lock_guard<mutex> print_lock(cout_mutex);
        cout << "Withdrew " << amount << ". Balance: " << balance << endl;
    }

    // if there is withdrawal in queue, wake them up
    cv.notify_all();
}

// customer function
void customer(int id) {
    int action = rand() % 2;//0 is withdraw and 1 is deposit
    int amount = (rand() % 100) + 1; //random number generator between 1-100

    { //print bwfore withdrawing or depositing
        lock_guard<mutex> print_lock(cout_mutex);
        if (action == 0) {
            cout << "Customer " << id << " wants to withdraw " << amount << endl;
        } else {
            cout << "Customer " << id << " deposits " << amount << endl;
        }
    } 

    if (action == 0) { // Withdraw
        withdraw(amount);
    } else { // Deposit
        deposit(amount);
    }
}

// Main function
int main() {
    srand(time(0)); //seed random number generator

    thread customers[10];

//start and iterate through 10 customer threads customers     
    for (int i = 0; i < 10; i++) {
        customers[i] = thread(customer, i);
    }

     for (auto &c : customers) {// for each thread objct in the array
        c.join();// wait for this thread to finish
    }
    return 0;
}