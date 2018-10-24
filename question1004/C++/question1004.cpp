#include<iostream>
#include<string>

using namespace std;

struct Student {
	string name;
	string number;
	int score;
};

int main() {
	int count;
	cin >> count;

	string name;
	string number;
	int score;
	cin >> name >> number >> score;

	Student lowestStudent;
	Student highestStudent;

	lowestStudent.name = name;
	lowestStudent.number = number;
	lowestStudent.score = score;

	highestStudent.name = name;
	highestStudent.number = number;
	highestStudent.score = score;

	for (int i = 1; i < count; i++) {
		cin >> name >> number >> score;
		if (score > highestStudent.score) {
			highestStudent.name = name;
			highestStudent.number = number;
			highestStudent.score = score;
		}
		if (score < lowestStudent.score) {
			lowestStudent.name = name;
			lowestStudent.number = number;
			lowestStudent.score = score;
		}
	}

	cout << highestStudent.name << " " << highestStudent.number << endl;
	cout << lowestStudent.name << " " << lowestStudent.number << endl;
}