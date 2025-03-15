# CIS 450 P3
**Developed by Eman Sedqi and Jack Wagner**\
**March 14th, 2025**

## (1) Bounded Buffer

### Compilation Instructions
This program was developed and compiled using a g++ compiler on Visual Studio Code. In order to compile this into an executable ***using C++20 standard***, open a terminal and run the following command:
```
g++ -std=c++20 -pthread boundedBuffer.cpp -o boundedBuffer
```
Once you have you rexecutable, run it in the terminal, ensuring you have the correct parameters set:
```
./boundedBuffer <number of iterations> <buffer size>
```
You should have a sample output similar to what is shown below.

### Sample Output
For running boundedBuffer.exe with 10 iterations and a buffer size of 5, one possible output we get is:
```
the total is 18
the total is 48
the total is 69
```

## (2a) Unisex Bathroom 
In this problem, we have a unisex bathroom which abides by the following two conditions:</br>
- Only three employees can be in the bathroom at the same time
- Only employees of the same gender can be in the bathroom at the same time

To implement this solution, we utilized fifty threads with randomized genders between male and female. The male threads would execute `oneMan` and the female threads would execute `oneWoman`, with each thread having their own respective enter and exit procedures for each gender. Both also have a method `useBathroom` which simulates the thread "using the bathroom" by holding it for some time between 100 and 2000 ms.

The `enter` procedures work by locking the thread if there is either a member of the opposite gender in the bathroom or the amount of people of the same gender in the bathroom reaches three. Once these conditions are no longer true, the thread is able to begin running and increments the amount of people in the bathroom. The `exit` procedures work by decrementing the amount of people in the bathroom and signifying if either one more member of the same gender can be in the bathroom or the bathroom is free for the other gender to enter, signaling the respective condition variable using `notify_one` and `notify_all` respectively.

### Compilation Instructions:
This program was developed and compiled using a g++ compiler on Visual Studio Code. In order to compile this into an executable, open a terminal and run the following command:
```
g++ unisexBathroom.cpp -o unisexBathroom
```
Once you have your executable, run it in the terminal:
```
./unisexBathroom
```
You should have a sample output similar to what is shown below.

### Sample Output:
```
Person 1 (female) wants to enter the bathroom. #Men: 0. #Women: 0.
Person 1 (female) enters the bathroom. #Men: 0. #Women: 1.
Person 24 (female) wants to enter the bathroom. #Men: 0. #Women: 1.
Person 24 (female) enters the bathroom. #Men: 0. #Women: 2.
Person 2 (female) wants to enter the bathroom. #Men: 0. #Women: 2.
Person 2 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 26 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 28 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 8 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 3 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 5 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 4 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 10 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 9 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 11 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 12 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 13 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 14 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 15 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 37 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 38 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 18 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 40 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 20 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 21 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 22 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 23 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 0 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 25 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 6 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 47 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 7 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 29 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 30 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 31 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 32 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 33 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 34 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 35 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 36 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 16 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 17 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 39 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 19 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 41 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 42 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 43 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 44 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 45 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 46 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 27 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 48 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 49 (female) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 50 (male) wants to enter the bathroom. #Men: 0. #Women: 3.
Person 24 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 26 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 1 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 28 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 2 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 3 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 3 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 5 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 26 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 10 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 28 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 10 (female) exits the bathroom. #Men: 0. #Women: 1.
Person 5 (female) exits the bathroom. #Men: 0. #Women: 0.
Person 38 (male) enters the bathroom. #Men: 1. #Women: 0.
Person 48 (male) enters the bathroom. #Men: 2. #Women: 0.
Person 37 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 48 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 14 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 37 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 19 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 19 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 42 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 38 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 39 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 14 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 16 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 16 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 36 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 42 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 34 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 39 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 7 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 34 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 25 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 25 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 23 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 36 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 45 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 45 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 18 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 18 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 4 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 23 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 8 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 8 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 27 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 12 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 30 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 27 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 29 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 4 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 50 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 30 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 46 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 50 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 29 (male) exits the bathroom. #Men: 1. #Women: 0.
Person 46 (male) exits the bathroom. #Men: 0. #Women: 0.
Person 13 (female) enters the bathroom. #Men: 0. #Women: 1.
Person 6 (female) enters the bathroom. #Men: 0. #Women: 2.
Person 22 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 6 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 21 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 22 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 49 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 49 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 44 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 44 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 43 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 13 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 41 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 21 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 17 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 41 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 35 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 43 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 33 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 33 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 32 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 17 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 31 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 31 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 47 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 35 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 20 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 32 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 0 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 47 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 40 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 0 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 11 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 20 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 15 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 40 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 9 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 9 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 11 (female) exits the bathroom. #Men: 0. #Women: 1.
Person 15 (female) exits the bathroom. #Men: 0. #Women: 0.
```
## (2b) Fair Unisex Bathroom
This problem uses the same concept as the unisex bathroom problem but adds an additional parameter:
- No more than ten members of the same gender can have entered the bathroom at the same time. 

