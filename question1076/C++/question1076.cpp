#include<iostream>
#include<string>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	string options;
	
	int scores[4] = {1, 2, 3, 4};
	getchar();
	for(int i = 0; i < N; i++){
		getline(cin, options);
		for(int j = 0; j < options.length(); j++){
			if(options[j] == 'T'){
				cout << scores[options[j - 2] - 'A'];
				break;
			}
		}
	}
	
	return 0;
} 
