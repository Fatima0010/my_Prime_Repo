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
void generateMaze(int size, int range, bool displayCharacters) 
{
    vector<vector<int>> maze(size, vector<int>(size, 0));

    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            int num = rand() % range;  // Random number between 0 and range
            maze[i][j] = num; // Store the number in the maze
        }
    }

    // Print the maze
    for (const auto &row : maze) 
    {
        for (const auto &cell : row) 
        {
            if (displayCharacters) 
            {
                // Display as characters
                if (isPrime(cell)) 
                {
                    cout << 'P' << ' ';  // Mark prime numbers with 'P'
                }
                else
                {
                    cout << '.' << ' ';  // Mark non-prime numbers with '.'
                }
            } 
            else
            {
                // Display numbers
                cout << cell << ' ';
            }
        }
        cout << endl;
    }
}

int main() 
{
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation
    int size, range;
    char displayOption;

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

    // Input for display option
    while (true) 
    {
        cout << "Do you want to display characters (P for prime, . for non-prime) or numbers? (Enter 'c' for characters, 'n' for numbers): ";
        cin >> displayOption;

        if (displayOption == 'c' || displayOption == 'C')
        {
            generateMaze(size, range, true);
            break;
        } 
        else if (displayOption == 'n' || displayOption == 'N') 
        {
            generateMaze(size, range, false);
            break;
        }
        else 
        {
            cout << "Invalid option. Please enter 'c' or 'n'." << endl;
        }
    }

    return 0;
}
