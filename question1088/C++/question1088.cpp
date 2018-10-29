#include<iostream>
#include<math.h>

using namespace std;

int change(int num);
void compare(int num1, int num2);

int main() {
	int M, X, Y;
	scanf("%d %d %d", &M, &X, &Y);
	int jia;
	int yi;
	double bin;
	for(jia = 99; jia >= 10; jia--) {
		yi = change(jia);
		bin = abs(jia - yi) * 1.0 / X;
		if(yi * 1.0 / Y - bin < 0.001 && yi * 1.0 / Y - bin > -0.001) {
			break;
		}
	}
	if(jia >= 10) {
		cout << jia << " ";
		compare(jia, M);
		cout << " ";
		compare(yi, M);
		cout << " ";
		if(bin - M < 0.001 && bin - M > -0.001){
			cout << "Ping";
		}else if(bin > M){
			cout << "Cong";
		}else{
			cout << "Gai";
		}
	}else{
		cout << "No Solution" << endl;
	}
	return 0;
}

int change(int num) {
	int num1 = num / 10;
	int num2 = num % 10;
	return num2 * 10 + num1;
}

void compare(int num1, int num2) {
	if(num1 > num2) {
		cout << "Cong";
	} else if(num1 == num2) {
		cout << "Ping";
	} else {
		cout << "Gai";
	}
}
