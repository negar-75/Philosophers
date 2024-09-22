# Dining Philosophers Problem

## Overview
The Dining Philosophers Problem is a classic synchronization problem that illustrates the challenges of resource sharing and multithreading. This project implements a solution using C, demonstrating the application of threading, mutexes, and condition variables to manage shared resources among multiple threads (philosophers).

## Features
- **Multithreading**: Each philosopher is represented by a separate thread, allowing them to think, eat, and sleep concurrently.
- **Synchronization**: Utilizes mutexes to prevent deadlock and ensure that forks (resources) are accessed safely.
- **Customizable Parameters**: The number of philosophers, maximum eating times, and sleep durations can be adjusted via command-line arguments.
## Solution:
| Concept     | Description                 
|-------------|------------------------------------
| Sequential  | Tasks are executed one after another, no overlap in execution.         
| Concurrency | Tasks are interleaved or handled in an overlapping manner, but not necessarily in parallel.         
| Parallelism | Tasks are executed truly simultaneously on multiple CPU cores.        
| Blocking    | The program halts or waits for a task to finish (e.g., I/O-bound task).          
      
Concurrency and parallelism are related but distinct. Concurrency allows for multiple tasks to be managed and executed during overlapping time periods (even on a single core), while parallelism requires multiple tasks to run simultaneously on different cores.
### thread vs process :

A program under execution is a process, and each process can have multiple threads.For example, Chrome is a process running on a single CPU core, but it has multiple threads to perform various tasks simultaneously, such as downloading files and displaying websites on the screen.Threads share the same memory space but can perform different tasks concurrently.

### **Multithreading**

- **Concurrency**: Multiple threads make progress **in overlapping time periods** but not necessarily at the same moment. This happens on a **single-core CPU**, where the processor switches between threads quickly, giving the illusion that they are running simultaneously. The focus here is on the management of multiple tasks over time.
- **Parallelism**: Multiple threads run **at the same time** on **multiple cores or processors**. This is true parallel execution, where tasks are actually processed simultaneously by separate CPU cores, improving performance when heavy computations are involved.

In this problem, **philosopher** is a single **thread** and **forks** are shared **resources**

The **challenge** is to coordinate philosophers (threads) such that they do not face issues like deadlock (where no one can eat because all forks are in use) or starvation (where one philosopher never gets a chance to eat)

## BIG QUESTION ❓

### **Given our limited shared resources (forks)🍴,How can we effectively manage them?**

### **Mutex**

Mutex (Mutual Exclusion) is a synchronization mechanism used in concurrent programming to prevent multiple threads from simultaneously accessing a shared resource. Key points about mutex:

- It acts as a lock that only one thread can acquire at a time.
- When a thread acquires a mutex, it has exclusive access to the protected resource.
- Other threads attempting to acquire the same mutex will be blocked until the mutex is released.
- Helps prevent race conditions and ensures data integrity in multi-threaded environments.

In the context of the dining philosophers problem, a mutex could be used to represent each fork, ensuring that only one philosopher can use a particular fork at any given time.

## Semaphore

A semaphore is a synchronization mechanism used in concurrent programming to control access to shared resources. It maintains a count of available resources and allows multiple threads to access them simultaneously, unlike a mutex which permits only one thread at a time.
 

## Installation
To compile and run the project, ensure you have a C compiler (like `cc`) and the necessary development tools installed. Follow these steps:

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd philosophers/philo
   ```

   ```bash
   make
   ```
## Run the program with following command
   ```bash
   ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <number_of_meals>
   ```

- **number_of_philosophers**: Total number of philosophers (must be greater than 0).
- **time_to_die**: Time in milliseconds before a philosopher dies from starvation.
- **time_to_ea**t: Time in milliseconds a philosopher spends eating.
- **time_to_sleep**: Time in milliseconds a philosopher spends sleeping.
- **number_of_meals**: Optional argument to specify the number of times each philosopher must eat.
## Logic
```bash
Time per cycle = Time to eat+Time to sleep=200ms+100ms=300ms
```
So in such a test case like 5 800 200 100
```bash
Time per cycle = 200 + 100 = 300
```
**So 800 >> 300**

each philosopher has enough chance to eat

 ### If Time to Eat+Time to Sleep<Time to Die, no philosopher will die.
 ## Output
 ```bash
0   1 has taken a left fork
0   1 has taken a right fork
0   1 starts to eat
0   3 has taken a left fork
0   3 has taken a right fork
0   3 starts to eat
...
```
