#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto phoneNums( 0 );

    std::cin >> phoneNums;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::map< std::string, std::string > phoneBook;
    std::string name;
    std::string phoneNum;

    for( auto x = 0; x < phoneNums; ++x ) { //  Creat phoneBook
        std::cin >> name >> phoneNum;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        phoneBook[ name ] = phoneNum;
    }

    std::string query;

    while( std::getline( std::cin, query ) ) {
        if( query == "\n" || query.size() == 0 ) {
            return( 0 );
        }
        if( phoneBook.find( query ) == phoneBook.end() ) {
            std::cout << "Not found" << std::endl;
        } else {
            std::cout << query << "=" << phoneBook[ query ] << std::endl;
        }
    }

  return 0;
}
