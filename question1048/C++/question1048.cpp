#include<iostream>
#include<string>

using namespace std;

int main(){
	
	while(true){
	
	string a;
	string b;
	
	cin >> a >> b;
	
	int index = 1;
	string result = "";
	while(true){
		if(index > a.length() && index > b.length()){
			break;
		}else if(index > a.length() && index <= b.length()){
			result += b[b.length() - index];
			index++;
		}else if(index <= a.length() && index > b.length()){
			if(index % 2 == 1){
			int sum = (a[a.length() - index] - '0') % 13;
			if(sum == 10){
				result += 'J';
			}else if(sum == 11){
				result += 'Q';
			}else if(sum == 12){
				result += 'K';
			}else{
				result += (sum + '0');
			}
			index++;
		}else if(index % 2 == 0){
			int diff = -(a[a.length() - index] - '0');
			if(diff < 0){
				diff += 10;
			}
			result += (diff + '0');
			index++;
		}
		}else if(index % 2 == 1){
			int sum = ((a[a.length() - index] - '0') + (b[b.length() - index] - '0')) % 13;
			if(sum == 10){
				result += 'J';
			}else if(sum == 11){
				result += 'Q';
			}else if(sum == 12){
				result += 'K';
			}else{
				result += (sum + '0');
			}
			index++;
		}else if(index % 2 == 0){
			int diff = (b[b.length() - index] - '0') - (a[a.length() - index] - '0');
			if(diff < 0){
				diff += 10;
			}
			result += (diff + '0');
			index++;
		}
	}
	
	for(int i = result.length() - 1; i >= 0; i--){
		cout << result[i];
	}
}

	return 0;
}
