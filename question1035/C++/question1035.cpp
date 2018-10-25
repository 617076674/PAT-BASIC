#include<iostream>
#include<vector>

using namespace std;

bool isInsertionSort(vector<int> input1, vector<int> input2);
void nextInsertionSortArray(vector<int>& input2);
void nextMergeSortArray(vector<int>& input2);
void printVector(vector<int> nums);

int main(){
	int n;
	cin >> n;
	
	vector<int> input1;
	vector<int> input2;
	
	int tempNum;
	for(int i = 0; i < n; i++){
		cin >> tempNum;
		input1.push_back(tempNum);
	}
	for(int i = 0; i < n; i++){
		cin >> tempNum;
		input2.push_back(tempNum);
	}
	
	if(isInsertionSort(input1, input2)){
		nextInsertionSortArray(input2);
		printf("Insertion Sort\n");
		printVector(input2);
	}else{
		nextMergeSortArray(input2);
		printf("Merge Sort\n");
		printVector(input2);
	}
	return 0;
}

bool isInsertionSort(vector<int> input1, vector<int> input2){
	int index = -1;
	for(int i = 1; i < input2.size(); i++){
		if(input2[i] < input2[i - 1]){
			index = i;
			break;
		}
	}
	if(index == -1){
		return true;
	}
	for(int i = index; i < input2.size(); i++){
		if(input1[i] != input2[i]){
			return false;
		}
	}
	return true;
}


void nextInsertionSortArray(vector<int>& input2){
	int index = -1;
	for(int i = 1; i < input2.size(); i++){
		if(input2[i] < input2[i - 1]){
			index = i;
			break;
		}
	}
	if(index == -1){
		return;
	}
	int temp = input2[index];
	int i = index;
	for(; input2[i - 1] > temp; i--){
		input2[i] = input2[i - 1];
	}
	input2[i] = temp;
	return;
}

void nextMergeSortArray(vector<int>& input2){
	int size = 1;
	while(true){
		size *= 2;
		bool flag = true;
		for(int i = 0; i < input2.size(); i += size){
			for(int j = i + 1; j < i + size && j < input2.size(); j++){
				if(input2[j] < input2[j - 1]){
					flag = false;
					break;
				}
			}
		}
		if(!flag){
			break;
		}
	}
	size /= 2;
	vector<int> tempNums;
	for(int i = 0; i < input2.size(); i++){
		tempNums.push_back(input2[i]);
	}
	
	for(int i = 0; i < tempNums.size(); i += 2 * size){
		int index1 = i;
		int maxIndex1 = i + size;
		if(tempNums.size() < maxIndex1){
			maxIndex1 = tempNums.size();
		}
		int index2 = i + size;
		int maxIndex2 = i + 2 * size;
		if(tempNums.size() < maxIndex2){
			maxIndex2 = tempNums.size();
		}
		int index = i;
		while(index1 < maxIndex1 || index2 < maxIndex2){
			if(index1 < maxIndex1 && index2 >= maxIndex2){
				input2[index++] = tempNums[index1++];
			}else if(index1 >= maxIndex1 && index2 < maxIndex2){
				input2[index++] = tempNums[index2++];
			}else if(tempNums[index1] < tempNums[index2]){
				input2[index++] = tempNums[index1++];
			}else{
				input2[index++] = tempNums[index2++];
			}
		}
	}
}

void printVector(vector<int> nums){
	for(int i = 0; i < nums.size(); i++){
		printf("%d", nums[i]);
		if(i != nums.size() - 1){
			printf(" ");
		}
	}
	return;
}
