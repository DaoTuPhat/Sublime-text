#include<bits/stdc++.h>
using namespace std;
void checkX(int p, int day[101]){
	int tmp1, tmp2;
	for(int i = 1; i <= p; i++){
		if(day[i] == -1){
			tmp1 = i;
			break;
		}
	}
	for(int i = tmp1 + 1; i <= p; i++){
		if(day[i] == -1){
			int ok = 1;
			tmp2 = i;
			for(int j = tmp1 + 1; j < tmp2; j++){
				if(day[j] == 0){
					tmp1 = tmp2;
					ok = 0;
					break;
				}
			}
			if(ok == 1){
				for(int j = tmp1 + 1; j < tmp2; j++){
					day[j] = 0;
				}
			}
		}
	}
}
void checkO(int p, int day[101]){
	int tmp1, tmp2;
	for(int i = 1; i <= p; i++){
		if(day[i] == 1){
			tmp1 = i;
			break;
		}
	}
	for(int i = tmp1+ 1; i <= p; i++){
		if(day[i] == 1){
			int ok = 1;
			tmp2 = i;
			for(int j = tmp1 + 1; j < tmp2; j++){
				if(day[j] == 0){
					tmp1 = tmp2;
					ok = 0;
					break;
				}
			}
			if(ok == 1){
				for(int j = tmp1 + 1; j < tmp2; j++){
					day[j] = 0;
				}
			}
		}
	}
}
int main(){
	int day[101] = {0};
	int p, n;
	cin >> p >> n;
	for(int i = 1; i < n; i++){
		int a;
		cin >> a;
		if(i % 2 == 1){
			day[a] = -1;
		}else{
			day[a] = 1;
		}
		checkX(p, day);
		checkO(p, day);
	}
	if(n % 2 == 1){
		int a;
		cin >> a;
		day[a] = -1;
		checkX(p, day);
	}else{
		int a;
		cin >> a;
		day[a] = 1;
		checkO(p, day);
	}
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = 1; i <= p; i++){
		if(day[i] == -1){
			cnt1++;
		}else if(day[i] == 1){
			cnt2++;
		}
	}
	cout << cnt1 << " " << cnt2;
	return 0;
}