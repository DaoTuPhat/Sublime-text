#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
bool vuong(dd x1, dd y1, dd x2, dd y2){
	if(x1 * x2 - y1 * y2 == 0){
		return true;
	}else{
		return false;
	}
}
dd dodai(dd x1, dd y1, dd x2, dd y2){
	dd a = x2 - x1;
	dd b = y2 - y1;
	return sqrt(a*a + b*b);
}

bool check(dd a1, dd b1, dd a2, dd b2, dd a3, dd b3){
	dd x1 = a2 - a1;
	dd y1 = b2 - b1;
	dd x2 = a3 - a2;
	dd y2 = b3 - b2;
	dd x3 = a1 - a3;
	dd y3 = b1 - b3;
	dd a = dodai(a1,b1,a2,b2);
	dd b = dodai(a1,b1,a3,b3);
	dd c = dodai(a2,b2,a3,b3);
	if(vuong(x1,y1,x2,y2) || vuong(x1,y1,x3,y3) || vuong(x2,y2,x3,y3) || a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b){
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
	}else if(check(a1+1,b1+1,a2,b2,a3,b3) || check(a1-1,b1-1,a2,b2,a3,b3) || check(a1+1,b1-1,a2,b2,a3,b3) || check(a1-1,b1+1,a2,b2,a3,b3)){
		cout << "ALMOST" << endl;
	}else{
		cout << "NEITHER" << endl;
	}
	return 0;
}