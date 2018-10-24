#include<iostream>
#include<vector>
#include<string>

using namespace std;

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
	
	string tempString;
	for(int i = 0; i < hand.length(); i++){
		if(hand[i] == '['){
			tempString = "";
		}else if(hand[i] == ']'){
			hands.push_back(tempString);
			tempString = "";
		}else{
			tempString += hand[i];
		}
	}
//	
//	for(int i = 0; i < hands.size(); i++){
//		cout << hands[i] << endl;
//	}
	
	for(int i = 0; i < eye.length(); i++){
		if(eye[i] == '['){
			tempString = "";
		}else if(eye[i] == ']'){
			eyes.push_back(tempString);
			tempString = "";
		}else{
			tempString += eye[i];
		}
	}
	
	for(int i = 0; i < mouth.length(); i++){
		if(mouth[i] == '['){
			tempString = "";
		}else if(mouth[i] == ']'){
			mouths.push_back(tempString);
			tempString = "";
		}else{
			tempString += mouth[i];
		}
	}
	
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
