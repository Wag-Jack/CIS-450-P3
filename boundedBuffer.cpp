/* boundedBuffer.c
 *
 * A complete example of simple producer/consumer program. The Producer
 * and Consumer functions are executed as independent threads.  They
 * share access to a single buffer.  The producer deposits a sequence
 * of integers from 1 to numIters into the buffer.  The Consumer fetches
 * these values and adds them.  Two semaphores,sem_empty and sem_full are used to
 * ensure that the producer and consumer alternate access to the buffer.
 *
 * This version uses thread coordination to ensure that the
 * consumer only reads valid data and the producer doesn't overwrite unread
 * data.
 */
#include <chrono>
#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>

using namespace std;

const int MAX = 100; // the maximum possible value of the internal counter for semaphores
const int NUM_PROD = 3;
const int NUM_CONS = 3;

int bufSize;
int* buffer; // shared buffer, size = bufSize
int numIters;

int front = 0;
int rear = 0;

// deposit 1, ..., numIters into the data buffer
void Producer(counting_semaphore<MAX> &sem_empty, counting_semaphore<MAX> &sem_full, counting_semaphore<MAX> &mutex) {
    
    for (int produced = 0; produced < numIters; produced++) {
        //wait for both empty sempaphore and mutex lock
        sem_empty.acquire();
        mutex.acquire();

        //modify buffer with production
        buffer[rear] = produced;
        rear = (rear + 1) % bufSize;

        //signal the mutex lock and full semaphore
        mutex.release();
        sem_full.release();
    }
}

// fetch numIters items from the buffer and sum them
void Consumer(counting_semaphore<MAX> &sem_empty, counting_semaphore<MAX> &sem_full, counting_semaphore<MAX> &mutex) {
    int total = 0;

    for (int consumed = 0; consumed < numIters; consumed++)
    {
        //wait for both full semaphore and mutex lock
        sem_full.acquire();
        mutex.acquire();
        
        //modify buffer
        total = total + buffer[front];
        front = (front + 1) % bufSize;
        
        //signal the mutex lock and empty semaphore
        mutex.acquire();
        sem_empty.release();
    }

    printf("the total is %d\n", total);
}

// main() -- read command line and create threads
// Input: ./boundedBuffer (numIters) (buffer))
int main(int argc, char *argv[])
{
    vector<thread> producer;
    vector<thread> consumer;

    if (argc < 3)
    {
        printf("Usage: boundedBuffer <Number of Iterations> <Buffer size>\n");
        exit(0);
    }

    //Retrieve command line values
    numIters = atoi(argv[1]);
    bufSize = atoi(argv[2]);

    //Create buffer using dynamically allocated memory
    buffer = new int[bufSize];

    counting_semaphore<MAX> sem_empty(bufSize);
    counting_semaphore<MAX> sem_full(0);
    counting_semaphore<MAX> mutex(1);

    //Create vector of NUM_PROD producer threads
    for (int i = 0; i < NUM_PROD; i++) {
        producer.push_back(thread(Producer, ref(sem_empty), ref(sem_full), ref(mutex)));
    }

    //Create vector of NUM_CONS consumer threads
    for (int i = 0; i < NUM_CONS; i++) {
        consumer.push_back(thread(Consumer, ref(sem_empty), ref(sem_full), ref(mutex)));
    }

    //Execute all producer threads
    for (int i = 0; i < producer.size(); i++) {
        producer[i].join();
    }

    //Execute all consumer threads
    for (int i = 0; i < consumer.size(); i++) {
        consumer[i].join();
    }

    //delete data from bugger
    delete[] buffer;

    return 0;
}
