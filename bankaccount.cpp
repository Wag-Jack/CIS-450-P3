/*
to keep track:
deposits always succeed immediately
withdrawals must wait if the balance is too low
multiple threads can access the account safely using mutex and condition variable

*/
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <random>
using namespace std;

random_device rd; //Seed source for random number engine
mt19937 gen(rd()); //mersenne_twister_engine seeded with rd()

int balance = 0;// for bank accout balance
mutex mtx; // mutex for balance to prevent race conditions
condition_variable canWithdraw;// for waiting withdrawals when balance is low

// deposit implementation
void deposit(int id, int amount) {
    balance += amount; //add amount to balance
    printf("Customer %d deposits %d. Balance: %d\n", id, amount, balance);
    canWithdraw.notify_one(); //notify waiting withdrawals
    
}

// withdraw function
void withdraw(int id, int amount) {
    unique_lock<mutex> lock(mtx);

    printf("Customer %d wants to withdraw %d. Balance: %d\n", id, amount, balance);

    // wait til enough balance is enough before withdrawing
    while (balance < amount) {
        canWithdraw.wait(lock, [&amount] {return (balance >= amount);});
    }

    //process withdrawla
    balance -= amount; 
    printf("Customer %d withdraws %d. Balance: %d\n", id, amount, balance);
}

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

int main() {
    //create thread of customers
    thread customers[10];

    for (int i = 0; i < 10; i++) { //start and iterate through 10 customer threads customers 
        customers[i] = thread(customer, i);
    }

    for (auto &c : customers) {// for each thread objct in the array
        c.join();// wait for this thread to finish
    }

    return 0;
}
