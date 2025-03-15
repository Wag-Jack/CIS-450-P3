# CIS 450 P3
**Developed by Eman Sedqi and Jack Wagner**\
**March 14th, 2025**

# Compilation Instructions
To compile and run each program, you must have a g++ compiler which can support C++20. We used Visual Studio Code configured with a g++ compiler to develop this project. To run each file as an executable, open a terminal and type in the following g++ command:
```
g++ {filename}.cpp -o {executable_name}
```
Once you have compiled your cpp file, it will now be available as an executable. You can run it by typing the following into your terminal:
```
./{executable_name}
```

## (1) Bounded Buffer

## (2a) Unisex Bathroom 
In this problem, we have a unisex bathroom which abides by the following two conditions:</br>
- Only three employees can be in the bathroom at the same time
- Only employees of the same gender can be in the bathroom at the same time

To implement this solution, we utilized fifty threads with randomized genders between male and female. The male threads would execute `oneMan` and the female threads would execute `oneWoman`, with each thread having their own respective enter and exit procedures for each gender. Both also have a method `useBathroom` which simulates the thread "using the bathroom" by holding it for some time between 100 and 2000 ms.

The `enter` procedures work by locking the thread if there is either a member of the opposite gender in the bathroom or the amount of people of the same gender in the bathroom reaches three. Once these conditions are no longer true, the thread is able to begin running and increments the amount of people in the bathroom. The `exit` procedures work by decrementing the amount of people in the bathroom and signifying if either one more member of the same gender can be in the bathroom or the bathroom is free for the other gender to enter, signaling the respective condition variable using `notify_one` and `notify_all` respectively.

Below is a sample output we received when executing the program:
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

Below is a sample output we received when running the program:
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

Below is the output of each of our five trial runs for the basic solutions of this problem:
### Trial 1
```
```

### Trial 2
```
```

### Trial 3
```
```

### Trial 4
```
```

### Trial 5
```
```

## (3b) FCFS Savings Account
This project aims to implement a FCFS solution to the savings account problem described in (3a). In this solution, strict ordering is enforced so that withdrawal requests are handled in the order they were made. This solution utilizes a queue to track the withdrawal requests, ensuring that earlier requests are processed before later ones, even if a smaller withdrawal could be fulfilled first. 

Below is the sample output of each of our five trial runs for the FCFS solutions of this problem:
### Trial 1
```
```

### Trial 2
```
```

### Trial 3
```
```

### Trial 4
```
```

### Trial 5
```
```

## Comparison Between (3a) and (3b)
The implementation uses threads to simulate multiple customers performing transactions and demonstrates the differences between the two synchronization approaches. The output of the programs demonstrate how deposit and withdrawal operations are synchronized to prevent race conditions. In the basic solution, withdrawals occur as soon as enough funds are available, but they do not necessarily follow the order in which they were requested. This can result in smaller withdrawals being processed before larger ones if sufficient funds exists for the smaller amount first. In the FCFS solution, withdrawals are processed in strict order, ensuring that earlier requests are fulfilled before later ones, even if a smaller request could be handled first. This gurantees fairness among withdrawal requests and prevents starvation, making the behavior of the program more predictable and structured.