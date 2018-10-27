#include<iostream>
#include<string>

using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	
	int illegals[10000];
	for(int i = 0; i < 10000; i++){
		illegals[i] = 0;
	}
	
	int tempIllegal;
	for(int i = 0; i < M; i++){
		scanf("%d", &tempIllegal);
		illegals[tempIllegal] = 1;
	}
	
	string name;
	int count;
	int things;
	int countStudent = 0;
	int countThing = 0;
	for(int i = 0; i < N; i++){
		cin >> name >> count;
		bool isFirstIllegal = true;
		for(int i = 0; i < count; i++){
			scanf("%d", &things);
			if(illegals[things] == 1){
				if(isFirstIllegal){
					isFirstIllegal = false;
					cout << name << ":";
				}
				printf(" %04d", things);
				countThing++;
			}
		}
		if(!isFirstIllegal){
			countStudent++;
			printf("\n");
		}
	}
	printf("%d %d", countStudent, countThing);
	
	return 0;
}