In order to implement this, we made some modifications to our code from the previous unisex bathroom implementation. We added in additional integer counters to keep track of how many men/women were waiting for the bathroom and add an additional locking condition to the `enter` procedures to reflect this. In addition to checking if there are any members of the opposite gender or if the bathroom has reached capacity, we must also if there are both members of the opposite gender waiting and the amount of consecutive members of the same gender that entered the bathroom has reached 10.

The `exit` procedures, on the other hand, are changed. We signal one member of the same gender can enter the bathroom if there is at least one member of the same gender waiting to use the bathroom and the amount of consecutive members of the same gender entering the bathroom is less than 10. Otherwise, we signal that members of the opposite gender can enter the bathroom if there are no members of the current gender in the bathroom and the amount of members of the opposite gender waiting outside the bathroom is greater than zero.

### Compilation Instructions:

This program was developed and compiled using a g++ compiler on Visual Studio Code. In order to compile this into an executable, open a terminal and run the following command:
```
g++ fairUnisexBathroom.cpp -o fairUnisexBathroom
```
Once you have your executable, run it in the terminal:
```
./fairUnisexBathroom
```
You should have a sample output similar to what is shown below.

### Sample Output:
```
Person 4 (male) wants to enter the bathroom. #Men: 0. #Women: 0.
Person 4 (male) enters the bathroom. #Men: 1. #Women: 0.
Person 3 (male) wants to enter the bathroom. #Men: 1. #Women: 0.
Person 3 (male) enters the bathroom. #Men: 2. #Women: 0.
Person 2 (female) wants to enter the bathroom. #Men: 2. #Women: 0.
Person 1 (male) wants to enter the bathroom. #Men: 2. #Women: 0.
Person 1 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 26 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 0 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 28 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 7 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 8 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 9 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 10 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 33 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 12 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 13 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 14 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 15 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 16 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 41 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 42 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 43 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 20 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 21 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 22 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 23 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 24 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 25 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 5 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 27 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 6 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 29 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 30 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 31 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 32 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 11 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 34 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 35 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 36 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 37 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 38 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 39 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 40 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 17 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 18 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 19 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 44 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 45 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 46 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 47 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 48 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 49 (female) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 50 (male) wants to enter the bathroom. #Men: 3. #Women: 0.
Person 1 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 26 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 3 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 8 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 8 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 9 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 9 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 10 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 4 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 33 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 26 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 13 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 10 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 14 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 13 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 33 (male) exits the bathroom. #Men: 1. #Women: 0.
Person 14 (male) exits the bathroom. #Men: 0. #Women: 0.
Person 17 (female) enters the bathroom. #Men: 0. #Women: 1.
Person 35 (female) enters the bathroom. #Men: 0. #Women: 2.
Person 29 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 17 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 6 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 29 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 34 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 35 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 20 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 20 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 19 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 34 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 42 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 6 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 41 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 41 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 40 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 19 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 40 (female) exits the bathroom. #Men: 0. #Women: 1.
Person 42 (female) exits the bathroom. #Men: 0. #Women: 0.
Person 47 (male) enters the bathroom. #Men: 1. #Women: 0.
Person 18 (male) enters the bathroom. #Men: 2. #Women: 0.
Person 36 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 18 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 11 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 47 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 50 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 36 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 5 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 11 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 32 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 50 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 27 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 27 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 31 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 5 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 25 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 32 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 31 (male) exits the bathroom. #Men: 1. #Women: 0.
Person 25 (male) exits the bathroom. #Men: 0. #Women: 0.
Person 45 (female) enters the bathroom. #Men: 0. #Women: 1.
Person 28 (female) enters the bathroom. #Men: 0. #Women: 2.
Person 38 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 45 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 49 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 28 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 48 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 38 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 2 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 48 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 7 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 49 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 0 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 2 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 15 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 0 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 23 (female) enters the bathroom. #Men: 0. #Women: 3.
Person 7 (female) exits the bathroom. #Men: 0. #Women: 2.
Person 23 (female) exits the bathroom. #Men: 0. #Women: 1.
Person 15 (female) exits the bathroom. #Men: 0. #Women: 0.
Person 37 (male) enters the bathroom. #Men: 1. #Women: 0.
Person 22 (male) enters the bathroom. #Men: 2. #Women: 0.
Person 44 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 37 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 24 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 22 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 43 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 43 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 21 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 44 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 16 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 16 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 30 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 24 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 46 (male) enters the bathroom. #Men: 3. #Women: 0.
Person 30 (male) exits the bathroom. #Men: 2. #Women: 0.
Person 21 (male) exits the bathroom. #Men: 1. #Women: 0.
Person 46 (male) exits the bathroom. #Men: 0. #Women: 0.
Person 39 (female) enters the bathroom. #Men: 0. #Women: 1.
Person 12 (female) enters the bathroom. #Men: 0. #Women: 2.
Person 12 (female) exits the bathroom. #Men: 0. #Women: 1.
Person 39 (female) exits the bathroom. #Men: 0. #Women: 0.
```
## (3a) Savings Account
This project implements a synchronized bank account system where multiple customers can deposit and withdraw money concurrently. The program ensures safe access to the shared account balance using mutexes and condition variables. This version is the basic solution, where withdrawals wait until sufficient funds are available. Any withdrawal that can be fulfilled proceeds immediately when funds become available.

