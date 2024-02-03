#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
dd dodai(dd x1, dd y1, dd x2, dd y2){
	dd a = x2 - x1;
	dd b = y2 - y1;
	return sqrt(a*a + b*b);
}
bool check(dd a1, dd b1, dd a2, dd b2, dd a3, dd b3){
	dd a = dodai(a1,b1,a2,b2);
	dd b = dodai(a1,b1,a3,b3);
	dd c = dodai(a2,b2,a3,b3);
	if(a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b){
		return true;
	}
	return false;
}
int main(){
	dd a1, b1, a2, b2, a3, b3;
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	if(check(a1,b1,a2,b2,a3,b3)){
		cout << "RIGHT" << endl;
	}else if(check(a1+1,b1,a2,b2,a3,b3) || check(a1-1,b1,a2,b2,a3,b3) || check(a1,b1+1,a2,b2,a3,b3) || check(a1,b1-1,a2,b2,a3,b3)){
		cout << "ALMOST" << endl;
	}else if(check(a1,b1,a2+1,b2,a3,b3) || check(a1,b1,a2-1,b2,a3,b3) || check(a1,b1,a2,b2+1,a3,b3) || check(a1,b1-1,a2,b2-1,a3,b3)){
		cout << "ALMOST" << endl;
	}else if(check(a1,b1,a2,b2,a3+1,b3) || check(a1,b1,a2,b2,a3-1,b3) || check(a1,b1,a2,b2,a3,b3+1) || check(a1,b1-1,a2,b2,a3,b3-1)){
		cout << "ALMOST" << endl;
	}else{
		cout << "NEITHER" << endl;
	}
	return 0;
}