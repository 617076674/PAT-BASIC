#include<iostream>
#include<vector>
#include<string>

using namespace std;

void generateArray(vector<string>& hands, string s); 

int main(){
	
	string hand;
	string eye;
	string mouth;
	
	getline(cin, hand);
	getline(cin, eye);
	getline(cin, mouth);
	
	vector<string> hands;
	vector<string> eyes;
	vector<string> mouths;
	
	generateArray(hands, hand);
	generateArray(eyes, eye);
	generateArray(mouths, mouth);
	
	int count;
	cin >> count;
	
	int leftHand;
	int leftEye;
	int midMouth;
	int rightEye;
	int rightHand;
	
	for(int i = 0; i < count; i++){
		cin >> leftHand >> leftEye >> midMouth >> rightEye >> rightHand;
		if(leftHand < 1 || leftHand > hands.size() || rightHand < 1 || rightHand > hands.size() || 
			leftEye < 1 || leftEye > eyes.size() || rightEye < 1 || rightEye > eyes.size() ||
			midMouth < 1 || midMouth > mouths.size()){
				printf("Are you kidding me? @\\/@\n");
			}else{
				cout << hands[leftHand - 1] << "(" << eyes[leftEye - 1] << mouths[midMouth - 1] << 
				eyes[rightEye - 1] << ")" << hands[rightHand - 1] << endl;
			}
	}
}

void generateArray(vector<string>& array, string s){
	string tempString;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '['){
			tempString = "";
		}else if(s[i] == ']'){
			array.push_back(tempString);
			tempString = "";
		}else{
			tempString += s[i];
		}
	}
}