### Compilation Instructions
This program was developed and compiled using a g++ compiler on Visual Studio Code. In order to compile this into an executable, open a terminal and run the following command:
```
g++ bankAccount.cpp -o bankAccount
```
Once you have your executable, run it in the terminal:
```
./bankAccount
```
You should have a sample output similar to one of the trials shown below.

### Test Cases

**Trial 1:**
```
Customer 0 wants to withdraw 26. Balance: 0
Customer 0 withdraws 26. Balance: 214
Customer 3 deposits 25. Balance: 38
Customer 4 deposits 18. Balance: 56
Customer 6 deposits 69. Balance: 125
Customer 7 deposits 36. Balance: 161
Customer 9 deposits 79. Balance: 240
Customer 1 deposits 13. Balance: 13
Customer 2 wants to withdraw 41. Balance: 214
Customer 2 withdraws 41. Balance: 173
Customer 5 wants to withdraw 35. Balance: 173
Customer 5 withdraws 35. Balance: 138
Customer 8 wants to withdraw 21. Balance: 138
Customer 8 withdraws 21. Balance: 117
```

**Trial 2:**
```
Customer 1 wants to withdraw 19. Balance: 0
Customer 1 withdraws 19. Balance: 272
Customer 4 deposits 47. Balance: 56
Customer 5 deposits 82. Balance: 138
Customer 7 deposits 90. Balance: 228
Customer 9 deposits 63. Balance: 291
Customer 0 deposits 9. Balance: 9
Customer 2 wants to withdraw 21. Balance: 272
Customer 2 withdraws 21. Balance: 251
Customer 3 wants to withdraw 96. Balance: 251
Customer 3 withdraws 96. Balance: 155
Customer 6 wants to withdraw 53. Balance: 155
Customer 6 withdraws 53. Balance: 102
Customer 8 wants to withdraw 61. Balance: 102
Customer 8 withdraws 61. Balance: 41
```

