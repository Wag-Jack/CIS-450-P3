/*
    to keep track:
    deposits always done immediately
    withdrawals must be processed in  fcfs 
    multiple threads can access the account safely 
*/
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <queue>
#include <random>
using namespace std;

random_device rd; //Seed source for random number engine
mt19937 gen(rd()); //mersenne_twister_engine seeded with rd()

int balance = 0; //bank account balance
int waitWithdraw = 0; //amount of customers waiting to withdraw
mutex mtx; //mutex for balance
condition_variable canWithdraw; //for withdrawa waiting
condition_variable bankAvailable; //for checking if the bank is available

queue<pair<int, condition_variable*>> withdrawQueue; //queue for fsfc withdrawals

// deposit implementation
void deposit(int id, int amount) {
    balance += amount;// add amount to balance
    canWithdraw.notify_one();// notify waiting withdrawals
    printf("Customer %d deposits %d. Balance: %d\n", id, amount, balance);
}

// fcfs withdraw function
void withdraw(int id, int amount) {
    unique_lock<mutex> lock(mtx);

    waitWithdraw++; //increment amount of people waiting to withdraw

    printf("Customer %d wants to withdraw %d. Balance: %d\n", id, amount, balance);

    //check if it's this thread's turn
    if (waitWithdraw > 1) {
        bankAvailable.wait(lock, [&] {return (waitWithdraw == 0);});
    }

    while (balance < amount) {
        canWithdraw.wait(lock, [&amount] {return (balance >= amount);});
    }

    /*
    //add withdraw request to queue
    withdrawQueue.push({amount, &myCV});

    // wiat til withdrawal is at the front of the queue and thees enough funds
    cv.wait(lock, [&] {
        return (withdrawQueue.front().second == &myCV) && (balance >= amount);
    });
    */

    //process withdrawla 
    balance -= amount;
    //withdrawQueue.pop(); // Remove processed withdrawal request
    printf("Customer %d withdraws %d. Balance %d\n", id, amount, balance);

    waitWithdraw--;
    bankAvailable.notify_one();
}

// customer function
void customer(int id) {
    uniform_int_distribution<int> actionDistribution(0,1);
    uniform_int_distribution<int> amountDistribution(1,100);
    
    int action = actionDistribution(gen);//0 is withdraw and 1 is deposit
    int amount = amountDistribution(gen); //random number generator between 1-100

    if (action == 0) { // Withdraw
        withdraw(id, amount);
    } else { // Deposit
        deposit(id, amount);
    }
}

// Main function
int main() {
    //create thread of customers
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