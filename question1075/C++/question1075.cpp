#include<iostream>
#include<vector>

using namespace std;

int main(){
	int firstAddress, N, K;
	cin >> firstAddress >> N >> K;
	
	int addresses[100000];
	int datas[100000];
	
	int tempAddress;
	int tempData;
	int tempNext;
	
	for(int i = 0; i < N; i++){
		cin >> tempAddress >> tempData >> tempNext;
		addresses[tempAddress] = tempNext;
		datas[tempAddress] = tempData;
	}
	
	vector<int> afterSort1;
	vector<int> afterSort2;
	vector<int> afterSort3;
	int curAddress = firstAddress;
	while(curAddress != -1){
		if(datas[curAddress] < 0){
			afterSort1.push_back(curAddress);
		}else if(datas[curAddress] >= 0 && datas[curAddress] <= K){
			afterSort2.push_back(curAddress);
		}else{
			afterSort3.push_back(curAddress);
		}
		curAddress = addresses[curAddress];
	}
	vector<int> afterSort;
	for(int i = 0; i < afterSort1.size(); i++){
		afterSort.push_back(afterSort1[i]);
	}
	for(int i = 0; i < afterSort2.size(); i++){
		afterSort.push_back(afterSort2[i]);
	}
	for(int i = 0; i < afterSort3.size(); i++){
		afterSort.push_back(afterSort3[i]);
	}
	
	for(int i = 0; i < afterSort.size(); i++){
		if(i != afterSort.size() - 1){
			printf("%05d %d %05d\n", afterSort[i], datas[afterSort[i]], afterSort[i + 1]);
		}else{
			printf("%05d %d -1\n", afterSort[i], datas[afterSort[i]]);	
		}
	}
	
	return 0;
	
}
