#include<iostream>
#include<string>

using namespace std;

struct student {
	string studentNumber;
	int tryNumber;
	int testNumber;
};

int main() {
	int totalNum;

	student tempStudent;
	string tempStudentNumber;
	int tempTryNumber;
	int tempTestNumber;

	cin >> totalNum;

	student students[1001];

	for (int i = 0; i < totalNum; i++) {
		cin >> tempStudentNumber >> tempTryNumber >> tempTestNumber;
		tempStudent.studentNumber = tempStudentNumber;
		tempStudent.tryNumber = tempTryNumber;
		tempStudent.testNumber = tempTestNumber;
		students[tempTryNumber] = tempStudent;
	}

	int queryNum;
	int queryNumber;
	
	cin >> queryNum;

	for (int i = 0; i < queryNum; i++) {
		cin >> queryNumber;
		cout << students[queryNumber].studentNumber << " " << students[queryNumber].testNumber << endl;
	}
}