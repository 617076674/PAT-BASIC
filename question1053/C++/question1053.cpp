#include<iostream>

using namespace std;

int main(){
	int total;
	double e;
	int D;
	
	cin >> total >> e >> D;
	
	int maybeEmpty = 0;
	int realEmpty = 0;
	int K;
	
	for(int i = 0; i < total; i++){
		cin >> K;
		int lowElectricDay = 0;
		double tempElectric;
		for(int j = 0; j < K; j++){
			cin >> tempElectric;
			if(tempElectric < e){
				lowElectricDay++;
			}
		}
		if(lowElectricDay > K / 2){
			if(K > D){
				realEmpty++;
			}else{
				maybeEmpty++;
			}
		}
	}
	
	printf("%.1lf", 100.0 * maybeEmpty / total);
	cout << "% ";
	printf("%.1lf", 100.0 * realEmpty / total);
	cout << "%";
}
