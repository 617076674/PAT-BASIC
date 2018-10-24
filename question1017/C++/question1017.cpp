#include<iostream>
#include<string>

using namespace std;

int main(){
	string a;
	string q = "";
	int b, r;
	cin >> a >> b;
	if (a.size() == 1){
		if (a[0] - '0' >= b){
			int temp = a[0] - '0';
			q = temp / b + '0';
			r = temp -  b * temp / b;
		}
		else{
			q = "0";
			r = a[0] - '0';
		}
	}else{
		int temp = a[0] - '0';
		if (temp >= b){
			q += temp / b + '0';
			r = temp % b * 10 + (a[1] - '0');
		} else {
			r = temp * 10 + (a[1] - '0');
		}
		int num = 1;
		while (num < a.size() - 1){
			q += (r / b) + '0';
			r = (r % b) * 10 + (a[num + 1] - '0');
			num++;
		}
		q += (r / b) + '0';
		r %= b;
	}

	cout << q << " " << r << endl;

	return 0;
}
