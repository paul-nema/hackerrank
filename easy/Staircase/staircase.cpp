//  https://www.hackerrank.com/challenges/staircase/

#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    for( auto x = 0; x < n; ++x ) {
        std::cout << std::setfill (' ') << std::setw ( n - x - 1);
        std::cout << "";
        std::cout << std::setfill ('#') << std::setw ( x + 1 );
        std::cout << "" << std::endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
