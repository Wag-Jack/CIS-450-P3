/*
* File: unisexBathroomA.cpp
* ----------------------------------------------------
* This program implements a monitor for the unisex bathroom
* problem using mutexes and condition variables.
*/
#include<chrono>
#include<condition_variable>
#include<iostream>
#include<mutex>
#include<thread>
#include<vector>
#include<random>
using namespace std;

random_device rd; //Seed source for random number engine
mt19937 gen(rd()); //mersenne_twister_engine seeded with rd()

mutex mtx; //monitor lock

int bMen = 0; //men in bathroom
int bWomen = 0; //women in bathroom

condition_variable manAllowed;
condition_variable womanAllowed;

vector<thread> person; //thread of people

void manEnter(int id) {
    unique_lock<mutex> lck(mtx);
    while (bWomen > 0 || bMen == 3) {
        //wait for men to leave
        manAllowed.wait(lck);
    }
    bMen++; //one man enters
}

void manExit(int id) {
    bMen--; //one man leaves

    if (bMen == 2) {
        manAllowed.notify_one(); //signify next thread
    } else if (bMen == 0) {
        womanAllowed.notify_all(); //no men in bathroom, women able to come in
    }
}

void womanEnter(int id) {
    unique_lock<mutex> lck(mtx);
    
    while (bMen > 0 || bWomen == 3) {
        womanAllowed.wait(lck);
    }
    bWomen++; //one woman enters
}

void womanExit(int id) {
    bWomen--;
    if (bWomen == 2) {
        womanAllowed.notify_one(); //signify next thread
    } else if (bWomen == 0) {
        manAllowed.notify_all(); //no women in bathroom, men able to come in
    }
}

void child(int id, int gender) {
    switch (gender) {
        case 1:
            manEnter(id);
            manExit(id);
            break;
        case 2:
            womanEnter(id);
            womanExit(id);
            break;
        default:
            break;
    }
}

int main(int argc, const char *argv[]) {
    uniform_int_distribution<int> distribution(1,2);

    int childGender;

    //Create child threads
    for (int i = 0; i <= 50; i++) {
        childGender = distribution(gen);
        person.push_back(thread(child, i, childGender));
    }

    for (thread &c : person) {
        c.join();
    } 

    return 0;
}