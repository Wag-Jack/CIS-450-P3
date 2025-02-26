/*
 * boundedBuffer.c
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

using namespace std;

const int MAX = 100; // the maximum possible value of the internal counter for semaphores
const int NUM_PROD = 3;
const int NUM_CONS = 3;

int buffer; // shared buffer, size = 1 /*Change buffer size to n*/
int numIters;

/*
TODO:
1. Allow multiple producers/consumers
2. Change bugger size from 1 to n, n being a command line parameter
3. Main thread creates 3 producers and 3 consumers
*/

// deposit 1, ..., numIters into the data buffer
void Producer(counting_semaphore<MAX> &sem_empty, counting_semaphore<MAX> &sem_full)
{
    for (int produced = 0; produced < numIters; produced++)
    {
        sem_empty.acquire();
        buffer = produced;
        sem_full.release();
    }
}

// fetch numIters items from the buffer and sum them
void Consumer(counting_semaphore<MAX> &sem_empty, counting_semaphore<MAX> &sem_full)
{
    int total = 0;

    for (int consumed = 0; consumed < numIters; consumed++)
    {
        sem_full.acquire();
        total = total + buffer;
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
    numIters = atoi(argv[1]);
    buffer = atoi(argv[2]);

    counting_semaphore<MAX> sem_empty(1);
    counting_semaphore<MAX> sem_full(0);

    //Create vector of NUM_PROD producer threads
    for (int i = 0; i < NUM_PROD; i++) {
        producer.push_back(thread(Producer, ref(sem_empty), ref(sem_full)));
    }

    //Create vector of NUM_CONS consumer threads
    for (int i = 0; i < NUM_CONS; i++) {
        consumer.push_back(thread(Consumer, ref(sem_empty), ref(sem_full)));
    }

    //Execute all producer threads
    for (int i = 0; i < producer.size(); i++) {
        producer[i].join();
    }

    //Execute all consumer threads
    for (int i = 0; i < consumer.size(); i++) {
        consumer[i].join();
    }

    exit(0);
}