**Trial 3:**
```
Customer 0 deposits 32. Balance: 32
Customer 1 wants to withdraw 21. Balance: 32
Customer 1 withdraws 21. Balance: 234
Customer 3 deposits 33. Balance: 114
Customer 6 deposits 7. Balance: 121
Customer 7 deposits 45. Balance: 166
Customer 8 deposits 5. Balance: 171
Customer 9 deposits 84. Balance: 255
Customer 2 deposits 49. Balance: 81
Customer 4 wants to withdraw 20. Balance: 234
Customer 4 withdraws 20. Balance: 214
Customer 5 wants to withdraw 86. Balance: 214
Customer 5 withdraws 86. Balance: 128
```

**Trial 4:**
```
Customer 0 wants to withdraw 92. Balance: 0
Customer 0 withdraws 92. Balance: 193
Customer 4 deposits 64. Balance: 118
Customer 5 deposits 50. Balance: 168
Customer 6 deposits 31. Balance: 199
Customer 7 deposits 75. Balance: 274
Customer 9 deposits 11. Balance: 285
Customer 1 deposits 54. Balance: 54
Customer 2 wants to withdraw 98. Balance: 193
Customer 2 withdraws 98. Balance: 95
Customer 3 wants to withdraw 58. Balance: 95
Customer 3 withdraws 58. Balance: 37
Customer 8 wants to withdraw 2. Balance: 37
Customer 8 withdraws 2. Balance: 35
```

**Trial 5:**
```
Customer 0 deposits 22. Balance: 22
Customer 1 deposits 79. Balance: 101
Customer 2 deposits 30. Balance: 131
Customer 3 wants to withdraw 25. Balance: 131
Customer 3 withdraws 25. Balance: 416
Customer 5 deposits 88. Balance: 257
Customer 6 deposits 34. Balance: 291
Customer 7 deposits 19. Balance: 310
Customer 8 deposits 34. Balance: 344
Customer 9 deposits 97. Balance: 441
Customer 4 deposits 38. Balance: 169
```
## (3b) FCFS Savings Account
This project aims to implement a FCFS solution to the savings account problem described in (3a). In this solution, strict ordering is enforced so that withdrawal requests are handled in the order they were made. This solution utilizes a queue to track the withdrawal requests, ensuring that earlier requests are processed before later ones, even if a smaller withdrawal could be fulfilled first. 

### Compilation Instructions
This program was developed and compiled using a g++ compiler on Visual Studio Code. In order to compile this into an executable, open a terminal and run the following command:
```
g++ bankAccountFCFS.cpp -o bankAccountFCFS
```
Once you have your executable, run it in the terminal:
```
./bankAccountFCFS
```
You should have a sample output similar to one of the trials shown below.

### Test Cases
**Trial 1:**
```
Customer 0 wants to withdraw 36. Balance: 0
Customer 0 withdraws 36. Balance 328
Customer 3 deposits 40. Balance: 73
Customer 4 deposits 97. Balance: 170
Customer 6 deposits 57. Balance: 227
Customer 7 deposits 92. Balance: 319
Customer 8 deposits 45. Balance: 364
Customer 2 deposits 33. Balance: 33
Customer 1 wants to withdraw 48. Balance: 328
Customer 1 withdraws 48. Balance 280
Customer 5 wants to withdraw 98. Balance: 280
Customer 5 withdraws 98. Balance 182
Customer 9 wants to withdraw 57. Balance: 182
Customer 9 withdraws 57. Balance 125
```

