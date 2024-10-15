#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits> // For numeric_limits

using namespace std;

// Initial commit: added isPrime function to check if a number is prime
// Function to check if a number is prime
bool isPrime(int num) 
{
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) 
    {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to generate a prime number maze
void generateMaze(int size, int range) 
{
    vector<vector<char>> maze(size, vector<char>(size, ' '));

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j) 
        {
            int num = rand() % range;  // Random number between 0 and range
            if (isPrime(num))
            {
                maze[i][j] = 'P';  // Mark prime numbers with 'P'
            }
            else 
            {
                maze[i][j] = '.';  // Mark non-prime numbers with '.'
            }
        }
    }

    // Print the maze
    for (const auto &row : maze)
    {
        for (const auto &cell : row)
        {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

int main() 
{
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation
    int size, range;

    // Input validation for maze size
    while (true) 
    {
        cout << "Enter the size of the maze (positive integer): ";
        cin >> size;

        if (cin.fail() || size <= 0) 
        {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Invalid input. Please enter a positive integer." << endl;
        } 
        else 
        {
            break; // Valid input, exit loop
        }
    }

    // Input validation for range
    while (true)
    {
        cout << "Enter the upper limit for random numbers (positive integer): ";
        cin >> range;

        if (cin.fail() || range <= 0) 
        {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Invalid input. Please enter a positive integer." << endl;
        } 
        else
        {
            break; // Valid input, exit loop
        }
    }

    generateMaze(size, range);
    return 0;
}
