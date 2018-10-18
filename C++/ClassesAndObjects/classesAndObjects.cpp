//  https://www.hackerrank.com/challenges/classes-objects/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// Write your Student class here
static const int NUM_OF_STUDENTS = 5;

class Student {
    public:
        void input() {
            auto tmp( 0 );

            for( auto x( 0 ); x < NUM_OF_STUDENTS; ++x ) {
                std::cin >> tmp;
                scores.push_back( tmp );
            }

            std::cin.ignore( numeric_limits< streamsize >::max(), '\n' );
        }

        int calculateTotalScore() {
            return( std::accumulate( scores.begin(), scores.end(), 0 ) );
        }

    private:
        std::vector< int > scores;
};

int main() {
  int n; // number of students
  cin >> n;
  Student *s = new Student[n]; // an array of n students

  for (int i = 0; i < n; i++) {
    s[i].input();
  }

  // calculate kristen's score
  int kristen_score = s[0].calculateTotalScore();

  // determine how many students scored higher than kristen
  int count = 0;
  for (int i = 1; i < n; i++) {
    int total = s[i].calculateTotalScore();
    if (total > kristen_score) {
      count++;
    }
  }

  // print result
  cout << count;

  return 0;
}
