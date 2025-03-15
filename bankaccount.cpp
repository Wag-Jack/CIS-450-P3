/*
to keep track:
deposits always succeed immediately
withdrawals must wait if the balance is too low
multiple threads can access the account safely using mutex and condition variable

*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cstdlib>

using namespace std;

int balance = 0;// for bank accout balance
mutex mtx; // mutex for balance to prevent race conditions
condition_variable cv;// for waiting withdrawals when balance is low
mutex cout_mutex;

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

// withdraw function
void withdraw(int amount) {
    unique_lock<mutex> lock(mtx);

    // wait til enoigh balance is enoigh before withdrawing
    while (balance < amount) {
        cv.wait(lock);
    }

    balance -= amount; 
    lock.unlock(); //unlock before printing

    { 
        lock_guard<mutex> print_lock(cout_mutex);
        cout << "Withdrew " << amount << ". Balance: " << balance << endl;
    }
}

// Customer function
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

int main() {
    srand(time(0));// seed random numebr generator

    thread customers[10];

    for (int i = 0; i < 10; i++) { //start and iterate through 10 customer threads customers 
        customers[i] = thread(customer, i);
    }

    for (auto &c : customers) {// for each thread objct in the array
        c.join();// wait for this thread to finish
    }

    return 0;
}
