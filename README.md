Dining Philosophers Problem
Overview
The Dining Philosophers Problem is a classic synchronization problem that illustrates the challenges of resource sharing and multithreading. This project implements a solution using C, demonstrating the application of threading, mutexes, and condition variables to manage shared resources among multiple threads (philosophers).

Features
Multithreading: Each philosopher is represented by a separate thread, allowing them to think, eat, and sleep concurrently.
Synchronization: Utilizes mutexes to prevent deadlock and ensure that forks (resources) are accessed safely.
Customizable Parameters: The number of philosophers, maximum eating times, and sleep durations can be adjusted via command-line arguments.
Installation
To compile and run the project, ensure you have a C compiler (like gcc) and the necessary development tools installed. Follow these steps:

Clone the repository:

bash
Copy code
git clone <repository-url>
cd dining-philosophers
Compile the code:

bash
Copy code
make
Run the program with desired parameters:

bash
Copy code
./philo <number_of_philosophers> <time_to_eat> <time_to_sleep> <max_eat_count>
Parameters
<number_of_philosophers>: The total number of philosophers (threads) participating in the dinner.
<time_to_eat>: The time (in milliseconds) each philosopher takes to eat.
<time_to_sleep>: The time (in milliseconds) each philosopher takes to sleep.
<max_eat_count>: The maximum number of times each philosopher should eat before the simulation ends.
Example
bash
Copy code
./philo 5 800 200 7
This command starts a simulation with 5 philosophers, where each philosopher eats for 800 milliseconds, sleeps for 200 milliseconds, and aims to eat 7 times.

Log Output
The program outputs the state of each philosopher throughout the simulation, including when they take forks, start eating, think, and sleep. Here’s an example log:

css
Copy code
0   1 has taken a left fork
0   1 has taken a right fork
0   1 starts to eat
...
Contributing
Contributions are welcome! If you have suggestions for improvements or new features, feel free to open an issue or submit a pull request.

