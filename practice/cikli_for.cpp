// Online C++ compiler to run C++ program online
#include <iostream> // Include the iostream library for input/output operations

int main() {
    
    int n; // Declare an integer variable to store the user input
    
    // Prompt the user to input a value for n
    std::cout << "Please make an input: " << "\n";
    std::cin >> n; // Read the user input and store it in the variable n
    
    int result = 1; // Initialize the result variable to 1 (since factorial starts from 1)
    
    // Use a for loop to calculate n!
    for (int i = 1; i <= n; i++) { // Loop from 1 to n
        result += i; // Add result by the current value of i
    }
    
    // Output the calculated factorial
    std::cout << result << "\n";
    
    return 0; // Indicate that the program executed successfully
}