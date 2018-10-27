#include<iostream>

using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	
	int teacherScore;
	int studentScore;
	int studentMaxScore;
	int studentMinScore;
	int studentTotalScore;
	int countValid;
	int tempStudentScore;
	
	double score;
	int finalScore;
	
	for(int i = 0; i < N; i++){
		studentMaxScore = 0;
		studentMinScore = M;
		studentTotalScore = 0;
		countValid = 0;
		cin >> teacherScore;
		for(int j = 0; j < N - 1; j++){
			cin >> tempStudentScore;
			if(tempStudentScore >= 0 && tempStudentScore <= M){
				if(studentMaxScore < tempStudentScore){
					studentMaxScore = tempStudentScore;
				}
				if(studentMinScore > tempStudentScore){
					studentMinScore = tempStudentScore;
				}
				countValid++;
				studentTotalScore += tempStudentScore;
			}
		}
//		cout << "studentMaxScore = " << studentMaxScore << " studentMinScore = " << studentMinScore << endl;
		studentScore = studentTotalScore - studentMaxScore - studentMinScore;
//		printf("teacherScore = %d, studentScore = %d, countValid = %d\n", teacherScore, studentScore, countValid);
		score = (teacherScore + studentScore * 1.0 / (countValid - 2)) * 0.5;
		finalScore = (int) score;
		if(score - finalScore >= 0.5){
			finalScore++;
		}
		printf("%d\n", finalScore);
	}
}
