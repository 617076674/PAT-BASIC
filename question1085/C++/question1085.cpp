#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>

using namespace std;

struct student{
	string studentNumber;
	int studentScore;
	string schoolName;
};

struct school{
	double schoolScore;
	int quantity;
};

bool compare(pair<string, school> pair1, pair<string, school> pair2);
string toLower(string s);

int main(){
	int N;
	cin >> N;
	
	student tempStudent;
	string tempStudentNumber;
	int tempStudentScore;
	string tempSchoolName;
	
	vector<student> students;
	for(int i = 0; i < N; i++){
		cin >> tempStudentNumber >> tempStudentScore >> tempSchoolName;
		tempStudent.studentNumber = tempStudentNumber;
		tempStudent.studentScore = tempStudentScore;
		tempSchoolName = toLower(tempSchoolName);
		tempStudent.schoolName = tempSchoolName;
		students.push_back(tempStudent);
	}
	
	map<string, school> schoolMap;
	map<string, school>::iterator it;
	
	for(int i = 0; i < students.size(); i++){
		it = schoolMap.find(students[i].schoolName);
		if(it != schoolMap.end()){
			it->second.quantity++;
			if(students[i].studentNumber[0] == 'B'){
				it->second.schoolScore += 1.0 * students[i].studentScore / 1.5;
			}else if(students[i].studentNumber[0] == 'A'){
				it->second.schoolScore += 1.0 * students[i].studentScore;
			}else if(students[i].studentNumber[0] == 'T'){
				it->second.schoolScore += 1.5 * students[i].studentScore;
			}
		}else{
			school tempSchool;
			tempSchool.quantity = 1;
			if(students[i].studentNumber[0] == 'B'){
				tempSchool.schoolScore = 1.0 * students[i].studentScore / 1.5;
			}else if(students[i].studentNumber[0] == 'A'){
				tempSchool.schoolScore = 1.0 * students[i].studentScore;
			}else if(students[i].studentNumber[0] == 'T'){
				tempSchool.schoolScore = 1.5 * students[i].studentScore;
			}
			schoolMap[students[i].schoolName] = tempSchool;
		}
	}
	
	vector<pair<string, school> > results;
	for(it = schoolMap.begin(); it != schoolMap.end(); it++){
		results.push_back(make_pair(it->first, it->second));
	}
	
	sort(results.begin(), results.end(), compare);
	
	cout << results.size() << endl;
	int index = 1;
	for(int i = 0; i < results.size(); i++){
		if(i > 0 && (int)results[i].second.schoolScore != (int)results[i - 1].second.schoolScore){
			index = i + 1;
		}		
		cout << index << " " << results[i].first << " " << (int)results[i].second.schoolScore << " " << results[i].second.quantity << endl;
	}
	
}

bool compare(pair<string, school> pair1, pair<string, school> pair2){
	if((int)pair1.second.schoolScore == (int)pair2.second.schoolScore){
		if(pair1.second.quantity == pair2.second.quantity){
			if(pair1.first.compare(pair2.first) >= 0){
				return false;
			}else{
				return true;
			}
		}else{
			if(pair1.second.quantity >= pair2.second.quantity){
				return false;
			}else{
				return true;
			}
		}
	}else{
		if((int)pair1.second.schoolScore >= (int)pair2.second.schoolScore){
			return true;
		}else{
			return false;
		}
	}
}

string toLower(string s){
	string result = "";
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			result += s[i] - 'A' + 'a';
		}else{
			result += s[i];
		}
	}
	return result;
}

