#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	int count1 = 0;
	int count2 = 0;
	
	int num1, num2, num3, num4;
	int sum;
	for(int i = 0; i < n; i++){
		cin >> num1 >> num2 >> num3 >> num4;
		sum = num1 + num3;
		if(num2 == sum && num4 != sum){
			count2++;
		}else if(num2 != sum && num4 == sum){
			count1++;
		}
	}
	
	cout << count1 << " " << count2 << endl;
	
	return 0;
}
