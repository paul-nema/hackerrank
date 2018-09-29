//      https://www.hackerrank.com/challenges/virtual-functions/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#include <numeric>

const int MARKS = 6;

static int STUDENT_NUMBER = 0;
static int PROFESSOR_NUMBER = 0;

class Person {
    public:
        std::string &name( ) {
            return( m_name );
        }
        void name( std::string &name ) {
            m_name = name;
        };

        int &age( ) {
            return( m_age );
        }
        void age( int age ) {
            m_age = age;
        };

        virtual void getdata() = 0;
        virtual void putdata() = 0;

    private:
        std::string m_name;
        int m_age;
};

class Student: public Person {
    public:
        Student () {
            m_cur_id = ++STUDENT_NUMBER;
        }

        void getdata() {
            std::cin >> name();
            std::cin >> age();

            for( auto x = 0; x < MARKS; ++x ) {
                std::cin >> m_marks[ x ];
            }

            std::cin.ignore( numeric_limits< streamsize >::max(), '\n' );
        }

        void putdata() {
            auto sum( 0 );

            std::cout << name() << " "
                << age() << " "
                << std::accumulate(m_marks, m_marks + MARKS, sum)    //  Sum m_marks
                << " " << m_cur_id << "\n";;
        }

    private:
        int m_cur_id;
        int m_marks[ MARKS ];
};

class Professor : public Person {
    public:
        Professor () {
            m_cur_id = ++PROFESSOR_NUMBER;
        }

        void getdata() {
            std::cin >> name();
            std::cin >> age();
            std::cin >> m_publications;

            std::cin.ignore( numeric_limits< streamsize >::max(), '\n' );
        };

        void putdata() {
            std::cout << name() << " "
                << age() << " "
                << m_publications << " "
                << m_cur_id << "\n";
        }
    private:
        int m_publications;
        int m_cur_id;
};

int main() {
  int n, val;
  cin >> n; // The number of objects that is going to be created.
  Person *per[n];

  for (int i = 0; i < n; i++) {

    cin >> val;
    if (val == 1) {
      // If val is 1 current object is of type Professor
      per[i] = new Professor;

    } else
      per[i] = new Student; // Else the current object is of type Student

    per[i]->getdata(); // Get the data from the user.
  }

  for (int i = 0; i < n; i++)
    per[i]->putdata(); // Print the required output for each object.

  return 0;
}
