#include<iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	int tempID;
	int tempX;
	int tempY;
	int tempDistance;
	
	int winnerID;
	int rookieID;
	
	int cloestDistance;
	int longestDistance;
	
	cin >> tempID >> tempX >> tempY;
	
	winnerID = tempID;
	rookieID = tempID;
	
	cloestDistance = tempX * tempX + tempY * tempY;
	longestDistance = tempX * tempX + tempY * tempY;
	
	for(int i = 1; i < N; i++){
		cin >> tempID >> tempX >> tempY;
		tempDistance = tempX * tempX + tempY * tempY;
		if(tempDistance < cloestDistance){
			winnerID = tempID;
			cloestDistance = tempDistance;
		}
		if(tempDistance > longestDistance){
			rookieID = tempID;
			longestDistance = tempDistance;
		}
	}
	
	printf("%04d %04d", winnerID, rookieID);
	
	return 0;
}
