#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
int i = 4;
double d = 4.0;
string s = "HackerRank ";

// Declare second integer, double, and String variables.
int secondInt( 0 );
double doubleNum( 0.0 );
std::string secondStr;

// Read and save an integer, double, and String to your variables.
std::cin >> secondInt >> doubleNum;
std::cin.ignore();  //  ignore the last return char
std::getline( std::cin, secondStr );

// Print the sum of both integer variables on a new line.
std::cout << i + secondInt << "\n";

// Print the sum of the double variables on a new line.
std::cout << std::fixed << std::setprecision(1) << ( d + doubleNum ) << "\n";

// Concatenate and print the String variables on a new line
// The 's' variable above should be printed first.
std::cout << s + secondStr << std::endl;
}
