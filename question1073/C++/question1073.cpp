#include<iostream>
#include<vector>

using namespace std;

struct question {
	int score;
	int options;
	int trueOptions;
	bool a;
	bool b;
	bool c;
	bool d;
	bool e;
};

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
		
	question questions[M];
	
	question tempQuestion;
	int tempScore;
	int tempOptions;
	int tempTrueOptions;
	char tempChar;
    for(int i = 0; i < M; i++){
		scanf("%d %d %d", &tempScore, &tempOptions, &tempTrueOptions);
		tempQuestion.score = tempScore;
		tempQuestion.options = tempOptions;
		tempQuestion.trueOptions = tempTrueOptions;
		tempQuestion.a = false;
		tempQuestion.b = false;
		tempQuestion.c = false;
		tempQuestion.d = false;
		tempQuestion.e = false;
		while((tempChar = getchar()) != '\n'){
			if(tempChar == 'a'){
				tempQuestion.a = true;
			}else if(tempChar == 'b'){
				tempQuestion.b = true;
			}else if(tempChar == 'c'){
				tempQuestion.c = true;
			}else if(tempChar == 'd'){
				tempQuestion.d = true;
			}else if(tempChar == 'e'){
				tempQuestion.e = true;
			}	               
		}
		questions[i] = tempQuestion;
	}
	
	char tempAnswer;
	bool tempA;
	bool tempB;
	bool tempC;
	bool tempD;
	bool tempE;
	double grade;
	
	int countsWrong[M][5];
	int countsTotalWrong = 0;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < 5; j++){
			countsWrong[i][j] = 0;
		}
	}
	for(int i = 0; i < N; i++){
		grade = 0.0;
		getchar();
		for(int j = 0; j < M; j++){
			tempA = false;
			tempB = false;
			tempC = false;
			tempD = false;
			tempE = false;
			tempChar = getchar();
			for(int k = 0; k < tempChar - '0';){
				scanf("%c", &tempAnswer);
				if(tempAnswer == 'a'){
					tempA = true;
					k++;
				}else if(tempAnswer == 'b'){
					tempB = true;
					k++;
				}else if(tempAnswer == 'c'){
					tempC = true;
					k++;
				}else if(tempAnswer == 'd'){
					tempD = true;
					k++;
				}else if(tempAnswer == 'e'){
					tempE = true;
					k++;
				}
			}
			if(j != M - 1){
				getchar();
				getchar();
				getchar();
			}
			if(tempA == questions[j].a && tempB == questions[j].b && tempC == questions[j].c 
				&& tempD == questions[j].d && tempE == questions[j].e){
				grade += questions[j].score;
			}else if((tempA && !questions[j].a) || (tempB && !questions[j].b) || (tempC && !questions[j].c) 
				|| (tempD && !questions[j].d) || (tempE && !questions[j].e)){
				grade += 0;
			}else {
				grade += 0.5 * questions[j].score;
			}
			if(tempA != questions[j].a){
				countsWrong[j][0]++;
				countsTotalWrong++;
			}
			if(tempB != questions[j].b){
				countsWrong[j][1]++;
				countsTotalWrong++;
			}
			if(tempC != questions[j].c){
				countsWrong[j][2]++;
				countsTotalWrong++;
			}
			if(tempD != questions[j].d){
				countsWrong[j][3]++;
				countsTotalWrong++;
			}
			if(tempE != questions[j].e){
				countsWrong[j][4]++;
				countsTotalWrong++;
			}
		}
		getchar();
		getchar();
		printf("%.1lf\n", grade);
	}
	
	if(countsTotalWrong == 0){
		cout << "Too simple" << endl;
		return 0;
	}
	
	int maxWrong = 0;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < 5; j++){
			if(countsWrong[i][j] > maxWrong){
				maxWrong = countsWrong[i][j];
			}
		}
	}
	
	for(int i = 0; i < M; i++){
		for(int j = 0; j < 5; j++){
			if(countsWrong[i][j] == maxWrong){
				printf("%d %d-%c\n", maxWrong, i + 1, 'a' + j);
			}
		}
	}
}                               	
             
