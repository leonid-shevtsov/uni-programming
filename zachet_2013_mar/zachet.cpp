#include <iostream>
#include <iomanip>

using namespace std;

class ExamResult {
public:
  ExamResult();
  ExamResult(int mark100);

  int setMark100(int mark100);
  int mark5() const;
  int mark100() const;

  friend ostream& operator << (ostream &out, const ExamResult &result);
  friend istream& operator >> (istream &in, ExamResult &result);

private:
  int _mark100;
};

ExamResult::ExamResult(): _mark100(0) {};
ExamResult::ExamResult(int mark100): _mark100(mark100) {};

int ExamResult::setMark100(int mark100) {
  return _mark100 = mark100;
}

int ExamResult::mark100() const {
  return _mark100;
}

int ExamResult::mark5() const {
  if (_mark100<60)
    return 2;
  else if (_mark100<75)
    return 3;
  else if (_mark100<90)
    return 4;
  else
    return 5;
}

ostream& operator << (ostream &out, const ExamResult &result) {
  return out << result.mark100() << "/100, " << result.mark5() << "/5";
}

istream& operator >> (istream &in, ExamResult &result) {
  return in >> result._mark100;
}

class ExamListing {
public:
  ExamListing(const char** studentList, int numStudents, const char** subjectList, int numSubjects);
  ~ExamListing();

  char** studentList() { return _studentList; }
  char** subjectList() { return _subjectList; }
  int numStudents() { return _numStudents; }
  int numSubjects() { return _numSubjects; }

  void recordResult(int iStudent, int iSubject, int mark100);
  ExamResult getResult(int iStudent, int iSubject);

  // Select students for which every ExamResult passes
  void selectStudents(int doesItPass(ExamResult &result), void resultFunction(const char* studentName));
  // Reject students for which every ExamResult passes
  void rejectStudents(int doesItPass(ExamResult &result), void resultFunction(const char* studentName));

  friend ostream& operator << (ostream &out, const ExamListing &listing);

private:
  char** _studentList;
  char** _subjectList;
  int _numStudents;
  int _numSubjects;
  ExamResult **_resultTable;
};

ExamListing::ExamListing(const char** studentList, int numStudents, const char** subjectList, int numSubjects):
  _numStudents(numStudents), _numSubjects(numSubjects)
{
  int i;
  _studentList = new char*[_numStudents];
  _subjectList = new char*[_numSubjects];
  for (i=0; i<_numStudents; ++i) {
    _studentList[i] = strdup(studentList[i]);
  }
  for (i=0; i<_numSubjects; ++i) {
    _subjectList[i] = strdup(subjectList[i]);
  }

  _resultTable = new ExamResult*[_numStudents];

  for (i=0; i<_numStudents; ++i) {
    _resultTable[i] = new ExamResult[_numSubjects];
  }
}

ExamListing::~ExamListing() {
  int i;
  for (i=0; i<_numStudents; ++i) {
    free(_studentList[i]);
    free(_resultTable[i]);
  }
  for (i=0; i<_numSubjects; ++i) {
    free(_subjectList[i]);
  }
  delete[] _studentList;
  delete[] _resultTable;
  delete[] _subjectList;
}

void ExamListing::recordResult(int iStudent, int iSubject, int mark100) {
  _resultTable[iStudent][iSubject].setMark100(mark100);
}

ExamResult ExamListing::getResult(int iStudent, int iSubject) {
  return _resultTable[iStudent][iSubject];
}

void ExamListing::selectStudents(int doesItPass(ExamResult &result), void resultFunction(const char* studentName)) {
  for (int i=0; i<_numStudents; ++i) {
    bool passes = true;
    for (int j=0; j<_numSubjects; ++j) {
      if (!doesItPass(_resultTable[i][j])) {
        passes = false;
        break;
      }
    }
    if (passes) {
      resultFunction(_studentList[i]);
    }
  }
}

void ExamListing::rejectStudents(int doesItPass(ExamResult &result), void resultFunction(const char* studentName)) {
  for (int i=0; i<_numStudents; ++i) {
    bool passes = true;
    for (int j=0; j<_numSubjects; ++j) {
      if (!doesItPass(_resultTable[i][j])) {
        passes = false;
        break;
      }
    }
    // the negation here is the only difference from selectStudents
    if (!passes) {
      resultFunction(_studentList[i]);
    }
  }
}

ostream& operator << (ostream &out, const ExamListing &listing) {
  int i, j;

  out << setw(15) << " ";
  for (i=0; i<listing._numSubjects; ++i) {
    out << setw(15) << listing._subjectList[i];
  }
  out << endl;

  for (i=0; i<listing._numStudents; ++i) {
    out << setw(15) << listing._studentList[i];
    for (j=0; j<listing._numSubjects; ++j) {
      out << setw(15) << listing._resultTable[i][j];
    }
    out << endl;
  }

  return out;
}

void printStudent(const char* studentName) {
  cout << studentName << endl;
}

int only5(ExamResult &result) {
  return result.mark5() == 5;
}

int only45(ExamResult &result) {
  return result.mark5() >= 4;
}

int not2(ExamResult &result) {
  return result.mark5() > 2;
}


// Example output
        //                        Mathematics                 Physics         Chemistry
        //  Ivanov             95/100, 5/5             84/100, 4/5             99/100, 5/5
        //  Petrov             92/100, 5/5             77/100, 4/5             65/100, 3/5
        // Sidorov             99/100, 5/5             66/100, 3/5              0/100, 2/5
// ## Only 5
// ## Only 4, 5
// Ivanov
// ## Not 2
// Ivanov
// Petrov
// ## Some 2
// Sidorov

int main() {
  const char* students[] = {"Ivanov", "Petrov", "Sidorov"};
  const char* subjects[] = {"Mathematics", "Physics", "Chemistry"};

  ExamListing *listing = new ExamListing(students, 3, subjects, 3);

  listing->recordResult(0, 0, 95);
  listing->recordResult(0, 1, 84);
  listing->recordResult(0, 2, 99);

  listing->recordResult(1, 0, 92);
  listing->recordResult(1, 1, 77);
  listing->recordResult(1, 2, 65);

  listing->recordResult(2, 0, 99);
  listing->recordResult(2, 1, 66);
  listing->recordResult(2, 2, 0);


  cout << *listing;

  cout << "## Only 5" << endl;
  listing->selectStudents(&only5, printStudent);
  cout << "## Only 4, 5" << endl;
  listing->selectStudents(&only45, printStudent);
  cout << "## Not 2" << endl;
  listing->selectStudents(&not2, printStudent);
  cout << "## Some 2" << endl;
  listing->rejectStudents(&not2, printStudent);

  delete listing;

  return 0;
  }