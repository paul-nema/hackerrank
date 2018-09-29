#include <bits/stdc++.h>

using namespace std;

/*
 *  * Complete the gradingStudents function below.
 *   */
vector<int> gradingStudents(vector<int> &grades) {
  /*
   *      * Write your code here.
   *           */
    for( auto &grade: grades ) {
        if( grade < 38 ) {
            continue;
        }

        if( ( grade + 1 ) % 5 == 0 ) {
            grade += 1;
            continue;
        }

        if( ( grade + 2 ) % 5 == 0 ) {
            grade += 2;
        }
    }

    return( grades );
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> grades(n);

  for (int grades_itr = 0; grades_itr < n; grades_itr++) {
    int grades_item;
    cin >> grades_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    grades[grades_itr] = grades_item;
  }

  vector<int> result = gradingStudents(grades);

  for (int result_itr = 0; result_itr < result.size(); result_itr++) {
    cout << result[result_itr];

    if (result_itr != result.size() - 1) {
        cout << "\n";
    }

  }

  cout << "\n";

  return 0;
}
