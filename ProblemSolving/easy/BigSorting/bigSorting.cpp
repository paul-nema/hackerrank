//  https://www.hackerrank.com/challenges/big-sorting/

#include <bits/stdc++.h>

using namespace std;

// Function to check string size
bool compare( std::string &s1, std::string &s2 ) { 
    if( s1.size() == s2.size() ) {  //  if same length compare string
        return( s1 < s2 );
    }

    return( s1.size() < s2.size() );
}

// Complete the bigSorting function below.
std::vector< std::string > &bigSorting( std::vector< std::string> &unsorted ) {
    std::sort( unsorted.begin(), unsorted.end(), compare );

    return( unsorted );
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<string> unsorted(n);

  for (int i = 0; i < n; i++) {
    string unsorted_item;
    getline(cin, unsorted_item);

    unsorted[i] = unsorted_item;
  }

  vector<string> result = bigSorting(unsorted);

  for ( unsigned long i = 0; i < result.size(); i++) {
    cout << result[i];

    if (i != result.size() - 1) {
      cout << "\n";
    }
  }

  cout << "\n";

  return 0;
}
