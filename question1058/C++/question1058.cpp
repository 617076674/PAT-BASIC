#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

struct question {
	int score;
	string trueOptionsAndAnswer;
};

int main() {

	int N, M;

	cin >> N >> M;

	int tempScore;
	int tempOptions;
	int tempTrueOptions;
	char tempAnswer;

	question tempQuestion;

	vector<question> questions;

	for(int i = 0; i < M; i++) {
		cin >> tempScore >> tempOptions >> tempTrueOptions;
		tempQuestion.trueOptionsAndAnswer = "";
		stringstream ss(tempQuestion.trueOptionsAndAnswer);
		ss << tempTrueOptions;
		tempQuestion.trueOptionsAndAnswer = ss.str();
		tempQuestion.trueOptionsAndAnswer += " ";
		for(int i = 0; i < tempTrueOptions; i++) {
			cin >> tempAnswer;
			tempQuestion.trueOptionsAndAnswer += tempAnswer;
			if(i != tempTrueOptions - 1) {
				tempQuestion.trueOptionsAndAnswer += " ";
			}
		}
		tempQuestion.score = tempScore;

		questions.push_back(tempQuestion);
	}

	getchar();

	string student;

	int scores[N];
	for(int i = 0; i < N; i++) {
		scores[i] = 0;
	}

	int countWrong[M];
	for(int i = 0; i < M; i++) {
		countWrong[i] = 0;
	}

	for(int i = 0; i < N; i++) {

		getline(cin, student);

		int index = 0;

		for(int j = 0; j < student.length(); j++) {
			if(student[j] == '(') {
				j++;
				string studentAnswer = "";
				while(student[j] != ')') {
					studentAnswer += student[j];
					j++;
				}
				if(questions[index].trueOptionsAndAnswer.compare(studentAnswer) == 0) {
					scores[i] += questions[index].score;
				} else {
					countWrong[index]++;
				}
				index++;
			}
		}
	}
	for(int i = 0; i < N; i++) {
		printf("%d\n", scores[i]);
	}

	int maxWrong = 0;
	for(int i = 0; i < M; i++) {
		if(countWrong[i] > maxWrong) {
			maxWrong = countWrong[i];
		}
	}

	if(maxWrong == 0) {
		cout << "Too simple" << endl;
	} else {
		cout << maxWrong;
		for(int i = 0; i < M; i++) {
			if(countWrong[i] == maxWrong){
				cout << " " << (i + 1);
			}
		}
	}
}
