#include<iostream>
#include<string>
#include<sstream>

using namespace std;

long changeToKnut(string s);
string changeToGalleonSickleKnut(long num);

int main(){
	
	string input1;
	string input2;
	
	cin >> input1 >> input2;
	
	long num1 = changeToKnut(input1);
	long num2 = changeToKnut(input2);
	
	if(num1 <= num2){
		cout << changeToGalleonSickleKnut(num2 - num1);
	}else{
		cout << "-" << changeToGalleonSickleKnut(num1 - num2);
	}
	
	return 0; 
}

long changeToKnut(string s){
	int indexPoint1 = -1;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '.'){
			indexPoint1 = i;
			break;
		}
	}
	int indexPoint2 = -1;
	for(int i = indexPoint1 + 1; i < s.length(); i++){
		if(s[i] == '.'){
			indexPoint2 = i;
			break;
		}
	}
	long galleon = 0;
	for(int i = 0; i < indexPoint1; i++){
		galleon = galleon * 10 + (s[i] - '0');
	}
	long sickle = 0;
	for(int i = indexPoint1 + 1; i < indexPoint2; i++){
		sickle = sickle * 10 + (s[i] - '0');
	}
	long knut = 0;
	for(int i = indexPoint2 + 1; i < s.length(); i++){
		knut = knut * 10 + (s[i] - '0');
	}
	return galleon * 17 * 29 + sickle * 29 + knut;
}
string changeToGalleonSickleKnut(long num){
	long galleon = num / (29 * 17);
	long sickle = (num - galleon * 29 * 17) / 29;
	long knut = num - galleon * 29 * 17 - sickle * 29;
	
	ostringstream os;
	os << galleon << "." << sickle << "." << knut;
	return os.str();
}