**Trial 2:**
```
Customer 1 deposits 92. Balance: 92
Customer 2 wants to withdraw 72. Balance: 92
Customer 2 withdraws 72. Balance 320
Customer 3 deposits 46. Balance: 142
Customer 6 deposits 84. Balance: 226
Customer 7 deposits 100. Balance: 326
Customer 8 deposits 17. Balance: 343
Customer 9 deposits 49. Balance: 392
Customer 0 deposits 4. Balance: 96
Customer 4 wants to withdraw 82. Balance: 320
Customer 4 withdraws 82. Balance 238
Customer 5 wants to withdraw 47. Balance: 238
Customer 5 withdraws 47. Balance 191
```

**Trial 3:**
```
Customer 0 wants to withdraw 33. Balance: 0
Customer 0 withdraws 33. Balance 262
Customer 3 deposits 32. Balance: 123
Customer 4 deposits 56. Balance: 179
Customer 5 deposits 66. Balance: 245
Customer 8 deposits 50. Balance: 295
Customer 1 deposits 91. Balance: 91
Customer 2 wants to withdraw 23. Balance: 262
Customer 2 withdraws 23. Balance 239
Customer 6 wants to withdraw 5. Balance: 239
Customer 6 withdraws 5. Balance 234
Customer 7 wants to withdraw 60. Balance: 234
Customer 7 withdraws 60. Balance 174
Customer 9 wants to withdraw 16. Balance: 174
Customer 9 withdraws 16. Balance 158
```

**Trial 4:**
```
Customer 1 wants to withdraw 92. Balance: 0
Customer 1 withdraws 92. Balance 166
Customer 3 deposits 96. Balance: 97
Customer 4 deposits 64. Balance: 161
Customer 6 deposits 33. Balance: 194
Customer 7 deposits 36. Balance: 230
Customer 9 deposits 28. Balance: 258
Customer 0 deposits 1. Balance: 1
Customer 2 wants to withdraw 79. Balance: 166
Customer 2 withdraws 79. Balance 87
Customer 5 wants to withdraw 4. Balance: 87
Customer 5 withdraws 4. Balance 83
Customer 8 wants to withdraw 64. Balance: 83
Customer 8 withdraws 64. Balance 19
```

**Trial 5:**
```
Customer 1 deposits 78. Balance: 78
Customer 0 deposits 68. Balance: 146
Customer 2 wants to withdraw 24. Balance: 146
Customer 2 withdraws 24. Balance 449
Customer 7 deposits 60. Balance: 306
Customer 8 deposits 24. Balance: 330
Customer 5 deposits 66. Balance: 396
Customer 6 deposits 77. Balance: 473
Customer 3 deposits 100. Balance: 246
Customer 4 wants to withdraw 45. Balance: 449
Customer 4 withdraws 45. Balance 404
Customer 9 wants to withdraw 31. Balance: 404
Customer 9 withdraws 31. Balance 373
```
## Comparison Between (3a) and (3b)
The implementation uses threads to simulate multiple customers performing transactions and demonstrates the differences between the two synchronization approaches. The output of the programs demonstrate how deposit and withdrawal operations are synchronized to prevent race conditions. In the basic solution, withdrawals occur as soon as enough funds are available, but they do not necessarily follow the order in which they were requested. This can result in smaller withdrawals being processed before larger ones if sufficient funds exists for the smaller amount first. In the FCFS solution, withdrawals are processed in strict order, ensuring that earlier requests are fulfilled before later ones, even if a smaller request could be handled first. This gurantees fairness among withdrawal requests and prevents starvation, making the behavior of the program more predictable and structured.