#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct student{
	string name;
	int height;
};

bool compare(student student1, student student2);
void printOneRow(vector<student> students);

int main(){
	int N;
	int K;
	
	cin >> N >> K;
	
	student tempStudent;
	string tempName;
	int tempHeight;
	
	vector<student> students;
	
	for(int i = 0; i < N; i++){
		cin >> tempName >> tempHeight;
		tempStudent.name = tempName;
		tempStudent.height = tempHeight;
		students.push_back(tempStudent);
	}
	
	sort(students.begin(), students.end(), compare);

	int otherRow = N / K;
	int lastRow = N - (otherRow * K) + otherRow;
	
	for(int i = 0; i < K; i++){
		vector<student> newStudents;
		if(i == 0){
			for(int j = 0; j < lastRow; j++){
				newStudents.push_back(students[j]);
			}
		}else{
			for(int j = lastRow + (i - 1) * otherRow; j < lastRow + i * otherRow; j++){
				newStudents.push_back(students[j]);
			}
		}
		printOneRow(newStudents);
	}
	
	
}

bool compare(student student1, student student2){
	if(student1.height == student2.height){
		if(student1.name.compare(student2.name) < 0){
			return true;
		}else{
			return false;
		}
	}else{
		if(student1.height >= student2.height){
			return true;
		}else{
			return false;
		}
	}
}

void printOneRow(vector<student> students){
	int m = students.size();
	student afterSort[m];
	afterSort[m / 2] = students[0];
	int left = m / 2 - 1;
	int right = m / 2 + 1;
	for(int i = 1; i < m; i++){
		if(i % 2 == 1){
			afterSort[left--] = students[i];
		}else{
			afterSort[right++] = students[i];
		}
	}
	
	for(int i = 0; i < m; i++){
		cout << afterSort[i].name;
		if(i != m - 1){
			cout << " ";
		}else{
			cout << endl;
		}
	}
}
