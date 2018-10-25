#include<iostream>
#include<vector>

using namespace std;

int main(){
	
	int N;
	cin >> N;
	
	int couples[100000];
	for(int i = 0; i < 100000; i++){
		couples[i] = -1;
	}
	
	int tempNum1;
	int tempNum2;
	for(int i = 0; i < N; i++){
		cin >> tempNum1 >> tempNum2;
		couples[tempNum1] = tempNum2;
		couples[tempNum2] = tempNum1;
	}
	
	int M;
	cin >> M;
	
	int flags[100000];
	for(int i = 0; i < 100000; i++){
		flags[i] = 0;
	}
	
	int tempNum;
	for(int i = 0; i < M; i++){
		cin >> tempNum;
		flags[tempNum]++;
	}
	
	vector<int> results;
	for(int i = 0; i < 100000; i++){
		if(flags[i] == 1){
			if((couples[i] == -1) || (couples[i] != -1 && flags[couples[i]] == 0)){
				results.push_back(i);
			}
		}
	}
	
	cout << results.size() << endl;
	for(int i = 0; i < results.size(); i++){
		printf("%05d", results[i]);
		if(i != results.size() - 1){
			cout << " ";
		}
	}
}
