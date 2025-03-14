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

condition_variable manAllowed; //condition variable for men
condition_variable womanAllowed; //condition variable for women

vector<thread> person; //thread of people

void manEnter(int id) {
    unique_lock<mutex> lck(mtx);

    printf("Person %d (male) wants to enter the bathroom. #Men: %d. #Women: %d.\n", id, bMen, bWomen);

    if (bWomen > 0 || bMen == 3) {
        manAllowed.wait(lck, [&id] {return (bWomen == 0 && bMen < 3);});
    }

    bMen++; //one man enters
    printf("Person %d (male) enters the bathroom. #Men: %d. #Women: %d.\n", id, bMen, bWomen);
}

void manExit(int id) {
    bMen--; //one man leaves
    printf("Person %d (male) exits the bathroom. #Men: %d. #Women: %d.\n", id, bMen, bWomen);

    if (bMen == 2) {
        manAllowed.notify_one(); //signify next thread
    } else if (bMen == 0) {
        womanAllowed.notify_all(); //no men in bathroom, women able to come in
    }
}

void womanEnter(int id) {
    unique_lock<mutex> lck(mtx);

    printf("Person %d (female) wants to enter the bathroom. #Men: %d. #Women: %d.\n", id, bMen, bWomen);

    if (bMen > 0 || bWomen == 3) {
        womanAllowed.wait(lck, [&id] {return (bMen == 0 && bWomen < 3);});
    }

    bWomen++; //one woman enters
    printf("Person %d (female) enters the bathroom. #Men: %d. #Women: %d.\n", id, bMen, bWomen);
}

void womanExit(int id) {
    bWomen--; //one woman leaves
    printf("Person %d (female) exits the bathroom. #Men: %d. #Women: %d.\n", id, bMen, bWomen);

    if (bWomen == 2) {
        womanAllowed.notify_one(); //signify next thread
    } else if (bWomen == 0) {
        manAllowed.notify_all(); //no women in bathroom, men able to come in
    }
}

//simulate a random "bathroom usage" time between 100 and 2000 ms
void useBathroom() {
    uniform_int_distribution<int> distribution(100, 2000);
    chrono::milliseconds timeToWait = chrono::milliseconds(distribution(gen));

    this_thread::sleep_for(timeToWait);
}

//male thread
void oneMan(int id) {
    manEnter(id);
    useBathroom();
    manExit(id);
}

//female thread
void oneWoman(int id) {
    womanEnter(id);
    useBathroom();
    womanExit(id);
}

int main(int argc, const char *argv[]) {
    uniform_int_distribution<int> distribution(1,2);

    int childGender;

    //Create child threads
    for (int i = 0; i <= 50; i++) {
        childGender = distribution(gen); //determine a random gender
        if (childGender % 2 == 1) { //Create a person thread based on random gender
            person.push_back(thread(oneMan, i));
        } else {
            person.push_back(thread(oneWoman, i));
        }
    }

    for (thread &c : person) {
        c.join();
    }

    return 0;
}