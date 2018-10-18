#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> &scores, vector<int> &alice) {
    vector< int > rankings( scores .size() );

    int pos{ 0 };
    unsigned long x;

    // create a vec with duplicates scores removed
    for( x = 0; x < scores.size(); ++x ) {
        rankings[ pos ] = scores[ x ];

        for( unsigned long y = x + 1; y < scores.size(); ++y ) {
            if( rankings[ pos ] == scores[ y ] ) {
                x = y;
            } else {
                break;
            }
        }

        ++pos;
    }

    rankings.resize( pos );

    vector< int > ranking( alice.size() );

    pos = rankings.size() - 1;  // Keep last position of scores and next loop start there
    int y;

    // Find rankings starting from the rear of scores.
    for( x = 0; x < alice.size(); ++x ) {
        for( y = pos; y >= 0; --y ) {
            if( alice[ x ] < rankings[ y ] ) {
                pos = y;
                ranking[ x ] = y + 2;
                break;
            } else if( alice[ x ] < rankings[ y ] ) {
                pos = y;
                ranking[ x ] = y + 1;
                break;
            } else if( y == 0 && alice[ x ] > rankings[ y ] ) {
                ranking[ x ] = 1;
            }
        }
    }

    return( ranking ) ;
}

int main() {
  int scores_count;
  cin >> scores_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string scores_temp_temp;
  getline(cin, scores_temp_temp);

  vector<string> scores_temp = split_string(scores_temp_temp);

  vector<int> scores(scores_count);

  for (int i = 0; i < scores_count; i++) {
    int scores_item = stoi(scores_temp[i]);

    scores[i] = scores_item;
  }

  int alice_count;
  cin >> alice_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string alice_temp_temp;
  getline(cin, alice_temp_temp);

  vector<string> alice_temp = split_string(alice_temp_temp);

  vector<int> alice(alice_count);

  for (int i = 0; i < alice_count; i++) {
    int alice_item = stoi(alice_temp[i]);

    alice[i] = alice_item;
  }

  vector<int> result = climbingLeaderboard(scores, alice);

  for (unsigned long i = 0; i < result.size(); i++) {
    cout << result[i];

    if (i != result.size() - 1) {
      cout << "\n";
    }
  }

  cout << "\n";

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
