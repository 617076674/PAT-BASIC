#include<iostream>
#include<math.h>

using namespace std;

int main(){
	
	double r1, p1, r2, p2;
	
	cin >> r1 >> p1 >> r2 >> p2;
	
	double r = r1 * r2;
	double p = p1 + p2;
	
	double a = r * cos(p);
	double b = r * sin(p);
	
	if(a < 0){
		if(a >= -0.005){
			printf("0.00");
		}else{
			printf("-%.2lf", -a);
		}
	}else{
		if(a <= 0.005){
			printf("0.00");
		}else{
			printf("%.2lf", a);
		}
	}
	
	if(b < 0){
		if(b >= -0.005){
			printf("+0.00i");
		}else{
			printf("-%.2lfi", -b);	
		}
	}else{
		if(b == 0){
			printf("+0.00i");
		}else{
			printf("+%.2lfi", b);
		}
	}
}

