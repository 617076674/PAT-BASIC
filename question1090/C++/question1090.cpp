#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	
	map<int, vector<int> > incompatibleMap;
	map<int, vector<int> >::iterator it;

	int tempNum1;
	int tempNum2;
	
	for(int i = 0; i < N; i++){
		cin >> tempNum1 >> tempNum2;
		incompatibleMap[tempNum1].push_back(tempNum2);
		incompatibleMap[tempNum2].push_back(tempNum1);
	}
	
	int K;
	int tempNum;
	
	bool flag;
	for(int i = 0; i < M; i++){
		cin >> K;
		vector<int> flagVector;
		flag = true; 
		for(int j = 0; j < K; j++){
			cin >> tempNum;	//If you break from line 43, the remain numbers in this line will be read by next circle.
			if(find(flagVector.begin(), flagVector.end(), tempNum) == flagVector.end()){
				it = incompatibleMap.find(tempNum);
				if(it != incompatibleMap.end()){
					for(int k = 0; k < it->second.size(); k++){
						flagVector.push_back(it->second[k]);
					}
				}
			}else{
				flag = false;
				//break; You can not break from here. 
			}
		}
		if(!flag){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
	
	return 0;
}
