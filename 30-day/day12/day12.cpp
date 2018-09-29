#include <iostream>
#include <vector>

using namespace std;

class Person {
protected:
  string firstName;
  string lastName;
  int id;

public:
  Person(string firstName, string lastName, int identification) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = identification;
  }
  void printPerson() {
    cout << "Name: " << lastName << ", " << firstName << "\nID: " << id << "\n";
  }
};

#include <numeric>

class Student : public Person {
private:
  vector<int> testScores;

public:
  /*
  *   Class Constructor
  *
  *   Parameters:
  *   firstName - A string denoting the Person's first name.
  *   lastName - A string denoting the Person's last name.
  *   id - An integer denoting the Person's ID number.
  *   scores - An array of integers denoting the Person's test scores.
  */
  // Write your constructor here
  Student(std::string fName, std::string lName, int id, std::vector<int> scores)
      : Person(fName, lName, id), testScores(scores) {}

  /*
  *   Function Name: calculate
  *   Return: A character denoting the grade.
  */
  // Write your function here
  char calculate() {
    auto score(std::accumulate(testScores.begin(), testScores.end(), 0.0) /
               testScores.size());
    auto grade('F');

    if (score >= 90) {
      grade = 'O';
    } else if (score >= 80) {
      grade = 'E';
    } else if (score >= 70) {
      grade = 'A';
    } else if (score >= 55) {
      grade = 'P';
    } else if (score >= 40) {
      grade = 'D';
    } else {
      grade = 'T';
    }

    return (grade);
  }
};

int main() {
  string firstName;
  string lastName;
  int id;
  int numScores;
  cin >> firstName >> lastName >> id >> numScores;
  vector<int> scores;
  for (int i = 0; i < numScores; i++) {
    int tmpScore;
    cin >> tmpScore;
    scores.push_back(tmpScore);
  }
  Student *s = new Student(firstName, lastName, id, scores);
  s->printPerson();
  cout << "Grade: " << s->calculate() << "\n";
  return 0;
}
