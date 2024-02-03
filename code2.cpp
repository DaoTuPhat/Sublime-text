#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<ll> fibo;
vector<ll> nto;
ll nt[100000001];
void fibonaci(){
	fibo.push_back(1);
	fibo.push_back(1);
	for(int i = 2; i <= 100000; i++){
		ll a = fibo[i-1] + fibo[i-2];
		fibo.push_back(a);
	}
}
ll check(ll n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			return 0;
		}
	}
	return n > 1;
}
void snt(){
	for(int i = 1; i <= 100; i++){
		if(check(i)){
			nto.push_back(i);
		}
	}
}
int main(){
	vector<int> lucas;
	int n;
	cin >> n;
	fibonaci();
	snt();
	for(int i = 1; i <= 100; i++){
		auto vt1 = find(fibo.begin(), fibo.end(), i);
		auto vt2 = find(nto.begin(), nto.end(), i);
		if(vt1 != fibo.end() && vt2 != nto.end()){
			lucas.push_back(i);
		}
	}
	cout << lucas[n-1] << endl;
	return 0;
}